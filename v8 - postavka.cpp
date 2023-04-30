#include <iostream>
using namespace std;

enum GODINA_STUDIJA{PRVA, DRUGA, TRECA, CETVRTA};

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
    int getDan() const { return (_dan == nullptr) ? 1 : *_dan; }
    int getMjesec() const { return (_mjesec == nullptr) ? 1 : *_mjesec; }
    int getGodina() const { return (_godina == nullptr) ? 1 : *_godina;}

    void setDan(int dan) {
        // implementirati funkciju
    }
    void setMjesec(int mjesec) {
        // implementirati funkciju
    }
    void setGodina(int godina) {
        // implementirati funkciju
    }

    Datum() {
    }

    Datum(int d, int m, int g) {
        // implementirati funkciju
    }

    Datum(const Datum& obj) {
        // implementirati funkciju
    }

    Datum& operator =(const Datum& obj) {
        // implementirati funkciju
        return *this;
    }

    ~Datum() {
        // implementirati funkciju
    }
};

ostream& operator << (ostream& COUT, const Datum& obj) {
    // implementirati funkciju
    return COUT;
}

bool operator == (const Datum& d1, const Datum& d2) {
    // implementirati funkciju
    return false;
}
bool operator != (const Datum& d1, const Datum& d2) {
    // implementirati funkciju
    return false;
}

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

template<class T1, class T2, int max = 10>
class Kolekcija {
    T1* _elementi1[max] = { nullptr };
    T2* _elementi2[max] = { nullptr };
    int* _trenutno;
public:
    Kolekcija() { _trenutno = new int(0); }

    Kolekcija(const Kolekcija& obj) {
        // implementirati funkciju

    }

    void AddElement(T1 el1, T2 el2) {
        // implementirati funkciju

    }

    Kolekcija& operator=(const Kolekcija& obj) {
        // implementirati funkciju
    }
    ~Kolekcija() {
        // implementirati funkciju

    }

    T2& operator[](T1 vrijednost) {
        // implementirati funkciju

    }


    void RemoveAt(int lokacija) {
        // implementirati funkciju
    }

    void AddElement(T1 el1, T2 el2, int lokacija) {
        // implementirati funkciju
    }

    T1& getElement1(int lokacija)const { return *_elementi1[lokacija]; }
    T2& getElement2(int lokacija)const { return *_elementi2[lokacija]; }
    int getTrenutno() { return *_trenutno; }
    friend ostream& operator<< (ostream& COUT, const Kolekcija& obj) {
        for (size_t i = 0; i < *obj._trenutno; i++)
            COUT << obj.getElement1(i) << " " << obj.getElement2(i) << endl;
        return COUT;
    }
};

class Predmet {
    char* _naziv = nullptr;
    int _ECTS;
public:
    const char* getNaziv()const { return _naziv; }
    int getECTS() const { return _ECTS; }

    void setNaziv(const char* naziv)
    {
        delete[] _naziv;
        _naziv = alocirajTekst(naziv);
    }

    void setECTS(int ECTS)
    {
        _ECTS = ECTS;
    }

    Predmet() {
        // implementirati funkciju

    }

    Predmet(const Predmet& obj)
    {
        // implementirati funkciju

    }

    Predmet& operator=(const Predmet& obj)
    {
        // implementirati funkciju
        return *this;
    }
    //porediti predmete po nazivu i broju ECTS bodova
    bool operator==(Predmet& p)
    {
        // implementirati funkciju
        return false;
    }

    bool operator!=(Predmet& p)
    {
        // implementirati funkciju
        return false;

    }

    friend ostream& operator<<(ostream& COUT, const Predmet& obj)
    {
        return COUT;
    }
};

class Student {
    const char* _brojIndeksa = nullptr;;
    const char* _imePrezime = nullptr;
    GODINA_STUDIJA _godStudija;
    Datum _datumRodjenja;
    bool* _spol = nullptr;
    Kolekcija<Predmet, int> _ocjene;
public:
    const char* getBrojIndeksa() const { return (_brojIndeksa == nullptr) ? "" : _brojIndeksa; }
    const char* getImePrezime() const { return (_imePrezime == nullptr) ? "" : _imePrezime; }
    GODINA_STUDIJA getGodStudija() const { return _godStudija; }
    Datum getDatumRodjenja() const { return _datumRodjenja; }
    bool getSpol() const { return (_spol == nullptr) ? false : *_spol; }
    int getOcjenaForPredmet(Predmet p){
        //implementirati funkciju 
    }
    // Z4.2 :: setteri
    void setBrojIndeksa(const char* brojIndeksa)
    {
        // implementirati funkciju
    }

    void setImePrezime(const char* imePrezime) {
        // implementirati funkciju
    }
    void setGodStudija(GODINA_STUDIJA godina) {
        // implementirati funkciju

    }
    void setDatumRodjenja(Datum datumRodjenja) {
        // implementirati funkciju
    }
    void setSpol(bool spol) {
        // implementirati funkciju
    }
    //omoguciti dodavanje ocjene za predmet, u kolekciji se za jedan predmet moze dodati samo jedna ocjena ( ne smije biti duplikata)
    void AddOcjenaForPredmet(Predmet p, int ocjena)
    {
        // implementirati funkciju

    }
    Student() {}
 
    // Z4.5 :: copy ctor
    Student(const Student& obj) {
        // implementirati funkciju
    }

    // Z4.6 :: operator '='
    Student& operator = (const Student& obj) {
        // implementirati funkciju
        return *this;
    }
    // Z4.7 :: destruktor
    ~Student() {
        // implementirati funkciju
    }

    float prosjekOcjena()
    {
        // implementirati funkciju
        return 0.0f;
    }
};
ostream& operator << (ostream& COUT, const Student& obj) {
    // implementirati funkciju
    return COUT;
}

bool operator == (const Student& obj1, const Student& obj2) {
    // implementirati funkciju
    return false;
}
bool operator != (const Student& obj1, const Student& obj2) {
    // implementirati funkciju
    return false;
}

Student getNajboljiStudent(Student studenti[]) {
    // implementirati funkciju
    return Student();
}


template<class T1, class T2>
class Par {
    T1 _lijevi;
    T2 _desni;
public:
    T1 getLijevi() const { return _lijevi; }
    T2 getDesni() const { return _desni; }

    void setLijevi(T1 el) {
        // implementirati funkciju
    }
    void setDesni(T2 el) {
        // implementirati funkciju
    }
    Par() {
    }
    Par(T1 el1, T2 el2) {
        // implementirati funkciju
    }
    Par(const Par<T1, T2>& obj) {
        // implementirati funkciju
    }
    Par<T1, T2>& operator = (const Par<T1, T2>& obj) {
        // implementirati funkciju
    }
};

template<class T1, class T2>
ostream& operator << (ostream& COUT, const Par<T1, T2>& par) {
    // implementirati funkciju
    return COUT;
}
template<class T, int max> //max oznacava velicinu niza
class Array {
    int _trenutno = 0; // trenutno elemenata 
    T* _elementi[max] = { nullptr }; // staticki niz pokazivaca
public:
    int getTrenutno() const { return _trenutno; }
    T** getElementi() const { return (T**)_elementi; }

    void setElementi(int trenutno, T** elementi = nullptr) {
        // implementirati funkciju
    }
    // ukoliko je brojac dosao do kraja niza, onemoguciti dodavanje
    bool add(const T& element) {
        // implementirati funkciju
        return false;
    }

    bool removeZadnji() {
        // implementirati funkciju
        return false;
    }
    Array() {
        // implementirati funkciju
    }
    Array(const Array<T, max>& obj) {
        // implementirati funkciju
    }
    Array<T, max>& operator = (const Array<T, max>& obj) {
        // implementirati funkciju
        return *this;
    }
    T& operator [] (int index) const {
        return *_elementi[index];
    }
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
class FITCC {
    char* _nazivTima = nullptr;
    Array<Par<Student, Student>,10> _timovi; // studenti koji u cestvuju u programerskom izazovu na takmicenju FIT CC
public:
    const char* getNaziv() const { return (_nazivTima == nullptr) ? "" : _nazivTima; }
    Array<Par<Student, Student>, 10> getTim(int indeks) const { return _timovi; }

    void setNaziv(const char* naziv) {
        // implementirati funkciju
    }

    void setTimove(Array<Par<Student, Student>, 10> timovi)
    {
        //implementirati funckiju
    }

    void dodajTim(Par<Student, Student> clanoviTima) {
        // implementirati funkciju
    }

    FITCC() {
    }

    FITCC(const char* naziv) {
        // implementirati funkciju
    }

    FITCC(const FITCC& obj) {
        // implementirati funkciju
    }
    
    FITCC& operator = (const FITCC& obj) {
        // implementirati funkciju
        return *this;
    }

    ~FITCC() {
        // implementirati funkciju
    }
};

ostream& operator <<(ostream& COUT, FITCC& st) {
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
    Predmet operativniSistemi;
    operativniSistemi.setNaziv("Operativni sistemi");
    operativniSistemi.setECTS(5);

    Predmet os_copy(operativniSistemi);
    Predmet os_copy2;
    os_copy2 = os_copy;

    if (os_copy2 == operativniSistemi)
        cout << "Predmeti su jednaki!\n";
    else
        cout << "Predmeti nisu jednaki\n";

    cout << "Dealokacija...\n";
}

void zadatak3() {
    Student s;
    s.setBrojIndeksa("BB220001");
    s.setDatumRodjenja(Datum(1, 1, 2003));
    s.setGodStudija(PRVA);
    s.setImePrezime("Naida Karabeg");
    s.setSpol(1);

    Student s_copy(s);
    cout << s_copy << endl;

    if (s == s_copy)
        cout << "Uspjesno implementirano!\n";
    else
        cout << "Imate neku gresku!\n";

    Predmet programiranje;
    programiranje.setECTS(7);
    programiranje.setNaziv("Objektno orijentisano programiranje");

    s.AddOcjenaForPredmet(programiranje, 6);
    cout << s << endl;

    cout << "Dealokacija...\n";
}

void zadatak4() {
    FITCC takmicenje("FIT CC");
    Student s1, s2;
    s1.setBrojIndeksa("BB210001");
    s1.setDatumRodjenja(Datum(1, 1, 2020));
    s1.setImePrezime("Student 1");
    s1.setGodStudija(DRUGA);
    s1.setSpol(0);
    s2 = s1;
    s2.setImePrezime("Student 2");
    s2.setBrojIndeksa("BB210002");

    Par<Student, Student> tim1;
    tim1.setDesni(s1);
    tim1.setLijevi(s2);

    takmicenje.dodajTim(tim1);
    
    FITCC takmicenje_copy = takmicenje;
    takmicenje_copy.dodajTim(tim1);

    cout << takmicenje_copy << endl;
    cout << "Dealokacija...\n";
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
