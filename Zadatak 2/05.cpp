void promjena(int&);
int main() {
	int N;
	do {
		cout << "Molim vas unesite broj: " << endl;
		cin >> N;
	} while (N > 5000000 || N < 50);
	promjena(N);




	cin.get();
	return 0;
}
void promjena(int& N) {
	int pomocna = 0;
	int ostatak = 0;
	while (N > 0) {
		ostatak = N % 10;
		if (ostatak % 2 != 0) {
			N /= 10;
		}
		else {
			pomocna = pomocna * 10 + ostatak;
			N /= 10;
		}
	}
	cout << "Uneseni broj procitan naopako bez neparnih cifri je: " << pomocna << endl;
}
