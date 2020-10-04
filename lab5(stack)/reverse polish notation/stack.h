//
// Created by danilapoddubny on 13/04/2020.
//

#ifndef TRAINING_STACK_H
#define TRAINING_STACK_H
struct FILO_INT{
    int data_INT;
    struct FILO_INT *next_INT;
};

struct FILO_CHAR{
    char data_CHAR;
    struct FILO_CHAR *next_CHAR;
};

struct FILO_INT * push_INT(struct FILO_INT *head_INT, int x);
void indestructibleView_INT(struct FILO_INT *head_INT);
struct FILO_INT *pop_INT(struct FILO_INT *head_INT);

struct FILO_CHAR * push_CHAR(struct FILO_CHAR *head_CHAR,char x);
void indestructibleView_CHAR(struct FILO_CHAR *head_CHAR);
struct FILO_CHAR *pop_CHAR(struct FILO_CHAR *head_CHAR);
#endif //TRAINING_STACK_H
