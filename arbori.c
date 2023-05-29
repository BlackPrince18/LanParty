#include "arbori.h"

TNode* createNode(char* data, float number) {
    TNode* newNode = (TNode*)malloc(sizeof(TNode));
    newNode->data = (char*)malloc(strlen(data)+1);
    strcpy(newNode->data, data);
    newNode->number = number;
    newNode->left = newNode->right = NULL;

    return newNode;
}

TNode* insertNode(TNode* root, char* data, float number) {
    if (root == NULL) {
        return createNode(data, number);
    }

    int compareResult = strcmp(data, root->data);

    if(number > root->number)
        root->left = insertNode(root->left, data, number);
    else if(number < root->number)
        root->right = insertNode(root->right, data, number);
    else
    {
        if(compareResult > 0)
            root->left = insertNode(root->left, data, number);
        else
            root->right = insertNode(root->right, data, number);
    }

    return root;
}

void inorderTraversal(TNode* root, FILE* ptr) {
    int i;
    
    if (root != NULL) {
        inorderTraversal(root->left, ptr);
        fprintf(ptr, "%s", root->data);
        for(i=0; i<(34-strlen(root->data)); i++)
                fprintf(ptr, " ");
        fprintf(ptr, "%.2f\n", root->number);
        inorderTraversal(root->right, ptr);
    }
}
