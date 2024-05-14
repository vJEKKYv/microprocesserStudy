#include "mbed.h"
#include <cstdint>

typedef struct{
    float     voltage, current;
    uint32_t  counter;
}message_t;
MemoryPool<message_t,16> mpool;
Queue<message_t, 16> queue;
Thread thread;
void generator(void)
{
    uint32_t i = 0;
    while (true) {
        i++;
        message_t *message = mpool.alloc();
        message -> voltage = (i*0.1)*33;
        message -> current = (i*0.1)*11;
        message -> counter = i;
        queue.put(message);
        ThisThread::sleep_for(1s);
    }
}
int main(){
    thread.start(&generator);
    while(true){
        osEvent evt = queue.get();
        if(evt.status == osEventMessage){
            message_t*message = (message_t*)evt.value.p;
            printf("\nVoltage: %d.%d V \n",int(message->voltage),int(((message->voltage)-int(message->voltage))*100));
            printf("\nCurrent: %d.%d V \n",int(message->current),int(((message->current)-int(message->current))*100));
            printf("Number of cycles: %u\n",message -> counter);
            mpool.free(message);
            
        }
    }
}

