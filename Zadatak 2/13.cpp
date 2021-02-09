#include <iostream>
#include <iomanip>
using namespace std;

int unos();
double Geometrijska_sredina(int);
int main() {
	int N = unos();
	cout << "Geometrijska sredina svih  neparnih brojeva dijeljivih sa 5  do unesenog " << N << " je: " << setprecision(4) << Geometrijska_sredina(N) << endl;



	cin.get();
	return 0;
}
int unos() {
	int N;
	cout << "Unesite cijeli broj N: " << endl;
	cin >> N;
	return N;
}
double Geometrijska_sredina(int N) {
	double GS = 1;
	float prolaz = 0;//Brojac je tipa float kako bi proracun GS bio tacan!
	for (int i = 1; i <= N; i += 2)
	{
		if (i % 5 == 0) {
			GS *= i;
			prolaz++;
		}
	}
	return pow(GS, 1 / prolaz);
}