## ОТЧЕТ ПО ПРАКТИЧЕСКОЙ РАБОТЕ №5

### 1 Введение
Задания на пятую практическую работу представлены в таблице 1.

Таблица 1 - Задания
| Номер | Задание |
| ------------- | ------------- |
|  1  | Должны быть выполнены предыдущие работы.  |
| 2 | Написать программу.|
| 3 | Настроить pipeline.|
| 4 | Написать отчет по работе в разметке Markdown (README.md).|
| 5 | Залить на gitlab и убедиться, что pipeline проходит успешно.|
| 6 | Защитить работу у преподавателя.|


Алгоритм выполнения программы:  

1. Создает пустое дерево, считывает 4 элемента ai, |ai| <= 2147483647 и заносит их в дерево;
2. Выводит дерево (используя функцию print_tree) и пустую строку;
3. Считывает 3 элемента ai, |ai| <= 2147483647 и заносит их в дерево;
4. Выводит дерево и пустую строку;
5. Считывает m1, |m1| <= 2147483647 и ищет элемент с заданным значением в дереве; выводит через пробел значение предка и потомков найденного элемента, если нет значений предка или потомков вывести "_" вместо таких значений; вывести "-", если элемент не найден; вывести пустую строку;
6. Считывает m2, |m2| <= 2147483647 и ищет элемент с заданным значением в дереве; выводит через пробел значение предка и потомков найденного элемента, если нет значений предка или потомков вывести "_" вместо таких значений; вывести "-", если элемент не найден; вывести пустую строку;
7. Считывает m3, |m3| <= 2147483647 и удаляет из дерева элемент с заданным значением (если такой элемент есть);
8. Выводит дерево и пустую строку;
9. Выполняет левый поворот дерева относительно корня, пока это возможно;
10. Выводит дерево и пустую строку;
11. Выполняет правый поворот дерева относительно корня, пока это возможно;
12. Выводит дерево и пустую строку;
13. Выводит на экран количество элементов в дереве и пустую строку;
14. Очищает дерево
15. Выводит дерево и пустую строку;


### 2 Ход работы
#### 2.1 Работа с программой

Код функции, которая удаляет все элементы из дерева, выглядит следущим образом:
```c
void clean(struct Tree *t)
{
if (t != NULL)
{
if (t->Right != NULL)
clean(t->Right);
if (t->Left != NULL)
clean(t->Left);
free(t);
}
}
```

Код функции, которая осуществляет поиск элемента по значению, выглядит следущим образом:
```c
struct Tree* find(struct Tree *t, int value)
{
if (t->Data==value)
return t;
else
{
if (value < t->Data)
{
if (t->Left != NULL)
return(find(t->Left, value));
else
return NULL;
}
else
{
if (t->Right != NULL)
return(find(t->Right, value));
else
return NULL;
}
}
}
```
Код функции, которая вставляет значение в дерево, выглядит следущим образом:
```c
int insert(struct Tree *t, int value)
{
if (t->Data == 2147483648)
{
t->Data = value;
return 0;
}
if (t->Data == value)
return 1;
if (value > (t->Data))
{
if ((t->Right)!=NULL)
return(insert(t->Right, value));
else
{
t->Right=(struct Tree *)malloc(sizeof(struct Tree));
t->Right->Right = NULL;
t->Right->Left = NULL;
t->Right->Data = value;
return 0;
}
}
else
{
if ((t->Left) != NULL)
return(insert(t->Left, value));
else
{
t->Left = (struct Tree *)malloc(sizeof(struct Tree));
t->Left->Right = NULL;
t->Left->Left = NULL;
t->Left->Data = value;
return 0;
}
}
}
```
Код функции, которая удаляет элемент из дерева, выглядит следущим образом:
```c
int remove_node(struct Tree **t, int value)
{
if ((*t)->Data == value)
{
if ((*t)->Right != NULL)
{
struct Tree *Temp = (*t)->Right, *Temp2;
if (Temp->Left != NULL)
{
while (Temp->Left->Left != NULL)
Temp = Temp->Left;
(*t)->Data = Temp->Left->Data;
Temp2=Temp->Left;
Temp->Left=Temp2->Right;
free(Temp2);
}
else
{
struct Tree *Temp;
(*t)->Data = (*t)->Right->Data;
Temp = (*t)->Right;
(*t)->Right = (*t)->Right->Right;
free(Temp);
}
}
else
{
struct Tree *Temp;
Temp = (*t);
(*t) = (*t)->Left;
free(Temp);
Temp = NULL;
}
return 0;
}
else
{
if (value < ((*t)->Data))
{
if ((*t)->Left != NULL)
return(remove_node(&((*t)->Left), value));
else
return 1;
}
else
{
if (((*t)->Right) != NULL)
return(remove_node(&((*t)->Right), value));
else
return 1;
}
}
}
```
Код функции, которая удаляет минимальный элемент из поддерева, выглядит следущим образом:
```c
int remove_min(struct Tree *t)
{
struct Tree *Temp = t, *Temp2;
if (Temp->Left != NULL)
{
while (Temp->Left->Left != NULL)
Temp = Temp->Left;
Temp2 = Temp->Left;
Temp->Left = Temp2->Right;
free(Temp2);
}
else
{
Temp = t->Right;
free(t);
t = Temp;
}
return 0;
}
```
Код функции, которая выполняет правое вращение поддерева, выглядит следущим образом:
```c
int rotate_right(struct Tree **t)
{
if (*t == NULL)
return 1;
struct Tree *A, *B, *C=(*t)->Right, *x=(*t)->Left, *y=(*t), 
*Temp = (struct Tree *)malloc(sizeof(struct Tree));
if (x != NULL)
{
A = x->Left;
B = x->Right;
}
else
return 1;
Temp->Right = y;
Temp->Left = A;
Temp->Right->Right = C;
Temp->Right->Left = B;
Temp->Data = x->Data;
free(x);
(*t) = Temp;
return 0;
}
}
```
Код функции, которая выполняет левое вращение поддерева, выглядит следущим образом:
```c
int rotate_left(struct Tree **t)
{
if (*t == NULL)
return 1;
struct Tree *A = (*t)->Left, *B, *C, *x =
(*t), *y = (*t)->Right,
*Temp=(struct Tree *)malloc(sizeof(struct Tree));
if (y != NULL)
{
B = y->Left;
C = y->Right;
}
else
return 1;
Temp->Right = C;
Temp->Left = x;
Temp->Left->Right = B;
Temp->Left->Left = A;
Temp->Data = y->Data;
free(y);
(*t) =Temp;
return 0;
}
```

Полный код программы находиться в приложении А.

В таблице 2 представлены значения для проверки кода, которые нужно проверить в своей программе.

Таблица 2 - Проверочные входные и выходные данные:
|Input|Output|
|-|-|
|2 1 3 2| 2 |
||1 3|
|0 4 5|2|
|| 1 3|
||0_ _4|
||_ _ _ _ _ _ _5|
|3| 2_4 |
|6|-|
|2|3|
||14|
||0_ _5|
||5|
||4 _ |
||3_ _ _|
||1_ _ _ _ _|
||0_ _ _ _ _ _ _ _|
||0|
|| _ 1 |
|| _ _ _ 3|
|| _ _ _ _ _ 4|
|| _ _ _ _ _ _ _ _ 5|
||5|
||-|

При вводе этих данных, программа выдает ожидаемый результат из этого следует, что программа работает корректно.

Результат работы программы представлен на рисунке 1.


![](https://sun9-11.userapi.com/impg/qudEk6wtlEe652zvD2fZh_usBxRHg0IJRrWzmA/Dk6rvY-82fg.jpg?size=278x730&quality=96&sign=75a17af5776422a00cb5d7be5f46e9c8&type=album)

Рисунок 1 — Результат работы программы.

#### 2.2 Настройка pipeline

Для корректной загрузки файлов на удаленный репозиторий в файле .gitlab_cy.yml наужно найти пункт stages и добавить pr5. Далее нужно убрать комментарии, чтобы все работало. На рисунке 2 представлено то, как это должно выглядеть.

![](https://sun9-37.userapi.com/impg/7FyQHyEhVszfNx0o4i_VKJKf5JJlLGoJdqbt-A/YDN-jOy71YQ.jpg?size=451x238&quality=96&sign=5517bbca253703956852d93ba5188ee9&type=album)

Рисунок 2 - Настройка pipeline

#### 2.3 Работа с GitLab

Далее, внесем последние изменения в наш локальный проект и передадим его в GitLab. 
После загрузки проекта он должен пройти pipeline проверку. 

Результаты проверки представлены на рисунке 3.

![](https://sun9-28.userapi.com/impg/QgzDye_MZfDV70Q9vNeQNNi0vj-NoRyC_gVp5A/ZB_6Ps7UZw4.jpg?size=324x273&quality=96&sign=952e5f7690c3b3071314e27fc24f2420&type=album)

Рисунок 3 — Результаты pipeline-проверки




### 3 Заключение
В процессе выполнения практической работы были изучены принципы работы с деревьями в языке программирования C, а также были изучены некоторые функции для работы с таким деревом.


### Приложение A
(обязательное)

Листининг кода программы
```c
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct Tree
{
struct Tree *Right;
struct Tree *Left;
double Data;
};
void init(struct Tree **t)
{
*t = (struct Tree *)malloc(sizeof(struct Tree));
(*t)->Right = NULL;
(*t)->Left = NULL;
(*t)->Data = 2147483648;
}
void clean(struct Tree *t)
{
if (t != NULL)
{
if (t->Right != NULL)
clean(t->Right);
if (t->Left != NULL)
clean(t->Left);
free(t);
}
}
struct Tree* find(struct Tree *t, int value)
{
if (t->Data==value)
return t;
else
{
if (value < t->Data)
{
if (t->Left != NULL)
return(find(t->Left, value));
else
return NULL;
}
else
{
if (t->Right != NULL)
return(find(t->Right, value));
else
return NULL;
}
}
}
int find_with_output(struct Tree *t, int value)
{
if (t->Data == value)
{
printf("_ ");
if (t->Left != NULL)
printf("%d ", (int)t->Left->Data);
else
printf("_ ");
if (t->Right != NULL)
printf("%d", (int)t->Right->Data);
else
printf("_");
}
else
{
if (value < t->Data)
{
if (t->Left != NULL)
{
if (t->Left->Data == value)
{
printf("%d ", (int)t->Data);
if ((t->Left->Left) != NULL)
printf("%d ", (int)t->Left->Left->Data);
else
printf("_ ");
if ((t->Left->Right) != NULL)
printf("%d", (int)t->Left->Right->Data);
else
printf("_");
}
else
return(find_with_output(t->Left, value));
}
else
return 1;
}
else
{
if (t->Right != NULL)
{
if (t->Right->Data == value)
{
printf("%d ", (int)t->Data);
if ((t->Right->Left) != NULL)
printf("%d ", (int)t->Right->Left->Data);
else
printf("_ ");
if ((t->Right->Right) != NULL)
printf("%d", (int)t->Right->Right->Data);
else
printf("_");
}
else
return(find_with_output(t->Right, value));
}
else
return 1;
}
}
return 0;
}
int insert(struct Tree *t, int value)
{
if (t->Data == 2147483648)
{
t->Data = value;
return 0;
}
if (t->Data == value)
return 1;
if (value > (t->Data))
{
if ((t->Right)!=NULL)
return(insert(t->Right, value));
else
{
t->Right=(struct Tree *)malloc(sizeof(struct Tree));
t->Right->Right = NULL;
t->Right->Left = NULL;
t->Right->Data = value;
return 0;
}
}
else
{
if ((t->Left) != NULL)
return(insert(t->Left, value));
else
{
t->Left = (struct Tree *)malloc(sizeof(struct Tree));
t->Left->Right = NULL;
t->Left->Left = NULL;
t->Left->Data = value;
return 0;
}
}
}
int deep(struct Tree *t)
{
int r=0, l=0;
if ((t->Right) != NULL)
r=deep(t->Right);
if ((t->Left) != NULL)
l = deep(t->Left);
if (r > l)
return (r+1);
return (l+1);
}
int remove_node(struct Tree **t, int value)
{
if ((*t)->Data == value)
{
if ((*t)->Right != NULL)
{
struct Tree *Temp = (*t)->Right, *Temp2;
if (Temp->Left != NULL)
{
while (Temp->Left->Left != NULL)
Temp = Temp->Left;
(*t)->Data = Temp->Left->Data;
Temp2=Temp->Left;
Temp->Left=Temp2->Right;
free(Temp2);
}
else
{
struct Tree *Temp;
(*t)->Data = (*t)->Right->Data;
Temp = (*t)->Right;
(*t)->Right = (*t)->Right->Right;
free(Temp);
}
}
else
{
struct Tree *Temp;
Temp = (*t);
(*t) = (*t)->Left;
free(Temp);
Temp = NULL;
}
return 0;
}
else
{
if (value < ((*t)->Data))
{
if ((*t)->Left != NULL)
return(remove_node(&((*t)->Left), value));
else
return 1;
}
else
{
if (((*t)->Right) != NULL)
return(remove_node(&((*t)->Right), value));
else
return 1;
}
}
}
int remove_min(struct Tree *t)
{
struct Tree *Temp = t, *Temp2;
if (Temp->Left != NULL)
{
while (Temp->Left->Left != NULL)
Temp = Temp->Left;
Temp2 = Temp->Left;
Temp->Left = Temp2->Right;
free(Temp2);
}
else
{
Temp = t->Right;
free(t);
t = Temp;
}
return 0;
}
int rotate_right(struct Tree **t)
{
if (*t == NULL)
return 1;
struct Tree *A, *B, *C=(*t)->Right, *x=(*t)->Left, *y=(*t), *Temp = (struct Tree *)malloc(sizeof(struct Tree));
if (x != NULL)
{
A = x->Left;
B = x->Right;
}
else
return 1;
Temp->Right = y;
Temp->Left = A;
Temp->Right->Right = C;
Temp->Right->Left = B;
Temp->Data = x->Data;
free(x);
(*t) = Temp;
return 0;
}
int rotate_left(struct Tree **t)
{
if (*t == NULL)
return 1;
struct Tree *A = (*t)->Left, *B, *C, *x = (*t), *y = (*t)->Right,
*Temp=(struct Tree *)malloc(sizeof(struct Tree));
if (y != NULL)
{
B = y->Left;
C = y->Right;
}
else
return 1;
Temp->Right = C;
Temp->Left = x;
Temp->Left->Right = B;
Temp->Left->Left = A;
Temp->Data = y->Data;
free(y);
(*t) = Temp;
return 0;
}
int print_tree(struct Tree *t)
{
if (t == NULL)
{
printf("-\n");
return 1;
}
struct Tree *Temp=t;
int Rang=0, i, j, k, sk;
int *comb;
Rang = deep(t);
comb = (int*)malloc(sizeof(int));
for (i = 0; i < Rang; i++)
{
if (i != 0)
{
comb = (int*)realloc(comb, i* sizeof(int));
for (j = 0; j < i; j++)
comb[j] = 0;
}
j = 1;
sk = i;
while (sk != 0)
{
j = j * 2;
sk--;
}
while (j != 0)
{
k = 0;
Temp = t;
for (k = 0; k < i; k++)
{
if (comb[k] == 0)
{
if ((Temp->Left) != NULL)
Temp = Temp->Left;
else
{
k = -1;
break;
}
}
else
{
if ((Temp->Right) != NULL)
Temp = Temp->Right;
else
{
k = -1;
break;
}
}
}
if (i != 0)
{
sk=i-1;
comb[sk]++;
while (1)
{
if (comb[sk] == 2)
{
comb[sk] = 0;
sk--;
if (sk < 0)
break;
else
comb[sk]++;
}
else
break;
}
}
if (k==-1)
printf("_");
else
printf("%d", (int)Temp->Data);
j--;
if (j != 0)
printf(" ");
}
printf("\n");
}
return 1;
}
int all(struct Tree *t)
{
if (t == NULL)
return 0;
int r, l;
l = all(t->Left);
r = all(t->Right);
return (l + r+1);
}
int main()
{
struct Tree *t;
int i;
double a;
init(&t);//1 пункт
for (i = 0; i < 4; i++)
{
scanf("%lf", &a);
insert(t, a);
}
print_tree(t);//2 пункт
printf("\n");
for (i = 0; i < 3; i++)//3 пункт
{
scanf("%lf", &a);
insert(t, a);
}
print_tree(t);//4 пункт
printf("\n");
for (i = 0; i < 2; i++)
{
scanf("%lf", &a);//5 и 6 пункт
a = find_with_output(t, a);
if (a == 1)
printf("-");
printf("\n\n");
}
scanf("%lf", &a);//7 пункт
remove_node(&t, a);
print_tree(t);//8 пункт
printf("\n");
while (1)//9 пункт
{
a=rotate_left(&t);
if (a == 1)
break;
}
print_tree(t);//10 пункт
printf("\n");
while (1)//11 пункт
{
a = rotate_right(&t);
if (a == 1)
break;
}
print_tree(t);//12 пункт
printf("\n");
printf("%d\n\n", all(t));//13 пункт
clean(t);//14 пункт
t = NULL;
print_tree(t);//15 пункт
return 0;
}
```
