#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct QUEUE* push(struct QUEUE *tail, int x){
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
        printf("%5d", p->data);
        p = p -> next;
    }
}

int maximum(struct DEQUE *head, int num){
    struct DEQUE *p = head;
    while(p != NULL){
        if(num < p->data)
            return 0;
        p = p -> next;
    }
    return 1;
}

int maxFinder(struct DEQUE *head1, struct DEQUE *head2){
    struct DEQUE *p1 = head1;
    struct DEQUE *p2 = head2;
    while(p1 != NULL){
        int u = 1;
        while(p2 != NULL){
            if(p1->data == p2->data){
                u = 0;
                break;
            }
            p2 = p2 -> next;
        }
        if(u == 0)
            p1 = p1 ->next;
        else{
            if(maximum(p1, p1->data)){
                printf("%d", p1->data);
                return 1;
            }
            else p1 = p1 ->next;
        }
    }
    return 0;
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