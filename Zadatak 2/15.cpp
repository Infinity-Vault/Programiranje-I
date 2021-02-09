#include <iostream>
using namespace std;

int brojCifri(int);
int unosM();
int unosN();
int srednjaCifra(int);
void Aritmeticka_sredina_i_najveca_srednja_cifra(int, int);
void ispisBrojeva(int, int);
int main() {
	int n = unosN();
	int m = unosM();
	ispisBrojeva(n, m);
	Aritmeticka_sredina_i_najveca_srednja_cifra(n, m);

	cin.get();
	return 0;
}
int brojCifri(int broj) {
	int br = 0;
	while (broj > 0) {
		broj /= 10;
		br++;
	}
	return br;
}
int unosM() {
	int m;
	do {
		cout << "Unesite broj m: " << endl;
		cin >> m;
	} while (brojCifri(m) <= 2 || m <= 100);
	return m;
}
int unosN() {
	int n;
	do {
		cout << "Unesite broj n: " << endl;
		cin >> n;
	} while (brojCifri(n) <= 2 || n >= 500);
	return n;
}
int srednjaCifra(int broj) {
	int brCifri = brojCifri(broj);
	if (brCifri % 2 == 0) {
		int temp = 0;
		broj = broj / pow(10.0, (brCifri / 2 - 1));
		temp = broj % 10;
		broj /= 10;
		temp += broj % 10;
		return temp / 2;

	}
	else {
		broj = broj / pow(10.0, brCifri / 2);
		return broj % 10;
	}
}
void Aritmeticka_sredina_i_najveca_srednja_cifra(int n, int m) {
	float suma = 0.0;
	int brojaczaSumu = 0;
	int najvecaSrednjacifra = 0;
	if (m > n) {
		int temp = n;
		n = m;
		m = temp;
	}
	for (int i = m; i <= n; i++)
	{
		suma += srednjaCifra(i);
		brojaczaSumu++;
		if (srednjaCifra(i) > najvecaSrednjacifra)
			najvecaSrednjacifra = srednjaCifra(i);
	}
	cout << "Aritmeticka sredina svih srednjih cifri svih brojeva ranga od n do m je: " << suma / float(brojaczaSumu) << endl;
	cout << "Najveca srednja cifra svih brojeva u rangu od n do m je: " << najvecaSrednjacifra << endl;

}
void ispisBrojeva(int n, int m) {
	if (m > n) {
		int temp = n;
		n = m;
		m = temp;
	}
	for (int i = m; i <= n; i++)
	{
		cout << i << " ";
	}
	cout << endl;
}
