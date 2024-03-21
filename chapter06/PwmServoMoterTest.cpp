//서보모터를 0~180도를 천천히 반복
#include "mbed.h"
PwmOut rcServo(D6);
void Turn(PwmOut &rc, float deg);
template<class T>
T map(T x, T in_min, T in_max, T out_min, T out_max);
int main()
{
    float ang = 0., inc = 0.1;
    rcServo.period_ms(10);
    Turn(rcServo,0);
    while (true) {
        Turn(rcServo, ang);
        ThisThread::sleep_for(10ms);
        ang+=inc;
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

