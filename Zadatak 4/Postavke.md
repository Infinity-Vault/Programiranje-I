## [**01 (Ispitni)**](01.cpp)

Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa fudbaler (fudbaler je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza.

```c++
struct fudbaler
{
    int* godRodjenja;
    int* brojIgraca;
    int* golovi;
};
```

Redovi dvodimenzionalnog niza predstavljaju različite timove, a kolone predstavljaju igrače u tim timovima.

Omogućiti korisniku unos svih podataka za sve igrače, te napraviti (i testirati u main funkciji) funkciju koja će pronaći tim sa najvećim prosjekom. Zatim napraviti (i testirati u main funkciji) funkciju koja će pronaći igrača sa najviše golova u timu sa najlošijim prosjekom golova. Radi lakšeg testiranja programa obavezno u funkciji unosa podataka omogućiti da se podaci generišu kao sljedeće:

```c++
godRodjenja: 1980 + rand() % ((2000 + 1) - 1980) // Generiše brojeve u rangu 1980 - 2000
brojIgraca: rand() % 30 + 1
golovi: rand() % 5
```

**(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)**

## [**02 (Ispitni)**](02.cpp)

Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vozilo (vozilo je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza.
```c++
struct vozilo
{
    char *markaVozila;
    char *brojSasije;
    char *tipVozila; //dozvoliti unos samo vrijednosti "A", "B", ili "C"
    int *kubnihCM;
};
```

Redovi dvodimenzionalnog niza predstavljaju različite firme a u kolone različita vozila u tim firmama.
(radi jednostavnosti rješenja podrazumijevati da svaka firma ima isti broj vozila). 
Omogućiti korisniku unos svih podataka za sva vozila. 

Napisati i testirati funkciju koja će pronaći (firmu) koja ima največu prosječnu kubikazu vozila
(prosjek vrijednosti kubnihCM). 


Zatim napisati i testirati funkciju koja će pronaći i ispisati porosječnu kubikažu vozila (prosjek vrijednosti kubnihCM) svih vozila tipova "A" te posebno 
svih vozila tipa "B" u cijeloj matrici 

(Pošto se trazi u istoj funkciji, vodite računa o optimizaciji petlji jer to utiče na broj bodova). 

**(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)**

## [**03 (Ispitni)**](03.cpp)
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vozilo (vozilo je struktura čija su obilježja data u nastavku). 
Omogućiti korisniku da unese dimenzije niza.
```c++
struct vozilo
{
    char *markaVozila;
    char *nazivVozila;
    char *tipVozila; // omogućiti unos samo 'A', 'B','C'
    float *potrosnja_goriva_po_km;
};
```
Redovi matrice predstavljaju firme, kolone automobile.
Izračunati u kojoj je firmi najveća potrošnja goriva po km. 

Naći i ispisati prosjek potrošnje goriva po km u vozilima tipa C u cijeloj matrici.

**(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)**

## [**04 (Ispitni)**](04.cpp)

Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vremenska_prognoza (prognoza je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza.
```c++
struct vremenska_prognoza
{
    char *padavine; //dozvoliti unos rijeci npr. "kisa" ili "snijeg"
    float *temperatura;
    float *vlaznost_vazduha;
};
```
Redovi dvodimenzionalnog niza predstavljaju različite meteorologe, a kolone različite dane. Omogućiti korisniku unos svih prognoza za sve meteorologe. 
Dodatno kreirati jednodimenzionalni dinamički niz čija će veličina biti uneseni broj dana u koji ćete omogućiti unos stvarnih izmjerenih vrijednosti za dane.
Zatim napraviti funkciju koja će pronaći i ispisati index meteorologa čija je prognoza dnevnih temperatura bila najtačnija, odnosno koji je imao najmanju grešku u
procjeni temperatura.
Pomoć: suma svih razlika između prognozirane i stvarne temperature za jednog meteorologa predstavlja njegovu ukupnu grešku.

**(U ovom zadatku je zabranjeno indeksirati elemente u niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)**

## [**05**](05.cpp)
2D niz na slici predstavlja šahovsku tablu. Napraviti i testirati u main programu slijedeće funkcije:

1. Funkcija za unos elemenata tako da se u svako crno polje unese parni broj sa neparnim brojem cifara a u svako bijelo polje unese neparni broj sa parnim brojem cifara. 
2. Funkcija koja će računati aritmetičku sredinu svih brojeva na crnim poljima iznad glavne dijagonale.

Za olaksanje rjesenja, mozete izabrati prototip funkcija po zelji te kreirati dodatne funkcije po potrebi.

**(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)**


## [**06 (Ispitni)**](06.cpp)

Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa košarkaš (košarkaš je struktura čija su obilježja data u nastavku). 
Omogućiti korisniku da unese dimenzije niza.
```c++
struct kosarkas
{
    char *ID;
    char *imePrezime;
    int *postignutiKosevi;
};
```
Redovi dvodimenzionalnog niza predstavljaju različite košarkaše a kolone različite klubove.
Omogućiti korisniku unos svih podataka za sve košarkaše, te napraviti funkciju koja će pronaći najuspješniji klub (klub u kojem je postignut najveći broj koševa).
Također je potrebno pronači najuspješnijeg košarkaša u tom timu (ne mora biti najuspješniji u ligi)  i najlošijeg košarkaša u kompletnoj ligi te izračunati razliku u broju postignutih koševa ta dva košarkaša. 

**(Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta razlika.)**


## [**07 (Ispitni)**](07.cpp)

Kreirati dvodimenzionalni dinamički niz čiji su elementi objekti tipa figura (figura je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza, te omogućiti unos elemenata.
```c++
struct figura
{
    int ID
    char *nazivFigure;
    float *visinaFigure;
}
```
Potrebno je napisati funkciju koja će računati prosječnu visinu svih figura koje se nalaze na crnim poljima ispod sporedne dijagonale. 

**(Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta vrijednost.)**
```c++
    C - Crna
    B - Bijela
    +-----+-----+-----+-----+-----+-----+-----+-----+
    | C00 | B01 | C02 | B03 | C04 | B05 | C06 | B07 |
    +-----+-----+-----+-----+-----+-----+-----+-----+
    | B10 | C11 | B12 | C13 | B14 | C15 | B16 | C17 |
    +-----+-----+-----+-----+-----+-----+-----+-----+
    | C20 | B21 | C22 | B23 | C24 | B25 | C26 | B27 |
    +-----+-----+-----+-----+-----+-----+-----+-----+
    | B30 | C31 | B32 | C33 | B34 | C35 | B36 | C37 |
    +-----+-----+-----+-----+-----+-----+-----+-----+
    | C40 | B41 | C42 | B43 | C44 | B45 | C46 | B47 |
    +-----+-----+-----+-----+-----+-----+-----+-----+
    | B50 | C51 | B52 | C53 | B54 | C55 | B56 | C57 |
    +-----+-----+-----+-----+-----+-----+-----+-----+
    | C60 | B61 | C62 | B63 | C64 | B65 | C66 | B67 |
    +-----+-----+-----+-----+-----+-----+-----+-----+
    | B70 | C71 | B72 | C73 | B74 | C75 | B76 | C77 |
    +-----+-----+-----+-----+-----+-----+-----+-----+
```
## [**08**](08.cpp)
Dat je 2D niz dimenzija 8 x 8.
Omogućiti korisniku unos cjelobrojnih elemenata 2D niza tako da se u svaki neparni red unesu parni brojevi a svaki parni red neparni broj.
Napraviti funkciju koja pronalazi kolonu sa najmanjim prosjekom elemenata.
U istoj funkciji ispisati index pronađene kolone, a u main funkciji sve elemente te kolone.

## [**09 (Ispitni)**](09.cpp)

Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa uposlenik (uposlenik je struktura čija su obilježja data). 
Omogućiti korisniku da unese dimenzije niza.
```c++
struct uposlenik
{
    char *ID;
    char *imePrezime;
    float *plata;
}
```
Redovi dvodimenzionalnog niza predstavljaju različite odjele firme u kojima rade različiti radnici (radi jednostavnosti rješenja podrazumijevati da svaki odjel ima isti broj radnika).

Omogućiti korisniku unos svih podataka za sve radnike, te napraviti funkciju koja će naći najveći prosjek plate po odjelima firme te ispisati koji je to redni broj odjela 
(indeks reda sa najvećim prosjekom) i koji je najveći prosjek plate.

## [**10**](10.cpp)

Neka je dat 2D niz tipa int dimenzija 10x10. Kreirati, a potom u glavnom programu testirati, sljedeće funkcije:
a) Funkciju koja za vrsi generisanje podataka u 2D nizu na nacin da se u elementu sa indexom [0][0] upise vrijednost 1 a svaki slijedeci element da ima vrijednost prethodnog elementa pomnozenog sa 2 kao na slici.Generisanje se prekida ako se desi overflow na varijabli int.
b) Funkciju koja popunjenu matricu iz pod-zadatka a) transponuje tako sto joj zamjeni redove i kolone. 
c) Funkciju koja računa aritmetičku sredinu elemenata na "crnim poljima" iznad glavne dijagonale kao na slici

## [**11**](11.cpp)
Napisati program koji će omogućiti unos elemenata matrice dimenzija 10x10 cijelim brojevima sa neparnim brojem cifara.Za provjeru broja cifara koristiti funkciju brCif(int).
Zatim pronaći i ispisati red sa najvećim prosjekom (aritmetičkom sredinom) elemenata, te kolonu sa najmanjim prosjekom elemenata.

## [**12**](12.cpp)
Dat je 2D niz koji simulira šahovsku tablu. Omogućiti korisniku unos cjelobrojnih elemenata 2D niza tako da se u svako "crno" polje unese parni broj sa neparnim brojem cifara, a u "bijelo polje neparni broj sa parnim brojem cifara.
Izračunati i ispisati prosjeke (aritmetičke sredine) svih elemenata na bijelim poljima iznad glavne dijagonale te na crnim poljima ispod sporedne dijagonale.

## [**13**](13.cpp)

Napisati program koji će omogučiti:
Unos 2D niza od 10x10 elemanata vodeći računa da su svi elementi dvocifreni (ukoliko unos nekog elementa ne zadovoljava uslov, ponavljati unos tog elementa dok se ne zadovolji uslov); 
Koristiti funkciju unos
Izvršiti transpoziciju niza tako što će se zamjeniti redovi i kolone - Koristiti funkciju transpose, a zatim na osnovu izmijenjenog 2D niza:
Izračunati aritmetičku sredinu svih prostih brojeva ispod sporedne dijagonale - Koristiti dvije funkcije: aritmeticka i prost_broj (pozivati će se iz funkcije aritmeticka)
Napisati funkciju simpatican koja će provjeriti da li su brojevi iznad sporedne dijagonale simpatični*.
Obavezno koristiti navedene funkcije, a parametre i eventualne povratne vrijednosti definisati prema potrebi. 
U main() funkciji napisati testni program koji će omogućiti izvršenje svih funkcija navedenim redoslijedom.
```c++
[a][a][a][a][a]        [a][b][c][d][e]
[b][b][b][b][b]        [a][b][c][d][e]
[c][c][c][c][c]  --->  [a][b][c][d][e]
[d][d][d][d][d]        [a][b][c][d][e]
[e][e][e][e][e]        [a][b][c][d][e]
```
Pomoć: Broj je simpatičan ukoliko je zbir cifara njegovog kvadrata jednak kvadratu zbira njegovih cifara. Broj 21 je simpatičan jer je s(441) = s(21) * s(21) pri čemu je s(n) zbir cifara
prirodnog broja n.

## [**14 (Ispitni)**](14.cpp)

Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa student (student je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza.
```c++
struct student
{
    char *ID;
    char *imePrezime;
    float *prosjek;
};
```
Kompletan 2D niz predstavlja univerzitet. Redovi dvodimenzionalnog niza predstavljaju različite fakultete,a kolone studente (radi jednostavnosti rješenja podrazumijevati da svaki fakultet ima isti broj studenata). Omogućiti korisniku unos svih podataka za sve studente, te napraviti funkciju koja će pronaći fakultet sa najvećim prosjekom te ispisati koji je to redni broj fakulteta (index reda sa najvećim prosjekom). Zatim pronaći i ispisati ID studenta koji ima najveći prosjek na cijelom univerzitetu. 

**(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača. Obavezno voditi računa o dealociranju dinamički alocirane memorije.)**



### [**15** (**Ispitni**)](15.cpp)

Kreirati dvodimenzionalni dinamički niz čiji su elementi objekti  tipa fudbaler ( fudbaler je struktura čija su obilježja data u nastavku).

```c++
struct fudbaler{
int ID;
char*ime_i_Prezime;//prihvati samo slova N, O i V (napad, vezni i odbrana);
char* pozicija;
int *broj_golova;
};
```

Omogućiti korisniku da unese dimenzije niza te omogućiti unos elemenata. Redovi 2D niza  predstavljaju različite klubove, a kolone različite fudbalere (igrače). Radi jednostavnosti rješenja, predpostaviti da svaki klub ima isti broj fudbalera.Ovisno o unesenoj poziciji  (N,O ili V) identificira se da li je dati fudbaler napadač,odbrambeni ili vezni igrač. U različitim klubovima  mogu igrati različiti brojevi napadača, veznih igrača ili odbrambenih igrača.

**(Npr. klub 1 može imati 10 veznih, 3 napadača i 5 odbrambenih igrača, dok klub 2 može imati 12 veznih, 2 napadača  i 6 odbrambenih igrača i sl.)**

Izračunati i ispisati prosječan broj golova po poziciji igrača za sve klubove. Zatim omogućiti korisniku izbor jednog tipa fudbalera (N,O ili V) i prema korisničkom izboru  pronaći klub koji ima najbolji prosjek postignutih zgoditaka tog tipa igraca (npr. ako se unese slovo V za klub 1 računa se prosjek za 10 veznih igrača  dok se za klub 2 računa prosjek 12 veznih igrača i ti prosjeci se porede).

**(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača. Obavezno voditi računa o dealociranju dinamički alocirane memorije.)**

