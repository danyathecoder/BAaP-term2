/* Две днунаправленные очереди. В первой найти максимальный элемент которого нет во второй.*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    struct DEQUE *head1 = NULL;
    struct DEQUE *tail1 = NULL;
    struct DEQUE *head2 = NULL;
    struct DEQUE *tail2 = NULL;
    int x, n, m;
    printf("Enter size of queue 1:\n");
    scanf("%d",&n);
    printf("Enter size of queue 2:\n");
    scanf("%d",&m);
    for(int i = 0; i<n; i++){
        scanf("%d",&x);
        push_d(&head1, &tail1, x);
        if(head1 == NULL)
            head1 = tail1;
    }
    for(int i = 0; i < m; i++){
        scanf("%d",&x);
        push_d(&head2, &tail2, x);
        if(head2 == NULL)
            head2 = tail2;
    }
    int a = maxFinder(head1, head2);
    if(!a)
        printf("\nNo answer");
    free(head1);
    free(tail1);
    free(head2);
    free(tail2);
    return 0;
}

