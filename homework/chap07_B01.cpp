// 가변저항의 회전에 따라 RC 서보모터가 비례적으로 회전하도록 한다. 단 POT의 최소와 최대 회전 각도가 RC 서보의 0°와 180°에 대응하도록 한다.
#include "mbed.h"v
AnalogIn POT(A0);
PwmOut rcServo(D6);
void Turn(PwmOut &rc, float deg);
template<class T>
T map(T x, T in_min, T in_max, T out_min, T out_max);
int main()
{
    rcServo.period_ms(10);
    float ang = 0., inc = 0.1;
    Turn(rcServo,0);
    while (true) {
        int value = (int)(POT.read()*10.);
        Turn(rcServo, ang);
        ThisThread::sleep_for(10ms);
        ang+=inc*value;
        if(ang>180.f || ang < 0.f)  inc = -inc;
    }
}
void Turn(PwmOut &rc, float deg){
    uint16_t pulseW = map<float>(deg,0,180,600,2400);
    rc.pulsewidth_us(pulseW);
}
template<class T>
T map(T x, T in_min, T in_max, T out_min, T out_max){
    return (x-in_min)*(out_max-out_min) / (in_max-in_min) + out_min;
}
