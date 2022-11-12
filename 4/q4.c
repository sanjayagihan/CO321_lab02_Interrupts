#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define delay 2000


int main(){
    DDRB = 0xFF;            // output port
    PORTB = 0;              // initialize to zero
    DDRD = DDRB & ~(1<<2);  // input port PD2
    DDRD = DDRB & ~(1<<3);  // input port PD3
    EICRA |= (1<<ISC01);    // rising edge for both INT0 and INT1
    EICRA &= ~(1<<ISC00);
    EICRA |= (1<<ISC11);
    EICRA &= ~(1<<ISC10);
    sei();                  // enable interupts globaly
    EIMSK |= (1<<INT0);     // enable INT0 for interupts
    EIMSK |= (1<<INT1);     // enable INT0 for interupts
    while(1){
    }                       // to run program witout terminating
    return 0;
}

//0
ISR (INT0_vect){
    PORTB = (PORTB<<1);     // shift all bits by 1 
    PORTB = PORTB & ~(1<<0);// update last bit
    _delay_ms(delay);
}

//1
ISR (INT1_vect){
    PORTB = (PORTB<<1);     // shift all bits by 1 
    PORTB = PORTB | (1<<0); // update last bit
    _delay_ms(delay);
}
