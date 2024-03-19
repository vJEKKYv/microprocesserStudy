#include "mbed.h"

// main() runs in its own thread in the OS
DigitalOut led(LED1);
DigitalIn but(BUTTON1);
DigitalIn but2(D2, PullUp);

int main()
{
    while (true) {
        if(!but2){
            led =!led;
            ThisThread::sleep_for(300ms);
        }
    }
}
