#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa05.h"

int compare(const void*, const void*);
int compare2(const void*, const void*);
/*
 * Read a file of integers.
 *
 * Arguments:
 *
 * filename: the name of a file that contains a list of integers (one
 * per line)
 * 
 * numInteger: pointer to store the number of integers in the
 * file. You need to update the value stored at the address which is
 * the pointer's value.  If the function fails to update the value, it
 * is considered reading the file has failed.
 *
 * Returns:
 *
 * a array of integers from the file, or NULL if *any* error is
 * encountered.
 *
 * Hint: use fscanf
 *
 * You do NOT know how many integers are in the file until you have
 * read it. Once you know how many integers there are, you can modify
 * the "numberOfIntegers" variable. (Note that this is a pointer, not
 * an integer) You must allocate memory to store the integers.
 * 
 * Once memory is allocated to store the integers, you will need to
 * re-read the values from the file. To do this, you must reset the
 * file pointer to the beginning of the file using the function
 * "fseek". 
 *
 * You should not use rewind (if you have learned it somewhere).  The
 * difference of rewind and fseek is that rewind does not tell you
 * whether it fails.  
 *
 * One way to read integeres is to use the "fscanf" function.  It is
 * easier than reading one character at a time by using fgetc.
 *
 * You must use malloc in this function.
 * 
 * Some old books encourage readers to type cast in front of malloc,
 * something like
 *
 * int * ptr = (int *) malloc(sizeof(int) * size);
 *
 * Type cast is no longer needed and in fact is discouraged now.  You
 * should *NOT* type cast malloc.  It is discouraged even though it is
 * not wrong.
 *
 * You will receive zero if you allocate a large array whose size is
 * independent of the number of integers in the file.  For example, if
 * you write this
 *
 * int array[10000];
 * 
 *
 */

int * readInteger(char * filename, int * numInteger)
{
	int count = 0;
	int number = 0;
	int num = 0;
	FILE* fh;
	
	//Opened file
	fh = fopen(filename,"r"); 
	if(fh == NULL)
	{
		return NULL;
	}
	else
	{
		//Counting the number of values
		while(fscanf(fh, "%d", &number) == 1)
		{
			count++;
		}
		//Allocating memory to the array
		int * array = malloc(sizeof(int) * count);
		//Going back to the start
		fseek(fh, 0, SEEK_SET );
		//Transfering values to array
		while(fscanf(fh, "%d", &number) == 1)
		{
			array[num] = number;
			num++;
		}
		
		fclose(fh);
		*numInteger = count;
		return &(array[0]);
	}

        

}

/* ----------------------------------------------- */

/*
 * Read a file of strings. This is similar to readInteger. However,
 * each string is an array of characters. The function needs to
 * allocate memory for an array of strings, i.e., array of arrays of
 * characters. In other words, this is a two-dimensional array (thus,
 * char **).
 *
 * Arguments:
 *
 * filename: the name of a file that contains a list of strings (one
 * per line)
 * 
 * numString: pointer to store the number of strings in the
 * file. You need to update the value stored at the address which is
 * the pointer's value.  If the function fails to update the value, it
 * is considered reading the file has failed.
 *
 * Returns:
 *
 * a array of strings from the file, or NULL if *any* error is
 * encountered.
 *
 * Hint: use fgets. 
 * 
 * Remember that an array of strings is a two-dimensional array of
 * characters
 *
 * You do NOT know how many strings are in the file until you have
 * read it. Once you know how many strings there are, you can modify
 * the "numberOfStrings" variable. (Note that this is a pointer, not
 * an string) You must allocate memory to store the strings.
 * 
 * Once memory is allocated to store the strings, you will need to
 * re-read the values from the file. To do this, you must reset the
 * file pointer to the beginning of the file using the function
 * "fseek". 
 *
 * You should not use rewind (if you have learned it somewhere).  The
 * difference of rewind and fseek is that rewind does not tell you
 * whether it fails.  
 *
 * One way to read stringes is to use the "fscanf" function.  It is
 * easier than reading one character at a time by using fgetc.
 *
 * You must use malloc in this function.
 * 
 * Some old books encourage readers to type cast in front of malloc,
 * something like
 *
 * int * ptr = (int *) malloc(sizeof(int) * size);
 *
 * Type cast is no longer needed and in fact is discouraged now.  You
 * should *NOT* type cast malloc.  It is discouraged even though it is
 * not wrong.
 *
 * You will receive zero if you allocate a large array whose size is
 * independent of the number of strings in the file.  For example, if
 * you write this
 *
 * char array[10000];
 * 
 *
 */

char * * readString(char * filename, int * numString)
{
	int numberoflines = 0;
	FILE* fh;
	char * * array;
	char buffer[MAXIMUM_LENGTH];
	fh = fopen(filename,"r"); 
	if(fh == NULL)
	{
		return NULL;
	}
	else
	{
	    //counting the number of lines
		while(fgets(buffer, MAXIMUM_LENGTH, fh))
		{
			numberoflines++;
		}
		//Allocating memory
		array= malloc(sizeof(char*) * numberoflines);
		//Going back to the start
		fseek(fh, 0, SEEK_SET );
		//Transfering values to array
		int i = 0;
		//Reading each line and allocating memory per line and  storing it in the new array
		while(fgets(buffer, MAXIMUM_LENGTH, fh) != NULL)
		{
			array[i] = malloc(sizeof(char) * (strlen(buffer) + 1));
			strcpy(array[i], buffer);
			i+=1;
		  
		}
		//Close file
		fclose(fh);
		*numString =  numberoflines;
		return array;
		
	}
}



/* ----------------------------------------------- */
/*
 * print an array of integers, one integer per line
 */
void printInteger(int * arrInteger, int numInteger)
{
	int a;
	for(a = 0; a < numInteger; a++)
	{
		printf("%d\n", arrInteger[a]);
	}
	return;
}

/* ----------------------------------------------- */
/*
 * print an array of strings, one string per line
 *
 * Hint: printf("%s" ... can print a string
 */
void printString(char * * arrString, int numString)
{
	int a;
	int len;
	//Prints the string
	for(a = 0; a < numString;a++)
	{
		printf("%s", arrString[a]);
	    len = strlen(arrString[a]);     
        if(len == 0 || arrString[a][len-1] != '\n') 
		{
			printf("\n");
		}
	}
	
}

/* ----------------------------------------------- */
/*
 * release the memory occupied by the array of integers
 */
void freeInteger(int * arrInteger, int numInteger)
{
	free(arrInteger);
}

/* ----------------------------------------------- */
/*
 * release the memory occupied by the array of strings
 *
 * Hint: an array of strings is a two-dimensional array of characters
 */
void freeString(char * * arrString, int numString)
{
	//First frees memory of each line, then of the array of the pointers
	int row;
    for (row = 0; row < numString; row++) 
	{
        free(arrString[row]);
    }
    free(arrString);
}

/* ----------------------------------------------- */
/*
 * Write integers to a file, one integer per line
 *
 * Arguments:
 *
 * filename: the name of a file.
 * arrInteger: an array of integers
 * numInteger: the number of integers 
 *
 * Returns:
 * 1 if saving to the file successfully
 * 0 if *any* error is encountered
 *
 * Hint: use fprintf(... %d
 *
 */

int saveInteger(char * filename, int * arrInteger, int numInteger)
{
	FILE *fh;
	int num;
	//Opens file
	fh = fopen(filename,"w");
	if(fh == NULL)
	{
		return 0;
	}
	//Stores the numbers in the file
	for(num = 0; num < numInteger; num++)
	{
		fprintf(fh, "%d", arrInteger[num]);
		fprintf(fh,"\n");
	}
	
	
	fclose(fh);
	return 1;
}

/* ----------------------------------------------- */
/*
 * Write strings to a file, one string per line
 *
 * Arguments:
 *
 * filename: the name of a file.
 * arrString: an array of strings
 * numString: the number of strings 
 *
 * Returns:
 * 1 if saving to the file successfully
 * 0 if *any* error is encountered
 *
 * Hint: use fprintf(... %s
 *
 */

int saveString(char * filename, char * * arrString, int numString)
 {
	FILE *fh;
	int num;
	int num2 = 0;
	int len;
	//Opens file
	fh = fopen(filename,"w");
	if(fh == NULL)
	{
		return 0;
	}
	for(num = 0; num < numString; num++)
	{
		fprintf(fh, "%s", arrString[num]);
		num2++;
        len = strlen(arrString[num]);     
        if(len == 0 || arrString[num][len-1] != '\n') 
		{
			fprintf(fh,"\n");
		}
	}

	
	fclose(fh);
	return 1;

}

/* ----------------------------------------------- */
/*
 * sort an arry of integers by calling the built-in qsort function in
 * the C library.  You need to provide the comparison function. Please
 * read the Linux manual about qsort
 *
 */

void sortInteger(int * arrInteger, int numInteger)
{
	qsort(arrInteger, numInteger, sizeof(int), compare);
}

int compare(const void * a, const void * b)
{
	int* intp1 = (int*) a;
	int* intp2 = (int*) b;
	
	int val = *intp1;
	int val2 = *intp2;
	
	if(val < val2)
	{
		return -1;
	}
	
	if(val == val2)
	{
		return 0;
	}
	
	return 1;
   
}

/* ----------------------------------------------- */
/*
 * sort an arry of strings by calling the built-in qsort function in
 * the C library.  You need to provide the comparison function. Please
 * read the Linux manual about qsort
 *
 * Hint: use strcmp in the comparison function
 *
 */


void sortString(char * * arrString, int numString)
{
    qsort(arrString, numString, sizeof(char*), compare2);
}

int compare2(const void * str1,const void * str2) 
{
	char** p1 = (char**) str1;
	char** p2 = (char**) str2;
	
	char *val = *p1;
	char *val2 = *p2;
	
	return strcmp(val, val2);

}



