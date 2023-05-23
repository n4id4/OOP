#include <iostream>
#include <exception>
#include <functional>
using namespace std;
int Max(int a, int b) { return (a >= b) ? a : b; }
int Min(int a, int b) { return (a <= b) ? a : b; }
//Z0.1
bool CheckIfIsti(const char* str1, const char* str2);
//Z0.2
char* Alokator(const char* str);

class Greska : public exception {
    int _linija;
    const char* _funkcija;
public:

    //Z0.4
    Greska(const char* poruka, int linija, const char* funkcija);
    //Z0.5
    Greska(const Greska& obj);
    //Z0.6
    Greska(Greska&& obj);
    //Z0.7
    const char* GetPoruka() const;
    int GetLinija() const;
    const char* GetFunkcija() const;
    //Z0.8
    void SetLinija(int linija);
    void SetFunkcija(const char* funkcija);
    //Z0.9
    Greska& operator =(const Greska& obj);
    //Z0.10
    ~Greska();
};
//Z0.11
ostream& operator <<(ostream& COUT, const Greska& obj);
template<class T>
class Vektor {
private:
    int _trenutno;
    int _maxElemenata;
    T* _elementi;
public:
    //Z1.1
    Vektor(int maxElemenata = 10);
    //Z1.2
    Vektor(const Vektor<T>& obj);
    //Z1.3
    Vektor<T>& operator = (const Vektor<T>& obj);
    //Z1.5
    T& operator [] (int index) const;
    int GetTrenutno() const;
    T* GetElementi() const;
    //Z1.6
    void ProsiriVektor(int prosiriZa);

    //Z1.7 :: Dodavanje novog elementa 
    //Ukoliko je _elementi == nullptr, uraditi ponovnu alokaciju (_maxElemenata = 10)
    //Ukoliko je _trenutno == _maxElemenata, prosiriti niz za 10
    void operator += (T noviElement);
    //Z1.8
    bool UkloniZadnjiElement();
    //Z1.9
    T* CheckIfSadrzi(T element);
    //Z1.10
    bool Ukloni(T element);
    //Z1.11
    bool UkloniAt(int index);
    ~Vektor();
};
//Z1.16
template<class T>
ostream& operator << <>(ostream& COUT, const Vektor<T>& obj);
//Z1.17
template<class T>
void Ispis(const Vektor<T>& obj, const char* delimiter = " ");
//Z1.18
template<class T>
bool operator == <>(const Vektor<T>& v1, const Vektor<T>& v2);
//Z1.19
template<class T>
bool operator != <>(const Vektor<T>& v1, const Vektor<T>& v2);
//Z1.20
template<class T>
bool operator == <>(const Vektor<const char*>& v1, const Vektor<const char*>& v2);
//Z1.21
template<class T>
bool operator != <>(const Vektor<const char*>& v1, const Vektor<const char*>& v2);
enum class Spol { Muski = 1, Zenski = 0 };
enum class Boja { Plava, Zelena, Zuta, Crvena, Crna, Bijela };
//Z1.22
ostream& operator << (ostream& COUT, const Boja& obj);

class Osoba {
protected:
    const char* _jmbg;
    pair<char*,char*> _imePrezime;
    Spol* _spol;
    float* _visina;
    Boja* _bojaOciju;
    Boja* _bojaKose;
public:
    Osoba();
    //Z3.2
    Osoba(const char* jmbg, const char* ime, const char* prezime, Spol spol, float visina, Boja bojaOciju, Boja bojaKose);
    //Z3.3
    Osoba(const Osoba& obj);
    //Z3.4
    const char* GetJmbg() const;
    const char* GetIme() const;
    const char* GetPrezime() const;
    Spol GetSpol() const;
    float GetVisina() const;
    Boja GetBojaOciju() const;
    Boja GetBojaKose() const;
    //Z3.6
    void SetJmbg(const char* jmbg);
    void SetIme(const char* ime);
    void SetPrezime(const char* prezime);
    void SetSpol(Spol spol);
    void SetVisina(float visina);
    void SetBojaOciju(Boja bojaOciju);
    void SetBojaKose(Boja bojaKose);
    //Z3.7
    Osoba& operator = (const Osoba& obj);
    //Z3.8
    ~Osoba();
};
//Z3.9
ostream& operator <<(ostream& COUT, const Osoba& osoba);
//Z3.10
bool operator == (const Osoba& o1, const Osoba& o2);
bool operator != (const Osoba& o1, const Osoba& o2);

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

