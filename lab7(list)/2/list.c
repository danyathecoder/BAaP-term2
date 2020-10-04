#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void push(struct FIFO **head, struct FIFO **tail, int x) {
    struct FIFO *n;
    n = (struct FIFO *)malloc(sizeof(struct FIFO));
    n -> next = NULL;
    n -> data = x;
    n -> prev = NULL;
    if (*head == NULL)
    {
        *head = n;
        *tail = n;
    }
    else
    {
        n -> prev = (*tail);
        (*tail) -> next = n;
        *tail = n;
    }

}

void view(struct FIFO *head){
    struct FIFO *p = head;
    while(p != NULL){
        printf("%5d", p->data);
        p = p->next;
    }
    printf("\n");
}

int get_pos(struct FIFO *head, int pos){
    struct FIFO *p = head;
    int i = 0;
    while(i != pos){
        p = p->next;
        i++;
    }
    return p -> data;
}

void push_pos(struct FIFO *head, int pos, int x){
    struct FIFO *p = head;
    int i = 0;
    while(i != pos){
        p = p->next;
        i++;
    }
     p -> data = x;
}

void shell(int *head, int n) // array - указатель на массив, а n - число его элементов
{
    int flg, tmp;
    for (int gap = n / 2; gap > 0; gap /= 2) //decrease gap
        do {
            flg = 0;
            for (int i = 0, j = gap; j < n; i++, j++) {
                if (get_pos(head, i) > get_pos(head, j)) //swap element if they are stand in incorrect sequence
                {
                    tmp = get_pos(head, j);
                    push_pos(head, j , get_pos(head, i));
                    push_pos(head, i, tmp);
                    flg = 1; //flag to countinue
                }
            }
        } while (flg); //if 'flag = 1' - repeat

}
