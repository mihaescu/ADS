#include "Huffman.h"
#include "RLE.h"
#include "LZW.h"

using namespace std;

int main()
{
    ifstream InputFile;
    ofstream EncodedFile,CRatioFile;

    InputFile.open("#Input.txt");
    EncodedFile.open("#EncodedInput.txt");
    CRatioFile.open("#CompressionRatio.txt");

    // Huffman
    TreeNode Tree[MAX_NODES];
    HuffNode Queue[MAX_NODES];
    Huff HuffmanDictionary[MAX_SYMBS];
    int HuffmanTreeSize=0,HuffmanQueueSize=1,HuffmanDictionarySize = 0;
    char HuffCode[MAX_CODE_LEN];

    // LZW
    LZW LZWDictionary[MAX_LEN];
    int LZWDictionarySize = 128;

    // RLE
    RLE RLEDictionary[MAX_LEN];
    int RLEDictionarySize = 0;

    string Input,HuffmanCompressed,RLECompressed,LZWCompressed;
    
    InputFile >> Input;

    float HuffmanCRatio,LZWCRatio,RLECratio;

    // Huffman Coding
    CountFrequencies(Input,HuffmanDictionary,HuffmanDictionarySize);
    BuildTree(Tree,HuffmanDictionary,Queue,HuffmanTreeSize,HuffmanQueueSize,HuffmanDictionarySize);
    EncodeTree(TreeTop,HuffCode,0,HuffmanDictionary,HuffmanDictionarySize);

    // LZW  Dictionary Initialising
    FillDictionaryLZW(LZWDictionary,LZWDictionarySize);
    
    HuffmanCompressed = HuffmanCompress(Input,HuffmanDictionary,HuffmanDictionarySize);
    RLECompressed = RLECompress(Input,RLEDictionary,RLEDictionarySize);
    LZWCompressed = LZWCompress(Input,LZWDictionary,LZWDictionarySize);


    EncodedFile << "Huffman Encoded Text: \n" << HuffmanCompressed << "\n\n";
    EncodedFile << "RLE Encoded Text: \n" << RLECompressed << "\n\n";
    EncodedFile << "LZW Encoded Text: \n" << LZWCompressed;

    HuffmanCRatio = HuffmanCompressionRatio(Input,HuffmanCompressed);
    LZWCRatio = LZWcompressionRatio(Input,LZWCompressed);
    RLECratio = RLECompressionRatio(Input,RLECompressed);

    CRatioFile << "Huffman Compresion Ratio: \n" << HuffmanCRatio << "\n\n";
    CRatioFile << "RLE Compression Ratio: \n" << RLECratio << "\n\n";
    CRatioFile << "LZW Compression Ratio: \n" << LZWCRatio ;
    
    return 0;
}
