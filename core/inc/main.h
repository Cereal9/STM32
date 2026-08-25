#ifndef MAIN_H
#define MAIN_H

#include "stm32l4xx.h"

/* Called by Reset_Handler in startup_stm32l432xx.s before main(). */
void SystemInit(void);

int main(void);

#endif /* MAIN_H */
