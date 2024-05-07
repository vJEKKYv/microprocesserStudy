#include "mbed.h"
Mutex mutex;
Thread t2,t3;
int cnt=0;
DigitalOut led(LED1);
void notify(const char* name, int ct){
    printf("%s: %3d\n\r", name, ct);
}
void thread_plus(const char* args){
    while(true){
        mutex.lock();
        led =! led;
        notify((const char*)args, ++cnt);
        mutex.unlock();
        ThisThread::sleep_for(490ms);
    }
}
void thread_mius(const char* args){
    while(true){
        mutex.lock();
        led =! led;
        notify((const char*)args, --cnt);
        mutex.unlock();
        ThisThread::sleep_for(1s);
    }
}
int main()
{
    t2.start(callback(&thread_plus,(const char*)"Th 2"));
    t3.start(callback(&thread_mius,(const char*)"Th 3"));

    thread_mius((const char*)"Th 1");
}

