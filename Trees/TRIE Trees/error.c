#include "error.h"
#include <stdio.h>

int error_handling(int error)
{
	if (error == MEM) {
		printf("Error! Cannot allocate memory!\n");
		return MEM;
	}
	else {
		return OKAY;
	}
}