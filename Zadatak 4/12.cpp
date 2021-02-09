#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

int brojCifri(int);
bool Crno_polje(int, int);

void dealokacija_niza(int**&, int, int);
void unos_Niza(int**, int, int);
void ispis_Niza(int**, int, int);
void prosjeci_bijelih_crnih(int**, int, int);
int main() {
	srand((time(0)));
	int red, kolona;
	cout << "Molim vas uneiste koliko redova zelite: " << endl;
	cin >> red;
	cout << "Unesite koliko kolona zelite: " << endl;
	cin >> kolona;
	int** niz = new int* [red];
	for (int i = 0; i < red; i++)
	{
		*(niz + i) = new int[kolona];
	}
	//Pozivi funkcija:
	unos_Niza(niz, red, kolona);
	ispis_Niza(niz, red, kolona);
	cout << '\n';
	prosjeci_bijelih_crnih(niz, red, kolona);






	dealokacija_niza(niz, red, kolona);
	cin.get();
	return 0;

}
void dealokacija_niza(int**& niz, int red, int kolona) {
	for (int i = 0; i < red; i++)
	{
		delete[] * (niz + i);
		*(niz + i) = nullptr;
	}
	delete[]niz;
	niz = nullptr;
}
int brojCifri(int broj) {
	int br = 0;
	while (broj > 0) {
		broj /= 10;
		br++;
	}
	return br;
}
bool Crno_polje(int i, int j) {
	if ((i + j) % 2 == 0)
		return true;
	else
		return false;
}

void unos_Niza(int** niz, int red, int kolona) {
	int temp;
	cout << "Unesite " << red * kolona << " elemenata: " << endl;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (Crno_polje(i, j)) {
				do {
					cout << "Unesite paran broj sa neparnim brojem cifri: " << endl;
					cin >> temp;
					//temp = rand() % 1000 + 100;
					*(*(niz + i) + j) = temp;
					if (temp % 2 != 0)
						cout << "Unijeli ste NEPARAN BROJ!" << endl;
					if (brojCifri(temp) % 2 == 0)
						cout << "Unijeli ste broj sa PARNIM brojem cifri!" << endl;
				} while (temp % 2 != 0 || brojCifri(temp) % 2 == 0);// MORA BITI ILI(||) KAKO BI BILO LOGICKI ISPRAVNO!!!
			}
			else {
				do {
					cout << "Unesite neparan broj sa parnim brojem cifri: " << endl;
					cin >> temp;
					*(*(niz + i) + j) = temp;
					if (temp % 2 == 0)
						cout << "Unijeli ste PARAN BROJ!" << endl;
					if (brojCifri(temp) % 2 != 0)
						cout << "Unijeli ste broj sa NEPARNIM brojem cifri: " << endl;
				} while (temp % 2 == 0 || brojCifri(temp) % 2 != 0);// MORA BITI ILI(||) KAKO BI BILO LOGICKI ISPRAVNO!!!
			}
		}
	}
}
void ispis_Niza(int** niz, int red, int kolona) {
	cout << endl;
	cout << "Unijeli ste " << red * kolona << " elemenata, a oni su: " << endl;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << *(*(niz + i) + j) << "\t";
		}
		cout << endl;
	}
}
void prosjeci_bijelih_crnih(int** niz, int red, int kolona) {
	float prosjek_Bijelih = 0.0;
	float prosjek_Crnih = 0.0;
	int brojacC = 0;
	int brojacB = 0;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (i < j && (i + j) % 2 != 0) {
				prosjek_Bijelih += *(*(niz + i) + j);
				brojacB++;
			}
			else if ((i + j) >= red - 1 && (i + j) % 2 == 0) {
				prosjek_Crnih += *(*(niz + i) + j);
				brojacC++;
			}
		}
	}
	cout << "Prosjek svih elemenata na crnim poljima ispod sporedne dijagonale je: " << setprecision(4) << prosjek_Crnih / float(brojacC) << endl;
	cout << "Prosjek svih elemenata na bijelim poljima iznad glavne dijagonale je: " << setprecision(4) << prosjek_Bijelih / float(brojacB) << endl;
}
