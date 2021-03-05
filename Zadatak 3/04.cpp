#include <iostream>

using namespace std;

void puniNiz(int* niz, int n, int counter = 0); //funkcija sa kojom cemo rekurzivno puniti niz, counter je u ovom slucaju nas brojac pomocu kojega cemo znati do kojeg elementa smo dosli, ovdje ga odmah inicijalizujemo na nulu

void ispisNiz(int* niz, int n, int counter = 0); //funkcija sa kojom cemo rekurzivno ispisati niz, counter ima istu svrhu kao i gore navedenu

int main()
{
	int n;

	cout << "Unesite velicinu niza: "; //unosimo velicinu niza, ovo smo mogli i preporuceno bi bilo uraditi sa while petljom jer ovaj broj mora uvijek biti pozitivan
	cin >> n;

	int* niz = new int[n]; //kreiramo dinamicki jednodimenzionalni niz

	puniNiz(niz, n); //pozivamo funkciju za punjenje niza

	cout << "Elementi niza sa faktorijelima su: ";
	ispisNiz(niz, n); //pozivamo funkciju za ispis niza

	return 0;
}

void puniNiz(int* niz, int n, int counter) //n nam je nasa velicina niza koju korisnik unese
{
	if (counter == n) //ako je brojac koji nam broji koliko se je puta rekurzija izvrsila postane jednak broju n tj. unesenoj velicini niza to znaci da smo popunili cjeli niz i ovo nam je bazni slucaj te onda rekurziju prekidamo returnom
		return;

	
		if (counter == 0) //ako je brojac 0 tj. ako nam se rekurzivna funkcija prvi put izvrsava onda to znaci da moramo staviti koji ce nam prvi elemenat u nizu biti i od kojeg sve pocinje, taj je elemenat dat zadatkom a u ovom slucaju to je 1 (faktorijel od 0 je 1 i faktorijel od 1 je 1)
			*(niz + counter) = 1;

		else // u svakom drugom slucaju kada brojac krene da ide prema gore izvrsavati ce se ostatak koda
		{
			int temp = *(niz + counter - 1) * (counter + 1); //stvaramo varijablu temp u kojoj u biti zapisivano nas trenutni rekurzivni elemant tj. trenutni faktorijel u nizu, ova nam varijabla sluzi da provjeravamo kad ce se desiti overflow
			// *(niz + counter - 1) * (counter + 1) ovo je napisan na ovaj nacin jer nam uzima prijasnji elemenat u nizu koji je od ranije zapisan i mnozi ga sa onim elementom koji treba ici iduci (znamo da je prijasnji jer pisemo counter - 1  a znamod a je iduci jer pisemo counter+1) i sa tim sto mnozimo prijasnji elemenat sa predhodnim mi u biti stvaramo faktorijele

			if (temp < 0) //ako nam je varijabla temp manja od 0 dosli smo do overflowa i u niz se ne smije vise upsiivati nista tako da samo izlazimo iz rekurzivne funkcije tako sto pisemo return
				return;

			*(niz + counter) = temp; //ako gore navedeni if nije ispunjen onda se u niz u odredeno mjesto diktirano counterom upisuje vrijednost koja ima varijabla temp
		}
	

	puniNiz(niz, n, counter + 1); //uvijet ponavljanja rekurzije gdje u biti sve sto moramo raditi je povecavati nas brojac da znamo do kojeg smo elementa u nizu dosli
}

void ispisNiz(int* niz, int n, int counter) //n nam je nasa velicina niza koju korisnik unese
{
	if (counter == n) //ako je brojac koji nam broji koliko se je puta rekurzija izvrsila postane jednak broju n tj. unesenoj velicini niza to znaci da smo popunili cjeli niz i ovo nam je bazni slucaj te onda rekurziju prekidamo returnom
		return;


		cout << *(niz + counter) << " "; //ispisivamo elemenat niza 

	ispisNiz(niz, n, counter + 1); //uvijet ponavljanja rekurzije gdje u biti sve sto moramo raditi je povecavati nas brojac da znamo do kojeg smo elementa u nizu dosli
}
