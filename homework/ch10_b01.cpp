#include "mbed.h"
Timeout tmo;
InterruptIn btn(BUTTON1);
DigitalOut led1(LED1);

void blink(){led1 = 1;}
void flip(){
    if (led1 == 1)  led1=0;
    else    tmo.attach(&blink, 1s);
}
int main(){
    btn.fall(&flip());
    while (true) {ThisThread::sleep_for(100ms);}
}

