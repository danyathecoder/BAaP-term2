/*Создать линейный однонаправленный список из целых чисел.
 * Определить сумму элементов списка со значениями больше либо равными 15.
 * Удалить из списка все значения, которые меньше 5.*/
#include <stdio.h>
#include "list.h"

int main() {
    int x;
    struct FIFO *head, *tail;
    head = NULL;
    tail = NULL;

    while(scanf("%d",&x)){
       push(&tail, x);
       if(head == NULL)
           head = tail;
    }
    printf("\n");
    view(head);
    sum15(head);
    find5(head);
    view(head);
    return 0;
}
