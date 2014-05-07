#include <stdio.h>
#include <conio.h>

void StepOne(int &step, int c[10][10] , int n);
void StepTwo(int &step, int col[10], int row[10], int n, int m[10][10],int c[10][10]);
void StepThree(int & step, int n, int col[10], int m[10][10]);
void FindAZero(int &rows,int &cols, int row[10], int col[10], int c[10][10], int n);
bool StarInRow(int rows, int n,int m[10][10]);
void FindStarInRow(int rows,int &cols, int n, int m[10][10]);
void StepFour(int &step, int n, int m[10][10], int row[10], int col[10], int &Z0_r, int &Z0_c, int c[10][10]);
void FindStarInCol(int cols,int &rows, int n, int m[10][10]);
void FindPrimeInRow(int rows,int &cols, int n, int m[10][10]);
void CovertPath(int path[20][10],int count, int m[10][10]);
void ClearCovers(int row[10],int col[10], int n);
void ErasePrimes(int n,int m[10][10]);
void StepFive(int &step,int n, int c[10][10],int Z0_r, int Z0_c, int m[10][10], int row[10], int col[10]);
void FindSmallests(int &minval, int n,int row[10], int col[10],int c[10][10]);
void StepSix(int &step, int c[10][10],int n,int row[10],int col[10]);
void Unger();