#include "battery.h"
                                 
uint8_t battery_status_0 =  BATTERY_STATUS_INITIAL;         //set battery status to glowing aqua on start up
uint8_t battery_status;    
uint8_t battery_percentage = BATTERY_PERCENTAGE_INITIAL;    //set battery percentage to 100 initially                                           
//uint8_t battery_reading = 0;                                //dummy voltage reading, replace with data from MCU

uint8_t compute_battery(uint8_t battery_reading){
    return ((battery_reading-30))* 100 /(42-30);
}

void check_battery_status(uint8_t battery_reading)
{
    int x = compute_battery(battery_reading);
    if(x>80){battery_status = GLOWING_AQUA;
        printf("%d %d 1\n",x, battery_status);}
        
    else if (x>63 && x<=80){battery_status = GLOWING_GREEN;
        printf("%d %d 2\n",x, battery_status);}
        
    else if (x>45 && x<=63){battery_status = YELLOW;
        printf("%d %d 3\n",x, battery_status);}
        
    else if (x>28 && x<=45){battery_status = ORANGE;
        printf("%d %d 4\n",x, battery_status);}
        
    else if (x<=28){battery_status = RED;
        printf("%d %d 5\n",x, battery_status);}
    
    else
        printf("Error detected\n");
}