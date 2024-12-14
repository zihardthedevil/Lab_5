/*
 * global.c
 *
 *  Created on: Dec 8, 2024
 *      Author: Lie
 */
#include "global.h"
int status_cp = 0;
int status_uart = 0;

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

uint32_t ADC_value = 0;
char str[30];
