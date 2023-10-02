#include "tablica.h"

void Tablica::stworzTablice()
{	
	tablica = new Komorka** [liczba_kolumn];
	for (int k = 0; k < liczba_kolumn; k++)
	{
		tablica[k] = new Komorka* [liczba_wierszy];
	}
	for (int w = 0; w < liczba_wierszy; w++)
	{
		for (int k = 0; k < liczba_kolumn; k++)
		{
			if(this->typ[k] == 's')
			{
				tablica[k][w] = new KomorkaString();
			}
			else if(this->typ[k] == 'i')
			{
				tablica[k][w] = new KomorkaInt();
			}
		}
	}
}

int Tablica::liczbaKolumn()
{
	return liczba_kolumn;
}

int Tablica::liczbaWierszy()
{
	return liczba_wierszy;
}


void Tablica::usunTablice()
{
	for (int k = 0; k < liczba_kolumn; k++)
	{
        	delete[] tablica[k];
	}
	delete[] tablica;
}

void Tablica::wczytajTablice() 
{
	fstream plik;
	plik.open("dane.txt");
	if (plik.eof())
	{
		cout << "BRAK DANYCH W PLIKU" << endl;
	}
	plik >> typ;	
	plik >> liczba_kolumn;
	plik >> liczba_wierszy;
	stworzTablice();
	for (int w = 0; w < liczba_wierszy; w++)
	{
		for (int k = 0; k < liczba_kolumn; k++)
		{
			if (plik.eof())
			{
				break;
			}
			string wartosc;
			plik >> wartosc;
			tablica[k][w]->wczytaj(wartosc);			
		}
	}
	plik.close();		
}

void Tablica::zapiszTablice()
{
	fstream plik;
	plik.open("dane.txt", ios::trunc | ios::out);
	plik << typ << endl;
	plik << liczba_kolumn << endl;
	plik << liczba_wierszy << endl;
	for (int w = 0; w < liczba_wierszy; w++)
	{
		for (int k = 0; k < liczba_kolumn; k++)
		{
			plik << tablica[k][w]->zapisz() << " ";
		}
		plik << endl;
	}
}

void Tablica::wyswietlTablice()
{
	cout << "Typy kolumn: " << typ << endl << endl;
	for (int w = 0; w < liczba_wierszy; w++)
	{
		for (int k = 0; k < liczba_kolumn; k++)
		{
			cout << tablica[k][w]->zapisz() << "   ";
		}
		cout << endl;
		cout << endl;
	}
}

void Tablica::modyfikujKomorke(int wyb_kolumna, int wyb_wiersz, string nowa_zawartosc)
{
	tablica[wyb_kolumna-1][wyb_wiersz-1] -> wczytaj(nowa_zawartosc);
}

void Tablica::modyfikujRozmiar(int nowy_kolumny, int nowy_wiersze, string nowy_typ)
{	
	bool typ_poprawny = (typ.rfind(nowy_typ, 0) == 0 || nowy_typ.rfind(typ, 0) == 0);
	if(!typ_poprawny)
	{
		throw std::invalid_argument("Nie można zmienić typów istniejących kolumn");
	}
	Tablica* nowy = new Tablica(nowy_kolumny, nowy_wiersze, nowy_typ);
	int kolumny = liczba_kolumn;
	int wiersze = liczba_wierszy;
	if (nowy_kolumny < liczba_kolumn)
	{
		kolumny = nowy_kolumny;
	}
	if(nowy_wiersze < liczba_wierszy)
	{
		wiersze = nowy_wiersze;
	}
	for (int w = 0; w < wiersze; w++)
	{
		for (int k = 0; k < kolumny; k++)
		{
			nowy->tablica[k][w] = tablica[k][w];
		}
	}
	usunTablice();
	tablica = nowy->tablica;
	liczba_kolumn = nowy_kolumny;
	liczba_wierszy = nowy_wiersze;
	typ = nowy_typ;
	delete nowy;

}

void Tablica::sumowanieKolumny()
{

	int suma = 0;
	wyswietlTablice();
	cout << endl;
	for (int k = 0; k < liczba_kolumn; k++)	
	{
		if(this->typ[k] == 'i')
		{
			for (int w = 0; w < liczba_wierszy; w++)
			{
				suma += ((KomorkaInt*)tablica[k][w])->zwrocWartosc();
			}
			cout << suma << " ";
			suma = 0;
		}
	}
	cout << "Sumy kolumn" << endl;
}

void Tablica::sumowanieWiersze()
{
	int suma = 0;
	wyswietlTablice();
	cout << endl;	
	for (int w = 0; w < liczba_wierszy; w++)
	{
		for (int k = 0; k < liczba_kolumn; k++)
		{
			if(this->typ[k] == 'i')
			{			
			suma += ((KomorkaInt*)tablica[k][w])->zwrocWartosc();
			}
		}
		cout << suma << " ";
		suma = 0;
	}
	cout << "Sumy wierszy" << endl;

}

void Tablica::ekstremumKolumny()
{
	bool przetwarzaj = false;
		for(int i = 0; i < typ.length(); i++)
		{
			if(typ[i] == 'i')
			{ 
				przetwarzaj = true;
			}
		}
		if(!przetwarzaj)
		{
			return;
		}	
	wyswietlTablice();
	cout << endl;
	int min = 9999999;
	int max = -9999999;
	for (int k = 0; k < liczba_kolumn; k++)
	{
		if(this->typ[k] == 'i')
		{
			for (int w = 0; w < liczba_wierszy; w++)
			{
				int wartosc = ((KomorkaInt*)tablica[k][w])->zwrocWartosc();		
				if (min > wartosc)
				{
					min = wartosc;
				}
			}
			cout << min << " ";
		}
		min = 9999999;
	}
	cout << " Najmniejsza " << endl;
	for (int k = 0; k < liczba_kolumn; k++)
	{
		if(this->typ[k] == 'i')
		{
			for (int w = 0; w < liczba_wierszy; w++)
			{
				int wartosc = ((KomorkaInt*)tablica[k][w])->zwrocWartosc();
				if (max < wartosc)
				{
					max = wartosc;
				}
			}
			cout << max << " ";
			max = -9999999;
		}
	}
	cout << " Największa " << endl;
}
void Tablica::ekstremumWiersze()
{
	bool przetwarzaj = false;
	for(int i = 0; i < typ.length(); i++)
	{
		if(typ[i] == 'i')
		{ 
			przetwarzaj = true;
		}
	}
	if(!przetwarzaj)
	{
		return;
	}
	wyswietlTablice();	
	cout << endl;
	int min = 9999999;
	int max = -9999999;
	for (int w = 0; w < liczba_wierszy; w++)
	{		
		for (int k = 0; k < liczba_kolumn; k++)
		{
			if(this->typ[k] == 'i')
			{
				int wartosc = ((KomorkaInt*)tablica[k][w])->zwrocWartosc();		
				if (min > wartosc)
				{
					min = wartosc;
				}
				if (max < wartosc)
				{
					max = wartosc;
				}
			}
		}	
		cout << min << " - " << max << " Najmniejsza - Największa" << endl;
		min = 9999999;
		max = -9999999;	
	}
	cout << endl;
}

void Tablica::sredniaKolumny()
{
	float suma = 0;
	wyswietlTablice();
	cout << endl;	
	for (int k = 0; k < liczba_kolumn; k++)
	{
		if(this->typ[k] == 'i')
		{
			for (int w = 0; w < liczba_wierszy; w++)
			{
				suma += ((KomorkaInt*)tablica[k][w])->zwrocWartosc();
			}
		}
		cout << suma/liczba_wierszy << " | ";
		suma = 0;
	}
	cout << endl;
}	

void Tablica::sredniaWiersze()
{
	int liczba_kolumn_int = 0;	
	for(int i = 0; i < typ.length(); i++)
		{
			if(typ[i] == 'i')
			{ 
				liczba_kolumn_int++;
			}
		}
	if(liczba_kolumn_int == 0)
	{
		return;
	}
	float suma = 0;
	for (int w = 0; w < liczba_wierszy; w++)
	{
		for (int k = 0; k < liczba_kolumn; k++)
		{
			if(this->typ[k] == 'i')
			{
				int wartosc = ((KomorkaInt*)tablica[k][w])->zwrocWartosc();
				suma += wartosc;
				cout << wartosc << " ";
			}
			else if(this->typ[k] == 's')
			{
				string wartosc = ((KomorkaString*)tablica[k][w])->zwrocWartosc();
				cout << wartosc << " ";
			}
		}
		cout << "	" << suma/liczba_kolumn_int << endl;
		suma = 0;
	}
}
