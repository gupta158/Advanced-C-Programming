#include <stdio.h>
#include <stdlib.h>
#include "pa09.h"

int main ( int argc , char ** argv )
{
  int i; //index

  //check arguments
  if (argc != 3)
    {
      printf("usage: ./pa09 <input file> <output file>\n");
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
  
  HuffNode* Huff_tree = Huff_create(fptr);
  fclose(fptr);
  fptr = fopen(argv[2], "w");
  if (fptr == NULL)
  {
    printf("output file error\n");
    return EXIT_FAILURE;
  }
  if(Huff_tree != NULL)
  {
    // Huff_postOrderPrint(Huff_tree);
  }
  
  // Huff_destroy(Huff_tree);
  fclose(fptr);
  return EXIT_SUCCESS ;

}
