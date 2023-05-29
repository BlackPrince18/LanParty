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

    if(number < root->number)
        root->left = insertNode(root->left, data, number);
    else if(number > root->number)
        root->right = insertNode(root->right, data, number);
    else
    {
        if(compareResult < 0)
            root->left = insertNode(root->left, data, number);
        else
            root->right = insertNode(root->right, data, number);
    }

    return root;
}

void inorderTraversal(TNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s: %.2f\n", root->data, root->number);
        inorderTraversal(root->right);
    }
}
