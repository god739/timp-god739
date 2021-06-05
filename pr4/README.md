### 1 Введение

Задание:

1. Написать программу 

2. Настроить pipeline

3. Написать отчет по работе в разметке Markdown (README.md)

4. Загрузить на gitlab и убедиться, что проверка pipeline проходит успешно

5. Защитить работу у преподавателя

Задания на четвертую практическую работу представлены в таблице 1.

Таблица 1 - Задания
| Номер | Используя функции, реализовать программу, которая: |
| ------------- | ------------- |
|  1  | считывает количество элементов n, 0 < n <= 2147483647;  |
| 2  | создает пустой список, считывает n элементов a, a <= 2147483647 и заносит их в список; |
|  3  | выводит содержимое списка, используя функцию print;  |
| 4 | считывает k1, k2, k3 (k <= 2147483647) и выводит "1", если в списке существует элемент с таким значением и "0", если нет (выводить через пробел, например "1 0 1"); |
|  5  | считывает m, m <= 2147483647 и вставляет его в конец списка;  |
| 6 | выводит содержимое списка, используя функцию print_inverse; |
|  7  | считывает t, t <= 2147483647 и вставляет его в начало списка;  |
| 8 | выводит содержимое списка, используя функцию print; |
|  9  | считывает j и x (0 < j <= 2147483647, x <= 2147483647) и вставляет значение x после j-ого элемента списка;  |
| 10 | выводит содержимое списка, используя функцию print_inverse;|
|11| считывает u и y (0 < u <= 2147483647, y <= 2147483647) и вставляет значение y перед u-ого элемента списка;|
| 12 | выводит содержимое списка, используя функцию print;|
|  13  | считывает z, z <= 2147483647 и удаляет первый элемент (при его наличии), хранящий значение z из списка; |
| 14| выводит содержимое списка, используя функцию print_inverse; |
|  15  | считывает r, r <= 2147483647 и удаляет последний элемент (при его наличии), хранящий значение r из списка; |
| 16| выводит содержимое списка, используя функцию print; |
|  17  | очищает список;  |


### 2 Ход работы
#### 2.1 Работа с кодом
С помощью онлайн компилятора были написан код, которые представлен ниже в приложении А. Лалее представлены функции, которые реализованы в программе соотвественно заданиям.


Код функции, реализующей вставку в конец списка значения, введенного с клавиатуры:
```с
int push_back(list *l, int val)
{
    tnode *lastnode = l -> tail;
    tnode *current = malloc(sizeof(tnode));
    if (l -> tail != NULL)
    {
        lastnode -> next = current;
        current -> value = val;
        current -> next = NULL;
        current -> prev = l -> tail;
        l -> tail = current;
    }
    else
    {
        current -> value = val;
        current -> next = NULL;
        current -> prev = NULL;
        l -> tail = current;
        l -> head = current;
    }
    return 0;
}

```
Код функции, реализующей поиск в списке чисел, введенных с клавиатуры:
```с
tnode *find(list *l, int val)
{
    tnode *current = l -> head;
    if(l -> head == NULL)
    {
        return NULL;
    }
    while(current -> value != val)
    {
        current = current -> next;
        if(current == NULL)
        {
            return NULL;
        }
    }
    return current;
}

```
Код функции, реализующей вставку в начало списка значения, введенного с клавиатуры:
```с
int push_front(list *l, int val)
{
    tnode *firstnode = l -> head;
    tnode *current = malloc(sizeof(tnode));
    firstnode -> prev = current;
    current -> value = val;
    current -> next = l -> head;
    current -> prev = NULL;
    l -> head = current;
    return 0;
}

```
Код функции, реализующей вставку значения, введенного с клавиатуры, после обозначенного нами элемента списка:
```с
int insert_after(list *l, tnode *n, int val)
{
    tnode *current = malloc(sizeof(tnode));
    if (n -> next == NULL) //Если n - последний узел
    {
        current -> value = val;
        current -> next = NULL;
        n -> next = current;
        current -> prev = l -> tail;
        l -> tail = current;        
    }
    else //Если n - не последний узел
    {
        tnode *nextnode = n -> next;
        current -> value = val;
        current -> next = nextnode;
        n -> next = current;
        current -> prev = n;
        nextnode -> prev = current;
    }
    return 0;
}

```
Код функции, реализующей вставку значения, введенного с клавиатуры, перед обозначенным нами элемента списка:
```с
int insert_before(list *l, tnode *n, int val)
{
    tnode *current = malloc(sizeof(tnode));
    if (n -> prev == NULL) //Если n - первый узел
    {
        current -> value = val;
        current -> next = n;
        n -> prev = current;
        current -> prev = NULL;
        l -> head = current;
    }
    else //Если n - не первый узел
    {
        tnode *prevnode = n -> prev;
        current -> value = val;
        current -> prev = prevnode;
        n -> prev = current;
        current -> next = n;
        prevnode -> next = current;
    }
    return 0;
}
```
Код функции, реализующей удаление первого элемента в списке:
```с
int remove_first(list *l, int val)
{
    tnode *current = l -> head;
    if(l -> head == NULL)
    {
        return 1;
    }
    while((current -> value != val) && (current -> next != NULL))
    {
        current = current -> next;
    }
    if(current -> value != val) return 0;
    if((l -> head == current) && (l -> tail == current)) //Если current - единственный узел
    {
        l -> head = NULL;
        l -> tail = NULL;
    }
    else if(l -> head == current) //Если current - первый узел
    {
        current -> next -> prev = NULL;
        l -> head = l -> head -> next;
    }
    else if(l -> tail == current) //Если  current - последний узел
    {
        current -> prev -> next = NULL;
        l -> tail = l -> tail -> prev;
    }
    else //Если в где-то середине
    {
        current -> next -> prev = current -> prev;
        current -> prev -> next = current -> next;
    }
    free(current);
    return 0;
}

```
Код функции, реализующей удаление последнего элемента в списке:
```с
int remove_last(list *l, int val)
{
    tnode *current = l -> tail;
    if(l -> head == NULL)
    {
        return 1;
    }
    while((current -> value != val) && (current -> prev != NULL))
    {
        current = current -> prev;
    }
    if(current -> value != val) return 0;
    if((l -> head == current) && (l -> tail == current)) //Если current - единственный узел
    {
        l -> head = NULL;
        l -> tail = NULL;
    }
    else if(l -> head == current) //Если current - первый узел
    {
        current -> next -> prev = NULL;
        l -> head = l -> head -> next;
    }
    else if(l -> tail == current) //Если  current - последний узел
    {
        current -> prev -> next = NULL;
        l -> tail = l -> tail -> prev;
    }
    else //Если в где-то середине
    {
        current -> next -> prev = current -> prev;
        current -> prev -> next = current -> next;
    }
    free(current);
    return 0;
}

```

Код функции, реализующей вывод значений списка в обратном порядке:
```с
void print_invers(list *l)
{
    tnode *current = l -> tail;
    if (current == NULL)
    {
        return;
    }
    while(current != NULL)
    {
        printf("%d ", current-> value);
        current = current -> prev;
    }
    printf("\n");
}
```

Результат работы программы, представленный на рисунке 1, соответствует ожидаемом результату, представленному на рисунке 2.


![](https://sun9-58.userapi.com/impg/XT0sgTnX74Qt8ZfkuzkPu3pd-CewcxZ8tZCRcA/qP-XIUeSjnQ.jpg?size=228x436&quality=96&sign=3c9b63bc46dfce782699bbf3fc5e6cdf&type=album)

Рисунок 1 — Результат работы программы

![](https://sun9-63.userapi.com/impg/QmhDzroGY8EuIYDHAxT1Gc9QuCuNu0C2Saz_Tw/czDR8TTP5rw.jpg?size=273x501&quality=96&sign=f606414309ae3695898372c5070f32b5&type=album)

Рисунок 2 — Ожидаемый результат работы программы

Полученные результаты совпали с ожидаемыми, следовательно, программа написана корректно.


#### 2.2 Настройка pipeline

Для корректной загрузки файлов на удаленный репозиторий в файле .gitlab_cy.yml нужно найти пункт stages и добавить pr3. Далее раскомментировать строки в разделе, где описываются программы третьей практической работы. На рисунке 3 представлено то, как это должно выглядеть. 

![](https://sun9-18.userapi.com/impg/0aLiOHXYnNrvDsaEcDGOpxB2DtJUzmFMMAZg8Q/eJIGiAU0pnw.jpg?size=401x483&quality=96&sign=240d0bcf9fc11f041679b38618028b8c&type=album)

Рисунок 3 — Настройка pipeline
#### 2.3 Работа с GitLab

После написания кодов необхожимо загрузить файлы в локальные проект, а затем загрузить их на удаленный репозиторий с помощью CLion.
После загрузки проекта он должен пройти pipeline проверку. Результаты проверки представлены на рисунке 4.


![](https://sun9-15.userapi.com/impg/gGJrGNPo87Gpe3f-Sn1U9nU0Qz6UIneDoxZXbQ/oOamDSzdWwU.jpg?size=325x359&quality=96&sign=ac0904a5adb00a8743106716a40b574d&type=album)

Рисунок 4 — Результаты pipeline-проверки

### 3 Заключение
В ходе выполнения второй практической работы была написана программа, реализующая различные действия с двухсвязными списками. Также программа успешно прошли pipeline проверку.
### Приложение А

```с
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node *next;
    struct node *prev;
}tnode;
typedef struct list {
    struct node *head;
    struct node *tail;
}list;
void init(list *l)
{
    l -> head = NULL;
    l -> tail = NULL;
}
void clean(list *l)
{
    if (l -> head == NULL)
    {
        return;
    }
    tnode *current = l->head;
    tnode *temp;
    while (current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    l -> head = NULL;
    l -> tail = NULL;
}
bool is_empty(list *l)
{
    if(l -> head == NULL)
    {
        return true;
    }
    return false;
}
tnode *find(list *l, int val)
{
    tnode *current = l -> head;
    if(l -> head == NULL)
    {
        return NULL;
    }
    while(current -> value != val)
    {
        current = current -> next;
        if(current == NULL)
        {
            return NULL;
        }
    }
    return current;
}
int push_back(list *l, int val)
{
    tnode *lastnode = l -> tail;
    tnode *current = malloc(sizeof(tnode));
    if (l -> tail != NULL)
    {
        lastnode -> next = current;
        current -> value = val;
        current -> next = NULL;
        current -> prev = l -> tail;
        l -> tail = current;
    }
    else
    {
        current -> value = val;
        current -> next = NULL;
        current -> prev = NULL;
        l -> tail = current;
        l -> head = current;
    }
    return 0;
}
int push_front(list *l, int val)
{
    tnode *firstnode = l -> head;
    tnode *current = malloc(sizeof(tnode));
    firstnode -> prev = current;
    current -> value = val;
    current -> next = l -> head;
    current -> prev = NULL;
    l -> head = current;
    return 0;
}
int insert_after(list *l, tnode *n, int val)
{
    tnode *current = malloc(sizeof(tnode));
    if (n -> next == NULL) //Если n - последний узел
    {
        current -> value = val;
        current -> next = NULL;
        n -> next = current;
        current -> prev = l -> tail;
        l -> tail = current;        
    }
    else //Если n - не последний узел
    {
        tnode *nextnode = n -> next;
        current -> value = val;
        current -> next = nextnode;
        n -> next = current;
        current -> prev = n;
        nextnode -> prev = current;
    }
    return 0;
}
int insert_before(list *l, tnode *n, int val)
{
    tnode *current = malloc(sizeof(tnode));
    if (n -> prev == NULL) //Если n - первый узел
    {
        current -> value = val;
        current -> next = n;
        n -> prev = current;
        current -> prev = NULL;
        l -> head = current;
    }
    else //Если n - не первый узел
    {
        tnode *prevnode = n -> prev;
        current -> value = val;
        current -> prev = prevnode;
        n -> prev = current;
        current -> next = n;
        prevnode -> next = current;
    }
    return 0;
}
int remove_first(list *l, int val)
{
    tnode *current = l -> head;
    if(l -> head == NULL)
    {
        return 1;
    }
    while((current -> value != val) && (current -> next != NULL))
    {
        current = current -> next;
    }
    if(current -> value != val) return 0;
    if((l -> head == current) && (l -> tail == current)) //Если current - единственный узел
    {
        l -> head = NULL;
        l -> tail = NULL;
    }
    else if(l -> head == current) //Если current - первый узел
    {
        current -> next -> prev = NULL;
        l -> head = l -> head -> next;
    }
    else if(l -> tail == current) //Если  current - последний узел
    {
        current -> prev -> next = NULL;
        l -> tail = l -> tail -> prev;
    }
    else //Если в где-то середине
    {
        current -> next -> prev = current -> prev;
        current -> prev -> next = current -> next;
    }
    free(current);
    return 0;
}
int remove_last(list *l, int val)
{
    tnode *current = l -> tail;
    if(l -> head == NULL)
    {
        return 1;
    }
    while((current -> value != val) && (current -> prev != NULL))
    {
        current = current -> prev;
    }
    if(current -> value != val) return 0;
    if((l -> head == current) && (l -> tail == current)) //Если current - единственный узел
    {
        l -> head = NULL;
        l -> tail = NULL;
    }
    else if(l -> head == current) //Если current - первый узел
    {
        current -> next -> prev = NULL;
        l -> head = l -> head -> next;
    }
    else if(l -> tail == current) //Если  current - последний узел
    {
        current -> prev -> next = NULL;
        l -> tail = l -> tail -> prev;
    }
    else //Если в где-то середине
    {
        current -> next -> prev = current -> prev;
        current -> prev -> next = current -> next;
    }
    free(current);
    return 0;
}
void print(list *l)
{
    tnode *current = l -> head;
    if (current == NULL)
    {
        return;
    }
    while(current != NULL)
    {
        printf("%d ", current-> value);
        current = current -> next;
    }
    printf("\n");
}
void print_invers(list *l)
{
    tnode *current = l -> tail;
    if (current == NULL)
    {
        return;
    }
    while(current != NULL)
    {
        printf("%d ", current-> value);
        current = current -> prev;
    }
    printf("\n");
}
tnode *find_index(list *l, int val)
{
    if(l -> head == NULL)
    {
        return NULL;
    }
    tnode *current = l -> head;
    int i = 1;
    while(i != val)
    {
        current = current -> next;
        if(current == NULL)
        {
            return NULL;
        }
        i++;
    }
    return current;
}
int main() {
    int i, n, x, y, z;
    list *l;
    l = malloc(sizeof(list));
    init(l);
    (void) scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        (void) scanf("%d", &x);
        push_back(l, x);
    }
    print(l);
    (void) scanf("%d %d %d", &x, &y, &z);
    tnode *a = find(l, x);
    if(a == NULL)
    {
        printf("0 ");
    }
    else
    {
        printf("1 ");
    }
    tnode * b = find(l, y);
    if(b == NULL)
    {
        printf("0 ");
    }
    else
    {
        printf("1 ");
    }
    tnode * c = find(l, z);
    if(c == NULL)
    {
        printf("0\n");
    }
    else
    {
        printf("1\n");
    }
    (void)scanf("%d", &x);
    push_back(l, x);
    print_invers(l);
    (void)scanf("%d", &x);
    push_front(l, x);
    print(l);
    (void)scanf("%d %d", &y, &x);
    tnode *cur1 = find_index(l, y);
    insert_after(l, cur1, x);
    print_invers(l);
    (void)scanf("%d %d", &y, &x);
    tnode *cur2 = find_index(l, y);
    insert_before(l, cur2, x);
    print(l);
    (void) scanf("%d", &x);
    remove_first(l, x);
    print_invers(l);
    (void) scanf("%d", &x);
    remove_last(l, x);
    print(l);
    clean(l);
    l -> head = NULL;
    return 0;
}





```


