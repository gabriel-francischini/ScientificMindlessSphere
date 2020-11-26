#include <stdio.h>
#include <stdlib.h>

// tipos e funções definidos na Questão 2

Tree make(int v[], int i, int j) {
    if( i>j ) return NULL;
    int m = (i+j)/2;
    return tree(make(v,  ,  ),v[m],make(v,  ,  ));
}

int main(void) {
    int v[7] = {10,20,30,40,50,60,70};
    Tree A = make(v,0,6);
    print(A,0);
    return 0;
}