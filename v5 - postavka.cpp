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
    return nullptr;
}

class Datum
{
    int* _dan{ nullptr };
    int* _mjesec{ nullptr };
    int* _godina{ nullptr };
public:
    //Z1.1 Dflt. ctor
    Datum() {
    }
    //Z1.2 User-def. ctor
    Datum(int d, int m, int g) {
        //Implementirati funkciju
    }
    //Z1.3
    int getDan() const { return 0; } //Implementirati funkciju
    int getMjesec() const { return 0; }  //Implementirati funkciju
    int getGodina() const { return 0; }  //Implementirati funkciju
    //Z1.4 
    void setDan(int dan) {
        //Implementirati funkciju
    }
    void setMjesec(int mjesec) {
        //Implementirati funkciju
    }
    void setGodina(int godina) {
        //Implementirati funkciju
    }
    //Z1.5
    void set(const Datum& obj) {
        //Implementirati funkciju
    }
    //Z1.6
    void ispis() const {
        //Implementirati funkciju
    }
    //Z1.7
    ~Datum() {
        //Implementirati funkciju
    }
};
class Zanr {
	char* _naziv;
	char _opis[200];
public:
    //Z2.1 Dflt. ctor
	Zanr(){
        //implementirati funkciju
    }
    //Z2.2 user-def. ctor
    Zanr(const char* naziv, const char* opis)
    {
        //implementirati funkciju

    }
    //Z2.3 copy ctor
    Zanr(const Zanr& obj)
    {
        //implementirati funkciju
    }
    //Z2.6
	void Ispis() {
        //implementirati funkciju
    }
	//Z2.5 destruktor
    ~Zanr()
    {
        //implementirati funkciju
    }

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
    Knjiga(const Knjiga& knjiga){
        //implementirati funkciju
        
    }

	//Z3.4
	void Ispis(){
        //implementirati funkciju

    }

    //Z3.5
	~Knjiga{
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

	~Biblioteka(){
        //implementirati funkciju
    }
};

int main() {


	system("pause>0");
	return 0;
}
