#include <iostream>
#include <time.h>
using namespace std;


//Kreiranje sturkture:
struct kosarkas {
    char* ID;
    char* imePrezime;
    int* postignutiKosevi;

    //Konstruktor:
    kosarkas() {
        ID = new char[10];
        imePrezime = new char[20];
        postignutiKosevi = new int;
    }
    //Destruktor:
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
void dealokacijaNiza(kosarkas**&, int, int);
int maxKlub(kosarkas**, int, int);
int* najuspjesnijiKosarkasuMaxklubu(kosarkas**, int, int, int);
int main() {
    srand((time(0)));
    //Kreiranje 2D niza: 
    int red, kolona;
    cout << "Molim vas unesite red: " << endl;
    cin >> red;
    cout << "Molim vas unesite kolone: " << endl;
    cin >> kolona;
    kosarkas** niz = new kosarkas * [red];
    for (int i = 0; i < red; i++)
    {
        *(niz + i) = new kosarkas[kolona];
    }
    //Pozivi funckija:
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
    int* ptrDocek = najuspjesnijiKosarkasuMaxklubu(niz, red, kolona, indeks);
    cout << "Memorijska adresa razlike kosarkasa je: " << ptrDocek;



    dealokacijaNiza(niz, red, kolona);
    delete ptrDocek;//Jer docekuje dinamicki  alociranu varijablu;
    ptrDocek = nullptr;
    cin.get();
    return 0;

}void unos(kosarkas** niz, int red, int kolona) {
    cout << "Unesite " << red * kolona << " elemenata: " << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cin.ignore();
            cout << "Unesite ID igraca: " << endl;
            cin.getline((*(niz + i) + j)->ID, 10);
            // *(*(niz + i) + j)->ID = rand() % 10 + 1;
            cout << "Unesite Ime i Prezime igraca: " << endl;
            cin.getline((*(niz + i) + j)->imePrezime, 20);
            /* cout << "Unesite broj postignutih koseva: " << endl;
             cin >> *(*(niz + i) + j)->postignutiKosevi;*/
            *(*(niz + i) + j)->postignutiKosevi = rand() % 20 + 1;
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
void dealokacijaNiza(kosarkas**& niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        delete[] * (niz + i);
        *(niz + i) = nullptr;
    }
    delete[]niz;
    niz = nullptr;
}
int maxKlub(kosarkas** niz, int red, int kolona) {
    int* pomocni = new int[kolona] {};
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(pomocni + i) += *(*(niz + j) + i)->postignutiKosevi;//Jednodim niz i njegovi redovi se pune kolonama od 2D, isto sam mogao sa obrnutim petljama postici;
        }
    }
    int maxKlub = 0;;
    for (int i = 0; i < kolona; i++)//Idem do kolona jer je to velicina pomocnog;
    {
        if (*(pomocni + i) > * (pomocni + maxKlub)) {
            maxKlub = i;
        }
    }
    return maxKlub;
}
int* najuspjesnijiKosarkasuMaxklubu(kosarkas** niz, int red, int kolona, int j) {
    int* najgori = new int[red] {};
    int* pomocni = new int[red] {};
    for (int i = 0; i < red; i++)
    {
        *(pomocni + i) = *(*(niz + i) + j)->postignutiKosevi;//Brojaci idu norm redom jer samo uzimam koseve u jednoj koloni;
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
        for (int z = 0; z < kolona; z++)
        {
            *(najgori + i) += *(*(niz + i) + z)->postignutiKosevi;//Moras+= jer zelis da sve koseve saberes za svakog igraca i onda da vidis koji je najgori;
        }
    }
    int najgoriK = *(najgori + 0);
    for (int i = 0; i < red; i++)
    {
        if (*(najgori + i) < najgoriK) {
            najgoriK = *(najgori + i);
        }
    }

    int razlikaK = abs(najbolji - najgoriK);//U slucaju da se oduzima od manjeg a ne od veceg;






    cout << "Najbolji kosarkas u klubu na indeksu: " << j << " ima " << najbolji << " koseva" << endl;
    cout << "Najgori kosarkas u cijeloj ligi ima golova:  " << najgoriK << endl;
    cout << "Razlika izmedju  najboljeg kosarkasa u klubu na indeksu " << j << " i izmedju najgoreg u citavoj ligi je:  " << razlikaK << endl;
    delete[]pomocni;
    pomocni = nullptr;
    delete[]najgori;
    najgori = nullptr;

    return new int(razlikaK);//Napravimo dinamicki alociranu varijablu koju ce pointer docekati;
}