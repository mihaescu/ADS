/**
* @file LSD_MSD.h
* @brief This file will contain LSD and MSD sort declarations
*
* @author Bușe-Dragomir Alexandru
*
* @date 31/12/2017
*/


#include <vector>

using namespace std;

/**
* This is a predicate used in order to implement a STL sort on a vector<Element>
* @author Bușe-Dragomir Alexandru
* @param element1 The reference to the first Element object
* @param element2 The reference to the second Element object
* @date 31/12/2017
*/
bool compare(Element &element1, Element &element2);

/**
* This is a STL sort implemented on a vector<Element> ////  O(n*log(n))
* @author Bușe-Dragomir Alexandru
* @param my_array The reference to a vector<Element> (a vector of Element objects)
* @param alphabet_size The size of the alphabet we are working on
* @date 31/12/2017
*/
void stl_quick_sort(vector<Element> &my_vector, int alphabet_size = 256);

/**
* This is a selection sort implemented on a vector<Element> //// O(n^2)
* @author Bușe-Dragomir Alexandru
* @param my_array The reference to a vector<Element> (a vector of Element objects)
* @param alphabet_size The size of the alphabet we are working on
* @date 31/12/2017
*/
void selection_sort(vector<Element> &my_array, int alphabet_size = 256);
/**
* This is a selection sort implemented on a vector<Element> //// O(n^2)
* @author Bușe-Dragomir Alexandru
* @param my_array The reference to a vector<Element> (a vector of Element objects)
* @param alphabet_size The size of the alphabet we are working on
* @date 31/12/2017
*/
void selection_sort(vector<Element> &my_array, int low, int high, int position = 0, int alphabet_size = 256);

/**
* This is a key indexed counting sort implemented on a vector<Element> //// O(n + k), where k = alphabet_size
* @author Bușe-Dragomir Alexandru
* @param my_array The reference to a vector<Element> (a vector of Element objects)
* @param alphabet_size The size of the alphabet we are working on
* @date 31/12/2017
*/
void key_indexed_counting(vector<Element> &my_array, int alphabet_size = 256);

/**
* This is a least significant digit sort implemented on a vector<Element> //// O(n * k), where k = alphabet_size
* @author Bușe-Dragomir Alexandru
* @param my_array The reference to a vector<Element> (a vector of Element objects)
* @param alphabet_size The size of the alphabet we are working on
* @date 31/12/2017
*/
void LSD_sort(vector<Element> &my_array, int alphabet_size = 256);
/**
* This is a most significant digit sort implemented on a vector<Element> //// between O(n) and O(n * k), where k = alphabet_size
* @author Bușe-Dragomir Alexandru
* @param my_array The reference to a vector<Element> (a vector of Element objects)
* @param low This is the position in the vector of strings from which we sort
* @param high This is the position in the vector of strings up to which we sort (inclusive)
* @param position This is the position of the character from which we start our sort (0 is the first char, 1 is the second etc.)
* @param alphabet_size The size of the alphabet we are working on
* @date 31/12/2017
*/
void MSD_sort(vector<Element> &my_array, int low, int high, int position = 0, int alphabet_size = 256);
