#ifndef pa09_h
#define pa09_h
#include <stdio.h>
typedef struct leaf {
    int value;
    struct leaf *left;
    struct leaf *right;
} HuffNode;

typedef struct lifo {
    HuffNode *top;
    struct lifo *next;
} Stack;

// typedef struct bits{
    // unsigned int pos; // Should be ECE264_IMAGE_MAGIC_BITS
	// unsigned int end;
	// FILE* bpoint;
// } Bitread;
typedef struct bit_file_st{
	FILE* fp;
	unsigned char byte;
	int remaining;
}bitfile;
//HuffNode * Huff_create( FILE * fptr);
	HuffNode * Huff_new(int value);
	Stack * Stack_new(HuffNode*);
	Stack* Stack_push(HuffNode * new, Stack* old);
    Stack* Stack_pop(Stack * old);
	HuffNode * Huff_create(char* filename, FILE* fptr);
	void Huff_postOrderPrint(HuffNode *tree, FILE* fh);
	void HuffNode_destroy ( HuffNode * array );
	HuffNode* bit_input(FILE* fptr);
	HuffNode* Huff_char(FILE* fptr);
	int getbit(bitfile * bp);
	void bitclose(bitfile* bp);
	bitfile* bitopen(FILE * fp);
	int getbyte(bitfile* bp);
 // void Huff_postOrderPrint(HuffNode *tree);

// void Huff_destroy(HuffNode* tree);
#endif /* pa09.h */

