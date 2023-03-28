#include<iostream>
using namespace std;

class Datum {
	int _dan, _mjesec, * _godina;
public:
	void Unos(int d, int m, int g)
	{
	}
	void Unos(Datum& datum)
	{

	}

	void Ispis()
	{

	}

	void Dealociraj()
	{

	}
};
class Zanr {
	char _naziv[40];
	char _opis[200];
public:
	void Unos(const char* naziv, const char* opis)
	{

	}
	void Unos(Zanr& zanr)
	{

	}
	void Unos(Zanr* zanr)
	{

	}
	void Ispis()
	{

	}
	void Dealociraj()
	{

	}

};
class Knjiga {
	char _naziv[40];
	char _autor[50];
	Zanr* _zanr;
public:
	void Unos(const char* naziv, const char* autor, Zanr* zanr)
	{

	}
	void Unos(Knjiga& knjiga)
	{

	}
	void Unos(Knjiga* knjiga)
	{

	}
	void Ispis()
	{

	}
	void Dealociraj()
	{

	}

};
class Biblioteka {

	char* Naziv;
	char* Adresa;
	Knjiga* nizKnjiga;
	int TrenutnoKnjiga;
public:
	void Unos(const char* naz, const char* adr)
	{

	}
	void Ispis()
	{

	}
	void Dealociraj()
	{

	}
	bool DodajKnjigu(Knjiga k) {

	}
};

int main() {


	system("pause>0");
	return 0;
}
