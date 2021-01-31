#include <iostream>
using namespace std;
/*
 * Napisati program koji omoguæava korisniku unos integer vrijednosti veæe od 100. 
 Napisati funckiju koja æe provjeriti da li je uneseni broj u isto vrijeme i prost i "palindrom", odnosno da li je isti broj i kada se obrnnu sve cifre. 
 Po potrebi koristiti dodatne funkcije. Npr. brojevi 383, 727, 757, 787, 797, 919, 929 su u isto vrijeme i prosti brojevi i "palindromi".
 */
int unos();
bool prost(int);
void prostiPalindrom(int broj);

int main() {
	
	int broj = unos();
	prostiPalindrom(broj);

	cin.get();
	return 0;
 }
int unos() {
	
	int broj;
	
	do {
		cout << "Unesite broj veci od 100: " << endl;
		cin >> broj;
	} while (broj <= 100);
	
	return broj;
}
bool prost(int broj) {
	
	for (int i = 2; i <=broj/2; i++)
	{
		if (broj % i == 0)
			return false;
	}
	
	if (broj == 1)
		return false;
	
	return true;
}
void prostiPalindrom(int broj) {
	
	int kopija = broj;
	int noviBr = 0;
	
	while (broj > 0) {
		noviBr = noviBr * 10 + broj % 10;
		broj /= 10;
	}
	
	if (prost(kopija) && noviBr == kopija)
		cout << "Uneseni broj " << kopija << " je i prost i palindrom." << endl;
	
	else
		cout << "Uneseni broj " << kopija << " nije ni prost ni palindrom." << endl;

}
