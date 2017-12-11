#include "mergesort.h"

int main() {
    int arr[100], perm[100];
    create_file("mergesort.in");
    ifstream f("mergesort.in");

    for (int i = 0; i < n; i++){
            f >> arr[i];
            perm[i] = i;
        }

    f.close();
    cout<<endl<<"Before Mergesort:"<<endl;
    output(arr, perm, n);
    
    *perm = index_array(arr, perm, n);
    
    cout<<endl<<"After Mergesort: "<<endl;
    output(arr, perm, n);
    is_valid(arr, perm, n)? cout<<"It is correct."<<endl: cout<<"It is incorrect."<<endl;
    
    return 0;
}
