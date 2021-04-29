
#include <avr/io.h>
#include "project_config.h"
#include "activity3.h"
#include <util/delay.h>
#include <avr/interrupt.h>

void initPWM()
{
    /*
    TCCR0A |= (1 << COM0A1) | (0 << COM0A0);
    // set non-inverting mode

    TCCR0A |= (1 << WGM01) | (1 << WGM00);
    // set fast PWM Mode

    TCCR0B |= (1 << CS01) | (1 << CS00);
    // set prescaler to 64 and starts PWM
    */

    TCCR1A |= (1 << COM1A1) | (1 << WGM11) | (1 << WGM10);
    TCCR1B |= (1 << WGM12) | (1 << CS11) | (1 << CS10);
//    DDRB |= (1 << PB1);
    DDRB |= (1 << PWM_OUT);
}

 void potScaler(uint16_t pot)
 {
     initPWM();
     OCR1A = abs(pot - 1);
     _delay_ms(300);
 }