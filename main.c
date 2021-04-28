/*
 */

#include <avr/io.h>
#include "project_config.h"

#include "activity1.h"


int main(void)
{
    DDRB |= (1 << LED);
    DDRD &= ~(1 << switch1);
    PORTD |= (1 << switch1);

    DDRD &= ~(1 << switch2);
    PORTD |= (1 << switch2);

    // Insert code

    while (1)
    {
        heaterSwitchCheck();

    };
    
    return 0;
}
