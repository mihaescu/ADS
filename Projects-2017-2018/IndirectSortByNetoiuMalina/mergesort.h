#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int n = 100;

void merges(int arr[n], int perm[n], int left, int mid, int right);

void mergesort(int arr[n], int left, int right);

int index_array(int arr[n], int perm[n], int n);

int rand_number(int min_val, int max_val);

bool is_valid(int arr[n], int perm[n], int n);

void output(string filename, int arr[n], int perm[n], int n);

void create_file(string filename);

#endif // MERGESORT_H
