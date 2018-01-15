#include <algorithm>
#include "mergesort.h"

void create_file(string filename){ //Generate input file.
        srand(time(0));
        ofstream file(filename);
        int val;

        for (int i = 0; i < n; i++){
                val = rand_number(-1000, 1000);
                file << val << "\n";
        }
        file.close();
}

void merges(int arr[n], int perm[n], int left, int mid, int right){
    int temp[n], i, j, k;

    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right) {
        if (arr[perm[i]] <= arr[perm[j]]) {
            temp[k++] = perm[i++];
        } else {
            temp[k++] = perm[j++];
        }
    }
    // The values at indexes perm[i] and perm[j] are compared.
    // The index of the smaller value is stored in temp.

    while (i <= mid) {
        temp[k++] = perm[i++];
    }
    while(j <= right) {
        temp[k++] = perm[j++];
    }

    for (i = left; i <= right; i++) {
        perm[i] = temp[i];
    }
}

void mergesort(int arr[n], int perm[n], int left, int right){
    if (right > left) {
        int mid = (left + right) / 2;
        mergesort(arr, perm, left, mid);
        mergesort(arr, perm, mid + 1, right);
        merges(arr, perm, left, mid, right);
    }

}

int index_array(int arr[n], int perm[n], int n){ // Return the array of indexes after Merge Sort.
    mergesort(arr, perm, 0, n - 1);
    return *perm;
}

int rand_number(int min_val, int max_val){ // Return a random number between min_val and max_val.

    return rand()%(max_val - min_val + 1) + min_val;
}

bool is_valid(int arr[n], int perm[n], int n){ //Check if the array of indexes (perm) has been sorted correctly.

    int i, sorted[n];
    copy(arr, arr+n, sorted); // Copy the original array into a new array.
    sort(sorted, sorted + n); // Sort the new array.
    for (i = 0; i < n; i++) {
        if (sorted[i] != arr[perm[i]]) {
        // If there is at least one value from arr at index perm[i] which is not equal to the value
        // in the sorted array, then it is incorrect.
            return false;
        }
    }
    return true;
}

void output(string filename, int arr[n], int perm[n], int n){
    int i;
    ofstream out(filename);
    out<<"index: value"<<"\n";
    for (i = 0; i < n; i++) {
        out<<"  "<<perm[i]<<"    "<<arr[perm[i]]<<"\n";
    }
    out<<"\n";
    out.close();
}
