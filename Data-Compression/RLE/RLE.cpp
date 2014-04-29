#include "RLE.h"

void AddToRLEDictionary(string S,int SeqLen,RLE *Dictionary,int& DictionarySize)
{
    DictionarySize = DictionarySize + 1;
    Dictionary[DictionarySize].Symbol = S;
    Dictionary[DictionarySize].SeqLen = SeqLen;
}

void PrintRLEDictionary(RLE *Dictionary,int DictionarySize)
{
    printf("Built RLE Dictionary:\n\n");
    printf("Symbol\t|\tSeq Len\n\n");
    for(int i=1;i<=DictionarySize;i++)
    {
        printf("%s\t|\t%d\n",Dictionary[i].Symbol.c_str(),Dictionary[i].SeqLen);
    }
    printf("\n\n");
}

string RLEDecompress(RLE *Dictionary,int DictionarySize)
{
    string Decompressed;
    string C;
    int Len;
    for(int i=1;i<=DictionarySize;i++)
    {
        C = Dictionary[i].Symbol;
        Len = Dictionary[i].SeqLen;
        for(int j=0;j<Len;j++)
        {
            Decompressed += C;
        }
    }
   return Decompressed;
}

string RLECompress(string Input,RLE *Dictionary,int& DictionarySize)
{
      stringstream Convertor;
      int SeqLen;
      string Compressed;
      string Current;
      string Len;
      for(int i=0 ; i < Input.length() ; i++)
      {
          Current = Input[i];
          SeqLen = 1;
          while (i+1 < Input.length() && Input[i] == Input[i+1])
          {
              SeqLen++;
              i++;
          }
          Convertor << SeqLen;
          Len = Convertor.str();
          Compressed = Compressed + Len;
          Compressed += Input[i];
          AddToRLEDictionary(Current,SeqLen,Dictionary,DictionarySize);
          Len.clear();
          Convertor.str("");
      }
	  return Compressed;
}

float RLECompressionRatio(string Input,string Compressed)
{
    int countIn,countOut;
    float CInput,COutput,Result;
    int inSize,outSize;

    countIn = Input.length();
    countOut = Compressed.length();

    inSize=countIn*8;

    for(int i=0 ; i<Compressed.length();i++)
    {
        if(Compressed[i] >= '0' && Compressed[i] <= '1')
            outSize += 1;
        if( Compressed[i]>= '2' && Compressed[i] <= '3')
            outSize += 2;
        if( Compressed[i] >= '4' && Compressed[i] <= '7')
            outSize += 3;
        if( Compressed[i] > '7' && Compressed[i] <= '9')
            outSize +=4;
        if(Compressed[i] > '9' && Compressed[i] <= '}')
            outSize +=8;
    }


    CInput=inSize;
    COutput=outSize;

    Result=CInput/COutput;
    return Result;
}
