#include <vector>

using namespace std;

bool compare(Element &element1, Element &element2);

void stl_quick_sort(vector<Element> &my_vector, int alphabet_size = 256);

void selection_sort(vector<Element> &my_array, int alphabet_size = 256);
void selection_sort(vector<Element> &my_array, int low, int high, int position = 0, int alphabet_size = 256);

void key_indexed_counting(vector<Element> &my_array, int alphabet_size = 256);

void LSD_sort(vector<Element> &my_array, int alphabet_size = 256);
void MSD_sort(vector<Element> &my_array, int low, int high, int position = 0, int alphabet_size = 256);
