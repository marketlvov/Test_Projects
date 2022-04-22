#ifndef __BSP_H__
#define __BSP_H__

#include <stdint.h>

/* system clock tick [Hz] */
#define BSP_TICKS_PER_SEC 100U

void BSP_init(void);
// void SysTick_init(uint32_t);


/* get the current value of the clock tick counter (returns immedately) */
uint32_t BSP_tickCtr(void);

/* delay for a specified number of system clock ticks (polling) */
void BSP_delay(uint32_t ticks);

void BSP_ledGreenOn(void);
void BSP_ledGreenOff(void);

#endif // __BSP_H__
