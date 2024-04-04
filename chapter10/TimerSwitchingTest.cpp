#include "mbed.h"
#define SAMPLE_INTERVAL 10000
Timer watch;
DigitalOut led(LED1);
int main()
{   
    watch.start();
    led=0;
    while (true) {
        if(watch.read_us()>SAMPLE_INTERVAL){
            watch.reset();
            led=!led;
        }
    }
}

