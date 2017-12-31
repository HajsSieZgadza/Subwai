#include "Menu.h"
using namespace std;

void Uzytkownik::menu(Konta *x,Kanapka *y,Skladnik *z, string s)
{
	char wybor;
	cout << "1.) Wybierz kanapke z menu.\n2.) Stworz kanapke\n3.) Wyjdz\n ";
	cin >> wybor;
	switch (wybor)
	{
	case '1':
	{
		y->wyswietlMenu();

	}
	break;
	case '2':
	{
		z->zbudujKanapke(s);
	}
		break;
	case '3':
	{
		exit(0);
	}
	break;
	default:
		break;
	}
}

void Admin::menu(Konta *x, Kanapka *y, Skladnik *z, string s)
{
	char wybor;
	cout << "1.) Zmien Kanapke dnia.\n2.) Dodaj kanapke\n3.) Wyjdz\n ";
	cin >> wybor;
	switch (wybor)
	{
	case '1':
	{
		y->kanapkaDnia(s);

	}
	break;
	case '2':
	{
		y->dodajKanapke();
		y->zapisKanapek(*y, s);
	}
	break;
	case '3':
	{
		exit(0);
	}
	break;
	default:
		break;
	}
}