struct vremenska_prognoza {
    char* padavine;//Mora biti niz karaktera!
    float* temperatura;
    float* vlaznost_zraka;
    //Kreiranje konstruktora:
    vremenska_prognoza() {
        padavine = new char[15];
        temperatura = new float;
        vlaznost_zraka = new float;
    }
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
void dealokacija_niza(vremenska_prognoza**&, int, int);
void unosNiza(vremenska_prognoza*, int);
int najtacniji_Meteorolog(vremenska_prognoza**, vremenska_prognoza*, int, int);
int main() {
    //Deklarisanje matrice:
    int redovi, kolone;
    cout << "Molim vas unesite duzinu redova i duzinu kolona" << endl;
    cin >> redovi >> kolone;
    vremenska_prognoza** niz2D = new vremenska_prognoza * [redovi];//Napravljeni redovi i pokazivac na 2D niz;
    //Pravljenje kolona:
    for (int i = 0; i < redovi; i++)
    {
        *(niz2D + i) = new vremenska_prognoza[kolone];//Napravljene kolone
    }
    //Pozivi funckija:
    unosElemenata(niz2D, redovi, kolone);
    cout << endl;
    ispisElemenata(niz2D, redovi, kolone);
    //Kreiranje jednodim. dinam. niza za unos dana:
    vremenska_prognoza* niz = new vremenska_prognoza[kolone];
    unosNiza(niz, kolone);
    cout << endl;
    cout << "Meteorolog sa najtacnijom prognozom dnevnih temperatura je na indeksu: " << najtacniji_Meteorolog(niz2D, niz, redovi, kolone);

  
    delete[]niz;
    niz = nullptr;
    cin.get();
    return 0;

}
void dealokacija_niza(vremenska_prognoza**& niz2D, int redovi, int kolone) {
    for (int i = 0; i < redovi; i++)
    {
        delete[] * (niz2D + i);//Dealocirao kolone
        *(niz2D + i) = nullptr;
    }
    delete[]niz2D;//Dealocirao niz tj. redove
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
            // (*(niz2D + i) + j)->padavine = new char[15];
            cin.getline((*(niz2D + i) + j)->padavine, 15);
            cout << "Molim vas unesite temperaturu: " << endl;
            //(*(niz2D + i) + i)->temperatura = new float;
            cin >> *(*(niz2D + i) + j)->temperatura;
            cout << "Molim vas unesite vlaznost zraka: " << endl;
            // (*(niz2D + i) + j)->vlaznost_zraka = new float;
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
            cout << "Unesena padavina je: " << ((*(niz2D + i) + j)->padavine) << endl;//Pointer na char niz se ne dereferencira;
            cout << "Unesena temperatura je: " << *((*(niz2D + i) + j)->temperatura) << endl;
            cout << "Unesena vlaznost zraka je: " << *((*(niz2D + i) + j)->vlaznost_zraka) << endl;
        }
        cout << "\n";//Nakon svake kolone zavrsene endl;
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
    float* pomocni = new float[kolone] {};

    for (int i = 0; i < redovi; i++)
    {
        for (int j = 0; j < kolone; j++)
        {
            *(pomocni + i) += abs(*(*(niz2D + i) + j)->temperatura - *(niz + i)->temperatura);//abs koristimo radi  potencijalnog neg br ;
        }
    }
    int minError = 0;
    for (int i = 0; i < kolone; i++)
    {
        if (*(pomocni + i) < *(pomocni + minError)) {
            minError = i;
        }
    }
    return minError;
}