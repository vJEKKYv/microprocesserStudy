#include "mbed.h"
Timeout tmo;
DigitalOut led1(LED1);
DigitalOut led2(D7,1);

void flip(){
    led2 = !led2;
}
int main()
{
    tmo.attach(&flip, 10s);
    while (true) {
        led1=!led1;
        ThisThread::sleep_for(100ms);
    }
}

