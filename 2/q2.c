#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define delay 500

int main(){
    DDRB |= (1<<0);
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
    // if(PORTB & (1<<0))
    //     PORTB = 0;
    // else
    //     PORTB = 0xFF;
    PORTB ^= 1;
     _delay_ms(delay);
}