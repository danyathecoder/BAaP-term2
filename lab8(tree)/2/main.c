/*Создайте программой числовое двоичное дерево.
 * Опишите функцию, которая находит наибольший элемент непустого дерева. В программе используйте подпрограммы.*/
#include <stdio.h>
#include "tree.h"

int main() {
    struct tree *node = NULL;
    int i, x;
    while (scanf("%d",&i))
        push(&node, i);
    out(node, 0);
    printf("\n Maximium - %d", max(node)->data);
    return 0;
}
