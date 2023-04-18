#include <iostream>
using namespace std;

//Z0.1
char* alocirajTekst(const char* izvor) {
    // implementirati funkciju
    return nullptr;
}

class Datum
{
    int* _dan = nullptr;
    int* _mjesec = nullptr;
    int* _godina = nullptr;
public:
    // Z1.1 :: getteri
    int getDan() const { return (_dan == nullptr) ? 1 : *_dan; }
    int getMjesec() const { return (_mjesec == nullptr) ? 1 : *_mjesec; }
    int getGodina() const { return (_godina == nullptr) ? 2023 : *_godina; }

    // Z1.2 :: setteri
    void setDan(int dan) {
        // implementirati funkciju
    }
    void setMjesec(int mjesec) {
        // implementirati funkciju
    }
    void setGodina(int godina) {
        // implementirati funkciju
    }
    // Z1.3 :: dflt. ctor 
    Datum() {
    }
    // Z1.4 :: user-def. ctor
    Datum(int d, int m, int g) {
        // implementirati funkciju
    }
    // Z1.5 :: copy ctor
    Datum(const Datum& obj) {
        // implementirati funkciju
    }

    // Z1.6 :: operator = 
    Datum& operator =(const Datum& obj) {
        // implementirati funkciju
        return *this;
    }
    // Z1.7 :: destruktor
    ~Datum() {
        // implementirati funkciju
    }
};

// Z1.8 ::ispisati datum
ostream& operator << (ostream& COUT, const Datum& obj) {
    // implementirati funkciju
    return COUT;
}
// Z1.9 :: porediti dva datuma po vrijednostima atributa
bool operator == (const Datum& d1, const Datum& d2) {
    // implementirati funkciju
    return false;
}
bool operator != (const Datum& d1, const Datum& d2) {
    // implementirati funkciju
    return false;
}

// Z1.10
bool operator > (const Datum& d1, const Datum& d2) {
    // implementirati funkciju
    return false;
}
bool operator >= (const Datum& d1, const Datum& d2) {
    // implementirati funkciju
    return false;
}
bool operator <(const Datum& d1, const Datum& d2) {
    // implementirati funkciju
    return false;
}
bool operator <=(const Datum& d1, const Datum& d2) {
    // implementirati funkciju
    return false;
}

// kolekcija elemenata 'Vektor' (tipa T) sa mogucnoscu dinamickog prosirivanja
template<class T>
class Vektor {
    int _trenutno = 0;
    int _maxElemenata;
    T* _elementi = nullptr;
public:
    // Z2.1 :: getteri
    int getTrenutno() const { return _trenutno; }
    int getMaxElemenata() const { return _maxElemenata; }
    T* getElementi() const { return _elementi; }

    // Z2.2 :: setteri (u ovom slucaju imamo samo jednu setter funkciju)
    void setElementi(int trenutno, int maxElemenata, T* elementi = nullptr) {
        // implementirati funkciju
    }
    // Z2.3 :: funkcija za dodavanje elementa tipa 'T'.
    // U slucaju da je brojac dosao do kraja -- uraditi prosirivanje niza za 10 elemenata.
    void add(const T& element) {
        // implementirati funkciju
    }

    // Z2.4 :: funkcija za uklanjanje zadnjeg elementa iz niza
    bool removeZadnji() {
        // implementirati funkciju
        return false;
    }

    // Z2.5 :: funkcija za prosirivanje dinamickog niza
    void expandElementi(int uvecanje) {
        // implementirati funkciju
    }

    // Z2.6 :: dflt ctor
    Vektor(int maxElemenata = 100) {
        // implementirati funkciju
    }
    // Z2.6 :: copy ctor :: Kopirati vrijednosti jednog vektora u drugi
    Vektor(const Vektor<T>& obj) {
        // implementirati funkciju
    }
    // Z2.7 :: operator '='
    Vektor<T>& operator = (const Vektor<T>& obj) {
        // implementirati funkciju
        return *this;
    }
    // Z2.8 :: operator '[]' za dohvacanje pojedinacne vrijednosti iz niza
    T& operator [] (int index) const {
        // implementirati funkciju
    }
    // Z2.9 :: destruktor
    ~Vektor() {
        // implementirati funkciju
    }
};

// Z2.10 :: ispisuje elemente vektora. Za pristup elementima koristiti preklopljeni operator '[]'
template<class T>
ostream& operator << <>(ostream& COUT, const Vektor<T>& obj) {
    // implementirati funkciju
    return COUT;
}


template<class T, int max> //max oznacava velicinu niza
class Array {
    int _trenutno = 0; // trenutno elemenata 
    T* _elementi[max] = { nullptr }; // staticki niz pokazivaca
public:
    // Z3.1 :: getteri
    int getTrenutno() const { return _trenutno; }
    T** getElementi() const { return (T**)_elementi; }

    // Z3.2 :: setteri (u ovom slucaju samo jedna setter funkcija)
    void setElementi(int trenutno, T** elementi = nullptr) {
        // implementirati funkciju
    }
    // Z3.3 :: funkcija za  dodavanje elementa
    // ukoliko je brojac dosao do kraja niza, onemoguciti dodavanje
    bool add(const T& element) {
        // implementirati funkciju
        return false;
    }

    // Z3.4 :: funkcija za uklanjanje zadnjeg dodanog elementa [ne zaboravite dealokaciju]
    bool removeZadnji() {
        // implementirati funkciju
        return false;
    }
    // Z3.5 :: dflt ctor
    Array() {
        // implementirati funkciju
    }
    // Z3.6 :: copy ctor
    Array(const Array<T, max>& obj) {
        // implementirati funkciju
    }
    // Z3.7 :: operator '='
    Array<T, max>& operator = (const Array<T, max>& obj) {
        // implementirati funkciju
        return *this;
    }
    // Z3.8 :: operator '[]'
    T& operator [] (int index) const {
        return *_elementi[index];
    }
    // Z3.9 :: destruktor
    ~Array() {
        // implementirati funkciju
    }
};

// Z3.10 :: operator '<<'
template<class T, int max>
ostream& operator << <>(ostream& COUT, const Array<T, max>& obj) {
    // implementirati funkciju
    return COUT;
}

class Sahist {
    const char* _imePrezime = nullptr;
    const char* _drzava = nullptr;
    Datum _datumRodjenja;
    bool* _spol = nullptr;
public:
    // Z4.1 :: getteri
    const char* getImePrezime() const { return (_imePrezime == nullptr) ? "" : _imePrezime; }
    const char* getDrzava() const { return (_drzava == nullptr) ? "" : _drzava; }
    Datum getDatumRodjenja() const { return _datumRodjenja; }
    bool getSpol() const { return (_spol == nullptr) ? false : *_spol; }

    // Z4.2 :: setteri
    void setImePrezime(const char* imePrezime) {
        // implementirati funkciju
    }
    void setDrzava(const char* drzava) {
        // implementirati funkciju

    }
    void setDatumRodjenja(Datum datumRodjenja) {
        // implementirati funkciju
    }
    void setSpol(bool spol) {
        // implementirati funkciju
    }
    // Z4.3 :: dflt ctor
    Sahist() {}
    // Z4.4 :: user-def. ctor
    Sahist(const char* imePrezime, const char* drzava, Datum datumRodjenja, bool spol) {
        // implementirati funkciju
    }
    // Z4.5 :: copy ctor
    Sahist(const Sahist& obj) {
        // implementirati funkciju
    }

    // Z4.6 :: operator '='
    Sahist& operator = (const Sahist& obj) {
        // implementirati funkciju
        return *this;
    }
    // Z4.7 :: destruktor
    ~Sahist() {
        // implementirati funkciju
    }
};
// Z4.8 :: operator '<<'
ostream& operator << (ostream& COUT, const Sahist& obj) {
    // implementirati funkciju
    return COUT;
}

// Z4.9 :: odgovara na pitanje: "Da li je prvi sahista mladji od drugog?"
bool operator >(const Sahist& obj1, const Sahist& obj2) {
    // implementirati funkciju
    return false;
}

// Z4.10 :: odgovara na pitanje: "Da li je drugi sahista mladji od prvog?"
bool operator <(const Sahist& obj1, const Sahist& obj2) {
    // implementirati funkciju
    return false;
}

// Z4.11 :: vraca true ako sahisti imaju isto ime i prezime
bool operator == (const Sahist& obj1, const Sahist& obj2) {
    // implementirati funkciju
    return false;
}
bool operator != (const Sahist& obj1, const Sahist& obj2) {
    // implementirati funkciju
    return false;
}

// Z4.12 :: vraca najmladjeg sahistu,
Sahist getNajmladjeg(Vektor<Sahist>& sahisti) {
    // implementirati funkciju
    return Sahist();
}
template<class T1, class T2>
class Par {
    T1 _lijevi;
    T2 _desni;
public:
    // Z5.1 :: getteri
    T1 getLijevi() const { return _lijevi; }
    T2 getDesni() const { return _desni; }

    // Z5.2 :: setteri
    void setLijevi(T1 el) {
        // implementirati funkciju
    }
    void setDesni(T2 el) {
        // implementirati funkciju
    }
    // Z5.3 :: dflt ctor
    Par() {
    }
    // Z5.4 :: user-def. ctor
    Par(T1 el1, T2 el2) {
        // implementirati funkciju
    }
    // Z5.5 :: copy ctor
    Par(const Par<T1, T2>& obj) {
        // implementirati funkciju
    }
    // Z5.6 :: operator '='
    Par<T1, T2>& operator = (const Par<T1, T2>& obj) {
        // implementirati funkciju
    }
};

// Z5.7 :: operator '<<'
template<class T1, class T2>
ostream& operator << (ostream& COUT, const Par<T1, T2>& par) {
    // implementirati funkciju
    return COUT;
}

// prikaz koristenja genericke klase 'Pair'
void demo() {
    Par<int, int> par(4, 3); // par (int, int)
    Par<int, float> par2(4, 4.5f); // par (int float)
    Par<Sahist, int> par3(Sahist(), 243); // par (Sahist, broj)
    Par<Datum, Datum> par4(Datum(2, 3, 2023), Datum(23, 5, 2023)); //par (Datum, Datum)
}

class SahovskiTurnir {
    char* _naziv = nullptr;
    char* _mjestoOdrzavanja = nullptr;
    Array<Par<Sahist, Sahist>, 20> _dueli; // niz sahovskih duela velicine 20
public:
    // Z5.8 :: getteri
    const char* getNaziv() const { return (_naziv == nullptr) ? "" : _naziv; }
    const char* getMjestoOdrzavanja() const { return (_mjestoOdrzavanja == nullptr) ? "" : _mjestoOdrzavanja; }
    Array<Par<Sahist, Sahist>, 20> getDueli() const { return _dueli; }

    // Z5.9 :: setteri
    void setNaziv(const char* naziv) {
        // implementirati funkciju
    }
    void setMjestoOdrzavanja(const char* mjestoOdrzavanja) {
        // implementirati funkciju
    }
    void setDueli(Array<Par<Sahist, Sahist>, 20> dueli) {
        // implementirati funkciju
    }

    // Z5.10 :: dflt ctor
    SahovskiTurnir() {
    }
    // Z5.11 :: user-def. ctor
    SahovskiTurnir(const char* naziv, const char* mjestoOdrzavanja) {
        // implementirati funkciju
    }
    // Z5.12 :: copy ctor
    SahovskiTurnir(const SahovskiTurnir& obj) {
        // implementirati funkciju
    }
    // Z5.13 :: operator '='
    SahovskiTurnir& operator = (const SahovskiTurnir& obj) {
        // implementirati funkciju
        return *this;
    }


    // Z5.14 :: dodavanje duela (objekta tipa 'Par')
    bool dodajDuel(Sahist& s1, Sahist& s2) {
        // implementirati funkciju
        return false;
    }
    // Z5.15 :: destruktor
    ~SahovskiTurnir() {
        // implementirati funkciju
    }
};

// Z5.16 :: ispisati naziv, mjesto, te sve duele
ostream& operator <<(ostream& COUT, SahovskiTurnir& st) {
    // implementirati funkciju
    return COUT;
}
void zadatak1() {
    Datum aprilFoolsDay;
    Datum laborDay(1, 5, 2023);
    Datum newYearsEve(31, 12, 2023);
    aprilFoolsDay.setDan(1);
    aprilFoolsDay.setMjesec(4);
    aprilFoolsDay.setGodina(2023);

    Datum d1(aprilFoolsDay);
    Datum d2;
    d2 = newYearsEve;
    cout << d1 << endl;
    cout << d2 << endl;
    cout << "Dealokacija..." << endl;
}

void zadatak2() {
    cout << "Kolekcija datuma..." << endl;
    Vektor<Datum> datumi;
    cout << "Dodajemo 5 elemenata: " << endl;
    datumi.add(Datum(1, 5, 2023));
    datumi.add(Datum(7, 7, 2023));
    datumi.add(Datum(1, 3, 2023));
    datumi.add(Datum(7, 10, 2023));
    datumi.add(Datum(8, 12, 2023));
    cout << "Ispis elemenata..." << endl;
    cout << datumi << endl;
    cout << "Uklanjamo zadnji element...." << endl;
    datumi.removeZadnji();
    cout << datumi << endl;

    cout << "Pravimo kopiju kolekcije: " << endl;
    Vektor<Datum> kopijaDatuma(datumi);
    cout << "Dodajemo jedan element (11.3.2023)" << endl;
    kopijaDatuma.add(Datum(11, 3, 2023));
    cout << kopijaDatuma << endl;

    cout << "Kreiramo novu kolekciju i vrsimo kopiranje (operator '=').. " << endl;
    Vektor<Datum> nova;
    nova = kopijaDatuma;
    cout << nova << endl;
    cout << "Dealokacija..." << endl;
}

void zadatak3() {
    cout << "Kreiramo 'tudjeOcjene'" << endl;
    cout << "Dodajemo nove elemente u 'tudjeOcjene'..." << endl;
    Array<int, 100> tudjeOcjene;
    tudjeOcjene.add(9);
    tudjeOcjene.add(10);
    tudjeOcjene.add(10);
    tudjeOcjene.add(10);
    tudjeOcjene.add(9);
    tudjeOcjene.add(10);
    tudjeOcjene.add(10);
    cout << tudjeOcjene << endl;

    cout << "Kreiramo 'mojeOcjene' na osnovu 'tudjeOcjene'" << endl;
    Array<int, 100> mojeOcjene(tudjeOcjene);
    cout << mojeOcjene << endl;
    cout << "Brisemo sve elemente iz 'mojeOcjene'" << endl;
    for (int i = 0; i < 10; i++)
        mojeOcjene.removeZadnji();
    cout << "Dodajemo nove (losije) ocjene u 'mojeOcjene'  .... " << endl;
    mojeOcjene.add(6);
    mojeOcjene.add(7);
    mojeOcjene.add(6);
    mojeOcjene.add(6);
    mojeOcjene.add(7);
    mojeOcjene.add(8);
    cout << mojeOcjene << endl;

    cout << "Kreiramo 'josGoreOcjene'" << endl;
    Array<int, 100> josGoreOcjene;
    cout << "Dodajemo nove ocjene u 'josGoreOcjene' .... " << endl;
    for (int i = 0; i < 5; i++)
        josGoreOcjene.add(6);
    cout << josGoreOcjene << endl;

    cout << "Kreiramo 'josGoreOcjene2' na osnovu 'josGoreOcjene' " << endl;
    Array<int, 100> josGoreOcjene2;
    josGoreOcjene2 = josGoreOcjene;
    cout << josGoreOcjene << endl;
    cout << "Dealokacija..." << endl;
}

void zadatak4() {
    Sahist s1("Gary Kasparov", "Rusija", Datum(2, 2, 1963), 1);
    Sahist s2(s1);
    Sahist garyKasparov;
    garyKasparov = s2;

    Sahist bobbyFischer("Bobby Fischer", "SAD", Datum(4, 4, 1943), 1);
    Sahist carlsen("Magnus Carlsen", "Norveska", Datum(3, 3, 1990), 1);
    Sahist judithPolgar("Judith Polgar", "Madjarska", Datum(5, 5, 1976), 0);

    Vektor<Sahist> sahisti;
    sahisti.add(garyKasparov);
    sahisti.add(bobbyFischer);
    sahisti.add(carlsen);
    sahisti.add(judithPolgar);

    cout << sahisti << endl;
    cout << "Najmladji Sahist: " << getNajmladjeg(sahisti).getImePrezime() << endl;
    cout << "Dealokacija..." << endl;
}

void zadatak5() {
    Sahist kingBobby("Bobo Fischek", "SAD", Datum(4, 4, 1943), 1);
    Sahist sahmatov("Viktor Sahmatov", "Rusija", Datum(4, 4, 1966), 1);
    Sahist chuckNorris("Chuck Mate", "SAD", Datum(4, 4, 1966), 1);
    SahovskiTurnir bugojno2023("MVST Bugojno (2023)", "Bugojno, BiH");
    bugojno2023.dodajDuel(kingBobby, sahmatov);
    bugojno2023.dodajDuel(sahmatov, chuckNorris);
    bugojno2023.dodajDuel(chuckNorris, kingBobby);
    cout << bugojno2023 << endl;
    cout << "Dealokacija..." << endl;
}

void menu() {
    int nastaviDalje = 1;
    while (nastaviDalje == 1) {
        int izbor = 0;
        do {
            system("cls");
            cout << "::Zadaci::" << endl;
            cout << "(1) Zadatak 1" << endl;
            cout << "(2) Zadatak 2" << endl;
            cout << "(3) Zadatak 3" << endl;
            cout << "(4) Zadatak 4" << endl;
            cout << "(5) Zadatak 5" << endl;
            cout << "Unesite odgovarajuci broj zadatka za testiranje: -->: ";
            cin >> izbor;
            cout << endl;
        } while (izbor < 1 || izbor > 5);
        switch (izbor) {
        case 1: zadatak1(); cout << "Zadatak 1. Done." << endl; break;
        case 2: zadatak2(); cout << "Zadatak 2. Done." << endl; break;
        case 3: zadatak3(); cout << "Zadatak 3. Done." << endl; break;
        case 4: zadatak4(); cout << "Zadatak 4. Done." << endl; break;
        case 5: zadatak5(); cout << "Zadatak 5. Done." << endl; break;
        default:break;
        }
        do {
            cout << "DA LI ZELITE NASTAVITI DALJE? (1/0): ";
            cin >> nastaviDalje;
        } while (nastaviDalje != 0 && nastaviDalje != 1);
    }
}
int main() {
    menu();
    return 0;
}
