#include <string>
#include "Element.h"

using namespace std;

Element :: Element()
{
    this -> word = "";
    this -> key = 0;
}

Element :: Element(string word)
{
    this -> word = word;
    this -> key = '?';
}

Element :: Element(string word, char key = '!')
{
    this -> word = word;
    this -> key = key;
}

Element :: ~Element()
{
    ///cout << "Destructor";
}

void Element :: setWord(string word)
{
    this -> word = word;
}

void Element :: setKey(char key)
{
    this -> key = key;
}

string Element :: getWord()
{
    return this -> word;
}

char Element :: getKey()
{
    return this -> key;
}
