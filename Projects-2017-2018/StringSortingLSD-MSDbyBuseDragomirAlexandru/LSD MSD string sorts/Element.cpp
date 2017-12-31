/**
* @file Element.cpp
* @brief This file will contain the Element class implementation
*
* @author Bușe-Dragomir Alexandru
*
* @date 31/12/2017
*/


#include <string>
#include "Element.h"

using namespace std;

/**
* This is the class default constructor (initialises the word)
* @author Bușe-Dragomir Alexandru
* @date 31/12/2017
*/
Element :: Element()
{
    this -> word = "";
    this -> key = 0;
}

/**
* This is the second class constructor (initialises the key)
* @author Bușe-Dragomir Alexandru
* @param word The string member of the class
* @date 31/12/2017
*/
Element :: Element(string word)
{
    this -> word = word;
    this -> key = '-';
}

/**
* This is the third class constructor (initialises the word and the key)
* @author Bușe-Dragomir Alexandru
* @param word The string member of the class
* @param key The char member of the class
* @date 31/12/2017
*/
Element :: Element(string word, char key = '!')
{
    this -> word = word;
    this -> key = key;
}

/**
* This is the class destructor (destroys an Element object)
* @author Bușe-Dragomir Alexandru
* @date 31/12/2017
*/
Element :: ~Element()
{
    ///cout << "Destructor";
}

/**
* This is the first setter of the class (sets the word)
* @author Bușe-Dragomir Alexandru
* @param word The string member of the class
* @date 31/12/2017
*/
void Element :: setWord(string word)
{
    this -> word = word;
}

/**
* This is the second setter of the class (sets the key)
* @author Bușe-Dragomir Alexandru
* @param key The char member of the class
* @date 31/12/2017
*/
void Element :: setKey(char key)
{
    this -> key = key;
}

/**
* This is the first getter of the class (gets the word)
* @author Bușe-Dragomir Alexandru
* @date 31/12/2017
*/
string Element :: getWord()
{
    return this -> word;
}

/**
* This is the second getter of the class (gets the key)
* @author Bușe-Dragomir Alexandru
* @date 31/12/2017
*/
char Element :: getKey()
{
    return this -> key;
}

/**
* This is a method that returns word[position] or -1 if there is no char
* @author Bușe-Dragomir Alexandru
* @param position This is the position in which we search for a char (in the word)
* @date 31/12/2017
*/
int Element :: getCharIndexAt(int position)
{
    string my_word = this -> word;

    if(position < int(my_word.length()))
    {
        return (this -> word)[position];
    }

    if(position == int(my_word.length()))
    {
        return -1;
    }
}

