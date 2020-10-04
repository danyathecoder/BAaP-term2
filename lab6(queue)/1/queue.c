#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct QUEUE* push(struct QUEUE *tail, char x){
    struct QUEUE *tmp;
    tmp = (struct QUEUE*)malloc(sizeof(struct QUEUE));
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

struct QUEUE* pop(struct QUEUE *head){
    if(head != NULL){
        head = head -> next;
        return head;
    }
    else
        return NULL;
}

void view(struct QUEUE *head){
    struct QUEUE *p = head;
    while(p != NULL){
        printf("%5c", p->data);
        p = p -> next;
    }
}

void push_d(struct DEQUE **head, struct DEQUE **tail, int x){
    struct DEQUE *tmp = (struct DEQUE*)malloc(sizeof(struct DEQUE));
    tmp->data = x;
    tmp->next = NULL;
    tmp->prev = NULL;
    if(*head == NULL) {
        *tail = tmp;
        *head = tmp;
    }
    else{
        (*tail)->next = tmp;
        tmp -> prev = *tail;
        *tail = tmp;
    }
}

void pop_d(struct DEQUE **head, struct DEQUE **tail){
    if(*head != NULL){
        *head = (*head) -> next;
        (*head) -> prev = NULL;
    }
    else
        *tail = NULL;
}

void view_d(struct DEQUE *tail){
    struct DEQUE *p = tail;
    while(p != NULL){
        printf("%5d", p->data);
        p = p -> prev;
    }
}