#ifndef BATTERY_H_
#define BATTERY_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

//Constants
#define BATTERY_PERCENTAGE_INITIAL                         100

//Colours
#define GLOWING_AQUA                                       0x00
#define GLOWING_GREEN                                      0x01
#define YELLOW                                             0x02
#define ORANGE                                             0x03
#define RED                                                0x04     
#define BATTERY_STATUS_INITIAL                             0x00

uint8_t compute_battery(void);
void check_battery_status(void)  ;        // compute B%

#ifdef __cplusplus
}
#endif

#endif /* BATTERY_H_ */