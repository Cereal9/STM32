#ifndef INITIALIZE_H
#define INITIALIZE_H

#include "stdint.h"

#define SYSCLK_HZ 16000000u
#define LED_BLINK_MS 500u
#define IWDG_KEY_ENABLE 0xCCCCu
#define IWDG_KEY_RELOAD 0xAAAAu
#define IWDG_KEY_WRITE_ACCESS 0x5555u
#define IWDG_PR_DIV16 0x2u
#define IWDG_RELOAD_2S 3999u

void SystemInit(void);
void clock_init(void);
void systick_init(void);
uint64_t systick_get_ms(void);
void SysTick_Handler(void);
void iwdg_init(void);
void iwdg_kick(void);
void led_init(void);
void led_toggle(void);

#endif /* INITIALIZE_H */
