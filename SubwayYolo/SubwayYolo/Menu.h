#ifndef Menu_H
#define Menu_H
#include <iostream>

#include "Konta.h"
#include "Kanapka.h"


class Menu
{
public:
	virtual void menu(Konta *x, Kanapka *y, Skladnik *z, std::string s) =0;
};

/////////////////RAFALTOGNUJ////////////

class Uzytkownik : public Menu
{
public:
	virtual void menu(Konta *x, Kanapka *y, Skladnik *z, std::string s);

};


///////////////NAPRAWDE////////////////

class Admin : public Menu
{
public:
	virtual void menu(Konta *x, Kanapka *y, Skladnik *z, std::string s);
};


#endif // !Menu_H
