#ifndef INITIALIZE_H
#define INITIALIZE_H

#include "stdint.h"


// Watchdog Timer (IWDG) register keys and configuration values
#define IWD_ENABLE_KEY 0xCCCC
#define IWD_RELOAD_KEY 0xAAAA
#define IWD_WRITE_ACCESS_KEY 0x5555
#define IWDG_PRESCALER 0x06
#define IWDG_RELOAD_VALUE 0xFFF

void IWDG_Init(void);
void SystemInit(void);
void Clock_Init(void);
void SysTick_handler(void);
void SysTick_MS(void);

#endif