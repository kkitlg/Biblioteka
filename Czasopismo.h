#include<string>
#include "ElementKataloguBibliotecznego.h"

using namespace std;

// dziedziczenie - klasa Czasopismo dziedziczy po klasie ElementKataloguBibliotecznego
class Czasopismo : public ElementKataloguBibliotecznego {
private:
    int numerWydania; // zmienna wystepujaca tylko w klasie Czasopismo
    string rodzaj; // rodzaj to czestotliwosc wydan np. kwartalnik, zmienna wystepujaca tylko w klasie Czasopismo

public:
    // konstruktor
    Czasopismo(string podanyTytul, string podaneWydawnictwo, int podanyRokWydania, int podanyNumerWydania, string podanyRodzaj) :
        ElementKataloguBibliotecznego(podanyTytul, podaneWydawnictwo, podanyRokWydania), numerWydania(podanyNumerWydania), rodzaj(podanyRodzaj) {}
    void wypisz() {
        cout << "Dane czasopisma: " << endl;
        cout << "ID: " << this->ID << endl;
        cout << "Tytul: " << this->tytul << endl;
        cout << "Wydawnictwo: " << this->wydawnictwo << endl;
        cout << "Rok wydania: " << this->rokWydania << endl;
        cout << "Numer wydania: " << this->numerWydania << endl;
        cout << "Rodzaj: " << this->rodzaj << endl;
    }
    size_t obliczHash() const {
        hash<string> funkcjaObliczajacaHashDlaStringa = hash<string>();
        hash<int> funkcjaObliczajacaHashDlaInta = hash<int>();
        return funkcjaObliczajacaHashDlaStringa(this->tytul) ^ funkcjaObliczajacaHashDlaStringa(this->wydawnictwo) ^ funkcjaObliczajacaHashDlaInta(this->numerWydania);
    }
    void zapiszDoPliku(ofstream& otwartyPlik) {
        otwartyPlik << "C," << this->ID << "," << this->tytul << "," << this->wydawnictwo << "," << this->rokWydania
        << this->numerWydania << "," << this->rodzaj << endl;
    }
};

