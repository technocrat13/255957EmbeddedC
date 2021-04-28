
#include <avr/io.h>
#include "project_config.h"
#include "activity1.h"

void heaterSwitchCheck()
{
    if (!(PIND & (1 << switch1)) && !(PIND & (1 << switch2))) // pressed is on
    {
        PORTB |= (1 << LED);
    }
    else
    {
        PORTB &= ~(1 << LED);
    }
}
