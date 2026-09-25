#include "stm32l432xx.h"
#include "initialize.h"

#define LED_PORT  GPIOB
#define LED_PIN   3U

int main(void){
    SystemInit();

    LED_PORT->MODER = (LED_PORT->MODER & ~(3U << (LED_PIN * 2U))) | (1U << (LED_PIN * 2U));
    for (;;) {
        IWDG_Kick();
        LED_PORT->ODR ^= (1U << LED_PIN);
    }
}
