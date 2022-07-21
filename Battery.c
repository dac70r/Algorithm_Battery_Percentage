#include "battery.h"

uint8_t battery_status = BATTERY_STATUS_INITIAL;            //set battery status to glowing aqua on start up
uint8_t battery_percentage = BATTERY_PERCENTAGE_INITIAL;    //set battery percentage to 100 initially                                           
//uint8_t battery_reading = 0;                                //dummy voltage reading, replace with data from MCU

uint8_t compute_battery(uint8_t battery_reading){
    battery_percentage = ((battery_reading-30)/(42-30)) * 100;
}

void check_battery_status(uint8_t battery_reading)
{
    int x = compute_battery(battery_reading);
    if(x>80)
        printf("Larger than 80 ");
    else
        printf("Smaller");
}