#include "huffman.h"

TreeNode Tree[MAX_NODES];
HuffNode Queue[MAX_NODES];
int TreeSize=0;
int QueueSize=1;
char *HuffmanCodes[MAX_SYMBS];
char CodingBuffer[MAX_CODE_LEN];
FILE *fQueue=fopen("#Freq.out","w");

//Creating leaf-nodes containing symbols found in the input and their frequencies
HuffNode CreateLeafNode(int frequency,char symbol)
{
    TreeSize++;
    HuffNode Leaf = Tree + TreeSize;
    Leaf->frequency = frequency;
    Leaf->symbol = symbol;
    return Leaf;
}

//Creating internal nodes contaning no symbols but frenquencies of their children
HuffNode CreateInternalNode(HuffNode Internal,HuffNode leftNode, HuffNode rightNode)
{
    TreeSize++;
    Internal = Tree + TreeSize;
    Internal->left = leftNode;
    Internal->right = rightNode;
    Internal->frequency = leftNode->frequency + rightNode->frequency;
    return Internal;
}

/*      Inserting nodes in the priority queue
   Every time we insert a node into the queue we compare frequencies to keep
   lower frequency on higher priority position < low index >. */
void QInsert(HuffNode N)
{
	int i = QueueSize++;
	int j;
	while ((j=i/2))
	{
		if (Queue[j]->frequency <= N->frequency)
            		break;
		Switch(Queue[i],Queue[j]);
		Switch(i,j);
	}
	Queue[i]=N;
	if(Queue[i]->symbol)
        fprintf(fQueue,"\" %c \" occured %d time(s).\n",Queue[i]->symbol,Queue[i]->frequency);
}

/*      Getting nodes from the queue in order to create internal nodes.
   Keeping nodes sorted by frequency in order to have the low frequency
   nodes on higher priority. */
HuffNode GetNode()
{
	int i = QueueFirst ;
    int j;
	HuffNode N = Queue[QueueFirst];
	QueueSize--;
	while ((j=i*2) < QueueSize)
    	{
		if (j+1 < QueueSize && Queue[j+1]->frequency < Queue[j]->frequency)
                	j++;
		Switch(Queue[i],Queue[j]);
		Switch(i,j);
	}
	Queue[i]=Queue[QueueLast];
	return N;
}


/*      Walk down the tree until a symbol is found. According to it's position
    in the tree, a code was build. Every time a symbol is found it's code
    is copied into the HuffmanCodes array */
void FillTree(HuffNode Root,char *Code, int codeLen)
{
	static char *HuffCode = CodingBuffer ;
	if (Root->symbol)
	{
		Code[codeLen] = 0;
		strcpy(HuffCode,Code);
		HuffmanCodes[Root->symbol] = HuffCode;
		HuffCode += codeLen + 1;
		return;
	}
	Code[codeLen] = '0';
	FillTree(Root->left,Code,codeLen+1);  // Fill left branches with '0'
	Code[codeLen] = '1';
	FillTree(Root->right,Code,codeLen+1); // Fill right branches with '1'
}

/*      Main Function:
    Step 1: Count Frequencies of the symbols found in the input.
    Step 2: Create LeafNodes formed by symbols found and their frequencies.
    Step 3: Create Internal Nodes by geting 2 nodes from the queue every step
            until only the root is left in the queue. */
void Huffman(const char *input)
{
	int Frequency[MAX_SYMBS]={0};
	char Codes[MAX_CODE_LEN];

	while (*input)
        Frequency[(int)*input++]++;

    for (int i=0;i<MAX_SYMBS;i++)
        if (Frequency[i])
            QInsert(CreateLeafNode(Frequency[i],i));

	while (QueueSize>2)
    	{
	        HuffNode N;
	        N = (struct nod*)malloc(sizeof(struct nod));
	        N->frequency = 0;
	        N->symbol = 0;
		QInsert(CreateInternalNode(N,GetNode(),GetNode()));
    	}
    FillTree(TreeTop,Codes,0);
}

// For every symbol found we print it's computed code.
void PrintCodes(FILE *f)
{
    for (int i = 0; i < MAX_SYMBS; i++)
        if (HuffmanCodes[i])
            fprintf(f,"\" %c \" -> %s\n",i,HuffmanCodes[i]);
}

/*      While reading the input, we copy into the output the Huffman Code
    of each read symbol. */
void HuffmanEncoding(const char *input, char *output)
{
	while (*input)
    	{
		strcpy(output,HuffmanCodes[*input]);
		output+=strlen(HuffmanCodes[*input++]);
	}
}

/*      While reading the encoded sequence,for every bit read we walk down the tree.
    If '0' is read we walk to the left, if '1' is read we walk to the right.
    When a character is found in the tree,it is outputed and we start again
    from the root. */
void DecodingHuffman(const char *EncodedSequence, HuffNode Root,FILE *f)
{
	HuffNode TEMP = Root;
	while (*EncodedSequence)
    	{
		if (*EncodedSequence++ == '0')
            		TEMP = TEMP->left;
		else
        		 TEMP = TEMP->right;
		if (TEMP->symbol)
		{
	            fprintf(f,"%c",TEMP->symbol);
	            TEMP = Root;
		}
	}
	if (Root != TEMP)
        printf("Error!\n");
}

void DisplayTree(TreeNode *Root,int l,FILE *f)
{
    if(Root != NULL)
    {
        DisplayTree(Root->right,l+1,f);
        for(int i=0;i<=l;i++)
            fprintf(f,"\t\t");
        fprintf(f,"(%c)-[%d]\n",Root->symbol,Root->frequency);
            DisplayTree(Root->left,l+1,f);
    }
}

void DisplayTreeLevels(TreeNode *Root,FILE *f)
{
  fprintf(f,"\n\nTree Levels\n");
  if (!Root)
    return;
  queue<nod*> currentLevel,nextLevel;
  currentLevel.push(Root);
  while (!currentLevel.empty())
  {
    nod *currNode = currentLevel.front();
    currentLevel.pop();
    if (currNode)
    {
      fprintf(f,"(%c)-[%d]\t",currNode->symbol,currNode->frequency);
      nextLevel.push(currNode->left);
      nextLevel.push(currNode->right);
    }
    if (currentLevel.empty())
    {
      fprintf(f,"\n");
      swap(currentLevel, nextLevel);
    }
  }
}

void compressionRatio(char *input,char *output,FILE *f)
{
    int countIn,countOut;
    float CInput,COutput,Result;
    int inSize,outSize;
    for(countIn=0;input[countIn];countIn++) ;
    for(countOut=0;output[countOut];countOut++) ;
    inSize=countIn*8;
    outSize=countOut;
    CInput=inSize;
    COutput=outSize;
    fprintf(f,"Input:%d Characters ( %d bits )\nOutput:%d Characters ( %d bits)\n",countIn,inSize,countOut,outSize);
    Result=CInput/COutput;
    fprintf(f,"\nCompression Ratio: %.2f",Result);
}
