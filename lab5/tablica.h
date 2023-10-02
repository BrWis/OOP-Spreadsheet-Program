#ifndef tablica_h
#define tablica_h
#include <iostream>
#include <fstream>
#include <string>
#include "komorka.h"
using namespace std;

/**
  * Klasa przechowuje informacje o tablicy
  *
  * @param tablica  na której wykonywane są operacje
  * @param liczba_kolumn  liczba kolumn tej tablicy
  * @param liczba_wierszy  liczba wierszy tej tablicy
  */
class Tablica
{
	private:
		Komorka*** tablica;
		int liczba_kolumn;
		int liczba_wierszy;
		string typ;
	public:
		/**
		  * Konstruktor domyślny, przypisuje domyślnie wymiary tablicy 0x0
		  *
		  * @param liczba_kolumn  liczba kolumn utworzonej tablicy
		  * @param liczba_wierszy  liczba wierszy utworzonej tablicy
		  */
		Tablica(int liczba_kolumn = 0, int liczba_wierszy = 0, string typ = "i")
		{
			this->liczba_kolumn = liczba_kolumn;
			this->liczba_wierszy = liczba_wierszy;
			this->typ = typ;
			stworzTablice();
		}

		/**
 		 * Metoda tworzy tablice o podanym przez użytkownika wymiarze
  		*/
		void stworzTablice();

		/**
		  * Metoda zwraca liczbę kolumn tablicy
		  */		
		int liczbaKolumn();
		
		/**
		  * Metoda zwraca liczbę wierszy tablicy
		  */
		int liczbaWierszy();
		
		/**
 		 * Metoda zwalnia pamięć usuwając tablicę
  		*/
		void usunTablice();

		/**
 		 * Metoda wczytuje tablicę z pliku
 		 */
		void wczytajTablice();

		/**
 		 * Metoda zapisuje tablicę do pliku
 		 */
		void zapiszTablice();
	
		/**
 		 * Metoda wyświetla zawartość tablicy
 		 */
		void wyswietlTablice();

		/**
 		 * Metoda zmienia zawartość wybranej komórki
 		 *
 		 * @param wyb_kolumna  numer kolumny, w której jest modyfikowna komórka
		 * @param wyb_wiersz  numer wiersza, w ktorym jest modyfikowana komórka
 		 * @param nowa_zawaratosc  wartość, która zostatnie wpisana do wybranej komórki
		 */
		void modyfikujKomorke(int wyb_kolumna, int wyb_wiersz, string nowa_zawaratosc);

		/**
  		 * Metoda zmienia rozmiar podanej tablicy
 		 *
 		 * @param nowy_kolumny  liczba kolumn nowej tablicy
 		 * @param nowy_wiersze  liczba wierszy nowej tablicy
 		 */
		void modyfikujRozmiar(int nowy_kolumny, int nowy_wiersze);

		/**
		  * Metoda sumuje zawartość kolumn w tablicy i wypisuje sumy
		  */
		void sumowanieKolumny();

		/**
		  * Metoda sumuje zawartość wierszy w tablicy i wypisuje sumy
		  */
		void sumowanieWiersze();

		/**
		  * Metoda wypisuje minumum i maksimum dla każdej z kolumn w tablicy
		  */
		void ekstremumKolumny();

		/**
		  * Metoda wypisuje minumum i maksimum dla każdego z wierszy w tablicy
		  */
		void ekstremumWiersze();

		/**
		  * Metoda oblicza wartość średnią każdej kolumny w tablicy i ją wypisuje 
		  */
		void sredniaKolumny();

		/**
		  * Metoda oblicza wartość średnią każdego wiersza w tablicy i ją wypisuje 
		  */
		void sredniaWiersze();

};

#endif
