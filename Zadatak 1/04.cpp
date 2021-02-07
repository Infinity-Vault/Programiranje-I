int prebroji(int);
int obrni(int);
int srednjacifra(int);
int prva(int);
int zadnja(int);
int main() {
	int broj;
	do {
		cout << "Molim vas unesite prirodan broj: " << endl;
		cin >> broj;
	} while (broj < 1);
	cout << "Uneseni broj je: " << broj << endl;
	cout << "Cifra obrnuta je: " << obrni(broj) << endl;
	cout << "Srednja cifra je: " << srednjacifra(broj) << endl;
	cout << "Prva cifra: " << prva(broj) << endl;
	cout << "Zadnja cifra: " << zadnja(broj) << endl;




	cin.get();
	return 0;
}
int prebroji(int broj) {
	int brojac = 0;
	while (broj > 0) {
		broj /= 10;
		brojac++;

	}
	return brojac;
}
int obrni(int broj) {
	int pomocna = 0;
	while (broj > 0) {
		pomocna = pomocna * 10 + broj % 10;
		broj /= 10;
	}
	return pomocna;
}
int srednjacifra(int broj) {
	int brojcifri = prebroji(broj);
	if (brojcifri % 2 == 0) {
		int pomocna;
		broj = broj / pow(10.0, (brojcifri / 2 - 1));
		pomocna = broj % 10;
		broj /= 10;
		pomocna += broj % 10;
		return pomocna / 2;

	}
	else {
		broj = broj / pow(10.0, brojcifri / 2);
		broj = broj % 10;
		return broj;
	}
}
int prva(int broj) {
	while (broj >= 10) {//Ako stavimo samo >10 ako je broj sa 10 vratit ce prva cifra 10 sto nije dobro, zato treba >=10!!!
		broj /= 10;
	}
	return broj % 10;//Moze ili ne treba!!!
	//return broj;
}
int zadnja(int broj) {
	return broj % 10;
}