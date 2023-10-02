#include <string>

using namespace std;
class Komorka
{
	public:
		virtual void wczytaj(string wartosc) = 0;
		virtual string zapisz() = 0;	
};

class KomorkaInt : public Komorka
{
	public:
		void wczytaj(string wartosc);
		string zapisz();
		int zwrocWartosc()
		{
			return wartosc;
		}

		KomorkaInt()
		{
			wartosc = 0;
		}	

		private:
			int wartosc;
};

class KomorkaString : public Komorka
{
	public:	
		void wczytaj(string wartosc);
		string zapisz();
		KomorkaString()
		{
			wartosc = "-";
		}	

		private:
			string wartosc;
};
