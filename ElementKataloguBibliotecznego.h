#include<string>
#pragma once

using namespace std;

// klasa abstrakcyjna - zawiera funkcje czysto wirtualne
class ElementKataloguBibliotecznego {
protected:
    int ID;
    string tytul;
    string wydawnictwo;
    int rokWydania;

public:
    // konstruktor
    ElementKataloguBibliotecznego(string podanyTytul, string podaneWydawnictwo, int podanyRokWydania) :
        tytul(podanyTytul), wydawnictwo(podaneWydawnictwo), rokWydania(podanyRokWydania) {}

    virtual void wypisz() = 0;

    void ustawID(int podaneID) {
        this->ID = podaneID;
    }

    void ustawTytul(int podanyTytul) {
        this->tytul = podanyTytul;
    }

    void ustawWydawnictwo(int podaneWydawnictwo) {
        this->wydawnictwo = podaneWydawnictwo;
    }

    void ustawRokWydania(int podanyRokWydania) {
        this->rokWydania = podanyRokWydania;
    }
    // dwa elementy sa takie same gdy maja taki sam hash
    virtual size_t obliczHash() const = 0;

    // przeciazenie operatora ==
    bool operator==(const ElementKataloguBibliotecznego& other) {
        // uzywamy funkcji obliczHash do porownania dwoch obiektow
        if (this->obliczHash() == other.obliczHash()) {
            return true;
        } else {
            return false;
        }
    }
    int pobierzID() {
        return this->ID;
    }
    virtual void zapiszDoPliku(ofstream& otwartyPlik) = 0;
};
