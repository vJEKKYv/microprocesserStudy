#include "mbed.h"
Thread thread;
DigitalOut led1(LED1), led2(D7);
volatile bool running = true;
void blink(DigitalOut *led){
    while(running){
        *led =! *led;
        ThisThread::sleep_for(20ms);
    }
}
int main()
{
    thread.start(callback(&blink, &led1));
    led2=1;
    ThisThread::sleep_for(5s);
    running=false;
    thread.join();
    led2=0;
}

