/**
* @file Element.h
* @brief This file will contain the Element class declaration
*
* @author Bușe-Dragomir Alexandru
*
* @date 31/12/2017
*/


using namespace std;

class Element
{
    private :

        string word;
        char key;

    public :

        Element();
        Element(string word);
        Element(string word, char key);
        ~Element();

        void setWord(string word);
        void setKey(char key);

        string getWord();
        char getKey();
        int getCharIndexAt(int position);
};
