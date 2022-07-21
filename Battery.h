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

//Function declaration
uint8_t compute_battery(float);
uint8_t determine_range(uint8_t);
void check_battery_status(float);

#ifdef __cplusplus
}
#endif

#endif /* BATTERY_H_ */