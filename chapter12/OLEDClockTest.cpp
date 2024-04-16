//미완성. 
#include "mbed.h"
#include "Adafruit_SSD1306.h"
#define REG_SEC         (0x02)
#define REG_MIN         (0x03)
#define REG_HOUR        (0x04)
#define PCF8563_ADDR    (0xD0)

I2C myI2C(I2C_SDA, I2C_SCL);
DigitalOut LED(LED1);
//void writeByte(uint8_t address, uint8_t subAddress, uint8_t data);
char readByte(uint8_t address, uint8_t subAddress);
uint8_t bcdToDec(uint8_t val);
//uint8_t decToBcd(uint8_t val);
Adafruit_SSD1306_I2c OLED(myI2C, D2, 0x78, 32, 128);

int main()
{
    OLED.begin();
    OLED.setTextSize(1);
    OLED.printf("16/APRIL/2024\r\n\n");
    OLED.setTextSize(2);
    OLED.display();
    while (true) {
        char s = readByte(PCF8563_ADDR, REG_SEC);
        char m = readByte(PCF8563_ADDR, REG_MIN);
        char h = readByte(PCF8563_ADDR, REG_HOUR);
        OLED.printf("%02u:%02u:%02u\r", bcdToDec(h & 0x3F),bcdToDec(m & 0x7F),bcdToDec(s & 0x7F));
        OLED.display();
    }
}
char readByte(uint8_t address, uint8_t subAddress){
    char data[1];
    char data_write[1];
    data_write[0] = subAddress;
    myI2C.write(address,data_write, 1,1);
    myI2C.read(address, data,1,0);
    return data[0];
}
uint8_t bcdToDec(uint8_t val){
    return ((val/16)*10 + (val%16));
}
