#ifndef SRC_BSP_BSP_H_
#define SRC_BSP_BSP_H_

#include "def.h"

#include "stm32f1xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif



bool bspInit();

uint32_t millis();
uint32_t micros();
void delay(uint32_t ms);

void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* SRC_BSP_BSP_H_ */
