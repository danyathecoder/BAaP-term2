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

int find_min(FILE *f)
{
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
    return min;
}

int find_max(FILE *f)
{
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
    return max;
}

void zero()
{
    FILE *f;
    int num, tmp;
    if ((f = fopen("12.bin", "w+b")) == NULL)
    {
        printf("Cannot open %s\n", "main.c");
        exit(1);
    }
    fread(&num, sizeof(int), 1, f);
    tmp = num;
    num = 0;
    fwrite(&num, sizeof(int), 1, f);
    while (1)
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
    int min = find_min(f);
    int max = find_max(f);
    printf("Sum is %d\n", min + max);
    fclose(f);
    zero();
    return 0;
}
