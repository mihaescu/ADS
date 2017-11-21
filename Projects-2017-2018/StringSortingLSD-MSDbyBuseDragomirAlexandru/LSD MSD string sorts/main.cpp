#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include "Element.h"
#include "LSD_MSD.h"

using namespace std;

int main()
{

    ///TEST FOR KEY INDEXED COUNTING SORT
    /*vector<Element> students;

    Element *student1 = new Element("Andreson", '2');
    Element *student2 = new Element("Brown", '3');
    Element *student3 = new Element("Davis", '3');
    Element *student4 = new Element("Garcia", '4');
    Element *student5 = new Element("Harris", '1');
    Element *student6 = new Element("Jackson", '3');
    Element *student7 = new Element("Johnson", '4');
    Element *student8 = new Element("Jones", '3');
    Element *student9 = new Element("Martin", '1');
    Element *student10 = new Element("Martinez", '2');
    Element *student11 = new Element("Miller", '2');
    Element *student12 = new Element("Moore", '1');
    Element *student13 = new Element("Robinson", '2');
    Element *student14 = new Element("Smith", '4');
    Element *student15 = new Element("Taylor", '3');
    Element *student16 = new Element("Thomas", '4');
    Element *student17 = new Element("Thompson", '4');
    Element *student18 = new Element("White", '2');
    Element *student19 = new Element("Williams", '3');
    Element *student20 = new Element("Wilson", '4');

    students.push_back(*student1);
    students.push_back(*student2);
    students.push_back(*student3);
    students.push_back(*student4);
    students.push_back(*student5);
    students.push_back(*student6);
    students.push_back(*student7);
    students.push_back(*student8);
    students.push_back(*student9);
    students.push_back(*student10);
    students.push_back(*student11);
    students.push_back(*student12);
    students.push_back(*student13);
    students.push_back(*student14);
    students.push_back(*student15);
    students.push_back(*student16);
    students.push_back(*student17);
    students.push_back(*student18);
    students.push_back(*student19);
    students.push_back(*student20);

    key_indexed_counting(students, 256);

    for(auto it = students.begin(); it != students.end(); it ++)
    {
        cout << it -> getWord() << " " << it -> getKey();
        cout << '\n';
    }

    return 0;*/


    ///TEST FOR LSD STRING SORT
    /*vector<Element> license_plates;

    Element *plate1 = new Element("4PGC938");
    Element *plate2 = new Element("2IYE230");
    Element *plate3 = new Element("3CIO720");
    Element *plate4 = new Element("1ICK750");
    Element *plate5 = new Element("1OHV845");
    Element *plate6 = new Element("4JZY524");
    Element *plate7 = new Element("1ICK750");
    Element *plate8 = new Element("3CIO720");
    Element *plate9 = new Element("1OHV845");
    Element *plate10 = new Element("1OHV845");
    Element *plate11 = new Element("2RLA629");
    Element *plate12 = new Element("2RLA629");
    Element *plate13 = new Element("3ATW723");

    license_plates.push_back(*plate1);
    license_plates.push_back(*plate2);
    license_plates.push_back(*plate3);
    license_plates.push_back(*plate4);
    license_plates.push_back(*plate5);
    license_plates.push_back(*plate6);
    license_plates.push_back(*plate7);
    license_plates.push_back(*plate8);
    license_plates.push_back(*plate9);
    license_plates.push_back(*plate10);
    license_plates.push_back(*plate11);
    license_plates.push_back(*plate12);
    license_plates.push_back(*plate13);

    LSD_sort(license_plates, 7, 256);

    for(auto it = license_plates.begin(); it != license_plates.end(); it ++)
    {
        cout << it -> getWord();
        cout << '\n';
    }*/

    return 0;
}
