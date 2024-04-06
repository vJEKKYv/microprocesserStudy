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

