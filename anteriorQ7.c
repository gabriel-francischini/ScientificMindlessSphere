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

Tree make(int v[], int i, int j) {
    if( i>j ) return NULL;
    int m = (i+j)/2;
    return tree(make(v, o1 , o2 ),v[m],make(v, o3 , o4 ));
}

int main(void) {
    int v[7] = {10,20,30,40,50,60,70};
    Tree A = make(v,0,6);
    print(A,0);
    return 0;
}