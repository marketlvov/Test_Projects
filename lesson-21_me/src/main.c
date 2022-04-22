/*****************************************************************************
*    My Blynk ver_1.0.0
*    Project for CPU stm32f407VET6
*    
*****************************************************************************/

#include <stdio.h>  /* for printf()/fprintf() */
#include <stdlib.h> /* for exit() */

#include <stdint.h>
#include "board_STM32F407VET6.h"


/* background code: non-blocking version */
int main() {
        
    BSP_init();
    
    while (1) {
        /* Blinky polling state machine */
        
        static enum {
            INITIAL,
            OFF_STATE,
            ON_STATE
        } state = INITIAL;
        
        static uint32_t start;
        
        switch (state) {
            case INITIAL:
                start = BSP_tickCtr();
                state = OFF_STATE; /* initial transition */
                break;
        
            case OFF_STATE:
                if ((BSP_tickCtr() - start) > BSP_TICKS_PER_SEC * 3U / 4U) {
                    BSP_ledGreenOn();
                    start = BSP_tickCtr();
                    state = ON_STATE; /* state transition */
                }
                break;

            case ON_STATE:
                if ((BSP_tickCtr() - start) > BSP_TICKS_PER_SEC / 4U) {
                    BSP_ledGreenOff();
                    start = BSP_tickCtr();
                    state = OFF_STATE; /* state transition */
                }
                break;

            default:
                //error();
                break;
        }
    }
    //return 0;
}
