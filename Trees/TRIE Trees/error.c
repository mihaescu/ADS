#include "error.h"
#include <stdio.h>

void error_handling(int error)
{
	if (error == MEM) {
		fprintf(stderr,"Error! Cannot allocate memory!\n");
	}
	else {
		return;
	}
}