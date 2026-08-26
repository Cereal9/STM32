#include "stm32l4xx.h"

#define LED_PORT  GPIOB
#define LED_PIN   3U

void SystemInit(void)
{
}

static void spin(volatile uint32_t n){
    while (n--) {
        __NOP();
    }
}

int main(void){
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;

    LED_PORT->MODER = (LED_PORT->MODER & ~(3U << (LED_PIN * 2U))) | (1U << (LED_PIN * 2U));

    for (;;) {
        LED_PORT->ODR ^= (1U << LED_PIN);
        spin(200000);
    }
}
