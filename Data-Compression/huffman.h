#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include "defines.h"

using namespace std;

typedef struct nod
{
	int frequency;
	char symbol;
	struct nod *left, *right;
}*HuffNode,TreeNode;


HuffNode CreateLeafNode(int frequency,char symbol);
HuffNode CreateInternalNode(HuffNode Internal,HuffNode leftNode,HuffNode rightNode);
HuffNode GetNode();
void QInsert(HuffNode N);
void FillTree(HuffNode Root, char *Code, int codeLen);
void Huffman(const char *input);
void PrintCodes(FILE *f);
void HuffmanEncoding(const char *input, char *output);
void DecodingHuffman(const char *EncodedSequence, HuffNode t,FILE *f);
void DisplayTree(TreeNode *Root,int l,FILE *f);
void DisplayTreeLevels(TreeNode *Root,FILE *f);
void compressionRatio(char *input,char *output,FILE *f);

extern TreeNode Tree[MAX_NODES];
extern HuffNode Queue[MAX_NODES];
extern int TreeSize;
extern int QueueSize;

#endif
