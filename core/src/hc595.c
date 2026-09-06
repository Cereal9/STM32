#include "hc595.h"
#include "stm32l4xx.h"

/* PB0 = SRCLK, PB6 = SER, PB7 = RCLK */
#define SER_HIGH()      (GPIOB->BSRR = GPIO_BSRR_BS6)
#define SER_LOW()       (GPIOB->BSRR = GPIO_BSRR_BR6)
#define SRCLK_HIGH()    (GPIOB->BSRR = GPIO_BSRR_BS0)
#define SRCLK_LOW()     (GPIOB->BSRR = GPIO_BSRR_BR0)
#define RCLK_HIGH()     (GPIOB->BSRR = GPIO_BSRR_BS7)
#define RCLK_LOW()      (GPIOB->BSRR = GPIO_BSRR_BR7)

/* The 595 needs ~20 ns of setup and hold at 3.3 V; a handful of NOPs at the
 * 4 MHz MSI reset clock is already far more than that. Kept as a knob for
 * long wires. */
static void settle(void){
    __NOP();
    __NOP();
}

void hc595_init(void){
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;    /* Turn on B port clock */

    GPIOB->MODER &= ~(GPIO_MODER_MODE0 | GPIO_MODER_MODE6 | GPIO_MODER_MODE7);
    GPIOB->MODER |=  (GPIO_MODER_MODE0_0 | GPIO_MODER_MODE6_0 | GPIO_MODER_MODE7_0);

    /* Idle low so the first shift sees a clean rising edge. */
    SRCLK_LOW();
    RCLK_LOW();
    SER_LOW();
}

void hc595_write(uint16_t value){
    /* MSB first: bit 15 is clocked out first and walks all the way through
     * #1 into #2, leaving the low byte on the register nearest the MCU. */
    for (int i = 15; i >= 0; i--) {
        if (value & (1u << i)) {
            SER_HIGH();
        } else {
            SER_LOW();
        }
        settle();

        SRCLK_HIGH();   /* data sampled on this rising edge */
        settle();
        SRCLK_LOW();
        settle();
    }

    RCLK_HIGH();        /* latch all 16 outputs together */
    settle();
    RCLK_LOW();
    settle();
}
