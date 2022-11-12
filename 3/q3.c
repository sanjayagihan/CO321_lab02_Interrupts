#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define delay 2000

int count = 1;

int main(){
    DDRB = 0xFF;
    DDRD = DDRD & ~(1<<2);
    EICRA |= (1<<ISC01);
    EICRA &= ~(1<<ISC00);
    sei();
    EIMSK |= (1<<INT0);
    while(1){
    }
    return 0;
}

ISR (INT0_vect){
    if(count>63)
        count = 1;
    PORTB = count;
    count++;
    _delay_ms(delay);
}