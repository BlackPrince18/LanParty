#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem4
{
    char* data;
    float number;
    struct Elem4 *left, *right;
};

typedef struct Elem4 TNode;

TNode* createNode(char* data, float number);
TNode* insertNode(TNode* root, char* data, float number);
void inorderTraversal(TNode* root, FILE* ptr);