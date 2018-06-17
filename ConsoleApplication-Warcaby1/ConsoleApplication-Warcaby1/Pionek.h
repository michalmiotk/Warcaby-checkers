#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

enum e_kolor { bialy , mbialy , zielony , mzielony , zolty , mzolty , szolty, smzolty, niebieski, mniebieski, sniebieski, smniebieski, czerwony, mczerwony, zero};
enum e_rodzaj_kamyk{pionek , dama};
class Pionek
{
public:
	Pionek();
	~Pionek();
	Pionek(Pionek const & stary_pionek);
	e_kolor kolor;
	int zycie;
	int dama;
	int pozycjax;
	int pozycjay;
	int wruchu;

	void smierc();
	void wzmocnienie();
	
};

