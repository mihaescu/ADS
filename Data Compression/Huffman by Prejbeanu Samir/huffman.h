#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nod
{
	int frecventa;
	char litera;
	struct nod *left, *right;
}*node;



node nodNou(int frecventa, char litera, node leftNode, node rightNode);
void queueInsert(node n);
node queueRemove();
void codeBuild(node n, char *codBiti, int lungimeCod);
void buildHuffman(const char *s);
void codare(const char *input, char *output);
void decodare(const char *codHuffman, node t);

extern struct nod noduri[256];
extern node queue[256];
extern int numarNoduri;
extern int queueEnd;
extern char *huffCode[128];
extern char buff[1024];

#endif
