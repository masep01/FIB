
/* Main.c
 * Processor: PIC18F45K22
 * Compiler:  MPLAB XC8
 */

#include <xc.h>
#include <string.h>
#include "config.h"
#include "GLCD.h"
#define _XTAL_FREQ 8000000

const char *s1 = "L5 Individual\n";
const char *s2 = "Josep Martinez Garcia\n";

int ra0 = 0; // Amunt
int ra1 = 0; // Esquerra
int ra2 = 0; // Dreta
int ra3 = 0; // Avall

int x = 13;
int y = 58;
int ant_x = 127/2;
int ant_y = 63/2;

void writeTxt(byte page, byte y, char *s)
{
    int i = 0;
    while (*s != '\n' && *s != '\0')
    {
        putchGLCD(page, y + i, *(s++));
        i++;
    };
}


void marcador(int x, int y)
{
    clearGLCD(0, 0, 6, 125);
    writeTxt(0, 1, "pwm=");
    writeNum(0, 5, x-13);
    writeTxt(0, 9, "adc=");
    writeNum(0, 13, 58-y);
}

void maracaton()
{
    ra0 = PORTAbits.RA0; // Amunt
    ra1 = PORTAbits.RA1; // Esquerra
    ra2 = PORTAbits.RA2; // Dreta
    ra3 = PORTAbits.RA3; // Avall
    ant_x = x;
    ant_y = y;

    if (ra0)
    {
        __delay_ms(2);
        if (y > 8)  --y;
       marcador(x, y);
    }
    if (ra3)
    {
        __delay_ms(2);
        if (y < 58)  ++y;
        marcador(x, y);
    }
    if (ra1)
    {
        __delay_ms(2);
        if (x > 13)  --x;
        marcador(x, y);
    }
    if (ra2)
    {
        __delay_ms(2);
        if (x < 113)  ++x;
        marcador(x, y);
    }
    __delay_ms(20);
	
}

void print_bars()
{
    for(int i = 13; i <= x; ++i)
	{	
		SetDot(59,i); 
		SetDot(60,i); 
		SetDot(61,i); 
	}
	for (int i = x; i < 114; i++) SetDot(60,i); 

	for(int i = y; i < 59;++i)
	{
		SetDot(i,124);
		SetDot(i,125);
		SetDot(i,126);
	}
    for (int i = 9; i <= y; ++i) SetDot(i,125);
}

void update_bars()
{
	if(x > ant_x) 
	{
		if(ant_x == 13)
		{
			SetDot(59,ant_x);
			SetDot(61,ant_x);
		}
		SetDot(59,x);
		SetDot(61,x);
	}
	else
	{
		ClearDot(59,ant_x);
		ClearDot(61,ant_x);

		if(x>13)
		{
			SetDot(59,x);
			SetDot(61,x);
		}
	}
	if(y < ant_y && y > 7) 
	{
		SetDot(ant_y,124);
		SetDot(ant_y,126);
	}
	else
	{
		ClearDot(y,124);
		ClearDot(y,126);
	}
}

void ull()
{
	writeByte(4, 61, 0x0E);
	writeByte(4, 62, 0x1F);
	writeByte(4, 63, 0x1F);
	writeByte(4, 64, 0x1F);
	writeByte(4, 65, 0x0E);

	if(x < 63)
	{
		if(y < 31) ClearDot(33,62);
		else if(y > 31) ClearDot(35,62);
	}
	else
	{
		if(y < 31) ClearDot(33,64);
		else if(y > 33) ClearDot(35,64);
	}
}

int var = 5;
void interrupt RSI_HP(void)
{
    if (TMR2IF && TMR2IE) 
    {
        TMR2IF = 0;
		CCPR1L = var + (x-13)/2.5;
    }
}


void configPIC()
{
    ANSELA = 0x00;
    ANSELB = 0x00;
    ANSELC = 0x00;
    ANSELD = 0x00;

    TRISD = 0x00;
    TRISB = 0x00;
	TRISC = 0x03;

    PORTD = 0x00;
    PORTB = 0x00;
    
	CCPTMRS0bits.C1TSEL = 0x00;
	PR2 = 49;
	
	T2CONbits.T2OUTPS = 0xF;
	T2CONbits.T2CKPS = 0x2;
	
	GIEH = 1;
    GIE = 1;
	IPEN = 1;
    TMR2IE = 1;
	
    TMR2IF = 0;
    TMR2IP = 1;
	
	TMR2ON = 1;
	CCPR1L = var;
	CCP1CONbits.CCP1M = 0xC;

	INTCONbits.PEIE = 1; 

    GLCDinit();              // Inicialitzem la pantalla
    clearGLCD(0, 7, 0, 127); // Esborrem pantalla
    setStartLine(0);         // Definim linia d'inici
}

void main(void)
{
    configPIC();
    marcador(x, y);
	print_bars();
    while (1)
    {
        maracaton();
		update_bars();
		ull();
    }
}

