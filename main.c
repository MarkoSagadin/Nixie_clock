/*
 * main.c
 *
 * Created: 01/04/2018 18:19:10
 *  Author: Marko Sagadin
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

#include "PinDefines.h"
#include "DisplayDigits.h"
#include "rtc.h"


// Global variables for turning on and off parts of displays
uint8_t globalShowHours = 0;
uint8_t globalShowMinutes = 0;
uint8_t globalShowSeconds = 0;

// Global variables for switching between show state and modify state and also which digit is being changed
uint8_t globalModifyingState = 0;
uint8_t globalSelectedDigits = 0;

// Global variables that indicate if the buttons are pressed
volatile uint8_t globalCycleButtonPressed = 0;
volatile uint8_t globalSetButtonPressed = 0;

// Only used to prevent false readings of buttons at startup 
volatile uint8_t enableReading = 0;
 
 void DisplayOn()
 {
	 globalShowHours = 1;
	 globalShowMinutes = 1;
	 globalShowSeconds = 1;
 }

 void DisplayOff()
 {
	 globalShowHours = 0;
	 globalShowMinutes = 0;
	 globalShowSeconds = 0;
 }


/* Main interrupt routine,
/ it is taking care of debouncing buttons and is also updating Nixie display.
/ Time between each execution is 1ms. */ 
ISR(TIMER0_COMPA_vect)
{
	static uint8_t cycleButtonDownCounter =  0;
	static uint8_t cycleButtonUpCounter =  0;
	static uint8_t setButtonDownCounter =  0;
	static uint8_t setButtonUpCounter =  0;
	
	// Debouncing section
	if(enableReading)
	{
		if(READ_CYCLE_BUTTON == 0)
		{	
			cycleButtonDownCounter++;
			
			if(cycleButtonDownCounter == 20)
			{
				cycleButtonDownCounter = 0;		
				///////////////////////
				globalCycleButtonPressed = 1;
				///////////////////////
			}
		}
		else
		{
			cycleButtonUpCounter++;
			
			if(cycleButtonUpCounter == 20)
			{
				cycleButtonUpCounter = 0;
				///////////////////////
				globalCycleButtonPressed = 0;
				///////////////////////
			}
		}
		
		if(READ_SET_BUTTON == 0)
		{
			setButtonDownCounter++;
			
			if(setButtonDownCounter == 20)
			{
				setButtonDownCounter = 0;
				///////////////////////
				globalSetButtonPressed = 1;
				///////////////////////	
			}
		}
		else
		{
			setButtonUpCounter++;
			
			if(setButtonUpCounter == 20)
			{
				setButtonUpCounter = 0;
				///////////////////////
				globalSetButtonPressed = 0;
				///////////////////////
			}
		}
	}
	
	// Hour, min and sec are extern global variables from rtc.h
	if(hour == 0 && min == 0 && sec == 0)
	{	
		for(int j = 0; j< 50; j++)
		{
			// Time to cycle Nixie tubes, to prevent burn in
			for(int i = 0; i< 10; i++)
			{
				DisplayHours(i*11);
				DisplayMinutes(i*11);
				DisplaySeconds(i*11);
			}	
		}		
	}
	else
	{
		// Normal display
		if(globalShowHours)
		DisplayHours(hour);
		
		if(globalShowMinutes)
		DisplayMinutes(min);
		
		if(globalShowSeconds)
		DisplaySeconds(sec);
	}
	
}

/* Routine for updating time variables form RTC module. 
 Exectues every second. */ 
ISR(TIMER1_COMPA_vect)
{
	// Do not update time values if we are modifying them.
	if(!globalModifyingState)
	{
		readTime();
	}


		
	
	
}


int main()
{	
	InitNixiePins();
	InitButtons();
	rtcInit();
	
	// Uncomment this to set the time and send it, then comment it again.
	//setTime(58, 59, 23, 6, 31, 8, 18);
	//sendTime();
	
	readTime();
	
	SetDisplayInterrupt();
	SetRtcFetchInterrupt();

	sei();				//Enable interrupts
	
	_delay_ms(1000);	// Needed to get desirable supply voltage for Nixie tubes
	DisplayOn();		// Turn on all tubes
	enableReading = 1;	// Needed to prevent wrong reading buttons at startup
	
	while (1)
	{	
		if(!globalModifyingState)
		{
			//We are checking if interrupt routine told us that cycle button has been pressed
			if(globalCycleButtonPressed)
			{
				globalModifyingState = 1;
				DisplayOff();
				_delay_ms(500);				// Delay for nice effect
				globalSelectedDigits = 1;	// Hour digits are shown
				while(globalCycleButtonPressed){}
				DisplayOn();
			}
		}
		else
		{
			// Here we are given an option to change the digits, by clicking set button.
			switch(globalSelectedDigits)
			{
				case 1:
				globalShowHours =   1;
				globalShowMinutes = 0;
				globalShowSeconds = 0;
				break;
				
				case 2:
				globalShowHours =   0;
				globalShowMinutes = 1;
				globalShowSeconds = 0;
				break;
				
				case 3:
				globalShowHours =	0;
				globalShowMinutes = 0;
				globalShowSeconds = 1;
				break;
			}
			
			// Used to cycle between digitis and to escape modifying state
			if(globalCycleButtonPressed)
			{
				DisplayOff();
				_delay_ms(500);
				DisplayOn();
				
				globalSelectedDigits += 1;
				
				if(globalSelectedDigits == 4)
				{
					globalSelectedDigits = 0;
					globalModifyingState = 0;
					DisplayOff();
					sendTime();
					_delay_ms(500);
					DisplayOn();
					
				}
				
				while(globalCycleButtonPressed){}
				
			}
			
			// CLicking set button will increment selected digit
			if(globalSetButtonPressed)
			{
				switch(globalSelectedDigits)
				{
					case 1:
					if(hour == 23)
					hour = 0;
					else
					hour += 1;
					break;
					
					case 2:
					if(min == 59)
					min = 0;
					else
					min += 1;
					break;
					
					case 3:
					if(sec == 59)
					sec = 0;
					else
					sec += 1;
					break;
				}
				
				while(globalSetButtonPressed){}
			}
			
		}
	}
}





