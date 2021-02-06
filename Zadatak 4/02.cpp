#include <iostream>
using namespace std;

//Deklar. strukture:
struct vozilo {
    char* markaVozila;
    char* brojSasije;
    char* tipVozila;
    int* kubnihCM;
    //Konstruktor:
    vozilo() {
        markaVozila = new char[15];
        brojSasije = new char[10];
        tipVozila = new char;
        kubnihCM = new int;
    }
    //Destruktor:
    ~vozilo() {
        delete[]markaVozila;
        markaVozila = nullptr;
        delete[]brojSasije;
        brojSasije = nullptr;
        delete tipVozila;
        tipVozila = nullptr;
        delete kubnihCM;
        kubnihCM = nullptr;
    }
};
//Deklaracije fija: 
void unos(vozilo**, int, int);
void ispis(vozilo**, int, int);
int najveca_Kubikaza(vozilo**, int, int);
void prosjecna_Kubikaza(vozilo**, int, int);

void dealokacijaNiza(vozilo**&, int, int);

int main() {
    int red, kolona;
    cout << "Molim vas unesite red: " << endl;
    cin >> red;
    cout << "Molim vas unesite kolone: " << endl;
    cin >> kolona;
    //Deklar matrice:
    vozilo** niz = new vozilo * [red];
    for (int i = 0; i < red; i++)
    {
        *(niz + i) = new vozilo[kolona];
    }
    unos(niz, red, kolona);
    cout << endl;
    ispis(niz, red, kolona);
    cout << endl;
    cout << "Firma sa najvecom  prosjecnom kubikazom se nalazi na indeksu: " << najveca_Kubikaza(niz, red, kolona);
    // cout << endl;
    int indeks = najveca_Kubikaza(niz, red, kolona);
    cout << "Uneseni podaci firme sa najvecom kubikazom su: ";
    for (int j = 0; j < kolona; j++)
    {
        cout << "Marka vozila je: " << (*(niz + indeks) + j)->markaVozila << "\t";
        cout << "Broj sasije vozila je: " << (*(niz + indeks) + j)->brojSasije << "\t";
        cout << "Tip vozila je: " << *(*(niz + indeks) + j)->tipVozila << "\t";;
        cout << "Kubna potrosnja vozila je: " << *(*(niz + indeks) + j)->kubnihCM << endl;
    }
    cout << endl;
    prosjecna_Kubikaza(niz, red, kolona);


    dealokacijaNiza(niz, red, kolona);
    cin.get();
    return 0;

}
//Definicije fija:

void unos(vozilo** niz, int red, int kolona) {
    cout << "Unesite " << red * kolona << " elemenata niza: " << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cin.ignore();
            cout << "Unesite marku vozila: " << endl;
            cin.getline((*(niz + i) + j)->markaVozila, 15);
            cout << "Unesite broj sasije vozila: " << endl;
            cin.getline((*(niz + i) + j)->brojSasije, 10);
            do {
                cout << "Unesite tip vozila (A,B,C): " << endl;
                cin >> *(*(niz + i) + j)->tipVozila;
            } while (*(*(niz + i) + j)->tipVozila != 'A' && *(*(niz + i) + j)->tipVozila != 'B' && *(*(niz + i) + j)->tipVozila != 'C');
            cout << "Unesite broj kubne potrosnje vozil : " << endl;
            cin >> *(*(niz + i) + j)->kubnihCM;
            //cin.ignore();
        }
    }
}
void ispis(vozilo** niz, int red, int kolona) {
    cout << "Unijeli ste " << red * kolona << " elemenata, a oni su: " << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << "Marka vozila je: " << (*(niz + i) + j)->markaVozila << "\t";
            cout << "Broj sasije vozila je: " << (*(niz + i) + j)->brojSasije << "\t";
            cout << "Tip vozila je: " << *(*(niz + i) + j)->tipVozila << "\t";;
            cout << "Kubna potrosnja vozila je: " << *(*(niz + i) + j)->kubnihCM << endl;
        }
        cout << endl;
    }
}
void dealokacijaNiza(vozilo**& niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        delete[] * (niz + i);
        *(niz + i) = nullptr;
    }
    delete[]niz;
    niz = nullptr;
}
int najveca_Kubikaza(vozilo** niz, int red, int kolona) {
    int* pomocni = new int[red] {};//Sa {} samo se inicijalizira sa 0, razilicito od statickih;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(pomocni + i) += *(*(niz + i) + j)->kubnihCM;
        }
        *(pomocni + i) /= kolona;//Napunjen pomocni niz sa prosjecnim kubikazama vozila;
    }
    int maxK = 0;
    for (int i = 0; i < red; i++)
    {
        if (*(pomocni + i) > * (pomocni + maxK)) {
            maxK = i;
        }
    }
    //Dealokacija ide prije return;
    delete[]pomocni;
    pomocni = nullptr;
    return maxK;

}
void prosjecna_Kubikaza(vozilo** niz, int red, int kolona) {
    int pomocniA = 0;
    int pomocniB = 0;
    int A = 0, B = 0;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            if (*(*(niz + i) + j)->tipVozila == 'A') {
                pomocniA += *(*(niz + i) + j)->kubnihCM;
                A++;
            }
            else if (*(*(niz + i) + j)->tipVozila == 'B') {
                pomocniB += *(*(niz + i) + j)->kubnihCM;
                B++;
            }
        }
    }
    //Ne mozes / sa kolonama jer npr mozda vozila sa kategor. A nije bilo u svakoj koloni, zato koristim brojac;
    if (A != 0) {
        pomocniA /= A;
    }
    if (B != 0) {
        pomocniB /= B;
    }


    cout << "Prosjecna kubikaza vozila  sa A kategorijom je: " << pomocniA << " dok je prosjecna kubikaza vozila sa kategorijom B : " << pomocniB << endl;

}