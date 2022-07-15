#include "main.h"

void led_effect_stop(void) {
	turn_off_all_leds();
	for(uint8_t i = 0; i < 4; i++) {
		xTimerStop(handle_led_timer[i], portMAX_DELAY);
	}
}
void led_effect(int n) {
	led_effect_stop();
	xTimerStart(handle_led_timer[n - 1], portMAX_DELAY);
}

void LED_effect1(void) {
	static uint8_t flag = 1;
	//(flag ^= 1) ? turn_off_all_leds() : turn_on_all_leds();
	flag ^= 1;
	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, (GPIO_PinState)flag);
	show_date_time();
}

void LED_effect2(void) {
	static uint8_t flag = 1;
	//(flag ^= 1) ? turn_on_even_leds() : turn_on_odd_leds();
	flag ^= 1;
	HAL_GPIO_WritePin(LD4_GPIO_Port, LD4_Pin, (GPIO_PinState)flag);
	show_date_time();
}

void LED_effect3(void) {
	static uint8_t flag = 1;
	//LED_control(0x01 << (i++ % 4));
	flag ^= 1;
	HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, (GPIO_PinState)flag);
	show_date_time();
}

void LED_effect4(void) {
	static uint8_t flag = 1;
	//LED_control(0x08 >> (i++ % 4));
	flag ^= 1;
	HAL_GPIO_WritePin(LD6_GPIO_Port, LD6_Pin, (GPIO_PinState)flag);
	show_date_time();
}

/*void LED_control(uint8_t value) {
	for(uint8_t i = 0; i < 4; i++) {
		HAL_GPIO_WritePin(LD3_GPIO_Port, (LED1 << i), ((value >> i) & 0x01));
	}
}

void turn_off_all_leds(void) {
	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LD4_GPIO_Port, LD4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LD6_GPIO_Port, LD6_Pin, GPIO_PIN_RESET);
}

void turn_on_all_leds(void) {
	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LD4_GPIO_Port, LD4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LD6_GPIO_Port, LD6_Pin, GPIO_PIN_SET);
}

void turn_on_even_leds(void) {
	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LD4_GPIO_Port, LD4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LD6_GPIO_Port, LD6_Pin, GPIO_PIN_RESET);
}

void turn_on_odd_leds(void) {
	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LD4_GPIO_Port, LD4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LD6_GPIO_Port, LD6_Pin, GPIO_PIN_SET);
}*/
void turn_off_all_leds(void) {
	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LD4_GPIO_Port, LD4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LD6_GPIO_Port, LD6_Pin, GPIO_PIN_RESET);
}

