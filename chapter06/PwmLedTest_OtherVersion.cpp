#include "mbed.h"
PwmOut led1(D6);
// main() runs in its own thread in the OS
int main()
{
    int cnt = 0;
    led1.period_us(25);
    while (true) {
        led1 = cnt/100.; // . <- 꼭 붙이기
        cnt++;
        cnt%=101;
        ThisThread::sleep_for(100ms);
    }
}

