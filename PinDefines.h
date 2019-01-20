/*
 * PinDefines.h
 *
 * Created: 28/08/2018 18:57:30
 *  Author: Marko Sagadin
 */ 


#ifndef PINDEFINES_H_
#define PINDEFINES_H_

#include <avr/io.h>

/* Macro definitions for setting bits, if wrong port is passed,
*  the default port is PORTD.*/

#define SET_BIT(p, b)		((p) |= 1 << (b))

#define RESET_BIT(p, b)		((p) &= ~(1 << (b)))

#define TOGGLE_BIT(p, b)	((p) ^= 1 << (b))

#define READ_BIT(p, b)		((p) & (1 << (b)))


/* Button definitions */
#define CYCLE_BUTTON PORTB7
#define SET_BUTTON PORTD5
 
#define READ_CYCLE_BUTTON   READ_BIT(PINB, CYCLE_BUTTON)
#define READ_SET_BUTTON		READ_BIT(PIND, SET_BUTTON)


/* Macros for display, if needed change pins assignments here */
//URE//
#define U_A PORTD6 //Pins to control chip K155iD
#define U_B PORTB0
#define U_C PORTB1
#define U_D PORTD7

#define SET_U_A   SET_BIT(PORTD, U_A)
#define SET_U_B   SET_BIT(PORTB, U_B)
#define SET_U_C   SET_BIT(PORTB, U_C)
#define SET_U_D   SET_BIT(PORTD, U_D)

#define RESET_U_A   RESET_BIT(PORTD, U_A)
#define RESET_U_B   RESET_BIT(PORTB, U_B)
#define RESET_U_C   RESET_BIT(PORTB, U_C)
#define RESET_U_D   RESET_BIT(PORTD, U_D)


//MINUTE//
#define M_A PORTB2 //Pins to control chip K155iD
#define M_B PORTB4
#define M_C PORTB5
#define M_D PORTB3

#define SET_M_A   SET_BIT(PORTB, M_A)
#define SET_M_B   SET_BIT(PORTB, M_B)
#define SET_M_C   SET_BIT(PORTB, M_C)
#define SET_M_D   SET_BIT(PORTB, M_D)

#define RESET_M_A   RESET_BIT(PORTB, M_A)
#define RESET_M_B   RESET_BIT(PORTB, M_B)
#define RESET_M_C   RESET_BIT(PORTB, M_C)
#define RESET_M_D   RESET_BIT(PORTB, M_D)


//SEKUNDE//
#define S_A PORTC0 //Pins to control chip K155iD
#define S_B PORTC2
#define S_C PORTC3
#define S_D PORTC1

#define SET_S_A   SET_BIT(PORTC, S_A)
#define SET_S_B   SET_BIT(PORTC, S_B)
#define SET_S_C   SET_BIT(PORTC, S_C)
#define SET_S_D   SET_BIT(PORTC, S_D)

#define RESET_S_A   RESET_BIT(PORTC, S_A)
#define RESET_S_B   RESET_BIT(PORTC, S_B)
#define RESET_S_C   RESET_BIT(PORTC, S_C)
#define RESET_S_D   RESET_BIT(PORTC, S_D)


//ANODE//
#define A10H	PORTD4 // For controlling transistors
#define A1H		PORTB6
#define A10M	PORTD3
#define A1M		PORTD2
#define A10S	PORTD1
#define A1S		PORTD0

#define SET_A10H	SET_BIT(PORTD, A10H)
#define SET_A1H		SET_BIT(PORTB, A1H)
#define SET_A10M	SET_BIT(PORTD, A10M)
#define SET_A1M		SET_BIT(PORTD, A1M)
#define SET_A10S	SET_BIT(PORTD, A10S)
#define SET_A1S		SET_BIT(PORTD, A1S)

#define RESET_A10H	RESET_BIT(PORTD, A10H)
#define RESET_A1H	RESET_BIT(PORTB, A1H)
#define RESET_A10M	RESET_BIT(PORTD, A10M)
#define RESET_A1M	RESET_BIT(PORTD, A1M)
#define RESET_A10S	RESET_BIT(PORTD, A10S)
#define RESET_A1S	RESET_BIT(PORTD, A1S)


/* Function is called at the start of the main function, it configures states of GPIO. */
void InitNixiePins();


/* Function is called at the start of the main function, it configures states of GPIO. */
void InitButtons();

#endif /* PINDEFINES_H_ */