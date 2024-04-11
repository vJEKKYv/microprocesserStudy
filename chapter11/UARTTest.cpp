//11장 과제와 동일. 
#include "mbed.h"
#include <string>

DigitalOut led1(LED1);
UnbufferedSerial pc(USBTX, USBRX);
volatile bool gotPacket = false;
volatile float data[4];

void onSerialRx() {
    static char serialInBuffer[32];
    static int data_cnt = 0,buff_cnt = 0;
    if(pc.readable()) {
        char byteIn;
        pc.read(&byteIn, 1);
        if(byteIn==',') {
            serialInBuffer[buff_cnt] = '\0';
            data[data_cnt++] = atof(serialInBuffer);
            buff_cnt = 0;
        } else  serialInBuffer[buff_cnt++] = byteIn;
        
        if(data_cnt >= 4) {
            data_cnt=0;
            gotPacket = true;
            return;
        } else{}
    }
}
int main () {
    pc.attach(&onSerialRx);
    while(true) {
        if(gotPacket) {
            gotPacket = false;
            printf("\ndata= %d.%d, %d.%d, %d.%d, %d.%d\n\r",    (int)data[0], (int)((data[0] - (int)data[0])*1000),
                                                                (int)data[1], (int)((data[1] - (int)data[1])*1000),
                                                                (int)data[2], (int)((data[2] - (int)data[2])*1000),
                                                                (int)data[3], (int)((data[3] - (int)data[3])*1000));
        }
        led1=!led1;
        ThisThread::sleep_for(200ms);
    }
}
