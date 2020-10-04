#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    int x;
    struct FILO *head = NULL;
    printf("Enter not number to stop\n");
    while(scanf("%d", &x)){
        head = push(head, x);
    }
    maxValue(head);
    indestructibleView(head);
    head = pop(head);
    indestructibleView(head);
    free(head);
    return 0;
}
