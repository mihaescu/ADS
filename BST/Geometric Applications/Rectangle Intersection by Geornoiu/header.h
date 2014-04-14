#include <iostream>
#include <queue>
#include <time.h>
#include <fstream>
#include "MinHeap.h"
using namespace std;


struct data
{
	int x,y,lenght, height, type;
};

struct NodArb
{
	data info;

	NodArb *left;
	NodArb *right;
};



void create();
NodArb *add(struct data temp, NodArb *root);
void compare(FILE *fp,struct data x,NodArb *tr);
NodArb *remove(struct data nr,NodArb **root); 
void SweepLine();
void BruteForce();

