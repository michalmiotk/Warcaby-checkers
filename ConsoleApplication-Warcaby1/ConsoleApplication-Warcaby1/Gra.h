#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <cstdlib>
#include "Gracz.h"
#include <conio.h>
using namespace std;
struct nowepozycje{
	int nowa_x;
	int nowa_y;
};
struct ruchy{
	Pionek pionek;
	Pionek* wskaznik_pionek;
	int nowa_x;
	int nowa_y;
	int bicie;
	int wartosc_planszy;
};
class Gra
{
public:
	Gra();
	~Gra();
	Gracz G[2];
	int ilosc_kombinacji;
	ruchy najlepszy_ruch;
	int plansza_pokaz[8][8][2];
	int pozycjakontrolerax;
	int pozycjakontroleray;
	void aktualizuj_plansza_pokaz(Gracz* zolt,Gracz* nieb,int plansza_kopia[8][8][2]);
	void zmienkolor(e_kolor);
	void wyswietlplansze();
	void wyswietlplansze(Gracz* zolt,Gracz* nieb);
	void aktualizuj_damy(Gracz* zolt, Gracz* nieb);
	int sprpionekkontroler(Gracz zolt, Gracz nieb);//0-nie ma pionka 1-pionek zolty(Gracz1) 2-pionek niebieski(Gracz2) 11-zoltadama 22-niebieskadama
	int poprawnoscruchu(Pionek* pionek, int nowe_x, int nowe_y,int plansza_kopia[8][8][2]);
	int poprawnoscbicia(); //0-zle bicie 1-dobrebicie
	int poprawnoscbicia(Pionek* pionek,Gracz zolt,Gracz nieb,int nowe_x,int nowe_y); //0-zle bicie 1-dobrebicie
	int wolne_pole(int x, int y,int plansza_kopia[8][8][2]);
	int sprbicie(e_kolor);//0-brak mozliwego bicia 1-mozliwe bicie //podaj kolor dla sprawdzanego gracza
	int sprbicie(e_kolor, Gracz zolt ,Gracz nieb);//0-brak mozliwego bicia 1-mozliwe bicie //podaj kolor dla sprawdzanego gracza
	int zaznaczbicie(e_kolor, Gracz* zolt ,Gracz* nieb,int (*plansza_kopia)[8][8][2],ruchy (*tabela_ruchy)[1000]);
	int zaznaczbicie_pionka(ruchy* ruch,nowepozycje (*wskazniki)[1200],Gracz* zolt ,Gracz* nieb);
	int sprbicie_pionka(Pionek pionek, Gracz zolt ,Gracz nieb);
	int oblicz_wartosc_planszy(e_kolor,int plansza_kopia[8][8][2]);
	int wektor_ruchu_x();//zwraca roznice wsp punktu x zaznaczonego pola i pozycji kontrolera
	int wektor_ruchu_x(Pionek* pionek,int nowe_x);
	int wektor_ruchu_y();//zwraca roznice wsp punktu y zaznaczonego pola i pozycji kontrolera
	int wektor_ruchu_y(Pionek* pionek,int nowe_y);
	int zgromadz_ruchy(e_kolor kolor, Gracz* zolt, Gracz* nieb,ruchy (*tabela)[1000]);
	Pionek* wskaznik_plansza(int x,int y,Gracz* zolt, Gracz* nieb);
	int mozliwosc_ruchu(e_kolor kolor, Gracz* zolt, Gracz* nieb);
	int  wykonaj_ruchy_rekurencja(ruchy* dobry_ruch,e_kolor kolor,int ile_iter,Gracz zolt, Gracz nieb,int pierwsze_wywolanie);
	int  wykonaj_najlepszy_ruch(ruchy* dobry_ruch,Gracz* zolt, Gracz* nieb);
	int  oblicz_wartosc_planszy_kris(e_kolor kolor,Gracz zolt, Gracz nieb, int plansza[8][8][2]);
	void kontynuj_bicie(ruchy tabela_ruchy[1000],Gracz* zolt, Gracz *nieb);
	void inicjuj_struktura_ruchy(ruchy* struktura);
	void zmienpozycjekontrolera();//zmienia pozycje kontrolera
	void podniescpionka();
	void upuscpionek();
	void upuscpionek(Pionek* pionek, int nowex, int nowey);
	void usunpionek();
	void usunpionek(Pionek* pionek, int nowex, int nowey, Gracz* zolt, Gracz* nieb);
	void start();
private:
	int kontroler;
	Pionek *wsk;
	Pionek *wsk_pomocniczy;
};

