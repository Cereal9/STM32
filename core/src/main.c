#include "stm32l4xx.h"
#include "hc595.h"

void SystemInit(void){}

static void spin(volatile uint32_t n){
    while (n--) {
        __NOP();
    }
}

int main(void){
    hc595_init();

    for (;;) {
        /* Walk a single lit output across both registers: #1 Q0..Q7, then
         * #2 Q0..Q7. */
        for (int i = 0; i < 8 * HC595_CHAIN_LEN; i++) {
            hc595_write(1u << i);
            spin(400000);
        }
    }
}
