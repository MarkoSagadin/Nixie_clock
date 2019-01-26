/*
 * DisplayDigits.h
 *
 * Created: 28/08/2018 18:58:00
 *  Author: Marko Sagadin
 */ 


#ifndef DISPLAYDIGITS_H_
#define DISPLAYDIGITS_H_

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>

/* Global variables that help with display functions, 
moved here because of clarity of main.c file */




/* Functions that show one digit, user has to turn on before 
the desirable anode and set display argument to 1, 2, 3 (hours, seconds, minutes) */
void Zero(int display);
void One(int display);
void Two(int display);
void Three(int display);
void Four(int display);
void Five(int display);
void Six(int display);
void Seven(int display);
void Eight(int display);
void Nine(int display);

/* Functions display double digits. Functions have to be called continuously so that numbers appear static. 
Input arguments go from 0 to 99*/
void DisplayHours(int value);
void DisplayMinutes(int value);
void DisplaySeconds(int value);

/* Refactored functions, they are here to keep main.c 
simple and nice to read and understand. */
void SetDisplayInterrupt();
void SetRtcFetchInterrupt();

#endif /* DISPLAYDIGITS_H_ */