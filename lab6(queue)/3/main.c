/*    5. Система состоит из двух процессоров P1 и P2, двух стеков S1 и S2 и четырёх очередей F1, F2, F3, F4.
 * В систему могут поступать запросы на выполнение задач двух приоритетов - высший (1) и низший (2).
 * Задачи сначала обрабатываются последовательно процессором P1, затем P2.
Запросы на выполнение задач высшего приоритета, поступающие из генератора задач, ставятся в очередь F1,
 а поступающие с процессора P1 - в очередь F3. Запросы на выполнение задач низшего приоритета,
 поступающие с генератора задач, ставятся в очередь F2,
 а поступающие с процессора P1 - в очередь F4. Процессор P1 обрабатывает запросы из очередей F1 и F2,
 а процессор P2 - из очередей F3 и F4. Процессор сначала
 обрабатывает задачи из очереди задач с высшим приоритетом, затем из очереди задач с низшим приоритетом. Если
 процессор выполняет задачу с низшим приоритетом и приходит запрос на выполнение задачи с высшим приоритетом,
 то выполняемая задача помещается в соответствующий процессору стек, а пришедшая задача - в процессор.
 Задача из стека возвращается в процессор, если все задачи большего приоритета обработаны.
 * */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hyper.h"
int main() {
    int i = 0;
    struct FIFO *head1 = NULL;
    struct FIFO *tail1 = NULL;
    struct FIFO *head2 = NULL;
    struct FIFO *tail2 = NULL;
    struct FIFO *head3 = NULL;
    struct FIFO *tail3 = NULL;
    struct FIFO *head4 = NULL;
    struct FIFO *tail4 = NULL;
    struct FILO *stack1 = NULL;
    struct FILO *stack2 = NULL;
    while(1){
        printf("Tick %d:\n", i);
        sleep(1);
        if(head1 != NULL && head2 != NULL){
            stack1 = push_s(head2, head2->data);
            head2 = pop_q(head2);
        }
        if(head3 != NULL && head4 != NULL){
            stack2 = push_s(head4, head4->data);
            head4 = pop_q(head4);
        }
        if(head2!=NULL && head1 == NULL){
            head2->data.complexity--;
            if (head2->data.complexity == 0)
                head2 = pop_q(head2);
        }
        if(head1 != NULL){
            head1->data.complexity--;
            if (head2->data.complexity == 0)
                head1 = pop_q(head1);
        }
        if(head4!=NULL && head3 == NULL){
            head4->data.complexity--;
            if (head4->data.complexity == 0)
                head4 = pop_q(head4);
        }
        if(head3 != NULL){
            head3->data.complexity--;
            if (head3->data.complexity == 0)
                head3 = pop_q(head3);
        }
        struct task p1 = generator();
        struct task p2 = generator();
        if(p1.priority == 1) {
            tail1 = push_q(tail1, p1);
            if(head1 == NULL)
                head1 = tail1;
            printf("Queue 1:\n");
            view(head1);
        }
        else {
            tail2 = push_q(tail2, p1);
            if(head2 == NULL)
                head2 = tail2;
            printf("Queue 2:\n");
            view(head2);
        }
        if(p2.priority == 1) {
            tail3 = push_q(tail3, p2);
            if(head3 == NULL)
                head3 = tail3;
            printf("Queue 3:\n");
            view(head3);
        }
        else{
            tail4 = push_q(tail4, p2);
            if(head4 == NULL)
                head4 = tail4;
            printf("Queue 4:\n");
            view(head4);
        }
        printf("Stack 1:\n");
        view_s(stack1);
        printf("Stack 2:\n");
        view_s(stack2);
        i++;
    }
    return 0;
}
