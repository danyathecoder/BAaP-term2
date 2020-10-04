#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    struct DEQUE *head = NULL;
    struct DEQUE *tail = NULL;
    int x;
    while(scanf("%d",&x)){
        push_d(&head, &tail, x);
        if(head == NULL)
            head = tail;
    }
    view_d(tail);
    printf("\n");
    pop_d(&head, &tail);
    view(head);
    free(head);
    free(tail);
    return 0;
}
