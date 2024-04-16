#include "mbed.h"
#include "Adafruit_SSD1306.h"

I2C myI2C(D14,D15);
Adafruit_SSD1306_I2c OLED(myI2C, D2, 0x78, 64, 128);

int main()
{
    int16_t x=0;
    float inc = 0.0f, force = 1.0f;
    myI2C.frequency(400000);
    OLED.begin();
    OLED.printf("Hello World\r\n");
    OLED.display();
    while (true) {
        OLED.fillRect(0,19,128,12,0);
        OLED.drawRect(x,20,10,10,1);
        OLED.display();
        inc+=0.1f*force;    x+=inc;
        if(x>118 || x<0){force=-force;  inc=0.0f;}
        ThisThread::sleep_for(10ms);
    }
}
