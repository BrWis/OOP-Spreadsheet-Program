#include "tablica.h"


void drukujMenu(Tablica* arr)
{
	int wybor = 999;

	while(wybor!=0)
	{
		cout << "=============================***=============================" << endl;
		cout << "Stwórz nową tablicę --> 1." << endl;
		cout << "Wyświetl tablicę --> 2." << endl;
		cout << "Zmień zawartość komórki tablicy --> 3." << endl;
		cout << "Zmień rozmiar tablicy --> 4." << endl;
		cout << "Sumuj wartości w kolumnach --> 5." << endl;
		cout << "Sumuj wartości w wierszach ---> 6." << endl;
		cout << "Wyświetl najmniejszą i największą wartość w kolumnach --> 7." << endl;
		cout << "Wyświetl najmniejszą i największą wartość w wierszach --> 8." << endl;
		cout << "Wyświetl średnią wartość dla kolumn --> 9." << endl;
		cout << "Wyświetl średnią wartość dla wierszy --> 10." << endl;
		cout << "Zapisz tablicę do pliku --> 11." << endl;
		cout << "Wczytaj tablicę z pliku -->12." << endl;
		cout << "Opuść program --> 0." << endl;
		cout << "=============================***=============================" << endl;
	
		cout << "Wybierz co chcesz zrobić: ";
		cin >> wybor;
		cout << endl;

		switch(wybor)
		{
			case 1:
				int liczba_kolumn;
				int liczba_wierszy;
				cout << "Podaj liczbę kolumn: ";
				cin >> liczba_kolumn;
				cout << "Podaj liczbę wierszy: ";
				cin >> liczba_wierszy;
				stworzTablice(arr, liczba_kolumn, liczba_wierszy);
				break;
			case 2:
				wyswietlTablice(*arr);
				break;
			case 3:
				int kolumna, wiersz, zawartosc;
				cout << "Aktualny stan tablicy:" << endl;
				wyswietlTablice(*arr);
				cout << "Którą komórkę zmodyfikować?" << endl;
				cout << "Kolumna: ";
				cin >> kolumna;
				cout << "Wiersz: ";
				cin >> wiersz;
				if((kolumna > arr->liczba_kolumn) || (wiersz > arr->liczba_wierszy)  || (kolumna < 1) || (wiersz < 1))
				{
					cout << "BŁĄD! Współrzędne komórki niezgodne z wymiarem tablicy. " << endl;
					break;
				} 
				else
				{
					cout << "Nowa zawartość: ";
					cin >> zawartosc;
				}
				modyfikujKomorke(arr, kolumna, wiersz, zawartosc);
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
				if((mod_kolumny == arr->liczba_kolumn) && (mod_wiersze == arr->liczba_wierszy))
				{
					cout << "Podano obecny rozmiar." << endl;
					break;
				}
				if((mod_kolumny < arr->liczba_kolumn) || (mod_wiersze < arr->liczba_wierszy))
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
					modyfikujRozmiar(arr, mod_kolumny, mod_wiersze);
				}
				break;

			case 5:
				sumowanieKolumny(*arr);
				break;
			case 6:
				sumowanieWiersze(*arr);
				break;
			case 7:
				ekstremumKolumny(*arr);
				break;
			case 8:
				ekstremumWiersze(*arr);
				break;
			case 9:
				sredniaKolumny(*arr);
				break;
			case 10:
				sredniaWiersze(*arr);
				break;
			case 11:
				zapiszTablice(*arr);
				cout << "Zapisano!" << endl;
				break;
			case 12:
				wczytajTablice(arr);
				cout << "Wczytywanie zakończone!" << endl;
				break;

			default:
				wybor=0;
				usunTablice(*arr);				
				break;
		}		
	}
}
