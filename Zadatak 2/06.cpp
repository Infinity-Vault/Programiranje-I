#include <iostream>
#include <time.h>
using namespace std;

int unosN();
int baciKocku();
int vratiProcenat(int);
int main() {
	srand((time(0)));
	int baceno = 0;
	int case1 = 0, case2 = 0, case3 = 0, case4 = 0, case5 = 0, case6 = 0;
	int N, Kocka;
	N = unosN();
	//Moze i sa for i sa while!!!
	while (baceno < N) {//Treba < ne <= jer ide od nule brojac;
		Kocka = baciKocku();
		switch (Kocka)
		{
		case 1: {
			case1++;
		}break;
		case 2: {
			case2++;
		}break;
		case 3: {
			case3++;
		}break;
		case 4: {
			case4++;
		}break;
		case 5: {
			case5++;
		}break;
		case 6: {
			case6++;
		}break;
		default: {
			cout << "Ne validno bacanje kocke: " << endl;
		}
		}
		cout << Kocka << " ";
		baceno++;
	}
	cout << endl;
	cout << "Procenat bacanja za broj 1:" << round(vratiProcenat(case1) / N * 100.0) / 100.0 << "%" << endl;//Moze i sa mojom fijom 
	cout << "Procenat bacanja za broj 2: " << round(100 * double(case2) / N * 100.0) / 100.0 << "%" << endl;//Ili sa mnozenjem sa 100;
	cout << "Procenat bacanja za broj 3: " << round(vratiProcenat(case3) / N * 100.0) / 100.0 << "%" << endl;
	cout << "Procenat bacanja za broj 4: " << round(vratiProcenat(case4) / N * 100.0) / 100.0 << "%" << endl;
	cout << "Procenat bacanja za broj 5: " << round(vratiProcenat(case5) / N * 100.0) / 100.0 << "%" << endl;
	cout << "Procenat bacanja za broj 6: " << round(vratiProcenat(case6) / N * 100.0) / 100.0 << "%" << endl;






	cin.get();
	return 0;
}
int unosN() {
	int N;
	do {
		cout << "Molim vas unesite broj: " << endl;
		cin >> N;
	} while (N > 10 && N > 1000);
	return N;
}
int baciKocku() {
	int Kocka;
	Kocka = rand() % 6 + 1;
	return Kocka;
}
int vratiProcenat(int broj) {
	int procenat;
	procenat = broj * 100;
	return procenat;
}