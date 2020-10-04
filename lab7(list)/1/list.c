#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void push(struct FIFO **tail, int x){
    struct FIFO *n;
    n = (struct FIFO*)malloc(sizeof(struct FIFO));
    n -> next = NULL;
    n -> data = x;
    if(*tail == NULL){
        *tail = n;
    }
    else{
        (*tail)->next = n;
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

void sum15(struct FIFO *head){
    struct FIFO *p = head;
    int sum = 0;
    while(p != NULL){
        if(p -> data >= 15){
            sum += p->data;
        }
        p = p->next;
    }
    printf("%d",sum);
    printf("\n");
}

struct FIFO* pop(int x, struct FIFO *head)
{
    struct FIFO* tmp = head;
    struct FIFO* p = NULL;

    if (head == NULL)
        return NULL;
    while (tmp && tmp->data != x)
    {
        p = tmp;
        tmp = tmp->next;
    }
    if (tmp == head)
    {
        free(head);
        return tmp->next;
    }
    if (!tmp)
        return head;
    p->next = tmp->next;
    free(tmp);
    return head;
}


void find5(struct FIFO *head){
    struct FIFO *p = head;
    while(p != NULL){
        if(p -> data <= 5){
            p = pop(p->data, head);
        }
        p = p->next;
    }
}