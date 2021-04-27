
#include <avr/io.h>
#include "project_config.h"
#include "activity1.h"

void hallwaySwitch()
{
    DDRB |= (1 << LED);
    DDRD &= ~(1 << switch1);
    PORTD |= (1 << switch1);

    DDRD &= ~(1 << switch2);
    PORTD |= (1 << switch2);

    // Insert code

    while (1)
    {
        if (!(PIND & (1 << switch1))) // pressed is on
        {
            if (!(PIND & (1 << switch2)))
            {
                PORTB |= (1 << LED);
            }
            else
            {
                PORTB &= ~(1 << LED);
            }

            //_delay_ms(1000);
        }
        
        else
        {
            if (!(PIND & (1 << switch2)))
            {
                PORTB &= ~(1 << LED);
            }
            else
            {
                PORTB &= ~(1 << LED);
            }
            //PORTB &= ~(1 << LED);

            //_delay_ms(1000);
        }

    };
}