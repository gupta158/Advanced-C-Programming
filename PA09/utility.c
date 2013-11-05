#include "pa09.h"
#include <stdio.h>
#include <stdlib.h>


HuffNode* Huff_create(FILE * fptr)
{
	int number_of_value_1 = 0;
	fscanf(fptr, "%d", &number_of_value_1);
	printf("\nlength: %d\n", number_of_value_1);
}