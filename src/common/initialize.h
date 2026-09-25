#ifndef INITIALIZE_H
#define INITIALIZE_H

#include "stdint.h"

// Watchdog Timer (IWDG) register keys and configuration values
#define IWD_ENABLE_KEY 0xCCCC
#define IWD_RELOAD_KEY 0xAAAA
#define IWD_WRITE_ACCESS_KEY 0x5555
#define IWDG_PRESCALER 0x06
#define IWDG_RELOAD_VALUE 0xFFF
#define SYSCLK_HZ 16000000UL
#define SYSTICK_RELOAD_1MS (SYSCLK_HZ / 1000U - 1U)

void SystemInit(void);
void IWDG_Init(void);
void IWDG_Kick(void);
void Clock_Init(void);
void SysTick_Init(void);
void SysTick_Handler(void);
uint64_t SysTick_MS(void);

#endif