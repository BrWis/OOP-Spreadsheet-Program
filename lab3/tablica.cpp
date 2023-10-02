#include "tablica.h"

void stworzTablice(Tablica* arr, int liczba_kolumn, int liczba_wierszy)
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
	
	arr->tablica = tablica;
	arr->liczba_kolumn = liczba_kolumn;
	arr->liczba_wierszy = liczba_wierszy;
}

void usunTablice(Tablica arr)
{
	for (int k = 0; k < arr.liczba_kolumn; k++)
	{
        	delete[] arr.tablica[k];
	}
	delete[] arr.tablica;
}

void wczytajTablice(Tablica* arr) 
{
	fstream plik;
	plik.open("dane.txt");
	int liczba_kolumn = 0;
	int liczba_wierszy = 0;
	if (plik.eof())
	{
		stworzTablice(arr, 1, 1);
		cout << "BRAK DANYCH W PLIKU" << endl;
		cout <<	"Utworzono tablicę 1x1" << endl;
	}
	plik >> liczba_kolumn;
	plik >> liczba_wierszy;
	stworzTablice(arr, liczba_kolumn, liczba_wierszy);
	for (int w = 0; w < arr->liczba_wierszy; w++)
	{
		for (int k = 0; k < arr->liczba_kolumn; k++)
		{
			if (plik.eof())
			{
				break;
			}
			plik >> arr->tablica[k][w];
		}
	}
	plik.close();		
}

void zapiszTablice(Tablica arr)
{
	fstream plik;
	plik.open("dane.txt", ios::trunc | ios::out);
	plik << arr.liczba_kolumn << endl;
	plik << arr.liczba_wierszy << endl;
	for (int w = 0; w < arr.liczba_wierszy; w++)
	{
		for (int k = 0; k < arr.liczba_kolumn; k++)
		{
			plik << arr.tablica[k][w] << " ";
		}
		plik << endl;
	}
}

void wyswietlTablice(Tablica arr)
{
	for (int w = 0; w < arr.liczba_wierszy; w++)
	{
		for (int k = 0; k < arr.liczba_kolumn; k++)
		{
			cout << arr.tablica[k][w] << " ";
		}
		cout << endl;
	}
}

void modyfikujKomorke(Tablica* arr, int wyb_kolumna, int wyb_wiersz, int nowa_zawartosc)
{
	arr->tablica[wyb_kolumna-1][wyb_wiersz-1] = nowa_zawartosc;
}

void modyfikujRozmiar(Tablica* arr, int nowy_kolumny, int nowy_wiersze)
{	
	Tablica* nowy = new Tablica;
	stworzTablice(nowy, nowy_kolumny, nowy_wiersze);
	int kolumny = arr->liczba_kolumn;
	int wiersze = arr->liczba_wierszy;
	if (nowy_kolumny < arr->liczba_kolumn)
	{
		kolumny = nowy_kolumny;
	}
	if(nowy_wiersze < arr->liczba_wierszy)
	{
		wiersze < nowy_wiersze;
	}
	for (int w = 0; w < wiersze; w++)
	{
		for (int k = 0; k < kolumny; k++)
		{
			nowy->tablica[k][w] = arr-> tablica[k][w];
		}
	}
	delete[]arr->tablica;
	arr->tablica = nowy->tablica;
	delete[]nowy;
	arr->liczba_kolumn = nowy_kolumny;
	arr->liczba_wierszy = nowy_wiersze;
}

void sumowanieKolumny(Tablica arr)
{
	int suma = 0;
	wyswietlTablice(arr);
	cout << endl;
	for (int k = 0; k < arr.liczba_kolumn; k++)
	{
		for (int w = 0; w < arr.liczba_wierszy; w++)
		{
			suma += arr.tablica[k][w];
		}
		cout << suma << " ";
		suma = 0;
	}
	cout << "Sumy kolumn" << endl;
}

void sumowanieWiersze(Tablica arr)
{
	int suma = 0;
	wyswietlTablice(arr);
	cout << endl;	
	for (int w = 0; w < arr.liczba_wierszy; w++)
	{
		for (int k = 0; k < arr.liczba_kolumn; k++)
		{
			suma += arr.tablica[k][w];
		}
		cout << suma << " ";
		suma = 0;
	}
	cout << "Sumy wierszy" << endl;
}

void ekstremumKolumny(Tablica arr)
{
	wyswietlTablice(arr);
	cout << endl;
	int min = 9999999;
	int max = -9999999;
	for (int k = 0; k < arr.liczba_kolumn; k++)
	{
		for (int w = 0; w < arr.liczba_wierszy; w++)
		{
			if (min > arr.tablica[w][k])
			{
				min = arr.tablica[w][k];
			}
		}
		cout << min << " ";
		min = 9999999;
	}
	cout << " Najmniejsze " << endl;
	for (int k = 0; k < arr.liczba_kolumn; k++)
	{
		for (int w = 0; w < arr.liczba_wierszy; w++)
		{
			if (max < arr.tablica[k][w])
			{
				max = arr.tablica[k][w];
			}
		}
		cout << max << " ";
		max = -9999999;
	}
	cout << " Największe " << endl;
}
void ekstremumWiersze(Tablica arr)
{
	wyswietlTablice(arr);	
	cout << endl;
	int min = 9999999;
	int max = -9999999;
	for (int w = 0; w < arr.liczba_wierszy; w++)
	{
		for (int k = 0; k < arr.liczba_kolumn; k++)
		{
			if (min > arr.tablica[k][w])
			{
				min = arr.tablica[k][w];
			}
			if (max < arr.tablica[k][w])
			{
				max = arr.tablica[k][w];
			}
		}	
		cout << min << " - " << max << " Najmniejsza - Największa" << endl;
		min = 9999999;
		max = -9999999;	
	}
	cout << endl;
}

void sredniaKolumny(Tablica arr)
{
	float suma = 0;
	wyswietlTablice(arr);
	cout << endl;	
	for (int k = 0; k < arr.liczba_kolumn; k++)
	{
		for (int w = 0; w < arr.liczba_wierszy; w++)
		{
			suma += arr.tablica[k][w];
		}
		cout << suma/arr.liczba_wierszy << " ";
		suma = 0;
	}
}

void sredniaWiersze(Tablica arr)
{
	float suma = 0;
	for (int w = 0; w < arr.liczba_wierszy; w++)
	{
		for (int k = 0; k < arr.liczba_kolumn; k++)
		{
			suma += arr.tablica[k][w];
			cout << arr.tablica[k][w] << " ";
		}
		cout << "	" << suma/arr.liczba_kolumn << endl;
		suma = 0;
	}
	
}
