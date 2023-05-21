#include <xc.h>
#include "splash.h"
#include "GLCD.h"

#define _XTAL_FREQ 8000000
const char * sa = "L7 Projecte\n\r";
const char * sb = "Josep Martinez Garcia\n\r";
const char * sc = "Oriol Roca Nunez\n\r";

int score = 0;
int time = 0;
int vides = 3;

int x = 20;
int pag = 4;
int ant_x = 20;
int ant_pag = 4;

int ra3 = 0; // Amunt
int ra4 = 0; // Esquerra
int ra5 = 0; // Dreta
int ra2 = 0; // Avall

int soli = 0;
int level = 1;
int cont = 1;

int x_doll = 0;
int p_doll = 0;
int x_ghost = 0;
int p_ghost = 0;

int wall_1_x0 = 115;
int wall_2_x0 = -30;
int wall_3_x0 = -60;

int free_pages[6] = {3,4, 2,3, 4,5};
int busy_pages[10] = {1,2, 5,6,
					  1,   4,6,
					  1,3,   6};
int seeds = 0;

void writeTxt(byte page, byte y, char *s)
{
    int i = 0;
    while (*s != '\n' && *s != '\0')
    {
        putchGLCD(page, y + i, *(s++));
        i++;
    };
}

void autors()
{
	int i = 0;
	 for(; i < 7; ++i)
	{
		clearGLCD(0,7,0,127);
		writeTxt(i, 2, sb);
		__delay_ms(200);
	}
	int j = 0;
	for(; j < 5; ++j)
	{
		clearGLCD(0,i - 2,0,127);
		writeTxt(j, 5, sc);
		__delay_ms(200);
	}
	int k = 0;
	for(; k < 3; ++k)
	{
		clearGLCD(0,j-2,0,127);
		writeTxt(k, 8, sa);
		__delay_ms(200);
	}
	__delay_ms(1000);
	clearGLCD(0,7,0,127);
}

void pintar_mapa()
{
	int c = 0;
	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 128; ++j)
		{
			writeByte(i,j,bitmap[c]);
			++c;
		}
	}
	__delay_ms(3000);
	clearGLCD(0,7,0,127);
}

void clear_wall_1()
{
	clearGLCD(1, 2, wall_1_x0, wall_1_x0+5);
	clearGLCD(5, 6, wall_1_x0, wall_1_x0+5);
}

void clear_wall_2()
{
	clearGLCD(1, 1, wall_2_x0, wall_2_x0+5);
	clearGLCD(4, 6, wall_2_x0, wall_2_x0+5);
}

void clear_wall_3()
{
	clearGLCD(1, 3, wall_3_x0, wall_3_x0+5);
	clearGLCD(6, 6, wall_3_x0, wall_3_x0+5);
}

void print_wall_1()
{
	for (int i = 0; i < 5; i++) writeByte(1,wall_1_x0+i,mur[i]);
	for (int i = 0; i < 5; i++) writeByte(2,wall_1_x0+i,mur[i+5]);

	for (int i = 0; i < 5; i++) writeByte(5,wall_1_x0+i,mur[i]);
	for (int i = 0; i < 5; i++) writeByte(6,wall_1_x0+i,mur[i+5]);
}

void print_wall_2()
{
	for (int i = 0; i < 5; i++) writeByte(1,wall_2_x0+i,muret[i]);

	for (int i = 0; i < 5; i++) writeByte(4,wall_2_x0+i,murazo[i]);
	for (int i = 0; i < 5; i++) writeByte(5,wall_2_x0+i,murazo[i+5]);
	for (int i = 0; i < 5; i++) writeByte(6,wall_2_x0+i,murazo[i+10]);
}

void print_wall_3()
{
	for (int i = 0; i < 5; i++) writeByte(1,wall_3_x0+i,murazo[i]);
	for (int i = 0; i < 5; i++) writeByte(2,wall_3_x0+i,murazo[i+5]);
	for (int i = 0; i < 5; i++) writeByte(3,wall_3_x0+i,murazo[i+10]);

	for (int i = 0; i < 5; i++) writeByte(6,wall_3_x0+i,muret[i]);
}

void update_pos_walls()
{
	if(wall_1_x0 < 9) {clear_wall_1(); wall_1_x0 = 115;}
	else wall_1_x0--;

	if(wall_2_x0 == -1) wall_2_x0 = 115;
	else if(wall_2_x0 > -1) wall_2_x0--;
	else wall_2_x0++;

	if(wall_3_x0 == -1) wall_3_x0 = 115;
	else if(wall_3_x0 > -1) wall_3_x0 --;
	else wall_3_x0 ++;
}

void pintar_mur()
{
	if(wall_1_x0 > 0)
	{
		clear_wall_1();
		print_wall_1();
		if(cont >= 6) cont = 1;
		clearGLCD(p_ghost, p_ghost, x_ghost, x_ghost+5);
		print_ghost(wall_1_x0-8,cont);
		clearGLCD(p_doll, p_doll, x_doll, x_doll+5);
		if(wall_1_x0+8 < 115) print_dollar(wall_1_x0+8, 6 - cont);
		cont+=level;
		person(pag);
	}
	if(wall_2_x0 > 0)
	{
		clear_wall_2();
		print_wall_2();
	} 
	if(wall_3_x0 > 0)
	{
		clear_wall_3();
		print_wall_3(); 
	}
	update_pos_walls();
}

void love(int i)
{
	writeByte(0, i+2, 0x18);
	writeByte(0, i+3, 0x3C);
	writeByte(0, i+4, 0x7C);
	writeByte(0, i+5, 0xF8);
	writeByte(0, i+6, 0x7C);
	writeByte(0, i+7, 0x3C);
	writeByte(0, i+8, 0x18);
}

void print_dollar(int ix, int p) {
   byte dollar [4] = {0x62, 0x92, 0xFE, 0x8C};
   x_doll = ix;
   p_doll = p;

   writeByte(p, ix, dollar[3]);
   writeByte(p, ix+1, dollar[1]);
   writeByte(p, ix+2, dollar[2]);
   writeByte(p, ix+3, dollar[1]);
   writeByte(p, ix+4, dollar[0]);
}

void print_ghost(int ix, int p) {
   byte fantasma [3] = {0x7E, 0x3B, 0x7F};
   x_ghost = ix;
   p_ghost = p;

   writeByte(p, ix, fantasma[0]);
   writeByte(p, ix+1, fantasma[1]);
   writeByte(p, ix+2, fantasma[2]);
   writeByte(p, ix+3, fantasma[1]);
   writeByte(p, ix+4, fantasma[0]);
}

void clear_ghost() 
{
	clearGLCD(p_ghost, p_ghost, x_ghost, x_ghost+5);
	--vides;
	x_ghost = 0;
	p_ghost = 0;
}

void clear_dollar() {
	clearGLCD(p_doll, p_doll, x_doll, x_doll+5);
	score += 75;

	CCPR1L = 10;
	__delay_ms(200);
	CCPR1L = 0;
	
	x_doll = 0;
	p_doll = 0;
}

void hit_dollar() {
	if (pag == p_doll &&
		(((x+4 >= x_doll) && (x+4 <= x_doll+4)) || 
		 ((x >= x_doll) && (x <= x_doll+4)))) clear_dollar();
}

void hit_ghost() {
	if (pag == p_ghost &&
		(((x+4 >= x_ghost) && (x+4 <= x_ghost+4)) || 
		 ((x >= x_ghost) && (x <= x_ghost+4)))) clear_ghost();
}

void hit_wall() 
{
	if(wall_1_x0 > 0)
	{
		if((pag != 3 && pag != 4) &&
			(wall_1_x0 <= x && x <= wall_1_x0+5)) vides = 0;
	}

	if(wall_2_x0 > 0)
	{
		if((pag != 2 && pag != 3) &&
			(wall_2_x0 <= x && x <= wall_2_x0+5)) vides = 0;
	}

	if(wall_3_x0 > 0)
	{
		if((pag != 4 && pag != 5) &&
			(wall_3_x0 <= x && x <= wall_3_x0+5)) vides = 0;
	}
}

void person(int f)
{	
	hit_dollar();
	hit_ghost();
	hit_wall();

	if(f == 1) clearGLCD(pag, pag, ant_x, ant_x+5);
	else if(f == 0) clearGLCD(ant_pag, ant_pag, ant_x-5, ant_x+6);
	
	byte* vec[5] = {0x10, 0xF4, 0x3A, 0xF4, 0x10};
	for(int i = 0; i<5; ++i) writeByte(pag, x+i, vec[i]);
	__delay_ms(10);
}

void configT()
{
	TRISCbits.RC6 = 1;
	TXREG1 = 0;
	PIE1bits.TX1IE = 0;
	PIR1bits.TX1IF = 0;
	IPR1bits.TX1IP = 1;
	
	RCSTA1bits.SPEN = 1;

	TXSTA1bits.TX9 = 0;
	TXSTA1bits.TXEN = 1;
	TXSTA1bits.SYNC = 0;
	TXSTA1bits.SENDB = 1;
	TXSTA1bits.BRGH = 1;
	TXSTA1bits.TRMT = 1;

	BAUDCON1bits.BRG16 = 1;
	
	SPBRG1 = 16;
}

void configR()
{
	TRISCbits.RC7 = 1;
	PIE1bits.RC1IE = 1;
	PIR1bits.RC1IF = 0;
	IPR1bits.RC1IP = 1;
	
	RCSTA1bits.RX9 = 0;
	RCSTA1bits.CREN = 1;
	RCSTA1bits.OERR = 1;
}

void configPWM() {
    CCPTMRS0bits.C1TSEL = 0x00;
    PR2 = 49;
	
    T2CONbits.T2OUTPS = 0xF;
    T2CONbits.T2CKPS = 0x2;
    
    TMR2IE = 1;
    TMR2IF = 0;
    TMR2IP = 1;
    
    TMR2ON = 1;
    CCPR1L = 0;
    CCP1CONbits.CCP1M = 0xC;
}

void configIntSeg()
{
	TMR0ON = 0;
	GIEH = 1;
	TMR0IE = 1;
	TMR0IF = 0;
	TMR0IP = 1;
	T0SE = 0;
	T08BIT = 0;
	T0CONbits.T0CS = 0;
	T0CONbits.PSA = 0;
	T0PS0 = 1;
	T0PS1 = 0;
	T0PS2 = 1;
	TMR0 = 65536 - 31250;
}

void configPIC()
{
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
   
    TRISA = 0xFF;
    TRISD = 0;
    TRISB = 0;
    TRISC = 0x93;

    PORTD = 0;
    PORTB = 0;

	IPEN = 1;
	PEIE = 1;
	GIE = 1;
	GIEH = 1;

	configT();
	configR();
	configIntSeg();
	configPWM();

    GLCDinit();              // Inicialitzem la pantalla
    clearGLCD(0, 7, 0, 127); // Esborrem pantalla
    setStartLine(0);         // Definim linia d'inici
    
}

void send_c(unsigned const char c) 
{
	 while (!PIR1bits.TX1IF);
	 TXREG1 = c;
}

void send_s(const char *st) 
{
	while(*st) send_c(*st++);
}

char llegir_char()
{
    soli = 1;
	return RCREG1;
}

void wasd(char char_llegit)
{
	if(!soli) return;
	else soli = 0;
    switch(char_llegit) 
    {
		case 'w':
			if (pag > 1)  {ant_pag = pag; --pag; person(0);}
			__delay_ms(100);
		break;

		case 'a':
			if (x > 5)  {ant_x = x; x-=2; person(1);}
			//__delay_ms(10);
		break;

		case 's':
			if (pag < 6)  {ant_pag = pag; ++pag; person(0);}
			__delay_ms(100);
		break;
		
		case 'd':
			if (x < 113) {ant_x = x; x += 2; person(1);}
			//__delay_ms(10);
		break;
    }
}

void buttons()
{
    ra3 = PORTAbits.RA3; // Amunt
    ra4 = PORTAbits.RA4; // Esquerra
    ra5 = PORTAbits.RA5; // Dreta
    ra2 = PORTAbits.RA2; // Avall

    if (!ra3)
    {
		if (pag > 1)  {ant_pag = pag; --pag; person(0);}
		__delay_ms(300);
    }
    if (!ra2)
    {
        if (pag < 6)  {ant_pag = pag; ++pag; person(0);}
		__delay_ms(300);
    }
    if (!ra4)
    {
        if (x > 5)  {ant_x = x; x -= 2; person(1);}
		__delay_ms(10);
    }
    if (!ra5)
    {
        if (x < 113)  {ant_x = x; x += 2; person(1);}
		__delay_ms(10);
    }
	if(!PORTCbits.RC1)
	{
		if(level < 2) ++level;
		__delay_ms(100);
	}
	if(!PORTCbits.RC4)
	{
		if(level > 1) --level;
		__delay_ms(100);
	}
}

void printar_noms()
{
   TXREG1 = 0;
   send_s(sa);
   send_s(sb);
   send_s(sc);
}

void print_vides()
{
   clearGLCD(0, 0, 0, 25);
   for(int i = 0; i < vides*8; i+=8) love(i);
}

void marcador()
{
    clearGLCD(0, 0, 60, 100);
    writeTxt(0, 14, "Score=");
    writeNum(0, 21, score);
	__delay_ms(20);
}

void print_bars()
{
	for (int i = 2; i < 123; i++) SetDot(60,i); 
    for (int i = 9; i < 60; ++i) SetDot(i,126);
	update_bars();
}

void update_bars()
{
	int xx = time+2;
	int yy = 59-((score*50/500));
		
	SetDot(59,xx);
	SetDot(61,xx);
	SetDot(59,xx+1);
	SetDot(61,xx+1);

	for(int i = 59; i >= yy; --i)
	{
		SetDot(i,125);
		SetDot(i,127);
	}
}

void inc_seg()
{
	++time;
	update_bars();
}

int check_stats()
{
	return (time >= 60 || score >= 500 || vides < 1);
}

void game_over()
{
	TMR0ON = 0;
	clearGLCD(0, 7, 0, 127);
	if (time >= 60 || vides < 1) writeTxt(3, 6, "Game over!!");
	else 
	{
		writeTxt(3, 6, "You have won!!!");
	}
}

void presentacio()
{
	autors();
	printar_noms();
	pintar_mapa();
}

void start()
{
	TMR0ON = 1;
	print_bars();
	person(3);
	pintar_mur();
}

int menu()
{
	writeTxt(1,61, "M E N U");
	for (int i = 48; i <= 84; i++) SetDot(16,i);
	writeTxt(3,62, "Play");
	SetDot(28,50);
	SetDot(28,77);
	while(1) 
	{if(!PORTCbits.RC0) {clearGLCD(0,7,0,127); return 1;}}
	
}