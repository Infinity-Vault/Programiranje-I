#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Kreiranje stukture:
struct figura {
	
    int ID;
    char* nazivFigure;
    float* visinaFigure;

	// Konstruktor: (Inicijaliziranje pointera kao dinamicke varijable/niz pri stvaranju objekta)
    figura() { 
        ID = 0;
        nazivFigure = new char[10];
        visinaFigure = new float;
    }

	// Destruktor: (Dealociranje svih dinamickih varijabli/nizova pri unistenju objekata)
    ~figura() {
        delete[]nazivFigure;
        nazivFigure = nullptr;
    	
        delete visinaFigure;
        visinaFigure = nullptr;
    }
};

//Deklaracije funkcija: 
void unos(figura**, int, int);
void ispis(figura**, int, int);
float* prosjecnaVisina(figura**, int, int);
void dealokacijaNiza(figura**&, int);

int main() {
    srand((time(0)));
    int red, kolona;
	
    cout << "Unesite red: " << endl;
    cin >> red;
    cout << "Unesite broj kolona: " << endl;
    cin >> kolona;

	// Kreiranje 2D matrice
    figura** niz = new figura * [red];
    for (int i = 0; i < red; i++)
    {
        *(niz + i) = new figura[kolona];
    }
	
    unos(niz, red, kolona);
    ispis(niz, red, kolona);
	
    float* docekptr = prosjecnaVisina(niz, red, kolona);
    cout << "Memorijska lokacija na kojoj se nalazi prosjecna  visina figura koje su ispod glavne dijagonale i na crnim poljima je " << docekptr << " a njena vrijednost je: " << *docekptr;

    dealokacijaNiza(niz, red);
	
    delete docekptr;//Dealociramo ga jer je i on dinam alocirana varijabla;
    docekptr = nullptr;
	
    cin.get();
    return 0;
}
//Definicije funkcija: 
void unos(figura** niz, int red, int kolona) {

    cin.ignore();
    cout << "Unesite " << red * kolona << " elemenata :" << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {

            cout << "Unesite naziv figure: " << endl;
            cin.getline((*(niz + i) + j)->nazivFigure, 10);
        	
            (*(niz + i) + j)->ID = rand() % 10000 + 100;
            *(*(niz + i) + j)->visinaFigure = rand() % 100 + 1;

        	// Odkomentiraj za rucni unos
            //cout << "Unesite ID : " << endl;
            //cin >> (*(niz + i) + j)->ID;
            //cout << "Unesite visinu figure: " << endl;
            //cin >> *(*(niz + i) + j)->visinaFigure;
        	//cin.ignore()

        }
    }
}

void ispis(figura** niz, int red, int kolona) {
	
    cout << endl;
    cout << "Unijeli ste " << red * kolona << " elemenata, a oni su: " << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << "ID figure je: " << (*(niz + i) + j)->ID << "\t";
            cout << "Naziv figure je: " << (*(niz + i) + j)->nazivFigure << "\t";
            cout << "Visina figure je: " << *(*(niz + i) + j)->visinaFigure << endl;
        }
        cout << "\n";
    }
}

float* prosjecnaVisina(figura** niz, int red, int kolona) {
	
    int brojac = 0;
    float average = 0.0f;
	
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            if ((i + j) >= red - 1 && (i + j) % 2 == 0) { // i+j >= red-1 da bi uzimali samo vrijednosti ispod sporedne dijagonale
                average += *(*(niz + i) + j)->visinaFigure;
                brojac++;
            }
        }
    }

	// Podijelimo ukupnu vrijednost visina sa brojem figura ispod sporedne dijagonale kako bi dobili njihov prosjek
    if (brojac != 0) {
        average /= brojac;
    }
	
    return new float(average);
}

void dealokacijaNiza(figura**& niz, int red) {
	
    for (int i = 0; i < red; i++)
    {
        delete[] * (niz + i);
    }
	
    delete[]niz;
    niz = nullptr;
}