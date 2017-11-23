#include <iostream>
#include <ctime>
#include <cstdlib>
#include "mergesort.h"
using namespace std;

int main()
{
    srand(time(NULL));
    int arr[100], perm[100];
    int n, i;
    n = rand_number(10, 30);

    cout<<"The array is: "<<endl;
    for (i = 0; i < n; i++) {
        arr[i] = rand_number(-200, 200);
        cout<<i<<": "<<arr[i]<<endl;
        perm[i] = i;
    }

    *perm = index_array(arr, perm, n);
    cout<<"The index array is: "<<endl;
    for (i = 0; i < n; i++){
        cout<<perm[i]<<" ";
    }

    return 0;
}
