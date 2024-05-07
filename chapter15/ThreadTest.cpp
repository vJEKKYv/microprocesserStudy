#include "mbed.h"
DigitalOut led1(LED1), led2(D7);
Thread thread;
void led1_thread(){
    while(true){
        led1=!led1;
        ThisThread::sleep_for(100ms);
    }
}
int main()
{
    thread.start(&led1_thread);
    while (true) {
        led2=!led2;
        ThisThread::sleep_for(500ms);
    }
}
