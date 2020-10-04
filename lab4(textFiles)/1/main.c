/*
 * Дан текстовый файл F1.  Создать новый текстовый файл, в него
 * записать на отдельных строках все подстроки из файла F1,
 * заключенные в кавычки. При перезапуске программы данные
 * в файл F2 должны записаться в конец.
 * */
#include <stdio.h>
#include <stdlib.h>

void F1_init(){
    FILE *F1;
    char *txt = (char*)malloc(1024*sizeof(char));
    if ((F1 = fopen("F1.txt", "w+t")) == NULL)
    {
        printf("Cannot open %s\n", "main.c");
        exit(1);
    }
    fgets(txt, 1024 , stdin);
    fputs(txt, F1);
    fclose(F1);
}

void solution(){
    FILE *F1, *F2;
    char c;
    long i1 = 0, i2 = 0;
    if ((F1 = fopen("F1.txt", "r+t")) == NULL)
    {
        printf("Cannot open %s\n", "main.c");
        exit(1);
    }
    if ((F2 = fopen("F2.txt", "a+t")) == NULL)
    {
        printf("Cannot open %s\n", "main.c");
        exit(1);
    }
    while(1) {
        fread(&c, sizeof(char), 1, F1);
        if (feof(F1))
            break;
        if(c =='"'&& i1 != 0){
            i2 = ftell(F1);
            fseek(F1, i1, SEEK_SET);
            while(i1<i2){
                fread(&c, sizeof(char), 1, F1);
                fwrite(&c, sizeof(char), 1, F2);
                i2--;
            }
            fseek(F1, 0, SEEK_CUR);
            i1 = 0;
            i2 = 0;
            continue;
        }
        if(c =='"'&& i2 == 0){
            i1 = ftell(F1);
        }
    }
    fclose(F1);
}

int main() {
    F1_init();
    solution();
    return 0;
}
