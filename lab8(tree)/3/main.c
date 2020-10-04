/*Напишите программу, содержащую функцию Create(T,n),
 * где n – положительное целое число,
 * которая строит Т – дерево, изображенное на рисунке. В программе используйте подпрограммы.*/

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    struct tree *node = NULL;
    int n;
    if(!scanf("%d",&n)||n < 1){
        printf("\nWrong input");
        exit(0);
    }
    while(n>=1) {
        push(&node,n);
        n--;
    }
    out(node, 0);
    return 0;
}