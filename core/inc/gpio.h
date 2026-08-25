#ifndef GPIO_H
#define GPIO_H

#include "stm32l4xx.h"

/* User LED LD3 (green) is on PB3 for the Nucleo-L432KC. */
#define LED_PORT  GPIOB
#define LED_PIN   3U

void gpioLedInit(void);
void gpioLedToggle(void);
void gpioLedWrite(uint32_t on);

#endif /* GPIO_H */
