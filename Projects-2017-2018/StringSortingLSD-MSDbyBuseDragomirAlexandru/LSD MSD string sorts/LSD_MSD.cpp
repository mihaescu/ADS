#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include "Element.h"
#include "LSD_MSD.h"

void key_indexed_counting(vector<Element> &my_array, int alphabet_size)
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

    Element *auxiliary_array = new Element[my_array.size()];

    int dimension = my_array.size();

    for(unsigned int index = 0; index < my_array.size(); index ++)
    {
        string current_word = my_array[index].getWord();
        int current_key = my_array[index].getKey();
        int current_position = counter[current_key];

        auxiliary_array[current_position].setWord(current_word);
        auxiliary_array[current_position].setKey(current_key);

        counter[current_key] ++;
    }

    for(int i = 0; i < dimension; i ++)
    {
        my_array[i].setKey(auxiliary_array[i].getKey());
        my_array[i].setWord(auxiliary_array[i].getWord());
    }

    delete[] auxiliary_array;
}
