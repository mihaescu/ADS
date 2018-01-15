#include "mergesort.h"

int main()
{
    int arr[n], perm[n];
    create_file("mergesort.in");
    ifstream f("mergesort.in");

    for (int i = 0; i < n; i++){
            f >> arr[i];
            perm[i] = i;
        }

    f.close();
    // Before merge sort
    output("before.out", arr, perm, n);
    *perm = index_array(arr, perm, n);
    // After merge sort
    output("after.out", arr, perm, n);
    is_valid(arr, perm, n)? cout<<"It is correct."<<endl: cout<<"It is incorrect."<<endl;
    return 0;
}
