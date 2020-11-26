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

Tree mirror(Tree T){
    if(T==NULL) return NULL;
    return tree(mirror(T->right),T->item,(mirror(T->left)));
}

int main(void) {
    Tree A = tree(tree(tree(NULL,1,NULL),2,NULL),3,tree(NULL,4,NULL));
    print(A,0);
    puts("-------");
    print(mirror(A),0);
    return 0;
}