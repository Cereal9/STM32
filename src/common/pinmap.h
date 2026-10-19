#ifndef PINMAP_H
#define PINMAP_H

#include "stm32l4xx.h"

// clang-format off
/* ---- Port A: PA13/PA14 SWD, PA15 JTDI, kept at reset values so the debugger works ------------ */
#define PINMAP_PORT_GPIOA_MODER             \
    (GPIO_MODER_MODE0      |    /* PA0  */  \
     GPIO_MODER_MODE1      |    /* PA1  */  \
     GPIO_MODER_MODE2      |    /* PA2  */  \
     GPIO_MODER_MODE3      |    /* PA3  */  \
     GPIO_MODER_MODE4      |    /* PA4  */  \
     GPIO_MODER_MODE5      |    /* PA5  */  \
     GPIO_MODER_MODE6      |    /* PA6  */  \
     GPIO_MODER_MODE7      |    /* PA7  */  \
     GPIO_MODER_MODE8      |    /* PA8  */  \
     GPIO_MODER_MODE9      |    /* PA9  */  \
     GPIO_MODER_MODE10     |    /* PA10 */  \
     GPIO_MODER_MODE11     |    /* PA11 */  \
     GPIO_MODER_MODE12     |    /* PA12 */  \
     GPIO_MODER_MODE13_1   |    /* PA13 */  \
     GPIO_MODER_MODE14_1   |    /* PA14 */  \
     GPIO_MODER_MODE15_1   )    /* PA15 */

#define PINMAP_PORT_GPIOA_OTYPER            \
    (0UL                   |    /* PA0  */  \
     0UL                   |    /* PA1  */  \
     0UL                   |    /* PA2  */  \
     0UL                   |    /* PA3  */  \
     0UL                   |    /* PA4  */  \
     0UL                   |    /* PA5  */  \
     0UL                   |    /* PA6  */  \
     0UL                   |    /* PA7  */  \
     0UL                   |    /* PA8  */  \
     0UL                   |    /* PA9  */  \
     0UL                   |    /* PA10 */  \
     0UL                   |    /* PA11 */  \
     0UL                   |    /* PA12 */  \
     0UL                   |    /* PA13 */  \
     0UL                   |    /* PA14 */  \
     0UL                   )    /* PA15 */

#define PINMAP_PORT_GPIOA_OSPEEDR           \
    (0UL                   |    /* PA0  */  \
     0UL                   |    /* PA1  */  \
     0UL                   |    /* PA2  */  \
     0UL                   |    /* PA3  */  \
     0UL                   |    /* PA4  */  \
     0UL                   |    /* PA5  */  \
     0UL                   |    /* PA6  */  \
     0UL                   |    /* PA7  */  \
     0UL                   |    /* PA8  */  \
     0UL                   |    /* PA9  */  \
     0UL                   |    /* PA10 */  \
     0UL                   |    /* PA11 */  \
     0UL                   |    /* PA12 */  \
     GPIO_OSPEEDR_OSPEED13 |    /* PA13 */  \
     0UL                   |    /* PA14 */  \
     0UL                   )    /* PA15 */

#define PINMAP_PORT_GPIOA_PUPDR             \
    (0UL                   |    /* PA0  */  \
     0UL                   |    /* PA1  */  \
     0UL                   |    /* PA2  */  \
     0UL                   |    /* PA3  */  \
     0UL                   |    /* PA4  */  \
     0UL                   |    /* PA5  */  \
     0UL                   |    /* PA6  */  \
     0UL                   |    /* PA7  */  \
     0UL                   |    /* PA8  */  \
     0UL                   |    /* PA9  */  \
     0UL                   |    /* PA10 */  \
     0UL                   |    /* PA11 */  \
     0UL                   |    /* PA12 */  \
     GPIO_PUPDR_PUPD13_0   |    /* PA13 */  \
     GPIO_PUPDR_PUPD14_1   |    /* PA14 */  \
     GPIO_PUPDR_PUPD15_0   )    /* PA15 */

#define PINMAP_PORT_GPIOA_ODR               \
    ((0UL << 0)            |    /* PA0  */  \
     (0UL << 1)            |    /* PA1  */  \
     (0UL << 2)            |    /* PA2  */  \
     (0UL << 3)            |    /* PA3  */  \
     (0UL << 4)            |    /* PA4  */  \
     (0UL << 5)            |    /* PA5  */  \
     (0UL << 6)            |    /* PA6  */  \
     (0UL << 7)            |    /* PA7  */  \
     (0UL << 8)            |    /* PA8  */  \
     (0UL << 9)            |    /* PA9  */  \
     (0UL << 10)           |    /* PA10 */  \
     (0UL << 11)           |    /* PA11 */  \
     (0UL << 12)           |    /* PA12 */  \
     (0UL << 13)           |    /* PA13 */  \
     (0UL << 14)           |    /* PA14 */  \
     (0UL << 15)           )    /* PA15 */

#define PINMAP_PORT_GPIOA_ALT_L             \
    ((0UL << 0)            |    /* PA0  */  \
     (0UL << 1)            |    /* PA1  */  \
     (0UL << 2)            |    /* PA2  */  \
     (0UL << 3)            |    /* PA3  */  \
     (0UL << 4)            |    /* PA4  */  \
     (0UL << 5)            |    /* PA5  */  \
     (0UL << 6)            |    /* PA6  */  \
     (0UL << 7)            )    /* PA7  */

#define PINMAP_PORT_GPIOA_ALT_H             \
    ((0UL << 8)            |    /* PA8  */  \
     (0UL << 9)            |    /* PA9  */  \
     (0UL << 10)           |    /* PA10 */  \
     (0UL << 11)           |    /* PA11 */  \
     (0UL << 12)           |    /* PA12 */  \
     (0UL << 13)           |    /* PA13 */  \
     (0UL << 14)           |    /* PA14 */  \
     (0UL << 15)           )    /* PA15 */

/* ---- Port B: PB3 is the user LED (LD3) ------------------------------------------------------- */
#define PINMAP_PORT_GPIOB_MODER             \
    (GPIO_MODER_MODE0      |    /* PB0  */  \
     GPIO_MODER_MODE1      |    /* PB1  */  \
     GPIO_MODER_MODE2      |    /* PB2  */  \
     GPIO_MODER_MODE3_0    |    /* PB3  */  \
     GPIO_MODER_MODE4      |    /* PB4  */  \
     GPIO_MODER_MODE5      |    /* PB5  */  \
     GPIO_MODER_MODE6      |    /* PB6  */  \
     GPIO_MODER_MODE7      |    /* PB7  */  \
     GPIO_MODER_MODE8      |    /* PB8  */  \
     GPIO_MODER_MODE9      |    /* PB9  */  \
     GPIO_MODER_MODE10     |    /* PB10 */  \
     GPIO_MODER_MODE11     |    /* PB11 */  \
     GPIO_MODER_MODE12     |    /* PB12 */  \
     GPIO_MODER_MODE13     |    /* PB13 */  \
     GPIO_MODER_MODE14     |    /* PB14 */  \
     GPIO_MODER_MODE15     )    /* PB15 */

#define PINMAP_PORT_GPIOB_OTYPER            \
    (0UL                   |    /* PB0  */  \
     0UL                   |    /* PB1  */  \
     0UL                   |    /* PB2  */  \
     0UL                   |    /* PB3  */  \
     0UL                   |    /* PB4  */  \
     0UL                   |    /* PB5  */  \
     0UL                   |    /* PB6  */  \
     0UL                   |    /* PB7  */  \
     0UL                   |    /* PB8  */  \
     0UL                   |    /* PB9  */  \
     0UL                   |    /* PB10 */  \
     0UL                   |    /* PB11 */  \
     0UL                   |    /* PB12 */  \
     0UL                   |    /* PB13 */  \
     0UL                   |    /* PB14 */  \
     0UL                   )    /* PB15 */

#define PINMAP_PORT_GPIOB_OSPEEDR           \
    (0UL                   |    /* PB0  */  \
     0UL                   |    /* PB1  */  \
     0UL                   |    /* PB2  */  \
     0UL                   |    /* PB3  */  \
     0UL                   |    /* PB4  */  \
     0UL                   |    /* PB5  */  \
     0UL                   |    /* PB6  */  \
     0UL                   |    /* PB7  */  \
     0UL                   |    /* PB8  */  \
     0UL                   |    /* PB9  */  \
     0UL                   |    /* PB10 */  \
     0UL                   |    /* PB11 */  \
     0UL                   |    /* PB12 */  \
     0UL                   |    /* PB13 */  \
     0UL                   |    /* PB14 */  \
     0UL                   )    /* PB15 */

#define PINMAP_PORT_GPIOB_PUPDR             \
    (0UL                   |    /* PB0  */  \
     0UL                   |    /* PB1  */  \
     0UL                   |    /* PB2  */  \
     0UL                   |    /* PB3  */  \
     0UL                   |    /* PB4  */  \
     0UL                   |    /* PB5  */  \
     0UL                   |    /* PB6  */  \
     0UL                   |    /* PB7  */  \
     0UL                   |    /* PB8  */  \
     0UL                   |    /* PB9  */  \
     0UL                   |    /* PB10 */  \
     0UL                   |    /* PB11 */  \
     0UL                   |    /* PB12 */  \
     0UL                   |    /* PB13 */  \
     0UL                   |    /* PB14 */  \
     0UL                   )    /* PB15 */

#define PINMAP_PORT_GPIOB_ODR               \
    ((0UL << 0)            |    /* PB0  */  \
     (0UL << 1)            |    /* PB1  */  \
     (0UL << 2)            |    /* PB2  */  \
     (0UL << 3)            |    /* PB3  */  \
     (0UL << 4)            |    /* PB4  */  \
     (0UL << 5)            |    /* PB5  */  \
     (0UL << 6)            |    /* PB6  */  \
     (0UL << 7)            |    /* PB7  */  \
     (0UL << 8)            |    /* PB8  */  \
     (0UL << 9)            |    /* PB9  */  \
     (0UL << 10)           |    /* PB10 */  \
     (0UL << 11)           |    /* PB11 */  \
     (0UL << 12)           |    /* PB12 */  \
     (0UL << 13)           |    /* PB13 */  \
     (0UL << 14)           |    /* PB14 */  \
     (0UL << 15)           )    /* PB15 */

#define PINMAP_PORT_GPIOB_ALT_L             \
    ((0UL << 0)            |    /* PB0  */  \
     (0UL << 1)            |    /* PB1  */  \
     (0UL << 2)            |    /* PB2  */  \
     (0UL << 3)            |    /* PB3  */  \
     (0UL << 4)            |    /* PB4  */  \
     (0UL << 5)            |    /* PB5  */  \
     (0UL << 6)            |    /* PB6  */  \
     (0UL << 7)            )    /* PB7  */

#define PINMAP_PORT_GPIOB_ALT_H             \
    ((0UL << 8)            |    /* PB8  */  \
     (0UL << 9)            |    /* PB9  */  \
     (0UL << 10)           |    /* PB10 */  \
     (0UL << 11)           |    /* PB11 */  \
     (0UL << 12)           |    /* PB12 */  \
     (0UL << 13)           |    /* PB13 */  \
     (0UL << 14)           |    /* PB14 */  \
     (0UL << 15)           )    /* PB15 */

/* ---- Port C: only PC14/PC15 are bonded out (LSE crystal) ------------------------------------- */
#define PINMAP_PORT_GPIOC_MODER             \
    (GPIO_MODER_MODE0      |    /* PC0  */  \
     GPIO_MODER_MODE1      |    /* PC1  */  \
     GPIO_MODER_MODE2      |    /* PC2  */  \
     GPIO_MODER_MODE3      |    /* PC3  */  \
     GPIO_MODER_MODE4      |    /* PC4  */  \
     GPIO_MODER_MODE5      |    /* PC5  */  \
     GPIO_MODER_MODE6      |    /* PC6  */  \
     GPIO_MODER_MODE7      |    /* PC7  */  \
     GPIO_MODER_MODE8      |    /* PC8  */  \
     GPIO_MODER_MODE9      |    /* PC9  */  \
     GPIO_MODER_MODE10     |    /* PC10 */  \
     GPIO_MODER_MODE11     |    /* PC11 */  \
     GPIO_MODER_MODE12     |    /* PC12 */  \
     GPIO_MODER_MODE13     |    /* PC13 */  \
     GPIO_MODER_MODE14     |    /* PC14 */  \
     GPIO_MODER_MODE15     )    /* PC15 */

#define PINMAP_PORT_GPIOC_OTYPER            \
    (0UL                   |    /* PC0  */  \
     0UL                   |    /* PC1  */  \
     0UL                   |    /* PC2  */  \
     0UL                   |    /* PC3  */  \
     0UL                   |    /* PC4  */  \
     0UL                   |    /* PC5  */  \
     0UL                   |    /* PC6  */  \
     0UL                   |    /* PC7  */  \
     0UL                   |    /* PC8  */  \
     0UL                   |    /* PC9  */  \
     0UL                   |    /* PC10 */  \
     0UL                   |    /* PC11 */  \
     0UL                   |    /* PC12 */  \
     0UL                   |    /* PC13 */  \
     0UL                   |    /* PC14 */  \
     0UL                   )    /* PC15 */

#define PINMAP_PORT_GPIOC_OSPEEDR           \
    (0UL                   |    /* PC0  */  \
     0UL                   |    /* PC1  */  \
     0UL                   |    /* PC2  */  \
     0UL                   |    /* PC3  */  \
     0UL                   |    /* PC4  */  \
     0UL                   |    /* PC5  */  \
     0UL                   |    /* PC6  */  \
     0UL                   |    /* PC7  */  \
     0UL                   |    /* PC8  */  \
     0UL                   |    /* PC9  */  \
     0UL                   |    /* PC10 */  \
     0UL                   |    /* PC11 */  \
     0UL                   |    /* PC12 */  \
     0UL                   |    /* PC13 */  \
     0UL                   |    /* PC14 */  \
     0UL                   )    /* PC15 */

#define PINMAP_PORT_GPIOC_PUPDR             \
    (0UL                   |    /* PC0  */  \
     0UL                   |    /* PC1  */  \
     0UL                   |    /* PC2  */  \
     0UL                   |    /* PC3  */  \
     0UL                   |    /* PC4  */  \
     0UL                   |    /* PC5  */  \
     0UL                   |    /* PC6  */  \
     0UL                   |    /* PC7  */  \
     0UL                   |    /* PC8  */  \
     0UL                   |    /* PC9  */  \
     0UL                   |    /* PC10 */  \
     0UL                   |    /* PC11 */  \
     0UL                   |    /* PC12 */  \
     0UL                   |    /* PC13 */  \
     0UL                   |    /* PC14 */  \
     0UL                   )    /* PC15 */

#define PINMAP_PORT_GPIOC_ODR               \
    ((0UL << 0)            |    /* PC0  */  \
     (0UL << 1)            |    /* PC1  */  \
     (0UL << 2)            |    /* PC2  */  \
     (0UL << 3)            |    /* PC3  */  \
     (0UL << 4)            |    /* PC4  */  \
     (0UL << 5)            |    /* PC5  */  \
     (0UL << 6)            |    /* PC6  */  \
     (0UL << 7)            |    /* PC7  */  \
     (0UL << 8)            |    /* PC8  */  \
     (0UL << 9)            |    /* PC9  */  \
     (0UL << 10)           |    /* PC10 */  \
     (0UL << 11)           |    /* PC11 */  \
     (0UL << 12)           |    /* PC12 */  \
     (0UL << 13)           |    /* PC13 */  \
     (0UL << 14)           |    /* PC14 */  \
     (0UL << 15)           )    /* PC15 */

#define PINMAP_PORT_GPIOC_ALT_L             \
    ((0UL << 0)            |    /* PC0  */  \
     (0UL << 1)            |    /* PC1  */  \
     (0UL << 2)            |    /* PC2  */  \
     (0UL << 3)            |    /* PC3  */  \
     (0UL << 4)            |    /* PC4  */  \
     (0UL << 5)            |    /* PC5  */  \
     (0UL << 6)            |    /* PC6  */  \
     (0UL << 7)            )    /* PC7  */

#define PINMAP_PORT_GPIOC_ALT_H             \
    ((0UL << 8)            |    /* PC8  */  \
     (0UL << 9)            |    /* PC9  */  \
     (0UL << 10)           |    /* PC10 */  \
     (0UL << 11)           |    /* PC11 */  \
     (0UL << 12)           |    /* PC12 */  \
     (0UL << 13)           |    /* PC13 */  \
     (0UL << 14)           |    /* PC14 */  \
     (0UL << 15)           )    /* PC15 */

/* ---- Port H: only PH0, PH1, PH3 exist; other MODER bits are reserved ------------------------- */
#define PINMAP_PORT_GPIOH_MODER             \
    (GPIO_MODER_MODE0      |    /* PH0  */  \
     GPIO_MODER_MODE1      |    /* PH1  */  \
     0UL                   |    /* PH2  */  \
     GPIO_MODER_MODE3      |    /* PH3  */  \
     0UL                   |    /* PH4  */  \
     0UL                   |    /* PH5  */  \
     0UL                   |    /* PH6  */  \
     0UL                   |    /* PH7  */  \
     0UL                   |    /* PH8  */  \
     0UL                   |    /* PH9  */  \
     0UL                   |    /* PH10 */  \
     0UL                   |    /* PH11 */  \
     0UL                   |    /* PH12 */  \
     0UL                   |    /* PH13 */  \
     0UL                   |    /* PH14 */  \
     0UL                   )    /* PH15 */

#define PINMAP_PORT_GPIOH_OTYPER            \
    (0UL                   |    /* PH0  */  \
     0UL                   |    /* PH1  */  \
     0UL                   |    /* PH2  */  \
     0UL                   |    /* PH3  */  \
     0UL                   |    /* PH4  */  \
     0UL                   |    /* PH5  */  \
     0UL                   |    /* PH6  */  \
     0UL                   |    /* PH7  */  \
     0UL                   |    /* PH8  */  \
     0UL                   |    /* PH9  */  \
     0UL                   |    /* PH10 */  \
     0UL                   |    /* PH11 */  \
     0UL                   |    /* PH12 */  \
     0UL                   |    /* PH13 */  \
     0UL                   |    /* PH14 */  \
     0UL                   )    /* PH15 */

#define PINMAP_PORT_GPIOH_OSPEEDR           \
    (0UL                   |    /* PH0  */  \
     0UL                   |    /* PH1  */  \
     0UL                   |    /* PH2  */  \
     0UL                   |    /* PH3  */  \
     0UL                   |    /* PH4  */  \
     0UL                   |    /* PH5  */  \
     0UL                   |    /* PH6  */  \
     0UL                   |    /* PH7  */  \
     0UL                   |    /* PH8  */  \
     0UL                   |    /* PH9  */  \
     0UL                   |    /* PH10 */  \
     0UL                   |    /* PH11 */  \
     0UL                   |    /* PH12 */  \
     0UL                   |    /* PH13 */  \
     0UL                   |    /* PH14 */  \
     0UL                   )    /* PH15 */

#define PINMAP_PORT_GPIOH_PUPDR             \
    (0UL                   |    /* PH0  */  \
     0UL                   |    /* PH1  */  \
     0UL                   |    /* PH2  */  \
     0UL                   |    /* PH3  */  \
     0UL                   |    /* PH4  */  \
     0UL                   |    /* PH5  */  \
     0UL                   |    /* PH6  */  \
     0UL                   |    /* PH7  */  \
     0UL                   |    /* PH8  */  \
     0UL                   |    /* PH9  */  \
     0UL                   |    /* PH10 */  \
     0UL                   |    /* PH11 */  \
     0UL                   |    /* PH12 */  \
     0UL                   |    /* PH13 */  \
     0UL                   |    /* PH14 */  \
     0UL                   )    /* PH15 */

#define PINMAP_PORT_GPIOH_ODR               \
    ((0UL << 0)            |    /* PH0  */  \
     (0UL << 1)            |    /* PH1  */  \
     (0UL << 2)            |    /* PH2  */  \
     (0UL << 3)            |    /* PH3  */  \
     (0UL << 4)            |    /* PH4  */  \
     (0UL << 5)            |    /* PH5  */  \
     (0UL << 6)            |    /* PH6  */  \
     (0UL << 7)            |    /* PH7  */  \
     (0UL << 8)            |    /* PH8  */  \
     (0UL << 9)            |    /* PH9  */  \
     (0UL << 10)           |    /* PH10 */  \
     (0UL << 11)           |    /* PH11 */  \
     (0UL << 12)           |    /* PH12 */  \
     (0UL << 13)           |    /* PH13 */  \
     (0UL << 14)           |    /* PH14 */  \
     (0UL << 15)           )    /* PH15 */

#define PINMAP_PORT_GPIOH_ALT_L             \
    ((0UL << 0)            |    /* PH0  */  \
     (0UL << 1)            |    /* PH1  */  \
     (0UL << 2)            |    /* PH2  */  \
     (0UL << 3)            |    /* PH3  */  \
     (0UL << 4)            |    /* PH4  */  \
     (0UL << 5)            |    /* PH5  */  \
     (0UL << 6)            |    /* PH6  */  \
     (0UL << 7)            )    /* PH7  */

#define PINMAP_PORT_GPIOH_ALT_H             \
    ((0UL << 8)            |    /* PH8  */  \
     (0UL << 9)            |    /* PH9  */  \
     (0UL << 10)           |    /* PH10 */  \
     (0UL << 11)           |    /* PH11 */  \
     (0UL << 12)           |    /* PH12 */  \
     (0UL << 13)           |    /* PH13 */  \
     (0UL << 14)           |    /* PH14 */  \
     (0UL << 15)           )    /* PH15 */
// clang-format on

#endif /* PINMAP_H */
