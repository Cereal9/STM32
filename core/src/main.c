#include "stm32l4xx.h"

void SystemInit(void){}

static void spin(volatile uint32_t n){
    while (n--) {
        __NOP();
    }
}

void GPIO_init(void){
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;  //Turn on B port clock
    GPIOB->MODER &= ~(GPIO_MODER_MODE0 | GPIO_MODER_MODE6 | GPIO_MODER_MODE7);
    GPIOB->MODER = GPIO_MODER_MODE0_0 | GPIO_MODER_MODE6_0 | GPIO_MODER_MODE7_0; //Set PB0, PB6, PB7 to output
}

/* Shifts byte out MSB-first into the 74HC595, then latches it onto Q0-Q7 */
static void hc595_write(uint8_t byte){
    for (int i = 7; i >= 0; i--) {
        if (byte & (1 << i)) {
            GPIOB->BSRR = GPIO_BSRR_BS6;    /* SER high */
        } else {
            GPIOB->BSRR = GPIO_BSRR_BR6;    /* SER low  */
        }

        GPIOB->BSRR = GPIO_BSRR_BS0;    /* SRCLK high */
        spin(10);
        GPIOB->BSRR = GPIO_BSRR_BR0;    /* SRCLK low  */
        spin(10);
    }

    GPIOB->BSRR = GPIO_BSRR_BS7;    /* RCLK high, latch outputs */
    spin(10);
    GPIOB->BSRR = GPIO_BSRR_BR7;    /* RCLK low */
    spin(10);
}

int main(void){
    GPIO_init();

    for (;;) {
        for (int i = 0; i < 8; i++) {
            hc595_write(1 << i);
            spin(400000);
        }
    }
}
