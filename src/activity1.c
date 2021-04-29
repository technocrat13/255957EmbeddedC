
#include <avr/io.h>
#include "project_config.h"
#include "activity1.h"

int heaterSwitchCheck()
{
    if (!(PIND & (1 << switch1)) && !(PIND & (1 << switch2))) // pressed is on
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
