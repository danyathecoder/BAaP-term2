/*
 * Implement functions for stack based on dynamic array:
 * 1. creating stack
 * 2. viewing elements of stack
 * 3. delete one element of stack
 * 4. delete stack
 * */


#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int size;
}FILO;

void push(FILO *head, int x, int i){
    if(head->size != MAXSIZE){
        head->data[i] = x;
    }
}

void indestructibleView(FILO head){
    int tmp = head.size;
    while(tmp){
        printf("%5d", head.data[tmp-1]);
        tmp--;
    }
    printf("\n");
};

void pop(FILO *head){
    if (head->size != 0){
        head->size--;
    }
};

int main() {
    int x;
    FILO head;
    printf("Enter amount of elements in stack:\n");
    scanf("%d",&head.size);
    for(int i = 0; i < head.size; i++){
        scanf("%d", &x);
        push(&head, x, i);
    }
    indestructibleView(head);
    pop(&head);
    indestructibleView(head);
    return 0;
}
