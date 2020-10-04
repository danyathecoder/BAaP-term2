/*
 * Implement functions:
 * 1. creating stack
 * 2. viewing elements of stack
 * 3. delete one element of stack
 * 4. delete stack
 * */


#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    int x;
    struct FILO *head = NULL;
    while(scanf("%d", &x)){
        head = push(head, x);
    }
    indestructibleView(head);
    head = pop(head);
    indestructibleView(head);
    free(head);
    return 0;
}
