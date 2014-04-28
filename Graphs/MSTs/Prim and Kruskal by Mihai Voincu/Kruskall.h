#ifndef _KRUSK_H_
#define _KRUSK_H_

#include <stdio.h>
#include <iostream>

//trebuie din core!
struct muchie{

	int x, y, c;		//x,y are vertexes, c = the weight

};	

//trebuie din core
void readData(int &n, int &m, muchie u[20]);

void kruskal(int &n, int &m, int L[20], muchie u[20]);

#endif
