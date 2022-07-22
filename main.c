#include <stdio.h>
#include "battery.h"

int main(){
    
    // test case for program 
    for (float x=42.0;x>=30;x=x-0.1){
        printf("%f\n",x);
        check_battery_status(x);
        
    }

}