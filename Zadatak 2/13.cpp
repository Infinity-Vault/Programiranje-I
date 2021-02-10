#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	const double godisnjirastA = 2.05,
		godisnirastB = 2.80,
		godisnjirastC = 4.30;
	double firmaA = 10, firmaB = 7, firmaC = 5;
	int brojGodina = 0;
	while (firmaB <= firmaA && firmaC <= firmaA) {
		firmaA = firmaA + (firmaA * godisnjirastA / 100.0);
		firmaB = firmaB + (firmaB * godisnirastB / 100.0);
		firmaC = firmaC + (firmaC * godisnjirastC / 100.0);
		brojGodina++;
	}
	if (firmaB > firmaC)
		cout << "Firma B je prva prestigla firmu A za " << brojGodina << " godina." << endl;
	else
		cout << "Firma C je prva prestigla firmu A za " << brojGodina << " godina." << endl;

	cout << "Godisnji prihod firme A u " << brojGodina << " godini iznosi " << fixed << setprecision(2) << firmaA << " M EURA." << endl;
	cout << "Godisnji prihod firme B u " << brojGodina << " godini iznosi " << firmaB << " M EURA." << endl;
	cout << "Godisnji prihod firme C u " << brojGodina << " godini iznosi " << firmaC << " M EURA." << endl;

	cin.get();
	return 0;
}
