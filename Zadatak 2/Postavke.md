## [**01 (Ispitni)**](01.cpp)

Napisati program koji simulira bacanje 3 kockice (jedna kockica ima 6 strana i na tim stranama su brojevi 1 - 6). Simuliranje bacanja svake kockice ostvariti funkcijom *rand() % 6 + 1*. Simulirati konstantno bacanje sve tri kockice dok se u dva uzastopna bacanja ne desi da se dobiju isti brojevi na sve tri kockice (<i>npr. u šestom bacanju se dobiju brojevi 2, 2, 2, a u sedmom 4, 4, 4 na sve tri kockice</i>). 

**Ispisati koliko je ukupno bilo bacanja dok se nije ispunio navedeni uslov.** 

**Nije potrebno tražiti bilo kakav unos od  korisnika.**

## [**02 (Ispitni)**](02.cpp)

Napisati program koji će omogućiti unos prirodnog broja A (A > 100000), te kreirati i ispisati broj B koji će se sastojati od cifara broja A u obrnutom redoslijedu gdje je svaka parna cifra uklonjena.

<i>Npr. ako se unese 45362792, funkcija treba vratiti 9735</i>Ispisati razliku brojava A i B

**(Obavezno koristiti bar jednu korisnički definisanu funkciju)**

## [**03 (Ispitni)**](03.cpp)

Napisati program koji omogućava unos pozitivnog broja n te pronalazi njegove parne cifre i formira novi broj u kojem su parne cifre zamijenjene cifrom '5'.

**Dodatno program treba ispisati razliku unesenog i broja koji se dobije nakon zamjene.**

## [**04 (Ispitni)**](04.cpp)
 Svaki paran broj se može prikazati kao suma dva prosta broja (tkz. Goldbachovo pravilo).
Napisati program koji će najprije učitati dva prirodna broja n1 i n2 (n2 > n1).

Zatim prikazati sve parne brojeve u intervalu od n1 do n2 kao sumu dva prosta broja.

**(U glavnom programu samo unijeti navedena dva prirodna broja i pozvati funkciju koja
obavlja zadani posao.)**

## [**05 (Ispitni)**](05.cpp)
 Napisati program koji omogućava korisniku unos prirodnog broja N (50 < N < 5000000). 
Zatim uneseni broj proslijediti funkciji kao parametar po referenci.
U funkciji je od unesenog broja potrebno kreirati novi broj teko što će se poredak cifri unesenog broja obrnuti.
Prilikom obrtanja potrebno je odbaciti neparne cifre.

**<i>Npr. Za uneseni broj 1234567 obrnuti broj bez neparnih cifara je 642.</i>**

## [**06 (Ispitni)**](06.cpp)
Napisati program koji će omogućiti korisniku unos broja n ( 10 <= n <= 1000).
Zatim simulirati n bacanja kockice (kockica ima 6 strana i na tim stranicama su brojevi 1-6).
Simuliranje bacanja svake kockice ostvariti funkcijom rand() % 6 + 1.
Izračunati statičke podatke u kojem procentu ukupnog bacanja se dobiva svaki od mogućih brojeva 1-6. Obavezno koristiti switch statement za zbrajanje rezultata bacanja kockice.

**Napomena: Po želji kreirati dodatne funkcije da se olakša rješavanje zadataka.**




## [**07 (Ispitni)**](07.cpp)

Napisati program koji će omogućiti korisniku unos broja n (uz uslov  10 <= n <= 1000). Zatim simulirati unos n slučajnih vrijednosti.  Simuliranje unosa ostvariti funkcijom rand() % 1000 + 1. Izračunati  statističke podatke u kojem procentu se od n generisanih slučajnih  vrijednosti pojavljuje prost broj.

<i>Npr. Ako je generisano 10 brojeva (n = 10):  5,7,4,13,17,20,25,23,30,45, u ovom uzorku od 10 brojeva postoji 5  prostih brojeva pa je procenat prostih brojeva u ovom slučaju 50%.</i>

**(Napomena: Po želji kreirati dodatne funkcije da se olakša rješavanje zadatka.)**

## [**08 (Ispitni)**](08.cpp)
Napisati program koji izračunava ukupan zbir faktorijela od svih prostih brojeva koji su članovi prvih 100 elemenata Fibonacci niza (tzv. fibonacci prime). 

Napomena: Pazljivo pročitajte zadatak.
Obavezno voditi računa da se uradi tačno ono što je trazeno u zadatku i da zadatak bude logicki ispravan. 
**Obavezno koristiti bar jednu funkciju kojoj ćete proslijediti parametar po referenci.**

## [**09 (Ispitni)**](09.cpp)
Napisati program koji korisniku omogućava unos realnog broja x, cijelog broja m i odabir funkcije za proračun datog izraza.
Korisnik bira funkciju unosom sljedećih karaktera 's' (sin), 'c' (cos), 'q' (sqrt), 'p' (pow). U slučaju da korisnik unese karakter koji ne odgovara niti jednoj od predefinisanih 
vrijednosti ispisati odgovarajuću poruku i ponoviti odabir.Za funkciju pow() drugi parametar treba biti 3.

Za odabranu funkciju izraz je:

![](https://i.postimg.cc/kgVgWn9b/Screenshot-1.png)

**Broj faktora u izrazu odgovara unesenom broju m. U rješenju obavezno iskoristiti switch iskaz.**

## [**10**](10.cpp)
Napisati program kojim će se izračunati 20 uzastopnih vrijednosti brzine i pređenog puta objekta u slobodnom padu u razmaku od po 3 sec.
Prilikom računanja potrebno je i ispisati na ekran uzastopno brzinu i pređeni put zajedno za svaki period od 3sec.
Obratiti pažnju da se koriste ispravni tipovi podataka. Formula za brzinu slobodnog pada je: v = g * t; g=9.81
Formula za pređeni put pri slobodnom padu je: s=(g/2)*pow(t,2)

Primjer izlaza:
```c++
Situacija u 3-oj sekundi je:
Brzina: 29.43
Predjeni put: 44.145
Situacija u 6-oj sekundi je:
Brzina: 58.86
Predjeni put: 176.58
Situacija u 9-oj sekundi je:
Brzina: 88.29
Predjeni put: 397.305
Situacija u 12-oj sekundi je:
Brzina: 117.72
Predjeni put: 706.32
```
## [**11**](11.cpp)
Napisati program koji rješava sljedeći problem.
Date su firma A, B i C sa godišnjim prihodima: A - prihod 10M eura B - prihod 7M eura C - prihod 5M eura
sa sljedećim stabilnim fiksnim godišnjim rastom prihoda za koji pretpostavljamo da se neće mijenjati A - 2.05% B - 2.80% C - 4.30% 
Potrebno je pronaći koja firma će prva prestići firmu A u godišnjem prihodu i za koliko godina će se to desit.

**Također potrebno je ispisati koliko će sve tri firme imati godišnji prihod u toj godini.**

## [**12**](12.cpp)
Napisati program koji će omogućiti korisniku unos dva minimalno trocifrena prirodna broja m i n (n > m, m > 100, n < 500). 
Zatim napraviti funkciju koja će vratiti aritmetičku sredinu svih srednjih cifara svih brojeva u rangu od m do n. 

**Također ta funkcija treba ispisati najveću srednju cifru navedenog ranga.**

## [**13**](13.cpp)
Napišite program u kojem ćete omogućiti unos dva prirodna broja manja od 500 koji predstavljaju granice intervala, te pronaći i ispisati kojom 
cifrom/znamenkom završava umnožak svih prostih brojeva u zadanom intervalu uključujući granične vrijednosti.

## [**14**](14.cpp)
Napišite program, u kojem ćete omogućiti unos dva prirodna broja manja od 500 koji predstavljaju granice intervala, te pronaći i ispisati kojom znamenkom završava najveći prosti broj u zadanom intervalu ne uključujući granične vrijednosti.

## [**15**](15.cpp)
Napisati program koji na osnovu unesenog cijelog broja N pronalazi i ispisuje srednju cifru ako broj N ima neparan broj cifara, odnosno aritmeticku sredinu (tip float) 
srednje dvije cifre ako broj N ima parni broj cifara, a zatim pronaci najmanji broj tipa int sa kojim se srednja cifra ili aritmeticka sredina srednjih cifri treba pomnoziti da bi se 
dobio broj koji je veci od inicijalnog zadanog broja.

Npr. za broj 75631 srednja cifra je 6, najmanja integer vrijednost sa kojom treba pomnoziti broj 6 da bi se dobio broj veci od 75631 je 12606 jer je 12606 * 6 = 75636, 75636 > 75631 ili za broj 984354 aritmeticka sredina srednje dvije cifre je 3.5, najmanja integer vrijednost sa kojom treba pomnoziti broj 3.5 da bi se dobio broj veci od 984354 je 281245 jer je 281245 * 3.5 = 984357.5, 984357.5 > 984354

**(Napomena: Potrebno je voditi računa o tipovima podataka.)**

## [**16**](16.cpp)
Poštujući sve faze procesa programiranja napraviti program koji pronalazi i ispisuje sve složene brojeve brojeve iz intervala m-n (10 < m < 100, 500 < n < 2000, m < n;
ukoliko unesene vrijednosti nisu ispravne, učitavanje treba ponavljati), te pronalazi i ispisuje njihovu aritmetičku sredinu. 
Napraviti sljedeće funkcije:

bool slozeni – koja će ispitivati da li je broj složeni 
ispis – koja koja će ispisivati sve složene brojeve i vratiti main funkciji njihovu aritmetičku sredinu.

U glavnom programu je potrebno ispisati aritmetičku sredinu.

**Složeni broj je svaki broj koji nije prosti, odnosno koji ima bar jednog djelioca osim broja 1 i samog sebe.**

## [**17**](17.cpp)

Napisati program koji će uzastopno učitavati cijele brojeve m i n (1 <= m <= 50, 1 <= n <= 500) i pronalaziti srednju cifru njihovog proizvoda/umnoška.
Program treba ispisivati srednju cifru samo ako je veća od prethodno izračunate srednje cifre. Prva pronađena srednja cifra se svakako ispisuje.
Program se forsirano prekida ako korisnik unese n = 0. 
Program se prirodno završava ako je pronađena srednja cifra 9.
Primjer izvršenja:
```c++
unesi m i n: 10, 15
srednja cifra/sredina proizvoda brojeva 10 i 15 (10 * 15 = 150) je: 5
unesi m i n: 10, 42
srednja cifra/sredina proizvoda brojeva 10 i 42 (10 * 42 = 420) je: ne ispisuje se
unesi m i n: 12, 31
srednja cifra/sredina proizvoda brojeva 12 i 31 (12 * 31 = 372) je: 7
unesi m i n: 149, 20
srednja cifra/sredina proizvoda brojeva 149 i 20 (149 * 20 = 2980) je: 8.5
unesi m i n: 150, 0
forsirani prekid...
```
## [**18 (Ispitni)**](18.cpp)
Napisati program koji će omogućiti korisniku unos broja n (uz uslov 10 <= n <= 1000). Zatim simulirati unos n slučajnih vrijednosti. Simuliranje unosa ostvariti funkcijom rand()% 1000 + 1. Izračunati statitičke podatke u kojem procentu se od n generisanih slučajnih vrijednosti pojavljuje savršen broj .
**Za neki broj se kaze da je savrsen ako je jednak sumi svih svojih djelilaca (ne uključujući njega samog)** .
Npr. 28 je savršen broj : njegovi djelioci su 1 , 2 , 4 , 7 i 14 , a 1 + 2 + 4 + 7 + 14 = 28
Jedini savršeni brojevi od 1 do 100 su brojevi 6 i 28
