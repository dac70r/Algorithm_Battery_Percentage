#include "battery.h"
                                 
uint8_t battery_status_0 =  BATTERY_STATUS_INITIAL;         //set battery status to glowing aqua on start up
uint8_t battery_status;    
uint8_t battery_percentage = BATTERY_PERCENTAGE_INITIAL;    //set battery percentage to 100 initially                                           
uint8_t app_battery_status; 

uint8_t compute_battery(uint8_t battery_reading){
    return ((battery_reading-30))* 100 /(42-30);
}

void check_battery_status(uint8_t battery_reading)
{
    printf("Before: battery_status_0: %d\n",battery_status_0);
    int x = compute_battery(battery_reading);
    if(x>80){battery_status = GLOWING_AQUA;
        printf("Battery now at %d%% %d color:GLOWING_AQUA\n",x, battery_status);
        if (battery_status_0 != battery_status){printf("Sending 5 bars to Dashboard (insert driver here)\n"); app_battery_status = battery_status;}
        printf("app_battery_status: %d\n",app_battery_status);}
        
    else if (x>63 && x<=80){battery_status = GLOWING_GREEN;
        printf("Battery now at %d%% %d color:GLOWING_GREEN\n",x, battery_status);
        if (battery_status_0 != battery_status){printf("Sending 4 bars to Dashboard (insert driver here)\n"); app_battery_status = battery_status;}
        printf("app_battery_status: %d\n",app_battery_status);}
        
    else if (x>45 && x<=63){battery_status = YELLOW;
        printf("Battery now at %d%% %d color:YELLOW\n",x, battery_status);
        if (battery_status_0 != battery_status){printf("Sending 3 bars to Dashboard (insert driver here)\n"); app_battery_status = battery_status;}
        printf("app_battery_status: %d\n",app_battery_status);}
        
    else if (x>28 && x<=45){battery_status = ORANGE;
        printf("Battery now at %d%% %d color:ORANGE\n",x, battery_status);
        if (battery_status_0 != battery_status){printf("Sending 2 bars to Dashboard (insert driver here)\n"); app_battery_status = battery_status;}
        printf("app_battery_status: %d\n",app_battery_status);}
        
    else if (x<=28){battery_status = RED;
        printf("Battery now at %d%% %d color:RED\n",x, battery_status);
        if (battery_status_0 != battery_status){printf("Sending 1 bars to Dashboard (insert driver here)\n"); app_battery_status = battery_status;}
        printf("app_battery_status: %d\n",app_battery_status);}
    
    else{printf("Error detected\n");}
        
    battery_status_0 = battery_status;
    printf("After: battery_status_0: %d\n",battery_status_0);
    printf("----------------------------------------\n");
}