
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

int x = 127/2;
int y = 63/2+2;
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

void presentacio()
{
    int i = 0;

    for (; i < 5; ++i)
    {
        clearGLCD(0, 7, 0, 127);
        writeTxt(i, 2, s2);
        __delay_ms(200);
    }

    int j = 0;

    for (; j < 3; ++j)
    {
        clearGLCD(0, i - 2, 0, 127);
        writeTxt(j, 7, s1);
        __delay_ms(200);
    }

    clearGLCD(0, 7, 0, 127);
}

void marcador(int x, int y)
{
    clearGLCD(0, 0, 94, 125);
    writeTxt(0, 16, "x=");
    writeNum(0, 18, x-13);
    writeTxt(0, 21, "y=");
    writeNum(0, 23, 58-y);
}

void configPIC()
{
    ANSELA = 0x00;
    ANSELB = 0x00;
    ANSELC = 0x00;
    ANSELD = 0x00;

    TRISD = 0x00;
    TRISB = 0x00;

    PORTD = 0x00;
    PORTB = 0x00;
    TRISA = 0xF; // PORT A input

    GLCDinit();              // Inicialitzem la pantalla
    clearGLCD(0, 7, 0, 127); // Esborrem pantalla
    setStartLine(0);         // Definim linia d'inici
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
    __delay_ms(25);
	
	ClearDot(ant_y, ant_x);
	SetDot(y, x);
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

void ghost()
{
	writeByte(7, 2, 0x3F);
	writeByte(7, 3, 0xE);
	writeByte(7, 4, 0x3F);
	writeByte(7, 5, 0xE);
	writeByte(7, 6, 0x3F);
	writeByte(6, 2, 0x80);
	writeByte(6, 3, 0xC0);
	writeByte(6, 4, 0xC0);
	writeByte(6, 5, 0xC0);
	writeByte(6, 6, 0x80);
}

void person()
{
	writeByte(7, 116, 0x10);
	writeByte(7, 117, 0xF4);
	writeByte(7, 118, 0x3A);
	writeByte(7, 119, 0xF4);
	writeByte(7, 120, 0x10);
}

void love()
{
	writeByte(1, 2, 0x18);
	writeByte(1, 3, 0x3C);
	writeByte(1, 4, 0x7C);
	writeByte(1, 5, 0xF8);
	writeByte(1, 6, 0x7C);
	writeByte(1, 7, 0x3C);
	writeByte(1, 8, 0x18);
}

void lan()
{
	writeByte(1, 115, 0xFF);
	writeByte(1, 116, 0xF9);
	writeByte(1, 117, 0xE1);
	writeByte(1, 118, 0xC1);
	writeByte(1, 119, 0xC1);
	writeByte(1, 120, 0xE1);
	writeByte(1, 121, 0xF9);
	writeByte(1, 122, 0xFF);
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

void draw()
{
	ghost();
	person();
	love();
	lan();
}

void main(void)
{
    configPIC();
    presentacio();
    marcador(x, y);
	print_bars();
	draw();
    while (1)
    {
        maracaton();
		update_bars();
		ull();
    }
}
