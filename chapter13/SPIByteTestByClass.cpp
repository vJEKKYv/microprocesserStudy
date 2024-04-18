#include "mbed.h"
#include <cstdint>
#define WHO_AM_I    0x75
#define SPI_READ    0x80

class Dummy{
    SPI _spi;
    DigitalOut _ss;
    public:
    Dummy(PinName mosi, PinName miso, PinName clk, PinName ss):
    _spi(mosi, miso, clk),_ss(ss){
        _ss=1;
        _spi.format(8,3);
        _spi.frequency(15000000);
    }
    uint8_t readByte(uint8_t address){
        _ss = 0;
        _spi.write(address | SPI_READ);
        int data = _spi.write(0x33);
        _ss = 1;
        return data;
    }
};

UnbufferedSerial pc(USBTX, USBRX, 115200);
Dummy dum(D11,D12,D13,D2);
int main()
{
    while (true) {
        printf("WHOAMI register = 0x%X\n",dum.readByte(WHO_AM_I));
        ThisThread::sleep_for(1s);
    }
}

