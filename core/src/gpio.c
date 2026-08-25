#include "gpio.h"

void gpioLedInit(void)
{
    /* Clock the port before touching any of its registers. */
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;

    /* General purpose output (01), push-pull, low speed, no pull-up/down. */
    LED_PORT->MODER   = (LED_PORT->MODER & ~(3U << (LED_PIN * 2U)))
                      | (1U << (LED_PIN * 2U));
    LED_PORT->OTYPER  &= ~(1U << LED_PIN);
    LED_PORT->OSPEEDR &= ~(3U << (LED_PIN * 2U));
    LED_PORT->PUPDR   &= ~(3U << (LED_PIN * 2U));

    gpioLedWrite(0U);
}

void gpioLedToggle(void)
{
    LED_PORT->ODR ^= (1U << LED_PIN);
}

void gpioLedWrite(uint32_t on)
{
    /* BSRR is atomic: low half sets, high half resets. */
    LED_PORT->BSRR = on ? (1U << LED_PIN) : (1U << (LED_PIN + 16U));
}
