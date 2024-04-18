#include "mbed.h"
#define WHO_AM_I    0x75
#define SPI_READ    0x80
SPI spi(D11,D12,D13);
DigitalOut ss(D2);
int main()
{
    ss=1;
    spi.format(8,3);
    spi.frequency(15000000);
    while (true) {
        ss=0;
        spi.write(WHO_AM_I | SPI_READ);
        int whoami = spi.write(0);
        printf("WHOAMI register = 0x%X\n",whoami);
        ss=1;
        ThisThread::sleep_for(1s);
    }
}

