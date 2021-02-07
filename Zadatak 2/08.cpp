#include<iostream>
using namespace std;

int unos();
int zamjenjeni(int);
int main() {
	int n = unos();
	int M = zamjenjeni(n);
	cout << "Uneseni broj je: " << n << " a napravljen je broj M  od broja n gdje su njegove parne cifre zamijenjene sa ciframa '5': " << M << endl;
	cout << "Razlika ova dva broja je: " << abs(n - M) << endl;


	cin.get();
	return 0;

}
int unos() {
	int n;
	do {
		cout << "Unesi broj: " << endl;
		cin >> n;
		if (n <= 0)
			cout << "Niste unijeli pozitivan broj: " << endl;
	} while (n <= 0);
	return n;
}
int zamjenjeni(int n) {
	int Zamjena = 0;
	int brojac = 0;
	int cifra;
	//Prvi nacin: Koristi obrnuti broj;

	/*while (n > 0) {
		cifra = n % 10;
		if (cifra %2== 0) {
			Zamjena = Zamjena * 10 + 5;
			n /= 10;
		}
		else {
			Zamjena = Zamjena * 10 + cifra;
			n /= 10;
		}
	}
	return Zamjena;*/

	//Drugi nacin: Koristi normalan broj, ne obrnut;
	while (n > 0) {
		cifra = n % 10;
		if (cifra % 2 == 0) {
			Zamjena = 5 * pow(10.0, brojac) + Zamjena;
			brojac++;
			n /= 10;
		}
		else {
			Zamjena = cifra * pow(10.0, brojac) + Zamjena;
			brojac++;
			n /= 10;
		}
	}
	return Zamjena;
}

