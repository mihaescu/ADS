#include <iostream>

using namespace std;

class Element
{
    private :

        string word;
        int key;

    public :

        Element();
        Element(string word, int key);
        ~Element();

        void setWord(string word);
        void setKey(int key);

        string getWord();
        int getKey();
};
