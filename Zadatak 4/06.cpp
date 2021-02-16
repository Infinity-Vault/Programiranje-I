#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Kreiranje sturkture:
struct kosarkas {
	
    char* ID;
    char* imePrezime;
    int* postignutiKosevi;

    //Konstruktor: (Inicijalizira sve pointere objekta kao dinamicke varijable/niz pri kreiranju objekta)
    kosarkas() {
        ID = new char[10];
        imePrezime = new char[20];
        postignutiKosevi = new int;
    }
	
    //Destruktor: (Dealocira sve dinamicke varijable/niz i nullpointuje pointere
    ~kosarkas() {
        delete[]ID;
        ID = nullptr;
    	
        delete[]imePrezime;
        imePrezime = nullptr;
    	
        delete postignutiKosevi;
        postignutiKosevi = nullptr;
    }
};

void unos(kosarkas**, int, int);
void ispis(kosarkas**, int, int);
void dealokacijaNiza(kosarkas**&, int);
int maxKlub(kosarkas**, int, int);
int* maxIgrac(kosarkas**, int, int, int);

int main() {
    srand((time(0))); 
    int red, kolona;
	
    cout << "Molim vas unesite red: " << endl;
    cin >> red;
    cout << "Molim vas unesite kolone: " << endl;
    cin >> kolona;

	// Kreiranje 2D niza
    kosarkas** niz = new kosarkas * [red];
    for (int i = 0; i < red; i++)
    {
        *(niz + i) = new kosarkas[kolona];
    }

    unos(niz, red, kolona);
    ispis(niz, red, kolona);
    cout << "Klub (kolona) koji je najuspijesniji tj koji ima najvise koseva je na indeksu: " << maxKlub(niz, red, kolona);
	
    cout << "\n";
	
    cout << "Ispis najuspijesnijeg kluba: " << endl;
    int indeks = maxKlub(niz, red, kolona);
    for (int i = 0; i < red; i++)
    {
        cout << "ID igraca je: " << (*(niz + i) + indeks)->ID << "\t";
        cout << "Ime i Prezime igraca je: " << (*(niz + i) + indeks)->imePrezime << "\t";
        cout << "Broj postignutih koseva od igraca je: " << *(*(niz + i) + indeks)->postignutiKosevi << endl;
    }

    cout << "\n";
	
    int* ptrDocek = maxIgrac(niz, red, kolona, indeks);
    cout << "Razlika izmedju koseva najboljeg kosarkasa u najboljem timu i najgoreg kosarkasa u citavoj ligi je " << *ptrDocek << endl;

    dealokacijaNiza(niz, red);

	// ptrDocek je primio dinamicki alociranu varijablu pa se mora dealocirati
    delete ptrDocek;
    ptrDocek = nullptr;
	
    cin.get();
    return 0;

}void unos(kosarkas** niz, int red, int kolona) {

    cin.ignore();
    cout << "Unesite " << red * kolona << " elemenata: " << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << "Unesite ID igraca: " << endl;
            cin.getline((*(niz + i) + j)->ID, 10);

            cout << "Unesite Ime i Prezime igraca: " << endl;
            cin.getline((*(niz + i) + j)->imePrezime, 20);
        	
            *(*(niz + i) + j)->postignutiKosevi = rand() % 20 + 1;

        	// Odkomentiraj za rucni unos postignutih koseva
            // cout << "Unesite broj postignutih koseva: " << endl;
            // cin >> *(*(niz + i) + j)->postignutiKosevi;
        	// cin.ignore();
        }
    }
}

void ispis(kosarkas** niz, int red, int kolona) {
	
    cout << endl;
    cout << "Unijeli ste " << red * kolona << " elemenata, a oni su: " << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << "ID igraca je: " << (*(niz + i) + j)->ID << "\t";
            cout << "Ime i Prezime igraca je: " << (*(niz + i) + j)->imePrezime << "\t";
            cout << "Broj postignutih koseva od igraca je: " << *(*(niz + i) + j)->postignutiKosevi << endl;
        }
        cout << "\n";
    }
}

void dealokacijaNiza(kosarkas**& niz, int red) {

	// Dealokacija svakog 1D niza objekata
    for (int i = 0; i < red; i++)
    {
        delete[] * (niz + i);
    }

	// Dealokacija niza pointera na koji pokazuje kosarkas** i nullpointanje istog
    delete[]niz;
    niz = nullptr;
}

int maxKlub(kosarkas** niz, int red, int kolona) {

	//Privremeni niz za pohranu koseva svake kolone 
    int* pomocni = new int[kolona] {};
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(pomocni + i) += *(*(niz + j) + i)->postignutiKosevi; // Jednodim niz i njegovi redovi se pune kolonama od 2D, isto se moze postici obrnutim petljama postici;
        }
    }

	// Kompariranje svakog elementa niza pomocni kako bi se pronasao najveci broj koseva
    int maxKlub = 0;
	
    for (int i = 0; i < kolona; i++) // Do velicina kolona jer je to velicina niza pomocni
    {
        if (*(pomocni + i) > * (pomocni + maxKlub)) {
            maxKlub = i;
        }
    }

	// Dealokacija pomocni
    delete[] pomocni;
    pomocni = nullptr;

    return maxKlub;
}
int* maxIgrac(kosarkas** niz, int red, int kolona, int max_klub) {
	
    int* najgori = new int[red] {};
    int* pomocni = new int[red] {};
	
    for (int i = 0; i < red; i++)
    {
        *(pomocni + i) = *(*(niz + i) + max_klub)->postignutiKosevi; // Brojaci idu norm redom jer samo uzimamo koseve u jednoj koloni
    }
	
    int najbolji = *(pomocni + 0);
	
    for (int i = 0; i < red; i++)
    {
        if (*(pomocni + i) > najbolji) {
            najbolji = *(pomocni + i);
        }
    }
	
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(najgori + i) += *(*(niz + i) + j)->postignutiKosevi; // Moras += jer zelis da sve koseve saberes za svakog igraca i onda da vidis koji je najgori
        }
    }
	
    int najgoriK = *(najgori + 0);
	
    for (int i = 0; i < red; i++)
    {
        if (*(najgori + i) < najgoriK) {
            najgoriK = *(najgori + i);
        }
    }

    int razlikaK = abs(najbolji - najgoriK); // abs() u slucaju da se oduzima od manjeg a ne od veceg;

    cout << "Najbolji kosarkas u klubu " << max_klub << " ima " << najbolji << " koseva" << endl;
    cout << "Najgori kosarkas u cijeloj ligi ima golova:  " << najgoriK << endl;

	// Dealokacija pomocnih nizova
    delete[]pomocni;
    pomocni = nullptr;
    delete[]najgori;
    najgori = nullptr;

    return new int(razlikaK); // Napravimo dinamicki alociranu varijablu sa vrijednost razlikaK koju ce pointer docekati;
}