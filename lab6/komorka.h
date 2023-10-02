#include <string>

using namespace std;
/**
  * Klasa abstraktycjna
  */
class Komorka
{
	public:

		virtual void wczytaj(string wartosc) = 0;

		virtual string zapisz() = 0;	
};

/**
  * Klasa przechowuje informacje o komórce typu INT
  */
class KomorkaInt : public Komorka
{
	public:
		/**
		  * Metoda wczytuje wartość dla komórki typu INT
		  */
		void wczytaj(string wartosc);

		/**
		  * Metoda zapisuje wczytaną wartość dla komórki typu INT
		  */
		string zapisz();
		
		/**
		  * Konstruktor tworzy komórkę przypisując jej wartość 0
		  */
		KomorkaInt()
		{
			wartosc = 0;
		}
	
		/**
		  * Metoda zwraca wartość komórki typu INT
		  */
		int zwrocWartosc()
		{
			return wartosc;
		}

	private:
		/**
		  * @param wartosc  wartość znajdująca się w komórce typu INT
		  */
		int wartosc;
};

/**
  * Klasa przechowuje informacje o komórce typu STRING
  */
class KomorkaString : public Komorka
{
	public:	
		/**
		  * Metoda wczytuje wartość dla komórki typu INT
		  */
		void wczytaj(string wartosc);

		/**
		  * Metoda zapisuje wczytaną wartość dla komórki typu INT
		  */
		string zapisz();
		
		/**
		  * Konstruktor tworzy komórkę przypisując jej wartość "-"
		  */
		KomorkaString()
		{
			wartosc = "-";
		}	

		/**
		  * Metoda zwraca wartość komórki typu INT
		  */
		string zwrocWartosc()
		{
			return wartosc;
		}

	private:
		/**
		  * @param wartosc  wartość znajdująca się w komórce typu STRING
		  */
		string wartosc;
};
