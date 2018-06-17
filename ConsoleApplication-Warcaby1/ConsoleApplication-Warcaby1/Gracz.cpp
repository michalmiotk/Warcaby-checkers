#include "Gracz.h"


Gracz::Gracz() {

}
Gracz::Gracz(e_kolor k1, int kol)
{
	kolor = k1;
	kolejka = kol;
	for (int i = 0; i < 12; i++) 
	{
		P[i].kolor = k1;
		P[i].wruchu=0;	
	}
	rozmieszczenie();
}
Gracz::Gracz(Gracz const & stary_gracz)
{
	kolor = stary_gracz.kolor;
	kolejka = stary_gracz.kolejka;
	for (int i = 0; i < 12; i++) 
	{
		P[i].kolor = stary_gracz.P[i].kolor;
		P[i].wruchu=stary_gracz.P[i].wruchu;	
		P[i].zycie =  stary_gracz.P[i].zycie;
		P[i].dama =   stary_gracz.P[i].dama;
		P[i].pozycjax=stary_gracz.P[i].pozycjax;
		P[i].pozycjay=stary_gracz.P[i].pozycjay;
	}
}

Gracz::~Gracz()
{
}

int Gracz::sprzycie()
{
	for (int i = 0; i < 12; i++) {
		if (P[i].zycie == 1) return 1;
	}
	return 0;
}

void Gracz::rozmieszczenie()
{
	if (kolor == zolty) {
		int nr=0;
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < 8; i++) {
				if (j % 2 == 0) {
					if (i % 2 == 1) {
						P[nr].pozycjax = i;
						P[nr].pozycjay = j;
						nr++;
					}
				}
				if (j % 2 == 1) {
					if (i % 2 == 0) {
						P[nr].pozycjax = i;
						P[nr].pozycjay = j;
						nr++;
					}
				}
			}
		}
	}
	if (kolor == niebieski) {
		int nr = 0;
		for (int j = 5; j < 8; j++) {
			for (int i = 0; i < 8; i++) {
				if (j % 2 == 0) {
					if (i % 2 == 1) {
						P[nr].pozycjax = i;
						P[nr].pozycjay = j;
						nr++;
					}
				}
				if (j % 2 == 1) {
					if (i % 2 == 0) {
						P[nr].pozycjax = i;
						P[nr].pozycjay = j;
						nr++;
					}
				}
			}
		}
	}
}

