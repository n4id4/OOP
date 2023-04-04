#include<iostream>
using namespace std;

class Datum {
	int _dan, _mjesec, * _godina = nullptr;

public:
	void Unos(int d, int m, int g)
	{
		SetDan(d);
		SetMjesec(m);
		SetGodina(g);
	}
	void Unos(Datum& datum)
	{
		SetDan(datum.GetDan());
		SetMjesec(datum.GetMjesec());
		SetGodina(datum.GetGodina());
	}
	void Unos(Datum* datum)
	{
		SetDan(datum->GetDan());
		//SetDan((*datum).GetDan());
		SetMjesec(datum->GetMjesec());
		SetGodina(datum->GetGodina());
	}

	int GetDan() { return _dan; }

	int GetMjesec() { return _mjesec; }

	int GetGodina() {
		if (_godina == nullptr)
			return 2023;
		return *_godina;
	}

	void SetDan(int dan) { _dan = dan; }

	void SetMjesec(int mjesec) { _mjesec = mjesec; }

	void SetGodina(int godina)
	{
		if (_godina == nullptr)
			_godina = new int;
		*_godina = godina;
	}
	void Ispis()
	{
		cout << _dan << "." << _mjesec << "." << *_godina;
	}
	void Dealociraj()
	{
		delete _godina;
		_godina = nullptr;
	}
};

class Zanr {
	char _naziv[40];
	char _opis[200]; 
public:
		void Unos(const char* naziv, const char* opis)
		{
			strcpy_s(_naziv, strlen(naziv) + 1, naziv);
			strcpy_s(_opis, strlen(opis) + 1, opis);
		}
		void Unos(Zanr& zanr)
		{
			strcpy_s(_naziv, strlen(zanr._naziv) + 1, zanr._naziv);
			strcpy_s(_opis, strlen(zanr._opis) + 1, zanr._opis);
		}
		void Unos(Zanr* zanr)
		{
			strcpy_s(_naziv, strlen(zanr->_naziv) + 1, zanr->_naziv);
			strcpy_s(_opis, strlen(zanr->_opis) + 1, zanr->_opis);
		}
		void Ispis()
		{
			cout << "Naziv zanra: " << _naziv << endl;
			cout << "Opis: " << _opis << endl;
		}
		void Dealociraj() {}
};

class Knjiga {
	char _naziv[40];
	char _autor[50];
	Zanr* _zanr;
public:
	void Unos(const char* naziv, const char* autor, Zanr zanr)
	{
		strcpy_s(_naziv, strlen(naziv) + 1, naziv);
		strcpy_s(_autor, strlen(autor) + 1, autor);
		_zanr = new Zanr;
		_zanr->Unos(zanr);
	}
	void Unos(Knjiga& knjiga)
	{
		strcpy_s(_naziv, strlen(knjiga._naziv) + 1, knjiga._naziv);
		strcpy_s(_autor, strlen(knjiga._autor) + 1, knjiga._autor);
		_zanr = new Zanr();
		_zanr->Unos(knjiga._zanr);
	}
	void Unos(Knjiga* knjiga)
	{
		strcpy_s(_naziv, strlen(knjiga->_naziv) + 1, knjiga->_naziv);
		strcpy_s(_autor, strlen(knjiga->_autor) + 1, knjiga->_autor);
		_zanr = new Zanr();
		_zanr->Unos(knjiga->_zanr);
	}
	void Ispis()
	{
		cout << "Naziv knjige: " << _naziv << endl;
		cout << "Autor: " << _autor << endl;
		_zanr->Ispis();
	}
	void Dealociraj()
	{
		_zanr->Dealociraj();
		delete _zanr;
		_zanr = nullptr;
	}
};
char* AlocirajTekst(const char* tekst)
{
	if (tekst == nullptr)
		return nullptr;
	int duzina = strlen(tekst) + 1;
	char* temp = new char[duzina];
	strcpy_s(temp, duzina, tekst);
	return temp;
}

class Biblioteka {
	char* _naziv;
	char* _adresa;
	Knjiga* _nizKnjiga;
	int _trenutnoKnjiga;
public:
	void Unos(const char* naziv, const char* adresa)
	{
		_naziv = AlocirajTekst(naziv);
		_adresa = AlocirajTekst(adresa);
		_nizKnjiga = nullptr;
		_trenutnoKnjiga = 0;
	}
	void Ispis()
	{
		cout << "Naziv biblioteke: " << _naziv << endl;
		cout << "Adresa: " << _adresa << endl;
		cout << "Knjige: " << endl;
		for (int i = 0; i < _trenutnoKnjiga; i++)
		{
			_nizKnjiga[i].Ispis();
			cout << "------------------------------------------------------------------------------------------------------------------------\n";
		}
		cout << "Trenutno knjiga: " << _trenutnoKnjiga << endl;

	}

	bool DodajKnjigu(Knjiga k) {
		Knjiga* temp = _nizKnjiga;
		_nizKnjiga = new Knjiga[_trenutnoKnjiga + 1];
		for (int i = 0; i < _trenutnoKnjiga; i++)
			_nizKnjiga[i] = temp[i];
		_nizKnjiga[_trenutnoKnjiga++].Unos(k);
		return true;
	}
	void Dealociraj()
	{
		delete[] _naziv, delete[] _adresa;
		_naziv = _adresa = nullptr;

		for (int i = 0; i < _trenutnoKnjiga; i++)
			_nizKnjiga[i].Dealociraj();

		delete[] _nizKnjiga;
		_nizKnjiga = nullptr;
		_trenutnoKnjiga = 0;
	}
};

int main() {
	const char* crt = "-------------------------------------------------------------------------\n\n";
	Datum d1;
	d1.Unos(28, 3, 2023);

	Zanr* zanrovi = new Zanr[3];
	zanrovi[0].Unos("Realizam", " Realisticku metodu oznacava knjizevnost koja prikazuje stvarnost kakvom je, ali i kakva je moguca prema zakonu vjerojatnosti i nuznosti, odnosno knjizevnost koja je uvjerljiva u odnosu prema objektivnoj stvarnosti.");
	zanrovi[1].Unos("Komedija", "Komedija je vrsta drame koja de odlikuje veselim sadrzajem.");
	zanrovi[2].Unos("Tragedija", "Tragedija je vrsta drame koja se bazira na negativnim dogadjajima sa tragicnim ishodom.");

	Knjiga antigona, aulularia;
	antigona.Unos("Antigona", "Sofoklo", zanrovi[2]);
	aulularia.Unos("Aulularia", "Plaut", zanrovi[1]);


	Biblioteka b;
	b.Unos("Narodna biblioteka Mostar", "Marsala Tita 55");

	b.DodajKnjigu(antigona);
	b.DodajKnjigu(aulularia);

	b.Ispis();

	d1.Dealociraj();

	antigona.Dealociraj();
	aulularia.Dealociraj();

	b.Dealociraj();
	for (int i = 0; i < 3; i++)
		zanrovi[i].Dealociraj();
	delete[] zanrovi;

	system("pause>0");
	return 0;
}
