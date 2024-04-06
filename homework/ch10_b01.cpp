//TimeOut 클래스와 InterruptIn 클래스를 이용하여 푸시 버튼(BUTTON1)을 누르면 1초 후에 led(LED1)가 켜지고 한번 더 누르면 곧바로 꺼지는 프로그램을 작성하라. 

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

