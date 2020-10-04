#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void push(struct tree **node, int a)
{
    struct tree *ptr;
    if (*node == NULL)  //Если дерева нет, то добавляем первый корневой элемент
    {
        *node= (struct tree *)calloc(1, sizeof(struct tree)); //Выделяем память под звено дерева
        (*node)->data = a; //Записываем данные в звено
        (*node)->left = NULL; //Подзвенья инициализируем пустотой во избежание ошибок
        (*node)->right = NULL;
    }

    else if (a < (*node)->data)   //Если нововведенный элемент x меньше чем элемент x из корня дерева, уходим влево
    {
        if ((*node)->left != NULL)
            push(&((*node)->left), a); //При помощи рекурсии помещаем элемент на свободный участок
        else //Если элемент получил свой участок, то
        {
            (*node)->left = (struct tree *)calloc(1, sizeof(struct tree));  //Выделяем память левому подзвену.
            (*node)->left->left = (*node)->left->right = NULL; //У левого подзвена будут свои левое и правое подзвенья, инициализируем их пустотой
            (*node)->left->data = a; //Записываем в левое подзвено записываемый элемент
        }
    }


    if (a > (*node)->data)   //Если нововведенный элемент x больше чем элемент x из корня дерева, уходим вправо
    {
        if ((*node)->right != NULL)
            push(&(*node)->right,a); //При помощи рекурсии заталкиваем элемент на свободный участок
        else //Если элемент получил свой участок, то
        {
            (*node)->right = (struct tree*)calloc(1, sizeof(struct tree));   //Выделяем память правому подзвену.
            (*node)->right->left = ((*node))->right->right = NULL; //У правого подзвена будут свои левое и правое подзвенья, инициализируем их пустотой
            (*node)->right->data = a; //Записываем в правое подзвено записываемый элемент
        }
    }
}


void out(struct tree *node, int g)
{
    int i;
    if(node != NULL)
    {
        out(node->right,g+5);
        for(i=0;i<g;i++)
        {
            printf(" ");
        }
        printf("%5d\n", node->data);
        out(node->left,g+5);
    }
}

struct tree *max(struct tree *node)
{
    if (node->right == NULL)
        return node;
    return max(node->right);
}