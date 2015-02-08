#include "DataCompression.h"

/* **********************************************************************************************************************************************************************************************************************
LZW                                                                                                                                                                                                                     */

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

int FindL(string S,LZW *Dictionary,int Len)
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
        found = FindL(wc,Dictionary,Len);
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

string MLZW(string Input)
{
    stringstream Convertor;
    LZW LZWDictionary[1024];
    int LZWDictionarySize = 128;
    float LZWCRatio;
    string LZWCompressed;
    string CRatio;
    string Output;

    FillDictionaryLZW(LZWDictionary,LZWDictionarySize);
    LZWCompressed = LZWCompress(Input,LZWDictionary,LZWDictionarySize);
    LZWCRatio = LZWcompressionRatio(Input,LZWCompressed);

    Convertor << LZWCRatio;
    CRatio = Convertor.str();

    Output = "Encoded Text:\n" + LZWCompressed + "\nCompression Ratio: " + CRatio;
    return Output;
}

/* *********************************************************************************************************************************************************************************************************************
RLE                                                                                                                                                                                                                    */

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

string MRLE(string Input)
{
    stringstream Convertor;
    string CRatio;
    string Output;
    RLE RLEDictionary[1024];
    int RLEDictionarySize = 0;
    string RLECompressed;
    float RLECratio;

    RLECompressed = RLECompress(Input,RLEDictionary,RLEDictionarySize);
    RLECratio = RLECompressionRatio(Input,RLECompressed);

    Convertor << RLECratio;
    CRatio = Convertor.str();

    Output = "Encoded Text:\n" + RLECompressed + "\nCompression Ratio: " + CRatio;
    return Output;
}

/* *********************************************************************************************************************************************************************************************
  Huffman                                                                                                                                                                                      */

void AddToHuffmanDictionary(string S,int Frequency,Huffman *Dictionary,int& Len)
{
    Len = Len + 1;
    Dictionary[Len].Frequency = Frequency;
    Dictionary[Len].Symbol = S;
}

int Find(string S,Huffman *Dictionary,int Len)
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

void PlusPlusFrequency(string S,Huffman *Dictionary,int Len)
{
    for(int i=1;i<=Len;i++)
    {
        if(S == Dictionary[i].Symbol)
           Dictionary[i].Frequency += 1;
    }
}

void PutCode(string Code,string S,Huffman *Dictionary,int Len)
{
    for(int i=1;i<=Len;i++)
    {
        if(S == Dictionary[i].Symbol)
        {
            Dictionary[i].Code = Code;
        }
    }
}

string GetCode(string S,Huffman *Dictionary,int Len)
{
    for(int i=1;i<=Len;i++)
    {
        if(S == Dictionary[i].Symbol)
            return Dictionary[i].Code;
    }
}

void PrintHuffmanDictionary(Huffman *Dictionary,int DictionarySize)
{
    printf("Symbol\t\tFrequency\t\tCode\n\n");
    for(int i=1;i<=DictionarySize;i++)
    {
        printf("%s\t|\t%d\t\t|\t%s\n",Dictionary[i].Symbol.c_str(),Dictionary[i].Frequency,Dictionary[i].Code.c_str());
    }
    printf("\n\n");
}

void CountFrequencies(string input,Huffman *Dictionary,int& DictionarySize)
{
    string Current;
    int Found;
    for(int i=0 ; i<input.length() ; i++)
    {
        Current = input[i];
        Found = Find(Current,Dictionary,DictionarySize);
        if(Found == 1)
            PlusPlusFrequency(Current,Dictionary,DictionarySize);
        else
            AddToHuffmanDictionary(Current,1,Dictionary,DictionarySize);
    }
}

HNode NewLeafNode(string Symbol,int Freq,HTNode *Tree,int& TreeSize)
{
    HNode Leaf = Tree + TreeSize++;
    Leaf->Frequency = Freq;
    Leaf->Symbol = Symbol;
    return Leaf;
}

HNode NewInternalNode(HNode Internal,HNode leftNode, HNode rightNode,HTNode *Tree,int& TreeSize)
{
    Internal = Tree + TreeSize++;
    Internal->left = leftNode;
    Internal->right = rightNode;
    Internal->Frequency = leftNode->Frequency + rightNode->Frequency;
    return Internal;
}
void QInsert(HNode N,HNode *Queue,int& QueueSize)
{
	int LowPI = QueueSize++;
	int HighPI;
	while ((HighPI = LowPI / 2))
	{
		if (Queue[HighPI]->Frequency < N->Frequency)
            break;
		Queue[LowPI] = Queue[HighPI];
		LowPI = HighPI;
	}
	Queue[LowPI]=N;
}

HNode GetNode(HNode *Queue,int& QueueSize)
{
	int HighPI = 1 ;
    int LowPI;
	HNode N = Queue[1];
	QueueSize--;
	while ((LowPI = HighPI*2) < QueueSize)
    {
		if (LowPI + 1 < QueueSize && Queue[LowPI+1]->Frequency < Queue[LowPI]->Frequency)
                LowPI++;
		Queue[HighPI] = Queue[LowPI];
		HighPI = LowPI;
	}
	Queue[HighPI]=Queue[QueueSize];
	return N;
}

void BuildTree(HTNode *Tree,Huffman *Dictionary,HNode *Queue,int& TreeSize,int& QueueSize,int DictionarySize)
{
    string Current;
    int CurrentFreq;
    for(int i=1;i<=DictionarySize;i++)
    {
        Current = Dictionary[i].Symbol;
        CurrentFreq = Dictionary[i].Frequency;
        QInsert(NewLeafNode(Current,CurrentFreq,Tree,TreeSize),Queue,QueueSize);
    }
    while(QueueSize > 2)
    {
        HNode N;
        N = (struct HuffmanTree*)malloc(sizeof(struct HuffmanTree));
        N->Frequency = 0;
        QInsert(NewInternalNode(N,GetNode(Queue,QueueSize),GetNode(Queue,QueueSize),Tree,TreeSize),Queue,QueueSize);
    }
}

void EncodeTree(HNode TreeRoot,char *Code,int CodeLen,Huffman *Dictionary,int DictionarySize)
{
    string HuffCode;
	if (!TreeRoot->Symbol.empty())
	{
		Code[CodeLen] = 0;
		HuffCode = Code;
		PutCode(HuffCode,TreeRoot->Symbol,Dictionary,DictionarySize);
		HuffCode.clear();
		return;
	}
	Code[CodeLen] = '0';
	EncodeTree(TreeRoot->left,Code,CodeLen+1,Dictionary,DictionarySize);
	Code[CodeLen] = '1';
	EncodeTree(TreeRoot->right,Code,CodeLen+1,Dictionary,DictionarySize);
}

string HuffmanCompress(string Input,Huffman *Dictionary,int DictionarySize)
{
    string Current;
    string Code;
    string Encoded;
    for(int i=0;i<Input.length();i++)
    {
        Current = Input[i];
        Code = GetCode(Current,Dictionary,DictionarySize);
        Encoded += Code;
    }
    return Encoded;
}

string DecodeText(string Encoded,HNode Root)
{
    string Decoded;
    HNode Temp = Root;
    for(int i=0;i<Encoded.length();i++)
    {
        if ( Encoded[i] == '0')
            Temp = Temp->left;
        else
            Temp = Temp->right;
        if (!Temp->Symbol.empty())
		{
            Decoded += Temp->Symbol;
            Temp = Root;
		}
    }
    return Decoded;
}
void DisplayTreeLevels(HTNode *Root)
{
    printf("\n\nTree Levels\n");
    if (!Root)
        return;
    queue<HuffmanTree*> ThisLevel,NextLevel;
    ThisLevel.push(Root);
    while (!ThisLevel.empty())
    {
        HTNode *Node = ThisLevel.front();
        ThisLevel.pop();
        if (Node)
        {
              printf("(%s)-[%d]\t",Node->Symbol.c_str(),Node->Frequency);
              NextLevel.push(Node->left);
              NextLevel.push(Node->right);
        }
        if (ThisLevel.empty())
        {
              printf("\n");
              swap(ThisLevel, NextLevel);
        }
    }
}

float HuffmanCompressionRatio(string Input,string Compressed)
{
    int countIn,countOut;
    float CInput,COutput,Result;
    int inSize,outSize;

    countIn = Input.length();
    countOut = Compressed.length();

    inSize=countIn*8;
    outSize=countOut;

    CInput=inSize;
    COutput=outSize;

    Result=CInput/COutput;
    return Result;
}

string MHuffman(string Input)
{
    stringstream Convertor;
    string CRatio;
    string Output;

    HTNode Tree[256];
    HNode Queue[256];
    Huffman HuffmanDictionary[128];

    int HuffmanTreeSize=0;
    int HuffmanQueueSize=1;
    int HuffmanDictionarySize = 0;

    char HuffCode[32];

    string HuffmanCompressed;
    float HuffmanCRatio;

    CountFrequencies(Input,HuffmanDictionary,HuffmanDictionarySize);
    BuildTree(Tree,HuffmanDictionary,Queue,HuffmanTreeSize,HuffmanQueueSize,HuffmanDictionarySize);
    EncodeTree(Queue[1],HuffCode,0,HuffmanDictionary,HuffmanDictionarySize);

    HuffmanCompressed = HuffmanCompress(Input,HuffmanDictionary,HuffmanDictionarySize);
    HuffmanCRatio = HuffmanCompressionRatio(Input,HuffmanCompressed);

    Convertor << HuffmanCRatio;
    CRatio = Convertor.str();

    Output = "Encoded Text:\n" + HuffmanCompressed + "\nCompression Ratio: " + CRatio;

    return Output;
}
