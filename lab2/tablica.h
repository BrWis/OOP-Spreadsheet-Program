#ifndef tablica_h
#define tablica_h
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
  * Funkcja tworzy tablice o podanym przez użytkownika wymiarze
  *
  * @param liczba_kolumn  liczba kolumn tworzonej tablicy
  * @param liczba_wierszy  liczba wierszy tworzonej tablicy
  *
  * @return  utworzona tablica
  */
int** stworzTablice(int liczba_kolumn, int liczba_wierszy);
/**
  * Funkcja zwalnia pamięć
  *
  * @param tablica  tablica, która ma zostać usunięta
  * @param liczba_kolumn  liczba kolumn tej tablicy
  */
void usunTablice(int** tablica, int liczba_kolumn);

/**
  * Funkcja wczytuje tablicę z pliku
  *
  * @param liczba_kolumn  aktualna liczba kolumn, wartość zostanie wczytana z pliku
  * @param liczba_wierszy  aktualna liczba wierszy, wartość zostanie wczytana z pliku
  *
  * @return  tablica utworzona z danych odczytanych z pliku
  */
int** wczytajTablice(int* liczba_kolumn, int* liczba_wierszy);

/**
  * Funkcja zapisuje tablicę do pliku
  *
  * @param tablica  tablica, która ma zostać zapisana
  * @param liczba_kolumn  liczba kolumn tej tablicy
  * @param liczba_wierszy  liczba wierszy tej tablicy
  */
void zapiszTablice(int** tablica, int* liczba_kolumn, int* liczba_wierszy);

/**
  * Funkcja wyświetla zawartość tablicy
  *
  * @param tablica  tablica, która ma zostać wyświetlona
  * @param liczba_kolumn  liczba kolumn tej tablicy
  * @param liczba_wierszy  liczba wierszy tej tablicy
  */
void wyswietlTablice(int** tablica, int liczba_kolumn, int liczba_wierszy);

/**
  * Funkcja zmienia zawartość danej komórki
  *
  * @param tablica  tablica, ktora ma zostać zmodyfikowana
  * @param wyb_kolumna  numer kolumny, w której jest szukana komórka
  * @param wyb_wiersz  numer wiersza, w ktorym jest szukana komórka
  * @param liczba_kolumn  liczba kolumn tej tablicy
  * @param liczba_wierszy  liczba wierszy tej tablicy
  * @param nowa_zawaratosc  wartość, która zostatnie wpisana do wybranej komórki
  */
void modyfikujKomorke(int** tablica, int wyb_kolumna, int wyb_wiersz, int liczba_kolumn, int liczba_wierszy, int nowa_zawaratosc);

/**
  * Funkcja zmienia rozmiar podanej tablicy
  *
  * @param tablica  tablica, której rozmiar zmieniamy
  * @param rozm_kolumny  liczba kolumn tablicy
  * @param rozm_wiersze  liczba wierszy tablicy
  * @param nowy_kolumny  liczba kolumn nowej tablicy
  * @param nowy_wiersze  liczba wierszy nowej tablicy
  *
  * @return tablica o nowym rozmiarze
  */
int** modyfikujRozmiar(int** tablica, int* rozm_kolumny, int* rozm_wiersze, int nowy_kolumny, int nowy_wiersze);

#endif
