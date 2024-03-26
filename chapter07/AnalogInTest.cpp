#include "mbed.h"
AnalogIn POT(A0);
// main() runs in its own thread in the OS
int main()
{
    while (true) {
        float voltage = POT*3.3f;
        uint16_t value = POT.read_u16();
        printf("POT Value = %u, Voltage = %u.%-2u \n", value, (int)voltage, (int)((voltage-(int)voltage)*100.));
        ThisThread::sleep_for(500ms);
    }
}
