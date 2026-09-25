#include "stm32l432xx.h"
#include "initialize.h"

#define LED_PORT  GPIOB
#define LED_PIN   3U

int main(void){
    IWDG_Init();
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;

    LED_PORT->MODER = (LED_PORT->MODER & ~(3U << (LED_PIN * 2U))) | (1U << (LED_PIN * 2U));
    for (;;) {
        LED_PORT->ODR ^= (1U << LED_PIN);
    }
}
