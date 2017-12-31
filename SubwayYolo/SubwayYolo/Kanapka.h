#ifndef Kanapka_H
#define Kanapka_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

class Kanapka
{
public:
	std::vector<Kanapka> kanapka;
	Kanapka();
	std::string nazwa, opis;
	double cena;
	Kanapka(std::string _x,double _y,std::string _z);
	void wczytajMenu(std::string menu);
	void wyswietlMenu();
	void dodajKanapke();
	void kanapkaDnia(std::string s);
	int ileKanapek();
	void zapisKanapek(Kanapka& dane, std::string s);
};
//////////////TAJNE//////////////////
class Skladnik
{
public:
	Skladnik();
	std::string nazwa;
	double cena;
	std::vector <Skladnik> skladnik;
	Skladnik(std::string _nazwa, double _cena);
	void wczytajSkladniki(std::string s);
	void zbudujKanapke(std::string s);
	int ileSkladniki();
};
#endif // !Kanapka_H
