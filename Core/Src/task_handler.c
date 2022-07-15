#include "main.h"

const char* msg_inv = "";
int extract_command(command_t* cmd);
void process_command(command_t* cmd);
uint8_t get_number(uint8_t *p, int len);
void menu_task(void* parameters)
{
	uint32_t cmd_addr;
	command_t* cmd;
	int option;
	const char* msg_menu = "";
	while(1)
	{
		xQueueSend(q_print, &msg_menu, portMAX_DELAY);
		// wait for menu command
		xTaskNotifyWait(0, 0, &cmd_addr, portMAX_DELAY);
		cmd = (command_t*)cmd_addr;

		if(cmd->len == 1) {
			option = cmd->payload[0] - 48;
			switch(option) {
			case 2:
			case 9:
			case 1:
				curr_state = sLedEffect;
				xTaskNotify(handle_led_task, 0, eNoAction);
				break;
			/*case 1:
				curr_state = sRtcMenu;
				xTaskNotify(handle_rtc_task, 0, eNoAction);
				break;
			case 2:
				break; */
			default:
				xQueueSend(q_print, &msg_inv, portMAX_DELAY);
				continue;
			}
		}
		else {
			xQueueSend(q_print, &msg_inv, portMAX_DELAY);
			continue;
		}

		// wait to run again when some other task notifies
		xTaskNotifyWait(0, 0, NULL, portMAX_DELAY);
	}
}

void led_task(void* parameters)
{
	uint32_t cmd_addr;
	command_t* cmd;
	const char* msg_led = "";
	while(1)
	{
		// wait for notification
		xTaskNotifyWait(0, 0, NULL, portMAX_DELAY);
		// print LED menu
		xQueueSend(q_print, &msg_led, portMAX_DELAY);
		// wait for LED command
		xTaskNotifyWait(0, 0, &cmd_addr, portMAX_DELAY);
		cmd = (command_t*)cmd_addr;

		if(cmd->len <= 1) {
			if(!strcmp((char*)cmd->payload, "s"))
				led_effect_stop();
			else if(!strcmp((char*)cmd->payload, "u"))
				led_effect(1);
			else if(!strcmp((char*)cmd->payload, "d"))
				led_effect(2);
			else if(!strcmp((char*)cmd->payload, "i"))
				led_effect(3);
			else if(!strcmp((char*)cmd->payload, "o"))
				led_effect(4);
			else
				xQueueSend(q_print, &msg_inv, portMAX_DELAY);
		}
		else
			xQueueSend(q_print, &msg_inv, portMAX_DELAY);

		// update state variable
		curr_state = sMainMenu;
		// notify menu task
		xTaskNotify(handle_menu_task, 0, eNoAction);
	}
}
/*void rtc_task(void* parameters)
{
	const char* msg_rtc1 = "===================================\n"
							"|         	RTC          |\n"
							"===================================\n";

	const char* msg_rtc2 = "Configure Time            ----> 0\n"
							"Configure Date            ----> 1\n"
							"Enable reporting		   ----> 2\n"
							"Exit                      ----> 3\n"
							"Enter your choice here : ";


	const char *msg_rtc_hh = "Enter hour(1-12):";
	const char *msg_rtc_mm = "Enter minutes(0-59):";
	const char *msg_rtc_ss = "Enter seconds(0-59):";

	const char *msg_rtc_dd  = "Enter date(1-31):";
	const char *msg_rtc_mo  ="Enter month(1-12):";
	const char *msg_rtc_dow  = "Enter day(1-7 sun:1):";
	const char *msg_rtc_yr  = "Enter year(0-99):";

	const char *msg_conf = "Configuration successful\n";
	const char *msg_rtc_report = "Enable time&date reporting(y/n)?: ";

	uint32_t cmd_addr;
	command_t *cmd;

	static int rtc_state = 0;
	int menu_code;

	RTC_TimeTypeDef time;
	RTC_DateTypeDef date;

#define HH_CONFIG 		0
#define MM_CONFIG 		1
#define SS_CONFIG 		2

#define DATE_CONFIG 	0
#define MONTH_CONFIG 	1
#define YEAR_CONFIG 	2
#define DAY_CONFIG 		3


	while(1){
		//Notify wait (wait till someone notifies)
		xTaskNotifyWait(0, 0, NULL, portMAX_DELAY);
		//Print the menu and show current date and time information
		xQueueSend(q_print, &msg_rtc1, portMAX_DELAY);
		show_date_time();
		xQueueSend(q_print, &msg_rtc2, portMAX_DELAY);

		while(curr_state != sMainMenu){

			//Wait for command notification
			xTaskNotifyWait(0, 0, &cmd_addr, portMAX_DELAY);
			cmd = (command_t*)cmd_addr;
			switch(curr_state)
			{
				case sRtcMenu:{
					//process RTC menu commands
					if(cmd->len == 1) {
						menu_code = cmd->payload[0] - 48;
						switch(menu_code) {
						case 0:
							curr_state = sRtcTimeConfig;
							xQueueSend(q_print, &msg_rtc_hh, portMAX_DELAY);
							break;
						case 1:
							curr_state = sRtcDateConfig;
							xQueueSend(q_print, &msg_rtc_dd, portMAX_DELAY);
							break;
						case 2:
							curr_state = sRtcReport;
							xQueueSend(q_print, &msg_rtc_report, portMAX_DELAY);
							break;
						case 3:
							curr_state = sMainMenu;
							break;
						default:
							curr_state = sMainMenu;
							xQueueSend(q_print, &msg_inv, portMAX_DELAY);
						}
					}
					else {
						curr_state = sMainMenu;
						xQueueSend(q_print, &msg_inv, portMAX_DELAY);
					}
					break;}

				case sRtcTimeConfig:{
					//get hh, mm, ss infor and configure RTC
					switch(rtc_state) {
					case HH_CONFIG: {
						uint8_t hour;
						hour = get_number(cmd->payload, cmd->len);
						time.Hours = hour;
						rtc_state = MM_CONFIG;
						xQueueSend(q_print, &msg_rtc_mm, portMAX_DELAY);
						break;}
					case MM_CONFIG: {
						uint8_t min;
						min = get_number(cmd->payload, cmd->len);
						time.Minutes = min;
						rtc_state = SS_CONFIG;
						xQueueSend(q_print, &msg_rtc_ss, portMAX_DELAY);
						break;}
					case SS_CONFIG: {
						uint8_t sec;
						sec = get_number(cmd->payload, cmd->len);
						time.Seconds = sec;
						if(!validate_rtc_information(&time, NULL)) {
							rtc_configure_time(&time);
							xQueueSend(q_print, &msg_conf, portMAX_DELAY);
							show_date_time();
						}
						else
							xQueueSend(q_print, &msg_inv, portMAX_DELAY);
						curr_state = sMainMenu;
						rtc_state = 0;
						break;}
					}
					break;}

				case sRtcDateConfig:{
					//get date, month, day , year info and configure RTC
					switch(rtc_state) {
					case DATE_CONFIG:{
						uint8_t d;
						d = get_number(cmd->payload, cmd->len);
						date.Date = d;
						rtc_state = MONTH_CONFIG;
						xQueueSend(q_print, &msg_rtc_mo, portMAX_DELAY);
						break;}
					case MONTH_CONFIG: {
						uint8_t month;
						month = get_number(cmd->payload, cmd->len);
						date.Month = month;
						rtc_state = DAY_CONFIG;
						xQueueSend(q_print, &msg_rtc_dow, portMAX_DELAY);
						break;}
					case DAY_CONFIG: {
						uint8_t day;
						day = get_number(cmd->payload, cmd->len);
						date.WeekDay = day;
						rtc_state = YEAR_CONFIG;
						xQueueSend(q_print, &msg_rtc_yr, portMAX_DELAY);
						break;}
					case YEAR_CONFIG: {
						uint8_t year;
						year = get_number(cmd->payload, cmd->len);
						date.Year = year;
						if(!validate_rtc_information(NULL, &date)) {
							rtc_configure_date(&date);
							xQueueSend(q_print, &msg_conf, portMAX_DELAY);
							show_date_time();
						}
						else
							xQueueSend(q_print, &msg_inv, portMAX_DELAY);
						curr_state = sMainMenu;
						rtc_state = 0;
						break;}
					}
					break;}
				case sRtcReport:{
					break;}
				default:
					break;
			}
		}
		   //Notify menu task
		xTaskNotify(handle_menu_task, 0, eNoAction);

		}//while super loop end
} */
void print_task(void* parameters)
{
	uint32_t* msg;
	while(1)
	{
		xQueueReceive(q_print, &msg, portMAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen((char*)msg), HAL_MAX_DELAY);
	}
}
void cmd_handler_task(void* parameters)
{
	BaseType_t ret;
	command_t cmd;
	while(1)
	{
		// implement notify wait
		ret = xTaskNotifyWait(0, 0, NULL, portMAX_DELAY);
		if(ret == pdTRUE) {
			// process user data stored in input data queue
			process_command(&cmd);
		}
	}
}

void process_command(command_t* cmd) {
	extract_command(cmd);
	switch(curr_state)
	{
	case sMainMenu:
		xTaskNotify(handle_menu_task, (uint32_t)cmd, eSetValueWithOverwrite);
		break;
	case sLedEffect:
		xTaskNotify(handle_led_task, (uint32_t)cmd, eSetValueWithOverwrite);
		break;
	/*case sRtcMenu:
	case sRtcTimeConfig:
	case sRtcDateConfig:
	case sRtcReport:
		xTaskNotify(handle_rtc_task, (uint32_t)cmd, eSetValueWithOverwrite);
		break;*/
	}
}

int extract_command(command_t* cmd) {
	uint8_t item;
	BaseType_t status;

	status = uxQueueMessagesWaiting(q_data);
	if(!status)
		return -1;
	uint8_t i = 0;
	do {
		status = xQueueReceive(q_data, &item, 0);
		if(status == pdTRUE)
			cmd->payload[i++] = item;
	} while(item != '\n');

	cmd->payload[i - 1] = '\0';
	cmd->len = i - 1; // save length of the command excluding null char

	return 0;
}

uint8_t get_number(uint8_t *p, int len) {
	uint8_t value;
	if(len > 1)
		value = (((p[0] - 48) * 10) + (p[1] - 48));
	else
		value = p[0] - 48;
	return value;
}
