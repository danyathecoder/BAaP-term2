//
// Created by danilapoddubny on 12/03/2020.
//
#include "struct.h"
#ifndef LAB2_UNIONS__FUNC_H
#define LAB2_UNIONS__FUNC_H
void mem_check_warehouse(WAREHOUSE* arr);
int int_input(int *x);
float float_input(float *x);
char* char_input(char **str);
WAREHOUSE* struct_input(WAREHOUSE* arr, int *n);
void struct_output(WAREHOUSE* arr, int n);
void single_struct_output(WAREHOUSE* arr, int i);
int struct_find(WAREHOUSE* arr, int n);
WAREHOUSE* struct_change(WAREHOUSE* arr, int n);
WAREHOUSE* struct_delete(WAREHOUSE* arr, int *n);
WAREHOUSE* struct_bubble_sort(WAREHOUSE* arr, int n);
int menu(int amount);
#endif //LAB2_UNIONS__FUNC_H
