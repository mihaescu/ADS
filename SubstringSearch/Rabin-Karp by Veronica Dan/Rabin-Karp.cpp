#include"Rabin-Karp.h"
#include "substringSearchCore.h"

/*
Method that computes the modular hashing for a Text structure's test array

txt -  Text structure on whose text array the hash function will be executed
patternLenght - the lenght of the pattern that will be searched for
q - large prime number representing the hypothetical hash table size

return - the hash value
*/
long modularHashing(struct Text &txt, int patternLenght, int q){
	long h = 0;
	for (int i = 0; i < patternLenght; i ++){
		h = (txt.radix * h + txt.text[i]) % q;
	}
	return h;
}

/*
Method that executed the rabin-Karp algorithm

pattern - the Text structure that contains the pattern that will be searched for
txt - the Text structure in which the pattern will be searched for
q - large prime number representing the hypothetical hash table size

return - 0, if not found,
	   - the index, if found
*/

int RabinKarp(struct Text &pattern, struct Text &txt, int q){
	
	txt.hash = modularHashing(txt, pattern.lenght, q);	
	pattern.hash = modularHashing(pattern,pattern.lenght, q);
	int RM = 1;
	
	for (int i = 1; i <= pattern.lenght - 1; i ++)
		RM = (txt.radix * RM) % q;
	
	if(pattern.hash == txt.hash)
		return 0;
	
	for(int i = pattern.lenght; i < txt.lenght; i ++){
		
		txt.hash = (txt.hash + q - RM * txt.text[i-pattern.lenght] % q) % q;
		txt.hash = (txt.hash * txt.radix + txt.text[i]) % q;
		
		if(pattern.hash == txt.hash){
			return i - pattern.lenght + 1;	
		}
	}
}