int fibonacci(int);
void punjenjeNiza(int*, int, int brojac = 0);
void provjera(int*, int, int, int brojac = 0);
int main() {
	//Kreiranje jednodim dinamickog niza:
	int velicina;
	cout << "Unesite velicinu niza: " << endl;
	cin >> velicina;
	int* niz = new int[velicina];
	punjenjeNiza(niz, velicina);
	//Ispis:
	for (int i = 0; i < velicina; i++)
	{
		cout << *(niz + i) << " ";
	}
	cout << endl;
	int izbor;
	cout << "Molim vas unesite broj za koji zelite znati da li ga ima u nizu: " << endl;
	cin >> izbor;
	provjera(niz, velicina, izbor);


	delete[]niz;
	niz = nullptr;
	cin.get();
	return 0;
}
int fibonacci(int broj) {

	if (broj <= 1)//Bazni slucaj, specifican za ovu rekurziju 
		return 1;
	return fibonacci(broj - 1) + fibonacci(broj - 2);
}
void punjenjeNiza(int* niz, int velicina, int brojac) {
	if (brojac == velicina)
		return;
	if (brojac < velicina) {
		if (brojac == 0)
			*(niz + brojac) = fibonacci(brojac);
		if (brojac == 1)
			*(niz + brojac) = fibonacci(brojac);
		int temp;
		temp = fibonacci(brojac);
		if (temp < 0)//Provjerimo overflow;
			return;
		else
			*(niz + brojac) = temp;

		punjenjeNiza(niz, velicina, brojac + 1);
	}
}
void provjera(int* niz, int velicina, int izbor, int brojac) {
	if (brojac == velicina)//Bazni slucaj;
		return;
	if (brojac < velicina) {
		if (brojac == 0 && *(niz + brojac) == izbor)
			cout << "Nadjen je element na indeksu: " << brojac << endl;
		else if (brojac == 1 && *(niz + brojac) == izbor)
			cout << "Nadjen je element na indeksu: " << brojac << endl;
		else if (*(niz + brojac) == izbor)
			cout << "Nadjen je element na indeksu: " << brojac << endl;
		provjera(niz, velicina, izbor, brojac + 1);
	}


}