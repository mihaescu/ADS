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
