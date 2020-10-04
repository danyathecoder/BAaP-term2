//
// Created by danilapoddubny on 13/03/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "struct_init.h"
#define SIZE 255
void mem_check_warehouse(WAREHOUSE* arr){
    if(!arr){
        printf("Allocation memory error\n");
        exit(0);
    }
}

int int_input(int *x){
    if(!scanf("%d",&*x)||*x<0){
        printf("Wrong input. You are bad person.\n");
        rewind(stdin);
        exit(0);
    };
    return *x;
}

float float_input(float *x){
    if(!scanf("%f",&*x)){
        printf("Wrong input. You are bad person.\n");
        fflush(stdin);
        exit(0);
    };
    return *x;
}

char* char_input(char **str){
    *str = (char*)malloc(SIZE);
    return *str;
}


WAREHOUSE* struct_input(WAREHOUSE* arr, int *n){
    int fl = 0, i = 0;
    int ask;
    do{
        arr[i].name=char_input(&arr[i].name);
        printf("Enter the name of warehouse %d:\n",*n);
        scanf("%s",arr[i].name);
        fflush(stdin);


        printf("Enter amount of units:\n");
        arr[i].amount=int_input(&arr[i].amount);

        printf("Enter total cost of warehouse:\n");
        arr[i].total_cost=int_input(&arr[i].total_cost);

        printf("Enter percentage markup of warehouse:\n");
        arr[i].trade_all=float_input(&arr[i].trade_all);

        printf("Choose the type of warehouse:\n \t1 - production\n \t2 - transit\n \t3 - retailers\n  \t4 - wholesale\n  \t5 - reserve\n ");
        while(!scanf("%d",&arr[i].room)||arr[i].room<=0||arr[i].room>=6){
            printf("Wrong input, try again.\n");
            fflush(stdin);
        };

        switch(arr[i].room) {
            case 1:
                arr = prod_init(arr, i);
                break;
            case 2:
                arr = trans_init(arr, i);
                break;
            case 3:
                arr = retail_init(arr, i);
                break;
            case 4:
                arr = whole_init(arr,i);
                break;
            case 5:
                arr = res_init(arr, i);
                break;
        }
        (*n)++;
        i++;
        arr = (WAREHOUSE*)realloc(arr, ((*n)+1)*sizeof(WAREHOUSE));
        printf("\nDo you want to continue? 1 - yes/0 - no\n");
        ask = int_input(&ask);
        if(ask == 1)
            fl = 1;
        else fl = 0;
    }while(fl);
    return arr;
}

void struct_output(WAREHOUSE* arr, int n){
    printf("name of warehouse:     total cost of warehouse:     total amount of units in warehouse:     trade allowance:\n");
    for(int i=0; i<n;i++) {
        printf("%s", arr[i].name);
        printf("                            %d", arr[i].total_cost);
        printf("                            %d", arr[i].amount);
        printf("                                          %.2f", arr[i].trade_all);
        switch(arr[i].room){
            case 1:
                printf("        production type");
                printf("     country: %s", arr[i].house.w1.counrycode);
                printf("              materials: %d\n",arr[i].house.w1.materials);
                break;
            case 2:
                printf("        transition type");
                printf("     current location: %s", arr[i].house.w2.currentcounry);
                printf("     source location: %s", arr[i].house.w2.from);
                printf("     destination: %s\n", arr[i].house.w2.to);
                break;
            case 3:
                printf("        retailers' type");
                printf("     price: %.2f", arr[i].house.w3.price);
                printf("             owner's name: %s\n", arr[i].house.w3.ownername);
                break;
            case 4:
                printf("        wholesale type");
                printf("      owner's name: %s", arr[i].house.w4.ownername);
                printf("          company's name: %s\n", arr[i].house.w4.companyname);
                break;
            case 5:
                printf("        reserve type");
                printf("        volume: %d\n",arr[i].house.w5.volume);
                break;
        }
    }
    printf("\n-------------------------------------------------------------------------------\n");
}

void single_struct_output(WAREHOUSE* arr, int i){
    printf("name of warehouse: %s\n", arr[i].name);
    printf("total cost of warehouse: %d\n", arr[i].total_cost);
    printf("total amount of units in warehouse: %d\n", arr[i].amount);
    printf("trade allowance: %.2f\n", arr[i].trade_all);
    switch(arr[i].room){
        case 1:
            printf("production type\n");
            printf("country: %s\n", arr[i].house.w1.counrycode);
            printf("materials: %d\n",arr[i].house.w1.materials);
            break;
        case 2:
            printf("transition type\n");
            printf("current location: %s\n", arr[i].house.w2.currentcounry);
            printf("source location: %s\n", arr[i].house.w2.from);
            printf("destination: %s\n", arr[i].house.w2.to);
            break;
        case 3:
            printf("retailers' type\n");
            break;
        case 4:
            printf("wholesale type\n");
            break;
        case 5:
            printf("reserve type\n");
            printf("volume: %d",arr[i].house.w5.volume);
            break;
    }
}

int struct_find(WAREHOUSE* arr, int n){
    int p, x;
    float f;
    char* str;
    int tmp;
    str = char_input(&str);
    printf("Choose parameter:\n \t 1 - name \n \t 2 - total cost \n \t 3 - amount \n \t 4 - trade allowance\n");
    while(!scanf("%d",&p)||p<0||p>=5) {
        fflush(stdin);
        printf("Again.");
    }
    printf("find: ");
    switch (p) {
        case 1:
            scanf("%s", str);
            for(int i=0; i<n;i++) {
                if (strstr(arr[i].name, str)) {
                    single_struct_output(arr, i);
                    tmp = i;
                }
            }
            break;
        case 2:
            scanf("%d",&x);
            for(int i=0; i<n;i++) {
                if (arr[i].total_cost == x) {
                    single_struct_output(arr, i);
                    tmp = i;
                }
            }
            break;
        case 3:
            scanf("%d",&x);
            for(int i=0; i<n;i++) {
                if (arr[i].amount == x) {
                    single_struct_output(arr, i);
                    tmp = i;
                }
            }
            break;
        case 4:
            scanf("%f",&f);
            for(int i=0; i<n;i++) {
                if (arr[i].trade_all == f) {
                    single_struct_output(arr, i);
                    tmp = i;
                }
            }
            break;
    }
    return tmp;
}

WAREHOUSE* struct_change(WAREHOUSE* arr, int n){
    int i, f;
    char strtmp[SIZE];
    i = struct_find(arr, n);
    printf("Choose field to change:\n \t 1 - name \n \t 2 - total cost \n \t 3 - amount \n \t 4 - trade allowance\n ");
    while(!scanf("%d",&f)||f<0||f>=5) {
        fflush(stdin);
        printf("Again.");
    }
    switch (f){
        case 1:
            printf("Enter new name of warehouse %d:\n",i);
            scanf("%s",strtmp);
            strcpy(arr[i].name, strtmp);
            break;
        case 2:
            printf("Enter new amount of units:\n");
            arr[i].amount=int_input(&arr[i].amount);
            break;
        case 3:
            printf("Enter new total cost of warehouse:\n");
            arr[i].total_cost=int_input(&arr[i].total_cost);
            break;
        case 4:
            printf("Enter new percentage markup of warehouse:\n");
            arr[i].trade_all=float_input(&arr[i].trade_all);
            break;
    }
    return arr;
}

WAREHOUSE* struct_delete(WAREHOUSE* arr, int *n){
    int x;
    x = struct_find(arr, *n);
    for(int i=x;i<(*n);i++){
        arr[i]=arr[i+1];
    }
    (*n)--;
    return arr;
}

WAREHOUSE* struct_bubble_sort(WAREHOUSE* arr, int n){
    int p;
    printf("choose parameter to sort:\n\t1 - total cost\n\t2 - amount\n\t3 - trade allowance\n");
    p=int_input(&p);
    WAREHOUSE tmp;
    switch(p) {
        case 1:
            for (int i = 0; i < n - 1; i++)
                for (int j = n - 1; j > i; j--) {
                    if (arr[j].total_cost < arr[j - 1].total_cost) {
                        tmp = arr[j];
                        arr[j] = arr[j - 1];
                        arr[j - 1] = tmp;
                    }
                }
            break;
        case 2:
            for (int i = 0; i < n - 1; i++)
                for (int j = n - 1; j > i; j--) {
                    if (arr[j].amount < arr[j - 1].amount) {
                        tmp = arr[j];
                        arr[j] = arr[j - 1];
                        arr[j - 1] = tmp;
                    }
                }
            break;
        case 3:
            for (int i = 0; i < n - 1; i++)
                for (int j = n - 1; j > i; j--) {
                    if (arr[j].trade_all < arr[j - 1].trade_all) {
                        tmp = arr[j];
                        arr[j] = arr[j - 1];
                        arr[j - 1] = tmp;
                    }
                }
            break;
    }
    return arr;
}

int menu(int amount){
    int n;
    if(amount<=0) {
        printf("You haven't any structures, please, create almost one structure\n");
        n = 1;
    }
    else{
        printf("0 - exit\n");
        printf("1 - input\n");
        printf("2 - output\n");
        printf("3 - change structure\n");
        printf("4 - find structure by parametrs\n");
        printf("5 - delete structure\n");
        printf("6 - sorting structure\n");

        scanf("%d", &n);
    }
    return n;
}


