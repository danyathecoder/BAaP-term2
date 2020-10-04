/*
    1. С клавиатуры заполнить файл целыми числами.
    2. Найти сумму минимального и максимального элементов.
    3. Занулить элементы по следующему принципу: начальный элемент, затем сдвинуться на
    столько элементов вправо, какое значение было
    указано в ячейке до зануления, занулить  элемент в новой позиции и так далее, пока УТПФ находиться
    в перделах файла и не указывает на нулевой элемент
*/
#include <stdio.h>
#include <stdlib.h>

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

int find_min()
{
    FILE *f;
    if ((f = fopen("12.bin", "r+b")) == NULL)
    {
        printf("Cannot open %s\n", "12.c");
        exit(1);
    }
    int min, tmp;
    rewind(f);
    fread(&min, sizeof(int), 1, f);
    if (feof(f))
        exit(1);
    while (1)
    {
        fread(&tmp, sizeof(int), 1, f);
        if (feof(f))
            break;
        if (tmp < min)
            min = tmp;
    }
    printf("\nMinimal number is %d\n", min);
    fclose(f);
    return min;
}

int find_max()
{
    FILE *f;
    if ((f = fopen("12.bin", "r+b")) == NULL)
    {
        printf("Cannot open %s\n", "12.c");
        exit(1);
    }
    int max, tmp;
    rewind(f);
    fread(&max, sizeof(int), 1, f);
    if (feof(f))
        exit(1);
    while (1)
    {
        fread(&tmp, sizeof(int), 1, f);
        if (feof(f))
            break;
        if (tmp > max)
            max = tmp;
    }
    printf("Maximal number is %d\n", max);
    fclose(f);
    return max;
}

void zero(int n)
{
    FILE *f;
    int num, tmp, i = 0;
    if ((f = fopen("12.bin", "r+b")) == NULL)
    {
        printf("Cannot open %s\n", "12.c");
        exit(1);
    }
    fread(&num, sizeof(int), 1, f);
    fseek(f, -1*(int)sizeof(int), SEEK_CUR);
    tmp = num;
    num = 0;
    fwrite(&num, sizeof(int), 1, f);
    fseek(f, -1*(int)sizeof(int), SEEK_CUR);
    while (i<n)
    {
        fseek(f, tmp * sizeof(int), SEEK_CUR);
        fread(&num, sizeof(int), 1, f);
        if (feof(f) || num == 0)
            break;
        fseek(f, -1*(int)sizeof(int), SEEK_CUR);
        tmp = num;
        num = 0;
        fwrite(&num, sizeof(int), 1, f);
        fseek(f, -1*(int)sizeof(int), SEEK_CUR);
        i++;
    }
    output(f);
    fclose(f);
}

int main()
{
    FILE *f;
    int n, num;
    if ((f = fopen("12.bin", "w+b")) == NULL)
    {
        printf("Cannot open %s\n", "main.c");
        exit(1);
    }

    printf("Enter the amount of numbers :\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        fwrite(&num, sizeof(int), 1, f);
    }
    output(f);
    fclose(f);
    int min = find_min(f);
    int max = find_max(f);
    printf("Sum is %d\n", min + max);
    zero(n);
    return 0;
}
