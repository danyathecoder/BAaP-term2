#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "hyper.h"


struct task generator(){
    struct task p;
    srand(time(0));
    p.complexity = 10 + rand() % 30;
    p.name =  10000 + rand() % 100000;
    p.priority = 1 + rand() % 2;
    return p;
}

struct FIFO *push_q(struct FIFO *tail, struct task x){
    struct FIFO  *tmp;
    tmp = (struct FIFO *)malloc(sizeof(struct FIFO));
    tmp->data = x;
    tmp->next = NULL;
    if(tail == NULL)
        tail = tmp;
    else{
        tail->next = tmp;
        tail = tmp;
    }
    return tail;
}

void view(struct FIFO *head){
    struct FIFO *p = head;
    while(p != NULL){
        printf("Name: %d, current complexity: %d, priority: %d\n", p->data.name, p->data.complexity, p->data.priority);
        p = p -> next;
    }
}

struct FIFO* pop_q(struct FIFO *head){
    if(head != NULL){
        head = head -> next;
        return head;
    }
    else
        return NULL;
}

struct FILO *push_s(struct FILO *head, struct task x){
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

void view_s(struct FILO *head){
    struct FILO *p = head;
    while(p!=NULL){
        printf("Name: %d, current complexity: %d, priority: %d\n", p->data.name, p->data.complexity, p->data.priority);
        p = p->next;
    }
    printf("\n");
};