#include "mbed.h"

class Blinker{ 
    Ticker _tick;   DigitalOut _led;
    void blink(){_led =! _led;}
    public:
    Blinker(PinName pin): _led(pin){_led = 0;}
    void begin(float sec){_tick.attach(callback(this, &Blinker::blink), sec);}
};
Blinker blink1(LED1), blink2(D7);
int main(){blink1.begin(0.1);  blink2.begin(0.2);}
