/*
 * global.h
 *
 *  Created on: Dec 8, 2024
 *      Author: Lie
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include"main.h"

#define MAX_BUFFER_SIZE 30
#define MAX_COMMAND_SIZE 30
#define cp_get_first 11
#define cp_get_end 12
#define rst_true 21
#define get_ok 22

extern int status_cp;      // Khai báo extern cho biến status_cp
extern int status_uart;    // Khai báo extern cho biến status_uart
extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

extern uint8_t cp_finish;
extern uint8_t cp[MAX_BUFFER_SIZE];
extern uint8_t cp_index;
extern uint32_t ADC_value;
extern char str[30];

#endif /* INC_GLOBAL_H_ */
