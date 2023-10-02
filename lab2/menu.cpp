#include "tablica.h"


void drukujMenu(int** tablica, int* liczba_kolumn, int* liczba_wierszy)
{
	int wybor = 999;

	while(wybor!=0)
	{
		cout << "=============================***=============================" << endl;
		cout << "Stwórz nową tablicę --> 1." << endl;
		cout << "Wyświetl tablicę --> 2." << endl;
		cout << "Zmień zawartość komórki tablicy --> 3." << endl;
		cout << "Zmień rozmiar tablicy --> 4." << endl;
		cout << "Zapisz tablicę do pliku --> 5." << endl;
		cout << "Wczytaj tablicę z pliku --> 6." << endl;
		cout << "Opuść program --> 0." << endl;
		cout << "=============================***=============================" << endl;
		cout << "Wybierz co chcesz zrobić: ";
		cin >> wybor;
		cout << endl;

		switch(wybor)
		{
			case 1:
				cout << "Podaj liczbę kolumn: ";
				cin >> *liczba_kolumn;
				cout << "Podaj liczbę wierszy: ";
				cin >> *liczba_wierszy;
				tablica = stworzTablice(*liczba_kolumn, *liczba_wierszy);
				break;
			
			case 2:
				wyswietlTablice(tablica, *liczba_kolumn, *liczba_wierszy);
				break;

			case 3:
				int kolumna, wiersz, zawartosc;
				cout << "Aktualny stan tablicy:" << endl;
				wyswietlTablice(tablica, *liczba_kolumn, *liczba_wierszy);
				cout << "Którą komórkę zmodyfikować?" << endl;
				cout << "Kolumna: ";
				cin >> kolumna;
				cout << "Wiersz: ";
				cin >> wiersz;
				if((kolumna > *liczba_kolumn) || (wiersz > *liczba_wierszy)  || (kolumna < 1) || (wiersz < 1))
				{
					cout << "BŁĄD! Współrzędne komórki niezgodne z wymiarem tablicy. " << endl;
					break;
				} 
				else
				{
					cout << "Nowa zawartość: ";
					cin >> zawartosc;
				}
				modyfikujKomorke(tablica, kolumna, wiersz, *liczba_kolumn, *liczba_wierszy, zawartosc);
				break;

			case 4:
				int mod_kolumny, mod_wiersze, opcja;
				cout << "Nowa liczba kolumn: ";
				cin >> mod_kolumny;
				cout << "Nowa liczba wierszy: ";
				cin >> mod_wiersze;
				if((mod_kolumny < 1) || (mod_wiersze < 1))
				{
					cout << "BŁĄD! Podano rozmiar mniejszy od 1." << endl;
					break;
				}
				if((mod_kolumny == *liczba_kolumn) && (mod_wiersze == *liczba_wierszy))
				{
					cout << "Podano obecny rozmiar." << endl;
					break;
				}
				if((mod_kolumny < *liczba_kolumn) || (mod_wiersze < *liczba_wierszy))
				{
					cout << "Podany rozmiar jest mniejszy od poprzedniego." << endl;
					cout << "Zmienić mimo to? (1.TAK 2.NIE)" << endl;
					cin >> opcja;
				}
				if(opcja == 2)
				{
					cout << "Anulowano operację." << endl;
					break;
				}
				else
				{
					tablica = modyfikujRozmiar(tablica, liczba_kolumn, liczba_wierszy, mod_kolumny, mod_wiersze);
				}
				break;

			case 5:
				zapiszTablice(tablica, liczba_kolumn, liczba_wierszy);
				cout << "Zapisano!" << endl;
				break;

			case 6:
				tablica = wczytajTablice(liczba_kolumn, liczba_wierszy);
				cout << "Wczytywanie zakończone!" << endl;
				break;

			default:
				wybor=0;
				usunTablice(tablica, *liczba_kolumn);				
				break;
		}
	}
}	
