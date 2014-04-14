#include "huffman.h"

int main()
{
    FILE *InputFile=fopen("#InputText.in","r");
    FILE *EncodedFile=fopen("#Output.out","w");
    FILE *CodesFile=fopen("#Keys.out","w");
    FILE *TreeFile=fopen("#Tree.out","w");
    FILE *DecodedFile=fopen("#Decoded.out","w");
    FILE *CompressionFile=fopen("#CRatio.out","w");

	TEXT INPUT[MAX_LEN],OUTPUT[ENCODE_LEN];
	ReadFile(InputFile);
    Huffman(INPUT);
    PrintCodes(CodesFile);
    DisplayTree(&ROOT , LEVEL , TreeFile);                         // Display the Huffman Tree
    DisplayTreeLevels(&ROOT , TreeFile);                           // Display the Huffman Tree by Levels
    HuffmanEncoding(INPUT , OUTPUT);                            // Input -<Encoding>-> Encoded Sequence
    EncodeFile(EncodedFile);
    DecodingHuffman(OUTPUT , TreeTop , DecodedFile);           // Encoded Sequence -<Decoding>-> Decoded Sequence
    compressionRatio(INPUT , OUTPUT , CompressionFile);
	return 0;
}
