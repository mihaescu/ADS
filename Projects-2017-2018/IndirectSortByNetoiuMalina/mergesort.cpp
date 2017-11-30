#include <ctime>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "mergesort.h"
using namespace std;

void merges(int arr[100], int perm[100], int left, int mid, int right)
{
    int temp[100], i, j, k;

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
    //The values at indexes perm[i] and perm[j] are compared.
    //The index of the smallest value is stored in temp.

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

void mergesort(int arr[100], int perm[100], int left, int right)
{
    if (right > left) {
        int mid = (left + right) / 2;
        mergesort(arr, perm, left, mid);
        mergesort(arr, perm, mid + 1, right);
        merges(arr, perm, left, mid, right);
    }

}

int index_array(int arr[100], int perm[100], int n)
{
    mergesort(arr, perm, 0, n - 1);
    return *perm;
}

int rand_number(int min_val, int max_val)
{
    return rand()%(max_val - min_val + 1) + min_val;
}

bool is_valid(int arr[100], int perm[100], int n)
{
    int i, sorted[100];
    copy(arr, arr+n, sorted);
    sort(sorted, sorted + n);
    for (i = 0; i < n; i++) {
        if (sorted[i] != arr[perm[i]]) {
            return false;
        }
    }
    return true;
}

void output(int arr[100], int perm[100], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        cout<<perm[i]<<" ";
    }
    cout<<endl;
    for (i = 0; i < 2*n; i++) {
        cout<<"-";
    }
    cout<<endl;
    for (i = 0; i < n; i++) {
        cout<<arr[perm[i]]<<" ";
    }
    cout<<endl;
}
