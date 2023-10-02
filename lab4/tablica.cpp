#include "tablica.h"

void Tablica::stworzTablice()
{	
	tablica = new int* [liczba_kolumn];
	for (int k = 0; k < liczba_kolumn; k++)
	{
		tablica[k] = new int[liczba_wierszy];
	}
	for (int w = 0; w < liczba_wierszy; w++)
	{
		for (int k = 0; k < liczba_kolumn; k++)
		{
			tablica[k][w] = 0;
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
			plik >> tablica[k][w];
		}
	}
	plik.close();		
}

void Tablica::zapiszTablice()
{
	fstream plik;
	plik.open("dane.txt", ios::trunc | ios::out);
	plik << liczba_kolumn << endl;
	plik << liczba_wierszy << endl;
	for (int w = 0; w < liczba_wierszy; w++)
	{
		for (int k = 0; k < liczba_kolumn; k++)
		{
			plik << tablica[k][w] << " ";
		}
		plik << endl;
	}
}

void Tablica::wyswietlTablice()
{
	for (int w = 0; w < liczba_wierszy; w++)
	{
		for (int k = 0; k < liczba_kolumn; k++)
		{
			cout << tablica[k][w] << "   ";
		}
		cout << endl;
		cout << endl;
	}
}

void Tablica::modyfikujKomorke(int wyb_kolumna, int wyb_wiersz, int nowa_zawartosc)
{
	tablica[wyb_kolumna-1][wyb_wiersz-1] = nowa_zawartosc;
}

void Tablica::modyfikujRozmiar(int nowy_kolumny, int nowy_wiersze)
{	
	Tablica* nowy = new Tablica(nowy_kolumny, nowy_wiersze);
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
	delete[] nowy;
	liczba_kolumn = nowy_kolumny;
	liczba_wierszy = nowy_wiersze;
}

void Tablica::sumowanieKolumny()
{
	int suma = 0;
	wyswietlTablice();
	cout << endl;
	for (int k = 0; k < liczba_kolumn; k++)
	{
		for (int w = 0; w < liczba_wierszy; w++)
		{
			suma += tablica[k][w];
		}
		cout << suma << " ";
		suma = 0;
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
			suma += tablica[k][w];
		}
		cout << suma << " ";
		suma = 0;
	}
	cout << "Sumy wierszy" << endl;
}

void Tablica::ekstremumKolumny()
{
	wyswietlTablice();
	cout << endl;
	int min = 9999999;
	int max = -9999999;
	for (int k = 0; k < liczba_kolumn; k++)
	{
		for (int w = 0; w < liczba_wierszy; w++)
		{
			if (min > tablica[w][k])
			{
				min = tablica[w][k];
			}
		}
		cout << min << " ";
		min = 9999999;
	}
	cout << " Najmniejsza " << endl;
	for (int k = 0; k < liczba_kolumn; k++)
	{
		for (int w = 0; w < liczba_wierszy; w++)
		{
			if (max < tablica[k][w])
			{
				max = tablica[k][w];
			}
		}
		cout << max << " ";
		max = -9999999;
	}
	cout << " Największa " << endl;
}
void Tablica::ekstremumWiersze()
{
	wyswietlTablice();	
	cout << endl;
	int min = 9999999;
	int max = -9999999;
	for (int w = 0; w < liczba_wierszy; w++)
	{
		for (int k = 0; k < liczba_kolumn; k++)
		{
			if (min > tablica[k][w])
			{
				min = tablica[k][w];
			}
			if (max < tablica[k][w])
			{
				max = tablica[k][w];
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
		for (int w = 0; w < liczba_wierszy; w++)
		{
			suma += tablica[k][w];
		}
		cout << suma/liczba_wierszy << " | ";
		suma = 0;
	}
	cout << endl;
}	

void Tablica::sredniaWiersze()
{
	float suma = 0;
	for (int w = 0; w < liczba_wierszy; w++)
	{
		for (int k = 0; k < liczba_kolumn; k++)
		{
			suma += tablica[k][w];
			cout << tablica[k][w] << " ";
		}
		cout << "	" << suma/liczba_kolumn << endl;
		suma = 0;
	}
	
}
