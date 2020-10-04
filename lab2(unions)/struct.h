//
// Created by danilapoddubny on 07/03/2020.
//

#ifndef LAB2_UNIONS__STRUCT_H
#define LAB2_UNIONS__STRUCT_H
enum type{
    production, transit, retailers, wholesale, reserve
};

typedef struct {
    char *counrycode;
    int materials;
} PROD;


typedef struct {
    char *currentcounry;
    char *from;
    char *to;
} TRANS;

typedef struct {
    float price;
    char *ownername;
} RETAIL;

typedef struct {
    char *ownername;
    char *companyname;
} WHOLE;

typedef struct {
    int volume;
} RES;

union BUILD{
    PROD w1;
    TRANS w2;
    RETAIL w3;
    WHOLE w4;
    RES w5;

};

typedef struct {
    char *name;
    int total_cost;
    int amount;
    float trade_all;
    int room;
    union BUILD house;
} WAREHOUSE;

#endif //LAB2_UNIONS__STRUCT_H
