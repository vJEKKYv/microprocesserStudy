#include "mbed.h"
#define BUF_SIZE    10
DigitalInOut led(LED1);
CircularBuffer<char, BUF_SIZE> buff;
UnbufferedSerial pc(USBTX, USBRX);
Ticker tickman;
void dataArrived(){
    if(pc.readable()){
        char c; pc.read(&c, BUF_SIZE);
        if(!buff.full())
            buff.push(c);
    }
}
void pusher(){
    if(!buff.full()){
        buff.push('!');
    }
}
int main()
{
    tickman.attach(&pusher,1.0);
    pc.attach(&dataArrived);
    char c;
    while (true) {
        led = buff.full()? 0:1;
        if(!buff.empty()){
            buff.pop(c);
            printf("size: %u    got: '%c'\n", buff.size(), c);
        }
        ThisThread::sleep_for(500ms);
    }
}

