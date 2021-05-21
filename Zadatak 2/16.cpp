#include <iostream>
using namespace std;

int unosm();
int unosn();
bool slozeni(int);
float artimeticka_sredina(int, int);
int main() {
	int m = unosm();
	int n = unosn();
	
	cout << "Aritmeticka sredina svih slozenih brojeva  u datom intervalu je: " << artimeticka_sredina(n, m) << endl;

	cin.get();
	return 0;
}

int unosm() {
	int m;
	
	do {
		cout << "Unesite broj m: " << endl;
		cin >> m;
	} while (m >= 100 || m <= 10);
	
	return m;
}

int unosn() {
	int n;
	
	do {
		cout << "Unesite broj n: " << endl;
		cin >> n;
	} while (n >= 2000 || n <= 500);
	
	return n;
}

bool slozeni(int broj) {
	for (int i = 2; i <= broj / 2; i++)
	{
		if (broj % i == 0)
			return true;
	}
	return false;
}

float artimeticka_sredina(int m, int n) {
	
	float artim = 0.0f;
	int brojac = 0;
	
	cout << "Brojevi su: " << endl;
	for (int i = m; i <= n; i++)
	{
		if (slozeni(i)) {
			cout << i << " ";
			artim += i;
			brojac++;
		}
	}
	
	cout << endl;
	
	if (brojac != 0)
		artim /= brojac;
	
	return artim;
}