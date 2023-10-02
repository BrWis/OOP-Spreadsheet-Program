#ifndef tablica_h
#define tablica_h
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
  * Struktura przechowuje informacje o tablicy
  *
  * @param tablica  na której wykonywane są operacje
  * @param liczba_kolumn  liczba kolumn tej tablicy
  * @param liczba_wierszy  liczba wierszy tej tablicy
  */
struct Tablica
{
	int** tablica;
	int liczba_kolumn;
	int liczba_wierszy;
};

/**
  * Funkcja tworzy tablice o podanym przez użytkownika wymiarze
  *
  * @param nowa  wskaźnik na zmienną przechowującą informacje o tablicy
  * @param liczba_kolumn  liczba kolumn tablicy
  * @param liczba_wierszy  liczba wierszy tablicy
  *
  * @return  utworzona tablica
  */
void stworzTablice(Tablica* nowa,int liczba_kolumn, int liczba_wierszy);
/**
  * Funkcja zwalnia pamięć usuwając tablicę
  *
  * @param tablica  tablica, która ma zostać usunięta
  */
void usunTablice(Tablica tablica);

/**
  * Funkcja wczytuje tablicę z pliku
  *
  * @param tablica  wskaźnik na zmienną przechowującą informacje o tablicy
  */
void wczytajTablice(Tablica* tablica);

/**
  * Funkcja zapisuje tablicę do pliku
  *
  * @param tablica  zmienna przechowująca informacje o tablicy
  */
void zapiszTablice(Tablica tablica);

/**
  * Funkcja wyświetla zawartość tablicy
  *
  * @param tablica  zmienna przechowująca informacje o tablicy
  */
void wyswietlTablice(Tablica tablica);

/**
  * Funkcja zmienia zawartość wybranej komórki
  *
  * @param tablica  wskaźnik na zmienną przechowującą informacje o tablicy
  * @param wyb_kolumna  numer kolumny, w której jest modyfikowna komórka
  * @param wyb_wiersz  numer wiersza, w ktorym jest modyfikowana komórka
  * @param nowa_zawaratosc  wartość, która zostatnie wpisana do wybranej komórki
  */
void modyfikujKomorke(Tablica* tablica, int wyb_kolumna, int wyb_wiersz, int nowa_zawaratosc);

/**
  * Funkcja zmienia rozmiar podanej tablicy
  *
  * @param tablica  wskaźnik na zmienną przechowującą informacje o tablicy
  * @param nowy_kolumny  liczba kolumn nowej tablicy
  * @param nowy_wiersze  liczba wierszy nowej tablicy
  */
void modyfikujRozmiar(Tablica* tablica, int nowy_kolumny, int nowy_wiersze);

/**
  * Funkcja sumuje zawartość kolumn w tablicy i wypisuje sumy
  *
  * @param tablica  zmienna przechowująca informacje o tablicy
  */
void sumowanieKolumny(Tablica tablica);

/**
  * Funkcja sumuje zawartość wierszy w tablicy i wypisuje sumy
  *
  * @param tablica  zmienna przechowująca informacje o tablicy
  */
void sumowanieWiersze(Tablica tablica);

/**
  * Funkcja wypisuje minumum i maksimum dla każdej z kolumn w tablicy
  *
  * @param tablica  zmienna  przechowująca informacje o tablicy
  */
void ekstremumKolumny(Tablica tablica);

/**
  * Funkcja wypisuje minumum i maksimum dla każdego z wierszy w tablicy
  *
  * @param tablica  zmienna  przechowująca informacje o tablicy
  */
void ekstremumWiersze(Tablica tablica);

/**
  * Funkcja oblicza wartość średnią każdej kolumny w tablicy i ją wypisuje 
  *
  * @param tablica  zmienna  przechowujaca informacje o tablicy
  */
void sredniaKolumny(Tablica tablica);

/**
  * Funkcja oblicza wartość średnią każdego wiersza w tablicy i ją wypisuje 
  *
  * @param tablica  zmienna  przechowujaca informacje o tablicy
  */
void sredniaWiersze(Tablica tablica);

#endif
