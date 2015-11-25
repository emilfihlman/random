//A circular loading icon with fade
//AVR Attiny84
//Emil Fihlman @ Elepaja (elepaja.aalto.fi) 2015
//":D"

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

unsigned char inop;

unsigned char pins[10]={0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b10000000, 0b00000010, 0b00000100}
unsigned char *ports[10]={&PORTA, &PORTA, &PORTA, &PORTA, &PORTA, &PORTA, &PORTA, &PORTA, &PORTB, &PORTB}

unsigned char t[100]={1,2,4,8,16,0,0,0,0,0, 0,1,2,4,8,16,0,0,0,0, 0,0,1,2,4,8,16,0,0,0, 0,0,0,1,2,4,8,16,0,0, 0,0,0,0,1,1,4,8,16,0, 0,0,0,0,0,1,2,4,8,16, 16,0,0,0,0,0,1,2,4,8, 8,16,0,0,0,0,0,1,2,4, 4,8,16,0,0,0,0,0,1,2, 2,4,8,16,0,0,0,0,0,1};

void reldelay(unsigned char t)
{
	for(inop=0; inop<t; inop++)
	{
		asm("");
	}
}

int main(void)
{
	DDRA=0b11111111;
	DDRB=0b00000110;
	unsigned char i, j;
	while(1)
	{
		for(j=0; j<90; j+=10)
		{
			for(i=0; i<10; i++)
			{
				*ports[i]=pins[i];
				reldelay(t[j+i]);
				*ports[i]=0b00000000;
			}
		}
	}
}
