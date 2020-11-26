#include <stdio.h>
#include <stdlib.h>

// -- tipos e funções definidos na Questão 2
typedef struct node {
    struct node *left;
    int item;
    struct node *right;
} *Tree;

Tree tree(Tree left, int item, Tree right) {
    Tree new = malloc(sizeof(struct node));
    new->left = left;
    new->item = item;
    new->right = right;
    return new;
}

void print(Tree T, int h) {
    if( T==NULL ) return;
    print(T->right, h+1);
    printf("%*s%d\n", 3*h, "", T->item);
    print(T->left, h+1);
}
// -- tipos e funções definidos na Questão 2

int minimum(Tree *T) {
    if( *T == NULL ) abort();
    if( (*T)->left == NULL ) {
        int x = (*T)->item;
        return x;
    }
    return minimum(&(*T)->left);
}

int main(void) {
    Tree A = tree(tree(tree(NULL,1,tree(NULL,2,NULL)),3,NULL),4,tree(NULL,5,tree(NULL,6,NULL)));
    printf("Minimum item: %d\n",minimum(A)); // deve exibir Minimum item: 1
    return 0;
}