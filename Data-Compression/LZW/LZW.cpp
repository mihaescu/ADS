#include "LZW.h"

void FillDictionaryLZW(LZW *Dictionary, int Len)
{
    for(int i=1;i<=Len;i++)
    {
        char c = i;
        Dictionary[i].Code = i;
        Dictionary[i].Symbol = c;
    }
}

void PrintLZWDictionary(LZW *Dictionary,int Len)
{
    for(int i=1;i<=Len;i++)
    {
        printf("%s = %d\n",Dictionary[i].Symbol.c_str(),Dictionary[i].Code);
    }
}

void AddToLZWDictionary(string S,LZW *Dictionary,int& Len)
{
    Len = Len + 1;
    Dictionary[Len].Code = Len;
    Dictionary[Len].Symbol = S;
}

int Find(string S,LZW *Dictionary,int Len)
{
    int ok;
    for(int i=1;i<=Len;i++)
    {
        if(S == Dictionary[i].Symbol)
           ok = 1;
    }
    if(ok == 1)
        return 1;
    else
        return 0;
}

int GetLZWCode(string S,LZW *Dictionary,int Len)
{
    int Code;
    for(int i=1;i<=Len;i++)
    {
        if( S == Dictionary[i].Symbol)
            Code = Dictionary[i].Code;
    }
    if(Code >= 0)
        return Code;
    else
        return -1;
}

string GetSymbol(int Code,LZW *Dictionary,int Len)
{
    int ok;
    string C;
    for(int i=1;i<=Len;i++)
    {
        if( Code == Dictionary[i].Code)
        {
            C = Dictionary[i].Symbol;
            ok = 1;
        }
    }
    if(ok == 1)
        return C;
    else
        return "Error";
}

string LZWCompress(string Input,LZW *Dictionary,int Len)
{
    stringstream Convertor;
    string w,wc;
    string c;
    string Compressed;
    string Code;
    int found;
    int LZWCode;
    int LZWCompressed[1024];
    int j=0;

    for(int i=0; i<Input.length(); i++)
    {
        c = Input[i];
        wc = w + c;
        found = Find(wc,Dictionary,Len);
        if(found == 1)
             w = wc;
        else
        {
             LZWCode = GetLZWCode(w,Dictionary,Len);
             LZWCompressed[j] = LZWCode;
             j++;
             AddToLZWDictionary(wc,Dictionary,Len);
             w = c;
             Convertor << LZWCode;
             Code = Convertor.str();
             Compressed +=  Code;
             Code.clear();
             Convertor.str("");
        }
    }
    return Compressed;
}

float LZWcompressionRatio(string Input,string Compressed)
{
    int countIn;
    float CInput,COutput,Result;
    int inSize,outSize = 0;

    countIn = Input.length();

    inSize=countIn*8;

    for(int i=0 ; i<Compressed.length();i++)
    {
        if(Compressed[i] >= '0' && Compressed[i] <= '1')
            outSize += 1;
        if( Compressed[i]>= '2' && Compressed[i] <= '3')
            outSize += 2;
        if( Compressed[i] >= '4' && Compressed[i] <= '7')
            outSize += 3;
        if( Compressed[i] > '7')
            outSize +=4;
    }

    CInput=inSize;
    COutput=outSize;

    Result=CInput/COutput;
    return Result;
}
