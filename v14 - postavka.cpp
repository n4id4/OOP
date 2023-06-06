#include<iostream>
#include<string>
#include<vector>
using namespace std;
//Z0.1
template<class T>
T* Alociraj();
//Z0.2
template<class T>
T* Alociraj(T element);
//Z0.3
template<class T>
T* Alociraj(T* pok);

class Datum {
private:
	int* _dan, * _mjesec, * _godina;
public:
	//Z1.1
	Datum();
	//Z1.2
	Datum(int d, int m, int g);
	//Z1.3
	Datum(const Datum& obj);
	//Z1.4
	Datum& operator=(const Datum&);
	//Z1.5
	void SetDan(int);
	void SetMjesec(int);
	void SetGodina(int);
	//Z1.6
	int GetDan();
	int GetMjesec();
	int GetGodina();
	~Datum();
};
//Z1.7
ostream& operator <<(ostream& COUT, const Datum&);

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
	Osoba();
	//Z2.2
	Osoba(const char* ime, const char* prezime, Datum datumR, string mjestoRodjenja, float visina, bool spol);
	//Z2.3
	Osoba(const Osoba&);
	//Z2.4
	Osoba& operator = (const Osoba&);
	//Z2.5
	string GetIme();
	string GetPrezime();
	Datum GetDatumRodjenja();
	string GetMjestoRodjenja();
	float GetVisina();
	bool GetSpol();
	//Z2.6
	void SetIme(const char* ime);
	void SetPrezime(const char* prezime);
	void SetDatumRodjenja(Datum);
	void SetMjestoRodjenja(const char* mjestoR);
	void SetVisina(float visina);
	void SetSpol(bool spol);
	~Osoba();
};
//Z2.7
ostream& operator <<(ostream& COUT, const Osoba&);

class Fudbaler : public Osoba {
private:
	string _pozicija; //pozicija na terenu
public:
	//Z3.1
	Fudbaler();
	//Z3.2
	Fudbaler(const char* ime, const char* prezime, Datum datumR, string mjestoRodjenja, float visina, bool spol, string pozicija);
	//Z3.3
	Fudbaler(const Fudbaler& fudbaler);
	//Z3.4
	Fudbaler& operator =(const Fudbaler&);
	//Z3.5
	string GetPozicija();
	void SetPozicija(const char* pozicija);
	~Fudbaler();
};
//Z3.6 :: Ispisati ime i prezime fudbalera te poziciju na terenu
ostream& operator<<(ostream& COUT, const Fudbaler&);

class FudbalskiTim {
private:
	string _naziv;
	Datum _datumOsnivanja;
	string _domaciStadion;
	vector<Fudbaler> _fudbaleri;
public:
	//Z4.1
	FudbalskiTim();
	//Z4.2
	FudbalskiTim(const char* naziv, Datum datumO, const char* domaciStadion);
	//Z4.3
	FudbalskiTim(const FudbalskiTim& obj);
	//Z4.4
	FudbalskiTim& operator =(const FudbalskiTim&);
	//Z4.5
	string GetNaziv();
	Datum GetDatumOsnivanja();
	string GetDomaciStadion();
	int GetTrenutnoFudbalera();
	//Z4.6
	void SetNaziv(const char* naziv);
	void SetDatumOsnivanja(Datum datum);
	void SetDomaciStadion(const char* domaciStadion);
	//Z4.7
	void DodajFudbalera(Fudbaler*);
	~FudbalskiTim();
};
//Z4.8
ostream& operator << (ostream& COUT, const FudbalskiTim&);

class Utakmica {
private:
	FudbalskiTim* _domacin;
	FudbalskiTim* _gosti;
	int _goloviDomacin;
	int _goloviGosti;
	vector<string> _postigliGolove;
public:
	//Z5.1
	Utakmica();
	//Z5.2
	Utakmica(FudbalskiTim* domacin, FudbalskiTim* gosti);
	//Z5.3
	Utakmica(const Utakmica&);
	//Z5.4
	Utakmica& operator = (const Utakmica&);
	//Z5.5
	FudbalskiTim GetDomacin();
	FudbalskiTim GetGosti();
	int GetBrojGolovaDomacina();
	int GetBrojGolovaGostiju();
	vector<string> GetPostigliGolove();
	//Z5.6
	void SetDomacin(FudbalskiTim*);
	void SetGosti(FudbalskiTim*);

	//Z5.7 Upisati gol u sljedecem formatu
	// Ime i prezime igraca [Naziv kluba] minuta
	//Ako je jedan igrac postigao vise golova, onda postaviti minutu novog postignutog gola na kraj postojeceg zapisa
	void DodajGol(bool golZa, Fudbaler* fudbaler, int minuta);
	//Z5.8
	~Utakmica();
};
//Z5.9
ostream& operator << (ostream& COUT, const Utakmica&);
void Zadatak1() {
	Datum prviMaj, novaGodina, prviApril(novaGodina), danNezavisnosti(move(novaGodina));
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
	Osoba o1(louis), o2(move(kash)), o3;
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

	Fudbaler f1(indyNeidell), f2(threeBlueOneBrown), f3(move(euler)), f4(move(elonMusk)), f5;
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
	FudbalskiTim tim1(move(bacunaMatata));
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
	Utakmica u3(move(u2));
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
