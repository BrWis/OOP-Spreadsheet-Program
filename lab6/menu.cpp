#include "tablica.h"


void drukujMenu(Tablica* arr)
{
	int wybor = 999;

	while(wybor!=0)
	{
		cout << "==============================***==============================" << endl;
		cout << "Stwórz nową tablicę 					--> 1." << endl;
		cout << "Wyświetl tablicę 					--> 2." << endl;
		cout << "Zmień zawartość komórki tablicy 			--> 3." << endl;
		cout << "Zmień rozmiar tablicy 					--> 4." << endl;
		cout << "Sumuj wartości w kolumnach				--> 5." << endl;
		cout << "Sumuj wartości w wierszach 				--> 6." << endl;
		cout << "Wyświetl najmniejszą i największą wartość w kolumnach   --> 7." << endl;
		cout << "Wyświetl najmniejszą i największą wartość w wierszach   --> 8." << endl;
		cout << "Wyświetl średnią wartość dla kolumn 			--> 9." << endl;
		cout << "Wyświetl średnią wartość dla wierszy 			--> 10." << endl;
		cout << "Zapisz tablicę do pliku 				--> 11." << endl;
		cout << "Wczytaj tablicę z pliku 				--> 12." << endl;
		cout << "Opuść program 						--> 0." << endl;
		cout << "==============================***==============================" << endl;
	
		cout << "Wybierz co chcesz zrobić: ";
		cin >> wybor;
		cout << endl;

		switch(wybor)
		{
			case 1:
				{
					int liczba_kolumn;
					int liczba_wierszy;
					string typ;
					cout << "Podaj typy kolumn np. issi" << endl;
					cout << "(INT: i | STRING: s): ";
					cin >> typ;
					cout << "Podaj liczbę kolumn: ";
					cin >> liczba_kolumn;
					cout << "Podaj liczbę wierszy: ";
					cin >> liczba_wierszy;
					try
					{		
						Tablica* old_arr = arr;						
						arr = new Tablica(liczba_kolumn, liczba_wierszy, typ);
						old_arr->usunTablice();	
					}
					catch(const std::invalid_argument& e) {cout << e.what() << endl;}
				}
				break;
			case 2:
				arr->wyswietlTablice();
				break;
			case 3:
				{				
					int kolumna, wiersz; 
					string zawartosc;
					cout << "Aktualny stan tablicy:" << endl;
					arr->wyswietlTablice();
					cout << "Którą komórkę zmodyfikować?" << endl;
					cout << "Kolumna: ";
					cin >> kolumna;
					cout << "Wiersz: ";
					cin >> wiersz;
					if((kolumna > arr->liczbaKolumn()) || (wiersz > arr->liczbaWierszy())  || (kolumna < 1) || (wiersz < 1))
					{
						cout << "BŁĄD! Współrzędne komórki niezgodne z wymiarem tablicy. " << endl;
						break;
					} 
					else
					{
						cout << "Nowa zawartość: ";
						cin >> zawartosc;
					}
					arr->modyfikujKomorke(kolumna, wiersz, zawartosc);
				}
				break;
			case 4:
				{				
					int mod_kolumny, mod_wiersze, opcja;
					string mod_typ;
					cout << "Nowa liczba kolumn: ";
					cin >> mod_kolumny;
					cout << "Nowa liczba wierszy: ";
					cin >> mod_wiersze;
					cout << "Nowe typy: ";
					cin >> mod_typ;
					if((mod_kolumny < 1) || (mod_wiersze < 1))
					{
						cout << "BŁĄD! Podano rozmiar mniejszy od 1." << endl;
						break;
					}
					if((mod_kolumny == arr->liczbaKolumn()) && (mod_wiersze == arr->liczbaWierszy()))
					{
						cout << "Podano obecny rozmiar." << endl;
						break;
					}
					if((mod_kolumny < arr->liczbaKolumn()) || (mod_wiersze < arr->liczbaWierszy()))
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
						try
						{
						arr->modyfikujRozmiar(mod_kolumny, mod_wiersze, mod_typ);
						}
						catch(const std::invalid_argument& e) {cout << e.what() << endl;}
					}
				}
				break;

			case 5:
				arr->sumowanieKolumny();
				break;
			case 6:
				arr->sumowanieWiersze();
				break;
			case 7:
				arr->ekstremumKolumny();
				break;
			case 8:
				arr->ekstremumWiersze();
				break;
			case 9:
				arr->sredniaKolumny();
				break;
			case 10:
				arr->sredniaWiersze();
				break;
			case 11:
				arr->zapiszTablice();
				cout << "Zapisano!" << endl;
				break;
			case 12:
				arr->wczytajTablice();
				cout << "Wczytywanie zakończone!" << endl;
				break;

			default:
				wybor=0;
				arr->usunTablice();				
				break;
		}		
	}
}
