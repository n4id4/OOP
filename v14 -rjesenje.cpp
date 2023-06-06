#include<iostream>
#include<string>
#include<vector>
using namespace std;
//Z0.1
template<class T>
T* Alociraj() {
	return new T;
}
//Z0.2
template<class T>
T* Alociraj(T element) {
	return new T(element);
}
//Z0.3
template<class T>
T* Alociraj(T* pok) {
	if (pok == nullptr)
		return nullptr;
	return new T(*pok);
}

class Datum {
private:
	int* _dan, * _mjesec, * _godina;
public:
	//Z1.1
	Datum() { _dan = _mjesec = _godina = nullptr; }
	//Z1.2
	Datum(int d, int m, int g) {
		_dan = Alociraj<int>(d);
		_mjesec = Alociraj<int>(m);
		_godina = Alociraj<int>(g);
	}
	//Z1.3
	Datum(const Datum& obj) {
		_dan = Alociraj<int>(obj._dan);
		_mjesec = Alociraj<int>(obj._mjesec);
		_godina = Alociraj<int>(obj._godina);
	}
	//Z1.4
	Datum& operator=(const Datum& datum) {
		if (this != &datum) {
			delete _dan, _mjesec, _godina;
			_dan = Alociraj<int>(datum._dan);
			_mjesec = Alociraj<int>(datum._mjesec);
			_godina = Alociraj<int>(datum._godina);
		}
		return *this;
	}
	//Z1.5
	void SetDan(int dan) {
		delete _dan;
		_dan = Alociraj<int>(dan);
	}
	void SetMjesec(int mjesec) {
		delete _mjesec;
		_mjesec = Alociraj<int>(mjesec);
	}
	void SetGodina(int godina) {
		delete _godina;
		_godina = Alociraj<int>(godina);
	}
	//Z1.6
	int GetDan() { return *_dan; }
	int GetMjesec() { return *_mjesec; }
	int GetGodina() { return *_godina; }
	~Datum() {
		delete _dan, _mjesec, _godina;
		_dan = _mjesec = _godina = nullptr;
	}
	friend ostream& operator <<(ostream& COUT, const Datum& datum);
};
//Z1.7
ostream& operator <<(ostream& COUT, const Datum& datum) {
	COUT << *datum._dan << "." << *datum._mjesec << "." << *datum._godina << endl;
	return COUT;
}
class Osoba {
protected:
	string _ime;
	string _prezime;
	Datum _datumRodjenja;
	string _mjestoRodjenja; //Grad, Drzava
	bool _spol;
	float _visina; // npr. 1.75 m
public:
	//Z2.1
	Osoba() :
		_ime(""),
		_prezime(""),
		_mjestoRodjenja("")
	{
		_spol = true;
		_visina = 0;
	}
	//Z2.2
	Osoba(const char* ime, const char* prezime, Datum datumR, string mjestoRodjenja, float visina, bool spol) :
		_ime(ime),
		_prezime(prezime),
		_datumRodjenja(datumR),
		_mjestoRodjenja(mjestoRodjenja)
	{
		_visina = visina;
		_spol = spol;
	}
	//Z2.3
	Osoba(const Osoba& osoba) :
		_ime(osoba._ime),
		_prezime(osoba._prezime),
		_datumRodjenja(osoba._datumRodjenja),
		_mjestoRodjenja(osoba._mjestoRodjenja)
	{
		_visina = osoba._visina;
		_spol = osoba._spol;
	}
	//Z2.4
	Osoba& operator = (const Osoba& osoba) {
		_ime = osoba._ime;
		_prezime = osoba._prezime;
		_datumRodjenja = osoba._datumRodjenja;
		_mjestoRodjenja = osoba._mjestoRodjenja;
		_visina = osoba._visina;
		_spol = osoba._spol;
		return *this;
	}
	//Z2.5
	string GetIme() { return _ime; }
	string GetPrezime() { return _prezime; }
	Datum GetDatumRodjenja() { return _datumRodjenja; }
	string GetMjestoRodjenja() { return _mjestoRodjenja; }
	float GetVisina() { return _visina; }
	bool GetSpol() { return _spol; }
	//Z2.6
	void SetIme(const char* ime) { _ime = ime; }
	void SetPrezime(const char* prezime) { _prezime = prezime; }
	void SetDatumRodjenja(Datum datum) {
		_datumRodjenja = datum;
	}
	void SetMjestoRodjenja(const char* mjestoR) { _mjestoRodjenja = mjestoR; }
	void SetVisina(float visina) { _visina = visina; }
	void SetSpol(bool spol) { _spol = spol; }
	~Osoba() {
	}
	friend ostream& operator <<(ostream& COUT, const Osoba& osoba);
};
//Z2.7
ostream& operator <<(ostream& COUT, const Osoba& osoba) {
	COUT << "Ime i prezime: " << osoba._ime << " " << osoba._prezime << endl;
	COUT << "Datum rodjenja: ";
	COUT << osoba._datumRodjenja;
	COUT << "Spol:" << (osoba._spol ? "Muski" : "Zenski") << endl;
	COUT << "Mjesto rodjenja: " << osoba._mjestoRodjenja << endl;
	COUT << "Visina: " << osoba._visina << endl;
	return COUT;
}
class Fudbaler : public Osoba {
private:
	string _pozicija; //pozicija na terenu
public:
	//Z3.1
	Fudbaler() :
		_pozicija("")
	{
	}
	//Z3.2
	Fudbaler(const char* ime, const char* prezime, Datum datumR, string mjestoRodjenja, float visina, bool spol, string pozicija) :
		Osoba(ime, prezime, datumR, mjestoRodjenja, visina, spol),
		_pozicija(pozicija)
	{
	}
	//Z3.3
	Fudbaler(const Fudbaler& fudbaler) :
		Osoba(fudbaler),
		_pozicija(fudbaler._pozicija)
	{
	}
	//Z3.4
	Fudbaler& operator =(const Fudbaler& fudbaler) {
		Osoba::operator=(fudbaler);
		_pozicija = fudbaler._pozicija;
		return *this;
	}
	//Z3.5
	string GetPozicija() { return _pozicija; }
	void SetPozicija(const char* pozicija) { _pozicija = pozicija; }
	~Fudbaler() {}
	friend ostream& operator<<(ostream& COUT, const Fudbaler& fudbaler);
};

//Z3.6 :: Ispisati ime i prezime fudbalera te poziciju na terenu
ostream& operator<<(ostream& COUT, const Fudbaler& fudbaler) {
	COUT << "Ime i prezime: " << fudbaler._ime << " " << fudbaler._prezime << endl;
	COUT << "Pozicija: " << fudbaler._pozicija << endl;
	return COUT;
}

class FudbalskiTim {
private:
	string _naziv;
	Datum _datumOsnivanja;
	string _domaciStadion;
	vector<Fudbaler> _fudbaleri;
public:
	//Z4.1
	FudbalskiTim() :
		_naziv(""),
		_domaciStadion("")
	{
	}
	//Z4.2
	FudbalskiTim(const char* naziv, Datum datumO, const char* domaciStadion) :
		_naziv(naziv),
		_datumOsnivanja(datumO),
		_domaciStadion(domaciStadion)
	{
	}
	//Z4.3
	FudbalskiTim(const FudbalskiTim& obj) :
		_naziv(obj._naziv),
		_datumOsnivanja(obj._datumOsnivanja),
		_domaciStadion(obj._domaciStadion),
		_fudbaleri(obj._fudbaleri)
	{
	}
	//Z4.4
	FudbalskiTim& operator =(const FudbalskiTim& fudbalskiTim) {
		_naziv = fudbalskiTim._naziv;
		_datumOsnivanja = fudbalskiTim._datumOsnivanja;
		_domaciStadion = fudbalskiTim._domaciStadion;
		_fudbaleri = fudbalskiTim._fudbaleri;
		return *this;
	}
	//Z4.5
	string GetNaziv() { return _naziv; }
	Datum GetDatumOsnivanja() { return _datumOsnivanja; }
	string GetDomaciStadion() { return _domaciStadion; }
	int GetTrenutnoFudbalera() { return _fudbaleri.size(); }
	//Z4.6
	void SetNaziv(const char* naziv) { _naziv = naziv; }
	void SetDatumOsnivanja(Datum datum) { _datumOsnivanja = datum; }
	void SetDomaciStadion(const char* domaciStadion) { _domaciStadion = domaciStadion; }
	//Z4.7
	void DodajFudbalera(Fudbaler* f) {
		_fudbaleri.push_back(*f);
	}
	~FudbalskiTim() {
	}
	friend ostream& operator << (ostream& COUT, const FudbalskiTim& tim);
};
//Z4.8
ostream& operator << (ostream& COUT, const FudbalskiTim& tim) {
	COUT << "Naziv: " << tim._naziv << endl;
	COUT << "Datum osnivanja: " << tim._datumOsnivanja;
	COUT << "Domaci stadion: " << tim._domaciStadion << endl;
	COUT << "Trenutno fudbalera: " << tim._fudbaleri.size() << endl;
	cout << endl;
	for (size_t i = 0; i < tim._fudbaleri.size(); i++)
		COUT << tim._fudbaleri[i];
	return COUT;
}

class Utakmica {
private:
	FudbalskiTim* _domacin;
	FudbalskiTim* _gosti;
	int _goloviDomacin;
	int _goloviGosti;
	vector<string> _postigliGolove;
public:
	//Z5.1
	Utakmica() {
		_goloviDomacin = _goloviGosti = 0;
		_domacin = _gosti = nullptr;
	}
	//Z5.2
	Utakmica(FudbalskiTim* domacin, FudbalskiTim* gosti) {
		_goloviDomacin = _goloviGosti = 0;
		_domacin = Alociraj<FudbalskiTim>(domacin);
		_gosti = Alociraj<FudbalskiTim>(gosti);
	}
	//Z5.3
	Utakmica(const Utakmica& obj) :
		_postigliGolove(obj._postigliGolove)
	{
		_goloviDomacin = obj._goloviDomacin;
		_goloviGosti = obj._goloviGosti;
		_domacin = Alociraj<FudbalskiTim>(obj._domacin);
		_gosti = Alociraj<FudbalskiTim>(obj._gosti);
	}
	//Z5.4
	Utakmica& operator = (const Utakmica& obj) {
		if (this != &obj) {
			delete _domacin, _gosti;
			_domacin = Alociraj<FudbalskiTim>(obj._domacin);
			_gosti = Alociraj<FudbalskiTim>(obj._gosti);
			_goloviDomacin = obj._goloviDomacin;
			_goloviGosti = obj._goloviGosti;
			_postigliGolove = obj._postigliGolove;
		}
		return *this;
	}
	//Z5.5
	FudbalskiTim GetDomacin() { return *_domacin; }
	FudbalskiTim GetGosti() { return *_gosti; }
	int GetBrojGolovaDomacina() { return  _goloviDomacin; }
	int GetBrojGolovaGostiju() { return _goloviGosti; }
	vector<string> GetPostigliGolove() { return _postigliGolove; }
	//Z5.6
	void SetDomacin(FudbalskiTim* domacin) {
		delete _domacin;
		_domacin = Alociraj<FudbalskiTim>(domacin);
	}
	void SetGosti(FudbalskiTim* gosti) {
		delete _gosti;
		_gosti = Alociraj<FudbalskiTim>(gosti);
	}

	//Z5.7 Upisati gol u sljedecem formatu
	// Ime i prezime igraca [Naziv kluba] minuta
	//Ako je jedan igrac postigao vise golova, onda postaviti minutu novog postignutog gola na kraj postojeceg zapisa
	void DodajGol(bool golZa, Fudbaler* fudbaler, int minuta) {
		if (golZa)
			_goloviDomacin++;
		else
			_goloviGosti++;
		string nazivTima = (golZa ? _domacin->GetNaziv() : _gosti->GetNaziv());
		string imePrezime = fudbaler->GetIme() + " " + fudbaler->GetPrezime();
		for (size_t i = 0; i < _postigliGolove.size(); i++)
			if (_postigliGolove[i].find(imePrezime) != string::npos) {
				_postigliGolove[i].append(", " + to_string(minuta));
				return;
			}
		_postigliGolove.push_back(imePrezime + " [" + nazivTima + "] " + to_string(minuta));
	}
	//Z5.8
	~Utakmica() {
		delete _domacin, _gosti;
		_domacin = _gosti = nullptr;
	}
	friend ostream& operator << (ostream& COUT, const Utakmica& utakmica);
};
//Z5.9
ostream& operator << (ostream& COUT, const Utakmica& utakmica) {
	COUT << utakmica._domacin->GetNaziv() << " - " << utakmica._gosti->GetNaziv()
		<< " [" << utakmica._goloviDomacin << ":" << utakmica._goloviGosti << "]" << endl;
	return COUT;
}
void Zadatak1() {
	Datum prviMaj(1, 5, 2020), novaGodina(1, 1, 2020), prviApril(novaGodina), danNezavisnosti(novaGodina);
	prviMaj = Datum(1, 5, 2020);
	danNezavisnosti.SetMjesec(3), prviApril.SetMjesec(4);
	vector<Datum> datumiVektor;
	datumiVektor.push_back(danNezavisnosti);
	datumiVektor.push_back(prviApril);
	datumiVektor.push_back(prviMaj);
	datumiVektor.push_back(Datum(1, 6, 2020));
	for (vector<Datum>::iterator it = datumiVektor.begin(); it < datumiVektor.end(); it++)
		cout << *it;
}
void Zadatak2() {
	Osoba louis("Louis", "Neighbors", Datum(1, 10, 1995), "Mostar, BiH", 1.73, 1);
	Osoba kash("Kash", "Register", Datum(2, 10, 1995), "Mostar, BiH", 1.74, 1);
	Osoba jack("Jack", "Daniels", Datum(3, 10, 1995), "Mostar, BiH", 1.75, 1);
	Osoba o1(louis), o2(kash), o3;
	o3 = jack;
	vector<Osoba> osobe;
	osobe.push_back(o1);
	osobe.push_back(o2);
	osobe.push_back(o3);
	for (vector<Osoba>::iterator it = osobe.begin(); it < osobe.end(); it++)
		cout << *it << endl;
}
void Zadatak3() {
	Fudbaler indyNeidell("Indy", "Neidell", Datum(3, 3, 1978), "Houston, Teksas (SAD)", 1.76, 1, "Napadac");
	Fudbaler threeBlueOneBrown("Grant", "Sanderson", Datum(4, 4, 1985), "Chicago, Illinois (SAD)", 1.85, 1, "Odbrana");
	Fudbaler euler("Leonhard", "Euler", Datum(11, 4, 1707), "Basel, Svicarska", 1.72, 1, "Golman");
	Fudbaler elonMusk("Elon", "Musk", Datum(28, 6, 1971), "Pretoria, South Africa", 1.73, 1, "Veznjak");
	Fudbaler michioKaku("Michio", "Kaku", Datum(23, 6, 1956), "San Jose, Kalifornija (SAD)", 1.70, 1, "Veznjak");

	Fudbaler f1(indyNeidell), f2(threeBlueOneBrown), f3(euler), f4(elonMusk), f5;
	f5 = michioKaku;
	vector<Fudbaler> neverWokAlone;
	neverWokAlone.push_back(f1);
	neverWokAlone.push_back(f2);
	neverWokAlone.push_back(f3);
	neverWokAlone.push_back(f4);
	neverWokAlone.push_back(f5);
	for (vector<Fudbaler>::iterator it = neverWokAlone.begin(); it < neverWokAlone.end(); it++)
		cout << *it;
}
void Zadatak4() {
	Fudbaler alanTuring("Alan", "Turing", Datum(2, 2, 1966), "London, UK", 1.71, 1, "Golman");
	Fudbaler louisCK("Louis", "C.K", Datum(2, 2, 1967), "Miami, Florida", 1.72, 1, "Odbrana");
	Fudbaler gandhi("Mohandas", "Gandhi", Datum(2, 2, 1967), "Miami, Florida", 1.72, 1, "Odbrana");
	Fudbaler jordanPeterson("Jordan", "Peterson", Datum(3, 3, 1968), "Toronto, Kanada", 1.73, 1, "Veznjak");
	Fudbaler markManson("Mark", "Manson", Datum(4, 4, 1969), "Toronto, Kanada", 1.74, 1, "Veznjak");
	Fudbaler dalaiLama("Lhamo", "Thondup", Datum(5, 5, 1970), "McLeod Ganj, India", 1.74, 1, "Napadac");

	FudbalskiTim bacunaMatata("Bacuna Matata", Datum(3, 2, 1900), "Tartaruga Stadium");
	bacunaMatata.DodajFudbalera(&alanTuring);
	bacunaMatata.DodajFudbalera(&louisCK);
	bacunaMatata.DodajFudbalera(&gandhi);
	bacunaMatata.DodajFudbalera(&jordanPeterson);
	bacunaMatata.DodajFudbalera(&markManson);
	bacunaMatata.DodajFudbalera(&dalaiLama);
	FudbalskiTim tim1(bacunaMatata);
	FudbalskiTim tim2(tim1);
	bacunaMatata = tim2;
	cout << bacunaMatata;
}
void Zadatak5() {
	//===================================FUDBALSKI TIM 1 =========================================================
	Fudbaler indyNeidell("Indy", "Neidell", Datum(3, 3, 1978), "Houston, Teksas (SAD)", 1.76, 1, "Napadac");
	Fudbaler threeBlueOneBrown("Grant", "Sanderson", Datum(4, 4, 1985), "Chicago, Illinois (SAD)", 1.85, 1, "Odbrana");
	Fudbaler euler("Leonhard", "Euler", Datum(11, 4, 1707), "Basel, Svicarska", 1.72, 1, "Golman");
	Fudbaler elonMusk("Elon", "Musk", Datum(28, 6, 1971), "Pretoria, South Africa", 1.73, 1, "Veznjak");
	Fudbaler michioKaku("Michio", "Kaku", Datum(23, 6, 1956), "San Jose, Kalifornija (SAD)", 1.70, 1, "Veznjak");
	Fudbaler trump("Donald J.", "Trump", Datum(24, 6, 1957), "New York City, New York(SAD)", 1.73, 1, "Napadac");

	FudbalskiTim ayewReady("Ayew Ready", Datum(2, 2, 1900), "Fort Saint Actione");
	ayewReady.DodajFudbalera(&indyNeidell);
	ayewReady.DodajFudbalera(&threeBlueOneBrown);
	ayewReady.DodajFudbalera(&euler);
	ayewReady.DodajFudbalera(&elonMusk);
	ayewReady.DodajFudbalera(&michioKaku);
	ayewReady.DodajFudbalera(&trump);
	//===================================FUDBALSKI TIM 2 =========================================================
	Fudbaler alanTuring("Alan", "Turing", Datum(2, 2, 1966), "London, UK", 1.71, 1, "Golman");
	Fudbaler louisCK("Louis", "C.K", Datum(2, 2, 1967), "Miami, Florida", 1.72, 1, "Odbrana");
	Fudbaler gandhi("Mohandas", "Gandhi", Datum(2, 2, 1967), "Miami, Florida", 1.72, 1, "Odbrana");
	Fudbaler jordanPeterson("Jordan", "Peterson", Datum(3, 3, 1968), "Toronto, Kanada", 1.73, 1, "Veznjak");
	Fudbaler markManson("Mark", "Manson", Datum(4, 4, 1969), "Toronto, Kanada", 1.74, 1, "Veznjak");
	Fudbaler dalaiLama("Lhamo", "Thondup", Datum(5, 5, 1970), "McLeod Ganj, India", 1.74, 1, "Napadac");

	FudbalskiTim bacunaMatata("Bacuna Matata", Datum(3, 2, 1900), "Tartaruga Stadium");
	bacunaMatata.DodajFudbalera(&alanTuring);
	bacunaMatata.DodajFudbalera(&louisCK);
	bacunaMatata.DodajFudbalera(&gandhi);
	bacunaMatata.DodajFudbalera(&jordanPeterson);
	bacunaMatata.DodajFudbalera(&markManson);
	bacunaMatata.DodajFudbalera(&dalaiLama);
	//===================================UTAKMICA =======================================================
	Utakmica clashOfTheTitans;
	clashOfTheTitans.SetDomacin(&ayewReady);
	clashOfTheTitans.SetGosti(&bacunaMatata);
	clashOfTheTitans.DodajGol(1, &trump, 5);
	clashOfTheTitans.DodajGol(0, &dalaiLama, 11);
	clashOfTheTitans.DodajGol(1, &trump, 23);
	clashOfTheTitans.DodajGol(1, &euler, 37);
	clashOfTheTitans.DodajGol(0, &gandhi, 81);
	clashOfTheTitans.DodajGol(0, &gandhi, 90);
	Utakmica u2(clashOfTheTitans);
	Utakmica u3(u2);
	Utakmica gameOfTheCentury;
	gameOfTheCentury = u3;
	cout << gameOfTheCentury << endl;
	vector<string> postignutiGolovi = gameOfTheCentury.GetPostigliGolove();
	for (size_t i = 0; i < postignutiGolovi.size(); i++)
		cout << postignutiGolovi[i] << endl;
}
void main() {
	bool nastaviDalje = true;
	while (nastaviDalje) {
		int izbor = 0;
		do {
			system("cls");
			cout << "::Zadaci::" << endl;
			cout << "(1) Zadatak 1" << endl;
			cout << "(2) Zadatak 2" << endl;
			cout << "(3) Zadatak 3" << endl;
			cout << "(4) Zadatak 4" << endl;
			cout << "(5) Zadatak 5" << endl;
			cout << "Unesite broj za testiranje zadatka: -->: ";
			cin >> izbor;
			cout << endl;
		} while (izbor <= 0 || izbor > 6);
		switch (izbor) {
		case 1: Zadatak1(); cout << "Done." << endl; break;
		case 2: Zadatak2(); cout << "Done." << endl; break;
		case 3: Zadatak3(); cout << "Done." << endl; break;
		case 4: Zadatak4(); cout << "Done." << endl; break;
		case 5: Zadatak5(); cout << "Done." << endl; break;
		default:break;
		}
		cout << "DA LI ZELITE NASTAVITI DALJE? (1/0): ";
		cin >> nastaviDalje;
	}
}
