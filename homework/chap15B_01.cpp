#include "mbed.h"
typedef struct{
    float a0, a1, a2, a3;
}message_t;
MemoryPool<message_t,16> mpool;
Queue<message_t, 16> queue;
Thread thread1, thread2;
AnalogIn a0(A0),a1(A2),a2(A3),a3(A4);
void generator(void){
    while (true) {
        message_t *message = mpool.alloc();
        message-> a0 = a0;
        message-> a1 = a1;
        message-> a2 = a2;
        message-> a3 = a3;
        queue.put(message);
        ThisThread::sleep_for(100ms);
    }
}
int main(){
    thread1.start(&generator);
    while(true){
        osEvent evt = queue.get();
        if(evt.status == osEventMessage){
            message_t*message = (message_t*)evt.value.p;
            printf("\nVoltage: %d.%d V \t",int(message->a0),int(((message->a0)-int(message->a0))*1000));
            printf("\nVoltage: %d.%d V \t",int(message->a1),int(((message->a1)-int(message->a1))*1000));
            printf("\nVoltage: %d.%d V \t",int(message->a2),int(((message->a2)-int(message->a2))*1000));
            printf("\nVoltage: %d.%d V \n",int(message->a3),int(((message->a3)-int(message->a3))*1000));
            mpool.free(message);
        }
        ThisThread::sleep_for(10ms);
    }
}
