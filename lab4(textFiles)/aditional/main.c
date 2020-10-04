/*
 * Даны 2 файла, в первом слова, во втором числа, которые означают порядок слова.
 * В третьем файле вывести все возможные комбинации букв в указанном слове.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *word, int i, int j){
    char tmp;
    tmp = word[i];
    word[i]=word[j];
    word[j]=tmp;
}

char* bubble(char* word, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
        for (j = size - 1; j > i; j--)
            if (word[j] < word[j - 1])
            {
                swap(word, j, j-1);
            }
}

void permutation(char* word, int size) {
    int i, j;
    FILE *F3;
    if ((F3 = fopen("F3.txt", "a+t")) == NULL)
    {
        printf("Cannot open %s\n", "F3.txt");
        exit(1);
    }
    fputs(word, F3);
    fputc('\n', F3);
    for (int i = strlen(word) - 2; i >= 0; --i){
        for (int j = strlen(word) - 1; j > i; j--) {
            if (word[j] > word[i]) {
                swap(word, i, j);
                bubble(word+1+i, size);
                fputs(word, F3);
                fputc('\n', F3);
                i = strlen(word) - 1;
                break;
            }
        }
    }
    fputc('\n', F3);
    fclose(F3);
}

void finder(){
    FILE *F1, *F2;
    char c;
    char *tmp =(char*)malloc(64*sizeof(char));
    int num, n = 0;
    long i1, i2;
    if ((F1 = fopen("F1.txt", "r+t")) == NULL)
    {
        printf("Cannot open %s\n", "F1.txt");
        exit(1);
    }
    if ((F2 = fopen("F2.txt", "r+t")) == NULL)
    {
        printf("Cannot open %s\n", "F2.txt");
        exit(1);
    }
    fseek(F2, 0, SEEK_SET);
    i1 = ftell(F1);
    while(!feof(F2)) {
        fscanf(F2, "%d", &num);
        fseek(F1,i1,SEEK_SET);
        while (!feof(F1)) {
            fread(&c,sizeof(char),1,F1);
            if(c==' '||feof(F1)||c=='\n'||c=='\0'){
                i2 = ftell(F1);
                n++;
                if(n==num){
                    fseek(F1,i1,SEEK_SET);
                    fread(tmp,sizeof(char),i2-i1, F1);
                    permutation(tmp, i2-i1-1);
                    free(tmp);
                    i1=i2;
                    break;
                }
                i1=i2;
            }
        }
    }
}

int main() {
    finder();
    return 0;
}
