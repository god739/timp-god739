## Отчет по практической работе №6

### 1 Введение
Целью данной практической работы является получение практических навыков по работе с бинарными деревьями, для этого нужно реализовать обходы деревьев.

Задания на практическую работу находятся в таблице 1.

Таблица 1 - Задания

| Номер | Задание |
| ------------- | ------------- |
| 1| Должны быть выполнены предыдущие работы |
|2 | Прочитать про односвязные списки на СИ |
|3| Написать программу |
|4| Настроить pipeline |
|5| Написать отчет по работе в разметке Markdown (README.md)|
|6| Залить на gitlab и убедиться, что pipeline проходит успешно|
|7| Защитить работу у преподавателя|

## 2 Ход работы
### 2.1 Работа с программой

Бинарное дерево — это иерархическая структура данных, в которой каждый узел имеет значение и ссылки на левого и правого потомка. Узел, находящийся на самом верхнем уровне называется корнем. Узлы, не имеющие потомков называются листьями.

Также бинарное дерево обладает дополнительными свойствами: значение левого потомка меньше значения родителя, а значение правого потомка больше значения родителя для каждого узла дерева.

Для начала необходимо создать структуру tree, а также объявить прототипы функций, код которых представлен ниже.

```c
struct tree
{
	struct tree* right;
	struct tree* left;
	int data;
};
int deep(struct tree* t);
int insert(struct tree* t, int value);
void init(struct tree** t, int value);
int print_width(struct tree* t);
}

``` 
Функция main обычно управляет выполнением программы, вызывая другие ее функции. Как правило, выполнение программы завершается в конце данной функции. Функция main реализована во всех трех программах, которые представлены в приложениях А,Б и В, будет отличаться только название функции вывода обхода дерева.

Код этой функции представлен ниже для обхода в ширину.

```c

	void prnt(node * n, int lvl, int deep){

    if (lvl == deep)
    {
        if(n != NULL)
            printf("%d ", n->value);
    }
    else if (n != NULL)
    {
        prnt(n->left, lvl + 1, deep);
        prnt(n->right, lvl + 1, deep);
    }
    else
    {
        prnt(n, lvl + 1, deep);
        prnt(n, lvl + 1, deep);
    }
}

void width(struct node * n)
{
    int m = deep(n, 0);
    for (int i = 1; i <= m; i++)
    {
        prnt(n, 1, i);
    }
}

```
Ниже представлен код функции, реализующий обратный обход по бинарному дереву:
```c
int print_reverse(struct tree* t)
{
	if(t==NULL)
	return;
	print_reverse(t->left);
	print_reverse(t->right);
	printf("%d ",t->data);
}
```
На Ниже представлен код функции, реализующий прямой обход по бинарному дереву:
```c
int print_direct(struct tree* t)
{
	struct tree* current[7];
	int i = 0;
	current[0] = t;
	printf("%d", (int)current[i]->data);
	while (1)
	{
		while (1)//запись до конца
		{
			while ((current[i]->left) != NULL)
			{
			current[i + 1] = current[i]->left;
			i++;
			printf(" %d", (int)current[i]->data);
			}
			if ((current[i]->right) != NULL)
			{
			current[i + 1] = current[i]->right;
			i++;
			printf(" %d", (int)current[i]->data);
			}
			else
			break;
		}
		while ((i != 0) && ((current[i - 1]->right) == current[i]))
		i--;
		if (i == 0)
		break;
		while (i != 0)
		{
		if ((current[i - 1]->right) != NULL)
		{
		current[i] = current[i - 1]->right;
		printf(" %d", (int)current[i]->data);
		break;
		}
		else
		{
		i--;
		if (i == 0)
		return 0;
		}
	}
}
return 0;
```
На рисунках 1-3 преставлены результаты работы программ соответственно. Программы работают без каких-либо ошибок и соответствуют желаемому результату. 

![](https://sun9-43.userapi.com/impg/fporNgsokk-Ld3x1lrT06lPj3OEITNyblgqdTQ/VKQjF8lgw9s.jpg?size=439x138&quality=96&sign=890c8ea471d7375a40bdd877bdb96738&type=album)

Рисунок 1 — Пример работы программы первой программы.

![](https://sun9-23.userapi.com/impg/CyO3HkzqcbHXmGfFTMsYKmXtUBRpNTzraMiRKQ/YPemoJ7-uig.jpg?size=412x119&quality=96&sign=ad8005b63fece3c4866f98a3fa4ad676&type=album)

Рисунок 2 — Пример работы программы второй программы.

![](https://sun9-59.userapi.com/impg/M6yXaZnkOAmM_sgy0m6PWKWHruHn0-FgLGz6Mw/UjhtS3CgpgU.jpg?size=434x125&quality=96&sign=a693d672f43edd8fc784214f2c296ae6&type=album)

Рисунок 3 — Пример работы программы третьей программы.

Из рисунков видно, что результат соответствувет данным

#### 2.2 Настройка pipeline
Для корректной загрузки файлов на удаленный репозиторий в файле .gitlab_cy.yml наужно найти пункт stages и добавить pr6. Далее нужно убрать комментарии, чтобы все работало. На рисунке 4 представлено то, как это должно выглядеть.

![](https://sun9-42.userapi.com/impg/HYvcS69XX4_H0z-ABk3iQh8MklMYdd0CbZTLBA/BwB3lHX-_PU.jpg?size=299x336&quality=96&sign=260697e8d97c9e94727e7b2284848246&type=album)

Рисунок 4 - Настройка pipeline


#### 2.3 Работа с GitLab

Далее, внесем последние изменения в наш локальный проект и передадим его в GitLab. 
После загрузки проекта он должен пройти pipeline проверку. 

Результаты проверки представлены на рисунке 5.

![](https://sun9-5.userapi.com/impg/SCdj5pT5bIZuSqxUWDsKCMsDJYF0x7wj_aMJkQ/PAeoRGO0v1I.jpg?size=209x241&quality=96&sign=064b2a986ca7474f4e9c04e5e932a78a&type=album)

Рисунок 5 — Результаты pipeline-проверки


### 3 Заключение

В результате выполнения лабораторной работы были достигнуты поставленные цели и решины необходимые задачи. Получены практические навыки работы с указателями, бинарными деревьями и динамической памятью. В частности написаны функции для работы с бинарным деревом. Реализованы обходы деревьев: прямой, обратный и в ширину.


## Приложение А

(обязательное)

Листининг кода  прямого обхода

```c
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct tree
{
	struct tree* right;
	struct tree* left;
	int data;
};
int insert(struct tree* t, int value);
void init(struct tree** t, int value);
int print_direct(struct tree* t);

int main()
{
	struct tree* t;

	int value;

	int i;

	scanf("%d", &value);

	init(&t, value);

	for (i = 0; i < 6; i++)
	{
		scanf("%d", &value);
		insert(t, value);
	}

	print_direct(t);

	return 1;
}

int insert(struct tree* t, int value)
{
	if (t->data == value)
		return 1;
	if (value > (t->data))
	{
		if ((t->right) != NULL)
			return(insert(t->right, value));
		else
		{
			t->right = (struct tree*)malloc(sizeof(struct tree));

			t->right->right = NULL;

			t->right->left = NULL;

			t->right->data = value;

			return 0;
		}
	}
	else
	{
		if ((t->left) != NULL)

			return(insert(t->left, value));

		else

		{
			t->left = (struct tree*)malloc(sizeof(struct tree));

			t->left->right = NULL;

			t->left->left = NULL;

			t->left->data = value;

			return 0;
		}
	}
}
void init(struct tree** t, int value)
{
	*t = (struct tree*)malloc(sizeof(struct tree));

	(*t)->right = NULL;

	(*t)->left = NULL;

	(*t)->data = value;

}
int print_direct(struct tree* t)
{
	struct tree* current[7];
	int i = 0;
	current[0] = t;
	printf("%d", (int)current[i]->data);
	while (1)
	{
		while (1)//запись до конца
		{
			while ((current[i]->left) != NULL)
			{
			current[i + 1] = current[i]->left;
			i++;
			printf(" %d", (int)current[i]->data);
			}
			if ((current[i]->right) != NULL)
			{
			current[i + 1] = current[i]->right;
			i++;
			printf(" %d", (int)current[i]->data);
			}
			else
			break;
		}
		while ((i != 0) && ((current[i - 1]->right) == current[i]))
		i--;
		if (i == 0)
		break;
		while (i != 0)
		{
		if ((current[i - 1]->right) != NULL)
		{
		current[i] = current[i - 1]->right;
		printf(" %d", (int)current[i]->data);
		break;
		}
		else
		{
		i--;
		if (i == 0)
		return 0;
		}
	}
}
return 0;
}
```

## Приложение Б

(обязательное)

Листининг кода  обратного обхода

```c
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct tree
{
	struct tree* right;

	struct tree* left;

	int data;

};
int print_reverse(struct tree* t);
void init(struct tree** t, int value);
int insert(struct tree* t, int value);

int main()
{
	struct tree* t;

	int value;

	int i;

	scanf("%d", &value);

	init(&t, value);

	for (i = 0; i < 6; i++)
	{
		scanf("%d", &value);
		insert(t, value);
	}

	print_reverse(t);

	return 1;

}

int insert(struct tree* t, int value)
{
	if (t->data == value)

		return 1;

	if (value > (t->data))
	{
		if ((t->right) != NULL)

			return(insert(t->right, value));

		else
		{
			t->right = (struct tree*)malloc(sizeof(struct tree));

			t->right->right = NULL;

			t->right->left = NULL;

			t->right->data = value;

			return 0;
		}
	}
	else
	{
		if ((t->left) != NULL)
			return(insert(t->left, value));
		else
		{
			t->left = (struct tree*)malloc(sizeof(struct tree));

			t->left->right = NULL;

			t->left->left = NULL;

			t->left->data = value;

			return 0;
		}
	}
}

void init(struct tree** t, int value)
{
	*t = (struct tree*)malloc(sizeof(struct tree));

	(*t)->right = NULL;

	(*t)->left = NULL;

	(*t)->data = value;
}


int print_reverse(struct tree* t)
{
	if(t==NULL)
	return;
	print_reverse(t->left);
	print_reverse(t->right);
	printf("%d ",t->data);
}
```
## Приложение В

(обязательное)

Листининг кода обхода в ширину

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *parent; 
    struct node *left;  
    struct node *right;
} node;
typedef struct tree {
    struct node *root;
    int count;
} tree;

void init(tree* t)
{
    t -> root = NULL;
    t -> count = 0;
}


node *find(tree* t, int value)
{
    node * current;
    current = t->root;

    if (t->root == NULL)
    {
        return NULL;
    }
    while (current != NULL)
    {
        if (current->value == value)
        {
            return current;
        }
        else if (value > current->value)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    return NULL;
}


int insert(tree* t, int value)
{
    struct node *current,*last_n = NULL;

    node* check = find(t, value);
    if (check != NULL)
    {
        return 1;
    }
    current = t->root;

    while(current!=NULL)
    {
        last_n = current;
        if(value > current -> value)
            current = current->right;
        else
            current = current->left;
    }
    current = malloc(sizeof *current);
    if (current != NULL)
    {
        current->value= value;
        current->left = NULL;
        current->right = NULL;
        current->parent = last_n;
        if(last_n != NULL)
        {
            if(current -> value < last_n -> value)
                last_n -> left = current;
            else
                last_n -> right = current;
        }

        if(t->count == 0)
        {
            t -> root = current;
        }
        t->count++;
        return 0;
    }
    else  //не удалось выделить память для нового элемента
    {
        return 2;
    }
}

int deep(node * n, int deep){
    if (n == NULL){
        return deep;
    }
    int d1 = deep(n->left, deep + 1);
    int d2 = deep(n->right, deep + 1);

    if (d1 > d2)
        return d1;
    else return d2;
}

void prnt(node * n, int lvl, int deep){

    if (lvl == deep)
    {
        if(n != NULL)
            printf("%d ", n->value);
    }
    else if (n != NULL)
    {
        prnt(n->left, lvl + 1, deep);
        prnt(n->right, lvl + 1, deep);
    }
    else
    {
        prnt(n, lvl + 1, deep);
        prnt(n, lvl + 1, deep);
    }
}

void width(struct node * n)
{
    int m = deep(n, 0);
    for (int i = 1; i <= m; i++)
    {
        prnt(n, 1, i);
    }
}

int main() {
    tree * t = malloc(sizeof(tree));
    init(t);

    for (int i = 0; i < 7; i++)
    {
        int x;
        scanf("%d", &x);
        insert(t, x);
    }
    node *n = t->root;
    width(n);
    return 0;
}
```
