int unos();
int Obrnibroj(int);
int sumaCifri(int);
void ispisXY(int, int);
int main() {

	int x = unos();
	int y = unos();
	ispisXY(x, y);


	cin.get();
	return 0;

}
int unos() {
	int broj;
	do {
		cout << "Unesite broj: " << endl;
		cin >> broj;
	} while (broj < 10 || broj>5000);
	return broj;
}
int Obrnibroj(int broj) {
	int obrnuti = 0;
	while (broj > 0) {
		obrnuti = obrnuti * 10 + broj % 10;
		broj /= 10;
	}
	return obrnuti;
}
int sumaCifri(int broj) {
	int Suma = 0;
	while (broj > 0) {
		Suma += broj % 10;
		broj /= 10;
	}
	return Suma;
}
void ispisXY(int X, int Y) {
	int obrni;
	int sumac;
	for (int i = X; i <= Y; i++)
	{
		obrni = Obrnibroj(i);
		sumac = sumaCifri(i);
		if (obrni % sumac == 0) {
			cout << i << " ";
		}
		/*else {
			i++;
		}*/
	}
}