#include "mbed.h"
// BUTTON1은 기본적으로 PULLUP 저항이므로 신호가 들어가지 않을때 1을 출력. 따라서 신호를 역전시켜 대입시켜한다. 
DigitalIn sw(BUTTON1);
DigitalOut lamp(BUTTON1);
int main()
{   
    while (1) {
        lamp = !sw;
    }
}

