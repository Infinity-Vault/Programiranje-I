#include<iostream>
using namespace std;
struct student
{
    char* ID;
    char* imePrezime;
    float* prosjek;
    void unos();
    void ispis();
    void dealokacija();
};
void student::unos() //funkcija koju cemo pozvati za unos obiljezija objekata
{
    cin.ignore();
    ID = new char[10];
    cout << "Unesite ID :" << endl;
    cin.getline(ID, 10);
    imePrezime = new char[25];
    cout << "Unesite ime i prezime : " << endl;
    cin.getline(imePrezime, 25);
    prosjek = new float;
    cout << "Unesite prosjek : " << endl;
    cin >> *prosjek;
}
void student::ispis() //funkciju koju cemo pozivati za ispis obiljezija
{
    cout << endl;
    cout << "Vas ID je : " << ID << endl;
    cout << "Vase ime i prezime je : " << imePrezime << endl;
    cout << "Vas prosjek je : " << *prosjek << endl;
}
void student::dealokacija() //funkciju koju cemo pozivati za dealokaciju obiljezija objekata
{
    delete[] ID;
    ID = NULL;
    delete[] imePrezime;
    imePrezime = nullptr;
    delete prosjek;
    prosjek = NULL;
}
void Unos(student**, int);// nema jos jedan int jer je isti broj redova i kolona pa imamo univerzalnu varijablu za to a funkcija sluzi za unos elemenata u dinamicki niz
void Ispis(student**, int);// funkcija sluzi za ispis elemenata iz dinamickog niza
void NajboljiFax(student**, int); //funkcija sluzi za pronalazenje fakulteta (reda) s najboljim prosjekom
void NajboljiStudent(student**, int); //funkcija sluzi za pronalazenje studenta sa najboljim prsjekom u cjeloj matrici
void DEALOKACIJA(student**&, int); //funkcija sluzi za dealokaciju elemenata dinamickog niza
int main()
{
    int univerzalno;
    do
    {
        cout << "Unesite broj fakulteta (redova) : " << endl;
        cin >> univerzalno;
    } while (univerzalno < 0);
    student** niz = new student * [univerzalno]; //u normalnom slucaju ovdje bi unosili red(sto i radimo i sad)samo sto se drugacije zove 
    // jer je isti broj i redova i kolona pa da ne moramo dvije varijable praviti posebno za red i posebno za kolonu
    for (int i = 0; i < univerzalno; i++)
    {
        *(niz + i) = new student[univerzalno];
    }
    //ispis funkcija
    Unos(niz, univerzalno);
    Ispis(niz, univerzalno);
    cout << endl;
    NajboljiFax(niz, univerzalno);
    NajboljiStudent(niz, univerzalno);
    DEALOKACIJA(niz, univerzalno);

    cin.get();
    return 0;
}
void Unos(student** niz, int univerzalno)
{
    for (int i = 0; i < univerzalno; i++)
    {
        for (int j = 0; j < univerzalno; j++)
        {
            (*(*(niz + i) + j)).unos();
        }
    }
}
void Ispis(student** niz, int univerzalno)
{
    for (int i = 0; i < univerzalno; i++)
    {
        cout << "RED : " << i << endl; //dodao sam ovo da se zna koji je tacno red 
        for (int j = 0; j < univerzalno; j++)
        {
            cout << "KOLONA : " << j << endl; //da se zna tacno koja je tacno kolona u pitanju
            (*(*(niz + i) + j)).ispis();
        }
    }
}
void DEALOKACIJA(student**& niz, int univerzalno)
{
    for (int i = 0; i < univerzalno; i++) //brise sve sto je zapisano u elementima strukture
    {
        for (int j = 0; j < univerzalno; j++)
        {
            (*(*(niz + i) + j)).dealokacija();
        }
    }
    for (int i = 0; i < univerzalno; i++) //brise kolone dok ide po redovima
    {
        delete[] * (niz + i);
        *(niz + i) = NULL;
    }
    delete[]niz; //brise sve redove
    niz = nullptr; //stavljamo da pointer pokaziva na 0
}
void NajboljiFax(student** niz, int univerzalno)
{
    //trazi se najbolji fakultet tj. najbolji red
    //sto podrazumjeva naci red s najboljim prosjekom
    float* pomocni = new float[univerzalno] {};//ima velicinu nasih redova jer redove pretrazivamo
    //{} dodajemo jer to nam automatski sve elemente niza stavlja kao da su 0
    for (int i = 0; i < univerzalno; i++)
    {
        for (int j = 0; j < univerzalno; j++)
        {
            *(pomocni + i) += *(*(niz + i) + j)->prosjek;
        }
        *(pomocni + i) /= univerzalno;
    }// nasli smo ukupan zbir prosjeka za sve redove
    int najveci = 0;
    for (int i = 0; i < univerzalno; i++)//krece po redovima jer broj redova je broj koji ima i pomocni niz
    {
        // npr.
        // pomocni [2,55,7,4]
        //indeks   [0, 1,2,3]
        if (*(pomocni + najveci) < *(pomocni + i)) //radimo obicno poredenje elemenata pomocnog niza
        {
            najveci = i;
        }
    }
    cout << "Fakultet(red) s najvecim prosjekom je fakultet s indeksom : " << najveci << endl;
    delete[]pomocni; //pomocni niz je dinamicki pa ga moramo onda i obrisati 
    pomocni = NULL;
}
void NajboljiStudent(student** niz, int univerzalna)
{
    int najboljiRed = 0, najboljaKolona = 0;
    for (int i = 0; i < univerzalna; i++)
    {
        for (int j = 0; j < univerzalna; j++)
        {
            if ((*(*(niz + najboljiRed) + najboljaKolona)->prosjek) < (*(*(niz + i) + j)->prosjek)) //opet radimo obicno poredenje ali sada poredimo sve elemente naseg dinamickog niza
            {
                najboljiRed = i;
                najboljaKolona = j;
            }
        }
    }
    cout << "Najbolji student je student s ID : " << *(*(*(niz + najboljiRed) + najboljaKolona)).ID << endl;
}
