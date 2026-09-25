#include "stm32l4xx.h"
#include "initialize.h"


void IWDG_Init(void){
    IWDG->KR  = IWD_ENABLE_KEY;
    IWDG->KR  = IWD_WRITE_ACCESS_KEY;
    IWDG->PR  = IWDG_PRESCALER;
    IWDG->RLR = IWDG_RELOAD_VALUE;
    while (IWDG->SR) {}
    IWDG->KR  = IWD_RELOAD_KEY;
}

// Add a simple system tick so we can keep timing of the microcontroller
void SysTick_handler(void){}
void SysTick_MS(void){

}
void SystemInit(void){
    Clock_Init();
}

void Clock_Init(void){
    RCC->CR |= RCC_CR_HSION;
    while (!(RCC->CR & RCC_CR_HSIRDY)) {}
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_HSI;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI) {}
}
