///I do not own some of the images below; they were used in educational purposes///
![alt text](https://github.com/AIexandru/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Logo%20proiect.png)

<i>Radix sort este un algoritm de sortare care nu implică compararea de valori, ci acționează prin gruparea elementelor în funcție de chei. </i></br>

Mai jos adaug pașii schematici și implementarea funcției key indexed counting sort, fundamentul celor două metode de sortare (LSD și MSD) : </br></br>

![alt text](https://github.com/AIexandru/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Counting%20sort%201.png)

![alt text](https://github.com/AIexandru/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Counting%20sort%202.png)

![alt text](https://github.com/AIexandru/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Counting%20sort%203.png)

![alt text](https://github.com/AIexandru/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Counting%20sort%204.png)

![alt text](https://github.com/AIexandru/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Key%20indexed%20counting%20code.png)

În cazul de față, proiectul va prezenta sortările numite LSD (Least Significant Digit) și MSD (Most Significant Digit).

Care ar fi procedeul: Se grupează valorile în funcție de o literă semnificativă (care ocupă aceeași poziție în toate cuvintele).

LSD operează de la coadă la începutul stringului       <------------------

MSD operează de la începutul stringului spre coada sa  ------------------>


![alt text](https://github.com/AIexandru/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Exemplu%20prelucrat%20LSD-MSD%20(Taken%20and%20modified%20from%20Code%20Worm).png)


✍ **Rezumarea algoritmilor:**

**LEAST SIGNIFICANT DIGIT SORT**

**LSD.1** Se ia cea mai puțin semnificantă literă a tuturor stringurilor </br>
**LSD.2** Se grupează stringurile în funcție de valoarea acelei litere. În cazul în care două sau mai multe cuvinte au aceeași literă, se păstrează ordinea inițială a acestora (fapt ce face metoda una stabilă). </br>
**LSD.3** Se repetă procesul de sortare pentru litere din ce în ce mai semnificante până la obținerea ordonării


![alt_text](https://github.com/AIexandru/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Algorithms-4th-edition-Robert-Sedgewick-and-Kevin-Wayne%20LSD.png)


<b>MOST SIGNIFICANT DIGIT SORT</b>
 
**MSD.1** Se ia cea mai semnificantă literă de la fiecare element </br>
**MSD.2** Se sortează lista de stringuri pe baza acelei litere. Elementele care prezintă aceeași literă se grupează separat. </br>
**MSD.3** Se sortează recursiv fiecare grup, plecându-se de la următoarea cea mai semnificantă literă. </br>
**MDS.4** Se concatenează la loc textul original (se pun laolaltă stringurile sortate)
</br>

![alt_text](https://github.com/AIexandru/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Algorithms-4th-edition-Robert-Sedgewick-and-Kevin-Wayne%20MSD.png)

</br></br>
***_**Ce este o metodă de sortare stabilă?**_ </br>
###### Să luăm un exemplu (pentru a fi mai ușor de înțeles, le vom atașa cuvintelor niște chei aleatoare): </br>
###### Avem stringurile   ------>  carte(3) -> cavaler(2) -> excavator(1) -> dans(1) -> cravata(2) -> carte(5)</br>
###### Dacă facem sortarea neținând cont de chei, ci doar de valoarea stringurilor, avem 2 tipuri de algoritmi:

###### 1. Stabili </br>
###### ------>  carte(3) -> carte(5) -> cavaler(2) -> cravată(2) -> dans(1) -> excavator(1) </br>
###### Se observă cum cuvântul carte(3) rămâne înainte cuvântului carte(5), păstrându-se ordinea relativă


###### 2. Instabili </br>
###### ------>  carte(3) -> carte(5) -> cavaler(2) -> cravată(2) -> dans(1) -> excavator(1) </br>
######                                          SAU </br>
###### ------>  carte(5) -> carte(3) -> cavaler(2) -> cravată(2) -> dans(1) -> excavator(1) </br>
###### Se observă faptul că nu avem certitudinea păstrării ordinii relative.

###### Exemplu preluat de pe Stackexchange : </br></br>
![alt text](https://github.com/AIexandru/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Stack_exchange%20example%20on%20Stable%20Sort.png)

###### Exemplu preluat din cartea Algorithms 4th edition privind complexitatea mai multor algoritmi, inclusiv LSD, MSD : </br></br>
![alt text](https://github.com/AIexandru/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Complexity%20comparison.png)

###### Un grafic ce ne indică eficiența metodei de sortare radix sort ca timp de execuție:
![alt text](https://github.com/AIexandru/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/RadixSortComplexity.jpg)

###### În încheiere voi prezenta alte câteva informații comparative legate de algoritmii de sortare (Algorithms 4th edition) : </br>
![alt text](https://github.com/AIexandru/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Algorithm%20complexity.png)
