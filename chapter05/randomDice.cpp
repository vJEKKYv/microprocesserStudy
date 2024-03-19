#include "mbed.h"

// main() runs in its own thread in the OS
DigitalOut led(LED1);
DigitalIn but(BUTTON1);
DigitalIn but2(D2, PullUp);

int main()
{
    srand(time(NULL));    
    while (true) {
        if(!but){
            printf("%u \n",rand()%6+1);
            ThisThread::sleep_for(300ms);
        }
    }
}

