/*
 * i2c.c
 *
 * Created: 16. 04. 2018 17:33:18
 *  Author: Marko
 */ 


#include "i2c.h"


void init() {
	TWSR = 0;
	TWBR = ((F_CPU/SCL_CLOCK)-16)/2;
	TWCR = (1<<TWEN);
}


void write(uint8_t data) {
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);

	
	while(!(TWCR & (1<<TWINT)));
}

void stop() {
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	
	while(TWCR & (1<<TWSTO));
}

void startRtc() {
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while((TWCR & (1<<TWINT)) == 0);
}

uint8_t read(uint8_t ack)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(ack<<TWEA);
	while ((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}
