#include "Huffman.h"

void AddToHuffmanDictionary(string S,int Frequency,Huff *Dictionary,int& Len)
{
    Len = Len + 1;
    Dictionary[Len].Frequency = Frequency;
    Dictionary[Len].Symbol = S;
}

int Find(string S,Huff *Dictionary,int Len)
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

void PlusPlusFrequency(string S,Huff *Dictionary,int Len)
{
    for(int i=1;i<=Len;i++)
    {
        if(S == Dictionary[i].Symbol)
           Dictionary[i].Frequency += 1;
    }
}

void PutCode(string Code,string S,Huff *Dictionary,int Len)
{
    for(int i=1;i<=Len;i++)
    {
        if(S == Dictionary[i].Symbol)
        {
            Dictionary[i].Code = Code;
        }
    }
}

string GetCode(string S,Huff *Dictionary,int Len)
{
    for(int i=1;i<=Len;i++)
    {
        if(S == Dictionary[i].Symbol)
            return Dictionary[i].Code;
    }
}

void PrintHuffmanDictionary(Huff *Dictionary,int DictionarySize)
{
    printf("Symbol\t\tFrequency\t\tCode\n\n");
    for(int i=1;i<=DictionarySize;i++)
    {
        printf("%s\t|\t%d\t\t|\t%s\n",Dictionary[i].Symbol.c_str(),Dictionary[i].Frequency,Dictionary[i].Code.c_str());
    }
    printf("\n\n");
}

void CountFrequencies(string input,Huff *Dictionary,int& DictionarySize)
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

HuffNode NewLeafNode(string Symbol,int Freq,TreeNode *Tree,int& TreeSize)
{
    HuffNode Leaf = Tree + TreeSize++;
    Leaf->Frequency = Freq;
    Leaf->Symbol = Symbol;
    return Leaf;
}

HuffNode NewInternalNode(HuffNode Internal,HuffNode leftNode, HuffNode rightNode,TreeNode *Tree,int& TreeSize)
{
    Internal = Tree + TreeSize++;
    Internal->left = leftNode;
    Internal->right = rightNode;
    Internal->Frequency = leftNode->Frequency + rightNode->Frequency;
    return Internal;
}
void QInsert(HuffNode N,HuffNode *Queue,int& QueueSize)
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

HuffNode GetNode(HuffNode *Queue,int& QueueSize)
{
	int HighPI = QueueFirst ;
    int LowPI;
	HuffNode N = Queue[QueueFirst];
	QueueSize--;
	while ((LowPI = HighPI*2) < QueueSize)
    {
		if (LowPI + 1 < QueueSize && Queue[LowPI+1]->Frequency < Queue[LowPI]->Frequency)
                LowPI++;
		Queue[HighPI] = Queue[LowPI];
		HighPI = LowPI;
	}
	Queue[HighPI]=Queue[QueueLast];
	return N;
}

void BuildTree(TreeNode *Tree,Huff *Dictionary,HuffNode *Queue,int& TreeSize,int& QueueSize,int DictionarySize)
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
        HuffNode N;
        N = (struct nod*)malloc(sizeof(struct nod));
        N->Frequency = 0;
        QInsert(NewInternalNode(N,GetNode(Queue,QueueSize),GetNode(Queue,QueueSize),Tree,TreeSize),Queue,QueueSize);
    }
}

void EncodeTree(HuffNode TreeRoot,char *Code,int CodeLen,Huff *Dictionary,int DictionarySize)
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

string HuffmanCompress(string Input,Huff *Dictionary,int DictionarySize)
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

string DecodeText(string Encoded,HuffNode Root)
{
    string Decoded;
    HuffNode Temp = Root;
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
void DisplayTreeLevels(TreeNode *Root)
{
    printf("\n\nTree Levels\n");
    if (!Root)
        return;
    queue<nod*> ThisLevel,NextLevel;
    ThisLevel.push(Root);
    while (!ThisLevel.empty())
    {
        TreeNode *Node = ThisLevel.front();
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
