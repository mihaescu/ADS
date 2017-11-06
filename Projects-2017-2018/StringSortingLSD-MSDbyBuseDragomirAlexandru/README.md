<dl>
  <dt>### String sorting LSD and MSD ###</dt></br></br>
<i>Radix sort este un algoritm de sortare care nu implică compararea de valori, ci acționează prin gruparea elementelor în funcție de chei. </i></br>

Mai jos adaug o implementare în pseudocod preluată de pe site-ul wikipedia pentru a face conceptul mai ușor de înțeles: </br></br>

![alt text](https://github.com/Islaya/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Pseudocode-Source-Wikipedia.png)

În cazul de față, proiectul va prezenta sortările numite LSD (Least Significant Digit) și MSD (Most Significant Digit).

Care ar fi procedeul: Se grupează valorile în funcție de o literă semnificativă (care ocupă aceeași poziție în toate cuvintele).

LSD operează de la coadă la începutul stringului       <------------------

MSD operează de la începutul stringului spre coada sa  ------------------>


![alt text](https://github.com/Islaya/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Exemplu%20prelucrat%20LSD-MSD%20(Taken%20and%20modified%20from%20Code%20Worm).png)


✍ **Rezumarea algoritmilor:**

**LEAST SIGNIFICANT DIGIT SORT**

**LSD.1** Se ia cea mai puțin semnificantă literă a tuturor stringurilor </br>
**LSD.2** Se grupează stringurile în funcție de valoarea acelei litere. În cazul în care două sau mai multe cuvinte au aceeași literă, se păstrează ordinea inițială a acestora (fapt ce face metoda una stabilă). </br>
**LSD.3** Se repetă procesul de sortare pentru litere din ce în ce mai semnificante până la obținerea ordonării


![alt_text](https://github.com/Islaya/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Algorithms-4th-edition-Robert-Sedgewick-and-Kevin-Wayne%20LSD.png)


<b>MOST SIGNIFICANT DIGIT SORT</b>
 
**MSD.1** Se ia cea mai semnificantă literă de la fiecare element </br>
**MSD.2** Se sortează lista de stringuri pe baza acelei litere. Elementele care prezintă aceeași literă se grupează separat. </br>
**MSD.3** Se sortează recursiv fiecare grup, plecându-se de la următoarea cea mai semnificantă literă. </br>
**MDS.4** Se concatenează la loc textul original (se pun laolaltă stringurile sortate)
</br>

![alt_text](https://github.com/Islaya/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Algorithms-4th-edition-Robert-Sedgewick-and-Kevin-Wayne%20MSD.png)

</br></br>
***_**Ce este o metodă de sortare stabilă?**_ </br>
###### Să luăm un exemplu (pentru a fi mai ușor de înțeles, le vom atașa cuvintelor niște chei aleatoare): </br>
###### Avem stringurile   ------>  carte(3) -> carmin(2) -> buchet(1) -> bancă(1) -> cravata(2) -> carte(5)</br>
###### Dacă facem sortarea neținând cont de chei, ci doar de valoarea stringurilor, avem 2 tipuri de algoritmi:

###### 1. Stabili </br>
###### ------>  carte(3) -> carte(5) -> carmin(2) -> cravată(2) -> bancă(1) -> buchet(1) </br>
###### Se observă cum cuvântul carte(3) rămâne înainte cuvântului carte(5), păstrându-se ordinea relativă


###### 2. Instabili </br>
###### ------>  carte(3) -> carte(5) -> carmin(2) -> cravată(2) -> bancă(1) -> buchet(1) </br>
######                                          SAU </br>
###### ------>  carte(5) -> carte(3) -> carmin(2) -> cravată(2) -> bancă(1) -> buchet(1) </br>
###### Se observă faptul că nu avem certitudinea păstrării ordinii relative.

###### Exemplu preluat de pe Stackexchange : </br></br>
![alt text](https://github.com/Islaya/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Stack_exchange%20example%20on%20Stable%20Sort.png)
