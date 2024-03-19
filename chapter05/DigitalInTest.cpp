#include "mbed.h"
// main() runs in its own thread in the OS
int main()
{
    DigitalOut myLed(LED1);
    srand(time(NULL));
    printf("Hello world");
    while(true) {
        
        float v = (float)rand()/(float)RAND_MAX;
        //myLed = 1;
        myLed = (v<0.1f)? 1:0;
        ThisThread::sleep_for(100ms);
    }
}

