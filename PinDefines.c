/*
 * PinDefines.c
 *
 * Created: 01/09/2018 15:10:10
 *  Author: Marko Sagadin
 */ 
#include "PinDefines.h"

void InitNixiePins()
{	
	//Set pins for driving bcd to dec decoders to outputs
	//Hours, ure
	SET_BIT(DDRD, U_A);
	SET_BIT(DDRD, U_D);
	SET_BIT(DDRB, U_B);
	SET_BIT(DDRB, U_C);
	
	//Minutes
	SET_BIT(DDRB, M_A);
	SET_BIT(DDRB, M_B);
	SET_BIT(DDRB, M_C);
	SET_BIT(DDRB, M_D);
	
	//Seconds
	SET_BIT(DDRC, S_A);
	SET_BIT(DDRC, S_B);
	SET_BIT(DDRC, S_C);
	SET_BIT(DDRC, S_D);
	
	//Anode 
	SET_BIT(DDRD, A10H);
	SET_BIT(DDRB, A1H);
	SET_BIT(DDRD, A10M);
	SET_BIT(DDRD, A1M);
	SET_BIT(DDRD, A10S);
	SET_BIT(DDRD, A1S);

	//Set the to logical zero 
	//Hours	
	RESET_BIT(PORTD, U_A);
	RESET_BIT(PORTD, U_D);
	RESET_BIT(PORTB, U_B);
	RESET_BIT(PORTB, U_C);
	
	//Minutes
	RESET_BIT(PORTB, M_A);
	RESET_BIT(PORTB, M_B);
	RESET_BIT(PORTB, M_C);
	RESET_BIT(PORTB, M_D);	

	//Seconds	
	RESET_BIT(PORTC, S_A);
	RESET_BIT(PORTC, S_B);
	RESET_BIT(PORTC, S_C);
	RESET_BIT(PORTC, S_D);
	
	//Anodes
	RESET_BIT(PORTD, A10H);
	RESET_BIT(PORTB, A1H);
	RESET_BIT(PORTD, A10M);
	RESET_BIT(PORTD, A1M);
	RESET_BIT(PORTD, A10S);
	RESET_BIT(PORTD, A1S);
}

void InitButtons()
{
	/* Set button inputs, enable pull ups, debounce 
	and active low logic are solved in separate functions */
	RESET_BIT(DDRB, CYCLE_BUTTON);
	RESET_BIT(DDRD, SET_BUTTON);
	
	SET_BIT(PORTB, CYCLE_BUTTON);
	SET_BIT(PORTD, SET_BUTTON);
}