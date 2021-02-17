#include <iostream>
using namespace std;

int unosm();
int unosn();
int brojCifri(int);
float srednjaCifra(int);
int main() {
	float proslaSrednjacif;
	float trenutnaSrednjacif = 0;
	int m, n;
	bool zastava = true;
	do {
		m = unosm();
		n = unosn();
		if (n == 0) {
			cout << "Forsirani prekid..." << endl;
			break;
		}
		trenutnaSrednjacif = srednjaCifra(m * n);

		if (zastava) {
			cout << "Srednja cifra proizvoda brojeva " << m << " i " << n << " iznosi: " << trenutnaSrednjacif << endl;
			zastava = false;
			proslaSrednjacif = trenutnaSrednjacif;
		}

		if (trenutnaSrednjacif > proslaSrednjacif) {
			cout << "Srednja cifra proizvoda brojeva " << m << " i " << n << " iznosi: " << trenutnaSrednjacif << endl;
			proslaSrednjacif = trenutnaSrednjacif;
		}

	} while (trenutnaSrednjacif < 9);



	cin.get();
	return 0;
}
int unosm() {
	int m;
	do {
		cout << "Unesite broj m: " << endl;
		cin >> m;
	} while (m > 50 || m < 1);
	return m;
}
int unosn() {
	int n;
	do {
		cout << "Unesite broj n: " << endl;
		cin >> n;
	} while (n > 500);//|| n < 1);
	return n;
}
int brojCifri(int broj) {
	int br = 0;
	while (broj > 0) {
		broj /= 10;
		br++;
	}
	return br;
}
float srednjaCifra(int broj) {
	int brCif = brojCifri(broj);
	if (brCif % 2 == 0) {
		float temp;
		broj = broj / pow(10.0, (brCif / 2 - 1));
		temp = broj % 10;
		broj /= 10;
		temp += broj % 10;
		return temp / 2.0;
	}
	else {
		broj = broj / pow(10.0, brCif / 2);
		return broj % 10;
	}
}