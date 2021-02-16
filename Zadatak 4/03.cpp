#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Kreiranje strukture:
struct vozilo {
	
    char* markaVozila;
    char* nazivVozila;
    char* tipVozila;
    float* potrosnja_goriva_po_km;
	
    //Konstruktor: (Inicijalizira sva obiljezja kao pointere na dinamicke varijable/nizove)
    vozilo() {
        markaVozila = new char[15];
        nazivVozila = new char[10];
        tipVozila = new char;
        potrosnja_goriva_po_km = new float;
    }
	
    //Destruktor: (Dealocira sve dinamicke varijable/nizove i postavlja pointere sa nullptr)
    ~vozilo() {
        delete[]markaVozila;
        markaVozila = nullptr;
    	
        delete[] nazivVozila;
        nazivVozila = nullptr;
    	
        delete tipVozila;
        tipVozila = nullptr;
    	
        delete potrosnja_goriva_po_km;
        potrosnja_goriva_po_km = nullptr;
    }
};

//Deklaracije funckija:
void unos(vozilo**, int, int);
void ispis(vozilo**, int, int);
void firma_sa_Najvecom_potrosnjom(vozilo**, int, int);
void potrosnja_vozila_tipa_C(vozilo**, int, int);

void dealokacija_Niza(vozilo**&, int);

int main() {
	
    srand((time(0)));
    int red, kolona;
	
    cout << "Unesite koliko redova zelite: " << endl;
    cin >> red;
    cout << "Unesite koliko kolona zelite: " << endl;
    cin >> kolona;
	
    //Kreiranje dinam. 2D niza: 
    vozilo** niz = new vozilo * [red];
    for (int i = 0; i < red; i++)
    {
        *(niz + i) = new vozilo[kolona];
    }
	
    unos(niz, red, kolona);
    ispis(niz, red, kolona);
	
    firma_sa_Najvecom_potrosnjom(niz, red, kolona);
    potrosnja_vozila_tipa_C(niz, red, kolona);

    dealokacija_Niza(niz, red);
	
    cin.get();
    return 0;
}
//Definicije funkcija: 
void unos(vozilo** niz, int red, int kolona) {
	
    cout << "Unesite " << red * kolona << " elemenata u niz: " << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cin.ignore();
            cout << "Unesite marku vozila: " << endl;
            cin.getline((*(niz + i) + j)->markaVozila, 15);
            cout << "Unesite naziv vozila: " << endl;
            cin.getline((*(niz + i) + j)->nazivVozila, 10);
        	
            do {
            	
                cout << "Unesite tip vozila (A/B/C): " << endl;
                cin >> *(*(niz + i) + j)->tipVozila;
            	
            } while (*(*(niz + i) + j)->tipVozila != 'A' && *(*(niz + i) + j)->tipVozila != 'B' && *(*(niz + i) + j)->tipVozila != 'C');
        	
            *(*(niz + i) + j)->potrosnja_goriva_po_km = rand() % 10 + 5;
        	
        	// Odkomentiraj za rucni unos potrosnje
            //cout << "Unesite potrosnju goriva po kilometrima  za vozilo: " << endl;
            //cin >> *(*(niz + i) + j)->potrosnja_goriva_po_km;
        }
    }
}

void ispis(vozilo** niz, int red, int kolona) {
    cout << endl;
    cout << "Unijeli ste " << red * kolona << " elemenata a oni su: " << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << "Marka vozila je: " << (*(niz + i) + j)->markaVozila << "\t";
            cout << "Naziv vozila je: " << (*(niz + i) + j)->nazivVozila << "\t";
            cout << "Tip vozila je: " << *(*(niz + i) + j)->tipVozila << "\t";
            cout << "Potrosnja goriva po kilometrima vozila je: " << *(*(niz + i) + j)->potrosnja_goriva_po_km << " l/km" << endl;
        }
        cout << endl;
    }
}

void firma_sa_Najvecom_potrosnjom(vozilo** niz, int red, int kolona) {

	// Privremeni int niz za pohranu ukupne potrosnje goriva za svaki red, inicijaliziran na 0
    int* potrosnjaFirme = new int[red] {};
	
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(potrosnjaFirme + i) += *(*(niz + i) + j)->potrosnja_goriva_po_km;
        }
    }

	// Kompariranje elemenata potrosnjaFirme kako bi se pronasla najveca potrosnja
    int indeksFirme = 0;
    for (int i = 0; i < red; i++)
    {
        if (*(potrosnjaFirme + i) > * (potrosnjaFirme + indeksFirme)) {
            indeksFirme = i;
        }
    }
	
    cout << "\n";
	
    cout << "Firma sa najvecom potrosnjom  goriva se nalazi na indeksu: " << indeksFirme << " i ima sljedece podatke: " << endl;
    for (int j = 0; j < kolona; j++)
    {
        cout << "Marka vozila je: " << (*(niz + indeksFirme) + j)->markaVozila << "\t";
        cout << "Naziv vozila je: " << (*(niz + indeksFirme) + j)->nazivVozila << "\t";
        cout << "Tip vozila je: " << *(*(niz + indeksFirme) + j)->tipVozila << "\t";
        cout << "Potrosnja goriva po kilometrima vozila je: " << *(*(niz + indeksFirme) + j)->potrosnja_goriva_po_km << " l/km" << endl;
    }
    cout << "\n";

	// Dealokacija potrosnjaFirme
    delete[] potrosnjaFirme;
}

void potrosnja_vozila_tipa_C(vozilo** niz, int red, int kolona) {
	
    float potrosnjaC = 0.0f;
    int brojac_C_vozila = 0;

	// Samo sumiramo potrosnju svakog vozila koji je tipa 'C' i inkrementujemo brojac da bi znali koliko imamo C vozila
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            if (*(*(niz + i) + j)->tipVozila == 'C') {
                potrosnjaC += *(*(niz + i) + j)->potrosnja_goriva_po_km;
                brojac_C_vozila++;
            }
        }
    }

	// Podijelimo ukupnu potrosnju C vozila sa brojem vozila i tako dobijemo prosjek
	// Brojac castujemo u float da ne bi izgubili preciznost rezultata jer se radi o float/int kalkulaciji
	// U slucaju da nema vozila tipa 'C' u cijeloj matrici onda samo ispisemo potrosnjaC
    if (brojac_C_vozila != 0)
        cout << "Prosjecna potrosnja svih vozila tipa 'C' iznosi: " << potrosnjaC / float(brojac_C_vozila) << endl;
    else
        cout << "Prosjecna potrosnja svih vozila tipa 'C' iznosi: " << potrosnjaC << endl;
}

void dealokacija_Niza(vozilo**& niz, int red) {

	// Dealociranje svakog 1D niza objekata
    for (int i = 0; i < red; i++)
    {
        delete[] * (niz + i);
    }

	// Dealokacija niza pointera na koji pokazuje vozilo** i postavljanje vozilo** na nullptr
    delete[]niz;
    niz = nullptr;
}
