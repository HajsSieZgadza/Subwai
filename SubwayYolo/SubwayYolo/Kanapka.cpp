#include "Kanapka.h"
using namespace std;
#include <Windows.h>
Kanapka::Kanapka() {};
Kanapka::Kanapka(string _x, double _y, string _z)
{
	nazwa = _x;
	cena = _y;
	opis = _z;
}

void Kanapka::wczytajMenu(string menu)
{
	ifstream plik(menu);
	string linie;
	while (getline(plik, linie))
	{
		stringstream wczyt(linie);
		double cena;
		string nazwa, opis;
		wczyt >> nazwa;
		wczyt.ignore();
		wczyt >> cena;
		wczyt.ignore();
		wczyt >> opis;
		kanapka.push_back(Kanapka(nazwa, cena, opis));
	}
	plik.close();
}

void Kanapka::dodajKanapke()
{
	string newNazwa, newOpis;
	double newCena;
	cout << "Podaj nazwe nowej kanapki : ";
	cin >> newNazwa;
	cout << "\nPodaj cene nowej kanapki : ";
	cin >> newCena;
	cout << "\nPodaj opis nowej kanapki : ";
	cin >> newOpis;
	kanapka.push_back(Kanapka(newNazwa, newCena, newOpis));
}

void Kanapka::kanapkaDnia(string s)
{
	ofstream zapis("kanapka_dnia.txt");
	string newNazwa, newOpis;
	double newCena;
	cout << "Podaj nazwe kanapki dnia : ";
	cin >> newNazwa;
	cout << "\nPodaj cene kanapki dnia : ";
	cin >> newCena;
	cout << "\nPodaj opis kanapki dnia : ";
	cin >> newOpis;
	zapis << newNazwa << " " << newCena << " " << newOpis << endl;
	zapis.close();
}

void Kanapka::wyswietlMenu()
{
	ifstream kanDnia("kanapka_dnia.txt");
	ofstream zapis("rachunek.txt");
	for (int i=0; i < ileKanapek(); i++)
	{
		cout << kanapka[i].nazwa << " " << kanapka[i].cena << " " << kanapka[i].opis << endl;
	}
	string nazwaa, opiss;
	double cenaa;
	kanDnia >> nazwaa;
	kanDnia >> cenaa;
	kanDnia >> opiss;
	cout << "Kanapka dnia : " << nazwaa << " " << cenaa << " " << opiss << endl;
	string wybor;
	char wybor2;
	double suma=0;
	for (;;)
	{
		cout << "Podaj nazwe zamawianej kanapki : ";
		cin >> wybor;
		for (int j = 0; j < ileKanapek(); j++)
		{
			if (wybor == "KanapkaDnia")
			{
				zapis << "Kanapka_dnia" << endl;
				suma = suma + cenaa;
			}
			else
			{
				if (wybor == kanapka[j].nazwa)
				{
					zapis << kanapka[j].nazwa << endl;
					suma = suma + kanapka[j].cena;
					break;
				}
			}
		}
		cout << "Czy chcesz zamownic cos jeszcze? t/n" << endl;
		cin >> wybor2;
		switch (wybor2)
		{
		case 't':
			{
				
			}
			break;
		case 'n':
		{
			cout << "Do jedzenia, uheueheuheueh!" << endl;
			Sleep(2000);
			zapis << suma <<"zl";
			exit(0);
		}
		break;
		default:
			break;
		}

	}
}

int Kanapka::ileKanapek()
{
	return kanapka.size();
}

void Kanapka::zapisKanapek(Kanapka& dane, std::string s)
{
	ofstream zapis(s);
	for (int i = 0; i<ileKanapek(); i++)
	{
		zapis << kanapka[i].nazwa << " " << kanapka[i].cena << " " << kanapka[i].opis << endl;
	}
	zapis.close();
}
/////////////////TAJNE//////////////////
Skladnik::Skladnik() {};

Skladnik::Skladnik(string _nazwa, double _cena)
{
	nazwa = _nazwa;
	cena = _cena;
}

void Skladnik::wczytajSkladniki(string s)
{
	ifstream plik(s);
	string linie;
	while (getline(plik, linie))
	{
		stringstream wczyt(linie);
		double cena;
		string nazwa;
		wczyt >> nazwa;
		wczyt.ignore();
		wczyt >> cena;
		skladnik.push_back(Skladnik(nazwa, cena));
	}
	plik.close();
}

void Skladnik::zbudujKanapke(string s)
{
	{
		ofstream zapis("rachunek.txt");
		for (int i = 0; i < ileSkladniki(); i++)
		{
			cout << skladnik[i].nazwa << " " << skladnik[i].cena << endl;
		}
		string wybor;
		char wybor2;
		double suma = 0;
		for (;;)
		{
			cout << "Podaj nazwe zamawianego skladnika : ";
			cin >> wybor;
			for (int j = 0; j < ileSkladniki(); j++)
			{
				if (wybor == skladnik[j].nazwa)
				{
					zapis << skladnik[j].nazwa << endl;
					suma = suma + skladnik[j].cena;
					break;
				}
			}
			cout << "Czy chcesz dodac cos jeszcze? t/n" << endl;
			cin >> wybor2;
			switch (wybor2)
			{
			case 't':
			{

			}
			break;
			case 'n':
			{
				cout << "Do jedzenia, uheueheuheueh!" << endl;
				Sleep(2000);
				zapis << suma << "zl";
				exit(0);
			}
			break;
			default:
				break;
			}

		}
	}
}

int Skladnik::ileSkladniki()
{
	return skladnik.size();
}