#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int n = 100;

void merges(int arr[100], int perm[100], int left, int mid, int right);

void mergesort(int arr[100], int left, int right);

int index_array(int arr[100], int perm[100], int n);

int rand_number(int min_val, int max_val);

bool is_valid(int arr[100], int perm[100], int n);

void output(int arr[100], int perm[100], int n);

void create_file(string filename);

#endif // MERGESORT_H
