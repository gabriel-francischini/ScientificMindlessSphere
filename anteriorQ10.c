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

void leaves(Tree T){
    if(T==NULL) return;
    leaves(T->left);
    if(T->left==T->right) printf("%d\n",T->item);
    leaves(T->right);
}

int main(void) {
    Tree A = tree(tree(tree(NULL,1,NULL),2,tree(NULL,3,NULL)),4,tree(NULL,5,tree(NULL,6,NULL)));
    leaves(A); // deve exibir 1 3 6
    return 0;
}