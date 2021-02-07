#include <iostream>
#include<time.h>
using namespace std;

int unos();
bool prost(int);
int main() {
	srand((time(0)));
	int n = unos();
	int slucajna_Vrijednost;
	int brojacZaprost = 0;

	for (int i = 0; i < n; i++)
	{
		slucajna_Vrijednost = rand() % 1000 + 1;
		cout << slucajna_Vrijednost << " ";
		if (prost(slucajna_Vrijednost)) {
			brojacZaprost++;
		}
	}
	cout << "\n";
	cout << "Od " << n << "  generisanih prostih brojeva  ima: " << double((100 * brojacZaprost) / n * 100.0) / 100.0 << " % " << endl;



	cin.get();
	return 0;
}
int unos() {
	int n;
	do {
		cout << "Unesite broj: " << endl;
		cin >> n;
	} while (n < 10 || n > 1000);
	return n;
}
bool prost(int broj) {
	for (int i = 2; i <= broj / 2; i++)
	{
		if (broj % i == 0)
			return false;
	}
	if (broj == 1)
		return false;
	return true;
}

