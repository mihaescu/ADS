#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

ofstream file1("same_length_strings.out");
ofstream file2("different_length_strings.out");

void same_length_strings(int size_of_strings, int number_of_strings)
{
    string alpha = "abcdefghijklmnopqrstuwxyzABCDEFGHIJKLMNOPQRSTUWXYZ1234567890";
    int alpha_length = alpha.length();

    srand(time(NULL));

    for(int i = 0; i < number_of_strings; i ++)
    {
        string word = "";

        for(int j = 0; j < size_of_strings; j ++)
        {
            char letter = alpha[rand() % alpha_length];
            word = word + letter;
        }

        file1 << word;
        file1 << '\n';
    }

    file1.close();
}

void different_length_strings(int max_length, int number_of_strings)
{
    string alpha = "abcdefghijklmnopqrstuwxyzABCDEFGHIJKLMNOPQRSTUWXYZ1234567890";
    int alpha_length = alpha.length();

    srand(time(NULL));

    for(int i = 0; i < number_of_strings; i ++)
    {
        string word = "";
        int random_index = rand() % max_length + 1;

        for(int j = 0; j < random_index; j ++)
        {
            char letter = alpha[rand() % alpha_length];
            word = word + letter;
        }

        file2 << word;
        file2 << '\n';
    }

    file2.close();
}



