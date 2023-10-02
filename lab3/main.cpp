#include "menu.h"
#include "tablica.h"


int main()
{
	Tablica* tablica = new Tablica;
	stworzTablice(tablica, 0, 0);
	drukujMenu(tablica);

	return 0;
}
