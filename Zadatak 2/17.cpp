#include <iostream>
using namespace std;

int unos();
float srednjaCifra(int);
int brojCifri(int);
int pomnozi(int);
int main() {
	int N = unos();
	cout << "Najmanja int vrijednost sa kojom se treba pomnoziti srednja cifra broja N: " << srednjaCifra(N) << " je broj : " << pomnozi(N) << endl;



	cin.get();
	return 0;

}
int unos() {
	int N;
	cout << "Unesite cijeli broj N : " << endl;
	cin >> N;
	return N;
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
	int Brcif = brojCifri(broj);
	if (Brcif % 2 == 0) {
		float temp;
		broj = broj / pow(10.0, (Brcif / 2 - 1));
		temp = broj % 10;
		broj /= 10;
		temp += broj % 10;
		return temp / 2.0;
	}
	else {
		broj = broj / pow(10.0, Brcif / 2);
		return broj % 10;
	}
}
int pomnozi(int N) {
	float srednjaCodN = srednjaCifra(N);
	float noviBroj = 0;
	int brojac = 1;
	while (noviBroj <= N) {
		noviBroj = srednjaCodN * brojac;
		if (noviBroj > N)
			break;
		brojac++;
	}
	return brojac;
}