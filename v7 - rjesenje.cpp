#include <iostream>
#include<vector>
using namespace std;

//Z0.1
char* alocirajTekst(const char* izvor) {
    if (izvor == nullptr)
        return nullptr;
    int duzina = strlen(izvor) + 1;
    char* novi = new char[duzina];
    strcpy_s(novi, duzina, izvor);
    return novi;
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
        if (_dan == nullptr)
            _dan = new int;
        *_dan = dan;
    }
    void setMjesec(int mjesec) {
        if (_mjesec == nullptr)
            _mjesec = new int;
        *_mjesec = mjesec;
    }
    void setGodina(int godina) {
        if (_godina == nullptr)
            _godina = new int;
        *_godina = godina;
    }
    // Z1.3 :: dflt. ctor 
    Datum() {
    }
    // Z1.4 :: user-def. ctor
    Datum(int d, int m, int g) {
        setDan(d);
        setMjesec(m);
        setGodina(g);
    }
    // Z1.5 :: copy ctor
    Datum(const Datum& obj) {
        setDan(obj.getDan());
        setMjesec(obj.getMjesec());
        setGodina(obj.getGodina());
    }

    // Z1.6 :: operator = 
    Datum& operator =(const Datum& obj) {
        if (this != &obj)
        {
            setDan(obj.getDan());
            setMjesec(obj.getMjesec());
            setGodina(obj.getGodina());
        }
        return *this;
    }
    // Z1.7 :: destruktor
    ~Datum() {
        delete _dan;
        _dan = nullptr;
        delete _mjesec;
        _mjesec= nullptr;
        delete _godina;
        _godina = nullptr;
    }
};

// Z1.8 ::ispisati datum
ostream& operator << (ostream& COUT, const Datum& obj) {
    COUT << obj.getDan() << "." << obj.getMjesec() << "." << obj.getGodina();
    return COUT;
}
// Z1.9 :: porediti dva datuma po vrijednostima atributa
bool operator == (const Datum& d1, const Datum& d2) {
    return (d1.getDan() == d2.getDan() &&
        d1.getMjesec() == d2.getMjesec() &&
        d1.getGodina() == d2.getGodina());
}
bool operator != (const Datum& d1, const Datum& d2) {
    return !(d1 == d2);
}

// Z1.10
bool operator > (const Datum& d1, const Datum& d2) {
    return ((d1.getGodina() * 365) + (d1.getMjesec() * 30) + d1.getDan()
        > (d2.getGodina() * 365) + (d2.getMjesec() * 30)
        + d2.getDan());
}
bool operator >= (const Datum& d1, const Datum& d2) {
    return (d1 == d2 || d1 > d2);
}
bool operator <(const Datum& d1, const Datum& d2) {
    return !(d1 >= d2);
}
bool operator <=(const Datum& d1, const Datum& d2) {
    return !(d1 > d2);
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
        delete[] _elementi; // brisemo stari dinamicki niz
        _maxElemenata = maxElemenata; 
        _elementi = new T[_maxElemenata]; 
        _trenutno = 0; 
        if (elementi != nullptr)
            for (int i = 0; i < trenutno; i++)
                add(elementi[i]); //dodavanje pojedinacnog elementa
        
    }
    // Z2.3 :: funkcija za dodavanje elementa tipa 'T'.
    // U slucaju da je brojac dosao do kraja -- uraditi prosirivanje niza za 10 elemenata.
    void add(const T& element) {
        if (_trenutno == _maxElemenata)
            expandElementi(10);
        _elementi[_trenutno] = element;
        _trenutno++;
    }

    // Z2.4 :: funkcija za uklanjanje zadnjeg elementa iz niza
    bool removeZadnji() {
        if (_trenutno == 0)
            return false;
        _trenutno--;
        return true;
    }

    // Z2.5 :: funkcija za prosirivanje dinamickog niza
    void expandElementi(int uvecanje) {
        T* temp = _elementi;
        _maxElemenata += uvecanje;
        _elementi = new T[_maxElemenata];
        for (int i = 0; i < _trenutno; i++)
            _elementi[i] = temp[i];
        delete[] temp;
        temp = nullptr;
    }

    // Z2.6 :: dflt ctor
    Vektor(int maxElemenata = 100) {
        setElementi(0, maxElemenata);
    }
    // Z2.6 :: copy ctor :: Kopirati vrijednosti jednog vektora u drugi
    Vektor(const Vektor<T>& obj) {
        setElementi(obj.getTrenutno(), obj.getMaxElemenata()
            , obj._elementi);
    }
    // Z2.7 :: operator '='
    Vektor<T>& operator = (const Vektor<T>& obj) {
        if(this!=&obj)
            setElementi(obj.getTrenutno(), obj.getMaxElemenata(), obj._elementi);
        return *this;
    }
    // Z2.8 :: operator '[]' za dohvacanje pojedinacne vrijednosti iz niza
    T& operator [] (int index) const {
        if (index<0 || index >_trenutno - 1)
            return _elementi[0];
        return _elementi[index];
    }
    // Z2.9 :: destruktor
    ~Vektor() {
        delete[] _elementi;
        _elementi = nullptr;
    }
};

// Z2.10 :: ispisuje elemente vektora. Za pristup elementima koristiti preklopljeni operator '[]'
template<class T>
ostream& operator << <>(ostream& COUT, const Vektor<T>& obj) {
    for (int i = 0; i < obj.getTrenutno(); i++)
        COUT << obj[i] << endl;
    
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
        for (int i = 0; i < _trenutno; i++) {
            delete _elementi[i]; //brisanje dinamickog objekta
            _elementi[i] = nullptr; //anuliranje i-tog pokazivaca iz niza
        }
        _trenutno = 0;
        if (elementi != nullptr)
            for (int i = 0; i < trenutno; i++)
                add(*elementi[i]);
    }
    // Z3.3 :: funkcija za  dodavanje elementa
    // ukoliko je brojac dosao do kraja niza, onemoguciti dodavanje
    bool add(const T& element) {
        if (_trenutno == max)
            return false;
        _elementi[_trenutno] = new T(element); // copy ctor za klasu 'T'
        _trenutno++;
        return true;
    }

    // Z3.4 :: funkcija za uklanjanje zadnjeg dodanog elementa [ne zaboravite dealokaciju]
    bool removeZadnji() {
        if (_trenutno == 0)
            return false;
        delete _elementi[--_trenutno];
        _elementi[_trenutno] = nullptr;
        return true;
    }
    // Z3.5 :: dflt ctor
    Array() {
        setElementi(0);
    }
    // Z3.6 :: copy ctor
    Array(const Array<T, max>& obj) {
        setElementi(obj.getTrenutno(), obj.getElementi());
    }
    // Z3.7 :: operator '='
    Array<T, max>& operator = (const Array<T, max>& obj) {
        if (this != &obj)
            setElementi(obj.getTrenutno(), obj.getElementi());
        return *this;
    }
    // Z3.8 :: operator '[]'
    T& operator [] (int index) const {
        return *_elementi[index];
    }
    // Z3.9 :: destruktor
    ~Array() {
        for (int i = 0; i < _trenutno; i++)
            delete _elementi[i];
    }
};

// Z3.10 :: operator '<<'
template<class T, int max>
ostream& operator << <>(ostream& COUT, const Array<T, max>& obj) {
    for (int i = 0; i < obj.getTrenutno(); i++)
        COUT << obj[i] << endl; // koristenje operatora '[]' za pristup elementu na lokaciji 'i'
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
        delete[] _imePrezime;
        _imePrezime = alocirajTekst(imePrezime);
    }
    void setDrzava(const char* drzava) {
        delete[] _drzava;
        _drzava = alocirajTekst(drzava);

    }
    void setDatumRodjenja(Datum datumRodjenja) {
        _datumRodjenja = datumRodjenja;
    }
    void setSpol(bool spol) {
        if (_spol == nullptr)
            _spol = new bool;
        *_spol = spol;
    }
    // Z4.3 :: dflt ctor
    Sahist() {}
    // Z4.4 :: user-def. ctor
    Sahist(const char* imePrezime, const char* drzava, Datum datumRodjenja, bool spol) {
        setImePrezime(imePrezime);
        setDrzava(drzava);
        setDatumRodjenja(datumRodjenja);
        setSpol(spol);
    }
    // Z4.5 :: copy ctor
    Sahist(const Sahist& obj) {
        setImePrezime(obj.getImePrezime());
        setDrzava(obj.getDrzava());
        setDatumRodjenja(obj.getDatumRodjenja());
        setSpol(obj.getSpol());
    }

    // Z4.6 :: operator '='
    Sahist& operator = (const Sahist& obj) {
        if (this != &obj)
        {
            setImePrezime(obj.getImePrezime());
            setDrzava(obj.getDrzava());
            setDatumRodjenja(obj.getDatumRodjenja());
            setSpol(obj.getSpol());
        }
        return *this;
    }
    // Z4.7 :: destruktor
    ~Sahist() {
        delete[] _imePrezime, delete[] _drzava, delete _spol;
        _imePrezime = _drzava = nullptr;
        _spol = nullptr;
    }
};
// Z4.8 :: operator '<<'
ostream& operator << (ostream& COUT, const Sahist& obj) {
    COUT << "Ime i prezime:" << obj.getImePrezime() << endl;
    COUT << "Drzava: " << obj.getDrzava() << endl;
    COUT << "Datum rodjenja: " << obj.getDatumRodjenja() << endl;
    COUT << "Spol: " << (obj.getSpol() ? "Zenski" : "Muski");
    return COUT;
}

// Z4.9 :: odgovara na pitanje: "Da li je prvi sahista mladji od drugog?"
bool operator >(const Sahist& obj1, const Sahist& obj2) {
    return (obj1.getDatumRodjenja() > obj2.getDatumRodjenja());
}

// Z4.10 :: odgovara na pitanje: "Da li je drugi sahista mladji od prvog?"
bool operator <(const Sahist& obj1, const Sahist& obj2) {
    return (obj1.getDatumRodjenja() < obj2.getDatumRodjenja());
}

// Z4.11 :: vraca true ako sahisti imaju isto ime i prezime
bool operator == (const Sahist& obj1, const Sahist& obj2) {
    return (strcmp(obj1.getImePrezime(), obj2.getImePrezime()) == 0);
}
bool operator != (const Sahist& obj1, const Sahist& obj2) {
    return !(obj1 == obj2);
}

// Z4.12 :: vraca najmladjeg sahistu,
Sahist getNajmladjeg(Vektor<Sahist>& sahisti) {
    Sahist najmladji = sahisti[0];
    for (int i = 1; i < sahisti.getTrenutno(); i++)
    {
        if (sahisti[i].getDatumRodjenja() > najmladji.getDatumRodjenja())
            najmladji = sahisti[i];
    }
    return najmladji;
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
        _lijevi = el;
    }
    void setDesni(T2 el) {
        _desni = el;
    }
    // Z5.3 :: dflt ctor
    Par() {
    }
    // Z5.4 :: user-def. ctor
    Par(T1 el1, T2 el2) {
        setLijevi(el1);
        setDesni(el2);
    }
    // Z5.5 :: copy ctor
    Par(const Par<T1, T2>& obj) {
        setLijevi(obj.getLijevi());
        setDesni(obj.getDesni());
    }
    // Z5.6 :: operator '='
    Par<T1, T2>& operator = (const Par<T1, T2>& obj) {
        if (this != &obj)
        {
            setLijevi(obj.getLijevi());
            setDesni(obj.getDesni());
        }
        return *this;
    }
};

// Z5.7 :: operator '<<'
template<class T1, class T2>
ostream& operator << (ostream& COUT, const Par<T1, T2>& par) {
    COUT << "Lijevi: " << par.getLijevi() << endl;
    COUT << "Desni: " << par.getDesni() << endl;
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
        delete[] _naziv;
        _naziv = alocirajTekst(naziv);
    }
    void setMjestoOdrzavanja(const char* mjestoOdrzavanja) {
        delete[] _mjestoOdrzavanja;
        _mjestoOdrzavanja = alocirajTekst(mjestoOdrzavanja);
    }
    void setDueli(Array<Par<Sahist, Sahist>, 20> dueli) {
        _dueli.setElementi(dueli.getTrenutno(), dueli.getElementi());
    }

    // Z5.10 :: dflt ctor
    SahovskiTurnir() {
    }
    // Z5.11 :: user-def. ctor
    SahovskiTurnir(const char* naziv, const char* mjestoOdrzavanja) {
        setNaziv(naziv);
        setMjestoOdrzavanja(mjestoOdrzavanja);
    }
    // Z5.12 :: copy ctor
    SahovskiTurnir(const SahovskiTurnir& obj) {
        setNaziv(obj.getNaziv());
        setMjestoOdrzavanja(obj.getMjestoOdrzavanja());
        setDueli(obj.getDueli());
    }
    // Z5.13 :: operator '='
    SahovskiTurnir& operator = (const SahovskiTurnir& obj) {
        if (this != &obj)
        {
            setNaziv(obj.getNaziv());
            setMjestoOdrzavanja(obj.getMjestoOdrzavanja());
            setDueli(obj.getDueli());
        }
        return *this;
    }


    // Z5.14 :: dodavanje duela (objekta tipa 'Par')
    bool dodajDuel(Sahist& s1, Sahist& s2) {
        return _dueli.add(Par<Sahist, Sahist>(s1, s2));
    }
    // Z5.15 :: destruktor
    ~SahovskiTurnir() {
        delete[] _naziv;
        _naziv = nullptr;
        delete[] _mjestoOdrzavanja;
        _mjestoOdrzavanja = nullptr;
    }
};

// Z5.16 :: ispisati naziv, mjesto, te sve duele
ostream& operator <<(ostream& COUT, SahovskiTurnir& st) {
    COUT << "Turnir: " << endl;
    COUT << st.getNaziv() << endl;
    COUT << "Mjesto odrzavanja: " << st.getMjestoOdrzavanja() << endl;
    COUT << "Dueli: ";
    cout << endl;
    for (int i = 0; i < st.getDueli().getTrenutno(); i++)
        COUT << *st.getDueli().getElementi()[i]<<endl;
    
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
