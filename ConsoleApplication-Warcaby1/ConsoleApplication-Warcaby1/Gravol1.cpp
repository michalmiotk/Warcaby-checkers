#include "Gra.h"



Gra::Gra()
{
	Gracz GG1(zolty, 1);
	G[0] = GG1;
	Gracz GG2(niebieski, 0);
	G[1] = GG2;
	kontroler = 0;
	pozycjakontrolerax = 0;
	pozycjakontroleray = 0;
}


Gra::~Gra()
{
}


void Gra::zmienkolor(e_kolor k1)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (k1) {
	case bialy:
		SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED);
		break;
	case mbialy:
		SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
		break;
	case zielony:
		SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);
		break;
	case mzielony:
		SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
		break;
	case zolty:
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED);
		break;
	case mzolty:
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
		break;
	case smzolty:
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
		break;
	case szolty:
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED );
		break;
	case niebieski:
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED);
		break;
	case smniebieski:
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
		break;
	case mniebieski:
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
		break;
	case sniebieski:
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED );
		break;
	case czerwony:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED);
		break;
	case mczerwony:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
		break;
	case zero:
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		break;
	}
}

void Gra::wyswietlplansze()
{
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {
			int s = 0;
			if (pozycjakontrolerax == i && pozycjakontroleray == j) {
				if (j % 2 == 0 && i % 2 == 0) {
					zmienkolor(mzielony);
					cout << "  ";
					zmienkolor(zero);
					s++;
				}
				if (j % 2 == 1 && i % 2 == 1) {
					zmienkolor(mzielony);
					cout << "  ";
					zmienkolor(zero);
					s++;
				}
				for (int m = 0; m < 2; m++) {
					for (int n = 0; n < 12; n++) {
						if (G[m].P[n].pozycjax == i && G[m].P[n].pozycjay == j && G[m].P[n].zycie == 1) {
							if (G[m].kolor == zolty) {
								zmienkolor(mzolty);
								int ASCII = 12;
								cout << (char)ASCII;
								cout << (char)ASCII;
								zmienkolor(zero);
								s++;

							}
							else {
								zmienkolor(mniebieski);
								int ASCII = 11;
								cout << (char)ASCII;
								cout << (char)ASCII;
								zmienkolor(zero);
								s++;
							}
							
						}
					}
				}
				if (s == 0) {
					zmienkolor(mbialy);
					cout << "  ";
					zmienkolor(zero);
				}
			}
			else {
				if (j % 2 == 0 && i % 2 == 0) {
					zmienkolor(zielony);
					cout << "  ";
					zmienkolor(zero);
					s++;
				}
				if (j % 2 == 1 && i % 2 == 1) {
					zmienkolor(zielony);
					cout << "  ";
					zmienkolor(zero);
					s++;
				}
				for (int n = 0; n < 12; n++) {
					for (int m = 0; m < 2; m++) {
						if (G[m].P[n].pozycjax == i && G[m].P[n].pozycjay == j && G[m].P[n].zycie == 1) {
							if (G[m].kolor == zolty) {
								zmienkolor(zolty);
								int ASCII = 12;
								cout << (char)ASCII;
								cout << (char)ASCII;
								zmienkolor(zero);
								s++;

							}
							else {
								zmienkolor(niebieski);
								int ASCII = 11;
								cout << (char)ASCII;
								cout << (char)ASCII;
								zmienkolor(zero);
								s++;
							}
						}
					}
				}
				if (s == 0) {
					zmienkolor(bialy);
					cout << "  ";
					zmienkolor(zero);
				}
			}		
		}
		cout << endl;
	}
}

void Gra::zmienpozycjekontrolera()
{
	bool koniec = false;
	while (koniec == false)
	{
		unsigned char znak = getch();
		switch (znak)
		{
		case 224: //klawisze specjalne
			znak = getch();
			switch (znak)
			{
			case 72: //strza³ka w górê
				pozycjakontroleray--;
				if (pozycjakontroleray < 0) pozycjakontroleray = 0;
				koniec = true;
				break;
			case 80: //strza³ka w dó³
				pozycjakontroleray++;
				if (pozycjakontroleray > 7) pozycjakontroleray = 7;
				koniec = true;
				break;
			case 75: //strza³ka w lewo
				pozycjakontrolerax--;
				if (pozycjakontrolerax < 0) pozycjakontrolerax = 0;
				koniec = true;
				break;
			case 77: //strza³ka w prawo
				pozycjakontrolerax++;
				if (pozycjakontrolerax > 7) pozycjakontrolerax = 7;
				koniec = true;
				break;
			}
			znak = 0;
			break;
		case 32: //spacja
			if (kontroler == 0) {
				for (int i = 0; i < 12; i++) {
					for (int m = 0; m < 2; m++) {
						if (pozycjakontrolerax == G[m].P[i].pozycjax && pozycjakontroleray == G[m].P[i].pozycjay) {
							kontroler = 1;
							G[m].P[i].wruchu = 1;
							i = 12;
						}
					}
				}
			}
			else {
				for (int i = 0; i < 12; i++) {
					for (int m = 0; m < 2; m++) {
						if (pozycjakontrolerax == G[m].P[i].pozycjax && pozycjakontroleray == G[m].P[i].pozycjay) {
							kontroler = 0;
							G[m].P[i].wruchu = 0;
							i = 12;
						}
					}
				}

			}
			
			break;
		case 27: //ESC
			koniec = true;
			break;
		}
	}
}

void Gra::ruchpionka()
{
	Pionek *wsk=NULL;
	for (int m = 0; m < 2; m++) {
		for (int n = 0; n < 12; n++) {
			if (pozycjakontrolerax == G[m].P[n].pozycjax && pozycjakontroleray == G[m].P[n].pozycjay && G[m].P[n].zycie == 1) {
				wsk = &G[m].P[n];
			}
		}
	}


	
}

void Gra::start()
{
	while (getch) {
		system("cls");
		wyswietlplansze();
		zmienpozycjekontrolera();
	}
}
