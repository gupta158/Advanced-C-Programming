#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pa09.h"

int main ( int argc , char ** argv )
{
  //check arguments
  if (argc != 3)
    {
      printf("Error, need 2 input arguments, usage: ./pa09 <input file> <output file>\n");
      return EXIT_FAILURE;
    }
  
  //initializing input file
  FILE * fptr = NULL;
  fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      printf("File error!\n");
      return EXIT_FAILURE;
    }
	
	// printf("%s", argv[1]);
	// int inputlength = strlen(argv[1]);
	// // printf(" IL = %d, lastchar = %c \n", inputlength, argv[1][inputlength - 1]);
  	// char number = 0;
  	// int count = 0;
	// while(fscanf(fptr, "%c", &number) == 1)
	// {
		// count++;
		// // printf("Number = %d \n", number);
		// //printf("Number = %d \n", number);
		// if(number == 10)
		// {
			// if(fscanf(fptr, "%c", &number) == 1)
			// {
				// // printf("InsecondNumber = %d \n", number);
				// if(number == 48 || number == 49)
				// {
					// count++;
				// }
				// else
				// {
					// break;
				// }
			// }
		// }
	// }
	// // printf("Length = %d", count);
	// fseek(fptr, 0, SEEK_SET );
	// fclose(fptr);
   HuffNode* Huff_tree = Huff_create(argv[1], fptr);
   // HuffNode* Huff_tree = bit_input(argv[1], fptr);

  // fptr = fopen(argv[2], "w");
  // if (fptr == NULL)
  // {
    // printf("output file error\n");
    // return EXIT_FAILURE;
  // }
  // if(Huff_tree != NULL)
  // {
  FILE* fh = fopen(argv[2], "w");
  if(fh == NULL)
  {
	printf("FAILED TO OPEN FILE");
	return EXIT_FAILURE;
  }
     Huff_postOrderPrint(Huff_tree, fh);
  // }
  
  // // Huff_destroy(Huff_tree);
   fclose(fh);
   fclose(fptr);
  HuffNode_destroy (Huff_tree );
	return EXIT_SUCCESS ;

}
