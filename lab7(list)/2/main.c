/*Отсортировать линейный двусвязный список методом Шелла.*/
#include <stdio.h>
#include "list.h"

int main() {
    struct FIFO *head = NULL, *tail = NULL;
    int x, n;
    printf("Enter size of list:\n");
    scanf("%d",&n);
    for(int i = 0; i<n; i++){
        scanf("%d",&x);
        push(&head, &tail, x);
        if(head == NULL)
            head = tail;
    }
    view(head);
    shell(head, n);
    view(head);
    return 0;
}
