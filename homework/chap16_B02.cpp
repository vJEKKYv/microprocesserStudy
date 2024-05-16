#include "mbed.h"
#define BUF_SIZE    10
typedef struct{
    float a0,a1,a2,a3;
}ADATA;
CircularBuffer<ADATA, BUF_SIZE> buff;
AnalogIn a0(A0),a1(A1),a2(A2),a3(A3);
Ticker tickman;
void readAnalog(){
    if(!buff.full()){
        ADATA adata;
        adata.a0 = a0;
        adata.a1 = a1;
        adata.a2 = a2;
        adata.a3 = a3;
        buff.push(adata);
    }
}
int main()
{
    tickman.attach(&readAnalog,0.1);
    ADATA adata;
    while (true) {
        if(buff.pop(adata)){
            printf("\nVoltage: %d.%d V \t",int(adata.a0),int(((adata.a0)-int(adata.a0))*1000));
            printf("\nVoltage: %d.%d V \t",int(adata.a1),int(((adata.a1)-int(adata.a1))*1000));
            printf("\nVoltage: %d.%d V \t",int(adata.a2),int(((adata.a2)-int(adata.a2))*1000));
            printf("\nVoltage: %d.%d V \t",int(adata.a3),int(((adata.a3)-int(adata.a3))*1000));
        }
        ThisThread::sleep_for(10ms);
    }
}

