/*Создать стек для символов и стек для чисел.
 * Максимальный размер стеков вводится с экрана. Создать функции для ввода и вывода элементов стека.
 * Вводить символы с экрана. Символ попадает в первый стек, а его численное представление – во второй.
 * */
#include <stdio.h>
#include <stdlib.h>
#include "stack_2.h"

int main() {
    int n;
    struct FILO_INT *head_INT = NULL;
    struct FILO_CHAR *head_CHAR = NULL;
    printf("Enter max size of stack:\n");
    scanf("%d",&n);
    char *str = (char*)malloc(n*sizeof(char));
    scanf("%s", str);
    for(int i = 0; i<n; i++){
        head_CHAR = push_CHAR(head_CHAR, str[i]);
        head_INT = push_INT(head_INT, str[i]);
    }
    indestructibleView_INT(head_INT);
    indestructibleView_CHAR(head_CHAR);
    free(head_INT);
    free(head_CHAR);
    return 0;
}
