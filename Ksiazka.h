#include<string>
#include<fstream>
#include "ElementKataloguBibliotecznego.h"

using namespace std;

// dziedziczenie - klasa Ksiazka dziedziczy po klasie ElementKataloguBibliotecznego
class Ksiazka : public ElementKataloguBibliotecznego {
private:
    string autor; // zmienna wystepujaca tylko w klasie Ksiazka

public:
    // konstruktor
    Ksiazka(string podanyTytul, string podanyAutor, string podaneWydawnictwo, int podanyRokWydania) :
        ElementKataloguBibliotecznego(podanyTytul, podaneWydawnictwo, podanyRokWydania), autor(podanyAutor) {}
    void wypisz() {
        cout << "Dane ksiazki: " << endl;
        cout << "ID: " << this->ID << endl;
        cout << "Tytul: " << this->tytul << endl;
        cout << "Autor: " << this->autor << endl;
        cout << "Wydawnictwo: " << this->wydawnictwo << endl;
        cout << "Rok wydania: " << this->rokWydania << endl;
    }
    size_t obliczHash() const {
        hash<string> funkcjaObliczajacaHash = hash<string>();
        return funkcjaObliczajacaHash(this->tytul) ^ funkcjaObliczajacaHash(this->autor);
    }
    void zapiszDoPliku(ofstream& otwartyPlik) {
        otwartyPlik << "K," << this->ID << "," << this->tytul << "," << this->autor << "," << this->wydawnictwo << "," << this->rokWydania << endl;
    }
};
