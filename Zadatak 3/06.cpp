#include <iostream>
using namespace std;
const int x = 20;

int Fibonacci(int);
void Napuni_niz(int[]);
void Ispisi_niz(int[]);
int prebrojiCifre(int);
int srednjaCifra(int);
void Sort(int[]);
int main() {
	int niz[x];
	Napuni_niz(niz);
	Ispisi_niz(niz);
	Sort(niz);
	cin.get();
	return 0;
}
int Fibonacci(int broj) {
	if (broj <= 1)
		return 1;
	return Fibonacci(broj - 2) + Fibonacci(broj - 1);
}
void Napuni_niz(int niz[]) {
	for (int i = 0; i < x; i++)
	{
		niz[i] = Fibonacci(i);
	}
}
void Ispisi_niz(int niz[]) {
	cout << endl;
	cout << "Elementi niza su: " << endl;
	for (int i = 0; i < x; i++)
	{
		cout << niz[i] << "\t";
	}
}
int prebrojiCifre(int broj) {
	int br = 0;
	while (broj > 0) {
		broj /= 10;
		br++;
	}
	return br;
}
int srednjaCifra(int broj) {
	int brCifri = prebrojiCifre(broj);
	if (brCifri % 2 == 0) {
		broj = broj / pow(10.0, (brCifri / 2 - 1));
		int temp = broj % 10;
		broj /= 10;
		temp += broj % 10;
		return temp / 2;//MORA BITI INT KAKO BI PODIJELJEN BROJ BIO CIJELI, NPR  5/2=2.5 ALI CE SE GLEDATI SAMO CIJELI DIO TJ. 2;

	}
	else {
		broj = broj / pow(10.0, brCifri / 2);
		return broj % 10;
	}
}
void Sort(int niz[]) {
	//Posto koristimo while moramo na pocetku deklar zastavu kao true, da smo koristili do while to ne bi trebalo;
	bool zastava = true;
	while (zastava) {
		zastava = false;
		for (int i = 0; i < x - 1; i++)
		{
			if (srednjaCifra(niz[i]) > srednjaCifra(niz[i + 1])) {
				int temp = niz[i + 1];
				niz[i + 1] = niz[i];
				niz[i] = temp;
				zastava = true;
			}
		}
	}
	Ispisi_niz(niz);

}