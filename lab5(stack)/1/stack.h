//
// Created by danilapoddubny on 13/04/2020.
//

#ifndef TRAINING_STACK_H
#define TRAINING_STACK_H
struct FILO{
    int data;
    struct FILO *next;
};
struct FILO * push(struct FILO *head, int x);
void indestructibleView(struct FILO *head);
struct FILO *pop(struct FILO *head);
void maxValue(struct FILO *head);
#endif //TRAINING_STACK_H
