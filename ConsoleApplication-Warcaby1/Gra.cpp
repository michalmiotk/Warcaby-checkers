#include "Gra.h"
#define ascizolty 254
#define asciniebieski 254
#define glebokosc 5
#define waga_dama 25
#define waga_bicie 50
#define chodzenie_grupa 10
#define trzy_srodek 3
#define dwa_srodek 6
#define srodek 9
#define waga_pionek 20
#define chodzenie_dama 10

Gra::Gra()
{
	Gracz GG1(zolty, 1);
	G[0] = GG1;
	Gracz GG2(niebieski, 0);
	G[1] = GG2;
	kontroler = 0;
	pozycjakontrolerax = 0;
	pozycjakontroleray = 0;
	wsk=NULL;
	ilosc_kombinacji=0;
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
  		SetConsoleTextAttribute(hOut, FOREGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED);
		break;
	case mzolty:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
		break;
	case smzolty:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
		break;
	case szolty:
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED );
		break;
	case niebieski:
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED);
		break;
	case smniebieski:
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
		break;
	case mniebieski:
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
		break;
	case sniebieski:
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED );
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
	int ascii_dama_niebieski=239;
	int ascii_dama_zolty=207;
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {
			int s = 0;
			if (pozycjakontrolerax == i && pozycjakontroleray == j) {
				//zielony
				if (j % 2 == 0 && i % 2 == 0) {
					zmienkolor(mzielony);
					cout << "  ";
					zmienkolor(zero);
					s++;
				}
				//zielony
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
								if (G[m].P[n].wruchu == 1) {
									if (G[m].P[n].dama == 0){
										zmienkolor(smzolty);
										int ASCII = ascizolty;
										cout << (char)ASCII;
										cout << (char)ASCII;
										zmienkolor(zero);
										s++;
									}
									if (G[m].P[n].dama == 1){
										zmienkolor(smzolty);
										cout << (char)ascii_dama_zolty;
										cout << (char)ascii_dama_zolty;
										zmienkolor(zero);
										s++;
									}
								}
								else {
 									if (G[m].P[n].dama == 0){
										zmienkolor(mzolty);
										int ASCII = ascizolty;
										cout << (char)ASCII;
										cout << (char)ASCII;
										zmienkolor(zero);
										s++;
									}
									if (G[m].P[n].dama == 1){
										zmienkolor(mzolty);
										cout << (char)ascii_dama_zolty;
										cout << (char)ascii_dama_zolty;
										zmienkolor(zero);
										s++;
									}
								}

							}
							else {
								if (G[m].P[n].wruchu == 1) {
									if (G[m].P[n].dama == 0) {
										zmienkolor(smniebieski);
										int ASCII = asciniebieski;
										cout << (char)ASCII;
										cout << (char)ASCII;
										zmienkolor(zero);
										s++;
									}
									if (G[m].P[n].dama == 1) {
										zmienkolor(smniebieski);
										cout << (char)ascii_dama_niebieski;
										cout << (char)ascii_dama_niebieski;
										zmienkolor(zero);
										s++;
									}
								}
								else {
    								if (G[m].P[n].dama == 0) {
										zmienkolor(mniebieski);
										int ASCII = asciniebieski;
										cout << (char)ASCII;
										cout << (char)ASCII;
										zmienkolor(zero);
										s++;
									}
									if (G[m].P[n].dama == 1) {
										zmienkolor(mniebieski);
										cout << (char)ascii_dama_niebieski;
										cout << (char)ascii_dama_niebieski;
										zmienkolor(zero);
										s++;
									}
								}
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
			//zielony
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
								if (G[m].P[n].wruchu == 1) {
									if (G[m].P[n].dama == 0) {
										zmienkolor(szolty);
										int ASCII = ascizolty;
										cout << (char)ASCII;
										cout << (char)ASCII;
										zmienkolor(zero);
										s++;
									}
									if (G[m].P[n].dama == 1) {
										zmienkolor(szolty);
										cout << (char)ascii_dama_zolty;
										cout << (char)ascii_dama_zolty;
										zmienkolor(zero);
										s++;
									}
								}
								else {
									if (G[m].P[n].dama == 0) {
										zmienkolor(zolty);
										int ASCII = ascizolty;
										cout << (char)ASCII;
										cout << (char)ASCII;
										zmienkolor(zero);
										s++;
									}
									if (G[m].P[n].dama == 1) {
										zmienkolor(zolty);
										cout << (char)ascii_dama_zolty;
										cout << (char)ascii_dama_zolty;
										zmienkolor(zero);
										s++;
									}
								}								
							}
							else {
								if (G[m].P[n].wruchu == 1) {
									if (G[m].P[n].dama == 0) {
										zmienkolor(sniebieski);
										int ASCII = asciniebieski;
										cout << (char)ASCII;
										cout << (char)ASCII;
										zmienkolor(zero);
										s++;
									}
									if (G[m].P[n].dama == 1) {
										zmienkolor(sniebieski);
										cout << (char)ascii_dama_niebieski;
										cout << (char)ascii_dama_niebieski;
										zmienkolor(zero);
										s++;
									}
								}
								else {
									if (G[m].P[n].dama == 0) {
										zmienkolor(niebieski);
										int ASCII = asciniebieski;
										cout << (char)ASCII;
										cout << (char)ASCII;
										zmienkolor(zero);
										s++;
									}
									if (G[m].P[n].dama == 1) {
										zmienkolor(niebieski);
										cout << (char)ascii_dama_niebieski;
										cout << (char)ascii_dama_niebieski;
										zmienkolor(zero);
										s++;
									}
								}
								
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
	//cout<<"bicie niebieskich"<<sprbicie(niebieski,G[0],G[1],&(plansza_pokaz))<<endl;
	//cout<<"bicie zoltych"<<sprbicie(zolty,G[0],G[1],&(plansza_pokaz))<<endl;
	//cout<<"punktacja niebieskich"<<oblicz_wartosc_planszy(niebieski, plansza_pokaz)<<endl;
	//cout<<"punktacja zoltych"<<oblicz_wartosc_planszy(zolty, plansza_pokaz)<<endl;
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//for(int i=0; i<255; i++){SetConsoleTextAttribute(hConsole,i); cout<<i<<" "<<(char)i<<endl;}
}
void Gra::wyswietlplansze(Gracz* zolt,Gracz* nieb)
{
	int ascii_dama_niebieski=30;
	int ascii_dama_zolty=31;
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {
			int s = 0;
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
				Gracz* gracz[2];
				gracz[0]=zolt;
				gracz[1]=nieb;
				for (int n = 0; n < 12; n++) {
					for (int m = 0; m < 2; m++) {
						if ((*gracz[m]).P[n].pozycjax == i && (*gracz[m]).P[n].pozycjay == j && (*gracz[m]).P[n].zycie == 1) {
							if ((*gracz[m]).kolor == zolty) {
								if ((*gracz[m]).P[n].wruchu == 1) {
									if ((*gracz[m]).P[n].dama == 0) {
										zmienkolor(szolty);
										int ASCII = ascizolty;
										cout << (char)ASCII;
										cout << (char)ASCII;
										zmienkolor(zero);
										s++;
									}
									if ((*gracz[m]).P[n].dama == 1) {
										zmienkolor(szolty);
										cout << (char)ascii_dama_zolty;
										cout << (char)ascii_dama_zolty;
										zmienkolor(zero);
										s++;
									}
								}
								else {
									if ((*gracz[m]).P[n].dama == 0) {
										zmienkolor(zolty);
										int ASCII = ascizolty;
										cout << (char)ASCII;
										cout << (char)ASCII;
										zmienkolor(zero);
										s++;
									}
									if ((*gracz[m]).P[n].dama == 1) {
										zmienkolor(zolty);
										cout << (char)ascii_dama_zolty;
										cout << (char)ascii_dama_zolty;
										zmienkolor(zero);
										s++;
									}
								}								
							}
							else {
								if ((*gracz[m]).P[n].wruchu == 1) {
									if ((*gracz[m]).P[n].dama == 0) {
										zmienkolor(sniebieski);
										int ASCII = asciniebieski;
										cout << (char)ASCII;
										cout << (char)ASCII;
										zmienkolor(zero);
										s++;
									}
									if ((*gracz[m]).P[n].dama == 1) {
										zmienkolor(sniebieski);
										cout << (char)ascii_dama_niebieski;
										cout << (char)ascii_dama_niebieski;
										zmienkolor(zero);
										s++;
									}
								}
								else {
									if ((*gracz[m]).P[n].dama == 0) {
										zmienkolor(niebieski);
										int ASCII = asciniebieski;
										cout << (char)ASCII;
										cout << (char)ASCII;
										zmienkolor(zero);
										s++;
									}
									if ((*gracz[m]).P[n].dama == 1) {
										zmienkolor(niebieski);
										cout << (char)ascii_dama_niebieski;
										cout << (char)ascii_dama_niebieski;
										zmienkolor(zero);
										s++;
									}
								}
								
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
			cout << endl;
		}
		cout << endl;
}

int Gra::sprpionekkontroler(Gracz zolt, Gracz nieb)
{
		for (int n = 0; n < 12; n++) {
			if (zolt.P[n].zycie == 1 && pozycjakontrolerax == zolt.P[n].pozycjax && pozycjakontroleray == zolt.P[n].pozycjay) {
				if (zolt.kolor == zolty) {
					if (zolt.P[n].dama == 0) return 1;
					else return 11;
				}
				if (zolt.kolor == niebieski) {
					if (zolt.P[n].dama == 0) return 2;
					else return 22;
				}
			}
		}
		for (int n = 0; n < 12; n++) {
			if (nieb.P[n].zycie == 1 && pozycjakontrolerax == nieb.P[n].pozycjax && pozycjakontroleray == nieb.P[n].pozycjay) {
				if (nieb.kolor == zolty) {
					if (nieb.P[n].dama == 0) return 1;
					else return 11;
				}
				if (nieb.kolor == niebieski) {
					if (nieb.P[n].dama == 0) return 2;
					else return 22;
				}
			}
		}
	return 0;
}

int Gra::poprawnoscruchu(Pionek* pionek, int nowe_x, int nowe_y,int plansza_kopia[8][8][2])
{
		if(wolne_pole(nowe_x, nowe_y, plansza_kopia)==0)return 0;
		//dla zoltego pionka
		if (pionek->kolor == zolty && pionek->dama == 0) {
			if (pionek->pozycjax == nowe_x + 1 && pionek->pozycjay == nowe_y - 1) return 1;
			if (pionek->pozycjax == nowe_x - 1 && pionek->pozycjay == nowe_y - 1) return 1;
			else return 0;
		}
		//dla zoltej damy 
		if (pionek->kolor == zolty && pionek->dama == 1) {
			for(int i=1;i<8;i++)
				{
					if (pionek->pozycjax == nowe_x + i && pionek->pozycjay == nowe_y - i)
					{
						int a=0;
						for(int j=1;j<i;j++){
							if(plansza_kopia[nowe_x+j][nowe_y-j][0]==zolty || plansza_kopia[nowe_x+j][nowe_y-j][0]==niebieski)
								a++;
						}
						if(a<1)return 1;
					}
					if (pionek->pozycjax == nowe_x - i && pionek->pozycjay == nowe_y - i)
					{
						int a=0;
						for(int j=1;j<i;j++){
							if(plansza_kopia[nowe_x-j][nowe_y-j][0]==zolty ||plansza_kopia[nowe_x-j][nowe_y-j][0]==niebieski)
								a++;
						}
						if(a<1)
							return 1;
					}
					if (pionek->pozycjax == nowe_x + i && pionek->pozycjay == nowe_y + i)
					{
						int a=0;
						for(int j=1;j<i;j++){
							if(plansza_kopia[nowe_x+j][nowe_y+j][0]==zolty || plansza_kopia[nowe_x+j][nowe_y+j][0]==niebieski)
								a++;
						}
						if(a<1)
							return 1;
					}
					if (pionek->pozycjax == nowe_x - i && pionek->pozycjay == nowe_y + i)
					{
						int a=0;
						for(int j=1;j<i;j++){
							if(plansza_kopia[nowe_x-j][nowe_y+j][0]==zolty || plansza_kopia[nowe_x-j][nowe_y+j][0]==niebieski)
								a++;
						}
						if(a<1)
							return 1;
					}
				}
			 return 0;
		}
		//dla niebieskiego pionka
		if (pionek->kolor == niebieski && pionek->dama == 0) { 
			if (pionek->pozycjax == nowe_x + 1 && pionek->pozycjay == nowe_y + 1)
				return 1;
			if (pionek->pozycjax == nowe_x - 1 && pionek->pozycjay == nowe_y + 1) 
				return 1;
			else return 0;
		}
		//dla niebieskiej damy
		if (pionek->kolor == niebieski && pionek->dama == 1) {
				for(int i=1;i<8;i++)
				{
					if (pionek->pozycjax == nowe_x + i && pionek->pozycjay == nowe_y - i)
					{
						int a=0;
						for(int j=1;j<i;j++){
							if(plansza_kopia[nowe_x+j][nowe_y-j][0]==zolty || plansza_kopia[nowe_x+j][nowe_y-j][0]==niebieski)
								a++;
						}
						if(a<1)
							return 1;
					}
					if (pionek->pozycjax == nowe_x - i && pionek->pozycjay == nowe_y - i)
					{
						int a=0;
						for(int j=1;j<i;j++){
							if(plansza_kopia[nowe_x-j][nowe_y-j][0]==zolty ||plansza_kopia[nowe_x-j][nowe_y-j][0]==niebieski)
								a++;
						}
						if(a<1)
							return 1;
					}
					if (pionek->pozycjax == nowe_x + i && pionek->pozycjay == nowe_y + i)
					{
						int a=0;
						for(int j=1;j<i;j++){
							if(plansza_kopia[nowe_x+j][nowe_y+j][0]==zolty || plansza_kopia[nowe_x+j][nowe_y+j][0]==niebieski)
								a++;
						}
						if(a<1)
							return 1;
					}
					if (pionek->pozycjax == nowe_x - i && pionek->pozycjay == nowe_y + i)
					{
						int a=0;
						for(int j=1;j<i;j++){
							if(plansza_kopia[nowe_x-j][nowe_y+j][0]==zolty || plansza_kopia[nowe_x-j][nowe_y+j][0]==niebieski)
								a++;
						}
						if(a<1)
							return 1;
					}
				}
			 return 0;
		}
}

int Gra::sprbicie(e_kolor k1) //zwraca 1 jesli bicie G[0] , 2 jesli bicie G[1] , 0 jesli nie ma bicia
{
	if (k1 == zolty) { //dla pionkow
		for (int n = 0; n < 12; n++) {
			for (int m = 0; m < 12; m++) {
				if (G[0].P[n].dama==0 && G[0].P[n].pozycjax == G[1].P[m].pozycjax + 1 && G[0].P[n].pozycjay == G[1].P[m].pozycjay + 1 && G[0].P[n].zycie == 1 && G[1].P[m].zycie == 1) {  //ruch żółtych LG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (G[0].P[n].pozycjax == G[0].P[p].pozycjax + 2 && G[0].P[n].pozycjay == G[0].P[p].pozycjay + 2
							&& G[0].P[n].zycie == 1 && G[0].P[p].zycie == 1
							&& -1<G[0].P[p].pozycjax + 2<8 && -1<G[0].P[p].pozycjay + 2<8) 
							a++;
						if (G[0].P[n].pozycjax == G[1].P[p].pozycjax + 2 && G[0].P[n].pozycjay == G[1].P[p].pozycjay + 2
							&& G[0].P[n].zycie == 1 && G[1].P[p].zycie == 1
							&& -1<G[1].P[p].pozycjax + 2<8 && -1<G[1].P[p].pozycjay + 2<8)
							a++;
						if (G[0].P[n].pozycjax==1)a++;   //brak spełnienia powyższych warunków gdyż pionek dla pozycji x==1 przesuniety o lewo o 2 nie istnieje
						if (G[0].P[n].pozycjay==1)a++;
					}
					if (a<1) return 1;
				}
				if (G[0].P[n].dama==0 && G[0].P[n].pozycjax == G[1].P[m].pozycjax + 1 && G[0].P[n].pozycjay == G[1].P[m].pozycjay - 1 && G[0].P[n].zycie == 1 && G[1].P[m].zycie == 1) {  //ruch żółtych LD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (G[0].P[n].pozycjax == G[0].P[p].pozycjax + 2 && G[0].P[n].pozycjay == G[0].P[p].pozycjay - 2
							&& G[0].P[n].zycie == 1 && G[0].P[p].zycie == 1
							&& -1<G[0].P[p].pozycjax + 2<8 && -1<G[0].P[p].pozycjay - 2<8) 
							a++;
						if (G[0].P[n].pozycjax == G[1].P[p].pozycjax + 2 && G[0].P[n].pozycjay == G[1].P[p].pozycjay - 2
							&& G[0].P[n].zycie == 1 && G[1].P[p].zycie == 1
							&& -1<G[1].P[p].pozycjax + 2<8 && -1<G[1].P[p].pozycjay - 2<8)
							a++;
						if (G[0].P[n].pozycjay==6)a++;
						if (G[0].P[n].pozycjax==1)a++;
					}
					if (a<1) return 1;
				} 
				if (G[0].P[n].dama==0 && G[0].P[n].pozycjax == G[1].P[m].pozycjax - 1 && G[0].P[n].pozycjay == G[1].P[m].pozycjay + 1 && G[0].P[n].zycie == 1 && G[1].P[m].zycie == 1) {  //ruch żółtych PG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (G[0].P[n].pozycjax == G[0].P[p].pozycjax - 2 && G[0].P[n].pozycjay == G[0].P[p].pozycjay + 2
							&& G[0].P[n].zycie == 1 && G[0].P[p].zycie == 1
							&& -1<G[0].P[p].pozycjax - 2<8 && -1<G[0].P[p].pozycjay + 2<8)
							a++;
						if (G[0].P[n].pozycjax == G[1].P[p].pozycjax - 2 && G[0].P[n].pozycjay == G[1].P[p].pozycjay + 2
							&& G[0].P[n].zycie == 1 && G[1].P[p].zycie == 1
							&& -1<G[1].P[p].pozycjax - 2<8 && -1<G[1].P[p].pozycjay + 2<8)
							a++;
						if (G[0].P[n].pozycjay==1)a++;
					}
					if (a<1) return 1;
				} 
				if(G[0].P[n].dama==0 && G[0].P[n].pozycjax == G[1].P[m].pozycjax - 1 && G[0].P[n].pozycjay == G[1].P[m].pozycjay - 1 && G[0].P[n].zycie == 1 && G[1].P[m].zycie == 1) {  //ruch żółtych PD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (G[0].P[n].pozycjax == G[0].P[p].pozycjax - 2 && G[0].P[n].pozycjay == G[0].P[p].pozycjay - 2
							&& G[0].P[n].zycie == 1 && G[0].P[p].zycie == 1
							&& -1<G[0].P[p].pozycjax - 2<8 && -1<G[0].P[p].pozycjay - 2<8)
							a++;
						if (G[0].P[n].pozycjax == G[1].P[p].pozycjax - 2 && G[0].P[n].pozycjay == G[1].P[p].pozycjay - 2
							&& G[0].P[n].zycie == 1 && G[1].P[p].zycie == 1
							&& -1<G[1].P[p].pozycjax - 2<8 && -1<G[1].P[p].pozycjay - 2<8)
							a++;
						if (G[0].P[n].pozycjax==6)a++;
						if (G[0].P[n].pozycjay==6)a++;
					}
					if (a<1) return 1;
				}
			}

		}
		//zolte damy
		for(int x=0;x<8;x++){
			for(int y=0;y<8;y++){ 
				//wektor PG
				if(plansza_pokaz[x][y][0]==zolty &&plansza_pokaz[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y-i>-1) if(plansza_pokaz[x+i][y-i][0]==zolty) a++;
					}
					int licznik_niebieskich=0;
					int licznik_zoltych=0;
					int licznik_niebieskich_zwiekszony=0;
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y<2)a++;
						if(x+i<8 && y-i>-1)if(plansza_pokaz[x+i-1][y-i+1][0]==niebieski && plansza_pokaz[x+i][y-i][0]==niebieski)a++;
						if(x+i<8 && y-i>-1)if(plansza_pokaz[x+i][y-i][0]==zolty)a++;
						if(x+i<8 && y-i>-1)if(i>1 && plansza_pokaz[x+i-1][y-i+1][0]==niebieski && plansza_pokaz[x+i][y-i][0]==0) break;
						if(x+i<8 && y-i>-1)if((x+i==7 || y-i==0) && (plansza_pokaz[x+i][y-i][0]==0 ||plansza_pokaz[x+i][y-i][0]==niebieski)) a++;
					}
				    if(a<1)
						return 1;
				}
				 //wektor PD
				if(plansza_pokaz[x][y][0]==zolty &&plansza_pokaz[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y+i<8) if(plansza_pokaz[x+i][y+i][0]==zolty) a++;
					}
					int licznik_niebieskich=0;
					int licznik_zoltych=0;
					int licznik_niebieskich_zwiekszony=0;
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y>5)a++;
						if(x+i<8 && y+i<8)if(plansza_pokaz[x+i-1][y+i-1][0]==niebieski && plansza_pokaz[x+i][y+i][0]==niebieski)a++;
						if(x+i<8 && y+i<8)if(plansza_pokaz[x+i][y+i][0]==zolty)a++;
						if(x+i<8 && y+i<8)if(i>1 && plansza_pokaz[x+i-1][y+i-1][0]==niebieski && plansza_pokaz[x+i][y+i][0]==0) break;
						if(x+i<8 && y+i<8)if((x+i==7 || y+i==7) && (plansza_pokaz[x+i][y+i][0]==0 ||plansza_pokaz[x+i][y+i][0]==niebieski)) a++;
					}
				    if(a<1)
						return 1;
				}
				//wektor LG
				if(plansza_pokaz[x][y][0]==zolty &&plansza_pokaz[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y-i>-1) if(plansza_pokaz[x-i][y-i][0]==zolty) a++;
					}
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y<2)a++;
						if(x-i>-1 && y-i>-1)if(plansza_pokaz[x-i+1][y-i+1][0]==niebieski && plansza_pokaz[x-i][y-i][0]==niebieski)a++;
						if(x-i>-1 && y-i>-1)if(plansza_pokaz[x-i][y-i][0]==zolty)a++;
						if(x-i>-1 && y-i>-1)if(i>1 && plansza_pokaz[x-i+1][y-i+1][0]==niebieski && plansza_pokaz[x-i][y-i][0]==0) break;
						if(x-i>-1 && y-i>-1)if((x-i==0 || y-i==0) && (plansza_pokaz[x-i][y-i][0]==0 ||plansza_pokaz[x-i][y-i][0]==niebieski)) a++;
					}
				    if(a<1)
						return 1;
				}
				//wektor LD
				if(plansza_pokaz[x][y][0]==zolty &&plansza_pokaz[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y+i<8) if(plansza_pokaz[x-i][y+i][0]==zolty) a++;
					}
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y>5)a++;
						if(x-i>-1 && y+i<8)if(plansza_pokaz[x-i+1][y+i-1][0]==niebieski && plansza_pokaz[x-i][y+i][0]==niebieski)a++;
						if(x-i>-1 && y+i<8)if(plansza_pokaz[x-i][y+i][0]==zolty)a++;
						if(x-i>-1 && y+i<8)if(i>1 && plansza_pokaz[x-i+1][y+i-1][0]==niebieski && plansza_pokaz[x-i][y+i][0]==0) break;
						if(x-i>-1 && y+i<8)if((x-i==0 || y+i==7) && (plansza_pokaz[x-i][y+i][0]==0 ||plansza_pokaz[x-i][y+i][0]==niebieski)) a++;
					}
				    if(a<1)
						return 1;
				}
			}
		}
		return 0;
	}
	if (k1 == niebieski) { //dla pionkow
		for (int n = 0; n < 12; n++) {
			for (int m = 0; m < 12; m++) {
				if (G[1].P[n].dama==0 && G[1].P[n].pozycjax == G[0].P[m].pozycjax + 1 && G[1].P[n].pozycjay == G[0].P[m].pozycjay + 1 && G[1].P[n].zycie == 1 && G[0].P[m].zycie == 1) {  //ruch niebieskich LG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (G[1].P[n].pozycjax == G[0].P[p].pozycjax + 2 && G[1].P[n].pozycjay == G[0].P[p].pozycjay + 2
							&& G[1].P[n].zycie == 1 && G[0].P[p].zycie == 1
							&& -1<G[0].P[p].pozycjax + 2<8 && -1<G[0].P[p].pozycjay + 2<8)
							a++;
						if (G[1].P[n].pozycjax == G[1].P[p].pozycjax + 2 && G[1].P[n].pozycjay == G[1].P[p].pozycjay + 2
							&& G[1].P[n].zycie == 1 && G[1].P[p].zycie == 1
							&& -1<G[1].P[p].pozycjax + 2<8 && -1<G[1].P[p].pozycjay + 2<8) 
							a++;
						if (G[1].P[n].pozycjax==1)a++;
						if (G[1].P[n].pozycjay==1)a++;
					}
					if (a<1) return 2;
				}
				if (G[1].P[n].dama==0 && G[1].P[n].pozycjax == G[0].P[m].pozycjax + 1 && G[1].P[n].pozycjay == G[0].P[m].pozycjay - 1 && G[0].P[m].zycie == 1 && G[1].P[n].zycie == 1) { //ruch niebieskich LD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (G[1].P[n].pozycjax == G[0].P[p].pozycjax + 2 && G[1].P[n].pozycjay == G[0].P[p].pozycjay - 2
							&& G[1].P[n].zycie == 1 && G[0].P[p].zycie == 1
							&& -1<G[0].P[p].pozycjax + 2<8 && -1<G[0].P[p].pozycjay - 2<8) a++;
						if (G[1].P[n].pozycjax == G[1].P[p].pozycjax + 2 && G[1].P[n].pozycjay == G[1].P[p].pozycjay - 2
							&& G[1].P[n].zycie == 1 && G[1].P[p].zycie == 1
							&& -1<G[1].P[p].pozycjax + 2<8 && -1<G[1].P[p].pozycjay - 2<8) a++;
						if(G[1].P[n].pozycjax==1)a++;
						if(G[1].P[n].pozycjay==6)a++;
					}
					if (a<1) return 2;
				}
				if (G[1].P[n].dama==0 && G[1].P[n].pozycjax == G[0].P[m].pozycjax - 1 && G[1].P[n].pozycjay == G[0].P[m].pozycjay + 1 && G[0].P[m].zycie == 1 && G[1].P[n].zycie == 1) {  //ruch niebieskich PG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (G[1].P[n].pozycjax == G[0].P[p].pozycjax - 2 && G[1].P[n].pozycjay == G[0].P[p].pozycjay + 2
							&& G[1].P[n].zycie == 1 && G[0].P[p].zycie == 1
							&& -1<G[0].P[p].pozycjax - 2<8 && -1<G[0].P[p].pozycjay + 2<8) a++;
						if (G[1].P[n].pozycjax == G[1].P[p].pozycjax - 2 && G[1].P[n].pozycjay == G[1].P[p].pozycjay + 2
							&& G[1].P[n].zycie == 1 && G[1].P[p].zycie == 1
							&& -1<G[1].P[p].pozycjax - 2<8 && -1<G[1].P[p].pozycjay + 2<8) a++;
						if (G[1].P[n].pozycjax==6)a++;
						if (G[1].P[n].pozycjay==1)a++;
					}
					if (a<1) return 2;
				}
				if (G[1].P[n].dama==0 && G[1].P[n].pozycjax == G[0].P[m].pozycjax - 1 && G[1].P[n].pozycjay == G[0].P[m].pozycjay - 1 && G[1].P[n].zycie == 1 && G[0].P[m].zycie == 1) {  //ruch niebieskich PD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (G[1].P[n].pozycjax == G[0].P[p].pozycjax - 2 && G[1].P[n].pozycjay == G[0].P[p].pozycjay - 2
							&& G[1].P[n].zycie == 1 && G[0].P[p].zycie == 1
							&& -1<G[0].P[p].pozycjax - 2<8 && -1<G[0].P[p].pozycjay - 2<8 ) a++;
						if (G[1].P[n].pozycjax == G[1].P[p].pozycjax - 2 && G[1].P[n].pozycjay == G[1].P[p].pozycjay - 2
							&& G[1].P[n].zycie == 1 && G[1].P[p].zycie == 1
							&& -1<G[1].P[p].pozycjax - 2<8 && -1<G[1].P[p].pozycjay - 2<8) a++;
						if(G[1].P[n].pozycjay==6)a++;
						if(G[1].P[n].pozycjax==6)a++;
					}
					if (a<1) return 2;
				}
			}

		}
			//niebieskie damy
		for(int x=0;x<8;x++){
			for(int y=0;y<8;y++){ 
				//wektor PG
				if(plansza_pokaz[x][y][0]==niebieski &&plansza_pokaz[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y-i>-1) if(plansza_pokaz[x+i][y-i][0]==niebieski) a++;
					}
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y<2)a++;
						if(x+i<8 && y-i>-1)if(plansza_pokaz[x+i-1][y-i+1][0]==zolty && plansza_pokaz[x+i][y-i][0]==zolty)a++;
						if(x+i<8 && y-i>-1)if(plansza_pokaz[x+i][y-i][0]==niebieski)a++;
						if(x+i<8 && y-i>-1)if(i>1 && plansza_pokaz[x+i-1][y-i+1][0]==zolty && plansza_pokaz[x+i][y-i][0]==0) break;
						if(x+i<8 && y-i>-1)if((x+i==7 || y-i==0) && (plansza_pokaz[x+i][y-i][0]==0 ||plansza_pokaz[x+i][y-i][0]==zolty)) a++;
					}
				    if(a<1)
						return 2;
				}
				 //wektor PD
				if(plansza_pokaz[x][y][0]==niebieski &&plansza_pokaz[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y+i<8) if(plansza_pokaz[x+i][y+i][0]==niebieski) a++;
					}
					int licznik_niebieskich=0;
					int licznik_zoltych=0;
					int licznik_niebieskich_zwiekszony=0;
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y>5)a++;
						if(x+i<8 && y+i<8)if(plansza_pokaz[x+i-1][y+i-1][0]==zolty && plansza_pokaz[x+i][y+i][0]==zolty)a++;
						if(x+i<8 && y+i<8)if(plansza_pokaz[x+i][y+i][0]==niebieski)a++;
						if(x+i<8 && y+i<8)if(i>1 && plansza_pokaz[x+i-1][y+i-1][0]==zolty && plansza_pokaz[x+i][y+i][0]==0) break;
						if(x+i<8 && y+i<8)if((x+i==7 || y+i==7) && (plansza_pokaz[x+i][y+i][0]==0 ||plansza_pokaz[x+i][y+i][0]==zolty)) a++;
					}
				    if(a<1)
						return 2;
				}
				//wektor LG
				if(plansza_pokaz[x][y][0]==niebieski &&plansza_pokaz[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y-i>-1) if(plansza_pokaz[x-i][y-i][0]==niebieski) a++;
					}
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y<2)a++;
						if(x-i>-1 && y-i>-1)if(plansza_pokaz[x-i+1][y-i+1][0]==zolty && plansza_pokaz[x-i][y-i][0]==zolty)a++;
						if(x-i>-1 && y-i>-1)if(plansza_pokaz[x-i][y-i][0]==niebieski)a++;
						if(x-i>-1 && y-i>-1)if(i>1 && plansza_pokaz[x-i+1][y-i+1][0]==zolty && plansza_pokaz[x-i][y-i][0]==0) break;
						if(x-i>-1 && y-i>-1)if((x-i==0 || y-i==0) && (plansza_pokaz[x-i][y-i][0]==0 ||plansza_pokaz[x-i][y-i][0]==zolty)) a++;
					}
				    if(a<1)
						return 2;
				}
				//wektor LD
				if(plansza_pokaz[x][y][0]==niebieski &&plansza_pokaz[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y+i<8) if(plansza_pokaz[x-i][y+i][0]==niebieski) a++;
					}
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y>5)a++;
						if(x-i>-1 && y+i<8)if(plansza_pokaz[x-i+1][y+i-1][0]==zolty && plansza_pokaz[x-i][y+i][0]==zolty)a++;
						if(x-i>-1 && y+i<8)if(plansza_pokaz[x-i][y+i][0]==niebieski)a++;
						if(x-i>-1 && y+i<8)if(i>1 && plansza_pokaz[x-i+1][y+i-1][0]==zolty && plansza_pokaz[x-i][y+i][0]==0) break;
						if(x-i>-1 && y+i<8)if((x-i==0 || y+i==7) && (plansza_pokaz[x-i][y+i][0]==0 ||plansza_pokaz[x-i][y+i][0]==zolty)) a++;
					}
				    if(a<1)
						return 2;
				}
			}
		}
		return 0;
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
			case 72: //strzałka w górę
				pozycjakontroleray--;
				if (pozycjakontroleray < 0) pozycjakontroleray = 0;
				koniec = true;
				break;
			case 80: //strzałka w dół
				pozycjakontroleray++;
				if (pozycjakontroleray > 7) pozycjakontroleray = 7;
				koniec = true;
				break;
			case 75: //strzałka w lewo
				pozycjakontrolerax--;
				if (pozycjakontrolerax < 0) pozycjakontrolerax = 0;
				koniec = true;
				break;
			case 77: //strzałka w prawo
				pozycjakontrolerax++;
				if (pozycjakontrolerax > 7) pozycjakontrolerax = 7;
				koniec = true;
				break;
			}
			znak = 0;
			break;
		case 32: //spacja
			if (kontroler == 0) {
				podnies_pionek();
				system("cls");
				wyswietlplansze();
				break;
			}
  			if (kontroler == 1) {
				aktualizuj_plansza_pokaz(&G[0], &G[1], plansza_pokaz);
				if ((wsk->kolor==zolty && sprbicie(wsk->kolor) == 1) ||(wsk->kolor==niebieski && sprbicie(wsk->kolor) == 2) ) {
	 					if(poprawnoscbicia() == 1 && sprpionekkontroler(this->G[0], this->G[1])==0) {
							usunpionek();
							wsk_pomocniczy=wsk;
							upuscpionek();
							system("cls");
							aktualizuj_damy(&G[0], &G[1]);
							aktualizuj_plansza_pokaz(&G[0], &G[1], plansza_pokaz);
							wyswietlplansze();
							if (sprbicie_pionka(*wsk_pomocniczy,G[0],G[1])==0) //jesli mój pionek którym wykonałem bicie nie może już bić to ruch komputera 
							{
								if(wykonaj_ruchy_rekurencja(&najlepszy_ruch, zolty, glebokosc, G[0], G[1], 1) !=-1234567){
										wykonaj_najlepszy_ruch(&najlepszy_ruch,&G[0],&G[1]);
										system("cls");
								}
								else
								{
										cout<<"niebieski wygral!!!"<<endl;
										while(1);
								}
								wyswietlplansze();
							}
						}
						else {
							wsk->wruchu = 0;
							wsk=NULL;
							kontroler = 0;
 							break;
						}
						
				}
				if (poprawnoscruchu(wsk, pozycjakontrolerax, pozycjakontroleray, plansza_pokaz) == 1  && sprpionekkontroler(this->G[0], this->G[1]) == 0 && sprbicie(wsk->kolor) ==0) {
					upuscpionek();
					
					aktualizuj_damy(&G[0], &G[1]);
					aktualizuj_plansza_pokaz(&G[0], &G[1], plansza_pokaz);
					system("cls");
					wyswietlplansze();
					sprbicie_pionka(*wsk, G[0],G[1]);
					//system("cls");
					int x=wykonaj_ruchy_rekurencja(&najlepszy_ruch,zolty,glebokosc,G[0], G[1],1);
					if(x!=-1234567){
						wykonaj_najlepszy_ruch(&najlepszy_ruch,&G[0],&G[1]);
						cout<<endl;
						system("cls");
						wyswietlplansze();
						if (mozliwosc_ruchu(niebieski, &G[0], &G[1]) == 0) { cout << "czerwony wygral" << endl; while (1); }
					}
					else
					{
						if(wsk->kolor==niebieski){
								wyswietlplansze();
								cout<<"niebieski wygral!!!"<<endl;
								while(1);
						}
						if(wsk->kolor==zolty){
								wyswietlplansze();
								cout << "żólty wygral!!!" << endl;
								while(1);
						}
					}
				}
				wsk->wruchu = 0;
				wsk=NULL;
				kontroler = 0;
				break;
			}
		case 27: //ESC
			koniec = true;
			break;
		}
	}
}
int Gra::mozliwosc_ruchu(e_kolor kolor, Gracz* zolt, Gracz* nieb){
	ruchy tabela[1000];
	int a=0;
	a=zgromadz_ruchy(kolor,zolt,nieb,&tabela);
	return a;
}
int Gra::zgromadz_ruchy(e_kolor kolor, Gracz* zolt, Gracz* nieb,ruchy (*tabela)[1000]){
	int plansza_kopia[8][8][2] = {};
	aktualizuj_plansza_pokaz(zolt,nieb, plansza_kopia);
	int licznik=0;
	if(sprbicie(kolor, *zolt ,*nieb)==1 ||sprbicie(kolor, *zolt ,*nieb)==2){
		licznik=zaznaczbicie(kolor, zolt ,nieb,&plansza_kopia,tabela);
	}else{
	if(kolor==zolty){
		//dla zoltych pionków
		for(int i=0;i<12;i++){
			if(zolt->P[i].pozycjax+1<8 && zolt->P[i].zycie==1 && zolt->P[i].pozycjay+1<8 && zolt->P[i].dama==0){ 
				if(poprawnoscruchu(&(zolt->P[i]),zolt->P[i].pozycjax+1, zolt->P[i].pozycjay+1,plansza_kopia)==1){ 
					(*tabela)[licznik].wskaznik_pionek=&(zolt->P[i]); 
					(*tabela)[licznik].nowa_x=zolt->P[i].pozycjax+1; 
					(*tabela)[licznik].nowa_y=zolt->P[i].pozycjay+1;
					(*tabela)[licznik].bicie=0;
					licznik++;
				};
			}
			if(zolt->P[i].pozycjax-1>-1 && zolt->P[i].zycie==1 && zolt->P[i].pozycjay+1<8 && zolt->P[i].dama==0)
			{
				if(poprawnoscruchu(&(zolt->P[i]),zolt->P[i].pozycjax-1, zolt->P[i].pozycjay+1,plansza_kopia)==1){ 
					(*tabela)[licznik].wskaznik_pionek=&(zolt->P[i]); 
					(*tabela)[licznik].nowa_x=zolt->P[i].pozycjax-1; 
					(*tabela)[licznik].nowa_y=zolt->P[i].pozycjay+1;
					(*tabela)[licznik].bicie=0;
					licznik++;
				};
			}
			//dla zoltych dam
			//wektor PG
			for(int j=0;j<8;j++){
				if(zolt->P[i].pozycjax+j<8 && zolt->P[i].zycie==1 && zolt->P[i].pozycjay+j<8 && zolt->P[i].dama==1)
			{
				if(poprawnoscruchu(&(zolt->P[i]),zolt->P[i].pozycjax+j, zolt->P[i].pozycjay+j,plansza_kopia)==1){ 
					(*tabela)[licznik].wskaznik_pionek=&(zolt->P[i]); 
					(*tabela)[licznik].nowa_x=zolt->P[i].pozycjax+j; 
					(*tabela)[licznik].nowa_y=zolt->P[i].pozycjay+j;
					(*tabela)[licznik].bicie=0;
					licznik++;
				};
			}
			}
				//wektor LG
			for(int j=0;j<8;j++){
				if(zolt->P[i].pozycjax-j>-1 && zolt->P[i].zycie==1 && zolt->P[i].pozycjay+j<8 && zolt->P[i].dama==1)
			{
				if(poprawnoscruchu(&(zolt->P[i]),zolt->P[i].pozycjax-j, zolt->P[i].pozycjay+j,plansza_kopia)==1){ 
					(*tabela)[licznik].wskaznik_pionek=&(zolt->P[i]); 
					(*tabela)[licznik].nowa_x=zolt->P[i].pozycjax-j; 
					(*tabela)[licznik].nowa_y=zolt->P[i].pozycjay+j;
					(*tabela)[licznik].bicie=0;
					licznik++;
				};
			}
			}
			//wektor PD
			for(int j=0;j<8;j++){
				if(zolt->P[i].pozycjax+j<8 && zolt->P[i].zycie==1 && zolt->P[i].pozycjay-j>-1 && zolt->P[i].dama==1)
			{
				if(poprawnoscruchu(&(zolt->P[i]),zolt->P[i].pozycjax+j, zolt->P[i].pozycjay-j,plansza_kopia)==1){ 
					(*tabela)[licznik].wskaznik_pionek=&(zolt->P[i]); 
					(*tabela)[licznik].nowa_x=zolt->P[i].pozycjax+j; 
					(*tabela)[licznik].nowa_y=zolt->P[i].pozycjay-j;
					(*tabela)[licznik].bicie=0;
					licznik++;
				};
			}
			}
				//wektor LD
			for(int j=0;j<8;j++){
				if(zolt->P[i].pozycjax-j>-1 && zolt->P[i].zycie==1 && zolt->P[i].pozycjay-j>-1 && zolt->P[i].dama==1)
			{
				if(poprawnoscruchu(&(zolt->P[i]),zolt->P[i].pozycjax-j, zolt->P[i].pozycjay-j,plansza_kopia)==1){ 
					(*tabela)[licznik].wskaznik_pionek=&(zolt->P[i]); 
					(*tabela)[licznik].nowa_x=zolt->P[i].pozycjax-j; 
					(*tabela)[licznik].nowa_y=zolt->P[i].pozycjay-j;
					(*tabela)[licznik].bicie=0;
					licznik++;
				};
			}
			}
		}
	}
	if(kolor==niebieski){
		for(int i=0;i<12;i++){
			//dla niebieskich pionków
			if(nieb->P[i].pozycjax+1<8 && nieb->P[i].zycie==1 && nieb->P[i].pozycjay-1>-1 && nieb->P[i].dama==0){ 
				if(poprawnoscruchu(&(nieb->P[i]),nieb->P[i].pozycjax+1, nieb->P[i].pozycjay-1,plansza_kopia)==1){ 
					(*tabela)[licznik].wskaznik_pionek=&(nieb->P[i]); 
					(*tabela)[licznik].nowa_x=nieb->P[i].pozycjax+1; 
					(*tabela)[licznik].nowa_y=nieb->P[i].pozycjay-1;
					(*tabela)[licznik].bicie=0;
					licznik++;
				};
			}
			if(nieb->P[i].pozycjax-1>-1 && nieb->P[i].zycie==1 && nieb->P[i].pozycjay-1>-1 && nieb->P[i].dama==0)
			{
				if(poprawnoscruchu(&(nieb->P[i]),nieb->P[i].pozycjax-1, nieb->P[i].pozycjay-1,plansza_kopia)==1){ 
					(*tabela)[licznik].wskaznik_pionek=&(nieb->P[i]); 
					(*tabela)[licznik].nowa_x=nieb->P[i].pozycjax-1; 
					(*tabela)[licznik].nowa_y=nieb->P[i].pozycjay-1;
					(*tabela)[licznik].bicie=0;
					licznik++;
				};
			}
			//dla niebieskich dam
			//wektor PG
			for(int j=0;j<8;j++){
				if(nieb->P[i].pozycjax+j<8 && nieb->P[i].zycie==1 && nieb->P[i].pozycjay+j<8 && nieb->P[i].dama==1)
			{
				if(poprawnoscruchu(&(nieb->P[i]),nieb->P[i].pozycjax+j, nieb->P[i].pozycjay+j,plansza_kopia)==1){ 
					(*tabela)[licznik].wskaznik_pionek=&(nieb->P[i]); 
					(*tabela)[licznik].nowa_x=nieb->P[i].pozycjax+j; 
					(*tabela)[licznik].nowa_y=nieb->P[i].pozycjay+j;
					(*tabela)[licznik].bicie=0;
					licznik++;
				};
			}
			}
				//wektor LG
			for(int j=0;j<8;j++){
				if(nieb->P[i].pozycjax-j>-1 && nieb->P[i].zycie==1 && nieb->P[i].pozycjay+j<8 && nieb->P[i].dama==1)
			{
				if(poprawnoscruchu(&(nieb->P[i]),nieb->P[i].pozycjax-j, nieb->P[i].pozycjay+j,plansza_kopia)==1){ 
					(*tabela)[licznik].wskaznik_pionek=&(nieb->P[i]); 
					(*tabela)[licznik].nowa_x=nieb->P[i].pozycjax-j; 
					(*tabela)[licznik].nowa_y=nieb->P[i].pozycjay+j;
					(*tabela)[licznik].bicie=0;
					licznik++;
				};
			}
			}
			//wektor PD
			for(int j=0;j<8;j++){
				if(nieb->P[i].pozycjax+j<8 && nieb->P[i].zycie==1 && nieb->P[i].pozycjay-j>-1 && nieb->P[i].dama==1)
			{
				if(poprawnoscruchu(&(nieb->P[i]),nieb->P[i].pozycjax+j, nieb->P[i].pozycjay-j,plansza_kopia)==1){ 
					(*tabela)[licznik].wskaznik_pionek=&(nieb->P[i]); 
					(*tabela)[licznik].nowa_x=nieb->P[i].pozycjax+j; 
					(*tabela)[licznik].nowa_y=nieb->P[i].pozycjay-j;
					(*tabela)[licznik].bicie=0;
					licznik++;
				};
			}
			}
				//wektor LD
			for(int j=0;j<8;j++){
				if(nieb->P[i].pozycjax-j>-1 && nieb->P[i].zycie==1 && nieb->P[i].pozycjay-j>-1 && nieb->P[i].dama==1)
			{
				if(poprawnoscruchu(&(nieb->P[i]),nieb->P[i].pozycjax-j, nieb->P[i].pozycjay-j,plansza_kopia)==1){ 
					(*tabela)[licznik].wskaznik_pionek=&(nieb->P[i]); 
					(*tabela)[licznik].nowa_x=nieb->P[i].pozycjax-j; 
					(*tabela)[licznik].nowa_y=nieb->P[i].pozycjay-j;
					(*tabela)[licznik].bicie=0;
					licznik++;
				};
			}
			}
		}
	}
	}
	return licznik;
}

void Gra::podnies_pionek()
{
	if (kontroler == 0) {
		for (int m = 0; m < 2; m++) {
			for (int n = 0; n < 12; n++) {
				if (pozycjakontrolerax == G[m].P[n].pozycjax && pozycjakontroleray == G[m].P[n].pozycjay && G[m].P[n].zycie == 1) {
					wsk = &G[m].P[n];
					kontroler = 1;
					wsk->wruchu = 1;
				}
			}
		}
	}	
}
int Gra::wektor_ruchu_x(){
	int zwroc=0;
	zwroc=(pozycjakontrolerax-wsk->pozycjax);
	return zwroc;
}
int Gra::wektor_ruchu_y(){
	int zwroc=0;
	zwroc=(pozycjakontroleray-wsk->pozycjay);
	return zwroc;
}
void Gra::upuscpionek()
{
	if (kontroler == 1 && wsk != NULL) {
		wsk->pozycjax = pozycjakontrolerax;
		wsk->pozycjay = pozycjakontroleray;
		kontroler = 0;
		wsk->wruchu = 0;
	}

}
void Gra::upuscpionek(Pionek* pionek, int nowex, int nowey)
{
	if (pionek != NULL) {
		pionek->pozycjax = nowex;
		pionek->pozycjay = nowey;
		pionek->wruchu = 0;
	}

}
void Gra::usunpionek()
{
	if (wsk->kolor == zolty) {
		if ((wektor_ruchu_x()>1 || wektor_ruchu_x()<1) && (wektor_ruchu_y()>1 || wektor_ruchu_y()<1)) {
				for (int n=0; n < 12; n++) {
					 if(wektor_ruchu_x()/2 !=0 && wektor_ruchu_y()/2 !=0){
						 int x=0;
						 int y=0;
						 if(wektor_ruchu_x()>0) x=1;
						 if(wektor_ruchu_x()<0) x=-1;
						 if(wektor_ruchu_y()>0) y=1;
						 if(wektor_ruchu_y()<0) y=-1;
						 if (G[1].P[n].pozycjax == pozycjakontrolerax - x && G[1].P[n].pozycjay == pozycjakontroleray -y && G[1].P[n].zycie == 1) {
							G[1].P[n].smierc();		
						}
				   }		
				}
			}
	}
	if (wsk->kolor == niebieski) {
			if ((wektor_ruchu_x()>1 || wektor_ruchu_x()<1) && (wektor_ruchu_y()>1 || wektor_ruchu_y()<1)) {
				for (int n=0; n < 12; n++) {
					 if(wektor_ruchu_x()/2 !=0 && wektor_ruchu_y()/2 !=0){
						 int x=0;
						 int y=0;
						 if(wektor_ruchu_x()>0) x=1;
						 if(wektor_ruchu_x()<0) x=-1;
						 if(wektor_ruchu_y()>0) y=1;
						 if(wektor_ruchu_y()<0) y=-1;
						if (G[0].P[n].pozycjax == pozycjakontrolerax - x && G[0].P[n].pozycjay == pozycjakontroleray -y && G[0].P[n].zycie == 1) {
							G[0].P[n].smierc();		
						}
				   }		
				}
			}
	}
}
void Gra::usunpionek(Pionek* pionek, int nowex, int nowey, Gracz* zolt, Gracz* nieb)
{
	int wektor_x=wektor_ruchu_x(pionek, nowex);
	int wektor_y=wektor_ruchu_y(pionek, nowey);
	if (pionek->kolor == zolty) {
		if ((wektor_x>1 || wektor_x<1) && (wektor_y>1 || wektor_y<1)) {
				for (int n=0; n < 12; n++) {
					 if(wektor_x/2 !=0 && wektor_y/2 !=0){
						 int x=0;
						 int y=0;
						 if(wektor_x>0) x=1;
						 if(wektor_x<0) x=-1;
						 if(wektor_y>0) y=1;
						 if(wektor_y<0) y=-1;
						 if (nieb->P[n].pozycjax == nowex - x && nieb->P[n].pozycjay == nowey -y && nieb->P[n].zycie == 1) {
							nieb->P[n].smierc();		
						}
				   }		
				}
			}
	}
	if (pionek->kolor == niebieski) {
			if ((wektor_x>1 || wektor_x<1) && (wektor_y>1 || wektor_y<1)) {
				for (int n=0; n < 12; n++) {
					 if(wektor_x/2 !=0 && wektor_y/2 !=0){
						 int x=0;
						 int y=0;
						 if(wektor_x>0) x=1;
						 if(wektor_x<0) x=-1;
						 if(wektor_y>0) y=1;
						 if(wektor_y<0) y=-1;
						if (zolt->P[n].pozycjax == nowex - x && zolt->P[n].pozycjay == nowey -y && zolt->P[n].zycie == 1) {
							zolt->P[n].smierc();		
						}
				   }		
				}
			}
	}
}
void Gra::start()
{
	while (G[0].sprzycie() == 1 && G[1].sprzycie() == 1) {
		while (getch) {
			system("cls");
			wyswietlplansze();
			zmienpozycjekontrolera();
		}
	}
}

void Gra::aktualizuj_plansza_pokaz(Gracz* zolt,Gracz* nieb,int plansza_kopia[8][8][2]) // w plansza_pokaz [x][y][0] - kolor zółty lub niebieski[x][y][1] - 1 to pionek 2 - dama
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			plansza_kopia[i][j][0]=0; //kolor 
		}
	}

	for(int i=0;i<12;i++)
	{

		//żółci
		if (zolt->P[i].zycie == 1 && zolt->P[i].dama == 0)
		{
			if (zolt->P[i].pozycjax<8 && zolt->P[i].pozycjax>-1 && zolt->P[i].pozycjay<8 && zolt->P[i].pozycjay>-1)
			{
				plansza_kopia[zolt->P[i].pozycjax][zolt->P[i].pozycjay][0] = zolty;
				plansza_kopia[zolt->P[i].pozycjax][zolt->P[i].pozycjay][1] = pionek;

			}
		}
		if (zolt->P[i].zycie == 1 && zolt->P[i].dama == 1)
		{
			if (zolt->P[i].pozycjax<8 && zolt->P[i].pozycjax>-1 && zolt->P[i].pozycjay<8 && zolt->P[i].pozycjay>-1)
			{
				plansza_kopia[zolt->P[i].pozycjax][zolt->P[i].pozycjay][0] = zolty;
				plansza_kopia[zolt->P[i].pozycjax][zolt->P[i].pozycjay][1] = dama;

			}
		}
		//niebiescy
		if(nieb->P[i].zycie == 1 && nieb->P[i].dama==0)
		{
			if (nieb->P[i].pozycjax<8 && nieb->P[i].pozycjax>-1 && nieb->P[i].pozycjay<8 && nieb->P[i].pozycjay>-1)
			{
				plansza_kopia[nieb->P[i].pozycjax][nieb->P[i].pozycjay][0] = niebieski;
				plansza_kopia[nieb->P[i].pozycjax][nieb->P[i].pozycjay][1] = pionek;
			}
		}
		if (nieb->P[i].zycie == 1 && nieb->P[i].dama == 1)
		{
			if (nieb->P[i].pozycjax<8 && nieb->P[i].pozycjax>-1 && nieb->P[i].pozycjay<8 && nieb->P[i].pozycjay>-1)
			{
				plansza_kopia[nieb->P[i].pozycjax][nieb->P[i].pozycjay][0] = niebieski;
				plansza_kopia[nieb->P[i].pozycjax][nieb->P[i].pozycjay][1] = dama;

			}
		}
	}
}

void Gra::aktualizuj_damy(Gracz* zolt, Gracz* nieb)
{
	for(int i=0;i<12;i++)
	{
		//żółci
		if(zolt->P[i].zycie == 1 && zolt->P[i].dama==0)
		{
			if(zolt->P[i].pozycjax<8 && zolt->P[i].pozycjax>-1 && zolt->P[i].pozycjay<8 && zolt->P[i].pozycjay>-1)
				if(zolt->P[i].pozycjay==7) zolt->P[i].wzmocnienie();
				
		}
		//niebiescy
		if(nieb->P[i].zycie == 1 && nieb->P[i].dama==0)
		{
			if(nieb->P[i].pozycjax<8 && nieb->P[i].pozycjax>-1 && nieb->P[i].pozycjay<8 && nieb->P[i].pozycjay>-1)
				if(nieb->P[i].pozycjay==0) nieb->P[i].wzmocnienie();	
		}
	}
}
int Gra::oblicz_wartosc_planszy(e_kolor kolor, int plansza_kopia[8][8][2]){
	int punktacja_pionka=15;
	int punktacja_damy=40;
	int punktacja_y=1;
	if(kolor == zolty){
		int wartosc=0;
		for(int x=0;x<8;x++){
			for(int y=0;y<8;y++){
				if(plansza_kopia[x][y][0]==zolty){
					if(plansza_kopia[x][y][1]==pionek){
						wartosc=wartosc+punktacja_pionka+y*punktacja_y;
					}
					if(plansza_kopia[x][y][1]==dama){
						wartosc=wartosc+punktacja_damy;
					}
				}
			}
		}
		return wartosc;
	}
	if(kolor == niebieski){
		int wartosc=0;
		for(int x=0;x<8;x++){
			for(int y=0;y<8;y++){
				if(plansza_kopia[x][y][0]==niebieski){
					if(plansza_kopia[x][y][1]==pionek){
						wartosc=wartosc+punktacja_pionka+(7-y)*punktacja_y;
					}
					if(plansza_kopia[x][y][1]==dama){
						wartosc=wartosc+punktacja_damy;
					}
				}
			}
		}
		return wartosc;
	}
	return -1;
}
int Gra::sprbicie(e_kolor k1, Gracz zolt ,Gracz nieb)//zwraca 1 jesli bicie G[0] , 2 jesli bicie G[1] , 0 jesli nie ma bicia
{
	int plansza_kopia[8][8][2];
	for(int x=0;x<8;x++){
		for(int y=0;y<8;y++){
			plansza_kopia[x][y][0]=0;
			plansza_kopia[x][y][1]=0;
		}
	}
	aktualizuj_plansza_pokaz(&zolt,&nieb,plansza_kopia);
	if (k1 == zolty) { //dla pionkow
		for (int n = 0; n < 12; n++) {
			for (int m = 0; m < 12; m++) {
				if (zolt.P[n].dama==0 && zolt.P[n].pozycjax == nieb.P[m].pozycjax + 1 && zolt.P[n].pozycjay == nieb.P[m].pozycjay + 1 && zolt.P[n].zycie == 1 && nieb.P[m].zycie == 1) {  //ruch żółtych LG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (zolt.P[n].pozycjax == zolt.P[p].pozycjax + 2 && zolt.P[n].pozycjay == zolt.P[p].pozycjay + 2
							&& zolt.P[n].zycie == 1 && zolt.P[p].zycie == 1
							&& -1<zolt.P[p].pozycjax + 2<8 && -1<zolt.P[p].pozycjay + 2<8) 
							a++;
						if (zolt.P[n].pozycjax == nieb.P[p].pozycjax + 2 && zolt.P[n].pozycjay == nieb.P[p].pozycjay + 2
							&& zolt.P[n].zycie == 1 && nieb.P[p].zycie == 1
							&& -1<nieb.P[p].pozycjax + 2<8 && -1<nieb.P[p].pozycjay + 2<8)
							a++;
						if (zolt.P[n].pozycjax==1)a++;   //brak spełnienia powyższych warunków gdyż pionek dla pozycji x==1 przesuniety o lewo o 2 nie istnieje
						if (zolt.P[n].pozycjay==1)a++;
					}
					if (a<1) return 1;
				}
				if (zolt.P[n].dama==0 && zolt.P[n].pozycjax == nieb.P[m].pozycjax + 1 && zolt.P[n].pozycjay == nieb.P[m].pozycjay - 1 && zolt.P[n].zycie == 1 && nieb.P[m].zycie == 1) {  //ruch żółtych LD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (zolt.P[n].pozycjax == zolt.P[p].pozycjax + 2 && zolt.P[n].pozycjay == zolt.P[p].pozycjay - 2
							&& zolt.P[n].zycie == 1 && zolt.P[p].zycie == 1
							&& -1<zolt.P[p].pozycjax + 2<8 && -1<zolt.P[p].pozycjay - 2<8) 
							a++;
						if (zolt.P[n].pozycjax == nieb.P[p].pozycjax + 2 && zolt.P[n].pozycjay == nieb.P[p].pozycjay - 2
							&& zolt.P[n].zycie == 1 && nieb.P[p].zycie == 1
							&& -1<nieb.P[p].pozycjax + 2<8 && -1<nieb.P[p].pozycjay - 2<8)
							a++;
						if (zolt.P[n].pozycjay==6)a++;
						if (zolt.P[n].pozycjax==1)a++;
					}
					if (a<1) return 1;
				} 
				if (zolt.P[n].dama==0 && zolt.P[n].pozycjax == nieb.P[m].pozycjax - 1 && zolt.P[n].pozycjay == nieb.P[m].pozycjay + 1 && zolt.P[n].zycie == 1 && nieb.P[m].zycie == 1) {  //ruch żółtych PG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (zolt.P[n].pozycjax == zolt.P[p].pozycjax - 2 && zolt.P[n].pozycjay == zolt.P[p].pozycjay + 2
							&& zolt.P[n].zycie == 1 && zolt.P[p].zycie == 1
							&& -1<zolt.P[p].pozycjax - 2<8 && -1<zolt.P[p].pozycjay + 2<8)
							a++;
						if (zolt.P[n].pozycjax == nieb.P[p].pozycjax - 2 && zolt.P[n].pozycjay == nieb.P[p].pozycjay + 2
							&& zolt.P[n].zycie == 1 && nieb.P[p].zycie == 1
							&& -1<nieb.P[p].pozycjax - 2<8 && -1<nieb.P[p].pozycjay + 2<8)
							a++;
						if (zolt.P[n].pozycjay==1)a++;
						if (zolt.P[n].pozycjax==6)a++;
					}
					if (a<1) return 1;
				} 
				if(zolt.P[n].dama==0 && zolt.P[n].pozycjax == nieb.P[m].pozycjax - 1 && zolt.P[n].pozycjay == nieb.P[m].pozycjay - 1 && zolt.P[n].zycie == 1 && nieb.P[m].zycie == 1) {  //ruch żółtych PD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (zolt.P[n].pozycjax == zolt.P[p].pozycjax - 2 && zolt.P[n].pozycjay == zolt.P[p].pozycjay - 2
							&& zolt.P[n].zycie == 1 && zolt.P[p].zycie == 1
							&& -1<zolt.P[p].pozycjax - 2<8 && -1<zolt.P[p].pozycjay - 2<8)
							a++;
						if (zolt.P[n].pozycjax == nieb.P[p].pozycjax - 2 && zolt.P[n].pozycjay == nieb.P[p].pozycjay - 2
							&& zolt.P[n].zycie == 1 && nieb.P[p].zycie == 1
							&& -1<nieb.P[p].pozycjax - 2<8 && -1<nieb.P[p].pozycjay - 2<8)
							a++;
						if (zolt.P[n].pozycjax==6)a++;
						if (zolt.P[n].pozycjay==6)a++;
					}
					if (a<1) return 1;
				}
			}

		}
		//zolte damy
		for(int x=0;x<8;x++){
			for(int y=0;y<8;y++){ 
				//wektor PG
				if(plansza_kopia[x][y][0]==zolty &&plansza_kopia[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y-i>-1) if(plansza_kopia[x+i][y-i][0]==zolty) a++;
					}
					int licznik_niebieskich=0;
					int licznik_zoltych=0;
					int licznik_niebieskich_zwiekszony=0;
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y<2)a++;
						if(x+i<8 && y-i>-1)if(plansza_kopia[x+i-1][y-i+1][0]==niebieski && plansza_kopia[x+i][y-i][0]==niebieski)a++;
						if(x+i<8 && y-i>-1)if(plansza_kopia[x+i][y-i][0]==zolty)a++;
						if(x+i<8 && y-i>-1)if(i>1 && plansza_kopia[x+i-1][y-i+1][0]==niebieski && plansza_kopia[x+i][y-i][0]==0) break;
						if(x+i<8 && y-i>-1)if((x+i==7 || y-i==0) && (plansza_kopia[x+i][y-i][0]==0 ||plansza_kopia[x+i][y-i][0]==niebieski)) a++;
					}
				    if(a<1)
						return 1;
				}
				 //wektor PD
				if(plansza_kopia[x][y][0]==zolty &&plansza_kopia[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y+i<8) if(plansza_kopia[x+i][y+i][0]==zolty) a++;
					}
					int licznik_niebieskich=0;
					int licznik_zoltych=0;
					int licznik_niebieskich_zwiekszony=0;
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y>5)a++;
						if(x+i<8 && y+i<8)if(plansza_kopia[x+i-1][y+i-1][0]==niebieski && plansza_kopia[x+i][y+i][0]==niebieski)a++;
						if(x+i<8 && y+i<8)if(plansza_kopia[x+i][y+i][0]==zolty)a++;
						if(x+i<8 && y+i<8)if(i>1 && plansza_kopia[x+i-1][y+i-1][0]==niebieski && plansza_kopia[x+i][y+i][0]==0) break;
						if(x+i<8 && y+i<8)if((x+i==7 || y+i==7) && (plansza_kopia[x+i][y+i][0]==0 ||plansza_kopia[x+i][y+i][0]==niebieski)) a++;
					}
				    if(a<1)
						return 1;
				}
				//wektor LG
				if(plansza_kopia[x][y][0]==zolty &&plansza_kopia[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y-i>-1) if(plansza_kopia[x-i][y-i][0]==zolty) a++;
					}
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y<2)a++;
						if(x-i>-1 && y-i>-1)if(plansza_kopia[x-i+1][y-i+1][0]==niebieski && plansza_kopia[x-i][y-i][0]==niebieski)a++;
						if(x-i>-1 && y-i>-1)if(plansza_kopia[x-i][y-i][0]==zolty)a++;
						if(x-i>-1 && y-i>-1)if(i>1 && plansza_kopia[x-i+1][y-i+1][0]==niebieski && plansza_kopia[x-i][y-i][0]==0) break;
						if(x-i>-1 && y-i>-1)if((x-i==0 || y-i==0) && (plansza_kopia[x-i][y-i][0]==0 ||plansza_kopia[x-i][y-i][0]==niebieski)) a++;
					}
				    if(a<1)
						return 1;
				}
				//wektor LD
				if(plansza_kopia[x][y][0]==zolty &&plansza_kopia[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y+i<8) if(plansza_kopia[x-i][y+i][0]==zolty) a++;
					}
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y>5)a++;
						if(x-i>-1 && y+i<8)if(plansza_kopia[x-i+1][y+i-1][0]==niebieski && plansza_kopia[x-i][y+i][0]==niebieski)a++;
						if(x-i>-1 && y+i<8)if(plansza_kopia[x-i][y+i][0]==zolty)a++;
						if(x-i>-1 && y+i<8)if(i>1 && plansza_kopia[x-i+1][y+i-1][0]==niebieski && plansza_kopia[x-i][y+i][0]==0) break;
						if(x-i>-1 && y+i<8)if((x-i==0 || y+i==7) && (plansza_kopia[x-i][y+i][0]==0 ||plansza_kopia[x-i][y+i][0]==niebieski)) a++;
					}
				    if(a<1)
						return 1;
				}
			}
		}
		return 0;
	}
	if (k1 == niebieski) { //dla pionkow
		for (int n = 0; n < 12; n++) {
			for (int m = 0; m < 12; m++) {
				if (nieb.P[n].dama==0 && nieb.P[n].pozycjax == zolt.P[m].pozycjax + 1 && nieb.P[n].pozycjay == zolt.P[m].pozycjay + 1 && nieb.P[n].zycie == 1 && zolt.P[m].zycie == 1) {  //ruch niebieskich LG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (nieb.P[n].pozycjax == zolt.P[p].pozycjax + 2 && nieb.P[n].pozycjay == zolt.P[p].pozycjay + 2
							&& nieb.P[n].zycie == 1 && zolt.P[p].zycie == 1
							&& -1<zolt.P[p].pozycjax + 2<8 && -1<zolt.P[p].pozycjay + 2<8)
							a++;
						if (nieb.P[n].pozycjax == nieb.P[p].pozycjax + 2 && nieb.P[n].pozycjay == nieb.P[p].pozycjay + 2
							&& nieb.P[n].zycie == 1 && nieb.P[p].zycie == 1
							&& -1<nieb.P[p].pozycjax + 2<8 && -1<nieb.P[p].pozycjay + 2<8) 
							a++;
						if (nieb.P[n].pozycjax==1)a++;
						if (nieb.P[n].pozycjay==1)a++;
					}
					if (a<1) return 2;
				}
				if (nieb.P[n].dama==0 && nieb.P[n].pozycjax == zolt.P[m].pozycjax + 1 && nieb.P[n].pozycjay == zolt.P[m].pozycjay - 1 && zolt.P[m].zycie == 1 && nieb.P[n].zycie == 1) { //ruch niebieskich LD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (nieb.P[n].pozycjax == zolt.P[p].pozycjax + 2 && nieb.P[n].pozycjay == zolt.P[p].pozycjay - 2
							&& nieb.P[n].zycie == 1 && zolt.P[p].zycie == 1
							&& -1<zolt.P[p].pozycjax + 2<8 && -1<zolt.P[p].pozycjay - 2<8) a++;
						if (nieb.P[n].pozycjax == nieb.P[p].pozycjax + 2 && nieb.P[n].pozycjay == nieb.P[p].pozycjay - 2
							&& nieb.P[n].zycie == 1 && nieb.P[p].zycie == 1
							&& -1<nieb.P[p].pozycjax + 2<8 && -1<nieb.P[p].pozycjay - 2<8) a++;
						if(nieb.P[n].pozycjax==1)a++;
						if(nieb.P[n].pozycjay==6)a++;
					}
					if (a<1) return 2;
				}
				if (nieb.P[n].dama==0 && nieb.P[n].pozycjax == zolt.P[m].pozycjax - 1 && nieb.P[n].pozycjay == zolt.P[m].pozycjay + 1 && zolt.P[m].zycie == 1 && nieb.P[n].zycie == 1) {  //ruch niebieskich PG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (nieb.P[n].pozycjax == zolt.P[p].pozycjax - 2 && nieb.P[n].pozycjay == zolt.P[p].pozycjay + 2
							&& nieb.P[n].zycie == 1 && zolt.P[p].zycie == 1
							&& -1<zolt.P[p].pozycjax - 2<8 && -1<zolt.P[p].pozycjay + 2<8) a++;
						if (nieb.P[n].pozycjax == nieb.P[p].pozycjax - 2 && nieb.P[n].pozycjay == nieb.P[p].pozycjay + 2
							&& nieb.P[n].zycie == 1 && nieb.P[p].zycie == 1
							&& -1<nieb.P[p].pozycjax - 2<8 && -1<nieb.P[p].pozycjay + 2<8) a++;
						if (nieb.P[n].pozycjax==6)a++;
						if (nieb.P[n].pozycjay==1)a++;
					}
					if (a<1) return 2;
				}
				if (nieb.P[n].dama==0 && nieb.P[n].pozycjax == zolt.P[m].pozycjax - 1 && nieb.P[n].pozycjay == zolt.P[m].pozycjay - 1 && nieb.P[n].zycie == 1 && zolt.P[m].zycie == 1) {  //ruch niebieskich PD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (nieb.P[n].pozycjax == zolt.P[p].pozycjax - 2 && nieb.P[n].pozycjay == zolt.P[p].pozycjay - 2
							&& nieb.P[n].zycie == 1 && zolt.P[p].zycie == 1
							&& -1<zolt.P[p].pozycjax - 2<8 && -1<zolt.P[p].pozycjay - 2<8 ) a++;
						if (nieb.P[n].pozycjax == nieb.P[p].pozycjax - 2 && nieb.P[n].pozycjay == nieb.P[p].pozycjay - 2
							&& nieb.P[n].zycie == 1 && nieb.P[p].zycie == 1
							&& -1<nieb.P[p].pozycjax - 2<8 && -1<nieb.P[p].pozycjay - 2<8) a++;
						if(nieb.P[n].pozycjay==6)a++;
						if(nieb.P[n].pozycjax==6)a++;
					}
					if (a<1) return 2;
				}
			}

		}
			//niebieskie damy
		for(int x=0;x<8;x++){
			for(int y=0;y<8;y++){ 
				//wektor PG
				if(plansza_kopia[x][y][0]==niebieski &&plansza_kopia[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y-i>-1) if(plansza_kopia[x+i][y-i][0]==niebieski) a++;
					}
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y<2)a++;
						if(x+i<8 && y-i>-1)if(plansza_kopia[x+i-1][y-i+1][0]==zolty && plansza_kopia[x+i][y-i][0]==zolty)a++;
						if(x+i<8 && y-i>-1)if(plansza_kopia[x+i][y-i][0]==niebieski)a++;
						if(x+i<8 && y-i>-1)if(i>1 && plansza_kopia[x+i-1][y-i+1][0]==zolty && plansza_kopia[x+i][y-i][0]==0) break;
						if(x+i<8 && y-i>-1)if((x+i==7 || y-i==0) && (plansza_kopia[x+i][y-i][0]==0 ||plansza_kopia[x+i][y-i][0]==zolty)) a++;
					}
				    if(a<1)
						return 2;
				}
				 //wektor PD
				if(plansza_kopia[x][y][0]==niebieski &&plansza_kopia[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y+i<8) if(plansza_kopia[x+i][y+i][0]==niebieski) a++;
					}
					int licznik_niebieskich=0;
					int licznik_zoltych=0;
					int licznik_niebieskich_zwiekszony=0;
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y>5)a++;
						if(x+i<8 && y+i<8)if(plansza_kopia[x+i-1][y+i-1][0]==zolty && plansza_kopia[x+i][y+i][0]==zolty)a++;
						if(x+i<8 && y+i<8)if(plansza_kopia[x+i][y+i][0]==niebieski)a++;
						if(x+i<8 && y+i<8)if(i>1 && plansza_kopia[x+i-1][y+i-1][0]==zolty && plansza_kopia[x+i][y+i][0]==0) break;
						if(x+i<8 && y+i<8)if((x+i==7 || y+i==7) && (plansza_kopia[x+i][y+i][0]==0 ||plansza_kopia[x+i][y+i][0]==zolty)) a++;
					}
				    if(a<1)
						return 2;
				}
				//wektor LG
				if(plansza_kopia[x][y][0]==niebieski &&plansza_kopia[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y-i>-1) if(plansza_kopia[x-i][y-i][0]==niebieski) a++;
					}
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y<2)a++;
						if(x-i>-1 && y-i>-1)if(plansza_kopia[x-i+1][y-i+1][0]==zolty && plansza_kopia[x-i][y-i][0]==zolty)a++;
						if(x-i>-1 && y-i>-1)if(plansza_kopia[x-i][y-i][0]==niebieski)a++;
						if(x-i>-1 && y-i>-1)if(i>1 && plansza_kopia[x-i+1][y-i+1][0]==zolty && plansza_kopia[x-i][y-i][0]==0) break;
						if(x-i>-1 && y-i>-1)if((x-i==0 || y-i==0) && (plansza_kopia[x-i][y-i][0]==0 ||plansza_kopia[x-i][y-i][0]==zolty)) a++;
					}
				    if(a<1)
						return 2;
				}
				//wektor LD
				if(plansza_kopia[x][y][0]==niebieski &&plansza_kopia[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y+i<8) if(plansza_kopia[x-i][y+i][0]==niebieski) a++;
					}
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y>5)a++;
						if(x-i>-1 && y+i<8)if(plansza_kopia[x-i+1][y+i-1][0]==zolty && plansza_kopia[x-i][y+i][0]==zolty)a++;
						if(x-i>-1 && y+i<8)if(plansza_kopia[x-i][y+i][0]==niebieski)a++;
						if(x-i>-1 && y+i<8)if(i>1 && plansza_kopia[x-i+1][y+i-1][0]==zolty && plansza_kopia[x-i][y+i][0]==0) break;
						if(x-i>-1 && y+i<8)if((x-i==0 || y+i==7) && (plansza_kopia[x-i][y+i][0]==0 ||plansza_kopia[x-i][y+i][0]==zolty)) a++;
					}
				    if(a<1)
						return 2;
				}
			}
		}
		return 0;
	}
}
int Gra::wolne_pole(int x, int y,int plansza_kopia[8][8][2]){
	if(x>-1 && x<8 && y>-1 && y<8){
		if(plansza_kopia[x][y][0]==0) return 1;
		else return 0;
	}
	else return 0;
}
int Gra::sprbicie_pionka(Pionek pionek, Gracz zolt ,Gracz nieb)//zwraca 1 jesli bicie G[0] , 2 jesli bicie G[1] , 0 jesli nie ma bicia
{
	int plansza_kopia[8][8][2] = {};
	aktualizuj_plansza_pokaz(&zolt,&nieb,plansza_kopia);
	if (pionek.kolor == zolty){ //dla pionkow
			for (int m = 0; m < 12; m++) {
				if (pionek.dama==0 && pionek.pozycjax == nieb.P[m].pozycjax + 1 && pionek.pozycjay == nieb.P[m].pozycjay + 1 && pionek.zycie == 1 && nieb.P[m].zycie == 1) {  //ruch żółtych LG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (pionek.pozycjax == zolt.P[p].pozycjax + 2 && pionek.pozycjay == zolt.P[p].pozycjay + 2
							&& -1<zolt.P[p].pozycjax + 2<8 && -1<zolt.P[p].pozycjay + 2<8) 
							a++;
						if (pionek.pozycjax == nieb.P[p].pozycjax + 2 && pionek.pozycjay == nieb.P[p].pozycjay + 2
							&& pionek.zycie == 1 && nieb.P[p].zycie == 1
							&& -1<nieb.P[p].pozycjax + 2<8 && -1<nieb.P[p].pozycjay + 2<8)
							a++;
						if (pionek.pozycjax==1)a++;   //brak spełnienia powyższych warunków gdyż pionek dla pozycji x==1 przesuniety o lewo o 2 nie istnieje
						if (pionek.pozycjay==1)a++;
					}
					if (a<1) return 1;
				}
				if (pionek.dama==0 && pionek.pozycjax == nieb.P[m].pozycjax + 1 && pionek.pozycjay == nieb.P[m].pozycjay - 1 && pionek.zycie == 1 && nieb.P[m].zycie == 1) {  //ruch żółtych LD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (pionek.pozycjax == zolt.P[p].pozycjax + 2 && pionek.pozycjay == zolt.P[p].pozycjay - 2
							&& pionek.zycie == 1 && zolt.P[p].zycie == 1
							&& -1<zolt.P[p].pozycjax + 2<8 && -1<zolt.P[p].pozycjay - 2<8) 
							a++;
						if (pionek.pozycjax == nieb.P[p].pozycjax + 2 && pionek.pozycjay == nieb.P[p].pozycjay - 2
							&& pionek.zycie == 1 && nieb.P[p].zycie == 1
							&& -1<nieb.P[p].pozycjax + 2<8 && -1<nieb.P[p].pozycjay - 2<8)
							a++;
						if (pionek.pozycjay==6)a++;
						if (pionek.pozycjax==1)a++;
					}
					if (a<1) return 1;
				} 
				if (pionek.dama==0 && pionek.pozycjax == nieb.P[m].pozycjax - 1 && pionek.pozycjay == nieb.P[m].pozycjay + 1 && pionek.zycie == 1 && nieb.P[m].zycie == 1) {  //ruch żółtych PG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (pionek.pozycjax == zolt.P[p].pozycjax - 2 && pionek.pozycjay == zolt.P[p].pozycjay + 2
							&& pionek.zycie == 1 && zolt.P[p].zycie == 1
							&& -1<zolt.P[p].pozycjax - 2<8 && -1<zolt.P[p].pozycjay + 2<8)
							a++;
						if (pionek.pozycjax == nieb.P[p].pozycjax - 2 && pionek.pozycjay == nieb.P[p].pozycjay + 2
							&& pionek.zycie == 1 && nieb.P[p].zycie == 1
							&& -1<nieb.P[p].pozycjax - 2<8 && -1<nieb.P[p].pozycjay + 2<8)
							a++;
						if (pionek.pozycjax==6)a++;
						if (pionek.pozycjay==1)a++;
					}
					if (a<1) return 1;
				} 
				if(pionek.dama==0 && pionek.pozycjax == nieb.P[m].pozycjax - 1 && pionek.pozycjay == nieb.P[m].pozycjay - 1 && pionek.zycie == 1 && nieb.P[m].zycie == 1) {  //ruch żółtych PD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (pionek.pozycjax == zolt.P[p].pozycjax - 2 && pionek.pozycjay == zolt.P[p].pozycjay - 2
							&& pionek.zycie == 1 && zolt.P[p].zycie == 1
							&& -1<zolt.P[p].pozycjax - 2<8 && -1<zolt.P[p].pozycjay - 2<8)
							a++;
						if (pionek.pozycjax == nieb.P[p].pozycjax - 2 && pionek.pozycjay == nieb.P[p].pozycjay - 2
							&& pionek.zycie == 1 && nieb.P[p].zycie == 1
							&& -1<nieb.P[p].pozycjax - 2<8 && -1<nieb.P[p].pozycjay - 2<8)
							a++;
						if (pionek.pozycjax==6)a++;
						if (pionek.pozycjay==6)a++;
					}
					if (a<1) return 1;
				}
			}
		        int x=pionek.pozycjax;
				int y=pionek.pozycjay;
				//wektor PG
				if(plansza_kopia[x][y][0]==zolty &&plansza_kopia[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y-i>-1) if(plansza_kopia[x+i][y-i][0]==zolty) a++;
					}
					int licznik_niebieskich=0;
					int licznik_zoltych=0;
					int licznik_niebieskich_zwiekszony=0;
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y<2)a++;
						if(x+i<8 && y-i>-1)if(plansza_kopia[x+i-1][y-i+1][0]==niebieski && plansza_kopia[x+i][y-i][0]==niebieski)a++;
						if(x+i<8 && y-i>-1)if(plansza_kopia[x+i][y-i][0]==zolty)a++;
						if(x+i<8 && y-i>-1)if(i>1 && plansza_kopia[x+i-1][y-i+1][0]==niebieski && plansza_kopia[x+i][y-i][0]==0) break;
						if(x+i<8 && y-i>-1)if((x+i==7 || y-i==0) && (plansza_kopia[x+i][y-i][0]==0 ||plansza_kopia[x+i][y-i][0]==niebieski)) a++;
					}
				    if(a<1)
						return 1;
				}
				 //wektor PD
				if(plansza_kopia[x][y][0]==zolty &&plansza_kopia[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y+i<8) if(plansza_kopia[x+i][y+i][0]==zolty) a++;
					}
					int licznik_niebieskich=0;
					int licznik_zoltych=0;
					int licznik_niebieskich_zwiekszony=0;
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y>5)a++;
						if(x+i<8 && y+i<8)if(plansza_kopia[x+i-1][y+i-1][0]==niebieski && plansza_kopia[x+i][y+i][0]==niebieski)a++;
						if(x+i<8 && y+i<8)if(plansza_kopia[x+i][y+i][0]==zolty)a++;
						if(x+i<8 && y+i<8)if(i>1 && plansza_kopia[x+i-1][y+i-1][0]==niebieski && plansza_kopia[x+i][y+i][0]==0) break;
						if(x+i<8 && y+i<8)if((x+i==7 || y+i==7) && (plansza_kopia[x+i][y+i][0]==0 ||plansza_kopia[x+i][y+i][0]==niebieski)) a++;
					}
				    if(a<1)
						return 1;
				}
				//wektor LG
				if(plansza_kopia[x][y][0]==zolty &&plansza_kopia[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y-i>-1) if(plansza_kopia[x-i][y-i][0]==zolty) a++;
					}
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y<2)a++;
						if(x-i>-1 && y-i>-1)if(plansza_kopia[x-i+1][y-i+1][0]==niebieski && plansza_kopia[x-i][y-i][0]==niebieski)a++;
						if(x-i>-1 && y-i>-1)if(plansza_kopia[x-i][y-i][0]==zolty)a++;
						if(x-i>-1 && y-i>-1)if(i>1 && plansza_kopia[x-i+1][y-i+1][0]==niebieski && plansza_kopia[x-i][y-i][0]==0) break;
						if(x-i>-1 && y-i>-1)if((x-i==0 || y-i==0) && (plansza_kopia[x-i][y-i][0]==0 ||plansza_kopia[x-i][y-i][0]==niebieski)) a++;
					}
				    if(a<1)
						return 1;
				}
				//wektor LD
				if(plansza_kopia[x][y][0]==zolty &&plansza_kopia[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y+i<8) if(plansza_kopia[x-i][y+i][0]==zolty) a++;
					}
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y>5)a++;
						if(x-i>-1 && y+i<8)if(plansza_kopia[x-i+1][y+i-1][0]==niebieski && plansza_kopia[x-i][y+i][0]==niebieski)a++;
						if(x-i>-1 && y+i<8)if(plansza_kopia[x-i][y+i][0]==zolty)a++;
						if(x-i>-1 && y+i<8)if(i>1 && plansza_kopia[x-i+1][y+i-1][0]==niebieski && plansza_kopia[x-i][y+i][0]==0) break;
						if(x-i>-1 && y+i<8)if((x-i==0 || y+i==7) && (plansza_kopia[x-i][y+i][0]==0 ||plansza_kopia[x-i][y+i][0]==niebieski)) a++;
					}
				    if(a<1)
						return 1;
				}
		return 0;
	}
	if (pionek.kolor == niebieski) { //dla pionkow
			for (int m = 0; m < 12; m++) {
				if (pionek.dama==0 && pionek.pozycjax == zolt.P[m].pozycjax + 1 && pionek.pozycjay == zolt.P[m].pozycjay + 1 && pionek.zycie == 1 && zolt.P[m].zycie == 1) {  //ruch niebieskich LG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (pionek.pozycjax == zolt.P[p].pozycjax + 2 && pionek.pozycjay == zolt.P[p].pozycjay + 2
							&& pionek.zycie == 1 && zolt.P[p].zycie == 1
							&& -1<zolt.P[p].pozycjax + 2<8 && -1<zolt.P[p].pozycjay + 2<8)
							a++;
						if (pionek.pozycjax == nieb.P[p].pozycjax + 2 && pionek.pozycjay == nieb.P[p].pozycjay + 2
							&& pionek.zycie == 1 && nieb.P[p].zycie == 1
							&& -1<nieb.P[p].pozycjax + 2<8 && -1<nieb.P[p].pozycjay + 2<8) 
							a++;
						if (pionek.pozycjax==1)a++;
						if (pionek.pozycjay==1)a++;
					}
					if (a<1) return 2;
				}
				if (pionek.dama==0 && pionek.pozycjax == zolt.P[m].pozycjax + 1 && pionek.pozycjay == zolt.P[m].pozycjay - 1 && zolt.P[m].zycie == 1 && pionek.zycie == 1) { //ruch niebieskich LD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (pionek.pozycjax == zolt.P[p].pozycjax + 2 && pionek.pozycjay == zolt.P[p].pozycjay - 2
							&& pionek.zycie == 1 && zolt.P[p].zycie == 1
							&& -1<zolt.P[p].pozycjax + 2<8 && -1<zolt.P[p].pozycjay - 2<8) a++;
						if (pionek.pozycjax == nieb.P[p].pozycjax + 2 && pionek.pozycjay == nieb.P[p].pozycjay - 2
							&& pionek.zycie == 1 && nieb.P[p].zycie == 1
							&& -1<nieb.P[p].pozycjax + 2<8 && -1<nieb.P[p].pozycjay - 2<8) a++;
						if(pionek.pozycjax==1)a++;
						if(pionek.pozycjay==6)a++;
					}
					if (a<1) return 2;
				}
				if (pionek.dama==0 && pionek.pozycjax == zolt.P[m].pozycjax - 1 && pionek.pozycjay == zolt.P[m].pozycjay + 1 && zolt.P[m].zycie == 1 && pionek.zycie == 1) {  //ruch niebieskich PG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (pionek.pozycjax == zolt.P[p].pozycjax - 2 && pionek.pozycjay == zolt.P[p].pozycjay + 2
							&& pionek.zycie == 1 && zolt.P[p].zycie == 1
							&& -1<zolt.P[p].pozycjax - 2<8 && -1<zolt.P[p].pozycjay + 2<8) a++;
						if (pionek.pozycjax == nieb.P[p].pozycjax - 2 && pionek.pozycjay == nieb.P[p].pozycjay + 2
							&& pionek.zycie == 1 && nieb.P[p].zycie == 1
							&& -1<nieb.P[p].pozycjax - 2<8 && -1<nieb.P[p].pozycjay + 2<8) a++;
						if (pionek.pozycjax==6)a++;
						if (pionek.pozycjay==1)a++;
					}
					if (a<1) return 2;
				}
				if (pionek.dama==0 && pionek.pozycjax == zolt.P[m].pozycjax - 1 && pionek.pozycjay == zolt.P[m].pozycjay - 1 && pionek.zycie == 1 && zolt.P[m].zycie == 1) {  //ruch niebieskich PD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if (pionek.pozycjax == zolt.P[p].pozycjax - 2 && pionek.pozycjay == zolt.P[p].pozycjay - 2
							&& pionek.zycie == 1 && zolt.P[p].zycie == 1
							&& -1<zolt.P[p].pozycjax - 2<8 && -1<zolt.P[p].pozycjay - 2<8 ) a++;
						if (pionek.pozycjax == nieb.P[p].pozycjax - 2 && pionek.pozycjay == nieb.P[p].pozycjay - 2
							&& pionek.zycie == 1 && nieb.P[p].zycie == 1
							&& -1<nieb.P[p].pozycjax - 2<8 && -1<nieb.P[p].pozycjay - 2<8) a++;
						if(pionek.pozycjay==6)a++;
						if(pionek.pozycjax==6)a++;
					}
					if (a<1) return 2;
				}
			}

			//niebieskie damy
			int x=pionek.pozycjax;
			int y=pionek.pozycjay;
				//wektor PG
				if(plansza_kopia[x][y][0]==niebieski &&plansza_kopia[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y-i>-1) if(plansza_kopia[x+i][y-i][0]==niebieski) a++;
					}
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y<2)a++;
						if(x+i<8 && y-i>-1)if(plansza_kopia[x+i-1][y-i+1][0]==zolty && plansza_kopia[x+i][y-i][0]==zolty)a++;
						if(x+i<8 && y-i>-1)if(plansza_kopia[x+i][y-i][0]==niebieski)a++;
						if(x+i<8 && y-i>-1)if(i>1 && plansza_kopia[x+i-1][y-i+1][0]==zolty && plansza_kopia[x+i][y-i][0]==0) break;
						if(x+i<8 && y-i>-1)if((x+i==7 || y-i==0) && (plansza_kopia[x+i][y-i][0]==0 ||plansza_kopia[x+i][y-i][0]==zolty)) a++;
					}
				    if(a<1)
						return 2;
				}
				 //wektor PD
				if(plansza_kopia[x][y][0]==niebieski &&plansza_kopia[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y+i<8) if(plansza_kopia[x+i][y+i][0]==niebieski) a++;
					}
					int licznik_niebieskich=0;
					int licznik_zoltych=0;
					int licznik_niebieskich_zwiekszony=0;
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y>5)a++;
						if(x+i<8 && y+i<8)if(plansza_kopia[x+i-1][y+i-1][0]==zolty && plansza_kopia[x+i][y+i][0]==zolty)a++;
						if(x+i<8 && y+i<8)if(plansza_kopia[x+i][y+i][0]==niebieski)a++;
						if(x+i<8 && y+i<8)if(i>1 && plansza_kopia[x+i-1][y+i-1][0]==zolty && plansza_kopia[x+i][y+i][0]==0) break;
						if(x+i<8 && y+i<8)if((x+i==7 || y+i==7) && (plansza_kopia[x+i][y+i][0]==0 ||plansza_kopia[x+i][y+i][0]==zolty)) a++;
					}
				    if(a<1)
						return 2;
				}
				//wektor LG
				if(plansza_kopia[x][y][0]==niebieski &&plansza_kopia[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y-i>-1) if(plansza_kopia[x-i][y-i][0]==niebieski) a++;
					}
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y<2)a++;
						if(x-i>-1 && y-i>-1)if(plansza_kopia[x-i+1][y-i+1][0]==zolty && plansza_kopia[x-i][y-i][0]==zolty)a++;
						if(x-i>-1 && y-i>-1)if(plansza_kopia[x-i][y-i][0]==niebieski)a++;
						if(x-i>-1 && y-i>-1)if(i>1 && plansza_kopia[x-i+1][y-i+1][0]==zolty && plansza_kopia[x-i][y-i][0]==0) break;
						if(x-i>-1 && y-i>-1)if((x-i==0 || y-i==0) && (plansza_kopia[x-i][y-i][0]==0 ||plansza_kopia[x-i][y-i][0]==zolty)) a++;
					}
				    if(a<1)
						return 2;
				}
				//wektor LD
				if(plansza_kopia[x][y][0]==niebieski &&plansza_kopia[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y+i<8) if(plansza_kopia[x-i][y+i][0]==niebieski) a++;
					}
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y>5)a++;
						if(x-i>-1 && y+i<8)if(plansza_kopia[x-i+1][y+i-1][0]==zolty && plansza_kopia[x-i][y+i][0]==zolty)a++;
						if(x-i>-1 && y+i<8)if(plansza_kopia[x-i][y+i][0]==niebieski)a++;
						if(x-i>-1 && y+i<8)if(i>1 && plansza_kopia[x-i+1][y+i-1][0]==zolty && plansza_kopia[x-i][y+i][0]==0) break;
						if(x-i>-1 && y+i<8)if((x-i==0 || y+i==7) && (plansza_kopia[x-i][y+i][0]==0 ||plansza_kopia[x-i][y+i][0]==zolty)) a++;
					}
				    if(a<1)
						return 2;
				}
		return 0;
	}
}

int Gra::poprawnoscbicia()
{
		aktualizuj_plansza_pokaz(&G[0], &G[1], plansza_pokaz);
		if (wsk->kolor == zolty) {
			if (wsk->pozycjax == pozycjakontrolerax + 2 && wsk->pozycjay == pozycjakontroleray - 2) {
				for (int n=0; n < 12; n++) {
					if (G[1].P[n].pozycjax == pozycjakontrolerax + 1 && G[1].P[n].pozycjay == pozycjakontroleray - 1 && G[1].P[n].zycie == 1) {
						return 1;
					}
				}			
			}
			if (wsk->pozycjax == pozycjakontrolerax - 2 && wsk->pozycjay == pozycjakontroleray - 2) {
				for (int n=0; n < 12; n++) {
					if (G[1].P[n].pozycjax == pozycjakontrolerax - 1 && G[1].P[n].pozycjay == pozycjakontroleray - 1 && G[1].P[n].zycie == 1) {
						return 1;
					}
				}			
			}
			if(wsk->pozycjax == pozycjakontrolerax + 2 && wsk->pozycjay == pozycjakontroleray + 2) {
				for (int n = 0; n < 12; n++) {
					if (G[1].P[n].pozycjax == pozycjakontrolerax + 1 && G[1].P[n].pozycjay == pozycjakontroleray + 1 && G[1].P[n].zycie == 1) {
						return 1;
					}
				}
			}
			if (wsk->pozycjax == pozycjakontrolerax - 2 && wsk->pozycjay == pozycjakontroleray + 2) {
				for (int n = 0; n < 12; n++) {
					if (G[1].P[n].pozycjax == pozycjakontrolerax - 1 && G[1].P[n].pozycjay == pozycjakontroleray + 1 && G[1].P[n].zycie == 1) {
						return 1;
					}
				}
			}
			//dla ¿ó³tych dam
			if(wsk->dama==1){
				if(wektor_ruchu_x()>1 && wektor_ruchu_y()<-1) { //wektor PG
					int x=wsk->pozycjax;
					int y=wsk->pozycjay;
					int a=0;
					int przemieszczenie=wektor_ruchu_x();
					for(int i=1;i<3;i++){
						if(x+i<8 && y-i>-1) if(plansza_pokaz[x+i][y-i][0]==zolty) a++;
					}
					int licznik_niebieskich=0;
					for(int i=1;i<przemieszczenie;i++){if(x+i<8 && y-i>-1)if(plansza_pokaz[x+i][y-i][0]==niebieski)licznik_niebieskich++;}
					for(int i=1;i<przemieszczenie;i++){if(x+i<8 && y-i>-1)if(plansza_pokaz[x+i][y-i][0]==zolty)a++;}
					if(x+przemieszczenie<8 && y-przemieszczenie>-1)if(plansza_pokaz[x+przemieszczenie-1][y-przemieszczenie+1][0]==0)a++;
					for(int i=1;i<przemieszczenie;i++){
						if(x>5)a++;
						if(y<2)a++;
						if(x+i<8 && y-i>-1)if(i>1 && plansza_pokaz[x+i-1][y-i+1][0]==niebieski && plansza_pokaz[x+i][y-i][0]==0) break;
						if(x+i<8 && y-i>-1)if((x+i==7 || y-i==0) && (plansza_pokaz[x+i][y-i][0]==0 ||plansza_pokaz[x+i][y-i][0]==niebieski)) a++;
					}
					if(licznik_niebieskich>1)a++;
				    if(a<1)
						return 1;
				}
				if(wektor_ruchu_x()>1 && wektor_ruchu_y()>1){  //wektor PD
					int x=wsk->pozycjax;
					int y=wsk->pozycjay;
					int a=0;
					int przemieszczenie=wektor_ruchu_x();
					for(int i=1;i<3;i++){
						if(x+i<8 && y+i<8) if(plansza_pokaz[x+i][y+i][0]==zolty) a++;
					}
					int licznik_niebieskich=0;
					for(int i=1;i<przemieszczenie;i++){if(x+i<8 && y+i<8)if(plansza_pokaz[x+i][y+i][0]==niebieski)licznik_niebieskich++;}
					for(int i=1;i<przemieszczenie;i++){if(x+i<8 && y+i<8)if(plansza_pokaz[x+i][y+i][0]==zolty)a++;}
					if(x+przemieszczenie<8 && y+przemieszczenie<8)if(plansza_pokaz[x+przemieszczenie-1][y+przemieszczenie-1][0]==0)a++;
					for(int i=1;i<przemieszczenie;i++){
						if(x>5)a++;
						if(y>5)a++;
						if(x+i<8 && y+i<8)if(i>1 && plansza_pokaz[x+i-1][y+i-1][0]==niebieski && plansza_pokaz[x+i][y+i][0]==0) break;
						if(x+i<8 && y+i<8)if((x+i==7 || y+i==7) && (plansza_pokaz[x+i][y+i][0]==0 ||plansza_pokaz[x+i][y+i][0]==niebieski)) a++;
					}
					if(licznik_niebieskich>1)a++;
				    if(a<1)
						return 1;
				}
				if(wektor_ruchu_x()<-1 && wektor_ruchu_y()<-1) { //wektor LG
					int x=wsk->pozycjax;
					int y=wsk->pozycjay;
					int a=0;
					int przemieszczenie = -1*wektor_ruchu_x();
					for(int i=1;i<3;i++){
						if(x-i>-1 && y-i>-1) if(plansza_pokaz[x-i][y-i][0]==zolty) a++;
					}
					int licznik_niebieskich=0;
					for(int i=1;i<przemieszczenie;i++){if(x-i>-1 && y-i>-1)if(plansza_pokaz[x-i][y-i][0]==niebieski)licznik_niebieskich++;}
					for(int i=1;i<przemieszczenie;i++){if(x-i>-1 && y-i>-1)if(plansza_pokaz[x-i][y-i][0]==zolty)a++;}
					if(x-przemieszczenie>-1 && y-przemieszczenie>-1)if(plansza_pokaz[x-przemieszczenie+1][y-przemieszczenie+1][0]==0)a++;
					for(int i=1;i<przemieszczenie;i++){
						if(x<2)a++;
						if(y<2)a++;
						if(x-i>-1 && y-i>-1)if(i>1 && plansza_pokaz[x-i+1][y-i+1][0]==niebieski && plansza_pokaz[x-i][y-i][0]==0) break;
						if(x-i>-1 && y-i>-1)if((x-i==0 || y-1==0) && (plansza_pokaz[x-i][y-i][0]==0 ||plansza_pokaz[x-i][y-i][0]==niebieski)) a++;
					}
					if(licznik_niebieskich>1)a++;
				    if(a<1)
						return 1;
				}
				if(wektor_ruchu_x()<-1 && wektor_ruchu_y()>1) { //wektor LD
					int x=wsk->pozycjax;
					int y=wsk->pozycjay;
					int a=0;
					int przemieszczenie=-1*wektor_ruchu_x();
					for(int i=1;i<3;i++){
						if(x-i>-1 && y+i<8) if(plansza_pokaz[x-i][y+i][0]==zolty) a++;
					}
					int licznik_niebieskich=0;
					for(int i=1;i<przemieszczenie;i++){if(x-i>-1 && y+i<8)if(plansza_pokaz[x-i][y+i][0]==niebieski)licznik_niebieskich++;}
					for(int i=1;i<przemieszczenie;i++){if(x-i>-1 && y+i<8)if(plansza_pokaz[x-i][y+i][0]==zolty)a++;}
					if(x-przemieszczenie>-1 && y+przemieszczenie<8)if(plansza_pokaz[x-przemieszczenie+1][y+przemieszczenie-1][0]==0)a++;
					for(int i=1;i<przemieszczenie;i++){
						if(x<2)a++;
						if(y>5)a++;
						if(x-i>-1 && y+i<8)if(i>1 && plansza_pokaz[x-i+1][y+i-1][0]==niebieski && plansza_pokaz[x-i][y+i][0]==0) break;
						if(x-i>-1 && y+i<8)if((x-i==0 || y+i==8) && (plansza_pokaz[x-i][y+i][0]==0 ||plansza_pokaz[x-i][y+i][0]==niebieski)) a++;
					}
					if(licznik_niebieskich>1)a++;
				    if(a<1)
						return 1;
				}
			}
			return 0;
		}
		//dla niebieskiego
		if (wsk->kolor == niebieski){
			if (wsk->pozycjax == pozycjakontrolerax + 2 && wsk->pozycjay == pozycjakontroleray + 2) {
				for (int n=0; n < 12; n++) {
					if (G[0].P[n].pozycjax == pozycjakontrolerax + 1 && G[0].P[n].pozycjay == pozycjakontroleray + 1 && G[0].P[n].zycie == 1) {
						return 1;
					}
				}			
			}
			if (wsk->pozycjax == pozycjakontrolerax - 2 && wsk->pozycjay == pozycjakontroleray + 2) {
				for (int n=0; n < 12; n++) {
					if (G[0].P[n].pozycjax == pozycjakontrolerax - 1 && G[0].P[n].pozycjay == pozycjakontroleray + 1 && G[0].P[n].zycie == 1) {
						return 1;
					}
				}
			}
			if (wsk->pozycjax == pozycjakontrolerax + 2 && wsk->pozycjay == pozycjakontroleray - 2) {
				for (int n = 0; n < 12; n++) {
					if (G[0].P[n].pozycjax == pozycjakontrolerax + 1 && G[0].P[n].pozycjay == pozycjakontroleray - 1 && G[0].P[n].zycie == 1) {
						return 1;
					}
				}
			}
			if (wsk->pozycjax == pozycjakontrolerax - 2 && wsk->pozycjay == pozycjakontroleray - 2) {
				for (int n = 0; n < 12; n++) {
					if (G[0].P[n].pozycjax == pozycjakontrolerax - 1 && G[0].P[n].pozycjay == pozycjakontroleray - 1 && G[0].P[n].zycie == 1) {
						return 1;
					}
				}
			}
		// niebieskie damy
		if(wsk->dama==1){
				if(wektor_ruchu_x()>1 && wektor_ruchu_y()<-1) { //wektor PG
					int x=wsk->pozycjax;
					int y=wsk->pozycjay;
					int a=0;
					int przemieszczenie=wektor_ruchu_x();
					for(int i=1;i<3;i++){
						if(x+i<8 && y-i>-1) if(plansza_pokaz[x+i][y-i][0]==niebieski) a++;
					}
					int licznik_zoltych=0;
					for(int i=1;i<przemieszczenie;i++){if(x+i<8 && y-i>-1)if(plansza_pokaz[x+i][y-i][0]==zolty)licznik_zoltych++;}
					for(int i=1;i<przemieszczenie;i++){if(x+i<8 && y-i>-1)if(plansza_pokaz[x+i][y-i][0]==niebieski)a++;}
					if(x+przemieszczenie<8 && y-przemieszczenie>-1)if(plansza_pokaz[x+przemieszczenie-1][y-przemieszczenie+1][0]==0)a++;
					for(int i=1;i<przemieszczenie;i++){
						if(x>5)a++;
						if(y<2)a++;
						if(x+i<8 && y-i>-1)if(i>1 && plansza_pokaz[x+i-1][y-i+1][0]==zolty && plansza_pokaz[x+i][y-i][0]==0) break;
						if(x+i<8 && y-i>-1)if((x+i==7 || y-i==0) && (plansza_pokaz[x+i][y-i][0]==0 ||plansza_pokaz[x+i][y-i][0]==zolty)) a++;
					}
					if(licznik_zoltych>1)a++;
				    if(a<1)
						return 1;
				}
				if(wektor_ruchu_x()>1 && wektor_ruchu_y()>1){  //wektor PD niebieskie damy
					int x=wsk->pozycjax;
					int y=wsk->pozycjay;
					int a=0;
					int przemieszczenie=wektor_ruchu_x();
					for(int i=1;i<3;i++){
						if(x+i<8 && y+i<8) if(plansza_pokaz[x+i][y+i][0]==niebieski) a++;
					}
					int licznik_zoltych=0;
					for(int i=1;i<przemieszczenie;i++){if(x+i<8 && y+i<8)if(plansza_pokaz[x+i][y+i][0]==zolty)licznik_zoltych++;}
					for(int i=1;i<przemieszczenie;i++){if(x+i<8 && y+i<8)if(plansza_pokaz[x+i][y+i][0]==niebieski)a++;}
					if(x+przemieszczenie<8 && y+przemieszczenie<8)if(plansza_pokaz[x+przemieszczenie-1][y+przemieszczenie-1][0]==0)a++;
					for(int i=1;i<przemieszczenie;i++){
						if(x>5)a++;
						if(y>5)a++;
						if(x+i<8 && y+i<8)if(i>1 && plansza_pokaz[x+i-1][y+i-1][0]==zolty && plansza_pokaz[x+i][y+i][0]==0) break;
						if(x+i<8 && y+i<8)if((x+i==7 || y+i==7) && (plansza_pokaz[x+i][y+i][0]==0 ||plansza_pokaz[x+i][y+i][0]==zolty)) a++;
					}
					if(licznik_zoltych>1)a++;
				    if(a<1)
						return 1;
				}
				if(wektor_ruchu_x()<-1 && wektor_ruchu_y()<-1) { //wektor LG
					int x=wsk->pozycjax;
					int y=wsk->pozycjay;
					int a=0;
					int przemieszczenie = -1*wektor_ruchu_x();
					for(int i=1;i<3;i++){
						if(x-i>-1 && y-i>-1) if(plansza_pokaz[x-i][y-i][0]==niebieski) a++;
					}
					int licznik_zoltych=0;
					for(int i=1;i<przemieszczenie;i++){if(x-i>-1 && y-i>-1)if(plansza_pokaz[x-i][y-i][0]==zolty)licznik_zoltych++;}
					for(int i=1;i<przemieszczenie;i++){if(x-i>-1 && y-i>-1)if(plansza_pokaz[x-i][y-i][0]==niebieski)a++;}
					if(x-przemieszczenie>-1 && y-przemieszczenie>-1)if(plansza_pokaz[x-przemieszczenie+1][y-przemieszczenie+1][0]==0)a++;
					for(int i=1;i<przemieszczenie;i++){
						if(x<2)a++;
						if(y<2)a++;
						if(x-i>-1 && y-i>-1)if(i>1 && plansza_pokaz[x-i+1][y-i+1][0]==zolty && plansza_pokaz[x-i][y-i][0]==0) break;
						if(x-i>-1 && y-i>-1)if((x-i==0 || y-1==0) && (plansza_pokaz[x-i][y-i][0]==0 ||plansza_pokaz[x-i][y-i][0]==zolty)) a++;
					}
					if(licznik_zoltych>1)a++;
				    if(a<1)
						return 1;
				}
				if(wektor_ruchu_x()<-1 && wektor_ruchu_y()>1) { //wektor LD
					int x=wsk->pozycjax;
					int y=wsk->pozycjay;
					int a=0;
					int przemieszczenie=-1*wektor_ruchu_x();
					for(int i=1;i<3;i++){
						if(x-i>-1 && y+i<8) if(plansza_pokaz[x-i][y+i][0]==niebieski) a++;
					}
					int licznik_zoltych=0;
					for(int i=1;i<przemieszczenie;i++){if(x-i>-1 && y+i<8)if(plansza_pokaz[x-i][y+i][0]==zolty)licznik_zoltych++;}
					for(int i=1;i<przemieszczenie;i++){if(x-i>-1 && y+i<8)if(plansza_pokaz[x-i][y+i][0]==niebieski)a++;}
					if(x-przemieszczenie>-1 && y+przemieszczenie<8)if(plansza_pokaz[x-przemieszczenie+1][y+przemieszczenie-1][0]==0)a++;
					for(int i=1;i<przemieszczenie;i++){
						if(x<2)a++;
						if(y>5)a++;
						if(x-i>-1 && y+i<8)if(i>1 && plansza_pokaz[x-i+1][y+i-1][0]==zolty && plansza_pokaz[x-i][y+i][0]==0) break;
						if(x-i>-1 && y+i<8)if((x-i==0 || y+i==8) && (plansza_pokaz[x-i][y+i][0]==0 ||plansza_pokaz[x-i][y+i][0]==zolty)) a++;
					}
					if(licznik_zoltych>1)a++;
				    if(a<1)
						return 1;
				}
			}
	return 0;
	}
}

int Gra::poprawnoscbicia(Pionek* pionek,Gracz zolt,Gracz nieb,int nowe_x,int nowe_y)
{		
		int plansza_kopia [8][8][2];
		for(int x=0;x<8;x++){
			for(int y=0;y<8;y++){
				plansza_kopia[x][y][0]=0;
			}
		}
		aktualizuj_plansza_pokaz(&zolt, &nieb,plansza_kopia);
		int wektor_x=wektor_ruchu_x(pionek, nowe_x);
		int wektor_y=wektor_ruchu_y(pionek, nowe_y);
		if(!wolne_pole(nowe_x, nowe_y, plansza_kopia))return 0;
		if (pionek->kolor == zolty) {
			if (pionek->pozycjax == nowe_x + 2 && pionek->pozycjay == nowe_y - 2) {
				for (int n=0; n < 12; n++) {
					if (nieb.P[n].pozycjax == nowe_x + 1 && nieb.P[n].pozycjay == nowe_y - 1 && nieb.P[n].zycie == 1) {
						return 1;
					}
				}			
			}
			if (pionek->pozycjax == nowe_x - 2 && pionek->pozycjay == nowe_y - 2) {
				for (int n=0; n < 12; n++) {
					if (nieb.P[n].pozycjax == nowe_x - 1 && nieb.P[n].pozycjay == nowe_y - 1 && nieb.P[n].zycie == 1) {
						return 1;
					}
				}			
			}
			if(pionek->pozycjax == nowe_x + 2 && pionek->pozycjay == nowe_y + 2) {
				for (int n = 0; n < 12; n++) {
					if (nieb.P[n].pozycjax == nowe_x + 1 && nieb.P[n].pozycjay == nowe_y + 1 && nieb.P[n].zycie == 1) {
						return 1;
					}
				}
			}
			if (pionek->pozycjax == nowe_x - 2 && pionek->pozycjay == nowe_y + 2) {
				for (int n = 0; n < 12; n++) {
					if (nieb.P[n].pozycjax == nowe_x - 1 && nieb.P[n].pozycjay == nowe_y + 1 && nieb.P[n].zycie == 1) {
						return 1;
					}
				}
			}
			//dla żółtych dam
			if(pionek->dama==1){
				if(wektor_x>1 && wektor_y<-1) { //wektor PG
					int x=pionek->pozycjax;
					int y=pionek->pozycjay;
					int a=0;
					int przemieszczenie=wektor_x;
					for(int i=1;i<3;i++){
						if(x+i<8 && y-i>-1) if(plansza_pokaz[x+i][y-i][0]==zolty) a++;
					}
					int licznik_niebieskich=0;
					for(int i=1;i<przemieszczenie;i++){if(x+i<8 && y-i>-1)if(plansza_kopia[x+i][y-i][0]==niebieski)licznik_niebieskich++;}
					for(int i=1;i<przemieszczenie;i++){if(x+i<8 && y-i>-1)if(plansza_kopia[x+i][y-i][0]==zolty)a++;}
					if(x+przemieszczenie<8 && y-przemieszczenie>-1)if(plansza_kopia[x+przemieszczenie-1][y-przemieszczenie+1][0]==0)a++;
					for(int i=1;i<przemieszczenie;i++){
						if(x>5)a++;
						if(y<2)a++;
						if(x+i<8 && y-i>-1)if(i>1 && plansza_kopia[x+i-1][y-i+1][0]==niebieski && plansza_kopia[x+i][y-i][0]==0) break;
						if(x+i<8 && y-i>-1)if((x+i==7 || y-i==0) && (plansza_kopia[x+i][y-i][0]==0 ||plansza_kopia[x+i][y-i][0]==niebieski)) a++;
					}
					if(licznik_niebieskich>1)a++;
				    if(a<1)
						return 1;
				}
				if(wektor_x>1 && wektor_y>1){  //wektor PD
					int x=pionek->pozycjax;
					int y=pionek->pozycjay;
					int a=0;
					int przemieszczenie=wektor_x;
					for(int i=1;i<3;i++){
						if(x+i<8 && y+i<8) if(plansza_kopia[x+i][y+i][0]==zolty) a++;
					}
					int licznik_niebieskich=0;
					for(int i=1;i<przemieszczenie;i++){if(x+i<8 && y+i<8)if(plansza_kopia[x+i][y+i][0]==niebieski)licznik_niebieskich++;}
					for(int i=1;i<przemieszczenie;i++){if(x+i<8 && y+i<8)if(plansza_kopia[x+i][y+i][0]==zolty)a++;}
					if(x+przemieszczenie<8 && y+przemieszczenie<8)if(plansza_kopia[x+przemieszczenie-1][y+przemieszczenie-1][0]==0)a++;
					for(int i=1;i<przemieszczenie;i++){
						if(x>5)a++;
						if(y>5)a++;
						if(x+i<8 && y+i<8)if(i>1 && plansza_kopia[x+i-1][y+i-1][0]==niebieski && plansza_kopia[x+i][y+i][0]==0) break;
						if(x+i<8 && y+i<8)if((x+i==7 || y+i==7) && (plansza_kopia[x+i][y+i][0]==0 ||plansza_kopia[x+i][y+i][0]==niebieski)) a++;
					}
					if(licznik_niebieskich>1)a++;
				    if(a<1)
						return 1;
				}
				if(wektor_x<-1 && wektor_y<-1) { //wektor LG
					int x=pionek->pozycjax;
					int y=pionek->pozycjay;
					int a=0;
					int przemieszczenie = -1*wektor_x;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y-i>-1) if(plansza_kopia[x-i][y-i][0]==zolty) a++;
					}
					int licznik_niebieskich=0;
					for(int i=1;i<przemieszczenie;i++){if(x-i>-1 && y-i>-1)if(plansza_kopia[x-i][y-i][0]==niebieski)licznik_niebieskich++;}
					for(int i=1;i<przemieszczenie;i++){if(x-i>-1 && y-i>-1)if(plansza_kopia[x-i][y-i][0]==zolty)a++;}
					if(x-przemieszczenie>-1 && y-przemieszczenie>-1)if(plansza_kopia[x-przemieszczenie+1][y-przemieszczenie+1][0]==0)a++;
					for(int i=1;i<przemieszczenie;i++){
						if(x<2)a++;
						if(y<2)a++;
						if(x-i>-1 && y-i>-1)if(i>1 && plansza_kopia[x-i+1][y-i+1][0]==niebieski && plansza_kopia[x-i][y-i][0]==0) break;
						if(x-i>-1 && y-i>-1)if((x-i==0 || y-1==0) && (plansza_kopia[x-i][y-i][0]==0 ||plansza_kopia[x-i][y-i][0]==niebieski)) a++;
					}
					if(licznik_niebieskich>1)a++;
				    if(a<1)
						return 1;
				}
				if(wektor_x<-1 && wektor_y>1) { //wektor LD
					int x=pionek->pozycjax;
					int y=pionek->pozycjay;
					int a=0;
					int przemieszczenie=-1*wektor_x;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y+i<8) if(plansza_kopia[x-i][y+i][0]==zolty) a++;
					}
					int licznik_niebieskich=0;
					for(int i=1;i<przemieszczenie;i++){if(x-i>-1 && y+i<8)if(plansza_kopia[x-i][y+i][0]==niebieski)licznik_niebieskich++;}
					for(int i=1;i<przemieszczenie;i++){if(x-i>-1 && y+i<8)if(plansza_kopia[x-i][y+i][0]==zolty)a++;}
					if(x-przemieszczenie>-1 && y+przemieszczenie<8)if(plansza_kopia[x-przemieszczenie+1][y+przemieszczenie-1][0]==0)a++;
					for(int i=1;i<przemieszczenie;i++){
						if(x<2)a++;
						if(y>5)a++;
						if(x-i>-1 && y+i<8)if(i>1 && plansza_kopia[x-i+1][y+i-1][0]==niebieski && plansza_kopia[x-i][y+i][0]==0) break;
						if(x-i>-1 && y+i<8)if((x-i==0 || y+i==8) && (plansza_kopia[x-i][y+i][0]==0 ||plansza_kopia[x-i][y+i][0]==niebieski)) a++;
					}
					if(licznik_niebieskich>1)a++;
				    if(a<1)
						return 1;
				}
			}
			return 0;
		}
		//dla niebieskiego
		if (pionek->kolor == niebieski){
			if (pionek->pozycjax == nowe_x + 2 && pionek->pozycjay == nowe_y + 2) {
				for (int n=0; n < 12; n++) {
					if (zolt.P[n].pozycjax == nowe_x + 1 && zolt.P[n].pozycjay == nowe_y + 1 && zolt.P[n].zycie == 1) {
						return 1;
					}
				}			
			}
			if (pionek->pozycjax == nowe_x - 2 && pionek->pozycjay == nowe_y + 2) {
				for (int n=0; n < 12; n++) {
					if (zolt.P[n].pozycjax == nowe_x - 1 && zolt.P[n].pozycjay == nowe_y + 1 && zolt.P[n].zycie == 1) {
						return 1;
					}
				}
			}
			if (pionek->pozycjax == nowe_x + 2 && pionek->pozycjay == nowe_y - 2) {
				for (int n = 0; n < 12; n++) {
					if (zolt.P[n].pozycjax == nowe_x + 1 && zolt.P[n].pozycjay == nowe_y - 1 && zolt.P[n].zycie == 1) {
						return 1;
					}
				}
			}
			if (pionek->pozycjax == nowe_x - 2 && pionek->pozycjay == nowe_y - 2) {
				for (int n = 0; n < 12; n++) {
					if (zolt.P[n].pozycjax == nowe_x - 1 && zolt.P[n].pozycjay == nowe_y - 1 && zolt.P[n].zycie == 1) {
						return 1;
					}
				}
			}
		// niebieskie damy
		if(pionek->dama==1){
				if(wektor_x>1 && wektor_y<-1) { //wektor PG
					int x=pionek->pozycjax;
					int y=pionek->pozycjay;
					int a=0;
					int przemieszczenie=wektor_x;
					for(int i=1;i<3;i++){
						if(x+i<8 && y-i>-1) if(plansza_pokaz[x+i][y-i][0]==niebieski) a++;
					}
					int licznik_zoltych=0;
					for(int i=1;i<przemieszczenie;i++){if(x+i<8 && y-i>-1)if(plansza_kopia[x+i][y-i][0]==zolty)licznik_zoltych++;}
					for(int i=1;i<przemieszczenie;i++){if(x+i<8 && y-i>-1)if(plansza_kopia[x+i][y-i][0]==niebieski)a++;}
					if(x+przemieszczenie<8 && y-przemieszczenie>-1)if(plansza_kopia[x+przemieszczenie-1][y-przemieszczenie+1][0]==0)a++;
					for(int i=1;i<przemieszczenie;i++){
						if(x>5)a++;
						if(y<2)a++;
						if(x+i<8 && y-i>-1)if(i>1 && plansza_kopia[x+i-1][y-i+1][0]==zolty && plansza_kopia[x+i][y-i][0]==0) break;
						if(x+i<8 && y-i>-1)if((x+i==7 || y-i==0) && (plansza_kopia[x+i][y-i][0]==0 ||plansza_kopia[x+i][y-i][0]==zolty)) a++;
					}
					if(licznik_zoltych>1)a++;
				    if(a<1)
						return 1;
				}
				if(wektor_x>1 && wektor_y>1){  //wektor PD niebieskie damy
					int x=pionek->pozycjax;
					int y=pionek->pozycjay;
					int a=0;
					int przemieszczenie=wektor_x;
					for(int i=1;i<3;i++){
						if(x+i<8 && y+i<8) if(plansza_kopia[x+i][y+i][0]==niebieski) a++;
					}
					int licznik_zoltych=0;
					for(int i=1;i<przemieszczenie;i++){if(x+i<8 && y+i<8)if(plansza_kopia[x+i][y+i][0]==zolty)licznik_zoltych++;}
					for(int i=1;i<przemieszczenie;i++){if(x+i<8 && y+i<8)if(plansza_kopia[x+i][y+i][0]==niebieski)a++;}
					if(x+przemieszczenie<8 && y+przemieszczenie<8)if(plansza_kopia[x+przemieszczenie-1][y+przemieszczenie-1][0]==0)a++;
					for(int i=1;i<przemieszczenie;i++){
						if(x>5)a++;
						if(y>5)a++;
						if(x+i<8 && y+i<8)if(i>1 && plansza_kopia[x+i-1][y+i-1][0]==zolty && plansza_kopia[x+i][y+i][0]==0) break;
						if(x+i<8 && y+i<8)if((x+i==7 || y+i==7) && (plansza_kopia[x+i][y+i][0]==0 ||plansza_kopia[x+i][y+i][0]==zolty)) a++;
					}
					if(licznik_zoltych>1)a++;
				    if(a<1)
						return 1;
				}
				if(wektor_x<-1 && wektor_y<-1) { //wektor LG
					int x=pionek->pozycjax;
					int y=pionek->pozycjay;
					int a=0;
					int przemieszczenie = -1*wektor_x;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y-i>-1) if(plansza_kopia[x-i][y-i][0]==niebieski) a++;
					}
					int licznik_zoltych=0;
					for(int i=1;i<przemieszczenie;i++){if(x-i>-1 && y-i>-1)if(plansza_kopia[x-i][y-i][0]==zolty)licznik_zoltych++;}
					for(int i=1;i<przemieszczenie;i++){if(x-i>-1 && y-i>-1)if(plansza_kopia[x-i][y-i][0]==niebieski)a++;}
					if(x-przemieszczenie>-1 && y-przemieszczenie>-1)if(plansza_kopia[x-przemieszczenie+1][y-przemieszczenie+1][0]==0)a++;
					for(int i=1;i<przemieszczenie;i++){
						if(x<2)a++;
						if(y<2)a++;
						if(x-i>-1 && y-i>-1)if(i>1 && plansza_kopia[x-i+1][y-i+1][0]==zolty && plansza_kopia[x-i][y-i][0]==0) break;
						if(x-i>-1 && y-i>-1)if((x-i==0 || y-1==0) && (plansza_kopia[x-i][y-i][0]==0 ||plansza_kopia[x-i][y-i][0]==zolty)) a++;
					}
					if(licznik_zoltych>1)a++;
				    if(a<1)
						return 1;
				}
				if(wektor_x<-1 && wektor_y>1) { //wektor LD
					int x=pionek->pozycjax;
					int y=pionek->pozycjay;
					int a=0;
					int przemieszczenie=-1*wektor_x;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y+i<8) if(plansza_kopia[x-i][y+i][0]==niebieski) a++;
					}
					int licznik_zoltych=0;
					for(int i=1;i<przemieszczenie;i++){if(x-i>-1 && y+i<8)if(plansza_kopia[x-i][y+i][0]==zolty)licznik_zoltych++;}
					for(int i=1;i<przemieszczenie;i++){if(x-i>-1 && y+i<8)if(plansza_kopia[x-i][y+i][0]==niebieski)a++;}
					if(x-przemieszczenie>-1 && y+przemieszczenie<8)if(plansza_kopia[x-przemieszczenie+1][y+przemieszczenie-1][0]==0)a++;
					for(int i=1;i<przemieszczenie;i++){
						if(x<2)a++;
						if(y>5)a++;
						if(x-i>-1 && y+i<8)if(i>1 && plansza_kopia[x-i+1][y+i-1][0]==zolty && plansza_kopia[x-i][y+i][0]==0) break;
						if(x-i>-1 && y+i<8)if((x-i==0 || y+i==8) && (plansza_kopia[x-i][y+i][0]==0 ||plansza_kopia[x-i][y+i][0]==zolty)) a++;
					}
					if(licznik_zoltych>1)a++;
				    if(a<1)
						return 1;
				}
			}
	return 0;
	}
}
int Gra::wektor_ruchu_x(Pionek* pionek,int nowe_x){
	int zwroc=0;
	zwroc=(nowe_x-pionek->pozycjax);
	return zwroc;
}
int Gra::wektor_ruchu_y(Pionek* pionek,int nowe_y){
	int zwroc=0;
	zwroc=(nowe_y-pionek->pozycjay);
	return zwroc;
}
int Gra::zaznaczbicie(e_kolor k1, Gracz* zolt ,Gracz* nieb,int (*plansza_kopia)[8][8][2],ruchy (*tabela_ruchy)[1000]) // wprowadza bicia do tabeli tabela_ruchy
{
	int licznik_bic=0;
	if (k1 == zolty) { //dla pionkow
		for (int n = 0; n < 12; n++) {
			for (int m = 0; m < 12; m++) {
				if ((*zolt).P[n].dama==0 && (*zolt).P[n].pozycjax == (*nieb).P[m].pozycjax + 1 && (*zolt).P[n].pozycjay == (*nieb).P[m].pozycjay + 1 && (*zolt).P[n].zycie == 1 && (*nieb).P[m].zycie == 1) {  //ruch żółtych LG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if ((*zolt).P[n].pozycjax == (*zolt).P[p].pozycjax + 2 && (*zolt).P[n].pozycjay == (*zolt).P[p].pozycjay + 2
							&& (*zolt).P[n].zycie == 1 && (*zolt).P[p].zycie == 1
							&& -1<(*zolt).P[p].pozycjax + 2<8 && -1<(*zolt).P[p].pozycjay + 2<8) 
							a++;
						if ((*zolt).P[n].pozycjax == (*nieb).P[p].pozycjax + 2 && (*zolt).P[n].pozycjay == (*nieb).P[p].pozycjay + 2
							&& (*zolt).P[n].zycie == 1 && (*nieb).P[p].zycie == 1
							&& -1<(*nieb).P[p].pozycjax + 2<8 && -1<(*nieb).P[p].pozycjay + 2<8)
							a++;
						if ((*zolt).P[n].pozycjax==1)a++;   //brak spełnienia powyższych warunków gdyż pionek dla pozycji x==1 przesuniety o lewo o 2 nie istnieje
						if ((*zolt).P[n].pozycjay==1)a++;
					}
					if (a<1) {(*tabela_ruchy)[licznik_bic].wskaznik_pionek=&((*zolt).P[n]); (*tabela_ruchy)[licznik_bic].nowa_x=(*zolt).P[n].pozycjax - 2; (*tabela_ruchy)[licznik_bic].nowa_y=(*zolt).P[n].pozycjay - 2; (*tabela_ruchy)[licznik_bic].bicie=1; licznik_bic++; }
				}
				if ((*zolt).P[n].dama==0 && (*zolt).P[n].pozycjax == (*nieb).P[m].pozycjax + 1 && (*zolt).P[n].pozycjay == (*nieb).P[m].pozycjay - 1 && (*zolt).P[n].zycie == 1 && (*nieb).P[m].zycie == 1) {  //ruch żółtych LD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if ((*zolt).P[n].pozycjax == (*zolt).P[p].pozycjax + 2 && (*zolt).P[n].pozycjay == (*zolt).P[p].pozycjay - 2
							&& (*zolt).P[n].zycie == 1 && (*zolt).P[p].zycie == 1
							&& -1<(*zolt).P[p].pozycjax + 2<8 && -1<(*zolt).P[p].pozycjay - 2<8) 
							a++;
						if ((*zolt).P[n].pozycjax == (*nieb).P[p].pozycjax + 2 && (*zolt).P[n].pozycjay == (*nieb).P[p].pozycjay - 2
							&& (*zolt).P[n].zycie == 1 && (*nieb).P[p].zycie == 1
							&& -1<(*nieb).P[p].pozycjax + 2<8 && -1<(*nieb).P[p].pozycjay - 2<8)
							a++;
						if ((*zolt).P[n].pozycjay==6)a++;
						if ((*zolt).P[n].pozycjax==1)a++;
					}
					if (a<1) {(*tabela_ruchy)[licznik_bic].wskaznik_pionek=&((*zolt).P[n]); (*tabela_ruchy)[licznik_bic].nowa_x=(*zolt).P[n].pozycjax - 2; (*tabela_ruchy)[licznik_bic].nowa_y=(*zolt).P[n].pozycjay + 2; (*tabela_ruchy)[licznik_bic].bicie=1; licznik_bic++; }
				} 
				if ((*zolt).P[n].dama==0 && (*zolt).P[n].pozycjax == (*nieb).P[m].pozycjax - 1 && (*zolt).P[n].pozycjay == (*nieb).P[m].pozycjay + 1 && (*zolt).P[n].zycie == 1 && (*nieb).P[m].zycie == 1) {  //ruch żółtych PG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if ((*zolt).P[n].pozycjax == (*zolt).P[p].pozycjax - 2 && (*zolt).P[n].pozycjay == (*zolt).P[p].pozycjay + 2
							&& (*zolt).P[n].zycie == 1 && (*zolt).P[p].zycie == 1
							&& -1<(*zolt).P[p].pozycjax - 2<8 && -1<(*zolt).P[p].pozycjay + 2<8)
							a++;
						if ((*zolt).P[n].pozycjax == (*nieb).P[p].pozycjax - 2 && (*zolt).P[n].pozycjay == (*nieb).P[p].pozycjay + 2
							&& (*zolt).P[n].zycie == 1 && (*nieb).P[p].zycie == 1
							&& -1<(*nieb).P[p].pozycjax - 2<8 && -1<(*nieb).P[p].pozycjay + 2<8)
							a++;
						if ((*zolt).P[n].pozycjay==1) a++;
					}
					if (a<1) {(*tabela_ruchy)[licznik_bic].wskaznik_pionek=&((*zolt).P[n]); (*tabela_ruchy)[licznik_bic].nowa_x=(*zolt).P[n].pozycjax + 2; (*tabela_ruchy)[licznik_bic].nowa_y=(*zolt).P[n].pozycjay - 2; (*tabela_ruchy)[licznik_bic].bicie=1;licznik_bic++;  }
				} 
				if((*zolt).P[n].dama==0 && (*zolt).P[n].pozycjax == (*nieb).P[m].pozycjax - 1 && (*zolt).P[n].pozycjay == (*nieb).P[m].pozycjay - 1 && (*zolt).P[n].zycie == 1 && (*nieb).P[m].zycie == 1) {  //ruch żółtych PD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if ((*zolt).P[n].pozycjax == (*zolt).P[p].pozycjax - 2 && (*zolt).P[n].pozycjay == (*zolt).P[p].pozycjay - 2
							&& (*zolt).P[n].zycie == 1 && (*zolt).P[p].zycie == 1
							&& -1<(*zolt).P[p].pozycjax - 2<8 && -1<(*zolt).P[p].pozycjay - 2<8)
							a++;
						if ((*zolt).P[n].pozycjax == (*nieb).P[p].pozycjax - 2 && (*zolt).P[n].pozycjay == (*nieb).P[p].pozycjay - 2
							&& (*zolt).P[n].zycie == 1 && (*nieb).P[p].zycie == 1
							&& -1<(*nieb).P[p].pozycjax - 2<8 && -1<(*nieb).P[p].pozycjay - 2<8)
							a++;
						if ((*zolt).P[n].pozycjax==6)a++;
						if ((*zolt).P[n].pozycjay==6)a++;
					}
					if (a<1) {(*tabela_ruchy)[licznik_bic].wskaznik_pionek=&((*zolt).P[n]); (*tabela_ruchy)[licznik_bic].nowa_x=(*zolt).P[n].pozycjax + 2; (*tabela_ruchy)[licznik_bic].nowa_y=(*zolt).P[n].pozycjay + 2; (*tabela_ruchy)[licznik_bic].bicie=1;licznik_bic++;  }
				}
			}

		}
		//zolte damy
		for(int x=0;x<8;x++){
			for(int y=0;y<8;y++){ 
				//wektor PG
				if((*plansza_kopia)[x][y][0]==zolty &&(*plansza_kopia)[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y-i>-1) if((*plansza_kopia)[x+i][y-i][0]==zolty) a++;
					}
				    int nowex=0;
					int nowey=0;
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y<2)a++;
						if(x+i<8 && y-i>-1)if((*plansza_kopia)[x+i-1][y-i+1][0]==niebieski && (*plansza_kopia)[x+i][y-i][0]==niebieski)a++;
						if(x+i<8 && y-i>-1)if((*plansza_kopia)[x+i][y-i][0]==zolty)a++;
						if(x+i<8 && y-i>-1)if(i>1 && (*plansza_kopia)[x+i-1][y-i+1][0]==niebieski && (*plansza_kopia)[x+i][y-i][0]==0){nowex=x+i; nowey=y-i; break;}
						if(x+i<8 && y-i>-1)if((x+i==7 || y-i==0) && ((*plansza_kopia)[x+i][y-i][0]==0 ||(*plansza_kopia)[x+i][y-i][0]==niebieski)) a++;
					}
				    if(a<1)
					{ 
							(*tabela_ruchy)[licznik_bic].wskaznik_pionek=wskaznik_plansza(x,y,zolt,nieb); (*tabela_ruchy)[licznik_bic].nowa_x=nowex; (*tabela_ruchy)[licznik_bic].nowa_y=nowey; (*tabela_ruchy)[licznik_bic].bicie=1;licznik_bic++;
					}
					
				}
				 //wektor PD
				if((*plansza_kopia)[x][y][0]==zolty &&(*plansza_kopia)[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y+i<8) if((*plansza_kopia)[x+i][y+i][0]==zolty) a++;
					}
					int nowex=0;
					int nowey=0;
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y>5)a++;
						if(x+i<8 && y+i<8)if((*plansza_kopia)[x+i-1][y+i-1][0]==niebieski && (*plansza_kopia)[x+i][y+i][0]==niebieski)a++;
						if(x+i<8 && y+i<8)if((*plansza_kopia)[x+i][y+i][0]==zolty)a++;
						if(x+i<8 && y+i<8)if(i>1 && (*plansza_kopia)[x+i-1][y+i-1][0]==niebieski && (*plansza_kopia)[x+i][y+i][0]==0) {nowex=x+i; nowey=y+i;break;}
						if(x+i<8 && y+i<8)if((x+i==7 || y+i==7) && ((*plansza_kopia)[x+i][y+i][0]==0 ||(*plansza_kopia)[x+i][y+i][0]==niebieski)) a++;
					}
				    if(a<1)
						{ (*tabela_ruchy)[licznik_bic].wskaznik_pionek=wskaznik_plansza(x,y,zolt,nieb); (*tabela_ruchy)[licznik_bic].nowa_x=nowex; (*tabela_ruchy)[licznik_bic].nowa_y=nowey; (*tabela_ruchy)[licznik_bic].bicie=1;licznik_bic++; }
				}
				//wektor LG
				if((*plansza_kopia)[x][y][0]==zolty &&(*plansza_kopia)[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y-i>-1) if((*plansza_kopia)[x+i][y-i][0]==zolty) a++;
					}
					int nowex=0;
					int nowey=0;
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y<2)a++;
						if(x-i>-1 && y-i>-1)if((*plansza_kopia)[x-i+1][y-i+1][0]==niebieski && (*plansza_kopia)[x-i][y-i][0]==niebieski)a++;
						if(x-i>-1 && y-i>-1)if((*plansza_kopia)[x-i][y-i][0]==zolty)a++;
						if(x-i>-1 && y-i>-1)if(i>1 && (*plansza_kopia)[x-i+1][y-i+1][0]==niebieski && (*plansza_kopia)[x-i][y-i][0]==0){nowex=x-i; nowey=y-i; break;}
						if(x-i>-1 && y-i>-1)if((x-i==0 || y-i==0) && ((*plansza_kopia)[x-i][y-i][0]==0 ||(*plansza_kopia)[x-i][y-i][0]==niebieski)) a++;
					}
				    if(a<1)
						{ (*tabela_ruchy)[licznik_bic].wskaznik_pionek=wskaznik_plansza(x,y,zolt,nieb); (*tabela_ruchy)[licznik_bic].nowa_x=nowex; (*tabela_ruchy)[licznik_bic].nowa_y=nowey; (*tabela_ruchy)[licznik_bic].bicie=1;licznik_bic++; }
				}
				//wektor LD
				if((*plansza_kopia)[x][y][0]==zolty &&(*plansza_kopia)[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y+i<8) if((*plansza_kopia)[x+i][y+i][0]==zolty) a++;
					}
					int nowex=0;
					int nowey=0;
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y>5)a++;
						if(x-i>-1 && y+i<8)if((*plansza_kopia)[x-i+1][y+i-1][0]==niebieski && (*plansza_kopia)[x-i][y+i][0]==niebieski)a++;
						if(x-i>-1 && y+i<8)if((*plansza_kopia)[x-i][y+i][0]==zolty)a++;
						if(x-i>-1 && y+i<8)if(i>1 && (*plansza_kopia)[x-i+1][y+i-1][0]==niebieski && (*plansza_kopia)[x-i][y+i][0]==0){nowex=x-i; nowey=y+i; break;}
						if(x-i>-1 && y+i<8)if((x-i==0 || y+i==7) && ((*plansza_kopia)[x-i][y+i][0]==0 ||(*plansza_kopia)[x-i][y+i][0]==niebieski)) a++;
					}
				    if(a<1)
						{ (*tabela_ruchy)[licznik_bic].wskaznik_pionek=wskaznik_plansza(x,y,zolt,nieb); (*tabela_ruchy)[licznik_bic].nowa_x=nowex; (*tabela_ruchy)[licznik_bic].nowa_y=nowey; (*tabela_ruchy)[licznik_bic].bicie=1;licznik_bic++; }
				}
			}
		}
		return licznik_bic;
	}
	if (k1 == niebieski) { //dla pionkow
		for (int n = 0; n < 12; n++) {
			for (int m = 0; m < 12; m++) {
				if ((*nieb).P[n].dama==0 && (*nieb).P[n].pozycjax == (*zolt).P[m].pozycjax + 1 && (*nieb).P[n].pozycjay == (*zolt).P[m].pozycjay + 1 && (*nieb).P[n].zycie == 1 && (*zolt).P[m].zycie == 1) {  //ruch (*nieb)ieskich LG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if ((*nieb).P[n].pozycjax == (*zolt).P[p].pozycjax + 2 && (*nieb).P[n].pozycjay == (*zolt).P[p].pozycjay + 2
							&& (*nieb).P[n].zycie == 1 && (*zolt).P[p].zycie == 1
							&& -1<(*zolt).P[p].pozycjax + 2<8 && -1<(*zolt).P[p].pozycjay + 2<8)
							a++;
						if ((*nieb).P[n].pozycjax == (*nieb).P[p].pozycjax + 2 && (*nieb).P[n].pozycjay == (*nieb).P[p].pozycjay + 2
							&& (*nieb).P[n].zycie == 1 && (*nieb).P[p].zycie == 1
							&& -1<(*nieb).P[p].pozycjax + 2<8 && -1<(*nieb).P[p].pozycjay + 2<8) 
							a++;
						if ((*nieb).P[n].pozycjax==1)a++;
						if ((*nieb).P[n].pozycjay==1)a++;
					}
					if (a<1) { (*tabela_ruchy)[licznik_bic].wskaznik_pionek=&((*nieb).P[n]); (*tabela_ruchy)[licznik_bic].nowa_x=(*nieb).P[n].pozycjax - 2; (*tabela_ruchy)[licznik_bic].nowa_y=(*nieb).P[n].pozycjay - 2; (*tabela_ruchy)[licznik_bic].bicie=1; licznik_bic++; }
				}
				if ((*nieb).P[n].dama==0 && (*nieb).P[n].pozycjax == (*zolt).P[m].pozycjax + 1 && (*nieb).P[n].pozycjay == (*zolt).P[m].pozycjay - 1 && (*zolt).P[m].zycie == 1 && (*nieb).P[n].zycie == 1) { //ruch (*nieb)ieskich LD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if ((*nieb).P[n].pozycjax == (*zolt).P[p].pozycjax + 2 && (*nieb).P[n].pozycjay == (*zolt).P[p].pozycjay - 2
							&& (*nieb).P[n].zycie == 1 && (*zolt).P[p].zycie == 1
							&& -1<(*zolt).P[p].pozycjax + 2<8 && -1<(*zolt).P[p].pozycjay - 2<8) a++;
						if ((*nieb).P[n].pozycjax == (*nieb).P[p].pozycjax + 2 && (*nieb).P[n].pozycjay == (*nieb).P[p].pozycjay - 2
							&& (*nieb).P[n].zycie == 1 && (*nieb).P[p].zycie == 1
							&& -1<(*nieb).P[p].pozycjax + 2<8 && -1<(*nieb).P[p].pozycjay - 2<8) a++;
						if((*nieb).P[n].pozycjax==1)a++;
						if((*nieb).P[n].pozycjay==6)a++;
					}
					if (a<1) {(*tabela_ruchy)[licznik_bic].wskaznik_pionek=&((*nieb).P[n]); (*tabela_ruchy)[licznik_bic].nowa_x=(*nieb).P[n].pozycjax - 2; (*tabela_ruchy)[licznik_bic].nowa_y=(*nieb).P[n].pozycjay + 2; (*tabela_ruchy)[licznik_bic].bicie=1;licznik_bic++;  }
				}
				if ((*nieb).P[n].dama==0 && (*nieb).P[n].pozycjax == (*zolt).P[m].pozycjax - 1 && (*nieb).P[n].pozycjay == (*zolt).P[m].pozycjay + 1 && (*zolt).P[m].zycie == 1 && (*nieb).P[n].zycie == 1) {  //ruch (*nieb)ieskich PG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if ((*nieb).P[n].pozycjax == (*zolt).P[p].pozycjax - 2 && (*nieb).P[n].pozycjay == (*zolt).P[p].pozycjay + 2
							&& (*nieb).P[n].zycie == 1 && (*zolt).P[p].zycie == 1
							&& -1<(*zolt).P[p].pozycjax - 2<8 && -1<(*zolt).P[p].pozycjay + 2<8) a++;
						if ((*nieb).P[n].pozycjax == (*nieb).P[p].pozycjax - 2 && (*nieb).P[n].pozycjay == (*nieb).P[p].pozycjay + 2
							&& (*nieb).P[n].zycie == 1 && (*nieb).P[p].zycie == 1
							&& -1<(*nieb).P[p].pozycjax - 2<8 && -1<(*nieb).P[p].pozycjay + 2<8) a++;
						if ((*nieb).P[n].pozycjax==6)a++;
						if ((*nieb).P[n].pozycjay==1)a++;
					}
					if (a<1)  { (*tabela_ruchy)[licznik_bic].wskaznik_pionek=&((*nieb).P[n]); (*tabela_ruchy)[licznik_bic].nowa_x=(*nieb).P[n].pozycjax + 2; (*tabela_ruchy)[licznik_bic].nowa_y=(*nieb).P[n].pozycjay - 2; (*tabela_ruchy)[licznik_bic].bicie=1;licznik_bic++; }
				}
				if ((*nieb).P[n].dama==0 && (*nieb).P[n].pozycjax == (*zolt).P[m].pozycjax - 1 && (*nieb).P[n].pozycjay == (*zolt).P[m].pozycjay - 1 && (*nieb).P[n].zycie == 1 && (*zolt).P[m].zycie == 1) {  //ruch niebieskich PD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if ((*nieb).P[n].pozycjax == (*zolt).P[p].pozycjax - 2 && (*nieb).P[n].pozycjay == (*zolt).P[p].pozycjay - 2
							&& (*nieb).P[n].zycie == 1 && (*zolt).P[p].zycie == 1
							&& -1<(*zolt).P[p].pozycjax - 2<8 && -1<(*zolt).P[p].pozycjay - 2<8 ) a++;
						if ((*nieb).P[n].pozycjax == (*nieb).P[p].pozycjax - 2 && (*nieb).P[n].pozycjay == (*nieb).P[p].pozycjay - 2
							&& (*nieb).P[n].zycie == 1 && (*nieb).P[p].zycie == 1
							&& -1<(*nieb).P[p].pozycjax - 2<8 && -1<(*nieb).P[p].pozycjay - 2<8) a++;
						if((*nieb).P[n].pozycjay==6)a++;
						if((*nieb).P[n].pozycjax==6)a++;
					}
					if (a<1) {(*tabela_ruchy)[licznik_bic].wskaznik_pionek=&((*nieb).P[n]); (*tabela_ruchy)[licznik_bic].nowa_x=(*nieb).P[n].pozycjax + 2; (*tabela_ruchy)[licznik_bic].nowa_y=(*nieb).P[n].pozycjay + 2; (*tabela_ruchy)[licznik_bic].bicie=1;licznik_bic++;  }
				}
			}

		}
			//(*nieb)ieskie damy
		for(int x=0;x<8;x++){
			for(int y=0;y<8;y++){ 
				//wektor PG
				if((*plansza_kopia)[x][y][0]==niebieski &&(*plansza_kopia)[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y-i>-1) if((*plansza_kopia)[x+i][y-i][0]==niebieski) a++;
					}
					int nowex=0;
					int nowey=0;
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y<2)a++;
						if(x+i<8 && y-i>-1)if((*plansza_kopia)[x+i-1][y-i+1][0]==zolty && (*plansza_kopia)[x+i][y-i][0]==zolty)a++;
						if(x+i<8 && y-i>-1)if((*plansza_kopia)[x+i][y-i][0]==niebieski)a++;
						if(x+i<8 && y-i>-1)if(i>1 && (*plansza_kopia)[x+i-1][y-i+1][0]==zolty && (*plansza_kopia)[x+i][y-i][0]==0) {nowex=x+i; nowey=y-i; break;}
						if(x+i<8 && y-i>-1)if((x+i==7 || y-i==0) && ((*plansza_kopia)[x+i][y-i][0]==0 ||(*plansza_kopia)[x+i][y-i][0]==zolty)) a++;
					}
				    if(a<1)
						{ (*tabela_ruchy)[licznik_bic].wskaznik_pionek=wskaznik_plansza(x,y,zolt,nieb); (*tabela_ruchy)[licznik_bic].nowa_x=nowex; (*tabela_ruchy)[licznik_bic].nowa_y=nowey; (*tabela_ruchy)[licznik_bic].bicie=1;licznik_bic++; }
				}
				 //wektor PD
				if((*plansza_kopia)[x][y][0]==niebieski &&(*plansza_kopia)[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y+i<8) if((*plansza_kopia)[x+i][y+i][0]==niebieski) a++;
					}
					int nowex=0;
					int nowey=0;
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y>5)a++;
						if(x+i<8 && y+i<8)if((*plansza_kopia)[x+i-1][y+i-1][0]==zolty && (*plansza_kopia)[x+i][y+i][0]==zolty)a++;
						if(x+i<8 && y+i<8)if((*plansza_kopia)[x+i][y+i][0]==niebieski)a++;
						if(x+i<8 && y+i<8)if(i>1 && (*plansza_kopia)[x+i-1][y+i-1][0]==zolty && (*plansza_kopia)[x+i][y+i][0]==0) {nowex=x+i; nowey=y+i; break;}
						if(x+i<8 && y+i<8)if((x+i==7 || y+i==7) && ((*plansza_kopia)[x+i][y+i][0]==0 ||(*plansza_kopia)[x+i][y+i][0]==zolty)) a++;
					}
				    if(a<1)
						{ (*tabela_ruchy)[licznik_bic].wskaznik_pionek=wskaznik_plansza(x,y,zolt,nieb); (*tabela_ruchy)[licznik_bic].nowa_x=nowex; (*tabela_ruchy)[licznik_bic].nowa_y=nowey; (*tabela_ruchy)[licznik_bic].bicie=1;licznik_bic++; }
				}
				//wektor LG
				if((*plansza_kopia)[x][y][0]==niebieski &&(*plansza_kopia)[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y-i>-1) if((*plansza_kopia)[x+i][y-i][0]==niebieski) a++;
					}
					int nowex=0;
					int nowey=0;
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y<2)a++;
						if(x-i>-1 && y-i>-1)if((*plansza_kopia)[x-i+1][y-i+1][0]==zolty && (*plansza_kopia)[x-i][y-i][0]==zolty)a++;
						if(x-i>-1 && y-i>-1)if((*plansza_kopia)[x-i][y-i][0]==niebieski)a++;
						if(x-i>-1 && y-i>-1)if(i>1 && (*plansza_kopia)[x-i+1][y-i+1][0]==zolty && (*plansza_kopia)[x-i][y-i][0]==0){nowex=x-i; nowey=y-i; break;}
						if(x-i>-1 && y-i>-1)if((x-i==0 || y-i==0) && ((*plansza_kopia)[x-i][y-i][0]==0 ||(*plansza_kopia)[x-i][y-i][0]==zolty)) a++;
					}
				    if(a<1)
						{ (*tabela_ruchy)[licznik_bic].wskaznik_pionek=wskaznik_plansza(x,y,zolt,nieb); (*tabela_ruchy)[licznik_bic].nowa_x=nowex; (*tabela_ruchy)[licznik_bic].nowa_y=nowey; (*tabela_ruchy)[licznik_bic].bicie=1;licznik_bic++; }
				}
				//wektor LD
				if((*plansza_kopia)[x][y][0]==niebieski &&(*plansza_kopia)[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y+i<8) if((*plansza_kopia)[x+i][y+i][0]==niebieski) a++;
					}
					int nowex=0;
					int nowey=0;
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y>5)a++;
						if(x-i>-1 && y+i<8)if((*plansza_kopia)[x-i+1][y+i-1][0]==zolty && (*plansza_kopia)[x-i][y+i][0]==zolty)a++;
						if(x-i>-1 && y+i<8)if((*plansza_kopia)[x-i][y+i][0]==niebieski)a++;
						if(x-i>-1 && y+i<8)if(i>1 && (*plansza_kopia)[x-i+1][y+i-1][0]==zolty && (*plansza_kopia)[x-i][y+i][0]==0) {nowex=x-i; nowey=y+i; break;}
						if(x-i>-1 && y+i<8)if((x-i==0 || y+i==7) && ((*plansza_kopia)[x-i][y+i][0]==0 ||(*plansza_kopia)[x-i][y+i][0]==zolty)) a++;
					}
				    if(a<1)
						{ (*tabela_ruchy)[licznik_bic].wskaznik_pionek=wskaznik_plansza(x,y,zolt,nieb); (*tabela_ruchy)[licznik_bic].nowa_x=nowex; (*tabela_ruchy)[licznik_bic].nowa_y=nowey; (*tabela_ruchy)[licznik_bic].bicie=1;licznik_bic++; }
				}
			}
		}
		return licznik_bic;
	}
}
int Gra::zaznaczbicie_pionka(ruchy* ruch,nowepozycje (*wskazniki)[1200],Gracz* zolt ,Gracz* nieb) // wprowadza bicia do tabeli tabela_ruchy
{
	e_kolor k1=ruch->wskaznik_pionek->kolor;
	int (*plansza_kopia)[8][8][2];
	int plansza[8][8][2];
	aktualizuj_plansza_pokaz(zolt,nieb,plansza);
	plansza_kopia=&plansza;
	int licznik_bic=0;
	if (k1 == zolty) { //dla pionkow
		int n=-1;
		for (int i = 0; i < 12; i++) {
			if(&((*zolt).P[i]) == (ruch->wskaznik_pionek)) n=i;
		}
		if(n!=-1){
			for (int m = 0; m < 12; m++) {
				if ((*zolt).P[n].dama==0 && (*zolt).P[n].pozycjax == (*nieb).P[m].pozycjax + 1 && (*zolt).P[n].pozycjay == (*nieb).P[m].pozycjay + 1 && (*zolt).P[n].zycie == 1 && (*nieb).P[m].zycie == 1) {  //ruch żółtych LG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if ((*zolt).P[n].pozycjax == (*zolt).P[p].pozycjax + 2 && (*zolt).P[n].pozycjay == (*zolt).P[p].pozycjay + 2
							&& (*zolt).P[n].zycie == 1 && (*zolt).P[p].zycie == 1
							&& -1<(*zolt).P[p].pozycjax + 2<8 && -1<(*zolt).P[p].pozycjay + 2<8) 
							a++;
						if ((*zolt).P[n].pozycjax == (*nieb).P[p].pozycjax + 2 && (*zolt).P[n].pozycjay == (*nieb).P[p].pozycjay + 2
							&& (*zolt).P[n].zycie == 1 && (*nieb).P[p].zycie == 1
							&& -1<(*nieb).P[p].pozycjax + 2<8 && -1<(*nieb).P[p].pozycjay + 2<8)
							a++;
						if ((*zolt).P[n].pozycjax==1)a++;   //brak spełnienia powyższych warunków gdyż pionek dla pozycji x==1 przesuniety o lewo o 2 nie istnieje
						if ((*zolt).P[n].pozycjay==1)a++;
					}
					if (a<1)  {
						wskazniki[0]->nowa_x=(*zolt).P[n].pozycjax - 2; wskazniki[0]->nowa_y=(*zolt).P[n].pozycjay - 2; licznik_bic++;
						int fff=66;
					}
				}
				if ((*zolt).P[n].dama==0 && (*zolt).P[n].pozycjax == (*nieb).P[m].pozycjax + 1 && (*zolt).P[n].pozycjay == (*nieb).P[m].pozycjay - 1 && (*zolt).P[n].zycie == 1 && (*nieb).P[m].zycie == 1) {  //ruch żółtych LD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if ((*zolt).P[n].pozycjax == (*zolt).P[p].pozycjax + 2 && (*zolt).P[n].pozycjay == (*zolt).P[p].pozycjay - 2
							&& (*zolt).P[n].zycie == 1 && (*zolt).P[p].zycie == 1
							&& -1<(*zolt).P[p].pozycjax + 2<8 && -1<(*zolt).P[p].pozycjay - 2<8) 
							a++;
						if ((*zolt).P[n].pozycjax == (*nieb).P[p].pozycjax + 2 && (*zolt).P[n].pozycjay == (*nieb).P[p].pozycjay - 2
							&& (*zolt).P[n].zycie == 1 && (*nieb).P[p].zycie == 1
							&& -1<(*nieb).P[p].pozycjax + 2<8 && -1<(*nieb).P[p].pozycjay - 2<8)
							a++;
						if ((*zolt).P[n].pozycjay==6)a++;
						if ((*zolt).P[n].pozycjax==1)a++;
					}
					if (a<1) {
						wskazniki[0]->nowa_x=(*zolt).P[n].pozycjax - 2; wskazniki[0]->nowa_y=(*zolt).P[n].pozycjay + 2; licznik_bic++; 
						int fff=55;
					}
				} 
				if ((*zolt).P[n].dama==0 && (*zolt).P[n].pozycjax == (*nieb).P[m].pozycjax - 1 && (*zolt).P[n].pozycjay == (*nieb).P[m].pozycjay + 1 && (*zolt).P[n].zycie == 1 && (*nieb).P[m].zycie == 1) {  //ruch żółtych PG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if ((*zolt).P[n].pozycjax == (*zolt).P[p].pozycjax - 2 && (*zolt).P[n].pozycjay == (*zolt).P[p].pozycjay + 2
							&& (*zolt).P[n].zycie == 1 && (*zolt).P[p].zycie == 1
							&& -1<(*zolt).P[p].pozycjax - 2<8 && -1<(*zolt).P[p].pozycjay + 2<8)
							a++;
						if ((*zolt).P[n].pozycjax == (*nieb).P[p].pozycjax - 2 && (*zolt).P[n].pozycjay == (*nieb).P[p].pozycjay + 2
							&& (*zolt).P[n].zycie == 1 && (*nieb).P[p].zycie == 1
							&& -1<(*nieb).P[p].pozycjax - 2<8 && -1<(*nieb).P[p].pozycjay + 2<8)
							a++;
						if ((*zolt).P[n].pozycjax==6) a++;
						if ((*zolt).P[n].pozycjay==1) a++;
					}
					if (a<1) {
						wskazniki[0]->nowa_x=(*zolt).P[n].pozycjax + 2; wskazniki[0]->nowa_y=(*zolt).P[n].pozycjay - 2; licznik_bic++;
						int fff=661;
					}
				} 
				if((*zolt).P[n].dama==0 && (*zolt).P[n].pozycjax == (*nieb).P[m].pozycjax - 1 && (*zolt).P[n].pozycjay == (*nieb).P[m].pozycjay - 1 && (*zolt).P[n].zycie == 1 && (*nieb).P[m].zycie == 1) {  //ruch żółtych PD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if ((*zolt).P[n].pozycjax == (*zolt).P[p].pozycjax - 2 && (*zolt).P[n].pozycjay == (*zolt).P[p].pozycjay - 2
							&& (*zolt).P[n].zycie == 1 && (*zolt).P[p].zycie == 1
							&& -1<(*zolt).P[p].pozycjax - 2<8 && -1<(*zolt).P[p].pozycjay - 2<8)
							a++;
						if ((*zolt).P[n].pozycjax == (*nieb).P[p].pozycjax - 2 && (*zolt).P[n].pozycjay == (*nieb).P[p].pozycjay - 2
							&& (*zolt).P[n].zycie == 1 && (*nieb).P[p].zycie == 1
							&& -1<(*nieb).P[p].pozycjax - 2<8 && -1<(*nieb).P[p].pozycjay - 2<8)
							a++;
						if ((*zolt).P[n].pozycjax==6)a++;
						if ((*zolt).P[n].pozycjay==6)a++;
					}
					if (a<1) {
						wskazniki[0]->nowa_x=(*zolt).P[n].pozycjax + 2; wskazniki[0]->nowa_y=(*zolt).P[n].pozycjay + 2; licznik_bic++;
						int fff=5;
					}
				}
			}

		}
		//zolte damy
		for(int x=0;x<8;x++){
			for(int y=0;y<8;y++){ 
				//wektor PG
				if((*plansza_kopia)[x][y][0]==zolty &&(*plansza_kopia)[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y-i>-1) if((*plansza_kopia)[x+i][y-i][0]==zolty) a++;
					}
				    int nowex=0;
					int nowey=0;
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y<2)a++;
						if(x+i<8 && y-i>-1)if((*plansza_kopia)[x+i-1][y-i+1][0]==niebieski && (*plansza_kopia)[x+i][y-i][0]==niebieski)a++;
						if(x+i<8 && y-i>-1)if((*plansza_kopia)[x+i][y-i][0]==zolty)a++;
						if(x+i<8 && y-i>-1)if(i>1 && (*plansza_kopia)[x+i-1][y-i+1][0]==niebieski && (*plansza_kopia)[x+i][y-i][0]==0){nowex=x+i; nowey=y-i; break;}
						if(x+i<8 && y-i>-1)if((x+i==7 || y-i==0) && ((*plansza_kopia)[x+i][y-i][0]==0 ||(*plansza_kopia)[x+i][y-i][0]==niebieski)) a++;
					}
				    if(a<1)
					{ 
							{wskazniki[0]->nowa_x=nowex; wskazniki[0]->nowa_y=nowey; licznik_bic++; }
					}
					
				}
				 //wektor PD
				if((*plansza_kopia)[x][y][0]==zolty &&(*plansza_kopia)[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y+i<8) if((*plansza_kopia)[x+i][y+i][0]==zolty) a++;
					}
					int nowex=0;
					int nowey=0;
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y>5)a++;
						if(x+i<8 && y+i<8)if((*plansza_kopia)[x+i-1][y+i-1][0]==niebieski && (*plansza_kopia)[x+i][y+i][0]==niebieski)a++;
						if(x+i<8 && y+i<8)if((*plansza_kopia)[x+i][y+i][0]==zolty)a++;
						if(x+i<8 && y+i<8)if(i>1 && (*plansza_kopia)[x+i-1][y+i-1][0]==niebieski && (*plansza_kopia)[x+i][y+i][0]==0) {nowex=x+i; nowey=y+i;break;}
						if(x+i<8 && y+i<8)if((x+i==7 || y+i==7) && ((*plansza_kopia)[x+i][y+i][0]==0 ||(*plansza_kopia)[x+i][y+i][0]==niebieski)) a++;
					}
				    if(a<1)
						{wskazniki[0]->nowa_x=nowex; wskazniki[0]->nowa_y=nowey; licznik_bic++; }
				}
				//wektor LG
				if((*plansza_kopia)[x][y][0]==zolty &&(*plansza_kopia)[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y-i>-1) if((*plansza_kopia)[x+i][y-i][0]==zolty) a++;
					}
					int nowex=0;
					int nowey=0;
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y<2)a++;
						if(x-i>-1 && y-i>-1)if((*plansza_kopia)[x-i+1][y-i+1][0]==niebieski && (*plansza_kopia)[x-i][y-i][0]==niebieski)a++;
						if(x-i>-1 && y-i>-1)if((*plansza_kopia)[x-i][y-i][0]==zolty)a++;
						if(x-i>-1 && y-i>-1)if(i>1 && (*plansza_kopia)[x-i+1][y-i+1][0]==niebieski && (*plansza_kopia)[x-i][y-i][0]==0){nowex=x-i; nowey=y-i; break;}
						if(x-i>-1 && y-i>-1)if((x-i==0 || y-i==0) && ((*plansza_kopia)[x-i][y-i][0]==0 ||(*plansza_kopia)[x-i][y-i][0]==niebieski)) a++;
					}
				    if(a<1)
						{wskazniki[0]->nowa_x=nowex; wskazniki[0]->nowa_y=nowey; licznik_bic++; }
				}
				//wektor LD
				if((*plansza_kopia)[x][y][0]==zolty &&(*plansza_kopia)[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y+i<8) if((*plansza_kopia)[x+i][y+i][0]==zolty) a++;
					}
					int nowex=0;
					int nowey=0;
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y>5)a++;
						if(x-i>-1 && y+i<8)if((*plansza_kopia)[x-i+1][y+i-1][0]==niebieski && (*plansza_kopia)[x-i][y+i][0]==niebieski)a++;
						if(x-i>-1 && y+i<8)if((*plansza_kopia)[x-i][y+i][0]==zolty)a++;
						if(x-i>-1 && y+i<8)if(i>1 && (*plansza_kopia)[x-i+1][y+i-1][0]==niebieski && (*plansza_kopia)[x-i][y+i][0]==0){nowex=x-i; nowey=y+i; break;}
						if(x-i>-1 && y+i<8)if((x-i==0 || y+i==7) && ((*plansza_kopia)[x-i][y+i][0]==0 ||(*plansza_kopia)[x-i][y+i][0]==niebieski)) a++;
					}
				    if(a<1)
						{wskazniki[0]->nowa_x=nowex; wskazniki[0]->nowa_y=nowey; licznik_bic++; }
				}
			}
		}
		return licznik_bic;
	}
	if (k1 == niebieski) { //dla pionkow
		int n=-1;
		for (int i = 0; i < 12; i++) {
			if(&((*nieb).P[i]) == (ruch->wskaznik_pionek)) n=i;
		}
		if(n!=-1){
			for (int m = 0; m < 12; m++) {
				if ((*nieb).P[n].dama==0 && (*nieb).P[n].pozycjax == (*zolt).P[m].pozycjax + 1 && (*nieb).P[n].pozycjay == (*zolt).P[m].pozycjay + 1 && (*nieb).P[n].zycie == 1 && (*zolt).P[m].zycie == 1) {  //ruch (*nieb)ieskich LG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if ((*nieb).P[n].pozycjax == (*zolt).P[p].pozycjax + 2 && (*nieb).P[n].pozycjay == (*zolt).P[p].pozycjay + 2
							&& (*nieb).P[n].zycie == 1 && (*zolt).P[p].zycie == 1
							&& -1<(*zolt).P[p].pozycjax + 2<8 && -1<(*zolt).P[p].pozycjay + 2<8)
							a++;
						if ((*nieb).P[n].pozycjax == (*nieb).P[p].pozycjax + 2 && (*nieb).P[n].pozycjay == (*nieb).P[p].pozycjay + 2
							&& (*nieb).P[n].zycie == 1 && (*nieb).P[p].zycie == 1
							&& -1<(*nieb).P[p].pozycjax + 2<8 && -1<(*nieb).P[p].pozycjay + 2<8) 
							a++;
						if ((*nieb).P[n].pozycjax==1)a++;
						if ((*nieb).P[n].pozycjay==1)a++;
					}
					if (a<1) {wskazniki[0]->nowa_x=(*nieb).P[n].pozycjax - 2; wskazniki[0]->nowa_y=(*nieb).P[n].pozycjay - 2; licznik_bic++; }
				}
				if ((*nieb).P[n].dama==0 && (*nieb).P[n].pozycjax == (*zolt).P[m].pozycjax + 1 && (*nieb).P[n].pozycjay == (*zolt).P[m].pozycjay - 1 && (*zolt).P[m].zycie == 1 && (*nieb).P[n].zycie == 1) { //ruch (*nieb)ieskich LD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if ((*nieb).P[n].pozycjax == (*zolt).P[p].pozycjax + 2 && (*nieb).P[n].pozycjay == (*zolt).P[p].pozycjay - 2
							&& (*nieb).P[n].zycie == 1 && (*zolt).P[p].zycie == 1
							&& -1<(*zolt).P[p].pozycjax + 2<8 && -1<(*zolt).P[p].pozycjay - 2<8) a++;
						if ((*nieb).P[n].pozycjax == (*nieb).P[p].pozycjax + 2 && (*nieb).P[n].pozycjay == (*nieb).P[p].pozycjay - 2
							&& (*nieb).P[n].zycie == 1 && (*nieb).P[p].zycie == 1
							&& -1<(*nieb).P[p].pozycjax + 2<8 && -1<(*nieb).P[p].pozycjay - 2<8) a++;
						if((*nieb).P[n].pozycjax==1)a++;
						if((*nieb).P[n].pozycjay==6)a++;
					}
					if (a<1) {wskazniki[0]->nowa_x=(*nieb).P[n].pozycjax - 2; wskazniki[0]->nowa_y=(*nieb).P[n].pozycjay + 2; licznik_bic++; }
				}
				if ((*nieb).P[n].dama==0 && (*nieb).P[n].pozycjax == (*zolt).P[m].pozycjax - 1 && (*nieb).P[n].pozycjay == (*zolt).P[m].pozycjay + 1 && (*zolt).P[m].zycie == 1 && (*nieb).P[n].zycie == 1) {  //ruch (*nieb)ieskich PG
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if ((*nieb).P[n].pozycjax == (*zolt).P[p].pozycjax - 2 && (*nieb).P[n].pozycjay == (*zolt).P[p].pozycjay + 2
							&& (*nieb).P[n].zycie == 1 && (*zolt).P[p].zycie == 1
							&& -1<(*zolt).P[p].pozycjax - 2<8 && -1<(*zolt).P[p].pozycjay + 2<8) a++;
						if ((*nieb).P[n].pozycjax == (*nieb).P[p].pozycjax - 2 && (*nieb).P[n].pozycjay == (*nieb).P[p].pozycjay + 2
							&& (*nieb).P[n].zycie == 1 && (*nieb).P[p].zycie == 1
							&& -1<(*nieb).P[p].pozycjax - 2<8 && -1<(*nieb).P[p].pozycjay + 2<8) a++;
						if ((*nieb).P[n].pozycjax==6)a++;
						if ((*nieb).P[n].pozycjay==1)a++;
					}
					if (a<1) {wskazniki[0]->nowa_x=(*nieb).P[n].pozycjax + 2; wskazniki[0]->nowa_y=(*nieb).P[n].pozycjay - 2; licznik_bic++; }
				}
				if ((*nieb).P[n].dama==0 && (*nieb).P[n].pozycjax == (*zolt).P[m].pozycjax - 1 && (*nieb).P[n].pozycjay == (*zolt).P[m].pozycjay - 1 && (*nieb).P[n].zycie == 1 && (*zolt).P[m].zycie == 1) {  //ruch niebieskich PD
					int a = 0;//zliczająca
					for (int p = 0; p < 12; p++) {
						if ((*nieb).P[n].pozycjax == (*zolt).P[p].pozycjax - 2 && (*nieb).P[n].pozycjay == (*zolt).P[p].pozycjay - 2
							&& (*nieb).P[n].zycie == 1 && (*zolt).P[p].zycie == 1
							&& -1<(*zolt).P[p].pozycjax - 2<8 && -1<(*zolt).P[p].pozycjay - 2<8 ) a++;
						if ((*nieb).P[n].pozycjax == (*nieb).P[p].pozycjax - 2 && (*nieb).P[n].pozycjay == (*nieb).P[p].pozycjay - 2
							&& (*nieb).P[n].zycie == 1 && (*nieb).P[p].zycie == 1
							&& -1<(*nieb).P[p].pozycjax - 2<8 && -1<(*nieb).P[p].pozycjay - 2<8) a++;
						if((*nieb).P[n].pozycjay==6)a++;
						if((*nieb).P[n].pozycjax==6)a++;
					}
					if (a<1) {wskazniki[0]->nowa_x=(*nieb).P[n].pozycjax + 2; wskazniki[0]->nowa_y=(*nieb).P[n].pozycjay + 2; licznik_bic++; }
				}
			}

		}
			//niebieskie damy
		for(int x=0;x<8;x++){
			for(int y=0;y<8;y++){ 
				//wektor PG
				if((*plansza_kopia)[x][y][0]==niebieski &&(*plansza_kopia)[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y-i>-1) if((*plansza_kopia)[x+i][y-i][0]==niebieski) a++;
					}
					int nowex=0;
					int nowey=0;
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y<2)a++;
						if(x+i<8 && y-i>-1)if((*plansza_kopia)[x+i-1][y-i+1][0]==zolty && (*plansza_kopia)[x+i][y-i][0]==zolty)a++;
						if(x+i<8 && y-i>-1)if((*plansza_kopia)[x+i][y-i][0]==niebieski)a++;
						if(x+i<8 && y-i>-1)if(i>1 && (*plansza_kopia)[x+i-1][y-i+1][0]==zolty && (*plansza_kopia)[x+i][y-i][0]==0) {nowex=x+i; nowey=y-i; break;}
						if(x+i<8 && y-i>-1)if((x+i==7 || y-i==0) && ((*plansza_kopia)[x+i][y-i][0]==0 ||(*plansza_kopia)[x+i][y-i][0]==zolty)) a++;
					}
				    if(a<1)
						{wskazniki[0]->nowa_x=nowex; wskazniki[0]->nowa_y=nowey; licznik_bic++; }
				}
				 //wektor PD
				if((*plansza_kopia)[x][y][0]==niebieski &&(*plansza_kopia)[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x+i<8 && y+i<8) if((*plansza_kopia)[x+i][y+i][0]==niebieski) a++;
					}
					int nowex=0;
					int nowey=0;
					for(int i=1;i<8;i++){
						if(x>5)a++;
						if(y>5)a++;
						if(x+i<8 && y+i<8)if((*plansza_kopia)[x+i-1][y+i-1][0]==zolty && (*plansza_kopia)[x+i][y+i][0]==zolty)a++;
						if(x+i<8 && y+i<8)if((*plansza_kopia)[x+i][y+i][0]==niebieski)a++;
						if(x+i<8 && y+i<8)if(i>1 && (*plansza_kopia)[x+i-1][y+i-1][0]==zolty && (*plansza_kopia)[x+i][y+i][0]==0) {nowex=x+i; nowey=y+i; break;}
						if(x+i<8 && y+i<8)if((x+i==7 || y+i==7) && ((*plansza_kopia)[x+i][y+i][0]==0 ||(*plansza_kopia)[x+i][y+i][0]==zolty)) a++;
					}
				    if(a<1)
						{wskazniki[0]->nowa_x=nowex; wskazniki[0]->nowa_y=nowey; licznik_bic++; }
				}
				//wektor LG
				if((*plansza_kopia)[x][y][0]==niebieski &&(*plansza_kopia)[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y-i>-1) if((*plansza_kopia)[x+i][y-i][0]==niebieski) a++;
					}
					int nowex=0;
					int nowey=0;
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y<2)a++;
						if(x-i>-1 && y-i>-1)if((*plansza_kopia)[x-i+1][y-i+1][0]==zolty && (*plansza_kopia)[x-i][y-i][0]==zolty)a++;
						if(x-i>-1 && y-i>-1)if((*plansza_kopia)[x-i][y-i][0]==niebieski)a++;
						if(x-i>-1 && y-i>-1)if(i>1 && (*plansza_kopia)[x-i+1][y-i+1][0]==zolty && (*plansza_kopia)[x-i][y-i][0]==0){nowex=x-i; nowey=y-i; break;}
						if(x-i>-1 && y-i>-1)if((x-i==0 || y-i==0) && ((*plansza_kopia)[x-i][y-i][0]==0 ||(*plansza_kopia)[x-i][y-i][0]==zolty)) a++;
					}
				    if(a<1)
						{wskazniki[0]->nowa_x=nowex; wskazniki[0]->nowa_y=nowey; licznik_bic++; }
				}
				//wektor LD
				if((*plansza_kopia)[x][y][0]==niebieski &&(*plansza_kopia)[x][y][1]==dama)
				{
					int a=0;
					for(int i=1;i<3;i++){
						if(x-i>-1 && y+i<8) if((*plansza_kopia)[x+i][y+i][0]==niebieski) a++;
					}
					int nowex=0;
					int nowey=0;
					for(int i=1;i<8;i++){
						if(x<2)a++;
						if(y>5)a++;
						if(x-i>-1 && y+i<8)if((*plansza_kopia)[x-i+1][y+i-1][0]==zolty && (*plansza_kopia)[x-i][y+i][0]==zolty)a++;
						if(x-i>-1 && y+i<8)if((*plansza_kopia)[x-i][y+i][0]==niebieski)a++;
						if(x-i>-1 && y+i<8)if(i>1 && (*plansza_kopia)[x-i+1][y+i-1][0]==zolty && (*plansza_kopia)[x-i][y+i][0]==0) {nowex=x-i; nowey=y+i; break;}
						if(x-i>-1 && y+i<8)if((x-i==0 || y+i==7) && ((*plansza_kopia)[x-i][y+i][0]==0 ||(*plansza_kopia)[x-i][y+i][0]==zolty)) a++;
					}
				    if(a<1)
						{wskazniki[0]->nowa_x=nowex; wskazniki[0]->nowa_y=nowey; licznik_bic++; }
				}
			}
		}
		return licznik_bic;
	}
}
Pionek* Gra::wskaznik_plansza(int x,int y,Gracz* zolt, Gracz* nieb){
	for(int i=0;i<12;i++)
	{
		if((*zolt).P[i].pozycjax==x && (*zolt).P[i].pozycjay==y && (*zolt).P[i].zycie==1) 
			return &zolt->P[i];
 		if((*nieb).P[i].pozycjax==x && (*nieb).P[i].pozycjay==y && (*nieb).P[i].zycie==1) 
			return  &((*nieb).P[i]);
	}
	return NULL;
}
int Gra::wykonaj_ruchy_rekurencja(ruchy* dobry_ruch,e_kolor kolor,int ile_iter,Gracz zolt, Gracz nieb,int pierwsze_wywolanie)
{
	if(ile_iter>0)
	{
		ruchy tabela_ruchy_test[1000];
		int plansza[8][8][2];
		for(int x=0;x<8;x++){
			for(int y=0;y<8;y++){
				plansza[x][y][0]=0;
				plansza[x][y][1]=0;
			}
		}
		aktualizuj_plansza_pokaz(&zolt, &nieb,plansza);
		int ilosc_ruchow=zgromadz_ruchy(kolor, &zolt,&nieb,&tabela_ruchy_test);
		if(ilosc_ruchow==0 && pierwsze_wywolanie==1) return -1234567;
		for(int i=0;i<ilosc_ruchow;i++){
			int plansza_kopia[8][8][2];
			for(int x=0;x<8;x++){
				for(int y=0;y<8;y++){
					plansza_kopia[x][y][0]=0;
					plansza_kopia[x][y][1]=0;
				}
			}
			ruchy tabela_ruchy[1000];
			Gracz zolt2(zolt);
			Gracz nieb2(nieb);
			aktualizuj_damy(&zolt2, &nieb2);
			aktualizuj_plansza_pokaz(&zolt2, &nieb2, plansza_kopia);
			zgromadz_ruchy(kolor, &zolt2,&nieb2,&tabela_ruchy);
			int bedzie_bicie=0;
			if(tabela_ruchy[i].bicie==1){
				if ((tabela_ruchy[i].wskaznik_pionek->kolor==zolty && sprbicie(tabela_ruchy[i].wskaznik_pionek->kolor, zolt2,nieb2) == 1) || (tabela_ruchy[i].wskaznik_pionek->kolor==niebieski && sprbicie(tabela_ruchy[i].wskaznik_pionek->kolor, zolt2,nieb2) == 2) ) {
						if(poprawnoscbicia(tabela_ruchy[i].wskaznik_pionek,zolt2 ,nieb2,tabela_ruchy[i].nowa_x,tabela_ruchy[i].nowa_y) == 1) {
							usunpionek(tabela_ruchy[i].wskaznik_pionek, tabela_ruchy[i].nowa_x, tabela_ruchy[i].nowa_y,&zolt2, &nieb2);
							upuscpionek(tabela_ruchy[i].wskaznik_pionek, tabela_ruchy[i].nowa_x, tabela_ruchy[i].nowa_y);
							aktualizuj_damy(&zolt2, &nieb2);
							aktualizuj_plansza_pokaz(&zolt2, &nieb2, plansza_kopia);
							//wyswietlplansze(&zolt2,&nieb2);
							if((tabela_ruchy[i].wskaznik_pionek->kolor==zolty && sprbicie_pionka(*(tabela_ruchy[i].wskaznik_pionek), zolt2 ,nieb2) ==1) ||(tabela_ruchy[i].wskaznik_pionek->kolor==niebieski && sprbicie_pionka(*(tabela_ruchy[i].wskaznik_pionek), zolt2 ,nieb2) == 2))
								bedzie_bicie=1;
						}
				}	
			}	
			if(tabela_ruchy[i].bicie==0){
							upuscpionek(tabela_ruchy[i].wskaznik_pionek, tabela_ruchy[i].nowa_x, tabela_ruchy[i].nowa_y);
							aktualizuj_damy(&zolt2, &nieb2);
							aktualizuj_plansza_pokaz(&zolt2, &nieb2, plansza_kopia);
							//wyswietlplansze(&zolt2,&nieb2);
							bedzie_bicie=0;
			}
			ilosc_kombinacji++;
			if(ilosc_kombinacji>0 && ilosc_kombinacji%10000==0) cout<<"* ";
			e_kolor nowy_kolor;
			if(kolor==niebieski)nowy_kolor=zolty;
			else nowy_kolor=niebieski;
			ruchy jakis_ruch;
			int wynik=0;
			if(bedzie_bicie==1)
				wynik=wykonaj_ruchy_rekurencja(&jakis_ruch,kolor,ile_iter,zolt2, nieb2,0);
			if(bedzie_bicie==0)
				wynik=wykonaj_ruchy_rekurencja(&jakis_ruch,nowy_kolor,ile_iter-1,zolt2, nieb2,0);
			if(wynik==-10000){
				tabela_ruchy_test[i].wartosc_planszy=oblicz_wartosc_planszy_kris(kolor,zolt2,nieb2, plansza_kopia);
				//cout<<"wartosc planszy"<<tabela_ruchy_test[i].wartosc_planszy<<endl;
			}
			else{
				tabela_ruchy_test[i].wartosc_planszy=wynik;
			}
		}
		int max=-1000;
		int min=10000;
		int pozycja=0;
		if(kolor==niebieski){
			for(int i=0;i<ilosc_ruchow;i++)if(tabela_ruchy_test[i].wartosc_planszy>max){max=tabela_ruchy_test[i].wartosc_planszy; pozycja=i;}
		}
		if(kolor==zolty){
			for(int i=0;i<ilosc_ruchow;i++)if(tabela_ruchy_test[i].wartosc_planszy<min){min=tabela_ruchy_test[i].wartosc_planszy; pozycja=i;}
		}
		/*
		if(kolor==niebieski){
			for(int i=0;i<ilosc_ruchow;i++)if(tabela_ruchy_test[i].wartosc_planszy<min){min=tabela_ruchy_test[i].wartosc_planszy; pozycja=i;}
		}
		*/
		if(pierwsze_wywolanie==1){
			//(*dobry_ruch).wskaznik_pionek=tabela_ruchy_test[pozycja].wskaznik_pionek;
			(*dobry_ruch).pionek.pozycjax=tabela_ruchy_test[pozycja].wskaznik_pionek->pozycjax;
			(*dobry_ruch).pionek.pozycjay=tabela_ruchy_test[pozycja].wskaznik_pionek->pozycjay;
			(*dobry_ruch).pionek.zycie=tabela_ruchy_test[pozycja].wskaznik_pionek->zycie;
			(*dobry_ruch).pionek.dama=tabela_ruchy_test[pozycja].wskaznik_pionek->dama;
			(*dobry_ruch).pionek.kolor=tabela_ruchy_test[pozycja].wskaznik_pionek->kolor;
			(*dobry_ruch).nowa_x=tabela_ruchy_test[pozycja].nowa_x;
			(*dobry_ruch).nowa_y=tabela_ruchy_test[pozycja].nowa_y;
			(*dobry_ruch).bicie=tabela_ruchy_test[pozycja].bicie;
			(*dobry_ruch).wartosc_planszy=tabela_ruchy_test[pozycja].wartosc_planszy;
			ilosc_kombinacji=0;
		}
		return tabela_ruchy_test[pozycja].wartosc_planszy;
	}else{
		//cout<<"koniec"<<endl;
		return -10000;}
}
int Gra::wykonaj_najlepszy_ruch(ruchy* dobry_ruch,Gracz* zolt, Gracz* nieb)
{
	for(int i=0;i<1;i++){
		int plansza_kopia[8][8][2];
		for(int x=0;x<8;x++){
			for(int y=0;y<8;y++){
				plansza_kopia[x][y][0]=0;
				plansza_kopia[x][y][1]=0;
			}
		}
		aktualizuj_damy(zolt, nieb);
		aktualizuj_plansza_pokaz(zolt, nieb, plansza_kopia);
		ruchy tabela_ruchy[1000];
		zgromadz_ruchy(zolty, zolt, nieb,&tabela_ruchy);
		for(int z=0;z<12;z++){
			if(G[0].P[z].pozycjax==dobry_ruch->pionek.pozycjax && G[0].P[z].pozycjay==dobry_ruch->pionek.pozycjay && G[0].P[z].zycie==1)
				dobry_ruch->wskaznik_pionek=&(G[0].P[z]);
				//break;
		}	
	
			if(dobry_ruch->bicie==1){
				if ((dobry_ruch->wskaznik_pionek->kolor==zolty && sprbicie(dobry_ruch->wskaznik_pionek->kolor, (*zolt),(*nieb)) == 1) || (dobry_ruch->wskaznik_pionek->kolor==niebieski && sprbicie(dobry_ruch->wskaznik_pionek->kolor, (*zolt),(*nieb)) == 2) ) {
						if(poprawnoscbicia(dobry_ruch->wskaznik_pionek,(*zolt) ,(*nieb),dobry_ruch->nowa_x,dobry_ruch->nowa_y) == 1) {
							usunpionek(dobry_ruch->wskaznik_pionek, dobry_ruch->nowa_x, dobry_ruch->nowa_y,zolt, nieb);
							upuscpionek(dobry_ruch->wskaznik_pionek, dobry_ruch->nowa_x, dobry_ruch->nowa_y);
							aktualizuj_damy(zolt, nieb);
							aktualizuj_plansza_pokaz(zolt, nieb, plansza_kopia);
							while((dobry_ruch->wskaznik_pionek->kolor == zolty && sprbicie(dobry_ruch->wskaznik_pionek->kolor,G[0],G[1]) ==1) || (dobry_ruch->wskaznik_pionek->kolor == niebieski && sprbicie(dobry_ruch->wskaznik_pionek->kolor,G[0],G[1]) ==2)){
								wykonaj_ruchy_rekurencja(dobry_ruch,dobry_ruch->wskaznik_pionek->kolor,glebokosc,G[0], G[1],1);
								wykonaj_najlepszy_ruch(dobry_ruch,&G[0], &G[1]);
							}						
						}
			}
		}
		if(dobry_ruch->bicie==0){
						upuscpionek(dobry_ruch->wskaznik_pionek, dobry_ruch->nowa_x, dobry_ruch->nowa_y);
						aktualizuj_damy(zolt, nieb);
						aktualizuj_plansza_pokaz(zolt, nieb, plansza_kopia);
		}
	}
	return 3;
}

void Gra::kontynuj_bicie(ruchy tabela_ruchy[1000],Gracz* zolt, Gracz *nieb){
		int plansza_kopia[8][8][2];
		for(int x=0;x<8;x++){
			for(int y=0;y<8;y++){
				plansza_kopia[x][y][0]=0;
				plansza_kopia[x][y][1]=0;
			}
		}
		aktualizuj_plansza_pokaz(zolt,nieb,plansza_kopia);
		int iteracja=0;		
		int bicie_zaznaczone=0;
		nowepozycje wsk[1200];
		bicie_zaznaczone=zaznaczbicie_pionka(&tabela_ruchy[0],&wsk,zolt ,nieb);
		while(sprbicie_pionka(*(tabela_ruchy[0].wskaznik_pionek), *zolt ,*nieb)==1 && bicie_zaznaczone>0){
			//for(int i=0;i<12;i++)wsk[i]=(nowepozycje*) malloc (sizeof(nowepozycje));
			//for(int i=0;i<12;i++)wsk[i]=tabela_ruchy[i].wskazniki[i];
			//for(int l=0;l<iteracja;l++)wsk[0]=wsk[0]->wskazniki[0];
			if ((tabela_ruchy[0].wskaznik_pionek->kolor==zolty && sprbicie(tabela_ruchy[0].wskaznik_pionek->kolor, (*zolt),(*nieb)) == 1) || (tabela_ruchy[0].wskaznik_pionek->kolor==niebieski && sprbicie(tabela_ruchy[0].wskaznik_pionek->kolor, (*zolt),(*nieb))== 2) ) {
				if(poprawnoscbicia((tabela_ruchy[0].wskaznik_pionek),(*zolt) ,(*nieb), wsk[0].nowa_x, wsk[0].nowa_y) == 1) {
					usunpionek((tabela_ruchy[0].wskaznik_pionek), wsk[0].nowa_x,  wsk[0].nowa_y,zolt, nieb);
					upuscpionek((tabela_ruchy[0].wskaznik_pionek),wsk[0].nowa_x,  wsk[0].nowa_y);
					aktualizuj_damy(zolt, nieb);
					aktualizuj_plansza_pokaz(zolt, nieb, plansza_kopia);
				}
			}
			bicie_zaznaczone=zaznaczbicie_pionka(&tabela_ruchy[0],&wsk,zolt ,nieb);
			//zgromadz_ruchy(tabela_ruchy[0].wskaznik_pionek->kolor,zolt,nieb,&tabela_ruchy);
			iteracja++;
		}
}

int Gra::oblicz_wartosc_planszy_kris(e_kolor kolor,Gracz zolt, Gracz nieb, int plansza[8][8][2]) {
	int wartosc[9];
	int punktacja_y = 1;
	int wspolczynnik_y[9];
	wspolczynnik_y[4] = 1;
	wspolczynnik_y[8] = -1;
	int wspolczynnik_y2[9];
	wspolczynnik_y2[4] = 0;
	wspolczynnik_y2[8] = 7;
	wartosc[4] = 0;
	wartosc[8] = 0;
	for (int k = 4; k < 9; k = k + 4) {
		//liczenie pionków i ich położenie
		for (int x = 0; x<8; x++) {
			for (int y = 0; y<8; y++) {
				if (plansza[x][y][0] == k) {
					if (plansza[x][y][1] == pionek) {
						wartosc[k] = wartosc[k] + waga_pionek + 2 * (y*wspolczynnik_y[k] + wspolczynnik_y2[k]);
						//położenie bliżej środka
						if (x == 0 || x == 7) {
							wartosc[k] = wartosc[k] + trzy_srodek;
						}
						if (x == 1 || x == 6) {
							wartosc[k] = wartosc[k] + dwa_srodek;
						}
						if (x == 2 || x == 3 || x == 4 || x == 5) {
							wartosc[k] = wartosc[k] + srodek;
						}
						// chodzenie w grupach
						if (x + 1 < 8 && y + 1 < 8) {
							if (plansza[x + 1][y + 1][1] == pionek) {
								wartosc[k] = wartosc[k] + chodzenie_grupa;
							}
						}
						if (x - 1 > 0 && y + 1 < 8) {
							if (plansza[x - 1][y + 1][1] == pionek) {
								wartosc[k] = wartosc[k] + chodzenie_grupa;
							}
						}
						if (x + 1 < 8 && y - 1 > 0) {
							if (plansza[x + 1][y - 1][1] == pionek) {
								wartosc[k] = wartosc[k] + chodzenie_grupa;
							}
						}
						if (x - 1 > 0 && y - 1 > 0) {
							if (plansza[x - 1][y - 1][1] == pionek) {
								wartosc[k] = wartosc[k] + chodzenie_grupa;
							}
						}
					}
					if (plansza[x][y][1] == dama) {
						wartosc[k] = wartosc[k] + waga_dama;
						if ((x == 0 && y == 1 || y == 3 || y == 5 || y == 7) ||
							(x == 7 && y == 0 || y == 2 || y == 4 || y == 6) ||
							(y == 0 && x == 1 || x == 3 || x == 5 || x == 7) ||
							(y == 7 && x == 0 || x == 2 || x == 4 || x == 6)) {
							wartosc[k] = wartosc[k] + chodzenie_dama;
						}
					}
				}
			}
		}
	}
	wartosc[4] = wartosc[4] + sprbicie(zolty, zolt, nieb) * waga_bicie; //wartosc zoltych
	wartosc[8] = wartosc[8] + sprbicie(niebieski, zolt, nieb) * waga_bicie; //wartosc niebieskich
	int a=0;
	e_kolor nowy_kolor;
	if (kolor == niebieski)nowy_kolor = zolty;
	else nowy_kolor = niebieski;
	a=mozliwosc_ruchu(nowy_kolor, &zolt, &nieb);
	if(a==0) {
		if(kolor==niebieski) return -10000;
		if(kolor==zolty) return 10000;
	}
	return wartosc[8] - wartosc[4]; //niebiescy - zolci
}