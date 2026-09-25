#include "stm32l432xx.h"
#include "initialize.h"

#define LED_PORT  GPIOB
#define LED_PIN   3U
#define LED_BLINK_MS 500U

int main(void){
    SystemInit();

    LED_PORT->MODER = (LED_PORT->MODER & ~(3U << (LED_PIN * 2U))) | (1U << (LED_PIN * 2U));

    uint64_t last_toggle = SysTick_MS();
    for (;;) {
        IWDG_Kick();
        uint64_t now = SysTick_MS();
        if ((now - last_toggle) >= LED_BLINK_MS) {
            last_toggle += LED_BLINK_MS;
            LED_PORT->ODR ^= (1U << LED_PIN);
        }
    }
}
