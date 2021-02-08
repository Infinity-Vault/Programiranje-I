#include <iostream>
using namespace std;
const int x = 8, y = 8;

bool paranRed(int);
bool neparanRed(int);
void unos(int[][y]);
void ispis(int[][y]);
int indeks_Kolone_sa_Najmanjim_prosjekom_Elemenata(int[][y]);
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
		for (int j = 0; j < y; j++)
		{
			if (paranRed(i)) {
				do {
					cout << "Unesite NEPARAN broj: " << endl;
					cin >> temp;
					if (temp % 2 != 0) {
						niz[i][j] = temp;
						break;
					}
					if (temp % 2 == 0)
						cout << "Unos nije vazeci unijeli ste PARAN broj!" << endl;
				} while (temp % 2 == 0);

			}
			/*if (neparanRed(i))*/else {//Moze i sa else bez upotrebe fije za pronalazenje neparnog reda;
				do {
					cout << "Unesite PARAN broj: " << endl;
					cin >> temp;
					if (temp % 2 == 0) {
						niz[i][j] = temp;
						break;
					}
					if (temp % 2 != 0)
						cout << "Unos nije vazeci unijeli ste NEPARAN broj: " << endl;
				} while (temp % 2 != 0);
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