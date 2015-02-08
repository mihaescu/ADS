#pragma once
//#ifndef _DC_H_
//#define _DC_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>

using namespace std;

// Dictionaries
// LZW

typedef struct LZW
{
    string Symbol;
    int Code;
};

// RLE

typedef struct RLE
{
    string Symbol;
    int SeqLen;
};

// Huffman

typedef struct Huffman
{
    string Symbol;
    int Frequency;
    string Code;
};

// Huffman Tree

typedef struct HuffmanTree
{
	int Frequency;
	string Symbol;
	struct HuffmanTree *left, *right;
}*HNode,HTNode;

//Functions

    // LZW

    void FillDictionaryLZW(LZW *Dictionary, int Len);
    void PrintLZWDictionary(LZW *Dictionary,int Len);
    void AddToLZWDictionary(string S,LZW *Dictionary,int& Len);
    int FindL(string S,LZW *Dictionary,int Len);
    int GetLZWCode(string S,LZW *Dictionary,int Len);
    string GetSymbol(int Code,LZW *Dictionary,int Len);
    string LZWCompress(string Input,LZW *Dictionary,int Len);
    float LZWcompressionRatio(string Input,string Compressed);
    string MLZW(string Input);

    // RLE

    void AddToRLEDictionary(string S,int SeqLen,RLE *Dictionary,int& DictionarySize);
    void PrintRLEDictionary(RLE *Dictionary,int DictionarySize);
    string RLEDecompress(RLE *Dictionary,int DictionarySize);
    string RLECompress(string Input,RLE *Dictionary,int& DictionarySize);
    float RLECompressionRatio(string Input,string Compressed);
    string MRLE(string Input);

    // Huffman

    void AddToHuffmanDictionary(string S,int Frequency,Huffman *Dictionary,int& Len);
    int Find(string S,Huffman *Dictionary,int Len);
    void PlusPlusFrequency(string S,Huffman *Dictionary,int Len);
    void PutCode(string Code,string S,Huffman *Dictionary,int Len);
    string GetCode(string S,Huffman *Dictionary,int Len);
    void PrintHuffmanDictionary(Huffman *Dictionary,int DictionarySize);
    void CountFrequencies(string input,Huffman *Dictionary,int& DictionarySize);
    HNode NewLeafNode(string Symbol,int Freq,HTNode *Tree,int& TreeSize);
    HNode NewInternalNode(HNode Internal,HNode leftNode, HNode rightNode,HTNode *Tree,int& TreeSize);
    void QInsert(HNode N,HNode *Queue,int& QueueSize);
    HNode GetNode(HNode *Queue,int& QueueSize);
    void BuildTree(HTNode *Tree,Huffman *Dictionary,HNode *Queue,int& TreeSize,int& QueueSize,int DictionarySize);
    void EncodeTree(HNode TreeRoot,char *Code,int CodeLen,Huffman *Dictionary,int DictionarySize);
    string HuffmanCompress(string Input,Huffman *Dictionary,int DictionarySize);
    string DecodeText(string Encoded,HNode Root);
    void DisplayTreeLevels(HTNode *Root);
    float HuffmanCompressionRatio(string Input,string Compressed);
    string MHuffman(string Input);
//
//#endif


