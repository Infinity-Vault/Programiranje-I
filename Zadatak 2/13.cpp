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
		cout << "Unesite broj: " << endl;
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
	int umnozak = 1;
	if (a > b) {
		int temp = b;
		b = a;
		a = temp;
	}
	for (int i = a; i <= b; i++)
	{
		if (prost(i)) {
			umnozak *= i;
		}
	}
	cout << "Umnozak svih prostih brojeva u zadanom intervalu zavrsava sa cifrom: " << umnozak % 10 << endl;
}