#include "menu.h"
#include "tablica.h"


int main()
{
	int** tablica;
	int liczba_kolumn = 0;
	int liczba_wierszy = 0;
	tablica = stworzTablice(liczba_kolumn, liczba_wierszy);
	drukujMenu(tablica, &liczba_kolumn, &liczba_wierszy);

	return 0;
}
