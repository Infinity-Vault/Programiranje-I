#include <iostream>
#include <iomanip>

using namespace std;

int unosN();

double Geometrijska_sredina(int);

int main() {
	
	int N = unosN();
	
	cout << "Geometrijska sredine svih neparnih brojeva koji nisu djeljivi sa 5 u datom intervalu je: " << setprecision(3) << Geometrijska_sredina(N) << endl;


	cin.get();
	return 0;
 }

int unosN() {
	int n;
	
	cout << "Unesite cijeli broj N: " << endl;
	cin >> n;
	
	return n;
}

double Geometrijska_sredina(int N) {
	
	double GS = 1.0;
	int brojac = 1;
	
	for (int i = 1; i <=N; i+=2)
	{
		if (i % 5 != 0) {
			GS *= i;
			brojac++;
		}
	}
	return pow(GS, 1 / double(brojac)); // Cast brojac u double da se ne bi izgubila preciznost ispisa jer je brojac int
}
