#include "mbed.h"
#include "Adafruit_SSD1306.h"

I2C myI2C(D14,D15);
Adafruit_SSD1306_I2c OLED(myI2C, D2, 0x78, 64, 128);

void OLED_drawString(char *str){
    for(int i=0;str[i];i++){
        OLED.writeChar(str[i]);
    }
}

int main()
{
    OLED.clearDisplay();
    OLED.setTextSize(2);
    OLED_drawString("TUK");

    OLED.setTextSize(1);
    OLED.setTextCursor(0, 20);
    OLED_drawString("ComputerEngineering");

    OLED.setTextSize(2);
    OLED.setTextCursor(0, 30);
    OLED_drawString("Cheers~");
    
    OLED.display();

    while (true){}
}
