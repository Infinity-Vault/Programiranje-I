#include <iostream>
#include <iomanip> 
#include <time.h> //dodajemo da bi radila komanda na 14. liniji
using namespace std;

int brojCifri(int); //funkcija koja racuna koliko cifri nas broj ima
bool Crno_polje(int, int); //funkcija koja nam govori koje je crno polje u matrici

void dealokacija_niza(int**&, int, int); //funkcija koja brise dinamicki dvodimenzionalni niz
void unos_Niza(int**, int, int); //funkcija koja sluzi za unos elemenata u dinamicki dvodimenzionalni niz
void ispis_Niza(int**, int, int); //funkcija koja sluzi za ispis elemenata niza
void prosjeci_bijelih_crnih(int**, int, int); //funkcija koja racuna prosjek svih elemenata na bijelim i na crnim poljima
int main() {
	srand((time(0))); //sluzi za generisanje uvijek drugacijek slucajnog broja pri pokretanju programa, ako bi se izbrisala ova linija slucajni broj kod plate uvijek bi bio isti
	int red, kolona;
	cout << "Molim vas uneiste koliko redova zelite: " << endl;
	cin >> red;
	cout << "Unesite koliko kolona zelite: " << endl;
	cin >> kolona;
	//kreiramo sada nas dvodimenzionalni dinamicki niz
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
		delete[] * (niz + i); //sa ovim brisemo kolone dvodimenzionalnog dinamickog niza
		*(niz + i) = nullptr;
	}
	delete[]niz; //sa ovim brisemo redove dinamickog dvodimenzionalnog niza i u biti stvaramo prazan pointer sto pokaziva na nista
	niz = nullptr; //sa ovim stavljamo da pointer pokaziva na 0
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
	if ((i + j) % 2 == 0) //uzeli smo da ako nam je zbroj reda i kolone djeljiv sa 2 da nam je to crno polje
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
					//sa ovim rand automatiziramo unos a sa ovim vamo dole mi rucno unosimo elemente
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
	/*
	glavna dijagonala ide : 

	 \	*	*	*	*
	 *	\	*	*	*
	 *	*	\	*	*
	 *  *	*	\	*
	 *	*	*	*	\
	 

	sporedna dijagonala ide : 

	*	*	*	*	/
	*	*	*	/	*
	*	*	/	*	*
	*	/	*	*	*
	/	*	*	*	*



	*/
	cout << "Prosjek svih elemenata na crnim poljima ispod sporedne dijagonale je: " << setprecision(4) << prosjek_Crnih / float(brojacC) << endl;
	cout << "Prosjek svih elemenata na bijelim poljima iznad glavne dijagonale je: " << setprecision(4) << prosjek_Bijelih / float(brojacB) << endl;
}
