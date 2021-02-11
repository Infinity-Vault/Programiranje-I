#include <iostream>
using namespace std;

int unos();
bool prost(int);
void program(int, int);
int main() {
	int a = unos();
	int b = unos();
	program(a, b);





	cin.get();
	return 0;
}
int unos() {
	int broj;
	do {
		cout << "Unesite broj : " << endl;
		cin >> broj;
	} while (broj < 1 || broj >= 500);
	return broj;
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
void program(int a, int b) {
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	int najveciProstbr = 0;
	for (int i = a + 1; i < b; i++)//a+1 da se izbjegne prva a i<b da se izbjegne zadnja, npr: 1 2 3 4 5  uzimace se cifre 2 3 4;
	{
		if (prost(i)) {
			if (i > najveciProstbr) {
				najveciProstbr = i;
			}
		}
	}
	cout << "Najveci prosti broj u datom intervalu zavrsava sa cifrom: " << najveciProstbr % 10 << endl;
}