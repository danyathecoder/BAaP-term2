#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void push(struct tree **node, int n)
{
    struct tree *ptr;
    if (*node == NULL)  //Если дерева нет, то добавляем первый корневой элемент
    {
        *node= (struct tree *)calloc(1, sizeof(struct tree)); //Выделяем память под звено дерева
        (*node)->data = n; //Записываем данные в звено
        (*node)->left = NULL; //Подзвенья инициализируем пустотой во избежание ошибок
        (*node)->right = NULL;
    }

    else if (n < (*node)->data)   //Если нововведенный элемент x меньше чем элемент x из корня дерева, уходим влево
    {
        if ((*node)->left != NULL) {
            push(&((*node)->left), n); //При помощи рекурсии помещаем элемент на свободный участок
        }
        if ((*node)->right != NULL)
            push(&(*node)->right,n); //При помощи рекурсии заталкиваем элемент на свободный участок
        else //Если элемент получил свой участок, то
        {
            (*node)->left = (struct tree *)calloc(1, sizeof(struct tree));  //Выделяем память левому подзвену.
            (*node)->left->left = (*node)->left->right = NULL; //У левого подзвена будут свои левое и правое подзвенья, инициализируем их пустотой
            (*node)->left->data = n; //Записываем в левое подзвено записываемый элемент
            (*node)->right = (struct tree*)calloc(1, sizeof(struct tree));   //Выделяем память правому подзвену.
            (*node)->right->left = ((*node))->right->right = NULL; //У правого подзвена будут свои левое и правое подзвенья, инициализируем их пустотой
            (*node)->right->data = n; //Записываем в правое подзвено записываемый элемент
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

