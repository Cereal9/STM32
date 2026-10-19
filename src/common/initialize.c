#include "stm32l4xx.h"
#include "initialize.h"

static volatile uint64_t g_ms_ticks = 0u;

void SystemInit(void) {}

void clock_init(void) {
    RCC->CR |= RCC_CR_HSION;
    while (0u == (RCC->CR & RCC_CR_HSIRDY)) {
    }
    RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_SW) | RCC_CFGR_SW_HSI;
    while (RCC_CFGR_SWS_HSI != (RCC->CFGR & RCC_CFGR_SWS)) {
    }
}

void systick_init(void) {
    SysTick->LOAD = (SYSCLK_HZ / 1000u) - 1u; /* count 16000 cycles = 1 ms */
    SysTick->VAL  = 0u;                       /* start counting from zero */
    /* CPU clock source, interrupt at 0, start counting */
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
}

void led_init(void) {
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    GPIOB->MODER &= ~GPIO_MODER_MODE3;  /* clear PB3's 2 mode bits */
    GPIOB->MODER |= GPIO_MODER_MODE3_0; /* 01 = output */
}

void iwdg_init(void) {
    IWDG->KR  = IWDG_KEY_ENABLE;
    IWDG->KR  = IWDG_KEY_WRITE_ACCESS;
    IWDG->PR  = IWDG_PR_DIV16;
    IWDG->RLR = IWDG_RELOAD_2S;
    while (0u != IWDG->SR) {
    }
    IWDG->KR = IWDG_KEY_RELOAD;
}

void SysTick_Handler(void) { // Built in interrupt handler for SysTick
    g_ms_ticks++;
}

uint64_t systick_get_ms(void) {
    uint32_t const primask = __get_PRIMASK();
    __disable_irq();
    uint64_t const ticks = g_ms_ticks;
    __set_PRIMASK(primask);
    return ticks;
}

void iwdg_kick(void) {
    IWDG->KR = IWDG_KEY_RELOAD;
}

void led_toggle(void) {
    GPIOB->ODR ^= GPIO_ODR_OD3;
}
