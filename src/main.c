#include "initialize.h"

int main(void) {
    iwdg_init();
    clock_init();
    systick_init();
    led_init();

    uint64_t last_toggle_ms = systick_get_ms();
    for (;;) {
        iwdg_kick();
        if ((systick_get_ms() - last_toggle_ms) >= LED_BLINK_MS) {
            last_toggle_ms += LED_BLINK_MS;
            led_toggle();
        }
    }
}
