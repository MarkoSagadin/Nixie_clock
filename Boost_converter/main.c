#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>

int main(void)
{	
	DDRB = 1<<DDB4 | 1<<DDB1 | 1<<DDB0;
    TCCR0A = 2<<COM0A0 | 2<<COM0B0 | 3<<WGM00;
    TCCR0B = 0<<WGM02 | 1<<CS00 | 1<<CS01 | 0<<CS02; 
    TCCR1 = 0<<PWM1A | 0<<COM1A0 | 1<<CS10;
    GTCCR = 1<<PWM1B | 2<<COM1B0;
	
	OCR1B = 249;		// 92% duty cycle
	
	while(1)
	{
		 
	}
	
	}