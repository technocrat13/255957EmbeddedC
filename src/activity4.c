
#include <avr/io.h>
#include "project_config.h"
#include "activity4.h"
#include <util/delay.h>

void initUSART()
{
    UBRR0H = (uint8_t)(UBRR_VALUE >> 8);
    UBRR0L = (uint8_t)UBRR_VALUE;
    UCSR0C = (1 << UMSEL00) | (1 << UCSZ01) | (1 << UCSZ00);
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0) | (1 << TXCIE0);
}

void USARTPrint(uint16_t data)
{
    while (!(UCSR0A & (1 << UDRE0)));            // Wait for empty transmit buffer
    UDR0 = data; // Put data into buffer, sends the data
}

void USARTPrintHighRes(int data)
{
    //1024 == 35
    //0 == 
}

