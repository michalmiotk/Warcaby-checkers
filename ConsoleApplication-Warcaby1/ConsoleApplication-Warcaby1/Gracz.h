#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "Pionek.h"
using namespace std;

class Gracz
{
public:
	Gracz();
	Gracz(e_kolor, int);
	Gracz(Gracz const & stary_gracz);
	~Gracz();
    e_kolor kolor;
	Pionek P[12];
	int kolejka;
    int sprzycie();//sprawdza czy zyje Ci jeszcze jaki� pionek 0-nie �yje 1-�yje
	void rozmieszczenie();//pocz�tkowe ustawienie
};

