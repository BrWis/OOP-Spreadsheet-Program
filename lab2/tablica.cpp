#include "tablica.h"

int** stworzTablice(int liczba_kolumn, int liczba_wierszy)
{	
	int** tablica = new int* [liczba_kolumn];
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
	return tablica;
}

void usunTablice(int** tablica, int liczba_kolumn)
{
	for (int k = 0; k < liczba_kolumn; k++)
	{
        	delete[] tablica[k];
	}
	delete[] tablica;
}

int** wczytajTablice(int* liczba_kolumn, int* liczba_wierszy) 
{
	fstream plik;
	plik.open("dane.txt");
	if (plik.eof())
	{
		*liczba_kolumn = 1;
		*liczba_wierszy = 1;
		int** czystaTablica = stworzTablice(*liczba_kolumn, *liczba_wierszy);
		cout << "BRAK DANYCH W PLIKU" << endl;
		cout <<	"Utworzono tablicę 1x1" << endl;
		return czystaTablica;
	}
	plik >> *liczba_kolumn;
	plik >> *liczba_wierszy;
	int** nowaTablica = stworzTablice(*liczba_kolumn, *liczba_wierszy);
	for (int w = 0; w < *liczba_wierszy; w++)
	{
		for (int k = 0; k < *liczba_kolumn; k++)
		{
			if (plik.eof())
			{
				break;
			}
			plik >> nowaTablica[k][w];
		}
	}
	plik.close();
	return nowaTablica;		
}

void zapiszTablice(int** tablica, int* liczba_kolumn, int* liczba_wierszy)
{
	fstream plik;
	plik.open("dane.txt", ios::trunc | ios::out);
	plik << *liczba_kolumn << endl;
	plik << *liczba_wierszy << endl;
	for (int w = 0; w < *liczba_wierszy; w++)
	{
		for (int k = 0; k < *liczba_kolumn; k++)
		{
			plik << tablica[k][w] << " ";
		}
		plik << endl;
	}
}

void wyswietlTablice(int** tablica, int liczba_kolumn, int liczba_wierszy)
{
	for (int w = 0; w < liczba_wierszy; w++)
	{
		for (int k = 0; k < liczba_kolumn; k++)
		{
			cout << tablica[k][w] << " ";
		}
		cout << endl;
	}
}

void modyfikujKomorke(int** tablica, int wyb_kolumna, int wyb_wiersz, int liczba_kolumn, int liczba_wierszy, int nowa_zawartosc)
{
	tablica[wyb_kolumna-1][wyb_wiersz-1] = nowa_zawartosc;
}

int** modyfikujRozmiar(int** tablica, int* rozm_kolumny, int* rozm_wiersze, int nowy_kolumny, int nowy_wiersze)
{	
	int** nowyTablica = stworzTablice(nowy_kolumny, nowy_wiersze);
	int kolumny = *rozm_kolumny;
	int wiersze = *rozm_wiersze;
	if (nowy_kolumny < *rozm_kolumny)
	{
		kolumny = nowy_kolumny;
	}
	if(nowy_wiersze < *rozm_wiersze)
	{
		wiersze < nowy_wiersze;
	}
	for (int w = 0; w < wiersze; w++)
	{
		for (int k = 0; k < kolumny; k++)
		{
			nowyTablica[k][w] = tablica[k][w];
		}
	}
	*rozm_kolumny = nowy_kolumny;
	*rozm_wiersze = nowy_wiersze;
	return nowyTablica;
}
