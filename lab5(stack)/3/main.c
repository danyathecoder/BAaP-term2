/*
 * В файле записан текст, сбалансированный по круглым скобкам.
 * Требуется для каждой пары соответствующих открывающей и закрывающей
 * скобок напечатать номера их позиций в тексте,
 * упорядочив пары номеров по возрастанию номеров позиций закрывающих скобок.
 * Напимер, для текста a+(45-f(x)*(b-c)) на до напечатать 8 10, 12 16, 3 17.*/

#include <stdio.h>
#include <stdlib.h>
#include "stack_2.h"


int main() {
    FILE *f;
    char c;
    struct FILO_INT *head = NULL;
    if ((f = fopen("text.txt", "rt")) == NULL)
    {
        printf("Cannot open %s\n", "main.c");
        exit(1);
    }
    fseek(f, 0, SEEK_END);
    long len = ftell(f);
    long i = 0;
    while(i<=len){
        fseek(f, len-i-1, SEEK_SET);
        fread(&c,sizeof(char),1,f);
        if(c == ')')
            head = push_INT(head, len-i);
        i++;
    }
    indestructibleView_INT(head);
    free(head);
    return 0;
}
