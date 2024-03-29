/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 * You can test your functions with your own input file.
 * See details in README or typing command ./pa04 in terminal after make.
 * See output format examples in any of the files in directory expected.
 * 
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa04.h.
 */

#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
void partitionworker(int *, int, int);
void partitionworker2(int *, int, int);
void partitionworker3(int *, int, int);
void partitionworker4(int *, int, int);
void partitionworker5(int *, int, int);
void partitionworker6(int *, int, int);
void partitionworker7(int *, int, int);
void print(int *, int);
/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * For example, if the value is 3:
 *
 * partitionAll 3
 * = 1 + 1 + 1
 * = 1 + 2
 * = 2 + 1
 * = 3
 */

void partitionAll(int value)
{
	printf("partitionAll %d\n", value);
	// int ind = 0;
	// int ind2 = 0;
	// int val = 0;
	// int iter = 0;
	//Allocates max memory, which is the number of integers and then frees it
	int * arr = malloc(sizeof(int) * value);
	partitionworker(arr, 0, value);
	
	free(arr);
	return;
}

void partitionworker(int * arr, int pos, int n)
{
	/*Recursive function which prints all partitions.
	Puts a value for the first variable, then partitions the remainder from the sum,
	continues until n is 0.*/
	
	if(n <= 0)
	{
		print(arr, pos);
		return;
	}
	int i;
	for(i = 1; i <= n; ++i)
	{
		arr[pos] = i;
		partitionworker(arr, pos + 1, n - i);
	}
	
	return;
}



void print (int * arr, int len)
{
	/* Simple Print function which prints all variables in the array*/
	int i;
	if(len > 0)
	{
		printf("= %d", arr[0]);
	}
	for(i = 1; i < len; ++i)
	{
		printf(" + %d", arr[i]);
	}
		printf("\n");
	return;
}
/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */


void partitionIncreasing(int value)
{
	printf("partitionIncreasing %d\n", value);
	// int ind = 0;
	// int ind2 = 0;
	// int val = 0;
	// int iter = 0;
	int * arr = malloc(sizeof(int) * value);
	partitionworker2(arr, 0, value);
	
	free(arr);
	return;
}

void partitionworker2(int * arr, int pos, int n)
{
	/* Same as above partition function, just has an if which makes sure that the array is increasing,
	adds the value to the array only if it is larger than the variable before it */
	if(n <= 0)
	{
		print(arr, pos);
		return;
	}
	int i;
	for(i = 1; i <= n; ++i)
	{
		if(pos == 0)
		{
			arr[pos] = i;
			partitionworker2(arr, pos + 1, n - i);
		}
		else if(i > arr[pos - 1])
		{
			arr[pos] = i;
			partitionworker2(arr, pos + 1, n - i);	
		}
	}
	
	return;
}

/*
 * =================================================================
 * This function prints the partitions that use Decreasing values.
 *
 * For example, if value is 5
 * 3 + 2 and
 * 4 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */


void partitionDecreasing(int value)
{
  printf("partitionDecreasing %d\n", value);
	// int ind = 0;
	// int ind2 = 0;
	// int val = 0;
	// int iter = 0;
	int * arr = malloc(sizeof(int) * value);
	partitionworker3(arr, 0, value);
	
	free(arr);
	return;
}

void partitionworker3(int * arr, int pos, int n)
{
	/* Same as initial partition function, just has an if which makes sure that the array is decreasing,
	adds the value to the array only if it is smaler than the variable before it */
	if(n <= 0)
	{
		print(arr, pos);
		return;
	}
	int i;
	for(i = 1; i <= n; ++i)
	{
		if(pos == 0)
		{
			arr[pos] = i;
			partitionworker3(arr, pos + 1, n - i);
		}
		else if(i < arr[pos - 1])
		{
			arr[pos] = i;
			partitionworker3(arr, pos + 1, n - i);	
		}
	}
	
	return;
}
/*
 * =================================================================
 * This function prints odd number only partitions of a positive integer value
 * For example, if value is 5
 * 1 + 1 + 1 + 1 + 1 and
 * 1 + 3 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 1 + 2 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partitionOdd(int value)
{
  printf("partitionOdd %d\n", value);
  
	int * arr = malloc(sizeof(int) * value);
	partitionworker4(arr, 0, value);
	
	free(arr);
	return;
}

void partitionworker4(int * arr, int pos, int n)
{
	/* Same as initial partition function, just has an if which makes sure that the array has odd numbers only,
	checks if the value is odd, if it is, the value is added to the array */
	if(n <= 0)
	{
		print(arr, pos);
		return;
	}
	int i;
	for(i = 1; i <= n; ++i)
	{
		if(i % 2 == 1)
		{
			arr[pos] = i;
			partitionworker4(arr, pos + 1, n - i);	
		}
	}
	
	return;
}

/*
 * =================================================================
 * This function prints even number only partitions of a positive integer value
 * For example, if value is 8
 * 2 + 2 + 2 + 2and
 * 2 + 4 + 2 are valid partitions
 *
 * 8 is a valid partition
 *
 * 2 + 1 + 1 + 2 + 2and
 * 2 + 1 + 2 + 3and
 * 5 + 3 are invalid partitions.
 *
 * if the value is 5, there will be no result generated
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partitionEven(int value)
{
  printf("partitionEven %d\n", value);

	int * arr = malloc(sizeof(int) * value);
	partitionworker5(arr, 0, value);
	
	free(arr);
	return;
}

void partitionworker5(int * arr, int pos, int n)
{
	/* Same as initial partition function, just has an if which makes sure that the array has even numbers only,
	checks if the value is even, if it is, the value is added to the array */
	if(n <= 0)
	{
		print(arr, pos);
		return;
	}
	int i;
	for(i = 1; i <= n; ++i)
	{
		if(i % 2 == 0)
		{
			arr[pos] = i;
			partitionworker5(arr, pos + 1, n - i);	
		}
	}
	
	return;
}

/*
 * =================================================================
 * This function prints alternate ood and even number partitions of a positive integer value. Each partition starts from and odd number, even number, ood number again, even number again...etc.
 *
 * For example, if value is 6
 * 1 + 2 + 1 + 2 and
 * 3 + 2 + 1 are valid partitions
 *
 * 6 is not a valid partition
 *
 * 2 + 1 + 1 + 2 and
 * 2 + 1 + 3and
 * 5 + 1 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partitionOddAndEven(int value)
{
  printf("partitionOddAndEven %d\n", value);
  
	int * arr = malloc(sizeof(int) * value);
	partitionworker6(arr, 0, value);
	
	free(arr);
	return;
}

void partitionworker6(int * arr, int pos, int n)
{
	/* Same as initial partition function, just has an if which makes sure that the array has an odd numbers first and then alternates with even numbers,
	if the value in the position is even, then only an odd number can be added to the array and vice versa */
	if(n <= 0)
	{
		print(arr, pos);
		return;
	}
	int i;
	for(i = 1; i <= n; ++i)
	{
		if(pos == 0)
		{
			if(i % 2 == 1)
			{
				arr[pos] = i;
				partitionworker6(arr, pos + 1, n - i);	
			}
		}
		if(pos > 0)
		{
			if(arr[pos - 1] % 2 == 1)
			{
				if(i % 2 == 0)
				{
					arr[pos] = i;
					partitionworker6(arr, pos + 1, n - i);	
				}
			}
			if(arr[pos - 1] % 2 == 0)
			{
				if(i % 2 == 1)
				{
					arr[pos] = i;
					partitionworker6(arr, pos + 1, n - i);	
				}
			}
		}

	}
	
	return;
}
/*
 * =================================================================
 * This function prints prime number only partitions of a positive integer value
 * For example, if value is 6
 * 2 + 2 + 2 and
 * 3 + 3 are valid partitions
 *
 * 6 is not a valid partition
 * 
 * 2 + 4 and
 * 1 + 5 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */



void partitionPrime(int value)
{
  printf("partitionPrime %d\n", value);


	int * arr = malloc(sizeof(int) * value);
	partitionworker7(arr, 0, value);
	
	free(arr);
	return;
}

void partitionworker7(int * arr, int pos, int n)
{	
	/* Same as initial partition function, just has an if which makes sure that the array has prime numbers only,
	checks if value is 1 or divisible by 2. It then runs through all numbers except multiples of 2 to check if i is divisible by it */
	int check = 1;
	int ind;
	if(n <= 0)
	{
		print(arr, pos);
		return;
	}
	int i;
	for(i = 1; i <= n; i++)
	{
		check = 1;
		if(i > 2 && i % 2 == 0)
		{
			check = 0;
		}	
		if(i == 1)
		{
			check = 0;
		}

		if(check != 0)
		{
			for(ind = 3; ind < i; ind += 2)
			{
				if(i % ind == 0)
				{
					check = 0;
					//ind = i;
				}
			}

		}
		if(check == 1)
		{
			arr[pos] = i;
			partitionworker7(arr, pos + 1, n - i);	
		}
	}
	
	return;
}
