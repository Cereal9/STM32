#ifndef PINMAP_h
#define PINMAP_h

#include "stm32l432xx.h"

#define PINMAP_PORT_GPIOB_MODER (GPIO_MODER_MODE0    | \
                                 GPIO_MODER_MODE1    | \
                                 GPIO_MODER_MODE2    | \
                                 GPIO_MODER_MODE3_0  | \
                                 GPIO_MODER_MODE4    | \
                                 GPIO_MODER_MODE5    | \
                                 GPIO_MODER_MODE6    | \
                                 GPIO_MODER_MODE7    | \
                                 GPIO_MODER_MODE8    | \
                                 GPIO_MODER_MODE9    | \
                                 GPIO_MODER_MODE10   |  \
                                 GPIO_MODER_MODE11   | \
                                 GPIO_MODER_MODE12   | \
                                 GPIO_MODER_MODE13   | \
                                 GPIO_MODER_MODE14   | \
                                 GPIO_MODER_MODE15 )

#define PINMAP_PORT_GPIOB_OTYPER (0UL  | \
                                  0UL  | \
                                  0UL  | \
                                  0UL  | \
                                  0UL  | \
                                  0UL  | \
                                  0UL  | \
                                  0UL  | \
                                  0UL  | \
                                  0UL  | \
                                  0UL  | \
                                  0UL  | \
                                  0UL  | \
                                  0UL  | \
                                  0UL  | \
                                  0UL  )

#define PINMAP_PORT_GPIOB_OSPEEDR (0UL  | \
                                   0UL  | \
                                   0UL  | \
                                   0UL  | \
                                   0UL  | \
                                   0UL  | \
                                   0UL  | \
                                   0UL  | \
                                   0UL  | \
                                   0UL  | \
                                   0UL  | \
                                   0UL  | \
                                   0UL  | \
                                   0UL  | \
                                   0UL  | \
                                   0UL  )

#define PINMAP_PORT_GPIOB_PUPDR (0UL  | \
                                 0UL  | \
                                 0UL  | \
                                 0UL  | \
                                 0UL  | \
                                 0UL  | \
                                 0UL  | \
                                 0UL  | \
                                 0UL  | \
                                 0UL  | \
                                 0UL  | \
                                 0UL  | \
                                 0UL  | \
                                 0UL  | \
                                 0UL  | \
                                 0UL  )

#define PINMAP_PORT_GPIOB_ODR ((0UL     << 0)  | \
                               (0UL     << 1)  | \
                               (0UL     << 2)  | \
                               (0UL     << 3)  | \
                               (0UL     << 4)  | \
                               (0UL     << 5)  | \
                               (0UL     << 6)  | \
                               (0UL     << 7)  | \
                               (0UL     << 8)  | \
                               (0UL     << 9)  | \
                               (0UL     << 10) | \
                               (0UL     << 11) | \
                               (0UL     << 12) | \
                               (0UL     << 13) | \
                               (0UL     << 14) | \
                               (0UL     << 15) )

#define PINMAP_PORT_GPIOB_ALT_L ((0UL   << 0) | \
                                 (0UL   << 1) | \
                                 (0UL   << 2) | \
                                 (0UL   << 3) | \
                                 (0UL   << 4) | \
                                 (0UL   << 5) | \
                               	 (0UL   << 6) | \
                               	 (0UL   << 7) )

#define PINMAP_PORT_GPIOB_ALT_H ((0UL   << 8)  | \
                               	 (0UL   << 9)  | \
                               	 (0UL   << 10) | \
                               	 (0UL   << 11) | \
                               	 (0UL   << 12) | \
                               	 (0UL   << 13) | \
                               	 (0UL   << 14) | \
                               	 (0UL   << 15) )

#endif