
#include "pa03.h"
#include <stdio.h>
#include <stdlib.h>

void quicksort(int *, int, int, int);
void exchange(int *, int, int);
int binary_search(int *, int, int, int);
/**
 * Read a file of integers.
 *
 * Arguments:
 *
 * filename: the name of a file that contains a list of integers (one
 * per line)
 * 
 * numberOfIntegers: pointer to store the number of integers in the
 * file. You need to update the value stored at the address which is
 * the pointer's value
 *
 * Returns:
 *
 * a array of integers from the file, or NULL if *any* error is
 * encountered.
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
 * The allocated memory will be released in pa03.c. You do not need to
 * worry about releasing memory.
 *
 * You will receive zero if you allocate a large array whose size is
 * independent of the number of integers in the file.  For example, if
 * you write this
 *
 * int array[10000];
 * 
 *
 */

int * readIntegers(const char * filename, int * numberOfIntegers)
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
		*numberOfIntegers = count;
		return &(array[0]);
	}

        
}

/**
 * Sort an (ascending) array of integers
 *
 * Arguments:
 * arr    The array to search
 * length Number of elements in the array
 *
 * Uses "quicksort" to sort "arr".  Use the first element of the array
 * as the pivot.  
 *
 * Your solution MUST use recursive function (or functions)
 * 
 * quicksort works in the following way: 
 * 
 * find an element in the array (this element is called the
 * pivot). 
 *
 * rearrange the array's elements into two parts: the part smaller
 * than this pivot and the part greater than this pivot; make the pivot
 * the element between these two parts
 * 
 * sort the first and the second parts separately by repeating the 
 * procedure described above
 * 
 * You will receive no point if you use any other sorting algorithm.
 * You cannot use selection sort, merge sort, or bubble sort.
 * 
 * Some students are fascinated by the name of bubble sort.  In
 * reality, bubble sort is rarely used because it is slow.  It is a
 * mystery why some students (or even professors) like bubble sort.
 * Other than the funny name, bubble sort has nothing special and is
 * inefficient, in both asymptotic complexity and the amount of data
 * movement.  There are many algorithms much better than bubble sort.
 * You would not lose anything if you do not know (or forget) bubble
 * sort.
 *
 */
void sort(int * arr, int length)
{
	int min = 0;

	quicksort(arr, length, min, length);

}

void quicksort(int * arr, int max, int min, int length)
{
	int number;
	int higher = 0;
	int lower = min;
	int var; 
	int var3 = min;
	int num;

	//Breaks once it breaks some parameters
	num = min;
	if((max < 1) || (min >= max) || (max > length))
	{
		return;
	}

	number = arr[num];	
	
	//Counts number of variables greater than the number and the number smaller
	var = num;
	for(++var; var < max; var++)
	{
		if(arr[var] < number)
		{
			lower++;
		}
		else
		{
			higher++;
		}	
	}
	//Moves the number to the point where the lower numbers end
	exchange(arr, num, lower);
	num = lower;
	//Moves all smaller numbers to the left
	for(var = min; var < max; var++)
	{
		if(arr[var] < number)
		{
			exchange(arr, var, var3);
			var3++;
		}
	}
	//Recursive call, for the second half of the values, if lower is min, min value is increased
	if(lower == min)
	{
		quicksort(arr, num + higher + 1, num + 1, length);
	}
	else
	{
		quicksort(arr, num + higher + 1, num, length);
	}
	//Recursive call, for the first half of the values, if higher is 0, max value is decreased
	if(higher == 0)
	{
		quicksort(arr, num , min, length);
	}
	else
	{
		quicksort(arr, num, min, length);
	}
		
	return;
}

//Exchanges values in an array when called
void exchange(int * arr, int num1, int num2)
{
	int temp;
	
	temp = arr[num1];
	arr[num1] = arr[num2];
	arr[num2] = temp;
	
}
/**
 * Use binary search to find 'key' in a sorted array of integers
 *
 * Arguments:
 * 
 * arr The array to search. Must be sorted ascending.  You do not need
 *        to check. This array is from the result of your sort
 *        function. Make sure your sort function is correct before you
 *        start writing this function.
 *
 * length Number of elements in the array
 * key    Value to search for in arr
 *
 * Returns:
 * The index of 'key', or -1 if key is not found.
 *
 * Since the array is sorted, you can quickly discard many elements by
 * comparing the key and the element at the center of the array. If
 * the key is the same as this element, you have found the index.  If
 * the key is greater than this element, you can discard the first
 * half of the array.  If the key is smaller, you can discard the
 * second half of the array.  Now you have only half of the array to
 * search.  Continue this procedure until either you find the index or
 * it is impossible to find a match.
 * 
 * Your solution MUST use recursive function (or functions)
 *
 * Don't forget that arrays are 'zero-indexed'. Also, you must
 * use a binary search to pass this question.
 * 
 * You will receive no point if you do the following because it is not
 * binary search.  This is called linear search because it checks
 * every element.
 *
 * int ind;
 * for (ind = 0; ind < length; ind ++)
 * {
 *    if (arr[ind] == key)
 *    {
 *       return ind;
 *    }
 * }
 * return -1;
 */
int search(int * arr, int length, int key)
{
	int first = 0;
	int last = length - 1;
	int result;
	
	result = binary_search(arr, key, first, last);
		
    return result;
}

int binary_search(int * arr, int key, int first, int last)
{
	//If last is smaller than first, that means key doesnt exist
	if(last < first)
	{
		return -1;
	}	
	
	//Finds the middle value
	int middle = (first + last) / 2;
	int num;

	//If key is bigger than the middle value, then first value is made to be the value ahead of middle
	if(key > arr[middle])
	{
		first = middle + 1;
	}
	//If key is the middle value, function ends
	else if (key == arr[middle])
	{
		return middle;
	}
	//If key is smaller than middle value, second half of array is discarded, same logic as above
	else	
	{
		last = middle - 1;
	}
	
	//Recursive call until num gets a value
	num = binary_search(arr, key, first, last);
	
	return num ;
}
