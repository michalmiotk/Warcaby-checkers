#include "Pionek.h"



Pionek::Pionek()
{
	zycie = 1;
	dama = 0;
	kolor = zolty;
	wruchu = 0;
}
Pionek::Pionek(Pionek const & stary_pionek)
{
	zycie =  stary_pionek.zycie;
	dama =   stary_pionek.dama;
	kolor =  stary_pionek.kolor;
	wruchu = stary_pionek.wruchu;
	pozycjax=stary_pionek.pozycjax;
	pozycjay=stary_pionek.pozycjay;
}
Pionek::~Pionek()
{
}

void Pionek::smierc()
{
	zycie = 0;
}

void Pionek::wzmocnienie()
{
	dama = 1;
}
