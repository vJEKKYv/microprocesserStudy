#include "mbed.h"
class Counter{
    InterruptIn _interrupt;
    volatile uint16_t _count;
    volatile bool _updated;
    void isr(){
        _count++;
        _updated = 1;
    }
    public:
    Counter(PinName pin): _interrupt(pin){
        _count=0;   _updated=0;
        _interrupt.fall(callback(this, &Counter::isr));
    }
    uint16_t read(){    _updated=0; return _count;   }
    bool isUpdated(){   return _updated;    }
    void clear(){   _count = 0; }
};
Counter cnt(BUTTON1);
int main()
{   
    while (true) {
        if(cnt.isUpdated()){
            printf("count = %3d\n",cnt.read());
        }if(cnt.read()>=100){
            cnt.clear();
            printf("count is fulled. clear count. \n");
        }
        ThisThread::sleep_for(100ms);
    }
}
