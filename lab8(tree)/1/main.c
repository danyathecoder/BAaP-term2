/*Организовать функции для ввода, вывода, поиска элемента в дереве.*/
#include <stdio.h>
#include "tree.h"
int main() {
    struct tree *node = NULL;
    int i, x;
    while (scanf("%d",&i))
        push(&node, i);
    out(node, 0);
    printf("\n Enter element to find - ");
    //scanf("%d",&x);
    x = 5; //finds 5 in the tree
    find(node, x);
    return 0;
}
