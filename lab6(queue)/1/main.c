/*Создать очередь для символов. Максимальный размер очереди вводится с экрана.
 * Создать функции для ввода и вывода элементов очереди. Вводить символы с экрана.
 * В случае совпадения вводимого символа с последним элементом очереди в очередь его не  добавлять,
 * а удалять первый элемент.*/
#include <stdio.h>
#include "queue.h"
#include <stdlib.h>
int main() {
    int n;
    char c;
    struct QUEUE *head = NULL;
    struct QUEUE *tail = NULL;
    printf("Enter the max size of queue:\n");
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        fflush(stdin);
        scanf("       %c",&c);
        if(head != NULL && tail->data == c){
            head = pop(head);
            continue;
        }
        tail = push(tail, c);
        if(head == NULL)
            head = tail;
    }
    view(head);
    free(head);
    free(tail);
    return 0;
}
