#include <iostream>
#include <string>
#include "header.h"

using namespace std;

int main()
{
    int selection;

    cout << "Press 1 if you want to generate fixed length strings";
    cout << '\n';
    cout << "Press 2 if you want to generate variable length strings";
    cout << '\n';
    cout << "-> ";
    cin >> selection;
    cout << '\n';

    if(selection == 1)
    {
        int size_of_string;
        int number_of_strings;

        cout << "Insert the length of a string : ";
        cin >> size_of_string;
        cout << "Insert the number of strings you would like to generate : ";
        cin >> number_of_strings;
        cout << '\n';

        same_length_strings(size_of_string, number_of_strings);
    }

    if(selection == 2)
    {
        int max_length;
        int number_of_strings;

        cout << "Insert the maximum length of a string : ";
        cin >> max_length;
        cout << "Insert the number of strings you would like to generate : ";
        cin >> number_of_strings;
        cout << '\n';

        different_length_strings(max_length, number_of_strings);
    }

    return 0;
}

