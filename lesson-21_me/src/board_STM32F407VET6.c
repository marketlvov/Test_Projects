/* Board Support Package (BSP) for the STM32F407VET6 board */
#include <stdint.h>             /* Standard integers. WG14/N843 C99 Standard */

#include "board_STM32F407VET6.h"
#include "stm32f4xx.h"          /* the STM32F407VET6 MCU Peripheral Access Layer (TI) */

#define VET_GPIOA_P6_ON        0x0040     // on  GPIOA  p6on p7off
#define VET_GPIOA_P6_OFF       0x0080     // off GPIOA  p7on p6off
#define VET_GPIOA_P6_UOTPUT    0x00005000 // GPIOA pin 6,7 OUTPUT
#define VET_GPIOA_ALL_PULLUP   0x0        // pullup all port GPIOA
#define VET_GPIOA_ALL_LOWSPEED 0x0        // GPIOA low speed to all port
#define SYSCLOCK 8000000U                 // Cristal 8000000MHz

static uint32_t volatile l_tickCtr;

void SysTick_Handler(void) {
    ++l_tickCtr;
}

void BSP_init(void) {
    RCC->AHB1ENR  |= RCC_AHB1ENR_GPIOAEN;    // on  GPIOA  rcc
    GPIOA->MODER   = VET_GPIOA_P6_UOTPUT;    // GPIOA PA-6,7 to OUTPUT
    GPIOA->OTYPER  = VET_GPIOA_ALL_PULLUP;   // pullup all port GPIOA
    GPIOA->OSPEEDR = VET_GPIOA_ALL_LOWSPEED; // GPIOA low speed to all port
    //qp_blink_turn_off();                     // off GPIOA pin6 and on GPIOA pin7

    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock / BSP_TICKS_PER_SEC);

    __enable_irq();
}

uint32_t BSP_tickCtr(void) {
    uint32_t tickCtr;

    __disable_irq();
    tickCtr = l_tickCtr;
    __enable_irq();

    return tickCtr;
}

void BSP_delay(uint32_t ticks) {
    uint32_t start = BSP_tickCtr();
    while ((BSP_tickCtr() - start) < ticks) {
    }
}


void BSP_ledGreenOn(void) {
        // ("LED ON\n");
    GPIOA->ODR = VET_GPIOA_P6_ON; // on  GPIOA pin6 and off GPIOA pin7
    // GPIOF_AHB->DATA_Bits[LED_GREEN] = LED_GREEN;
}

void BSP_ledGreenOff(void) {
        // ("LED OFF\n");
    GPIOA->ODR = VET_GPIOA_P6_OFF; // off GPIOA pin6 and on GPIOA pin7
    // GPIOF_AHB->DATA_Bits[LED_GREEN] = 0U;
}

/*

void SysTick_init (uint32_t t_delay) {
    SysTick->LOAD &= ~SysTick_LOAD_RELOAD_Msk;
    SysTick->LOAD  = SYSCLOCK / (t_delay-1);
    SysTick->VAL   = ~SysTick_VAL_CURRENT_Msk;
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk |
                        SysTick_CTRL_ENABLE_Msk |
                        SysTick_CTRL_TICKINT_Msk;
}

*/









  /* 
uint32_t SystemCoreClock = 16000000;

This variable is updated in three ways:
      1) by calling CMSIS function SystemCoreClockUpdate()
      2) by calling HAL API function HAL_RCC_GetHCLKFreq()
      3) each time HAL_RCC_ClockConfig() is called to configure the system clock frequency 
         Note: If you use this function to configure the system clock; then there
               is no need to call the 2 first functions listed above, since SystemCoreClock
               variable is updated automatically.
  */

/**
  SystemCoreClockUpdate();

  * @brief  Update SystemCoreClock variable according to Clock Register Values.
  *         The SystemCoreClock variable contains the core clock (HCLK), it can
  *         be used by the user application to setup the SysTick timer or configure
  *         other parameters.
  *           
  * @note   Each time the core clock (HCLK) changes, this function must be called
  *         to update SystemCoreClock variable value. Otherwise, any configuration
  *         based on this variable will be incorrect.         
  *     
  * @note   - The system frequency computed by this function is not the real 
  *           frequency in the chip. It is calculated based on the predefined 
  *           constant and the selected clock source:
  *             
  *           - If SYSCLK source is HSI, SystemCoreClock will contain the HSI_VALUE(*)
  *                                              
  *           - If SYSCLK source is HSE, SystemCoreClock will contain the HSE_VALUE(**)
  *                          
  *           - If SYSCLK source is PLL, SystemCoreClock will contain the HSE_VALUE(**) 
  *             or HSI_VALUE(*) multiplied/divided by the PLL factors.
  *         
  *         (*) HSI_VALUE is a constant defined in stm32f4xx_hal_conf.h file (default value
  *             16 MHz) but the real value may vary depending on the variations
  *             in voltage and temperature.   
  *    
  *         (**) HSE_VALUE is a constant defined in stm32f4xx_hal_conf.h file (its value
  *              depends on the application requirements), user has to ensure that HSE_VALUE
  *              is same as the real frequency of the crystal used. Otherwise, this function
  *              may have wrong result.
  *                
  *         - The result of this function could be not correct when using fractional
  *           value for HSE crystal.
  *     
  * @param  None
  * @retval None
  *
  */    

/**
  SysTick_Config(SystemCoreClock / BOARD_TICKS_PER_SEC);
    
  \brief   System Tick Configuration
  \details Initializes the System Timer and its interrupt, and starts the System Tick Timer.
           Counter is in free running mode to generate periodic interrupts.
  \param [in]  ticks  Number of ticks between two interrupts.
  \return          0  Function succeeded.
  \return          1  Function failed.
  \note    When the variable <b>__Vendor_SysTickConfig</b> is set to 1, then the
           function <b>SysTick_Config</b> is not included. In this case, the file <b><i>device</i>.h</b>
           must contain a vendor-specific implementation of this function.
 */



