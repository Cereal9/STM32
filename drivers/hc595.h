#ifndef HC595_H
#define HC595_H

#include <stdint.h>

/* Two 74HC595s daisy-chained: Q7' (pin 9) of the first feeds SER (pin 14) of
 * the second, and both share SRCLK and RCLK. Three MCU pins drive the pair.
 *
 *   PB6 -- SER   ->[595 #1]-- Q7' -->SER [595 #2]
 *   PB0 -- SRCLK ---^-----------------^
 *   PB7 -- RCLK  ---^-----------------^
 *
 * Bit map of the 16-bit value: the first bit clocked out travels furthest, so
 * the high byte ends up on the far register.
 *
 *   bits 0-7   -> #1 (nearest the MCU), Q0..Q7
 *   bits 8-15  -> #2 (far end),         Q0..Q7
 */
#define HC595_CHAIN_LEN 2

void hc595_init(void);

/* Shift out `value` MSB-first, then latch all 16 outputs at once. */
void hc595_write(uint16_t value);

#endif /* HC595_H */
