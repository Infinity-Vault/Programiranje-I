#include <iostream>

using namespace std;

int unosA();
int napraviB(int);

int main() {
	
	int A = unosA();
	int B = napraviB(A);
	
	cout << "Od unesenog A " << A << " napravljen je broj B sa obrnutim ciframa i bez parnih cifri: " << B << endl;
	cout << "Razlika A i B je: " << abs(A - B);

	cin.get();
	return 0;
}
int unosA() {
	
	int A;
	
	do {
		cout << "Unesite broj A: " << endl;
		cin >> A;
	} while (A <= 1000000);
	
	return A;
}
int napraviB(int A) {
	
	int B = 0;
	int cifra;
	
	while (A > 0) {
		
		cifra = A % 10;
		
		if (cifra % 2 == 0) {   // Ako je cifra parna, odbacuje se(preskace se dio spajanja u broj B i ide se direktno na iduci korak.)
			A /= 10;
		}
		
		else {
			B = B * 10 + cifra;
			A /= 10;
		}
	}
	
	return B;
}
