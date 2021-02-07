#include <iostream>

using namespace std;

int unos();

int main() {
	
	int sastavljeniBr = 0;
	int cifra = 0;
	
	do {
		
		cifra = unos();
		
		if (cifra < 0)//Dodatna provjera da se ne bi sracunao neg broj, jer se uslov gleda na kraju zbog do while;
			break;
		
		if (cifra > 9)
			cout << "Cifra nije validna" << endl;
		
		else {
			sastavljeniBr = sastavljeniBr * 10 + cifra;
		}
		
	} while (cifra >= 0);
	
	cout << "Od unesenih cifri je sastavljen broj: " << sastavljeniBr << endl;

	cin.get();
	return 0;
}
int unos() {
	
	int broj;
	
	cout << "Unesite broj: " << endl;
	cin >> broj;
	
	return broj;
}