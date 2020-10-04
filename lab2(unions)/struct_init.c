//
// Created by danilapoddubny on 13/03/2020.
//
#include <stdio.h>
#include "struct.h"
#include "func.h"
WAREHOUSE* prod_init(WAREHOUSE* arr, int i){
    printf("Enter code of country:\n");
    arr[i].house.w1.counrycode = char_input(&arr[i].house.w1.counrycode);
    scanf("%s",arr[i].house.w1.counrycode);

    printf("Enter amount of materials in warehouse:\n");
    arr[i].house.w1.materials = int_input(&arr[i].house.w1.materials);

    return arr;
}

WAREHOUSE* trans_init(WAREHOUSE* arr, int i){
    printf("Enter code of current location:\n");
    arr[i].house.w2.currentcounry  = char_input(&arr[i].house.w2.currentcounry);
    scanf("%s",arr[i].house.w2.currentcounry);

    printf("Enter code of source location:\n");
    arr[i].house.w2.from  = char_input(&arr[i].house.w2.from);
    scanf("%s",arr[i].house.w2.from);

    arr[i].house.w2.to =  char_input(&arr[i].house.w2.from);
    printf("Enter code of destination:\n");
    scanf("%s",arr[i].house.w2.to);

    return arr;
}

WAREHOUSE* retail_init(WAREHOUSE* arr, int i){
    printf("Enter price:\n");
    scanf("%d",&arr[i].house.w3.price);

    arr[i].house.w3.ownername=char_input(&arr[i].house.w3.ownername);
    printf("Enter name of warehouse's owner:\n");
    scanf("%s",arr[i].house.w3.ownername);

    return arr;
}

WAREHOUSE* whole_init(WAREHOUSE* arr, int i){
    arr[i].house.w4.ownername = char_input(&arr[i].house.w4.ownername);
    printf("Enter name of warehouse's owner:\n");
    scanf("%s",arr[i].house.w4.ownername);

    arr[i].house.w4.companyname = char_input(&arr[i].house.w4.companyname);
    printf("Enter company name:\n");
    scanf("%s",arr[i].house.w4.companyname);

    return arr;
}

WAREHOUSE* res_init(WAREHOUSE* arr, int i){
    printf("Enter price:\n");
    scanf("%d",&arr[i].house.w5.volume);

    return arr;
}
