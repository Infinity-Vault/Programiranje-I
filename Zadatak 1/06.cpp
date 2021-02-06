int napraviB(int);
int main() {
	int A;
	int B;
	do {
		cout << "Molim vas unesite broj: " << endl;
		cin >> A;
		if (A < 100000)
			cout << "Unijeli ste nedovoljno velik broj!" << endl;
	} while (A < 100000);
	B = napraviB(A);
	cout << "Unesen je broj A: " << A << " dok je njegov ispis naopako bez parnih cifri: " << B << endl;
	cout << "RAZLIKA BROJEVA: " << "Broj A: " << " " << A << "\t" << "Broj B: " << B << endl;





	cin.get();
	return 0;
}
int napraviB(int A) {
	int B = 0;
	int cifra = 0;
	while (A > 0) {
		cifra = A % 10;
		if (cifra % 2 == 0)
			A /= 10;
		else {
			B = B * 10 + cifra;
			A /= 10;
		}
	}
	return B;
}