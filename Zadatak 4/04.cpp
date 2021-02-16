#include <iostream>
#include <cstdlib>

using namespace std;

struct vremenska_prognoza {
	
    char* padavine;//Mora biti niz karaktera!
    float* temperatura;
    float* vlaznost_zraka;
	
   // Konstruktor: (Inicijaliziramo pointere strukture kao dinamicke varijable/niz)
    vremenska_prognoza() {
        padavine = new char[15];
        temperatura = new float;
        vlaznost_zraka = new float;
    }

	// Destruktor: (Dealocira sve dinamicke varijable/niz i nullpointuje pointere)
    ~vremenska_prognoza() {
        delete[]padavine;
        padavine = nullptr;
        delete temperatura;
        temperatura = nullptr;
        delete vlaznost_zraka;
        vlaznost_zraka = nullptr;
    }
};

//Deklarisanje funckija:
void unosElemenata(vremenska_prognoza**, int, int);
void ispisElemenata(vremenska_prognoza**, int, int);
void dealokacija_niza(vremenska_prognoza**&, int);
void unosNiza(vremenska_prognoza*, int);
int najtacniji_Meteorolog(vremenska_prognoza**, vremenska_prognoza*, int, int);

int main() {
	
    int redovi, kolone;
	
    cout << "Molim vas unesite duzinu redova i duzinu kolona" << endl;
    cin >> redovi >> kolone;

	// Kreiramo 2D matricu
    vremenska_prognoza** niz2D = new vremenska_prognoza * [redovi];
    for (int i = 0; i < redovi; i++)
    {
        *(niz2D + i) = new vremenska_prognoza[kolone];//Napravljene kolone
    }
	
    unosElemenata(niz2D, redovi, kolone);
    cout << endl;
    ispisElemenata(niz2D, redovi, kolone);
	
    //Kreiranje jednodim. dinam. niza za unos dana sa stvarnim mjerenjima:
    vremenska_prognoza* niz = new vremenska_prognoza[kolone];
    unosNiza(niz, kolone);
	
    cout << endl;
	
    cout << "Meteorolog sa najtacnijom prognozom dnevnih temperatura je na indeksu: " << najtacniji_Meteorolog(niz2D, niz, redovi, kolone);

    delete[]niz;
    niz = nullptr;

    dealokacija_niza(niz2D, redovi);
	
    cin.get();
    return 0;

}

void dealokacija_niza(vremenska_prognoza**& niz2D, int redovi) {

	// Dealociranje svakog 1D niza objekata
    for (int i = 0; i < redovi; i++)
    {
        delete[] * (niz2D + i);
    }

	// Dealociranje niza pointera na koju pokazuje vremenska_prognoza** i nullpointanje istog
    delete[]niz2D;
    niz2D = nullptr;
}

void unosElemenata(vremenska_prognoza** niz2D, int redovi, int kolone) {
	
    cout << "Molim vas unesite " << redovi * kolone << " elemenata u  niz: " << endl;
    for (int i = 0; i < redovi; i++)
    {
        for (int j = 0; j < kolone; j++)
        {
            cin.ignore();
            cout << "Molim vas unesite padavine: " << endl;
            cin.getline((*(niz2D + i) + j)->padavine, 15);
        	
            cout << "Molim vas unesite temperaturu: " << endl;
            cin >> *(*(niz2D + i) + j)->temperatura;
        	
            cout << "Molim vas unesite vlaznost zraka: " << endl;
            cin >> *(*(niz2D + i) + j)->vlaznost_zraka;
        }
    }
}

void ispisElemenata(vremenska_prognoza** niz2D, int redovi, int kolone) {
	
    cout << "Unijeli ste " << redovi * kolone << " elemenata, a oni su: " << endl;
    for (int i = 0; i < redovi; i++)
    {
        for (int j = 0; j < kolone; j++)
        {
            cout << "Unesena padavina je: " << ((*(niz2D + i) + j)->padavine) << endl; //Pointer na char niz se ne dereferencira prilikom ispisa;
            cout << "Unesena temperatura je: " << *((*(niz2D + i) + j)->temperatura) << endl;
            cout << "Unesena vlaznost zraka je: " << *((*(niz2D + i) + j)->vlaznost_zraka) << endl;
        }
        cout << "\n"; // Nakon svake kolone zavrsene endl;
    }
}

void unosNiza(vremenska_prognoza* niz, int kolone) {
	
    cout << "Unesite " << kolone << " elemenata" << endl;
    for (int i = 0; i < kolone; i++)
    {
        cin.ignore();
        cout << "Unesite padavine: " << endl;
        cin.getline((niz + i)->padavine, 15);
    	
        cout << "Unesite temperaturu: " << endl;
        cin >> *(niz + i)->temperatura;
    	
        cout << "Unesite vlaznost zraka: " << endl;
        cin >> *(niz + i)->vlaznost_zraka;
    }
}

int najtacniji_Meteorolog(vremenska_prognoza** niz2D, vremenska_prognoza* niz, int redovi, int kolone) {

	// Privremeni niz za pohranu ukupne greske svakog reda (Razlika izmedju temperatura objekta u niz2D i objekta u niz), inicijaliziran na 0
    float* pomocni = new float[kolone] {};

    for (int i = 0; i < redovi; i++)
    {
        for (int j = 0; j < kolone; j++)
        {
            *(pomocni + i) += abs(*(*(niz2D + i) + j)->temperatura - *(niz + i)->temperatura);// abs() daje apsolutnu vrijednost izraza (u slučaju da imamo negativan broj)
        }
    }

	// Kompariramo pomocni niz da bi nasli najmanji element (tj. meteorolog sa najmanjom gresom)
    int minError = 0;
    for (int i = 0; i < kolone; i++)
    {
        if (*(pomocni + i) < *(pomocni + minError)) {
            minError = i;
        }
    }

	// Dealokacija pomocni niza
    delete[] pomocni;
	
    return minError;
}