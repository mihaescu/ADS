#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "Includes.h"

typedef struct nod
{
	int Frequency;
	string Symbol;
	struct nod *left, *right;
}*HuffNode,TreeNode;

typedef struct
{
    string Symbol;
    int Frequency;
    string Code;
}Huff;

void AddToHuffmanDictionary(string S,int Frequency,Huff *Dictionary,int& Len);
int Find(string S,Huff *Dictionary,int Len);
void PlusPlusFrequency(string S,Huff *Dictionary,int Len);
void PutCode(string Code,string S,Huff *Dictionary,int Len);
string GetCode(string S,Huff *Dictionary,int Len);
void PrintHuffmanDictionary(Huff *Dictionary,int DictionarySize);
void CountFrequencies(string input,Huff *Dictionary,int& DictionarySize);
HuffNode NewLeafNode(string Symbol,int Freq,TreeNode *Tree,int& TreeSize);
HuffNode NewInternalNode(HuffNode Internal,HuffNode leftNode, HuffNode rightNode,TreeNode *Tree,int& TreeSize);
void QInsert(HuffNode N,HuffNode *Queue,int& QueueSize);
HuffNode GetNode(HuffNode *Queue,int& QueueSize);
void BuildTree(TreeNode *Tree,Huff *Dictionary,HuffNode *Queue,int& TreeSize,int& QueueSize,int DictionarySize);
void EncodeTree(HuffNode TreeRoot,char *Code,int CodeLen,Huff *Dictionary,int DictionarySize);
string HuffmanCompress(string Input,Huff *Dictionary,int DictionarySize);
string DecodeText(string Encoded,HuffNode Root);
void DisplayTreeLevels(TreeNode *Root);
float HuffmanCompressionRatio(string Input,string Compressed);

#endif
