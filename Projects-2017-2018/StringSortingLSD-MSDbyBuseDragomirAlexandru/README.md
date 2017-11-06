<dl>
  <dt>String sorting LSD and MSD</dt></br></br>
<i>Radix sort este un algoritm de sortare care nu implică compararea de valori, ci acționează prin gruparea elementelor în funcție de chei. </i></br>

Mai jos adaug o implementare în pseudocod preluată de pe site-ul wikipedia pentru a face conceptul mai ușor de înțeles: </br></br>
![alt text](https://github.com/Islaya/LSD-and-MSD-Radix-Sorts-on-Strings/blob/master/Pseudocode-Source-Wikipedia.png)

În cazul de față, proiectul va prezenta sortările numite LSD (Least Significant Digit) și MSD (Most Significant Digit).

Care ar fi procedeul: Se grupează valorile în funcție de o literă semnificativă (care ocupă aceeași poziție în toate cuvintele).

LSD operează de la coadă la începutul stringului       <------------------

MSD operează de la începutul stringului spre coada sa  ------------------>

✍ <b>Rezumarea algoritmilor:<b>

<b>LEAST SIGNIFICANT DIGIT SORT</b>

<b>LSD.1</b> Se ia cea mai puțin semnificantă literă a tuturor stringurilor </br>
<b>LSD.2</b> Se grupează stringurile în funcție de valoarea acelei litere. În cazul în care două sau mai multe cuvinte au aceeași <b>literă, se păstrează ordinea inițială a acestora (fapt ce face metoda una stabilă). </br>
<b>LSD.3</b> Se repetă procesul de sortare pentru litere din ce în ce mai semnificante până la obținerea ordonării


<b>MOST SIGNIFICANT DIGIT SORT</b>
 
<b>MSD.1</b> Se ia cea mai semnificantă literă de la fiecare element </br>
<b>MSD.2</b> Se sortează lista de stringuri pe baza acelei litere. Elementele care prezintă aceeași literă se grupează separat. </br>
<b>MSD.3</b> Se sortează recursiv fiecare grup, plecându-se de la următoarea cea mai semnificantă literă. </br>
<b>MDS.4</b> Se concatenează la loc textul original (se pun laolaltă stringurile sortate)

</b>
<i>Ce este o metodă de sortare stabilă?</i> </br>
Să luăm un exemplu (pentru a fi mai ușor de înțeles, le vom atașa cuvintelor niște chei aleatoare): </br>
</br>
Avem stringurile   ------>  carte(3) -> carmin(2) -> buchet(1) -> bancă(1) -> cravata(2) -> carte(5)</br>
</br>
Dacă facem sortarea neținând cont de chei, ci doar de valoarea stringurilor avem 2 tipuri de algoritmi:

1. Stabili </br>
------>  carte(3) -> carte(5) -> carmin(2) -> cravată(2) -> bancă(1) -> buchet(1) </br>
Se observă cum cuvântul carte(3) rămâne înainte cuvântului carte(5), păstrându-se ordinea relativă


2. Instabili </br>
------>  carte(3) -> carte(5) -> carmin(2) -> cravată(2) -> bancă(1) -> buchet(1) </br>
				  SAU </br>
------>  carte(5) -> carte(3) -> carmin(2) -> cravată(2) -> bancă(1) -> buchet(1) </br>
Se observă faptul că nu avem certitudinea păstrării ordinii relative.
