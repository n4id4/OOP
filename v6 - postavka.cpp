#include <iostream>
using namespace std;

// Koristene skracenice u komentarima
//  user-def. = user-defined (korisnicki-definirano)
//  ctor = constructor (konstruktor)
//  copy ctor = copy constructor (konstruktor kopije)
//  dtor = destructor

// Z0.1 dinamicka alokacija niza karaktera i kopiranje
char* alocirajTekst(const char* tekst) {
    // Implementirati funkciju
    return nullptr;
}

// Z0.2 Funkcija koja vraca logicku vrijednost u zavisnosti da li je proslijedjena godina prijestupna ili ne
bool prijestupnaGodina(int godina) {
    // Implementirati funkciju
    return false;
}

class Datum
{
    int* _dan = nullptr;
    int* _mjesec = nullptr;
    int* _godina = nullptr;
public:
    // Z1.1 getteri
    int getDan() const { return (_dan == nullptr) ? 1 : *_dan; }
    int getMjesec() const { return (_mjesec == nullptr) ? 1 : *_mjesec; }
    int getGodina() const { return (_godina == nullptr) ? 2023 : *_godina; }

    // Z1.2 setteri
    void setDan(int dan) {
        // Implementirati funkciju
    }
    void setMjesec(int mjesec) {
        // Implementirati funkciju
    }
    void setGodina(int godina) {
        // Implementirati funkciju
    }
    // Z1.3 Dflt. ctor 
    Datum() {
    }
    // Z1.4 User-def. ctor
    Datum(int d, int m, int g) {
        // Implementirati funkciju
    }
    // Z1.5 Copy ctor
    Datum(const Datum& obj) {
        // Implementirati funkciju
    }

    // Z1.6 Operator = 
    Datum& operator =(const Datum& obj) {
        // Implementirati funkciju
        return *this;
    }

    // Z1.7 dtor
    ~Datum() {
        // Implementirati funkciju
    }
};

// Z1.8 Ispisati datum
ostream& operator << (ostream& COUT, const Datum obj) {
    // Implementirati funkciju
    return COUT;
}

// Z1.9 Porediti dva datuma po vrijednostima atributa
bool operator == (const Datum& d1, const Datum& d2) {
    // Implementirati funkciju
    return false;
}

// Z1.10 Implementirati operator !=
bool operator != (const Datum& d1, const Datum& d2) {
    // Implementirati funkciju
    return false;
}

// Z1.11 Provjeriti da li je 'd1' veci (noviji datum) od 'd2'
bool operator > (const Datum& d1, const Datum& d2) {
    // Implementirati funkciju
    return false;
}
// Z1.12 Provjeriti da li je 'd1' veci ili jednak (noviji datum ili isti datum) od 'd2'
bool operator >= (const Datum& d1, const Datum& d2) {
    // Implementirati funkciju
    return false;
}

// Z1.13 Provjeriti da li je 'd1' manji (stariji datum) od 'd2'
bool operator <(const Datum& d1, const Datum& d2) {
    // Implementirati funkciju
    return false;
}

// Z1.14 Provjeriti da li je 'd1' manji ili jednak (stariji datum ili isti datum) od 'd2'
bool operator <=(const Datum& d1, const Datum& d2) {
    // Implementirati funkciju
    return false;
}

// Z1.15 Od dva datuma vratiti onaj stariji
const Datum& min(const Datum& d1, const Datum& d2) {
    // Implementirati funkciju
    return d1;
}

// Z1.16 Od dva datuma vratiti onaj noviji
const Datum& max(const Datum& d1, const Datum& d2) {
    // Implementirati funkciju
    return d1;
}

class Autor {
    char* _ime = nullptr;
    char* _prezime = nullptr;
    Datum* _datumRodjenja = nullptr;
    bool _spol;
public:
    //Z2.1 dflt. ctor
    Autor()
    {
        //Implementirati funkciju
    }

    //Z2.2 user-def. ctor
    Autor(const char* ime, const char* prezime, Datum datumRodjenja, bool spol)
    {
        //Implementirati funkciju
    }

    //Z2.3 copy ctor
    Autor(const Autor& obj)
    {
        //Implementirati funkciju
    }

    //Z2.4 Operator dodjele
    Autor& operator= (const Autor& obj)
    {
        //Implementirati funkciju
        return *this;
    }

    //Z2.5 Getteri
    const char* getIme() const { return _ime; }
    const char* getPrezime() const { return _prezime; }
    Datum getDatumRodjenja() const { return (_datumRodjenja == nullptr) ? Datum(1, 1, 2023) : *_datumRodjenja; }
    bool getSpol() const { return _spol; }

    //Z2.6 Setteri
    void setIme(const char* ime)
    {
        //Implementirati funkciju
    }

    void setPrezime(const char* prezime)
    {
        //Implementirati funkciju
    }

    void setDatumRodjenja(Datum datumRodjenja)
    {
        //Implementirati funkciju
    }

    void setSpol(bool spol)
    {
        //Implementirati funkciju
    }

    //Z2.7 dtor
    ~Autor()
    {
        //Implementirati funkciju
    }

    //Z2.8 Ispisati podatke o autoru (operator <<)
    friend ostream& operator<<(ostream& COUT, const Autor& autor)
    {
        //Implementirati funkciju
        return COUT;
    }

    //Z2.9 operator == (porediti autore po imenu, prezimenu i datumu rodjenja)
    bool operator==(const Autor& obj)
    {
        //Implementirati funkciju
        return false;
    }
};


class Zanr {
    char* _naziv{ nullptr };
    char _opis[200];
public:
    //Z3.1 dflt. ctor
    Zanr()
    {
        //Implementirati funkciju
    }

    //Z3.2 user-def. ctor
    Zanr(const char* naziv, const char* opis)
    {
        //Implementirati funkciju
    }

    //Z3.3 copy ctor
    Zanr(const Zanr& obj)
    {
        //Implementirati funkciju
    }

    //Z3.4 operator dodjele
    Zanr& operator=(const Zanr& obj)
    {
        //Implementirati funkciju
        return *this;
    }

    //Z3.4 Getteri
    const char* getNaziv()const { return _naziv; }
    const char* getOpis()const { return _opis; }

    //Z3.5 Setteri
    void setNaziv(const char* naziv)
    {
        //Implementirati funkciju
    }

    void setOpis(const char* opis)
    {
        //Implementirati funkciju
    }

    //Z3.6 dtor
    ~Zanr()
    {
        //Implementirati funkciju
    }

    //Z3.7 Ispisati podatke o zanru
    friend ostream& operator<<(ostream& COUT, const Zanr& zanr)
    {
        //Implementirati funkciju
        return COUT;
    }
};

//Z3.8 operator == (porediti zanrove po nazivu
bool operator== (const Zanr& z1, const Zanr& z2)
{
    //Implementirati funkciju
    return false;
}

class Knjiga {
    char* _naziv = nullptr;
    int* brojStranica = nullptr;
    Zanr _zanr;
    Autor* _autor = nullptr;
    char _kratakSadrzaj[200];
public:
    //Z4.1 dflt. ctor
    Knjiga()
    {
        //Implementirati funkciju
    }

    //Z4.2 user-def. ctor
    Knjiga(const char* naziv, int brojStranica, Zanr zanr, Autor autor, const char* kratakSadrzaj)
    {
        //Implementirati funkciju
    }

    //Z4.3 copy ctor
    Knjiga(const Knjiga& obj)
    {
        //Implementirati funkciju
    }

    //Z4.4 operator dodjele (=)
    Knjiga& operator= (const Knjiga& obj)
    {
        //Implementirati funkciju
    }

    //Z4.5 Getteri
    const char* getNaziv()const
    {
        //Implementirati funkciju
    }

    int getBrojStranica() const
    {
        //Implementirati funkciju
    }

    Zanr getZanr()const
    {
        //Implementirati funkciju
    }

    Autor getAutor()const
    {
        //Implementirati funkciju
    }

    const char* getKratakSadrzaj()const
    {
        //Implementirati funkciju
    }

    //Z4.6 Setteri
    void setNaziv(const char* naziv)
    {
        //Implementirati funkciju
    }

    void setBrojStranica(int brStr)
    {
        //Implementirati funkciju
    }

    void setZanr(Zanr zanr)
    {
        //Implementirati funkciju
    }

    void setAutor(Autor autor)
    {
        //Implementirati funkciju
    }

    void setKratakSadrzaj(const char* kratakSadrzaj)
    {
        //Implementirati funkciju
    }

    //Z4.7 dtor
    ~Knjiga()
    {
        //Implementirati funkciju
    }

    friend ostream& operator<<(ostream& COUT, const Knjiga& knjiga);
};

//Z4.8 Ispis podataka o knjizi (operator <<)
ostream& operator<<(ostream& COUT, const Knjiga& knjiga)
{
    //Implementirati funkciju
    return COUT;
}

//Z4.9 operator usporedbe (porediti knjige po nazivu i po autoru)
bool operator== (const Knjiga& k1, const Knjiga& k2)
{
    //Implementirati funkciju
    return false;
}

class Biblioteka {
    char* _naziv = nullptr;
    char _adresa[50];
    Datum _datumOtvaranja;
    Knjiga* _nizKnjiga = nullptr;
    int* _trenutnoKnjiga = nullptr;
public:
    //Z5.1 dflt. ctor
    Biblioteka()
    {
        //Implementirati funkciju
    }

    //Z5.2 user-def. ctor
    Biblioteka(const char* naziv, const char* adresa, Datum datumOtvaranja)
    {
        //Implementirati funkciju
    }

    //Z5.3 copy ctor
    Biblioteka(const Biblioteka& obj)
    {
        //Implementirati funkciju
    }

    //Z5.4 operator dodjele (=)
    Biblioteka& operator=(const Biblioteka& obj)
    {
        //Implementirati funkciju
        return *this;
    }

    //Z5.5 Getteri
    const char* getNaziv()const
    {
        //Implementirati funkciju
    }

    const char* getAdresa()const
    {
        //Implementirati funkciju
    }

    Datum getDatumOtvaranja()const
    {
        //Implementirati funkciju
    }

    int getTrenutnoKnjiga()const
    {
        //Implementirati funkciju
    }

    Knjiga getKnjigaAtI(int index)const
    {
        //Implementirati funkciju
    }

    void dodajKnjigu(Knjiga& k)
    {
        //Implementirati funkciju
    }

    //Z5.6 Setteri
    void setNaziv(const char* naziv)
    {
        //Implementirati funkciju
    }

    void setAdresa(const char* adresa)
    {
        //Implementirati funkciju
    }

    void setDatumOtvaranja(Datum d)
    {
        //Implementirati funkciju
    }

    void setKnjige(int trenutnoKnjiga, Knjiga* knjige = nullptr)
    {
        //Implementirati funkciju
    }

    //Z5.7 dtor
    ~Biblioteka()
    {
        //Implementirati funkciju
    }

    //Z5.8 Ispis podataka o biblioteci
    friend ostream& operator<<(ostream& COUT, const Biblioteka& b)
    {
        //Implementirati funkciju
        return COUT;
    }
};

void zadatak1() {
    cout << "Sve prijestupne godine izmedju [1900-2023]: " << endl;
    for (int i = 1900; i <= 2023; i++)
        if (prijestupnaGodina(i))
            cout << i << ", ";
    cout << endl;
    Datum worldRiversDay; // dflt. ctor
    worldRiversDay.setDan(14);
    worldRiversDay.setMjesec(3);
    worldRiversDay.setGodina(2023);
    cout << "World rivers day: " << worldRiversDay << endl; //  operator <<

    Datum nationalWalnutDay(worldRiversDay.getDan() - 3, worldRiversDay.getMjesec() + 2, worldRiversDay.getGodina()); // user-def. ctor
    cout << "National walnut day: " << nationalWalnutDay << endl;

    Datum laborDay(worldRiversDay); // copy ctor
    laborDay.setDan(1);
    laborDay.setMjesec(5);
    cout << "Labor day (BiH): " << laborDay << endl;

    Datum stPatricksDay(17, 3, 2023), stPatricksDay_copy;
    stPatricksDay_copy = stPatricksDay;
    cout << "St Patrick's Day: " << stPatricksDay << endl;
    cout << "St Patrick's Day (copy): " << stPatricksDay_copy << endl;

    cout << "Dealokacija..." << endl;
}

void zadatak2()
{
    //testiranje user-def. ctora
    Autor safak("Elif", "Safak", Datum(25, 10, 1971), 1);

    //testiranje dflt. ctora
    Autor tolstoj;
    // testiranje settera
    tolstoj.setIme("Lav");
    tolstoj.setPrezime("Tolstoj");
    tolstoj.setSpol(0);
    tolstoj.setDatumRodjenja(Datum(9, 9, 1828));

    //testiranje operatora za ispis
    cout << safak << endl;
    cout << tolstoj << endl;

    //testiranje copy ctor-a
    Autor tolstoj_copy(tolstoj);
    cout << tolstoj_copy << endl;

    Autor sidran("Abdulah", "Sidran", Datum(2, 10, 1944), 0);
    //testiranje operatora dodjele (=)
    Autor sidran_copy;
    sidran_copy = sidran;
    //testiranje operatora usporedbe
    if (sidran == sidran_copy)
        cout << "Autori su isti!";
    else
        cout << "Rzaliciti autori!";
   
}

void zadatak3()
{
    //testiranje dflt. ctora
    Zanr tragedija;
    //testiranje settera
    tragedija.setNaziv("Tragedija");
    tragedija.setOpis("Vrsta drame sa tragicnim zavrstekom.");

    //testiranje copy ctora
    Zanr tragedija_copy(tragedija);

    //testiranje operatora usporedbe
    if (tragedija == tragedija_copy)
        cout << "Zanrovi su jednaki, uspjesno implementirano!\n";
    else
        cout << "Greska u implementaciji!\n";

    //testiranje user-def. ctora
    Zanr komedija("Komedija", "Vrsta drame sa komicnim dogadjajima i sretnim zavrsetkom.");

    Zanr komedija_copy;
    //testiranje operatora dodjele (=)
    komedija_copy = komedija;

    //testiranje ispisa
    cout << komedija_copy << endl;
}

void zadatak4()
{
    Autor sidran("Abdulah", "Sidran", Datum(2, 10, 1944), 0);
    Autor safak("Elif", "Safak", Datum(25, 10, 1971), 1);

    Zanr poezija("Poezija", "Umjetnost koja se zasniva na izrazajnim mogucnostima jezika.");
    Zanr fikcija("Fikcija", "Fikcija predstavlja pricanje prica koje nisu u potpunosti bazirane na cinjenicama. Bolje receno, fikcija je forma izmesljene naracije");

    Knjiga sahbaza("Sahbaza", 1400, poezija, sidran, "Sadrzi najbolje sevdalinke ovih prostora i bh. pjesme s tekstovima");
    Knjiga triEvineKceri("Tri Evine kceri", 368, fikcija, safak, "Elif Safak pripovijeda opseznu i dirljivu pricu koja humanizira i personalizira neke od temeljnih promjena u savremenom svijetu." );
    Knjiga kopileIstanbula("Kopile Istanbula", 368, fikcija, safak, "Kopile Istanbula roman je o dva naroda, turskom i armenskom, i dvije obitelji koje su povezane mracnom tajnom iz proslosti");

    Biblioteka narodna("Narodna biblioteka Mostar", "Marsala Tita 55", Datum(1, 1, 2000));
    narodna.dodajKnjigu(sahbaza);
    narodna.dodajKnjigu(kopileIstanbula);
    narodna.dodajKnjigu(triEvineKceri);

    Biblioteka narodna_copy;
    narodna_copy = narodna;
    cout << narodna_copy << endl;
}

void menu() {
    int nastaviDalje = 1;
    while (nastaviDalje == 1) {
        int izbor = 0;
        do {
            system("cls");
            cout << "::Zadaci::" << endl;
            cout << "(1) zadatak 1" << endl;
            cout << "(2) zadatak 2" << endl;
            cout << "(3) zadatak 3" << endl;
            cout << "(4) zadatak 4" << endl;
            cout << "Unesite odgovarajuci broj zadatka za testiranje: -->: ";
            cin >> izbor;
            cout << endl;
        } while (izbor < 1 || izbor > 5);
        switch (izbor) {
        case 1: zadatak1(); cout << "zadatak 1. Done." << endl; break;
        case 2: zadatak2(); cout << "zadatak 2. Done." << endl; break;
        case 3: zadatak3(); cout << "zadatak 3. Done." << endl; break;
        case 4: zadatak4(); cout << "zadatak 4. Done." << endl; break;
        default:break;
        }
        do {
            cout << "DA LI ZELITE NASTAVITI DALJE? (1/0): ";
            cin >> nastaviDalje;
        } while (nastaviDalje != 0 && nastaviDalje != 1);
    }
}

int main()
{
    menu();

    system("pause>0");
    return 0;
}
