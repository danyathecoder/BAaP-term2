#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int isNumber(char x){
    if(x<='9'&&x>='0')
        return 1;
    else return 0;
}

int toINT(char *p, int i){
    int num = 0;
    while(isNumber(p[i])){
        num = num * 10 + p[i] - '0';
        i++;
    }
    return num;
};

int priority(char s){
    switch(s){
        case '*': return 4;
        case '/': return 3;
        case '+': return 2;
        case '-': return 1;
    }
    return 0;
}

void calculation(struct FILO_INT *head_INT, struct FILO_CHAR *head_CHAR){
     struct FILO_INT *tmp = head_INT->next_INT;
     switch(head_CHAR->data_CHAR){
         case '*':
             tmp->data_INT*= head_INT->data_INT;
             break;
         case '/':
             tmp->data_INT/= head_INT->data_INT;
             break;
         case '+':
             tmp->data_INT+= head_INT->data_INT;
             break;
         case '-':
             tmp->data_INT-= head_INT->data_INT;
             break;
     }
}

int main() {
    struct FILO_INT *head_INT = NULL;
    struct FILO_CHAR *head_CHAR = NULL;
    char *str = (char*)malloc(1024*sizeof(char));
    fgets(str, 1024 , stdin);
    int i = 0;
    while(str[i]){
        if(isNumber(str[i])){
            head_INT = push_INT(head_INT, toINT(str, i));
            while(isNumber(str[i+1])){
                i++;
            }
        }
        else
            if(!head_CHAR){
                head_CHAR = push_CHAR(head_CHAR, str[i]);
            }
            else
                switch (str[i])
                {
                    case '(':
                        head_CHAR = push_CHAR(head_CHAR, '(');
                        break;
                    default:
                        if (str[i] == ')')
                        {
                            while ((head_CHAR->data_CHAR) != '(') {
                                calculation(head_INT, head_CHAR);
                                head_INT = pop_INT(head_INT);
                                head_CHAR = pop_CHAR(head_CHAR);
                            }
                            head_CHAR = pop_CHAR(head_CHAR);
                            break;
                        }
                        if (priority(str[i]) < priority(head_CHAR->data_CHAR)) {
                            while (head_CHAR && (priority(str[i]) < priority(head_CHAR->data_CHAR))) {
                                calculation(head_INT, head_CHAR);
                                head_INT = pop_INT(head_INT);
                                head_CHAR = pop_CHAR(head_CHAR);
                            }
                            head_CHAR = push_CHAR(head_CHAR, str[i]);
                        }
                        else
                            head_CHAR = push_CHAR(head_CHAR, str[i]);
                        break;
                }
        i++;
    }
    indestructibleView_INT(head_INT);
    while (head_CHAR) {
        calculation(head_INT, head_CHAR);
        head_INT = pop_INT(head_INT);
        head_CHAR = pop_CHAR(head_CHAR);
    }
    if (!head_CHAR && head_INT->next_INT) {
        puts("ERROR. INCORRECT INPUT");
        return 0;
    }
    printf("%d", head_INT->data_INT);
    return 0;
}
