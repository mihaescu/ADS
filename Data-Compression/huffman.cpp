#include "huffman.h"

TreeNode Tree[MAX_NODES];
HuffNode Queue[MAX_NODES];
int TreeSize=0;
int QueueSize=1;
char *HuffmanCodes[MAX_SYMBS];
char Buffer[ENCODE_LEN];
FILE *fQueue=fopen("#Freq.out","w");


HuffNode CreateLeafNode(int frequency,char symbol)			// Creating leaf-nodes containing symbols found in the input and their frequencies
{
    TreeSize++;
    HuffNode Leaf = Tree + TreeSize;
    Leaf->frequency = frequency;
    Leaf->symbol = symbol;
    return Leaf;
}

HuffNode CreateInternalNode(HuffNode Internal,HuffNode leftNode, HuffNode rightNode)		// Creating internal nodes contaning no symbols but frenquencies of their children
{
    TreeSize++;
    Internal = Tree + TreeSize;
    Internal->left = leftNode;
    Internal->right = rightNode;
    Internal->frequency = leftNode->frequency + rightNode->frequency;
    return Internal;
}

void QInsert(HuffNode N)
{
	int i = QueueSize++;
	int j;
	while ((j=i/2))
	{
		if (Queue[j]->frequency <= N->frequency)		// Check for frequencies in order to establish priority
            break;										// Keeping higher freqs on low priority ( higher index ) ; Q[i] <- the new node	< on lower priority >
		Switch(Queue[i],Queue[j]);						// Else, Q[j] is set on low priority
		Switch(i,j);									// J is the new index ( higher priority) ; Q[i] <- new node < on higher priority >
	}
	Queue[i]=N;
	if(Queue[i]->symbol)
        fprintf(fQueue,"\" %c \" occured %d time(s).\n",Queue[i]->symbol,Queue[i]->frequency);
}

HuffNode GetNode()
{
	int i = QueueFirst ;
    int j;
	HuffNode N = Queue[QueueFirst];      // Getting the first node in the queue
	if (QueueSize < 2)
        return 0;
	QueueSize--;					// Lowering the higher limit of the queue
	while ((j=i*2) < QueueSize)
    {
		if (j+1 < QueueSize && Queue[j+1]->frequency < Queue[j]->frequency)		// If there are more than 3 node left in the Queue and the node on lower priority < higher index >
                j++;															//   has a lower frequency than the one on higher priority we walk forward into the queue and get the node with
		Switch(Queue[i],Queue[j]);                                              //   lower frequency. Q[i] <- this node.
		Switch(i,j);
	}
	Queue[i]=Queue[QueueLast];													// The place where the low-frequency node was found is filled with the lowest-priority node in the Queue
	return N;
}

void FillTree(HuffNode Root, char *Code, int codeLen)
{
	static char *out = Buffer ;
	if (Root->symbol)
	{
		Code[codeLen]=0;
		strcpy(out,Code);
		HuffmanCodes[Root->symbol]=out;
		out += codeLen + 1;
		return;
	}
	Code[codeLen] = '0';
	FillTree(Root->left,Code,codeLen+1);  // Fill left branches with '0'
	Code[codeLen] = '1';
	FillTree(Root->right,Code,codeLen+1); // Fill right branches with '1'
}

void Huffman(const char *input)
{
	int Frequency[MAX_SYMBS]={0};
	char Codes[MAX_CODE_LEN];

	while (*input)
        Frequency[(int)*input++]++;    // Counting frequencies of character found in file.

    for (int i=0;i<MAX_SYMBS;i++)
        if (Frequency[i])
            QInsert(CreateLeafNode(Frequency[i],i));  // Creating leaf-nodes containing the characters found in file and their frequency.

	while (QueueSize>2)
    {
        HuffNode N;
        N = (struct nod*)malloc(sizeof(struct nod));
        N->frequency = 0;
        N->symbol = 0;
		QInsert(CreateInternalNode(N,GetNode(),GetNode()));   // Creating internal nodes
    }
    FillTree(TreeTop,Codes,0);
}

void PrintCodes(FILE *f)
{
    for (int i = 0; i < MAX_SYMBS; i++)
        if (HuffmanCodes[i])
            fprintf(f,"\" %c \" -> %s\n",i,HuffmanCodes[i]);
}

void HuffmanEncoding(const char *input, char *output)
{
	while (*input)									// While reading the input
    {
		strcpy(output,HuffmanCodes[*input]);			// Copy the Huffman Code of the encountered character from the input into the output
		output+=strlen(HuffmanCodes[*input++]);
	}
}

void DecodingHuffman(const char *EncodedSequence, HuffNode Root,FILE *f)
{
	HuffNode TEMP = Root;
	while (*EncodedSequence)				        // While reading the encoded sequence
    {
		if (*EncodedSequence++ == '0')    	        // If '0' is encountered we walk the left path
            TEMP = TEMP->left;
		else
            TEMP = TEMP->right;  					// If '1' is encountered we walk the right path
		if (TEMP->symbol)
		{
            fprintf(f,"%c",TEMP->symbol);		    // Until a symbol is found and it is written into the file
            TEMP = Root;						    // We start again from the top
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
