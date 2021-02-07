#include <iostream>
#include <time.h>
using namespace std;

void punjenje(int*, int, int brojac = 0);
void ispis(int*, int, int brojac = 0);

int main() {
	srand((time(0)));
	int n;
	cout << "Molim vas unesite duzinu niza koju zelite : " << endl;
	cin >> n;
	int* niz = new int[n];
	punjenje(niz, n);
	//Ispis:
	//for (int i = 0; i < n; i++)
	//{
	//	cout << *(niz + i) << " ";
	//}
	cout << endl;
	ispis(niz, n);




	//Dealokacija:
	delete[]niz;
	niz = nullptr;
	cin.get();
	return 0;
}
void punjenje(int* niz, int n, int brojac) {
	if (brojac == n)
		return;
	if (brojac < n) {
		if (brojac == 0) {
			*(niz + brojac) = rand() % 100 + 1;
			if (*(niz + brojac) == *(niz + brojac - 1) && *(niz + brojac) == *(niz + brojac - 2)) {
				return;
			}
		}
		if (brojac == 1) {
			*(niz + brojac) = rand() % 100 + 1;
			if (*(niz + brojac) == *(niz + brojac - 1) && *(niz + brojac) == *(niz + brojac - 2)) {
				return;
			}
		}
		*(niz + brojac) = rand() % 100 + 1;
		if (*(niz + brojac) == *(niz + brojac - 1) && *(niz + brojac) == *(niz + brojac - 2)) {
			return;
		}
	}
	punjenje(niz, n, brojac + 1);
}
void ispis(int* niz, int n, int brojac) {
	if (brojac == n)
		return;
	if (brojac < n) {
		cout << *(niz + brojac) << " ";
		ispis(niz, n, brojac + 1);
	}

}