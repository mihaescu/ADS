#ifndef LZW_H
#define LZW_H
#include "Includes.h"

typedef struct
{
    string Symbol;
    int Code;
}LZW;

void FillDictionaryLZW(LZW *Dictionary, int Len);
void PrintLZWDictionary(LZW *Dictionary,int Len);
void AddToLZWDictionary(string S,LZW *Dictionary,int& Len);
int Find(string S,LZW *Dictionary,int Len);
int GetLZWCode(string S,LZW *Dictionary,int Len);
string GetSymbol(int Code,LZW *Dictionary,int Len);
string LZWCompress(string Input,LZW *Dictionary,int Len);
float LZWcompressionRatio(string Input,string Compressed);

#endif
