/*
 * rtc.c
 *
 * Created: 16. 04. 2018 17:38:46
 *  Author: Marko
 */ 

#include "i2c.h"
#include "rtc.h"

volatile uint8_t sec = 0;
volatile uint8_t min = 0;
volatile uint8_t hour = 0;
volatile uint8_t weekDay = 0;
volatile uint8_t date = 0;
volatile uint8_t month = 0;
volatile uint8_t year = 0;

void rtcInit()
{
	init();			
	startRtc();
	write(RTCwrite);
	write(0x0E); //address
	write(0x00);
	stop();
}
void sendTime()
{
	startRtc();
	write(RTCwrite);
	write(0x00);
	write(decToBcd(sec));
	write(decToBcd(min));
	write(decToBcd(hour));
	write(decToBcd(weekDay));
	write(decToBcd(date));
	write(decToBcd(month));
	write(decToBcd(year));
	stop();
}

void readTime()
{
	startRtc();
	write(RTCwrite);
	write(SECONDS);
	
	startRtc();
	write(RTCread);
	sec=bcdToDec(read(1) & 0x7f);
	min=bcdToDec(read(1));
	hour=bcdToDec(read(1) & 0x3f);
	weekDay=bcdToDec(read(1));
	date=bcdToDec(read(1));
	month=bcdToDec(read(1));
	year=bcdToDec(read(0));
	stop();
}
void setTime(uint8_t secArg, uint8_t minArg, uint8_t hourArg, uint8_t weekDayArg, uint8_t dateArg, uint8_t monthArg, uint8_t yearArg)
{
	sec=secArg;
	min=minArg;
	hour=hourArg;
	weekDay=weekDayArg;
	date=dateArg;
	month=monthArg;
	year=yearArg;
}

// Convert binary coded decimal to normal decimal numbers
uint8_t decToBcd(uint8_t val)
{
	return( (val/10*16) + (val%10) );
}
// Convert binary coded decimal to decimal numbers
uint8_t bcdToDec(uint8_t val)
{
	return( (val/16*10) + (val%16) );
}
