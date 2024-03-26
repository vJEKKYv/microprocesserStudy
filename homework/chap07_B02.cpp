// Nucloe의 A0에서 A5핀의 전압을 0.5초마다 차례로 ADC 하여 PC에 16비트 정수로 표시하는 코드를 작성하라. 단, 객체의 배열을 사용한다. 
#include "mbed.h"
AnalogIn adc[5] = {A0,A2,A3,A4,A5};
int main()
{
    while(true){
        for(int i = 0; i < 5; i++){
            printf("A%d = %u V\t",i,adc[i].read_u16());
        }
        printf("\n");        ThisThread::sleep_for(500ms);
    }
}
