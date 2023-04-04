#include<iostream>
#include <string.h>

using namespace std;
//Koristene skracenice u komentarima
// dflt. = default
// user-def. = user-defined (korisnicki-definirano)
// ctor = constructor (konstruktor)
// copy ctor = copy constructor (konstruktor kopije)

//Z1.0
char* alocirajTekst(const char* tekst) {
    //Implementirati funkciju
    if(tekst==nullptr)
        return nullptr;
    int duzina = strlen(tekst) + 1;
    char* temp = new char[duzina];
    strcpy_s(temp, duzina, tekst);
    return temp;
}

class Datum
{
    int* _dan=nullptr;
    int* _mjesec{ nullptr };
    int* _godina{ nullptr };
public:
    //Z1.1 Dflt. ctor
  /*  Datum() {
        setDan(1);
        setMjesec(1);
        setGodina(2023);
    }*/
    //Z1.2 User-def. ctor
    Datum(int d=1, int m=1, int g=2023) {
        //Implementirati funkciju
        setDan(d);
        setMjesec(m);
        setGodina(g);
    }

    Datum(const Datum& obj)
    {
        setDan(obj.getDan());
        setMjesec(obj.getMjesec());
        setGodina(obj.getGodina());
    }
    //Z1.3
    int getDan() const {
        //Implementirati funkciju 
        if (_dan == nullptr)
            return 0;
        return *_dan;
    } 
    int getMjesec() const { 
        //Implementirati funkciju
        if(_mjesec==nullptr)
            return 0;
        return *_mjesec;
    }  
    int getGodina() const { 
        //Implementirati funkciju
        if(_godina==nullptr)
            return 0; 
        return *_godina;
    }  
    //Z1.4 
    void setDan(int dan) {
        if (_dan == nullptr)
            _dan = new int;
        *_dan = dan;
    }
    void setMjesec(int mjesec) {
        //Implementirati funkciju
        if (_mjesec == nullptr)
            _mjesec = new int;
        *_mjesec = mjesec;
    }
    void setGodina(int godina) {
        //Implementirati funkciju
        if (_godina == nullptr)
            _godina = new int;
        *_godina = godina;
    }
  
    //Z1.6
    void ispis() const {
        //Implementirati funkciju
        cout << getDan() << "." << getMjesec() << "." << getGodina() << endl;
    }
    //Z1.7
    ~Datum() {
        //Implementirati funkciju
        delete _dan;
        //_dan = nullptr;
        delete _mjesec;
        //_mjesec = nullptr;
        delete _godina;
        //_godina = nullptr;
        _dan = _mjesec = _godina = nullptr;
    }
};
class Zanr {
    char* _naziv;
    char _opis[200];
public:
    //Z2.1 Dflt. ctor
    Zanr() {
        //implementirati funkciju
        setNaziv("");
        setOpis("");
    }
    //Z2.2 user-def. ctor
    Zanr(const char* naziv, const char* opis)
    {
        //implementirati funkciju
        setNaziv(naziv);
        setOpis(opis);
    }
    //Z2.3 copy ctor
    Zanr(const Zanr& obj)
    {
        setNaziv(obj.getNaziv());
        setOpis(obj.getOpis());
    }
    //Z2.6
    void Ispis() {
        //implementirati funkciju
        cout << "Naziv zanra: " << getNaziv() << endl;
        cout << "Opis zanra: " << getOpis() << endl;
    }
    //Z2.5 destruktor
    ~Zanr()
    {
        //implementirati funkciju
        delete[] _naziv;
        _naziv = nullptr;
    }

    char* getNaziv() const { return _naziv; }
    const char* getOpis() const { return _opis; }

    void setNaziv(const char* naziv) { _naziv = alocirajTekst(naziv);}

    void setOpis(const char* opis) { strcpy_s(_opis, strlen(opis) + 1, opis);}
};

class Knjiga {
    char* _naziv;
    char _autor[50];
    Zanr* _zanr;
public:
    //Z3.1 dflt. ctor
    Knjiga()
    {
        //implementirati funkciju
    }

    //Z3.2 user-def. ctor
    Knjiga(const char* naziv, const char* autor, Zanr zanr) {
        //implementirati funkciju

    }

    //Z3.3 copy ctor
    Knjiga(const Knjiga& knjiga) {
        //implementirati funkciju

    }

    //Z3.4
    void Ispis() {
        //implementirati funkciju

    }

    //Z3.5
    ~Knjiga() {
        //implementirati funkciju
    }
};

class Biblioteka {
    char* _naziv;
    char* _adresa;
    Knjiga* _nizKnjiga;
    int _trenutnoKnjiga;
public:
    //Z4.1 dflt. ctor
    Biblioteka()
    {
        //implementirati funkciju

    }
    //Z4.2 user-def. ctor
    Biblioteka(const char* naziv, const char* adresa)
    {
        //implementirati funkciju
    }

    //Z4.3
    void Ispis() {
        //implementirati funkciju
    }

    bool DodajKnjigu(Knjiga k) {
        //implementirati funkciju
    }

    ~Biblioteka() {
        //implementirati funkciju
    }
};

int main() {
    Datum datum(1, 1, 2023);

    Datum* d2 = new Datum(datum);

    system("pause>0");
    return 0;
}
