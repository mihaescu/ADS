/**
* @file main.cpp
* @brief This file will contain the main block of the program
*
* @author Bușe-Dragomir Alexandru
*
* @date 31/12/2017
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <fstream>
#include "Element.h"
#include "LSD_MSD.h"

using namespace std;

ifstream LSD_in("LSD input.in");
ifstream MSD_in("MSD input.in");

ofstream LSD_out("LSD output.out");
ofstream MSD_out("MSD output.out");

int main()
{
    vector <Element> LSD_vector;
    vector <Element> MSD_vector;

    Element element1;
    Element element2;

    string word1;
    string word2;

    LSD_in >> word1;
    element1.setWord(word1);
    LSD_vector.push_back(element1);

    while(LSD_in >> word1)
    {
        element1.setWord(word1);
        LSD_vector.push_back(element1);
    }

    MSD_in >> word2;
    element2.setWord(word2);
    MSD_vector.push_back(element2);

    while(MSD_in >> word2)
    {
        element2.setWord(word2);
        MSD_vector.push_back(element2);
    }

    LSD_sort(LSD_vector, 256);

    for(int index = 0; index < LSD_vector.size(); index ++)
    {
        LSD_out << LSD_vector[index].getWord();
        LSD_out << '\n';
    }

    MSD_sort(MSD_vector, 0, 99, 0, 256);

    for(int index = 0; index < MSD_vector.size(); index ++)
    {
        MSD_out << MSD_vector[index].getWord();
        MSD_out << '\n';
    }

    return 0;
}










