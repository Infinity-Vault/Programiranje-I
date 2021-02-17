#include <iostream>
#include <time.h> //ovo dodajemo da bi komanda na 34. liniji radila
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
void unos(uposlenik**, int, int); //funkcija za unos elemenata niza 
void ispis(uposlenik**, int, int); //funkcija za ispis elemenata niza
void odjel_sa_Najvecim_prosjekom(uposlenik**, int, int); //funkcija koja sluzi za racunanje koji odjel ima najveci prosjek plate
void dealokacijaNiza(uposlenik**&, int); //funkcija koja sluzi za dealokaciju niza
int main() {
    srand((time(0))); //sluzi za generisanje uvijek drugacijek slucajnog broja pri pokretanju programa, ako bi se izbrisala ova linija slucajni broj kod plate uvijek bi bio isti
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
            //platu smo unjeli automatski sa kodom koji je dole prikazan dok zakomentirani gore kod sluzi za unos iznosa plate rucno tj. preko tastature
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
        //stavili smo ovaj endl ovdje da vidimo odakle pocinje novi red u nasoj matrici
        cout << endl;
    }
}
void odjel_sa_Najvecim_prosjekom(uposlenik** niz, int red, int kolona) {
    double* prosjekOdjela = new double[red] {}; //pravimo pomocni niz koji ima velicinu broja nasih redova u taj pomocni niz spremamo prosjecnu platu svakog reda
    // {} nakon deklarisanja niza sluzi da sve elemente niza postavimo na 0 sto nam je vazno jer cemo dole vrsiti sabiranje
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
        if (*(prosjekOdjela + i) > *(prosjekOdjela + najbolji_prosjek_Indeks)) //oov je najobicnije poredenje gdje gledamo koji element naseg pomocnog niza je najveci 
        {
            najbolji_prosjek_Indeks = i;
        }
    }
    cout << "Indeks odjela (reda) sa najvecim prosjekom je: " << najbolji_prosjek_Indeks << " a najbolji prosjek je: " << *(prosjekOdjela + najbolji_prosjek_Indeks) << endl;
    delete[]prosjekOdjela; //ne smijemo zaboraviti izbrisati nas pomocni niz jer i on je dinamički
    prosjekOdjela = nullptr;

}

void dealokacijaNiza(uposlenik**& niz, int red) {
    for (int i = 0; i < red; i++)
    {
        delete[] * (niz + i); //ovdje brisemo nase kolone u nizu
        *(niz + i) = nullptr;
    }
    delete[]niz; //ovdje brisemo redove i sa tim postaje prazan niz
    niz = nullptr; //dodjeljivamo da niz ne pokaziva ni na šta
} 
