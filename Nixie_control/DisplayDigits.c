/*
 * DisplayDigits.c
 *
 * Created: 28/08/2018 18:58:20
 *  Author: Marko Sagadin
 */ 

#include "DisplayDigits.h"
#include "PinDefines.h"
#define NUMBER_DELAY_US (1000) //Delay between separate digits, in microseconds





void Zero(int display)
{
	switch(display)
	{
		case 1:
		RESET_U_A;
		RESET_U_B; 
		RESET_U_C;
		RESET_U_D;
		break;
		
		case 2:
		RESET_M_A;
		RESET_M_B;
		RESET_M_C;
		RESET_M_D;
		break;
		
		case 3:
		RESET_S_A;
		RESET_S_B;
		RESET_S_C;
		RESET_S_D;
		break;
	}
}

void One(int display)
{
	switch(display)
	{
		case 1:
		SET_U_A;
		RESET_U_B; 
		RESET_U_C;
		RESET_U_D;
		break;
		
		case 2:
		SET_M_A;
		RESET_M_B;
		RESET_M_C;
		RESET_M_D;
		break;
		
		case 3:
		SET_S_A;
		RESET_S_B;
		RESET_S_C;
		RESET_S_D;
		break;
	}
}

void Two(int display)
{
	switch(display)
	{
		case 1:
		RESET_U_A;
		SET_U_B;
		RESET_U_C;
		RESET_U_D;
		break;
		
		case 2:
		RESET_M_A;
		SET_M_B;
		RESET_M_C;
		RESET_M_D;
		break;
		
		case 3:
		RESET_S_A;
		SET_S_B;
		RESET_S_C;
		RESET_S_D;
		break;
	}
}

void Three(int display)
{
	switch(display)
	{
		case 1:
		SET_U_A;
		SET_U_B;
		RESET_U_C;
		RESET_U_D;
		break;
		
		case 2:
		SET_M_A;
		SET_M_B;
		RESET_M_C;
		RESET_M_D;
		break;
		
		case 3:
		SET_S_A;
		SET_S_B;
		RESET_S_C;
		RESET_S_D;
		break;
	}
}

void Four(int display)
{
	switch(display)
	{
		case 1:
		RESET_U_A;
		RESET_U_B;
		SET_U_C;
		RESET_U_D;
		break;
		
		case 2:
		RESET_M_A;
		RESET_M_B;
		SET_M_C;
		RESET_M_D;
		break;
		
		case 3:
		RESET_S_A;
		RESET_S_B;
		SET_S_C;
		RESET_S_D;
		break;
	}
}

void Five(int display)
{
	switch(display)
	{
		case 1:
		SET_U_A;
		RESET_U_B;
		SET_U_C;
		RESET_U_D;
		break;
		
		case 2:
		SET_M_A;
		RESET_M_B;
		SET_M_C;
		RESET_M_D;
		break;
		
		case 3:
		SET_S_A;
		RESET_S_B;
		SET_S_C;
		RESET_S_D;
		break;
	}
}

void Six(int display)
{
	switch(display)
	{
		case 1:
		RESET_U_A;
		SET_U_B;
		SET_U_C;
		RESET_U_D;
		break;
		
		case 2:
		RESET_M_A;
		SET_M_B;
		SET_M_C;
		RESET_M_D;
		break;
		
		case 3:
		RESET_S_A;
		SET_S_B;
		SET_S_C;
		RESET_S_D;
		break;
	}
}

void Seven(int display)
{
	switch(display)
	{
		case 1:
		SET_U_A;
		SET_U_B;
		SET_U_C;
		RESET_U_D;
		break;
		
		case 2:
		SET_M_A;
		SET_M_B;
		SET_M_C;
		RESET_M_D;
		break;
		
		case 3:
		SET_S_A;
		SET_S_B;
		SET_S_C;
		RESET_S_D;
		break;
	}
}

void Eight(int display)
{
	switch(display)
	{
		case 1:
		RESET_U_A;
		RESET_U_B;
		RESET_U_C;
		SET_U_D;
		break;
		
		case 2:
		RESET_M_A;
		RESET_M_B;
		RESET_M_C;
		SET_M_D;
		break;
		
		case 3:
		RESET_S_A;
		RESET_S_B;
		RESET_S_C;
		SET_S_D;
		break;
	}
}

void Nine(int display)
{
	switch(display)
	{
		case 1:
		SET_U_A;
		RESET_U_B;
		RESET_U_C;
		SET_U_D;
		break;
		
		case 2:
		SET_M_A;
		RESET_M_B;
		RESET_M_C;
		SET_M_D;
		break;
		
		case 3:
		SET_S_A;
		RESET_S_B;
		RESET_S_C;
		SET_S_D;
		break;
	}
}

void DisplayHours(int value )
{
	
	int stevke_array[2];
	int display = 1;
	
	//Separating input argument to separate numbers

	for(int i=1; i>=0; i--)
	{	
		int digit = value % 10;
		stevke_array[i] = digit;
		value = floor(value/10);	
	}
	
	//First number
	SET_A1H;
	RESET_A10H;
	
	switch(stevke_array[1]) 
	{
		case 0 :
		Zero(display);
		break;
		
		case 1 :
		One(display);
		break;
		
		case 2 :
		Two(display);
		break;
		
		case 3 :
		Three(display);
		break;
		
		case 4 :
		Four(display);
		break;
		
		case 5 :
		Five(display);
		break;
		
		case 6 :
		Six(display);
		break;
		
		case 7 :
		Seven(display);
		break;
		
		case 8 :
		Eight(display);
		break;
		
		case 9 :
		Nine(display);
		break;
	}
	_delay_us(NUMBER_DELAY_US);
	
	RESET_A1H;
	RESET_A10H;
	
	_delay_us(NUMBER_DELAY_US);
	
	//Second number
	RESET_A1H;
	SET_A10H;
	
	switch(stevke_array[0]) 
	{
		case 0 :
		Zero(display);
		break;
		
		case 1 :
		One(display);
		break;
		
		case 2 :
		Two(display);
		break;
		
		case 3 :
		Three(display);
		break;
		
		case 4 :
		Four(display);
		break;
		
		case 5 :
		Five(display);
		break;
		
		case 6 :
		Six(display);
		break;
		
		case 7 :
		Seven(display);
		break;
		
		case 8 :
		Eight(display);
		break;
		
		case 9 :
		Nine(display);
		break;
	}
	_delay_us(NUMBER_DELAY_US);
	
	RESET_A1H;
	RESET_A10H;
	
	_delay_us(NUMBER_DELAY_US);
}

void DisplayMinutes(int value )
{
	
	int stevke_array[2];
	int display = 2;
	
	//Separating input argument to separate numbers
	for(int i=1; i>=0; i--)
	{
		
		int digit = value % 10;
		stevke_array[i] = digit;
		value = floor(value/10);
		
	}
	

	//First number
	
	SET_A1M;
	RESET_A10M;
	
	switch(stevke_array[1]) 
	{
		case 0 :
		Zero(display);
		break;
		
		case 1 :
		One(display);
		break;
		
		case 2 :
		Two(display);
		break;
		
		case 3 :
		Three(display);
		break;
		
		case 4 :
		Four(display);
		break;
		
		case 5 :
		Five(display);
		break;
		
		case 6 :
		Six(display);
		break;
		
		case 7 :
		Seven(display);
		break;
		
		case 8 :
		Eight(display);
		break;
		
		case 9 :
		Nine(display);
		break;
	}
	_delay_us(NUMBER_DELAY_US);
	
	RESET_A1M;
	RESET_A10M;
	
	_delay_us(NUMBER_DELAY_US);
	
	//Second number
	RESET_A1M;
	SET_A10M;
	
	switch(stevke_array[0]) {
		case 0 :
		Zero(display);
		break;
		
		case 1 :
		One(display);
		break;
		
		case 2 :
		Two(display);
		break;
		
		case 3 :
		Three(display);
		break;
		
		case 4 :
		Four(display);
		break;
		
		case 5 :
		Five(display);
		break;
		
		case 6 :
		Six(display);
		break;
		
		case 7 :
		Seven(display);
		break;
		
		case 8 :
		Eight(display);
		break;
		
		case 9 :
		Nine(display);
		break;
	}
	_delay_us(NUMBER_DELAY_US);
	
	RESET_A1M;
	RESET_A10M;
	
	_delay_us(NUMBER_DELAY_US);
}

void DisplaySeconds(int value )
{
	
	int stevke_array[2];
	int display = 3;
	
    //Separating input argument to separate numbers

	for(int i=1; i>=0; i--)
	{
		int digit = value % 10;
		stevke_array[i] = digit;
		value = floor(value/10);
	}
	

	//First number
	SET_A1S;
	RESET_A10S;
	
	switch(stevke_array[1]) {
		case 0 :
		Zero(display);
		break;
		
		case 1 :
		One(display);
		break;
		
		case 2 :
		Two(display);
		break;
		
		case 3 :
		Three(display);
		break;
		
		case 4 :
		Four(display);
		break;
		
		case 5 :
		Five(display);
		break;
		
		case 6 :
		Six(display);
		break;
		
		case 7 :
		Seven(display);
		break;
		
		case 8 :
		Eight(display);
		break;
		
		case 9 :
		Nine(display);
		break;
	}
	_delay_us(NUMBER_DELAY_US);
	
	RESET_A1S;
	RESET_A10S;
	
	_delay_us(NUMBER_DELAY_US);
	
	//Second number
	RESET_A1S;
	SET_A10S;
	
	switch(stevke_array[0]) {
		case 0 :
		Zero(display);
		break;
		
		case 1 :
		One(display);
		break;
		
		case 2 :
		Two(display);
		break;
		
		case 3 :
		Three(display);
		break;
		
		case 4 :
		Four(display);
		break;
		
		case 5 :
		Five(display);
		break;
		
		case 6 :
		Six(display);
		break;
		
		case 7 :
		Seven(display);
		break;
		
		case 8 :
		Eight(display);
		break;
		
		case 9 :
		Nine(display);
		break;
	}
	_delay_us(NUMBER_DELAY_US);
	
	RESET_A1S;
	RESET_A10S;	
	
	_delay_us(NUMBER_DELAY_US);
}



void SetDisplayInterrupt()
{
	TCNT0 = 0;
	TCCR0A |= (1<<WGM02);					// Set CTC mode
	OCR0A = 125;							// 1ms
	TCCR0B |= (1<<CS01) | (1<<CS00);		// Timer mode with 256 prescler
	TIMSK0 = (1 << OCIE0A) ;				// Enable compare A interrupt
}


void SetRtcFetchInterrupt()
{
	TCNT1 = 0;
	TCCR1A = 0;								// Set CTC mode
	OCR1A = 31250/2;						// 1000ms
	TCCR1B |= (1<<WGM12) | (1<<CS12);		// Timer mode with 256 prescler
	TIMSK1 = (1 << OCIE1A) ;				// Enable compare A interrupt	
}