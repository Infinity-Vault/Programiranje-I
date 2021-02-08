#include <iostream>
#include <time.h>
using namespace std;

//Deklarisanje strukture:
struct uposlenik {
    char* ID;
    char* imePrezime;
    float* plata;

    //Konstruktor:
    uposlenik() {
        ID = new char[10];
        imePrezime = new char[20];
        plata = new float;
    }
    //Destruktor:
    ~uposlenik() {
        delete[]ID;
        ID = nullptr;
        delete[]imePrezime;
        imePrezime = nullptr;
        delete plata;
        plata = nullptr;
    }

};
//Dekalracije funckija:
void unos(uposlenik**, int, int);
void ispis(uposlenik**, int, int);
void odjel_sa_Najvecim_prosjekom(uposlenik**, int, int);
void dealokacijaNiza(uposlenik**&, int, int);
int main() {
    srand((time(0)));
    int red, kolona;
    cout << "Unesite broj redova: " << endl;
    cin >> red;
    cout << "Unesite broj kolona: " << endl;
    cin >> kolona;
    //Kreiranje dinam 2D niza: 
    uposlenik** niz = new uposlenik * [red];
    for (int i = 0; i < red; i++)
    {
        *(niz + i) = new uposlenik[kolona];
    }
    //Pozivi funkcija:
    unos(niz, red, kolona);
    ispis(niz, red, kolona);
    odjel_sa_Najvecim_prosjekom(niz, red, kolona);


    dealokacijaNiza(niz, red, kolona);
    cin.get();
    return 0;
}
//Definicije funkcija: 
void unos(uposlenik** niz, int red, int kolona) {
    cout << "Unesite " << red * kolona << " elemenata: " << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << "Unesite ID uposlenika: " << endl;
            cin.ignore();//Sa cin.ignore() se vazda poigraj pa vidi gdje treba stajat kako bi fino sve islo;
            cin.getline((*(niz + i) + j)->ID, 10);
            cout << "Unesite Ime i Prezime uposlenika: " << endl;
            cin.getline((*(niz + i) + j)->imePrezime, 20);
            /*cout << "Unesite platu uposlenika: " << endl;
            cin >> *(*(niz + i) + j)->plata;*/
            *(*(niz + i) + j)->plata = rand() % 3000 + 1500;
        }
    }
}
void ispis(uposlenik** niz, int red, int kolona) {
    cout << endl;
    cout << "Unijeli ste " << red * kolona << " elemenata, a oni su: " << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << "ID uposlenika je: " << (*(niz + i) + j)->ID << "\t";
            cout << "Ime i Prezime uposlenika je: " << (*(niz + i) + j)->imePrezime << "\t";
            cout << "Plata uposlenika je: " << *(*(niz + i) + j)->plata << " KM" << endl;
        }
        cout << endl;
    }
}
void odjel_sa_Najvecim_prosjekom(uposlenik** niz, int red, int kolona) {
    double* prosjekOdjela = new double[red] {};
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(prosjekOdjela + i) += *(*(niz + i) + j)->plata;//Redove pomocnog niza punim zbirom plata svih uposlenika tog reda;
        }
        *(prosjekOdjela + i) /= kolona;//Dijelim sa onoliko plata koliko sam i sabrao tj sa kolonom, i dobijam prosjecnu vrijednost svakog reda;
    }
    int najbolji_prosjek_Indeks = 0;
    for (int i = 0; i < red; i++)
    {
        if (*(prosjekOdjela + i) > * (prosjekOdjela + najbolji_prosjek_Indeks)) {
            najbolji_prosjek_Indeks = i;
        }
    }
    cout << "Indeks odjela (reda) sa najvecim prosjekom je: " << najbolji_prosjek_Indeks << " a najbolji prosjek je: " << *(prosjekOdjela + najbolji_prosjek_Indeks) << endl;
    delete[]prosjekOdjela;
    prosjekOdjela = nullptr;

}

void dealokacijaNiza(uposlenik**& niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        delete[] * (niz + i);
        *(niz + i) = nullptr;
    }
    delete[]niz;
    niz = nullptr;
}