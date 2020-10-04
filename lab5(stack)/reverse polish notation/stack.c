#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct FILO_INT *push_INT(struct FILO_INT *head_INT, int x){
    struct FILO_INT *new;
    new = (struct FILO_INT *)malloc(sizeof(struct FILO_INT));
    new->next_INT = NULL;
    new->data_INT = x;
    if(head_INT == NULL){
        head_INT = new;
    }
    else{
        new->next_INT = head_INT;
        head_INT = new;
    }
    return head_INT;
}

void indestructibleView_INT(struct FILO_INT *head_INT){
    struct FILO_INT *p = head_INT;
    while(p!=NULL){
        printf("%5d", p->data_INT);
        p = p->next_INT;
    }
    printf("\n");
};

struct FILO_INT *pop_INT(struct FILO_INT *head_INT){
    if (head_INT != NULL){
        head_INT = head_INT->next_INT;
        return head_INT;
    }
    else return NULL;
};


struct FILO_CHAR *push_CHAR(struct FILO_CHAR *head_CHAR,char x){
    struct FILO_CHAR *new;
    new = (struct FILO_CHAR *)malloc(sizeof(struct FILO_CHAR));
    new->next_CHAR = NULL;
    new->data_CHAR = x;
    if(head_CHAR == NULL){
        head_CHAR = new;
    }
    else{
        new->next_CHAR = head_CHAR;
        head_CHAR = new;
    }
    return head_CHAR;
}

void indestructibleView_CHAR(struct FILO_CHAR *head_CHAR){
    struct FILO_CHAR *p = head_CHAR;
    while(p!=NULL){
        printf("%5с", p->data_CHAR);
        p = p->next_CHAR;
    }
    printf("\n");
};

struct FILO_CHAR *pop_CHAR(struct FILO_CHAR *head_CHAR){
    if (head_CHAR != NULL){
        head_CHAR = head_CHAR->next_CHAR;
        return head_CHAR;
    }
    else return NULL;
};