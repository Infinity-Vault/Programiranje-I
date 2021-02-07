#include <iostream>
using namespace std;

int unos();
float suma(int);
int main() {
	int n = unos();
	cout << "Suma je: " << suma(n);



	cin.get();
	return 0;
}
int unos() {
	int n;
	do {
		cout << "Unesi broj: " << endl;
		cin >> n;
		if (n < 1)
			cout << "Uneseni broj nije prirodan: " << endl;
	} while (n < 1);
	return n;
}
float suma(int n) {
	float suma = 0;

	for (int i = 1; i <= n; i++)
	{
		suma += 1 / pow(2 * i + 1, 2);
	}
	return suma;
}
