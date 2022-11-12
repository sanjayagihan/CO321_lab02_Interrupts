#include <avr/io.h>
#include<util/delay.h>
#define delay 1000

int main(){
    unsigned char count = 1;
    DDRB = 0xFF;
    DDRD = DDRD & ~(1<<7);
    while (1){
        if(PIND & (1<<7)){
          	if(count>252)
          		count = 1;
            PORTB = count;
          	_delay_ms(delay);
            count++;
        }
    }
}