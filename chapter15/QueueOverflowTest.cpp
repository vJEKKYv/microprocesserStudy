#include "mbed.h"
UnbufferedSerial pc(USBTX,USBRX);
MemoryPool<uint32_t,16> mpool;
Queue<uint32_t, 16> queue;
Thread thread;
Mutex uart_mutex;
DigitalOut led(LED1);
void send_Thread(void){
    uint32_t i=0;
    while(true){
        uint32_t *value = mpool.alloc();
        *value = i;
        if(queue.full()){
            uart_mutex.lock();
            printf("Thread: waiting...\n");
            uart_mutex.unlock();
            ThisThread::sleep_for(3s);
        }
        queue.put(value);
        uart_mutex.lock();
        printf("Thread: %d\n",*value);
        uart_mutex.unlock();
        ThisThread::sleep_for(400ms);
        i++;
    }
}
int main(){
    thread.start(&send_Thread);
    uint32_t cnt=0;
    while(true){
        osEvent evt = queue.get(0);
        if(evt.status == osEventMessage){
            led=!led;
            uint32_t *value = (uint32_t*)evt.value.p;
            uart_mutex.lock();
            printf("Main: %d\n",*value);
            uart_mutex.unlock();
            mpool.free(value);
        }
        if(cnt%20==0){
            uart_mutex.lock();
            printf("Main: waiting...\n");
            uart_mutex.unlock();
            ThisThread::sleep_for(2s);
        }
        // 시간 길게 가져가면 오버플로우 발생. thread쪽의 시간보다 짧은 시간 가져가야 한다. 
        ThisThread::sleep_for(1s);
        cnt++;
        
    }
}

