#include "stm32l4xx.h"
#include "initialize.h"

static volatile uint64_t ms_ticks = 0;
void SystemInit(void){
    Clock_Init();
}

void IWDG_Init(void){
    IWDG->KR  = IWD_ENABLE_KEY;
    IWDG->KR  = IWD_WRITE_ACCESS_KEY;
    IWDG->PR  = IWDG_PRESCALER;
    IWDG->RLR = IWDG_RELOAD_VALUE;
    while (IWDG->SR) {}
    IWDG->KR  = IWD_RELOAD_KEY;
}

void IWDG_Kick(void){
    IWDG->KR = IWD_RELOAD_KEY;
}

void SysTick_Handler(void){
    ms_ticks++;
}

uint64_t SysTick_MS(void){
    __disable_irq();
    uint64_t ticks = ms_ticks;
    __enable_irq();
    return ticks;
}

void Clock_Init(void){
    //I need to verify this with the reference manual 
    RCC->CR |= RCC_CR_HSION;
    while (!(RCC->CR & RCC_CR_HSIRDY)) {}
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_HSI;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI) {}
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    SysTick->LOAD = SYSTICK_RELOAD_1MS;
    SysTick->VAL  = 0;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
}
