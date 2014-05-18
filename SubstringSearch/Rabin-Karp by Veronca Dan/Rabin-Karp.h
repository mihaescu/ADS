#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10000 //max dimension for the input file

int RabinKarp(struct Text &pattern, struct Text &txt, int q);
long modularHashing(struct Text &txt, int lenght, int q);
