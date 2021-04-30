/*
 */

#include <avr/io.h>
#include "project_config.h"
#include <util/delay.h>
#include <avr/interrupt.h>

#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"


int main(void)
{
    DDRB |= (1 << LED);
    DDRD &= ~(1 << switch1);
    PORTD |= (1 << switch1);

    DDRD &= ~(1 << switch2);
    PORTD |= (1 << switch2);

    initADC();
    uint16_t potReading;
    initUSART();
    // Insert code

    //initPWM();
    //DDRD |= (1 << PWM_OUT);

    //OCR0A = 128;

    while (1)
    {
        if(heaterSwitchCheck() == 1)
        {
            //OCR0A = 128;
            PORTB |= (1 << LED);
            potReading = readADC(channel);
            initPWM();
            if (0 <= potReading && potReading < 200)
            {
                OCR1A = 205;
                int temp = 20; 
                USARTPrint(temp);
                _delay_ms(300);
                
                //20%
            }
            else if(200 <= potReading && potReading < 500)
            {
                OCR1A = 410;
                int temp = 25;
                USARTPrint(temp);
                _delay_ms(300);
                //40%
            }
            else if(500 <= potReading && potReading < 700)
            {
                OCR1A = 719;
                int temp = 29;
                USARTPrint(temp);
                _delay_ms(300);
                //70%
            }
            else if(700 <= potReading && potReading <= 1024)
            {
                OCR1A = 972;
                int temp = 33;
                USARTPrint(temp);
                _delay_ms(300);
                //95%
            }
            else
            {
                OCR1A = 0;
                _delay_ms(200);
            }
            
           //potScaler(potReading);
        }
        else 
        {
            PORTB &= ~(1 << LED);
            //OCR0A = 0;
            _delay_ms(300);
        }

    };
    
    return 0;
}
