#include <vector>
#include <iostream>
#include <cassert>
#include <functional>
using namespace std;

//Z0.1 
char* Alokator(const char* tekst)
{
    if (tekst == nullptr)
        return nullptr;
    int duzina = strlen(tekst) + 1;
    char* temp = new char[duzina];
    strcpy_s(temp, duzina, tekst);
    return temp;
}
//Z0.2
int IzracunajBrojZnamenki(int broj)
{
    return log10(broj) + 1;
}
//Z0.3 :: Pretvoriti (int) u (char*).
char* IntToStr(int broj)
{
    char brojNiz[5];
    _itoa_s(broj, brojNiz, 10);
    return brojNiz;
}

//Z0.6:: Provjeriti da li su dva niza karaktera ista (po vrijednosti)
bool CheckIfIsti(const char* tekst1, const char* tekst2)
{
    return (strcmp(tekst1, tekst2) == 0);
}
//Z0.7 Provjeriti da li su dva vektora jednaka (da li imaju iste elemente)
template<class T>
bool operator == (const vector<T>& v1, const vector<T>& v2)
{
    if (v1.size() != v2.size())
        return false;
    for (int i = 0; i < v1.size(); i++)
        if (v1.at(i) != v2.at(i))
            return false;
    return true;
}
template<class T>
bool operator != (const vector<T>& v1, const vector<T>& v2)
{
    return !(v1 == v2);
}
//Z0.8 Provjeriti da li su dva vektora nizova karaktera jednaka 
//(da li imaju iste elemente)
bool CheckIfIsti(const vector<const char*>& v1, const vector<const char*>& v2)
{
    if (v1.size() != v2.size())
        return false;
    for (int i = 0; i < v2.size(); i++)
        if (strcmp(v1.at(i), v2.at(i)) != 0)
            return false;
    return true;
}

class Uredjaj {
private:
    const char* _id;
protected:
    char* _naziv;
    int _godinaProizvodnje;
    float* _cijena;
    int* _garancija;
    vector<int> _ocjene;
public:
    //Z1.0 :: Staticka metoda koja vraca niz karaktera (brojeva) u opsegu "10000" do "99999"
    static const char* GetRandomId()
    {
        return (IntToStr(rand() % 100000));
    }
    //Z1.1 :: Postaviti '_id' na rezultat koji vrati staticka funkcija 'GetRandomId'
    Uredjaj()
    {
        _id = Alokator(GetRandomId());
        _naziv = nullptr;
        _godinaProizvodnje = 2023;
        _cijena = new float(0);
        _garancija = new int(0);

    }
    //Z1.2
    Uredjaj(const char* naziv, int godinaProizvodnje, float cijena, int garancija)
    {
        _id = Alokator(GetRandomId());
        SetNaziv(naziv);
        SetGodinaProizvodnje(godinaProizvodnje);
        SetCijena(cijena);
        SetGarancija(garancija);
    }
    //Z1.3 :: mozete koristiti property-je drugog (vec postojeceg) objekta za pristup vrijednostima njegovih atributa
    //Kopirati sve atribute, ukljucujuci i polje '_id'
    Uredjaj(const Uredjaj& obj)
    {
        SetId(obj.GetId());
        SetNaziv(obj.GetNaziv());
        SetCijena(obj.GetCijena());
        SetGarancija(obj.GetGarancija());
        SetOcjene(obj.GetOcjene());
    }
    //Z1.5
    const char* GetId() const { return _id; }
    const char* GetNaziv() const { return _naziv; }
    int GetGodinaProizvodnje() const { return _godinaProizvodnje; }
    float GetCijena() const
    {
        if (_cijena == nullptr)
            return 0;
        return *_cijena;
    }
    int GetGarancija() const
    {
        if (_garancija == nullptr)
            return 0;
        return *_garancija;
    }
    vector<int> GetOcjene() const { return _ocjene; }

    //Z1.6
    void SetId(const char* id) {
        delete[] _id;
        _id = Alokator(id);
    }
    void SetNaziv(const char* naziv)
    {
        delete[] _naziv;
        _naziv = Alokator(naziv);
    }
    void SetGodinaProizvodnje(int godinaProizvodnje)
    {
        _godinaProizvodnje = godinaProizvodnje;
    }
    void SetCijena(float cijena)
    {
        if (_cijena == nullptr)
            _cijena = new float;
        *_cijena = cijena;
    }
    void SetGarancija(int garancija)
    {
        if (_garancija == nullptr)
            _garancija = new int;
        *_garancija = garancija;
    }
    void SetOcjene(vector<int> ocjene)
    {
        _ocjene = ocjene;
    }
    //Z1.7 :: mozete koristiti property-je za oba objekta (obzirom da vec postoje)
    Uredjaj& operator =(const Uredjaj& obj)
    {
        if (this != &obj)
        {
            SetId(obj.GetId());
            SetNaziv(obj.GetNaziv());
            SetCijena(obj.GetCijena());
            SetGarancija(obj.GetGarancija());
            SetOcjene(obj.GetOcjene());
        }
        return *this;
    }
    //Z1.8
    void AddOcjena(int ocjena)
    {
        _ocjene.push_back(ocjena);
    }

    //Z1.9 :: Mozete koristiti property-je obzirom da objekt vec postoji
    float GetProsjecnaOcjena()
    {
        int suma = 0;
        for (int i = 0; i < _ocjene.size(); i++)
            suma += _ocjene[i];
        
        return float(suma) / _ocjene.size();
    }
    //Z1.10 :: implementacija funkcije 'Ispis' se prepisuje (override-a) sa implementacijom istoimene funkcije  najizvedenije klase
    // Mozete koristiti property-je obzirom da objekt vec postoji
    virtual void Ispis() {
        cout << "ID: " << GetId() << endl;
        cout << "Naziv: " << GetNaziv() << endl;
        cout << "Cijena: " << GetCijena() << endl;
        cout << "Garancija: " << GetGarancija() << endl;
    }
    //Z1.11
    virtual ~Uredjaj()
    {
        delete[] _id;
        _id = nullptr;
        delete[] _naziv;
        _naziv = nullptr;
        delete _garancija;
        _garancija = nullptr;
        delete _cijena;
        _cijena = nullptr;
    }
};

//Z1.12
//Iskljuciti polje 'Id' iz uporedbe
bool operator == (const Uredjaj& u1, const Uredjaj& u2)
{
    return (strcmp(u1.GetNaziv(), u2.GetNaziv()) == 0 &&
        u1.GetCijena() == u2.GetCijena() && u1.GetGarancija() == u2.GetGarancija()
        && u1.GetGodinaProizvodnje() == u2.GetGodinaProizvodnje()
        && u1.GetOcjene() == u2.GetOcjene());
}
bool operator != (const Uredjaj& u1, const Uredjaj& u2)
{
    return !(u1 == u2);
}

class Mobitel : public Uredjaj {
private:
    char _operativniSistem[50];
    float* _velicinaEkrana;//u incima Npr. 6.1
    int* _memorija; //GB
public:
    //Z3.1
    Mobitel():Uredjaj()
    {
        _velicinaEkrana = new float(0);
        _memorija = new int(0);
    }
    //Z2.2
    Mobitel(const char* naziv, int godinaP, float cijena, int garancija, const char* operativniS, float velicinaE, int memorija)
        : Uredjaj(naziv, godinaP, cijena, garancija)
    {
        SetOperativniSistem(operativniS);
        SetVelicinaEkrana(velicinaE);
        SetMemorija(memorija);
    }
    //Z2.3
    Mobitel(const Mobitel& mobitel): Uredjaj(mobitel)
    {
        SetOperativniSistem(mobitel.GetOperativniSistem());
        SetVelicinaEkrana(mobitel.GetVelicinaEkrana());
        SetMemorija(mobitel.GetMemorija());
    }
    //Z2.4

    const char* GetOperativniSistem()const { return _operativniSistem; }
    float GetVelicinaEkrana()const
    {
        if (_velicinaEkrana == nullptr)
            return 0;
        return *_velicinaEkrana;
    }
    int GetMemorija()const
    {
        if (_memorija == nullptr)
            return 0;
        return *_memorija;
    }

    void SetOperativniSistem(const char* operativniSistem)
    {
        strcpy_s(_operativniSistem, strlen(operativniSistem) + 1, operativniSistem);
    }
    void SetVelicinaEkrana(float velicinaEkrana)
    {
        if (_velicinaEkrana == nullptr)
            _velicinaEkrana = new float;
        *_velicinaEkrana = velicinaEkrana;
    }
    void SetMemorija(int memorija)
    {
        if (_memorija == nullptr)
            _memorija = new int;
        *_memorija = memorija;
    }
    //Z2.5
    Mobitel& operator = (const Mobitel& obj)
    {
        if (this != &obj)
        {
            SetOperativniSistem(obj.GetOperativniSistem());
            SetVelicinaEkrana(obj.GetVelicinaEkrana());
            SetMemorija(obj.GetMemorija());
            (Uredjaj&)(*this) = obj;
            //Uredjaj::operator=(obj);
        }
        return *this;
    }
    //Z2.6
    //Ispisati id, naziv mobitela, velicinu ekrana, operativni sistem, kolicinu memorije, cijenu te broj godina garancije
    void Ispis()
    {
        Uredjaj::Ispis();
        cout << "Vel. ekrana: " << GetVelicinaEkrana() << endl;
        cout << "OS: " << GetOperativniSistem() << endl;
        cout << "Memorija: " << GetMemorija() << endl;
    }
    //Z2.7
    ~Mobitel()
    {
        delete _memorija, delete _velicinaEkrana;
        _memorija = nullptr, _velicinaEkrana = nullptr;
    }
};
//Z2.8
bool operator == (const Mobitel& m1, const Mobitel& m2)
{
    return ((Uredjaj&)m1 == m2 && m1.GetVelicinaEkrana() == m2.GetVelicinaEkrana()
        && m1.GetMemorija() == m2.GetMemorija()
        && strcmp(m1.GetOperativniSistem(), m2.GetOperativniSistem()) == 0);
}
bool operator != (const Mobitel& m1, const Mobitel& m2)
{
    return !(m1 == m2);
}

class Televizor : public Uredjaj {
    float _velicinaEkrana;
    char* _tipEkrana;
    pair<int, int> _rezolucija;
    vector<const char*> _prikljucci;
public:
    //Z3.1
    Televizor():Uredjaj()
    {
    }
    //Z3.2
    Televizor(const char* naziv, int godinaP, float cijena, int garancija,
        float velicinaEkrana, const char* tipEkrana, pair<int, int> rezolucija)
        :Uredjaj(naziv, godinaP, cijena, garancija)
    {
        SetVelicinaEkrana(velicinaEkrana);
        SetTipEkrana(tipEkrana);
        SetRezolucija(rezolucija);
    }
    //Z3.3
    Televizor(const Televizor& obj):Uredjaj(obj)
    {
        SetVelicinaEkrana(obj.GetVelicinaEkrana());
        SetTipEkrana(obj.GetTipEkrana());
        SetRezolucija(obj.GetRezolucija());
        SetPrikljucci(obj.GetPrikljucci());
    }
    //Z3.4

    float GetVelicinaEkrana()const { return _velicinaEkrana; }
    const char* GetTipEkrana()const { return _tipEkrana; }
    pair<int, int> GetRezolucija()const { return _rezolucija; }
    vector<const char*> GetPrikljucci()const { return _prikljucci; }

    void SetVelicinaEkrana(float velicinaEkrana) { _velicinaEkrana = velicinaEkrana; }
    void SetTipEkrana(const char* tipEkrana) { 
        delete[] _tipEkrana;
        _tipEkrana = Alokator(tipEkrana);
    }
    void SetRezolucija(pair<int, int> rezolucija)
    {
        //_rezolucija.first=rezolucija.first;
        //_rezolucija.second = rezolucija.second;
        _rezolucija = rezolucija;
    }
    void SetPrikljucci(vector<const char*>prikljucci)
    {
        for (int i = 0; i < prikljucci.size(); i++)
            _prikljucci.push_back(prikljucci.at(i));
        
    }

    //Z3.5
    Televizor& operator = (const Televizor& obj)
    {
        if (this != &obj)
        {
            SetVelicinaEkrana(obj.GetVelicinaEkrana());
            SetTipEkrana(obj.GetTipEkrana());
            SetRezolucija(obj.GetRezolucija());
            SetPrikljucci(obj.GetPrikljucci());
        }
        return *this;
    }
    void operator+=(const char* prikljucak)
    {
        _prikljucci.push_back(prikljucak);
    }

    //Z3.6
    //Ispisati id, naziv TV-a, velicinu ekrana, tip ekrana, rezoluciju, cijenu, broj godina garancije, te sve prikljucke
    void Ispis()
    {
        Uredjaj::Ispis();
        cout << "Velicina: " << GetVelicinaEkrana() << endl;
        cout << "Rezolucija: " << GetRezolucija().first << "x" << GetRezolucija().second << endl;
        for (int i = 0; i < _prikljucci.size(); i++)
            cout << GetPrikljucci().at(i);
        
    }
    //Z3.7
    ~Televizor()
    {
        delete[] _tipEkrana;
        _tipEkrana = nullptr;
    }
};

bool operator == (const Televizor& t1, const Televizor& t2)
{
    return ((Uredjaj&)t1 == t2 && CheckIfIsti(t1.GetPrikljucci(), t2.GetPrikljucci())
        && strcmp(t1.GetTipEkrana(), t2.GetTipEkrana()) == 0
        && t1.GetRezolucija() == t2.GetRezolucija()
        && t1.GetVelicinaEkrana() == t2.GetVelicinaEkrana());
}
bool operator != (const Televizor& t1, const Televizor& t2)
{
    return !(t1 == t2);
}

class Printer : public Uredjaj {
    int* _brzinaPrintanja; // br. str. po minuti
public:
    //Z4.1
    Printer();
    //Z4.2
    Printer(const char* naziv, int godinaP, float cijena, int garancija, int brzinaPrintanja);
    //Z4.3
    Printer(const Printer& obj);

    int GetBrzinaPrintanja() const;
    void SetBrzinaPrintanja(int brzinaPrintanja);
    //Z4.5
    Printer& operator= (const Printer& obj);
    //Z4.6
    //Ispisati id, naziv, brzinu printanja, cijenu te broj godina garancije
    void Ispis();
    //Z4.7
    ~Printer();
};
//Z4.8
bool operator == (const Printer& p1, const Printer& p2);
bool operator != (const Printer& p1, const Printer& p2);

class WebShop {
    char* _naziv;
    char _emailAdresa[100];
    int _trenutnoUredjaja;
    Uredjaj* _uredjaji[100] = { nullptr };
public:
    //Z5.1
    WebShop() {
        _naziv = nullptr;
        _trenutnoUredjaja = 0;
    }
    //Z5.2
    WebShop(const char* naziv, const char* emailAdresa)
    {
        SetNaziv(naziv);
        SetEmailAdresa(emailAdresa);
        _trenutnoUredjaja = 0;
    }
    //Z5.3
    WebShop(const WebShop& obj)
    {
        SetNaziv(obj.GetNaziv());
        SetEmailAdresa(obj.GetEmailAdresa());
        _trenutnoUredjaja = obj.GetTrenutnoUredjaja();
        for (int i = 0; i < _trenutnoUredjaja; i++)
            _uredjaji[i] = new Uredjaj(*obj.GetElementAt(i));
        
    }

    const char* GetNaziv() const { return _naziv; }
    const char* GetEmailAdresa() const { return _emailAdresa; }
    int GetTrenutnoUredjaja() const { return _trenutnoUredjaja; }
    Uredjaj* GetElementAt(int index) const { return _uredjaji[index]; }

    void SetNaziv(const char* naziv)
    {
        delete[] _naziv;
        _naziv = Alokator(naziv);
    }
    void SetEmailAdresa(const char* emailAdresa)
    {
        strcpy_s(_emailAdresa, strlen(emailAdresa) + 1, emailAdresa);
    }
    //Z5.5
    WebShop& operator = (const WebShop& obj)
    {
        if (this != &obj)
        {
            SetNaziv(obj.GetNaziv());
            SetEmailAdresa(obj.GetEmailAdresa());
            for (int i = 0; i < _trenutnoUredjaja; i++)
            {
                delete _uredjaji[i];
                _uredjaji[i] = nullptr;
            }
            _trenutnoUredjaja = obj.GetTrenutnoUredjaja();
            for (int i = 0; i < _trenutnoUredjaja; i++)
                _uredjaji[i] = new Uredjaj(*obj.GetElementAt(i));
        }
        return *this;
    }
    //Z5.6 :: Dodavanje novog elementa u niz pokazivaca
    template <class T>
    bool DodajUredjaj(T uredjaj)
    {
        _uredjaji[_trenutnoUredjaja++] = new Uredjaj(uredjaj);
    }
    //Z5.7
    ~WebShop()
    {
        delete[] _naziv;
        _naziv = nullptr;
        for (int i = 0; i < _trenutnoUredjaja; i++)
        {
            delete _uredjaji[i];
            _uredjaji[i] = nullptr;
        }
    }
    friend ostream& operator << (ostream& COUT, const WebShop& webShop);
};
//Z5.8
ostream& operator << (ostream& COUT, const WebShop& obj);
//Z5.9
bool operator == (const WebShop& shop1, const WebShop& shop2);
auto IspisiPoruku = [](const char* tipFunkcije, bool success) {
    cout << tipFunkcije << " se izvrsio " << ((success) ? "uspjesno!" : "bezuspjesno!") << endl;
};
void Zadatak1() {
    //Generator ocjena
    const int max = 20;
    vector<int> ocjene;
    for (int i = 0; i < max; i++)
        ocjene.push_back(rand() % 5 + 1);
    //Testiranje klase 'Uredjaj'
    Uredjaj monitor;
    monitor.SetNaziv("LED monitor");
    monitor.SetGodinaProizvodnje(2017);
    monitor.SetCijena(250);
    monitor.SetGarancija(2);
    monitor.SetOcjene(ocjene);
    monitor.Ispis();
    cout << endl;
    Uredjaj monitor2("LED monitor", 2017, 250, 2);
    monitor2.SetOcjene(monitor.GetOcjene());
    IspisiPoruku("User-def. ctor", monitor == monitor2);
    Uredjaj monitor3(monitor);
    IspisiPoruku("Copy ctor", monitor == monitor3);
    Uredjaj monitor4(move(monitor2));
    IspisiPoruku("Move ctor", monitor == monitor4);
    Uredjaj monitor5;
    monitor5 = monitor;
    IspisiPoruku("Operator '='", monitor == monitor5);
    cout << endl << "Dealokacija..." << endl;
}
void Zadatak2() {
    Mobitel ironPhone;
    ironPhone.SetNaziv("Iron Phone S Ultra");
    ironPhone.SetGodinaProizvodnje(2021);
    ironPhone.SetCijena(1200);
    ironPhone.SetGarancija(2);
    ironPhone.SetOperativniSistem("Onyx");
    ironPhone.SetVelicinaEkrana(6.1f);
    ironPhone.SetMemorija(16);
    ironPhone.Ispis();
    cout << endl;
    Mobitel ironPhone2("Iron Phone S Ultra", 2021, 1200, 2, "Onyx", 6.1f, 16);
    IspisiPoruku("User-def. ctor", ironPhone == ironPhone2);
    Mobitel ironPhone3(ironPhone);
    IspisiPoruku("Copy ctor", ironPhone == ironPhone3);
    Mobitel ironPhone4(move(ironPhone2));
    IspisiPoruku("Move ctor", ironPhone == ironPhone4);
    cout << endl << "Dealokacija..." << endl;
}
void Zadatak3() {
    vector<const char*> prikljucci;
    prikljucci.push_back("USB-C");
    prikljucci.push_back("HDMI");
    prikljucci.push_back("S-Video");
    Televizor chromethius;
    chromethius.SetNaziv("Chromethius");
    chromethius.SetGodinaProizvodnje(2020);
    chromethius.SetCijena(700);
    chromethius.SetGarancija(2);
    chromethius.SetVelicinaEkrana(43.5);
    chromethius.SetTipEkrana("LED");
    chromethius.SetRezolucija(pair<int, int>(3840, 2160));
    chromethius.SetPrikljucci(prikljucci);
    chromethius.Ispis();
    cout << endl;
    Televizor chromethius2("Chromethius", 2020, 700, 2, 43.5, "LED", pair<int, int>(3840, 2160));
    chromethius2.SetPrikljucci(chromethius.GetPrikljucci());
    IspisiPoruku("User-def. ctor", chromethius == chromethius2);
    Televizor chromethius3(chromethius);
    IspisiPoruku("Copy ctor", chromethius == chromethius3);
    Televizor chromethius4(move(chromethius2));
    cout << endl << "Dealokacija..." << endl;
}
void Zadatak4() {
    Printer optomec;
    optomec.SetNaziv("Optomec X-40");
    optomec.SetGodinaProizvodnje(2021);
    optomec.SetCijena(550);
    optomec.SetGarancija(2);
    optomec.SetBrzinaPrintanja(30);
    optomec.Ispis();
    //Testiranje user-def. ctora
    Printer optomec2("Optomec X-40", 2021, 550, 2, 30);
    IspisiPoruku("User-def. ctor", optomec == optomec2);
    //Testiranje copy ctora
    Printer optomec3(optomec);
    IspisiPoruku("Copy ctor", optomec == optomec3);
    //Testiranje move ctora
    Printer optomec4(optomec2);
    Printer optomec5;
    optomec5 = optomec;
    IspisiPoruku("Operator '='", optomec == optomec5);
    cout << endl << "Dealokacija..." << endl;
}
void Zadatak5() {
    //WebShop
    WebShop bosnianVortex;
    bosnianVortex.SetNaziv("Bosnian Vortex");
    bosnianVortex.SetEmailAdresa("bosnian.vortex@gmail.com");
    //Uredjaji
    Uredjaj napojna("Corsair Napojna jedinica", 2018, 159.0, 2);
    Mobitel wikkoJerry("WIKO JERRY 3 ANTHRACITE", 2019, 149.0, 2, "Android 8.1", 5.45f, 16);
    Televizor phillipsTV("PHILIPS LED TV AMBILIGHT", 2019, 899.0, 3, 43.0, "LED", pair<int, int>(3840, 2160));
    Printer officeJet("B-HP OFFICEJET 202", 2019, 549.0, 2, 20);
    //Dodavanje razlicitih tipova uredjaja
    bosnianVortex.DodajUredjaj<Uredjaj>(napojna); //Mozete izostaviti naziv generickog tipa tj: bosnianVortex.DodajUredjaj(napojna);
    bosnianVortex.DodajUredjaj<Mobitel>(wikkoJerry);
    bosnianVortex.DodajUredjaj<Televizor>(phillipsTV);
    bosnianVortex.DodajUredjaj<Printer>(officeJet);
    //Testiranje user-def. ctora
    WebShop bosnianVortex2("Bosnian Vortex", "bosnian.vortex@gmail.com");
    bosnianVortex2.DodajUredjaj(napojna);
    bosnianVortex2.DodajUredjaj(wikkoJerry);
    bosnianVortex2.DodajUredjaj(phillipsTV);
    bosnianVortex2.DodajUredjaj(officeJet);
    cout << bosnianVortex << endl;
    IspisiPoruku("User-def. ctor", bosnianVortex2 == bosnianVortex);
    //Testiranje copy ctora
    WebShop bosnianVortex3(bosnianVortex);
    IspisiPoruku("Copy ctor", bosnianVortex3 == bosnianVortex);
    //Testiranje move ctora
    WebShop bosnianVortex4(bosnianVortex2);
    cout << endl << "Dealokacija..." << endl;
}
void Menu() {
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
        case 1: Zadatak1(); cout << "Zadatak 1. Done." << endl; break;
        case 2: Zadatak2(); cout << "Zadatak 2. Done." << endl; break;
        case 3: Zadatak3(); cout << "Zadatak 3. Done." << endl; break;
        case 4: Zadatak4(); cout << "Zadatak 4. Done." << endl; break;
        case 5: Zadatak5(); cout << "Zadatak 5. Done." << endl; break;
        default:break;
        }
        do {
            cout << "DA LI ZELITE NASTAVITI DALJE? (1/0): ";
            cin >> nastaviDalje;
        } while (nastaviDalje != 0 && nastaviDalje != 1);
    }
}

int main() {
    Menu();
    return 0;
}
