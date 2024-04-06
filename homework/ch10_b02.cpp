//Timer 클래스를 이용하여 𝑥 값이 1, 2, ... 10000까지의 변할 때 아래와 같은 RMS(root meansquare)를 구하는데 소요되는 시간을 us단위로 PC에 출력하는 프로그램을 작성하라. 단, computeRMS라는 함수로 만들어 RMS값을 반환 받도록 한다. 
//rms=입력 값들을 각각 제곱, 그 수를 다 더한 것을 전체 제곱근. (like L2 norm 연산)
#include "mbed.h"
#include "math.h"
#define SAMPLE_INTERVAL 10000
double computeRMS() {
    uint64_t sum = 0, i;
    for (i = 1; i <= 10000; i++)    sum +=i*i;
    return  sqrt((double)sum / (i-1));
}
Timer watch;
int main()
{   
    double RMS;
    while (true) {
        watch.reset();  watch.start();  RMS = computeRMS(); watch.stop();
        printf("RMS=%8.3f, Time=%uus\n", RMS, watch.read_us());
        ThisThread::sleep_for(1s);
    }
}

