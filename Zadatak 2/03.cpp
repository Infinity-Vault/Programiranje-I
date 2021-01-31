#include <iostream>
using namespace std;

int unos();
int Zamjeni(int);

int main() {
	
	int n = unos();
	int NoviBroj = Zamjeni(n);
	
	cout << "Od unesenog broja napravljen je broj sa tim ciframa gdje je svaka  parna cifra zamjenjena sa cifrom 5: " << NoviBroj << endl;
	cout << "Razlika ove dvije cifre je: " << abs(n - NoviBroj);

	cin.get();
	return 0;
}
int unos() {
	
	int broj;
	
	cout << "Unesite broj: " << endl;
	cin >> broj;
	
	return broj;
}
int Zamjeni(int n) {
	int noviBr = 0;
	int brojac = 0;
	int cifra;
	
	while (n > 0) {
		
		cifra = n % 10;
		
		if (cifra % 2 == 0) {
			noviBr = noviBr + 5 * pow(10.0, brojac);
			brojac++;
			n /= 10;
		}
		
		else {
			noviBr = noviBr + cifra * pow(10.0, brojac);
			brojac++;
			n /= 10;
		}
	}
	
	return noviBr;
}