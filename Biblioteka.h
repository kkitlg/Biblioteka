#include<vector>

class Biblioteka {
private:
    // agregracja - klasa Biblioteka zawiera wektor wskaznikow na obiekty klasy ElementKataloguBibliotecznego
    vector<ElementKataloguBibliotecznego*> katalogBiblioteczny;
    int aktualneID;
public:
    // konstruktor
    Biblioteka() : aktualneID(0) {}

    /* przekazujemy nowy element katalogu bibliotecznego poprzez wskaznik, bo nie mozemy stworzyc obiektu klasy
       ElementKataloguBibliotecznego, poniewaz jest ona klasa abstrakcyjna */
    void dodajDoKatalogu(ElementKataloguBibliotecznego* wskaznikNaNowyElement) {
        bool czyTakiElementJuzJest = false;
        for (auto wskaznikNaElement : this->katalogBiblioteczny) {
            if (*wskaznikNaElement == *wskaznikNaNowyElement) {
                cout << "Taki element jest juz w katalogu" << endl;
                czyTakiElementJuzJest = true;
                break;
            }
        }
        // sprawdzamy czy dana ksiazka lub czasopismo jest juz w katalogu bibliotecznym
        if (!czyTakiElementJuzJest) {
            this->katalogBiblioteczny.push_back(wskaznikNaNowyElement);
            wskaznikNaNowyElement->ustawID(aktualneID);
            aktualneID++;
        }
    }
    void pokazZawartoscBiblioteki() {
        cout << "Zawartosc katalogu bibliotecznego" << endl << endl;
        // polimorfizm - wywolanie tej samej metody na obiektach z roznych klas
        for (auto wskaznikNaElement : this->katalogBiblioteczny) {
            wskaznikNaElement->wypisz();
            cout << endl << endl;
        }
    }
    void usunZKatalogu(int ID) {
        int indeksElementuODanymID;
        bool czyTakiElementJest = false;
        for (int i = 0; i < this->katalogBiblioteczny.size(); i++) {
            if (katalogBiblioteczny[i]->pobierzID() == ID) {
                indeksElementuODanymID = i;
                czyTakiElementJest = true;
            }
        }
        if (czyTakiElementJest) {
            this->katalogBiblioteczny.erase(this->katalogBiblioteczny.begin() + indeksElementuODanymID);
        } else {
            cout << "Nie ma takiego ID w katalogu" << endl;
        }
    }
    void zapiszKatalogDoPliku(string nazwaPliku) {
        ofstream otwartyPlik(nazwaPliku);
        for (auto wskaznikNaElement : this->katalogBiblioteczny) {
            wskaznikNaElement->zapiszDoPliku(otwartyPlik);
        }
        otwartyPlik.close();
    }
};
