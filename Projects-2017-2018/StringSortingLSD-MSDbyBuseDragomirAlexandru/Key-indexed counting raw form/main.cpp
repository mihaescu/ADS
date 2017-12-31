#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

///each element must have a value and a key
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

Element :: Element()
{
    this -> word = "";
    this -> key = 0;
}

Element :: Element(string word, int key)
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

void Element :: setKey(int key)
{
    this -> key = key;
}

string Element :: getWord()
{
    return this -> word;
}

int Element :: getKey()
{
    return this -> key;
}

///will sort words by their key value
void key_indexed_counting(vector<Element> my_array, int alphabet_size)
{
    int counter[alphabet_size + 1] = {0};

    for(auto it = my_array.begin(); it != my_array.end(); it ++)
    {
        counter[it -> getKey() + 1] ++;
    }

    for(int i = 0; i < alphabet_size; i ++)
    {
        counter[i + 1] = counter[i] + counter[i + 1];
    }

    Element *auxiliary_array;
    auxiliary_array = new Element[my_array.size()];

    for(unsigned int index = 0; index < my_array.size(); index ++)
    {
        string current_word = my_array[index].getWord();
        int current_key = my_array[index].getKey();
        int current_position = counter[current_key];

        auxiliary_array[current_position].setWord(current_word);
        auxiliary_array[current_position].setKey(current_key);

        counter[current_key] ++;
    }

    int dimension = my_array.size();

    for(int i = 0; i < dimension; i ++)
    {
        my_array[i].setKey(auxiliary_array[i].getKey());
        my_array[i].setWord(auxiliary_array[i].getWord());
    }

    for(int i = 0; i < dimension; i ++)
    {
        cout << my_array[i].getWord() << " " << my_array[i].getKey();
        cout << '\n';
    }
}

int main()
{
    vector<Element> students;

    Element *student1 = new Element("Alexandru", 3);
    Element *student2 = new Element("Andrei", 2);
    Element *student3 = new Element("Bogdan", 2);
    Element *student4 = new Element("Irina", 1);
    Element *student5 = new Element("Dima", 3);
    Element *student6 = new Element("Elena", 1);
    Element *student7 = new Element("Mircea", 3);
    Element *student8 = new Element("Victor", 0);

    students.push_back(*student1);
    students.push_back(*student2);
    students.push_back(*student3);
    students.push_back(*student4);
    students.push_back(*student5);
    students.push_back(*student6);
    students.push_back(*student7);
    students.push_back(*student8);

    key_indexed_counting(students, 4);

    return 0;
}










