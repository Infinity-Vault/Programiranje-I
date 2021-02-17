#include <iostream>
using namespace std;

//Deklar. strukture:
struct vozilo {
	
    char* markaVozila;
    char* brojSasije;
    char* tipVozila;
    int* kubnihCM;
	
    //Konstruktor: (Incijalizira pointere sa dinamickim varijablima pri stvaranju objekta)
    vozilo() {
        markaVozila = new char[15];
        brojSasije = new char[10];
        tipVozila = new char;
        kubnihCM = new int;
    }
	
    //Destruktor: (Dealocira sve dinamicki alocirane varijable i nullpointuje pointere)
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

// Pointer se proslijeđuje po referenci jer se postavlja kao nullptr prilikom dealokacije
void dealokacijaNiza(vozilo**&, int);

int main() {
    int red, kolona;

    cout << "Molim vas unesite red: " << endl;
    cin >> red;
    cout << "Molim vas unesite kolone: " << endl;
    cin >> kolona;

    //Deklaracija  matrice:
    vozilo** niz = new vozilo * [red];
    for (int i = 0; i < red; i++)
    {
        *(niz + i) = new vozilo[kolona];
    }

    unos(niz, red, kolona);
    cout << endl;
    ispis(niz, red, kolona);
    cout << endl;

    cout << "Firma sa najvecom  prosjecnom kubikazom se nalazi na indeksu: " << najveca_Kubikaza(niz, red, kolona) << endl;

    int indeks = najveca_Kubikaza(niz, red, kolona);
    cout << "Uneseni podaci firme sa najvecom kubikazom su: ";
    for (int j = 0; j < kolona; j++)
    {
        cout << "Marka vozila je: " << (*(niz + indeks) + j)->markaVozila << "\t";
        cout << "Broj sasije vozila je: " << (*(niz + indeks) + j)->brojSasije << "\t";
        cout << "Tip vozila je: " << *(*(niz + indeks) + j)->tipVozila << "\t";
        cout << "Kubna potrosnja vozila je: " << *(*(niz + indeks) + j)->kubnihCM << endl;
    }

    cout << endl;

    prosjecna_Kubikaza(niz, red, kolona);

    dealokacijaNiza(niz, red);

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
        	
            cout << "Unesite broj kubne potrosnje vozila: " << endl;
            cin >> *(*(niz + i) + j)->kubnihCM;
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

void dealokacijaNiza(vozilo**& niz, int red) {

	// Dealokacija svakog 1D niza objekata
    for (int i = 0; i < red; i++)
    {
        delete[] * (niz + i);
    }

	// Dealokacija niza pointera na koje pointuje vozilo** i postavljanej vozilo** na nullptr
    delete[]niz;
    niz = nullptr;
}

int najveca_Kubikaza(vozilo** niz, int red, int kolona) {

	// Pomocni int niz, inicijaliziran na 0, koji punimo prosjecnim kubikazama svakog reda
    float* pomocni = new float[red] {};
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(pomocni + i) += *(*(niz + i) + j)->kubnihCM;
        }
        *(pomocni + i) /= kolona;
    }

	// Kompariramo elemente pomocni niza da bi pronasli najveci element (tj. najveci prosjek)
    int maxK = 0;
	
    for (int i = 0; i < red; i++)
    {
        if (*(pomocni + i) > * (pomocni + maxK)) {
            maxK = i;
        }
    }
	
    // Dealokacija pomocni i to prije return statement, kako bi se zapravo dealokacija izvrsila!
    delete[]pomocni;
    pomocni = nullptr;
	
    return maxK;
}

void prosjecna_Kubikaza(vozilo** niz, int red, int kolona) {
	
    float prosjek_A = 0.0f;
    float prosjek_B = 0.0f;
    int A = 0, B = 0; // Brojac sa vozila tipa 'A' i 'B' (da bi mogli racunati prosjek kubikaze nekog tipa vozila moramo znati koliko ih ima prvo
	
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            if (*(*(niz + i) + j)->tipVozila == 'A') {
                prosjek_A += *(*(niz + i) + j)->kubnihCM;
                A++;
            }
        	
            else if (*(*(niz + i) + j)->tipVozila == 'B') {
                prosjek_B += *(*(niz + i) + j)->kubnihCM;
                B++;
            }
        }
    }
    // Racunamo prosjek nekog tipa tako što podijelimo ukupnu kubikazu svih vozila tog tipa sa brojem vozila
    if (A != 0) {//Provjera brojaca jer se ne moze dijeliti sa nulom!
        prosjek_A /= A;
    }
	
    if (B != 0) {
       prosjek_B /= B;
    }


    cout << "Prosjecna kubikaza vozila  sa A kategorijom je: " << prosjek_A << " dok je prosjecna kubikaza vozila sa kategorijom B : " << prosjek_B << endl;
}
