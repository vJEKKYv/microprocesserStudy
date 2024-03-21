#include "mbed.h"
PwmOut led1(D6);
// main() runs in its own thread in the OS
int main()
{
    float value = 0.0;
    while (true) {
        led1 = value;
        if(value>=1.0){
            value = 0;
            printf("reset\n");
        }else{
            value+=0.1;
            //printf("up");
        }
        ThisThread::sleep_for(100ms);
    }
}

