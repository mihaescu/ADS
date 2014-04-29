#ifndef RLE_H
#define RLE_H
#include "Includes.h"

using namespace std;

typedef struct
{
    string Symbol;
    int SeqLen;
}RLE;

void AddToRLEDictionary(string S,int SeqLen,RLE *Dictionary,int& DictionarySize);
void PrintRLEDictionary(RLE *Dictionary,int DictionarySize);
string RLEDecompress(RLE *Dictionary,int DictionarySize);
string RLECompress(string Input,RLE *Dictionary,int& DictionarySize);
float RLECompressionRatio(string Input,string Compressed);

#endif
