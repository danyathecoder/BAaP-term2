/*
 * Дан текстовый файл. Сделать из него html-файл, оборачивая каждый абзац в тег <p>.
 * С клавиатуры задать цвет текста.
 * Дополнительных файлов не создавать, дополнительные коллекции не использовать.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void file_init(){
    FILE *f;
    char *txt = (char*)malloc(1024*sizeof(char));
    if ((f = fopen("index.html", "w+t")) == NULL)
    {
        printf("Cannot open %s\n", "main.c");
        exit(1);
    }
    fgets(txt, 1024 , stdin);
    fputs(txt, f);
    fclose(f);
}
void file_add(){
    FILE *f;
    if ((f = fopen("index.html", "a+t")) == NULL)
    {
        printf("Cannot open %s\n", "main.c");
        exit(1);
    }
    fputs("                                                                    ", f);
    fclose(f);
};

int main() {
    //file_init();
    //file_add();
    FILE *f;
    char *color = (char*)malloc(1);
    char *c= (char*)malloc(1);
    if ((f = fopen("index.html", "r+t")) == NULL)
    {
        printf("Cannot open %s\n", "main.c");
        exit(1);
    }
    fseek(f,0,SEEK_END);
    long sizeOfFile = ftell(f);
    printf("\n%ld\n",sizeOfFile);
    fputs("<p style = 'color:",f);
    while(*color!='\n'){
     *color = getchar();
     if(*color=='\n')
         break;
     fputs(color,f);
    }
    free(color);
    fputs(";'>",f);
    long curPos = ftell(f);
    int i = 0;
    int k = 0;
    while(i < sizeOfFile){
        fseek(f,i,SEEK_SET);
        fread(c,sizeof(char),1,f);
        fseek(f,i+curPos+k,SEEK_SET);
        if(*c=='\n'){
            fputs("</p>\n ",f);
            fputs("<p style = 'color:",f);
            while(*color!='\n'){
                *color = getchar();
                k++;
                if(*color=='\n') {
                    free(color);
                    break;
                }
                fputs(color,f);
            }
            fputs(";'>",f);
            k+=25;
        }
        fwrite(c,sizeof(char),1,f);
        i++;
    }
    fseek(f,0,SEEK_END);
    fputs("</p>",f);
    fseek(f,0,SEEK_SET);
    while(sizeOfFile){
        c[0] = " ";
        fwrite(c,sizeof(char),1,f);
        sizeOfFile--;
    }
    fclose(f);
    return 0;
}
