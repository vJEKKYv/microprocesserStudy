#include "mbed.h"
// 디바운싱을 위해 약간의 딜레이를 주어 바운싱이 될 수 있는 구간의 신호를 논리적으로 제거
DigitalOut led1(D2);
DigitalOut led2(D3);
DigitalIn sw(BUTTON1);
int main()
{   
    while (1) {
        if(sw){
            led1 = !sw;
            led2 = sw;
            ThisThread::sleep_for(3ms);
        }else{
            led1 = sw;
            led2 = !sw;
            ThisThread::sleep_for(3ms);
        }
    }
}

