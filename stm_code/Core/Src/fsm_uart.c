/*
 * fsm_uart.c
 *
 *  Created on: Dec 8, 2024
 *      Author: Lie
 */
#include "fsm_uart.h"
void fsm_uart_run(ADC_HandleTypeDef hadc1, UART_HandleTypeDef huart2) {
    switch (status_uart) {
        case rst_true:
            if (cp_finish == 1) {
                HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, GPIO_PIN_SET);
                cp_finish = 0;

                HAL_ADC_Start(&hadc1);
                ADC_value = HAL_ADC_GetValue(&hadc1);
                if (ADC_value > 0) {
                    HAL_GPIO_WritePin(GPIOA, LED_YELLOW1_Pin, GPIO_PIN_SET);
                } else {
                    HAL_GPIO_WritePin(GPIOA, LED_YELLOW1_Pin, GPIO_PIN_RESET);
                }
                HAL_ADC_Stop(&hadc1);
                HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!ADC=%lu#\r\n", ADC_value), 1000);

                status_uart = get_ok;
                setTimer1(300);
            }
            break;

        case get_ok:
            if (timer1_flag == 1) {
                timer1_flag = 0;
                HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!ADC=%lu#\r\n", ADC_value), 1000);
                setTimer1(300);
            }
            if (cp_finish == 1) {
            	cp_finish = 0;
            	status_uart = rst_true;
            	HAL_GPIO_WritePin(GPIOA, LED_YELLOW1_Pin, GPIO_PIN_RESET);
            }
            break;

        default:
            break;
    }
}




