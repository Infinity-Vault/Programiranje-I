#include <iostream>
#include<time.h>
using namespace std;
const int x = 10, y = 10;

int brCif(int);
void unos(int[][y]);
void ispis(int[][y]);
void red_i_kolona(int[][y]);
int main() {
	srand((time(0)));
	int niz[x][y];
	unos(niz);
	ispis(niz);
	red_i_kolona(niz);

	cin.get();
	return 0;

}
int brCif(int broj) {
	int brojac = 0;
	while (broj > 0) {
		broj /= 10;
		brojac++;
	}
	return brojac;
}
void unos(int niz[][y]) {
	int temp;
	cout << "Molim vas unesite " << x * y << " elemanata u niz: " << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			do {
				//cin >> temp;
				temp = rand() % 1000 + 1;
				niz[i][j] = temp;
				if (brCif(temp) % 2 == 0)
					cout << "Unijeli ste broj sa PARNIM  brojem cifri!!!" << endl;
			} while (brCif(temp) % 2 == 0);

		}
	}
}
void ispis(int niz[][y]) {
	cout << endl;
	cout << "Unijeli ste " << x * y << " elemenata u niz a oni su: " << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << niz[i][j] << "\t";
		}
		cout << endl;
	}
}
void red_i_kolona(int niz[][y]) {
	float rednP[x] = { 0 };
	float kolonanP[y] = { 0 };
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			rednP[i] += niz[i][j];
		}
		rednP[i] /= y;
	}
	int indeksNajvecegR = 0;
	for (int i = 0; i < x; i++)
	{
		if (rednP[i] > rednP[indeksNajvecegR]) {
			indeksNajvecegR = i;
		}
	}
	//cout << "Indeks reda sa najvecim prosjekom je: " << indeksNajvecegR << endl;
	cout << "\n";
	cout << "Ispis reda sa najvecim prosjekom: " << endl;
	for (int j = 0; j < y; j++)
	{
		cout << niz[indeksNajvecegR][j] << "\t";
	}
	cout << endl;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			kolonanP[i] += niz[j][i];
		}
		kolonanP[i] /= x;
	}
	int indeksNajveceK = 0;
	for (int i = 0; i < y; i++)
	{
		if (kolonanP[i] > kolonanP[indeksNajveceK]) {
			indeksNajveceK = i;
		}
	}
	//cout << "Indeks kolone sa najvecim prosjekom je: " << indeksNajveceK << endl;
	cout << "\n";
	cout << "Ispis kolone sa najvecim prosjekom: " << endl;
	for (int i = 0; i < x; i++)
	{
		cout << niz[i][indeksNajveceK] << endl;
	}
	cout << endl;
}