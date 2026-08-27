#include "stm32l4xx.h"

void SystemInit(void){}

static void spin(volatile uint32_t n){
    while (n--) {
        __NOP();
    }
}

int main(void){
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    GPIOB->MODER  = GPIO_MODER_MODE3_0;

    for (;;) {
        GPIOB->BSRR = GPIO_BSRR_BS3;    /* LED on  */
        spin(200000);

        GPIOB->BSRR = GPIO_BSRR_BR3;    /* LED off */
        spin(200000);
    }
}
