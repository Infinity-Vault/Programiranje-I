## [**01 (Ispitni)**](01.cpp)

Poštujući sve faze programiranja, napisati program koji korisniku omogućava unos realnog broja x i odabir funkcije za proračun datog izraza. KOrisnik bira funkciju unosom jednog od sljedećih karaktera: 's'(sin), 'c'(cos). U slučaju da korisnik unese karakter koji ne odgovara niti jednog od predefinisanih vrijednosti ispisati odgovarajuću poruku i ponoviti odabir.

Za odabranu funkciju sin izraz je:

![](https://i.postimg.cc/V65nFr3p/Screenshot-1.png)

## [**02**](02.cpp)

Napisati program koji korisniku omogućava unos cijelog broja N, te izračunava geometrijsku sredinu svih neparnih brojeva u intervalu [1, N] koji nisu djeljivi sa brojem 5. Rezultat trebi biti zaokružen na dvije decimale.

Geometrijska sredina n brojeva se računa po formuli:

![](https://i.postimg.cc/SKnVLsCj/Screenshot-1.png)

## [**03 (Ispitni)**](03.cpp)

Napisati program u kojem je potrebno unijeti odabrani broj cifara počevši od cifre najveće težinske vrijednosti, pa od njih sastaviti i napisati prirodni broj. Unos cifara se prekida kada se unese broj manji od 0, ukoliko korisnik unese cifru veću od 9, ispisati poruku da cifra nije validna, ali se unos ne prekida. 

**(Obavezno koristiti barem jednu korisnički definisanu funkciju)**

Ispis neka bude oblika:

```
Upisi cifru: 2

Upisi cifru: 8

Upisi cifru: 72

Cifra nije validna

Upisi cifru: -1

Broj sastavljen od zadanih cifara je 28.
```

## [**04**](04.cpp)
 a) Omogućiti korisniku unos prirodnog broja i nakon toga napraviti funkciju koja će prebrojati koliko taj broj ima cifara

b) Za taj broj pronaći i ispisati prvu, srednju i zadnju cifu (koristiti zasebne funkcije)

c) Obrnuti cifre tom broju (npr. ako je broj bio 12345 treba biti 54321) 

## [**05 (Ispitni)**](05.cpp)
Napisati program koji će omogućiti unos prirodnog broja A (A > 100000), 
te kreirati i ispisati broj B koji će se sastojati od cifara broja A u obrnutom redoslijedu u kojem je svaka parna uklonjena. 
(npr. ako se unese 45362792 funkcija će vratiti 9735). Ispisati razliku brojeva A i B. 

**(Obavezno koristiti bar jednu korisnički definiranu funkciju.)**

## [**06 (Ispitni)**](06.cpp)

Poštujući sve faze procesa programiranja, napisati program koji korisniku omogućava unos cijelog broja N, 
te izračunava vrijednost sume faktorijela neparnih brojeva u intervalu [1, N]. Suma faktorijela prikazana je
sljedećom formulom: S = 1! + 3! + 5! + ... + N!

## [**07**](07.cpp)

Napišite program, poštujući sve faze procesa programiranja, koji će  ispisati sve troznamenkaste brojeve koji su jednaki sumi faktorijela  svojih znamenki.

**ABC = A! + B! + C!**


## [**08 (Ispitni)**](08.cpp)
Omogučiti unos dva broja X i Y iz intervala od 10 do 5000.
Kreirati program koji će pronaći i ispisati sve brojeve od X do Y (uključujući granične vrijednosti) za koje važi da je obrnuti broj djeljiv sa
njegovom sumom cifara.
Za olakšanje rješenja zadataka napraviri funkcije za obrtanje poretka cifara i za sumu cifara.
Npr. Za broj 144 vrijedi da mu je suma cifara 9 i da je broj koji se dobije nakon što se njegove cifre obrnu 441, djeljiv sa 9.

**Definišite vrijednosti intervala [X, Y]: 11 150**
**Brojevi koji ispunjuju dati uslov: 18 20 21 24 27**

## [**09**](09.cpp)

Poštujući sve faze programiranja napisati program koji omogućava unos prirodnog broja n preko tastature te izračunava sumu:

![](https://i.postimg.cc/G20gPRGC/Screenshot-2.png)

## [**10**](10.cpp)
Poštujući sve faze procesa programiranja, napišite program, koji za uneseni prirodni broj n i realni broj x izračunava:

![](https://i.postimg.cc/zfP8qVsk/Screenshot-1.png)

## [**11 (Ispitni)**](11.cpp)

Napisati program koji korisniku omogućava unos realnog broja x, cijelog broja m i odabir funkcije za proračun datog izraza.
Korisnik bira funkciju unosom sljedećih karaktera 's' (sin), 'c' (cos), 'q' (sqrt), 'p' (pow). 
U slučaju da korisnik unese karakter koji ne odgovara niti jednoj od predefinisanih vrijednosti ispisati odgovarajuću poruku i ponoviti odabir. 
Funkciji pow postavite broj 2 za drugi parametar.

Za odabranu funkciju izraz je:

![](https://i.postimg.cc/6qsmbfGK/Screenshot-2.png)

**Broj faktora u izrazu odgovara unesenom broju m.** 
**U rješenju obavezno iskoristiti switch iskaz.**

## [**12**](12.cpp)
Napisati program koji korisniku omogućava unos cijelog broja n, te izračunava: 

**S = [1/(n + 1)] - [2/((n - 1) + 2!)] + [3/((n - 2) + 3!)] - [4/((n - 3) + 4!)] + ... + (-1)^(n - 1) * [n/(1 + n!)]**

## [**13**](13.cpp)
Napisati program koji omogućava unos realnog broja x, cijelog broja m (m > 0) i odabir funkcije za proračun datog izraza.
Korisnik bira funkciju unosom jednog od sljedećih karaktera: 's' (sabiranje), 'o' (oduzimanje), 'm' (množenje), 'd' (dijeljenje). 
U slučaju da korisnik unese karakter koji ne odgovara niti jednoj od predefinisanih vrijednosti ispisati odgovarajuću poruku i ponoviti odabir.

Za odabir funkcije s izraz je:
**f(x, m) = (x - 1) * 1 + (x - 2) * 2 + ... + (x - m) * m**

Za odabir funkcije o izraz je: 
**f(x, m) = (x - 1) * 1 - (x - 2) * 2 - ... - (x - m) * m itd.**

**Broj faktora u izrazu odgovara unesenom broju m.**
**U rješenju obavezno iskoristiti switch iskaz.**

## [**14**](14.cpp)

Postujuci sve faze procesa programiranja napisati program koji ce pronaci i ispisati  sve brojeve  od X do Y ( ukljucujuci granicne vrijednosti) koji su djeljivi svim svojim ciframa. 

**Na primjer, broj 36 je djeljiv svim svojim ciframa (36/6=6 i 36/3=12).**

Brojeve X i Y unosi korisnik  i oni moraju biti u opsegu od 10 do 6000.

**Obavezno koristiti bar jednu  funkciju.**