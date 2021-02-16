#include <iostream>
using namespace std;
const int x = 8, y = 8; //pravimo konstantne brojeve jer matrica mora imati 64 polja tj. x(broj redova)=8 i y(broj kolona)=8 pa 8*8=64

bool paranRed(int); //funkcija kojom trazimo parni red 
bool neparanRed(int); //funkcija kojom trazimo neparni red iako nam nije ni potrebna 
void unos(int[][y]); //funkcija za unos elemenata u matricu nasu
void ispis(int[][y]); //funkcija za ispis elemenata nase matrice
int indeks_Kolone_sa_Najmanjim_prosjekom_Elemenata(int[][y]); //funkcija za pretragu kolone sa najmanjim prosjekom
int main() {
	int niz[x][y];
	unos(niz);
	ispis(niz);
	int indeks = indeks_Kolone_sa_Najmanjim_prosjekom_Elemenata(niz);
	cout << endl;
	cout << "Ispis kolone sa najmanjim prosjekom elemenata: " << endl;
	for (int i = 0; i < x; i++)
	{
		cout << niz[i][indeks] << endl;
	}
	cout << endl;

	cin.get();
	return 0;

}
void unos(int  niz[][y]) {
	int temp;
	cout << "Unesite " << x * y << " elemenata u niz: " << endl;
	for (int i = 0; i < x; i++)//Null-ti (0) red ce se gledati kao paran;
	{
		//SAMO UKLONITI KOMENTARE DOLE AKO ŽELITE RUČNO UPISIVATI CIFRE
		for (int j = 0; j < y; j++)
		{
			if (paranRed(i)) {
				/*do {
					cout << "Unesite NEPARAN broj: " << endl;
					cin >> temp;
					if (temp % 2 != 0) {
						niz[i][j] = temp;
						break;
					}
					if (temp % 2 == 0)
						cout << "Unos nije vazeci unijeli ste PARAN broj!" << endl;
				} while (temp % 2 == 0);


				*/ //ovo radi i ovo je ispravan nacin kako zadatak uraditi po postavci ali je predugo za rucno pisati pa je lakse zbog provjere automatizirati sa ovim generisanjem slucajnog broja :


				niz[i][j] = (rand() % 100 + 1) * 2; //ovo unosi random broj koji ce uvijek biti paran (jer taj random broj pomnozimo sa 2)

			}
			/*if (neparanRed(i))*/ else {//Moze i sa else bez upotrebe fije za pronalazenje neparnog reda;
				/*do {
					cout << "Unesite PARAN broj: " << endl;
					cin >> temp;
					if (temp % 2 == 0) {
						niz[i][j] = temp;
						break;
					}
					if (temp % 2 != 0)
						cout << "Unos nije vazeci unijeli ste NEPARAN broj: " << endl;
				} while (temp % 2 != 0);


				*/ //isto i ovo radi ali da ne bi ručno unosili toliko puta zbog provjere samo ćemo koristit rand funkciju koja upisuje slucajan neparan broj


				niz[i][j] = (rand() % 100 + 1) * 2+1; //isto kao i gore random broj dobijemo koji mnozenjem sa 2 pretvara u paran broj i onda taj broj samo sabiramo sa 1 i dobijemo neparan broj
			}

		}
	}
}
void ispis(int niz[][y]) {
	cout << endl;
	cout << "Uneseni elementi su: " << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << niz[i][j] << " \t ";
		}
		cout << endl;
	}
}
int indeks_Kolone_sa_Najmanjim_prosjekom_Elemenata(int niz[][y]) {
	float prosjekK[y] = { 0 };
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			prosjekK[i] += niz[j][i];
		}
		prosjekK[i] /= y;
	}
	int najmanjiP = 0;
	for (int i = 0; i < y; i++)
	{
		if (prosjekK[i] < prosjekK[najmanjiP]) {
			najmanjiP = i;
		}
	}
	cout << "Kolona sa najmanjim prosjekom se nalazi na indeksu: " << najmanjiP << endl;
	return najmanjiP;
}

bool paranRed(int red) {
	if (red % 2 == 0)
		return true;
	return false;
}
bool neparanRed(int red) {
	if (red % 2 != 0)
		return true;
	return false;
}
