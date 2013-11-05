#ifndef pa09_h
#define pa09_h

typedef struct leaf {
    int value;
    struct leaf *left;
    struct leaf *right;
} HuffNode;

typedef struct lifo {
    struct lifo *push;
    struct lifo *peek;
    struct lifo *pop;
} Stack;

HuffNode * Huff_create(FILE*);

// void Huff_postOrderPrint(HuffNode *tree);

// void Huff_destroy(HuffNode* tree);
#endif /* pa09.h */

