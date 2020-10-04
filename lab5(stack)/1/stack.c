#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct FILO * push(struct FILO *head, int x){
    struct FILO *new;
    new = (struct FILO *)malloc(sizeof(struct FILO));
    new->next = NULL;
    new->data = x;
    if(head == NULL){
        head = new;
    }
    else{
        new->next = head;
        head = new;
    }
    return head;
}

void indestructibleView(struct FILO *head){
    struct FILO *p = head;
    while(p!=NULL){
        printf("%5d", p->data);
        p = p->next;
    }
    printf("\n");
};

struct FILO *pop(struct FILO *head){
    if (head != NULL){
        head = head->next;
        return head;
    }
    else return NULL;
};

void maxValue(struct FILO *head){
    struct FILO *p = head;
    int max = head->data;
    while(p!=NULL){
        if(p->data > max){
            max = p->data;
        }
        p = p->next;
    }
    printf("Max value is %d\n",max);
};