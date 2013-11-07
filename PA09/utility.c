#include "pa09.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

	
HuffNode * Huff_new(int value)
{
	HuffNode * list1 = NULL;
	list1 = malloc(sizeof(HuffNode));
	list1 -> value = value;
	list1 -> left = NULL;
	list1 -> right = NULL;
	return list1;
}
Stack * Stack_new(HuffNode * Node)
{
	Stack * list1 = NULL;
	list1 = malloc(sizeof(Stack));
	list1 -> top = Node;
	list1 -> next = NULL;
	return list1;
}

void HuffNode_destroy ( HuffNode * array )
{
	//Destroys left, then right then the node itself
	if (array == NULL)
	{
		return;
	}
	HuffNode_destroy(array -> left);
	HuffNode_destroy(array -> right);
	free(array);

} 

HuffNode* Huff_create(char* filename, FILE* fptr)
{
	// FILE * fptr = NULL;
	//fptr = fopen(filename, "r");
	HuffNode * Node1  = NULL;
	if (fptr == NULL)
    {
      printf("File error!\n");
      return NULL;
    }
	int inputlength = strlen(filename);
	if(filename[inputlength - 1] == 't')
	{
		//printf("BIT");
		Node1 = bit_input(fptr);//return NULL;
	}
	else
	{
		Node1 = Huff_char(fptr);
		//return Node1;
	}
	
	return Node1;
}

HuffNode* Huff_char(FILE* fptr)
{

  	char number = 0;
  	int count = 0;
	while(fscanf(fptr, "%c", &number) == 1)
	{
		count++;
		// printf("Number = %d \n", number);
		//printf("Number = %d \n", number);
		if(number == 10)
		{
			if(fscanf(fptr, "%c", &number) == 1)
			{
				// printf("InsecondNumber = %d \n", number);
				if(number == 48 || number == 49)
				{
					count++;
				}
				else
				{
					break;
				}
			}
		}
	}
	char * data = malloc(sizeof(char) * count);
	fseek(fptr, 0, SEEK_SET );
	int i = 0;
	for(i = 0; i < count ; i++)
	{
		if(fscanf(fptr, "%c", &data[i]) == 1)
		{
		
		}
		else
		{
			printf("ERROR getting values \n");
			break;
		}
	}
	//fclose(fptr);
	// printf("InsecondNumber1 = %d \n", data[0]);
	// printf("InsecondNumber1last = %d \n", data[count - 1]);
	// int number_of_value_1 = 0;
	// fscanf(fptr, "%d", &number_of_value_1);
	// printf("\nlength: %d\n", number_of_value_1);
		
	// printf("count = %d, dacount = %d", count, data[count]);
	int b = 0;
	Stack* hufftree = NULL;
	HuffNode* NewNode = NULL;
	HuffNode* Node1 = NULL;
	HuffNode* Node2 = NULL;
	while(b < count)	
	{
		if(data[b] == 49)
		{
			b++;
			
			NewNode = Huff_new(data[b]);

			hufftree = Stack_push(NewNode, hufftree); 
			//Add to stack push
		}
		
		if(data[b] == 48)
		{
		    Node1 = hufftree->top;
			hufftree = Stack_pop(hufftree);
			if(hufftree == NULL)
			{
				free(data);
				return Node1;
				
			}
			
			else
			{
				Node2 = hufftree->top;
				hufftree = Stack_pop(hufftree);
				NewNode = Huff_new(0);
				NewNode->right = Node1;
				NewNode->left = Node2;
				hufftree = Stack_push(NewNode, hufftree); 
			}
			// combine two nodes and put new node with left right there
			// pop the stack and combine the newest 2 huff nodes
			// and put this back into stack
			// manuallly end it
			// POP THE STACK TO GET ANOTHER NODE //node b
			// CREATE A NODE AS THE PARENT OF THE TWO NODES //node a and node b share a parent
			// pus the parent node to the stack
			// -> take latest 2 bulit leaf nodes and make them share the same leaf node//hint stack
		}
		b++;
		 // Huff_postOrderPrint(NewNode);
		 // printf("AAAAAAAAAAAAA and b = %d\n", b-1);
	}
	free(data);
	return Node1;
}

Stack* Stack_push(HuffNode * newNode, Stack* old)
{
	if(old == NULL)
	{
		return Stack_new(newNode);
	}
	
	Stack * NewStack =  Stack_new(newNode);
	NewStack -> next = old;
	
	return NewStack;
}

Stack* Stack_pop(Stack* old)
{
	if(old == NULL)
	{
		return NULL;
	}
	
	if(old->next == NULL)
	{
		free(old);
		return NULL;
	}
	
	Stack* newStack = old->next;
	free(old);
	return newStack;
	
}

/* DO NOT MODIFY THIS FUNCTION!!! */
void Huff_postOrderPrint(HuffNode *tree, FILE* fh)
{
    // Base case: empty subtree
    if (tree == NULL) {
		return;
    }

    // Recursive case: post-order traversal

    // Visit left
    fprintf(fh, "Left\n");
    Huff_postOrderPrint(tree->left, fh);
	fprintf(fh, "Back\n");
    // Visit right
    fprintf(fh, "Right\n");
    Huff_postOrderPrint(tree->right, fh);
	fprintf(fh, "Back\n");
    // Visit node itself (only if leaf)
    if (tree->left == NULL && tree->right == NULL) {
		fprintf(fh, "Leaf: %c\n", tree->value);
    }
    

}

HuffNode* bit_input(FILE* fptr)
{
	// uint8_t ptr;
	// size_t bytesnum = 1;
	// int count = 0;
	// int a = 0;
	// FILE * fh = fopen(filename, "r");
	if(fptr == NULL)
	{
		return NULL;
	}
	// // while(bytesnum == 1)
	// // {
		// // count++;
		 // // // printf("first = %d, bytesnbum = %d", ptr, bytesnum);
		// // bytesnum = fread(&ptr, 1, 1, fh);
		 // // // printf("first = %d, bytesnbum = %d", ptr, bytesnum);
		
	// // }
	// // fseek(fh, 0, SEEK_SET );
	// // uint8_t * bitdata = malloc(sizeof(uint8_t) * count);
	// // uint8_t * bitdata2 = bitdata;
	
	// // for( a = 0; a < count; a++)
	// // {
		// // bytesnum = fread(&bitdata[a], 1, 1, fh);
		// // printf("second = %d", bitdata[a]);
	// // }

	// // // printf("data = %d", ptr.data);
	// // //fclose(fh);
	
	// // free(bitdata);
	bitfile* bp = bitopen(fptr);
	Stack* hufftree = NULL;
	HuffNode* NewNode = NULL;
	HuffNode* Node1 = NULL;
	HuffNode* Node2 = NULL;
	if(bp == NULL)
	{
		printf("Failed to open file \n");
		return NULL;
	}
	int byte;
	int bit = 0;
	// fprintf(stderr, "Printinf to stderr just test '%s' \n", bit_filename); //./a.out 2>/dev/null 2 streams, error stream not going to be printed int that circumstance
	// int bit = 0;
	
	while((bit = getbit(bp)) >= 0)
	{
		//printf("%d \n", bit);
	
	//bit = getbit(bp);
		if(bit == 1)
		{
			byte = getbyte(bp);
			//printf("%c", byte);
			NewNode = Huff_new(byte);

			hufftree = Stack_push(NewNode, hufftree); 
			
		}
		else
		{
				Node1 = hufftree->top;
				hufftree = Stack_pop(hufftree);
				if(hufftree == NULL)
				{
					//free(data);
					bitclose(bp);
					return Node1;
					
				}
				
				else
				{
					Node2 = hufftree->top;
					hufftree = Stack_pop(hufftree);
					NewNode = Huff_new(0);
					NewNode->right = Node1;
					NewNode->left = Node2;
					hufftree = Stack_push(NewNode, hufftree); 
				}
			//getbit(bp);
		}
	}
	// while(byte = getByte(bp)) >= 0)
	// {
		// fprintf("%x \n", byte);
	// }
	
	bitclose(bp);
	return NULL;
}

int getbyte(bitfile* bp)
{
	int ret = 0;
	int i;
	int bit = 0;
	for(i = 0; i < 8; i++)
	{
		bit = getbit(bp);
		if(bit < 0)
		{
			return -1;
		}
		
		ret = ret << 1;
		ret = ret | bit;
		// printf(" ret, %d  i = %d \n", bit, i);
	}
	// printf("%d ret \n", ret);
	return ret;
}
bitfile* bitopen(FILE * fp)
{
	// FILE* fp = fopen(filebane, "rb");
	if(!fp)
	{
		return NULL;
	}
	bitfile* bp = malloc(sizeof(bitfile));
	bp->fp = fp;
	bp->byte = 0;
	bp ->remaining = 0;
	
	return bp;
}

void bitclose(bitfile* bp)
{
	if(!bp)
	{
		return;
	}
	// fclose(bp->fp);
	free(bp);
}
int getbit(bitfile * bp)
{
	if(bp -> remaining == 0)
	{
		//No bits left
		if(fread(&(bp->byte), 1, 1, bp->fp) == 1)
		{
			bp->remaining = 8; // 8 bytes
		}
		if(bp -> remaining == 0)
		{
			return -1;
		}
	}
		int pos = (bp -> remaining) - 1;
		unsigned char mask = 1 << pos;
		unsigned char ret = (bp-> byte) & mask;
		ret = ret >> pos;
		bp->remaining -= 1;
		return ret;
}


// int convertbinary(int val)
// {
	// int test = val % 2;
	// int num = 1;
	// int count = 0;
	// if(test == 1)
	// {
		// num = 1;
		// count++;
	// }
	
	// convertbinary(val, count
		// count++;



//How do we know that the character there, also how to read each bit? Reading one byte means 8 bits will it always be 8 bits or how do we take into account that
//Will it be 10 bytes always? Can we use fseek? do we read the whole file? How do we know if its the header end? Still \n? We read separatley or what?? Pad with 0??
//Get next bit//Letter seaparatr

//Get next 1 bit till 8, thn next byte

//1 then next 8 