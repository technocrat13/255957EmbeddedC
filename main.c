/*
 */

#include <avr/io.h>
#include "project_config.h"

#include "activity1.h"
#include "activity2.h"


int main(void)
{
    DDRB |= (1 << LED);
    DDRD &= ~(1 << switch1);
    PORTD |= (1 << switch1);

    DDRD &= ~(1 << switch2);
    PORTD |= (1 << switch2);

    initADC();
    uint16_t potReading;
    // Insert code

    while (1)
    {
        heaterSwitchCheck();
        potReading = readADC(channel);
    };
    
    return 0;
}
