void print_cactus(int x, int y)
{
	// Tronc
	for(int i = -1; i <= 3; ++i)
	{
		if(i == -1 || i == 3)
		{
			writeByte(4 - y/8, x+i, 0xFE);
			for(int j = 5; j <= 7;++j) writeByte(j - y/8, x+i, 0xFF);
		}
		else for(int j = 4; j <= 7;++j) writeByte(j - y/8, x+i, 0xFF);
	}
	// Planta
	writeByte(7 - y/8, x+4, 0x80);
	writeByte(7 - y/8, x-2, 0x80);

	// Braç esquerra
	for(int j = 2; j <= 5; ++j) writeByte(6 - y/8, x-j, 0x0F);
	writeByte(6 - y/8, x-6, 0x07);
	writeByte(6 - y/8, x-7, 0x03);
	writeByte(6 - y/8, x-8, 0x01);

	writeByte(5 - y/8, x-8, 0xFE);
	writeByte(5 - y/8, x-7, 0xFF);
	writeByte(5 - y/8, x-6, 0xFF);
	writeByte(5 - y/8, x-5, 0xFE);

	//Braç dret
	for(int i = 4; i <= 7; ++i) writeByte(6 - y/8, x+i, 0x0F);
	writeByte(6 - y/8, x+8, 0x07);
	writeByte(6 - y/8, x+9, 0x03);
	writeByte(6 - y/8, x+10, 0x01);

	writeByte(5 - y/8, x+10, 0xFE);
	writeByte(5 - y/8, x+9, 0xFF);
	writeByte(5 - y/8, x+8, 0xFF);
	writeByte(5 - y/8, x+7, 0xFE);
}

void print_pokeball(int x, int y)
{
	writeByte(6 - y/8, x-3, 0x38);
	writeByte(6 - y/8, x-2, 0x54);
	writeByte(6 - y/8, x-1, 0x92);
	writeByte(6 - y/8, x, 0xAA);
	writeByte(6 - y/8, x+1, 0x92);
	writeByte(6 - y/8, x+2, 0x54);
	writeByte(6 - y/8, x+3, 0x38);
}

byte lateral [3] = { 0xFF, 0x0F, 0x1C };
byte ull [3] = { 0xC7, 0xFF, 0x1F };
byte mig [2] = { 0xFF, 0x7F };

void dibuixa_fantasma(int x, int y) {
	int p = x/8;
	// Lateral
   	
	for (int i = 0; i < 3; ++i) {
		writeByte(p, y+i, lateral[0]);
		writeByte(p+1, y+i, lateral[1]);
		writeByte(p+2, y+i, lateral[2]);
	}
  	y += 3;

	// Ull
	for (int i = 0; i < 3; ++i) {
		writeByte(p, y+i, ull[0]);
		writeByte(p+1, y+i, ull[1]);
		writeByte(p+2, y+i, ull[2]);
	}
  	y += 3;

	//Mig
	for (int i = 0; i < 3; ++i) {
		writeByte(p, y+i, mig[0]);
		writeByte(p+1, y+i, mig[1]);
	}
   	y += 3;

	// Ull
   	for (int i = 0; i < 3; ++i) {
		writeByte(p, y+i, ull[0]);
		writeByte(p+1, y+i, ull[1]);
		writeByte(p+2, y+i, ull[2]);
	}
   	y += 3;

	// Lateral
  	for (int i = 0; i < 3; ++i) {
		writeByte(p, y+i, lateral[0]);
		writeByte(p+1, y+i, lateral[1]);
		writeByte(p+2, y+i, lateral[2]);
	}
}