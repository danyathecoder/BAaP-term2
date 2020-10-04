//создать бинарный файл и отсортироовать вставками
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void output(FILE *f)
{
    rewind(f);
    while (1)
    {
        int num;
        fread(&num, sizeof(int), 1, f);
        if (feof(f))
            break;
        printf("%5d", num);
    }
    printf("\n");
}

int main()
{
    FILE *f;
    int n;
    srand(time(0));
    if ((f = fopen("main.bin", "wb")) == NULL)
    {
        printf("Cannot open %s\n", "main.c");
        exit(1);
    }

    printf("Enter the amount of numbers to sort:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num = 1 + rand() % 100;
        fwrite(&num, sizeof(int), 1, f);
    }
    fclose(f);
    if ((f = fopen("main.bin", "r+b")) == NULL)
    {
        printf("Cannot open %s\n", "main.c");
        exit(1);
    }
    output(f);
    fclose(f);
    return 0;
}
