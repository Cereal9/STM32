/* Blink LD3 (green) on PB3 — Nucleo-L432KC */

#include "stm32l432xx.h"
#include "pinmap.h"

#define LED_PIN 3U

static void delay(volatile uint32_t n)
{
    while (n--) {
        __NOP();
    }
}

void Setup(void){
    RCC->CR |= RCC_CR_HSION;
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    GPIOB->MODER   = PINMAP_PORT_GPIOB_MODER;
    GPIOB->OTYPER  = PINMAP_PORT_GPIOB_OTYPER;
    GPIOB->OSPEEDR = PINMAP_PORT_GPIOB_OSPEEDR;
    GPIOB->PUPDR   = PINMAP_PORT_GPIOB_PUPDR;
    GPIOB->ODR     = PINMAP_PORT_GPIOB_ODR;
    GPIOB->AFR[0]  = PINMAP_PORT_GPIOB_ALT_L;
    GPIOB->AFR[1]  = PINMAP_PORT_GPIOB_ALT_H;
}

int main(void)
{
    Setup();
    for (;;) {
        GPIOB->ODR ^= (1U << LED_PIN);
        delay(200000);
    }
}
