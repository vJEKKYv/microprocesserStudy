#include "mbed.h"
InterruptIn sw(BUTTON1);
DigitalOut led1(LED1);
DigitalOut led2(D7);
void ISR(){
    led2 =! led2;
    //ThisThread::sleep_for(500ms);
}
int main()
{   
    sw.fall(&ISR);
    while (true) {
        led1 =! led1;
        ThisThread::sleep_for(500ms);
    }
}
