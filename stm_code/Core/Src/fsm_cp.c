#include "fsm_cp.h"


uint8_t cp[MAX_COMMAND_SIZE];
uint8_t cp_index = 0;
uint8_t cp_finish = 0;

void fsm_cp_run(void) {
    switch (status_cp) {
    case cp_get_first:
        if (temp == '!') {
            status_cp = cp_get_end;
            cp_index = 0;
            cp[cp_index++] = '!';
        }
        break;
    case cp_get_end:
        if (temp == '#') {
        	if (cp[1] == 'R') {
        		status_uart = rst_true;
        		for (int i = 0; i< 10; i++) {
        			cp[i] = '\0';
        		}
        	}
        	if (cp[1] == 'O') {
        		status_uart = get_ok;
        	    for (int i = 0; i< 10; i++) {
        	        cp[i] = '\0';
        	      }
        	  }
            cp_finish = 1;
            status_cp = cp_get_first;
        }
        else {
            cp[cp_index++] = temp;
        }
        break;
    default:
        status_cp = cp_get_first;
        break;
    }
}
