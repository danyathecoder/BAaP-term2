//Создать массив структур о студентах группы. О каждом студенте записать: имя, фамилию, год рождения, оценки по пяти экзаменам.
// Определить средний балл за сессию и отсортировать список по сумме баллов.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

typedef struct normal{
    int math, physics, programming, philosophy;
    int average;
} person;
int main() {
    srand(time(0));
    int n;
    printf("Enter the amount of students: ");
    scanf("%d",&n);
    person *student=(person*)malloc(n*sizeof(person));
    for(int i=0; i<n;i++){
        printf("\nStudent №%d\n",i+1);
        printf("Math mark: ");
        student[i].math=1+rand()%10;
        printf("%d\t",student[i].math);
        printf("Physics mark: ");
        student[i].physics=1+rand()%10;
        printf("%d\t",student[i].physics);
        printf("Programming mark: ");
        student[i].programming=1+rand()%10;
        printf("%d\t",student[i].programming);
        printf("Philosophy mark: ");
        student[i].philosophy=1+rand()%10;
        printf("%d\n",student[i].philosophy);
        student[i].average = (student[i].physics + student[i].philosophy + student[i].programming + student[i].math)/4;
        printf("Average mark:%d",student[i].average);
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
        {
            if (student[j].average < student[j-1].average)
                swap(&student[j].average , &student[j-1].average);
        }
    return 0;
}