#include "mbed.h"
class CounterUD{
    InterruptIn _up, _down;
    volatile int _count;
    volatile bool _updated;
    void plus(){
        _count++;
        _updated=true;
    }
    void minus(){
        _count--;
        _updated=true;
    }
    public:
    CounterUD(PinName p1, PinName p2): _up(p2,PullUp), _down(p1,PullUp){
        _count=0;   _updated=false;
        _up.fall(callback(this, &CounterUD::plus));
        _down.fall(callback(this, &CounterUD::minus));
    }
    int read(){ _updated=false; return _count;    }
    bool isUpdated(){   return _updated;    }
    void clear(){   _count = 0; }
};
CounterUD cnt(BUTTON1, D2);
int main()
{   
    while (true) {
        if(cnt.isUpdated()){
            printf("count = %3d\n",cnt.read());
        }
        ThisThread::sleep_for(100ms);
    }
}
