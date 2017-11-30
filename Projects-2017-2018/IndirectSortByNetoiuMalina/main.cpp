#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "mergesort.h"
using namespace std;

int main()
{
    ifstream f("mergesort.txt");
    int arr[100], perm[100];
    int n, i;
    f>>n;

    for (i = 0; i < n; i++) {
        f>>arr[i];
        perm[i] = i;
    }
    
    cout<<endl<<"The index array (before Mergesort) is:"<<endl;
    output(arr, perm, n);
    
    *perm = index_array(arr, perm, n);
    
    cout<<endl<<"The index array (after Mergesort) is: "<<endl;
    output(arr, perm, n);
    is_valid(arr, perm, n)? cout<<"It is correct."<<endl: cout<<"It is not correct."<<endl;
    return 0;
}
