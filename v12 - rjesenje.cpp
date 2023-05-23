#include <iostream>
#include <exception>
#include <functional>
using namespace std;
int Max(int a, int b) { return (a >= b) ? a : b; }
int Min(int a, int b) { return (a <= b) ? a : b; }
//Z0.1
bool CheckIfIsti(const char* str1, const char* str2)
{
    return (strcmp(str1, str2) == 0);
}
//Z0.2
char* Alokator(const char* str)
{
    if (str == nullptr)
        return nullptr;
    int duzina = strlen(str) + 1;
    char* temp = new char[duzina];
    strcpy_s(temp, duzina, str);
    return temp;
}

class Greska : public exception {
    int _linija;
    const char* _funkcija;
public:

    //Z0.4
    Greska(const char* poruka, int linija, const char* funkcija)
        : exception(poruka)
    {
        _linija = linija;
        _funkcija = funkcija;
    }
    //Z0.5
    Greska(const Greska& obj):exception(obj)
    {
        SetLinija(obj.GetLinija());
        SetFunkcija(obj.GetFunkcija());
    }
    //Z0.6
    const char* GetPoruka() const { return (*this).what(); }
    int GetLinija() const { return _linija; }
    const char* GetFunkcija() const { return _funkcija; }
    //Z0.8
    void SetLinija(int linija) { _linija = linija; }
    void SetFunkcija(const char* funkcija) {
        _funkcija = Alokator(funkcija);
    }
    //Z0.9
    Greska& operator =(const Greska& obj)
    {
        if (this != &obj)
        {
            SetLinija(obj.GetLinija());
            SetFunkcija(obj.GetFunkcija());
            (exception&)(*this) = (exception&)obj;
        }
        return *this;
    }
    //Z0.10
    ~Greska()
    {
        delete[] _funkcija;
        _funkcija = nullptr;
    }
};
//Z0.11
ostream& operator <<(ostream& COUT, const Greska& obj)
{
    COUT << "Greska: " << obj.GetPoruka() << endl;
    COUT << "Linija: " << obj.GetLinija() << endl;
    COUT << "Funkcija: " << obj.GetFunkcija() << endl;
    return COUT;
}

template<class T>
class Vektor {
private:
    int _trenutno;
    int _maxElemenata;
    T* _elementi=nullptr;
public:
    //Z1.1
    Vektor(int maxElemenata = 10)
    {
        _trenutno = 0;
        _maxElemenata = maxElemenata;
        _elementi = new T[_maxElemenata];
    }
    //Z1.2
    Vektor(const Vektor<T>& obj)
    {
        _trenutno = obj._trenutno;
        _maxElemenata = obj._maxElemenata;
        _elementi = new T[_maxElemenata];
        for (int i = 0; i < _trenutno; i++)
            _elementi[i] = obj._elementi[i];
    }
    //Z1.3
    Vektor<T>& operator = (const Vektor<T>& obj)
    {
        if (this != &obj)
        {
            if (_elementi != nullptr)
            {
                delete[] _elementi;
                _elementi = nullptr;
            }
            _trenutno = obj._trenutno;
            _maxElemenata = obj._maxElemenata;
            _elementi = new T[_maxElemenata];
            for (int i = 0; i < _trenutno; i++)
                _elementi[i] = obj._elementi[i];
        }
        return *this;
    }
    //Z1.5
    T& operator [] (int index) const
    {
        if (index<0 || index>_trenutno - 1)
            throw exception("Nevalidan index");
        return _elementi[index];
    }
    int GetTrenutno() const { return _trenutno; }
    T* GetElementi() const { return _elementi; }
    //Z1.6
    void ProsiriVektor(int prosiriZa)
    {
        T* temp = _elementi;
        //delete[] _elementi;
        _maxElemenata += prosiriZa;
        _elementi = new T[_maxElemenata];
        for (int i = 0; i < _trenutno; i++)
            _elementi[i] = temp[i];
        
    }

    //Z1.7 :: Dodavanje novog elementa 
    //Ukoliko je _elementi == nullptr, 
    // uraditi ponovnu alokaciju (_maxElemenata = 10)
    //Ukoliko je _trenutno == _maxElemenata, prosiriti niz za 10
    void operator += (T noviElement)
    {
        if (_elementi = nullptr)
        {
            _maxElemenata = 10;
            _trenutno = 0;
            _elementi = new T[_maxElemenata];
        }
        if (_trenutno == _maxElemenata)
            ProsiriVektor(10);

        _elementi[_trenutno] = noviElement;
        _trenutno++;
    }
    //Z1.8
    bool UkloniZadnjiElement()
    {
        if (_trenutno == 0)
            return false;
        _trenutno--;
        return true;
    }
    //Z1.9
    T* CheckIfSadrzi(T element)
    {
        for (int i = 0; i < _trenutno; i++)
            if (element == _elementi[i])
                return &_elementi[i];
        return nullptr;
    }
    //Z1.10
    bool Ukloni(T element)
    {
        auto adresa = CheckIfSadrzi(element);
        if (_elementi == nullptr || adresa == nullptr)
            return false;
        auto lokacija = adresa - _elementi;
        for (int i = lokacija; i < _trenutno - 1; i++)
            _elementi[i] = _elementi[i + 1];
        _trenutno--;
        return true;
    }
    //Z1.11
    bool UkloniAt(int index)
    {
        //auto adresa = CheckIfSadrzi(_elementi[index]);
        //if (_elementi == nullptr || adresa == nullptr)
        //    return false;
        //auto lokacija = adresa - _elementi;
        //for (int i = lokacija; i < _trenutno - 1; i++)
        //    _elementi[i] = _elementi[i + 1];
        //_trenutno--;
        //return true;
     /*   if (_elementi == nullptr)
            return false;
        for (int i = index; i < _trenutno-1; i++)
            _elementi[i] = _elementi[i + 1];
        _trenutno--;
        return true;*/
        return Ukloni(_elementi[index]);
    }
    ~Vektor()
    {
        delete[] _elementi;
        _elementi = nullptr;
    }
};
//Z1.16
template<class T>
ostream& operator << <>(ostream& COUT, const Vektor<T>& obj)
{
    COUT << "Elementi: " << endl;
    for (int i = 0; i < obj.GetTrenutno(); i++)
        COUT << obj[i] << endl;
    
    return COUT;
}
//Z1.17
template<class T>
void Ispis(const Vektor<T>& obj, const char* delimiter = " ")
{
    for (int i = 0; i < obj.GetTrenutn(); i++)
        cout << obj[i] << delimiter;
}
//Z1.18
template<class T>
bool operator == <>(const Vektor<T>& v1, const Vektor<T>& v2)
{
    if (v1.GetTrenutno() != v2.GetTrenutno())
        return false;
    for (int i = 0; i < v1.GetTrenutno(); i++)
        if (v1[i] != v2[i])
            return false;
    return true;
}
//Z1.19
template<class T>
bool operator != <>(const Vektor<T>& v1, const Vektor<T>& v2)
{
    return !(v1 == v2);
}
//Z1.20
template<class T>
bool operator == <>(const Vektor<const char*>& v1, const Vektor<const char*>& v2)
{
    if (v1.GetTrenutno() != v2.GetTrenutno())
        return false;
    for (int i = 0; i < v1.GetTrenutno(); i++)
        if (strcmp(v1[i], v2[i]) != 0)
            return false;
    return true;
}
//Z1.21
template<class T>
bool operator != <>(const Vektor<const char*>& v1, const Vektor<const char*>& v2)
{
    return !(v1 == v2);
}
enum class Spol { Muski = 1, Zenski = 0 };
enum class Boja { Plava, Zelena, Zuta, Crvena, Crna, Bijela };
//Z1.22
ostream& operator << (ostream& COUT, const Boja& obj)
{
    if (obj == Boja::Plava)
        COUT << "Plava";
    else if (obj == Boja::Zelena)
        COUT << "Zelena";
    else if (obj == Boja::Zuta)
        COUT << "Zuta";
    else if (obj == Boja::Bijela)
        COUT << "Bijela";
    else if (obj == Boja::Crna)
        COUT << "Crna";    
    else if (obj == Boja::Crvena)
        COUT << "Crvena";
    return COUT;
}

class Osoba {
protected:
    const char* _jmbg = nullptr;
    pair<char*, char*> _imePrezime;
    Spol* _spol = nullptr;
    float* _visina = nullptr;
    Boja* _bojaOciju = nullptr;
    Boja* _bojaKose = nullptr;
public:
    Osoba() {

    }
    //Z3.2
    Osoba(const char* jmbg, const char* ime, const char* prezime, Spol spol, float visina, Boja bojaOciju, Boja bojaKose)
    {
        SetJmbg(jmbg);
        SetIme(ime);
        SetPrezime(prezime);
        SetBojaKose(bojaKose);
        SetBojaOciju(bojaOciju);
        SetVisina(visina);
        SetSpol(spol);
    }
    //Z3.3
    Osoba(const Osoba& obj)
    {
        SetJmbg(obj.GetJmbg());
        SetIme(obj.GetIme());
        SetPrezime(obj.GetPrezime());
        SetBojaKose(obj.GetBojaKose());
        SetBojaOciju(obj.GetBojaOciju());
        SetVisina(obj.GetVisina());
        SetSpol(obj.GetSpol());
    }
    //Z3.4
    const char* GetJmbg() const {
        return _jmbg;
    }
    const char* GetIme() const { return _imePrezime.first; }
    const char* GetPrezime() const { return _imePrezime.second; }
    Spol GetSpol() const { 
        if (_spol == nullptr)
            return Spol::Muski;
        return *_spol; 
    }
    float GetVisina() const{
        if (_visina == nullptr)
            return 0.0f;
        return *_visina;
    }
    Boja GetBojaOciju() const
    {
        if (_bojaOciju == nullptr)
            return Boja::Bijela;
        return *_bojaOciju;
    }
    Boja GetBojaKose() const
    {
        if (_bojaKose == nullptr)
            return Boja::Zelena;
        return *_bojaKose;
    }
    //Z3.6
    void SetJmbg(const char* jmbg)
    {
        delete[] _jmbg;
        _jmbg = Alokator(jmbg);
    }
    void SetIme(const char* ime)
    {
        delete[] _imePrezime.first;
        _imePrezime.first = Alokator(ime);
    }
    void SetPrezime(const char* prezime)
    {
        delete[] _imePrezime.second;
        _imePrezime.second = Alokator(prezime);
    }
    void SetSpol(Spol spol)
    {
        if (_spol == nullptr)
            _spol = new Spol;
        *_spol = spol;
    }
    void SetVisina(float visina)
    {
        if (_visina == nullptr)
            _visina = new float;
        *_visina = visina;
    }
    void SetBojaOciju(Boja bojaOciju)
    {
        if (_bojaOciju == nullptr)
            _bojaOciju = new Boja;
        *_bojaOciju = bojaOciju;
    }
    void SetBojaKose(Boja bojaKose)
    {
        if (_bojaKose == nullptr)
            _bojaKose = new Boja;
        *_bojaKose = bojaKose;
    }
    //Z3.7
    Osoba& operator = (const Osoba& obj)
    {
        if (this != &obj)
        {
            SetJmbg(obj.GetJmbg());
            SetIme(obj.GetIme());
            SetPrezime(obj.GetPrezime());
            SetBojaKose(obj.GetBojaKose());
            SetBojaOciju(obj.GetBojaOciju());
            SetVisina(obj.GetVisina());
            SetSpol(obj.GetSpol());
        }
        return *this;
    }
    //Z3.8
    ~Osoba()
    {
        delete[] _imePrezime.first;
        _imePrezime.first = nullptr;
        delete[] _imePrezime.second;
        _imePrezime.second = nullptr;
        delete _visina;
        _visina = nullptr;
        delete _bojaKose;
        _bojaKose = nullptr;
        delete _bojaOciju;
        _bojaOciju = nullptr;
        delete _spol;
        _spol = nullptr;
        delete[] _jmbg;
        _jmbg = nullptr;
    }
};
//Z3.9
ostream& operator <<(ostream& COUT, const Osoba& osoba)
{
    COUT << "JMBG: " << osoba.GetJmbg() << endl;
    COUT << "Ime i prezime: " << osoba.GetIme() << " " << osoba.GetPrezime() << endl;
    COUT << "Spol: ";
    if (osoba.GetSpol() == Spol::Muski)
        COUT << "M" << endl;
    else
        COUT << "Z" << endl;
    COUT << "Visina: " << osoba.GetVisina() << endl;
    COUT << "Boja kose: " << osoba.GetBojaKose() << endl;
    COUT << "Boja ociju: " << osoba.GetBojaOciju() << endl;

    return COUT;
}
//Z3.10
bool operator == (const Osoba& o1, const Osoba& o2)
{
    return (strcmp(o1.GetJmbg(), o2.GetJmbg()) == 0);
}
bool operator != (const Osoba& o1, const Osoba& o2)
{
    return !(o1 != o2);
}

class Teniser : public Osoba {
protected:
    Vektor<const char*> _osvojeniNaslovi;
    int* _ranking;
public:
    Teniser();
    //Z4.2
    Teniser(const char* jmbg, const char* ime, const char* prezime, Spol spol, float visina, Boja bojaOciju, Boja bojaKose,
        Vektor<const char*> naslovi, int ranking);
    //Z4.3
    Teniser(const Teniser& obj);
    //Z4.4
    Vektor<const char*> GetOsvojeniNaslovi() const;
    int GetRanking() const;
    //Z4.6
    void SetOsvojeniNaslovi(Vektor<const char*> naslovi);
    void SetRanking(int ranking);
    //Z4.7
    Teniser& operator = (const Teniser& obj);
    //Z4.8
    void DodajOsvojeniNaslov(const char* naslov);
    //Z4.9
    ~Teniser();
};
//Z4.10
ostream& operator <<(ostream& COUT, const Teniser& teniser);
//Z4.11
bool operator == (const Teniser& t1, const Teniser& t2);
//Z4.12
bool operator != (const Teniser& t1, const Teniser& t2);
class Mec {
protected:
    Teniser* _prvi;
    Teniser* _drugi;
    Vektor<pair<int, int>> _setovi;
public:
    Mec();
    //Z5.2
    Mec(Teniser prvi, Teniser drugi);
    //Z5.3
    Mec(const Mec& obj);
    //Z5.4
    Mec(Mec&& obj);
    //Z5.5
    Teniser GetPrvi() const;
    Teniser GetDrugi() const;
    Vektor<pair<int, int>> GetSetovi() const;
    //Z5.6
    void SetPrvi(Teniser teniser);
    void SetDrugi(Teniser teniser);
    void SetSetovi(Vektor<pair<int, int>> setovi);
    //Z5.7
    void DodajSet(int bodovi1, int bodovi2);
    //Z5.8
    Mec& operator = (const Mec& obj);
    //Z5.9
    ~Mec();
};
//Z5.10
ostream& operator <<(ostream& COUT, const Mec& teniskiMec);
//Z5.11
bool operator == (const Mec& m1, const Mec& m2);
bool operator != (const Mec& m1, const Mec& m2);
auto IspisiPoruku = [](const char* tipFunkcije, bool success) {
    cout << tipFunkcije << " se izvrsio " << ((success) ? "uspjesno!" : "bezuspjesno!") << endl;
};
void Zadatak1() {

    Vektor<int> slucajniBrojevi;
    for (int i = 0; i < 30; i++)
        slucajniBrojevi += rand() % 40;
    cout << "Svi slucajni brojevi: " << endl;
    Ispis(slucajniBrojevi, " ");
    //Uklanjanje zadnjeg elementa
    cout << endl;
    slucajniBrojevi.UkloniZadnjiElement();
    cout << "Nakon uklanjanja zadnjeg ... " << endl;
    Ispis(slucajniBrojevi, " ");
    cout << endl;
    //Uklanjanje prvog elementa
    slucajniBrojevi.UkloniAt(0);
    cout << "Nakon uklanjanja prvog ... " << endl;
    Ispis(slucajniBrojevi, " ");
    cout << endl;

    //:::::::::::::::::: MAP ::::::::::::::::::
   
    //:::::::::::::::::: COPY CTOR | MOVE CTOR | OPERATOR '=' ::::::::::::::::::
    Vektor<int> v2(slucajniBrojevi);
    IspisiPoruku("Copy ctor", slucajniBrojevi == v2);
    Vektor<int> v3(v2);
    IspisiPoruku("Cpoy ctor", slucajniBrojevi == v3);
    Vektor<int> v4;
    v4 = slucajniBrojevi;
    IspisiPoruku("Operator '='", slucajniBrojevi == v4);
    //:::::::::::::::::: Testiranje funkcije Vektor<T>::Ukloni ::::::::::::::::::
    cout << endl << "Testiranje funkcije Vektor<T>::Ukloni" << endl;
    Vektor<int> noviVektor;
    noviVektor += 11;
    noviVektor += 2;
    noviVektor += 5;
    noviVektor += 5;
    noviVektor += 6;
    noviVektor += 7;
    noviVektor += 6;
    noviVektor += 11;
    Ispis(noviVektor, " ");
    int zaUklanjanje = 6;
    noviVektor.Ukloni(zaUklanjanje);
    cout << "Nakon uklanjanja (jedne instance) broja " << zaUklanjanje << endl;
    Ispis(noviVektor, " ");
    zaUklanjanje = 11;
    noviVektor.Ukloni(zaUklanjanje);
    cout << "Nakon uklanjanja (jedne instance) broja " << zaUklanjanje << endl;
    Ispis(noviVektor, " ");
    cout << endl << "Dealokacija..." << endl;
}
void Zadatak2() {
    Vektor<const char*> rijeci;
    const char* kolekcijaRijeci[] = { "reverenda","nakasljati se","podrugljivo", "trgnuti", "zajapuriti",
        "dozlogrditi", "zamajavati", "upravljati", "doskociti", "kalota" };
    for (size_t i = 0; i < size(kolekcijaRijeci); i++)
        rijeci += kolekcijaRijeci[i];
    Ispis(rijeci, ", ");
    //:::::::::::::::::: COPY CTOR | MOVE CTOR | OPERATOR '=' ::::::::::::::::::
    Vektor<const char*> v2(rijeci);
    IspisiPoruku("Copy ctor", rijeci == v2);
    Vektor<const char*> v3((v2));
    IspisiPoruku("Copy ctor", rijeci == v3);
    Vektor<const char*> v4;
    v4 = rijeci;
    IspisiPoruku("Operator '='", rijeci == v4);

  
    cout << endl << "Dealokacija..." << endl;
}
void Zadatak3() {
    Osoba putin;
    putin.SetJmbg ( "0710952215003");
    putin.SetIme ( "Vladimir");
    putin.SetPrezime( "Putin");
    putin.SetSpol( Spol::Muski);
    putin.SetBojaKose ( Boja::Plava);
    putin.SetBojaKose ( Boja::Plava);
    putin.SetVisina ( 1.68f);
    cout << putin << endl;
    //:::::::::::::::::: COPY CTOR | MOVE CTOR | OPERATOR '=' ::::::::::::::::::
    try
    {
        Osoba o2(putin);
        IspisiPoruku("Copy ctor", putin == o2);
        Osoba o3(move(o2));
        IspisiPoruku("Move ctor", putin == o3);
        Osoba o4;
        o4 = putin;
        IspisiPoruku("Operator '='", putin == o4);
        cout << endl << "Dealokacija..." << endl;
    }
    catch (const Greska& greska)
    {
        cout << greska << endl;
    }
}
void Zadatak4() {
    Vektor<const char*> titule;
    titule += "Australian Open 2020";
    titule += "Italian Open 2020";
    titule += "Cincinnati Masters 2020";
    Teniser djole;
    djole.SetJmbg("2205986345113");
    djole.SetIme("Novak");
    djole.SetPrezime( "Djokovic");
    djole.SetSpol( Spol::Muski);
    djole.SetVisina ( 1.88f);
    djole.SetBojaKose( Boja::Crna);
    djole.SetBojaOciju ( Boja::Zelena);
    djole.SetOsvojeniNaslovi ( titule);
    djole.SetRanking (11063);
    cout << djole << endl;
    //:::::::::::::::::: COPY CTOR | MOVE CTOR | OPERATOR '=' ::::::::::::::::::
    try {
        Teniser t2(djole);
        IspisiPoruku("Copy ctor", djole == t2);
        Teniser t3(move(t2));
        IspisiPoruku("Move ctor", djole == t3);
        Teniser t4;
        t4 = djole;
        IspisiPoruku("Operator '='", djole == t4);
        cout << endl << "Dealokacija..." << endl;
    }
    catch (const Greska& greska)
    {
        cout << greska << endl;
    }
}

void Zadatak5() {
    Teniser djole;
    djole.SetJmbg ( "2205986345113");
    djole.SetIme ("Novak");
    djole.SetPrezime ("Djokovic");
    djole.SetSpol( Spol::Muski);
    djole.SetVisina ( 1.88f);
    djole.SetBojaKose (Boja::Crna);
    djole.SetBojaOciju (Boja::Zelena);
    djole.SetRanking (11063);
    Teniser nadal;
    nadal.SetJmbg ("2304984344414");
    nadal.SetIme ("Rafael");
    nadal.SetPrezime ("Nadal");
    nadal.SetSpol (Spol::Muski);
    nadal.SetVisina ( 1.83f);
    nadal.SetBojaKose (Boja::Crna);
    nadal.SetBojaOciju (Boja::Crna);
    nadal.SetRanking ( 9500);
    Mec finale;
    finale.SetPrvi ( djole);
    finale.SetDrugi (nadal);
    finale.DodajSet(6, 1);
    finale.DodajSet(5, 7);
    finale.DodajSet(6, 4);
    cout << finale;
    //:::::::::::::::::: COPY CTOR | MOVE CTOR | OPERATOR '=' ::::::::::::::::::
    try
    {
        Mec m2(finale);
        IspisiPoruku("Copy ctor", finale == m2);
        Mec m3(move(m2));
        IspisiPoruku("Move ctor", finale == m3);
        Mec m4;
        m4 = finale;
        IspisiPoruku("Operator '='", finale == m4);
        cout << endl << "Dealokacija..." << endl;
    }
    catch (const Greska& greska)
    {
        cout << greska << endl;
    }
}
int main() {
    int nastaviDalje = 1;
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
        } while (izbor <= 0 || izbor > 5);
        switch (izbor) {
        case 1: Zadatak1(); cout << "Done." << endl; break;
        case 2: Zadatak2(); cout << "Done." << endl; break;
        case 3: Zadatak3(); cout << "Done." << endl; break;
        case 4: Zadatak4(); cout << "Done." << endl; break;
        case 5: Zadatak5(); cout << "Done." << endl; break;
        default:
            break;
        }
        do {
            cout << "DA LI ZELITE NASTAVITI DALJE? (1/0): ";
            cin >> nastaviDalje;
        } while (nastaviDalje != 0 && nastaviDalje != 1);
    }
    return 0;
}

