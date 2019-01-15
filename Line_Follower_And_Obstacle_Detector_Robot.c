#include<avr/io.h>
#include<util/delay.h>

void main()
{
DDRD=0b00000000;	//SETTING PART D AS AN INPUT PART
DDRB=0b11111111;	//SETTING PART B AS AN OUTPUT PART
PORTD=0b11111111;	//PULLING UP ALL THE PINS OF PART D

int c;

while(1)
{
c=PIND;

if(c==0b11111010)	//No obstacle and both sensors on white surface
PORTB=0b00001010;	//Move forward

if(c==0b11111110)	//No obstacle and left sensor on black line
PORTB=0b00000110;	//Turn left

if(c==0b11111011)	//No obstacle and right sensor on black line
PORTB=0b00001001;	//Turn right

if(c==0b11111111)	//Junction
PORTB=0b00011010;	//Beep and move forward

if(c==0b11111000)	//Obstacle on black line
PORTB=0b00010000; 	//Stop and beep

}
}