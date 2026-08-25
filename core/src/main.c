#include "main.h"
#include "gpio.h"

/* Crude busy-wait. Roughly ~n cycles; the MCU runs on the 4 MHz MSI at reset. */
static void spin(volatile uint32_t n)
{
    while (n--) {
        __NOP();
    }
}

/*
 * The startup file branches to SystemInit before main(). We do not reconfigure
 * the clock tree, so an empty body is all that is needed to satisfy the link.
 */
void SystemInit(void)
{
}

int main(void)
{
    gpioLedInit();

    for (;;) {
        gpioLedToggle();
        spin(200000);
    }
}
