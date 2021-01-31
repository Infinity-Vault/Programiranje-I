#include <iostream>
#include <ctime>

using namespace std;

struct fudbaler {
	
	int* godRodjenja;
	int* brojIgraca;
	int* golovi;
	
	//Konstruktor:
	fudbaler() {
		godRodjenja = new int;
		brojIgraca = new int;
		golovi = new int;
	}
	
	//Destruktor:
	~fudbaler() {
		delete godRodjenja;
		godRodjenja = nullptr;
		delete brojIgraca;
		brojIgraca = nullptr;
		delete golovi;
		golovi = nullptr;
	}
};
//Deklaracije fija:
void unos(fudbaler**, int, int);
void ispis(fudbaler**, int, int);
void tim_sa_najvecim_Prosjekom(fudbaler**, int, int);
void igrac_sa_najvise_Golova(fudbaler**, int, int);

void dealokacijaNiza(fudbaler**&, int);
int main() {
	
	srand((time(0)));
	int red, kolona;
	
	cout << "Unesite koliko redova zelite: " << endl;
	cin >> red;
	cout << "Unesite koliko kolona zelite: " << endl;
	cin >> kolona;
	
	fudbaler** niz = new fudbaler * [red];
	for (int i = 0; i < red; i++)
	{
		*(niz + i) = new fudbaler[kolona];
	}
	
	unos(niz, red, kolona);
	ispis(niz, red, kolona);
	
	tim_sa_najvecim_Prosjekom(niz, red, kolona);
	igrac_sa_najvise_Golova(niz, red, kolona);
	
	//Dealokacija:
	dealokacijaNiza(niz, red);
	cin.get();
	return 0;
}
//Definicije fija: 
void unos(fudbaler** niz, int red, int kolona) {
	
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(*(niz + i) + j)->godRodjenja = 1980 + rand() % ((2000 + 1) - 1980);
			*(*(niz + i) + j)->brojIgraca = rand() % 30 + 1;
			*(*(niz + i) + j)->golovi = rand() % 5;
		}
	}
}
void ispis(fudbaler** niz, int red, int kolona) {
	
	cout << endl;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << "Godina rodjenja je: " << *(*(niz + i) + j)->godRodjenja << "\t";
			cout << "Broj igraca je: " << *(*(niz + i) + j)->brojIgraca << "\t";
			cout << "Broj golova igraca je: " << *(*(niz + i) + j)->golovi << endl;
		}
		cout << endl;
	}
}
void tim_sa_najvecim_Prosjekom(fudbaler** niz, int red, int kolona) {
	
	float* najboljiTim = new float[red] {};
	
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(najboljiTim + i) += *(*(niz + i) + j)->golovi;
		}
		*(najboljiTim + i) /= kolona;
	}
	
	int indeksTima = 0;
	
	for (int i = 0; i < red; i++)
	{
		if (*(najboljiTim + i) > * (najboljiTim + indeksTima)) {
			indeksTima = i;
		}
	}
	
	cout << "Najbolji tim se nalazi na indeksu: " << indeksTima << " i sa podacima: " << endl;
	
	for (int j = 0; j < kolona; j++)
	{
		cout << "Godina rodjenja je: " << *(*(niz + indeksTima) + j)->godRodjenja << "\t";
		cout << "Broj igraca je: " << *(*(niz + indeksTima) + j)->brojIgraca << "\t";
		cout << "Broj golova igraca je: " << *(*(niz + indeksTima) + j)->golovi << endl;
	}
}
void igrac_sa_najvise_Golova(fudbaler** niz, int red, int kolona) {
	
	float* najgoriTim = new float[red] {};
	
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			*(najgoriTim + i) += *(*(niz + i) + j)->golovi;
		}
		*(najgoriTim + i) /= kolona;
	}
	
	int indeksTima = 0;
	
	for (int i = 0; i < red; i++)
	{
		if (*(najgoriTim + i) < *(najgoriTim + indeksTima)) {
			indeksTima = i;
		}
	}
	
	int najboljiFudbaler = *(*(niz + indeksTima) + 0)->golovi;
	int indeksj = 0;
	
	for (int j = 0;  j < kolona;  j++)
	{
		if (*(*(niz + indeksTima) + j)->golovi > najboljiFudbaler) {
			najboljiFudbaler = *(*(niz + indeksTima) + j)->golovi;
			indeksj = j;
		}
	}
	
	cout << "Najbolji fudbaler u najgorem timu je rodjen : " << *(*(niz + indeksTima) + indeksj)->godRodjenja<<" i ima golova: "<< *(*(niz + indeksTima) + indeksj)->golovi;
}

void dealokacijaNiza(fudbaler**& niz, int red) {
	for (int i = 0; i < red; i++)
	{
		delete[] * (niz + i);
		*(niz + i) = nullptr;
	}
	delete[] niz;
	niz = nullptr;
}
