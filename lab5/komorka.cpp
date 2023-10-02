#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include "komorka.h"
	
void KomorkaInt::wczytaj(string wartosc)
{
	int i;	
	try
	{
		i = std::stoi(wartosc);
		this->wartosc = i;
	}
	catch (std::invalid_argument const &e)
	{
		cout << "Nieprawidłowa wartość INT: " << wartosc << endl;
	}
}

string KomorkaInt::zapisz()
{
	return to_string(this->wartosc);
}

void KomorkaString::wczytaj(string wartosc)
{
	this->wartosc = wartosc;
}

string KomorkaString::zapisz()
{
	return this->wartosc;
}
