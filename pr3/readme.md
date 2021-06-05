### 1 Введение

Задание:

1. Написать программу 

2. Настроить pipeline

3. Написать отчет по работе в разметке Markdown (README.md)

4. Загрузить на gitlab и убедиться, что проверка pipeline проходит успешно

5. Защитить работу у преподавателя

Задания на вторую практическую работу представлены в таблице 1.

Таблица 1 - Задания
| Номер | Используя функции, реализовать программу, которая: |
| ------------- | ------------- |
|  1  | считывает количество элементов n, 0 < n <= 2147483647;  |
| 2  | создает пустой список, считывает n элементов a, a <= 2147483647 и заносит их в список; |
|  3  | выводит содержимое списка, используя функцию print;  |
| 4 | считывает k1, k2, k3 (k <= 2147483647) и выводит "1", если в списке существует элемент с таким значением и "0", если нет (выводить через пробел, например "1 0 1"); |
|  5  | считывает m, m <= 2147483647 и вставляет его в конец списка;  |
| 6 | выводит содержимое списка, используя функцию print; |
|  7  | считывает t, t <= 2147483647 и вставляет его в начало списка;  |
| 8 | выводит содержимое списка, используя функцию print; |
|  9  | считывает j и x (0 < j <= 2147483647, x <= 2147483647) и вставляет значение x после j-ого элемента списка;  |
| 10 | выводит содержимое списка, используя функцию print;|
|  11  | считывает z, z <= 2147483647 и удаляет первый элемент (при его наличии), хранящий значение z из списка; |
| 12| выводит содержимое списка, используя функцию print; |
|  13  | очищает список;  |


### 2 Ход работы
#### 2.1 Работа с кодом
С помощью онлайн компилятора были написан код, которые представлен ниже в приложении А. Лалее представлены функции, которые реализованы в программе соотвественно заданиям.

Код функции инициализации списка init:
```с
void init(list **l)
{
    *l = (list*)malloc(sizeof(list));
    (*l)->head = NULL;
    return;
}
```

Код функции, реализующей вставку в конец списка значения, введенного с клавиатуры:
```с
int push_back(list *l, int key)
{
    if (! is_empty(l))
    {
        node *last = FindTail(l);
        node *current = malloc(sizeof(node));
        last -> next = current;
        current -> next = NULL;
        current -> value = key;
    }
    else
    {
        node *current = malloc(sizeof(node));
        current -> value = key;
        current -> next = NULL;
        l -> head = current;
    }
    return 0;
}

```
Код функции, реализующей поиск в списке чисел, введенных с клавиатуры, и выводящей 1 или 0 при нахождении или нет соотвественно:
```с
void checkingexist(node *n1, node *n2, node *n3)
{
    if(n1 == NULL)
    {
        printf("0 ");
    }
    else
    {
        printf("1 ");
    }
    if(n2 == NULL)
    {
        printf("0 ");
    }
    else
    {
        printf("1 ");
    }
    if(n3 == NULL)
    {
        printf("0 ");
    }
    else
    {
        printf("1 \n");
    }
}

```
Код функции, реализующей вставку в начало списка значения, введенного с клавиатуры:
```с

int push_front(list *l, int key)
{
    node *current;
    current = malloc(sizeof(node));
    current -> value = key;
    current -> next = l -> head;
    l -> head = current;
    return 0;
}

```
Код функции, реализующей вставку значения, введенного с клавиатуры, после обозначенного нами элемента списка:
```с
int insert_after(node *n, int key)
{
    if(n == NULL)
    {
        return 1;
    }
    node *New = malloc(sizeof(node));
    New -> value = key;
    New -> next = n -> next;
    n -> next = New;
    return 0;
}
```
Код функции, реализующей удаление значения, введенного с клавиатуры, при наличие его в списке:
```с
int remove_node(list *l, int key)
{
    node *current = l -> head;
    node *previous = NULL;
    if(l -> head == NULL)
    {
        return 1;
    }
    while(current -> value != key)
    {
        if(current -> next == NULL)
        {
            return 1;
        }
        else
        {
            previous = current;
            current = current -> next;
        }
    }
    if(current == l -> head)
    {
        l -> head = l -> head -> next;
    }
    else
    {
        previous -> next = current -> next;
    }
    free(current);
    return 0;
}
```
Код функции, реализующей очищения списка:
```с
void clean(list *l)
{
    if (! l -> head)
    {
        return;
    }
    node *current = l->head;
    node *temp;
    while (current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    l->head = NULL;
    return;
}
```
Код функции, реализующей вывод значений списка:
```с
void print(list *l)
{
    node *current = l -> head;
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
    return;
}
```
![](https://sun9-3.userapi.com/impf/Of6iVgmMWudI-5Pay5ajbtoepxvwHfJQBuVbTA/fwyzMnqY5pI.jpg?size=139x258&quality=96&sign=c98aeafcec7e4d6f5d038f039891abd0&type=album)

Рисунок 1 — Результат работы программы


#### 2.2 Настройка pipeline

Для корректной загрузки файлов на удаленный репозиторий в файле .gitlab_cy.yml нужно найти пункт stages и добавить pr3. Далее раскомментировать строки в разделе, где описываются программы третьей практической работы. На рисунке 3 представлено то, как это должно выглядеть. 

![](https://sun9-51.userapi.com/impg/IS7oFzqoD1-UuyzEN7idPswFdJxGJY2Xi1D0Yg/ZUdphS6Ogxo.jpg?size=519x465&quality=96&sign=1713f04686871ca18feddf1f289a0577&type=album)

Рисунок 3 — Настройка pipeline
#### 2.3 Работа с GitLab

После написания кодов необхожимо загрузить файлы в локальные проект, а затем загрузить их на удаленный репозиторий с помощью CLion.
После загрузки проекта он должен пройти pipeline проверку. Результаты проверки представлены на рисунке 4.


![](https://sun9-51.userapi.com/impg/fhnKADxy_ijAJX9jfLMljiCv1u_B1CU0-0HVgA/ZW3Luqm-i7U.jpg?size=427x648&quality=96&sign=8f522a299ea01122d6b8feaa30ef5428&type=album)

Рисунок 4 — Результаты pipeline-проверки

### 3 Заключение
В ходе выполнения второй практической работы была написана программа, реализующая различные действия с односвязными списками. Также программы успешно прошли pipeline проверку.
### Приложение А

```с
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
    int value; // значение, которое хранит узел
    struct node *next; // ссылка на следующий элемент списка
} node;
typedef struct list
{
    struct node *head; // начало списка
} list;
// инициализация пустого списка
void init(list **l)
{
    *l = (list*)malloc(sizeof(list));
    (*l)->head = NULL;
    return;
}
// удалить все элементы из списка
void clean(list *l)
{
    if (! l -> head)
    {
        return;
    }
    node *current = l->head;
    node *temp;
    while (current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    l->head = NULL;
    return;
}
// проверка на пустоту списка
bool is_empty(list *l)
{
    if(l -> head == NULL)
    {
        return true;
    }
    return false;
}
// поиск элемента по значению, вернуть NULL если элемент не найден
node *find(list *l, int key)
{
    node *current = l -> head;
    if(! l -> head)
    {
        return NULL;
    }
    while(current -> value != key)
    {
        current = current -> next;
        if(current == NULL)
        {
            return NULL;
        }
    }
    return current;
}
node* FindTail(list *l)
{
    if(l -> head == NULL)
    {
        return NULL;
    }
    node *current = l -> head;
    while(current -> next != NULL)
    {
        current = current -> next;
    }
    return current;
}
// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int key)
{
    if (! is_empty(l))
    {
        node *last = FindTail(l);
        node *current = malloc(sizeof(node));
        last -> next = current;
        current -> next = NULL;
        current -> value = key;
    }
    else
    {
        node *current = malloc(sizeof(node));
        current -> value = key;
        current -> next = NULL;
        l -> head = current;
    }
    return 0;
}
// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int key)
{
    node *current;
    current = malloc(sizeof(node));
    current -> value = key;
    current -> next = l -> head;
    l -> head = current;
    return 0;
}
// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(node *n, int key)
{
    if(n == NULL)
    {
        return 1;
    }
    node *New = malloc(sizeof(node));
    New -> value = key;
    New -> next = n -> next;
    n -> next = New;
    return 0;
}
// удалить первый элемент из списка с указанным значением,
// вернуть 0 если успешно
int remove_node(list *l, int key)
{
    node *current = l -> head;
    node *previous = NULL;
    if(l -> head == NULL)
    {
        return 1;
    }
    while(current -> value != key)
    {
        if(current -> next == NULL)
        {
            return 1;
        }
        else
        {
            previous = current;
            current = current -> next;
        }
    }
    if(current == l -> head)
    {
        l -> head = l -> head -> next;
    }
    else
    {
        previous -> next = current -> next;
    }
    free(current);
    return 0;
}
// вывести все значения из списка в прямом порядке через пробел,
void print(list *l)
{
    node *current = l -> head;
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
    return;
}
void checkingexist(node *n1, node *n2, node *n3)
{
    if(n1 == NULL)
    {
        printf("0 ");
    }
    else
    {
        printf("1 ");
    }
    if(n2 == NULL)
    {
        printf("0 ");
    }
    else
    {
        printf("1 ");
    }
    if(n3 == NULL)
    {
        printf("0 ");
    }
    else
    {
        printf("1 \n");
    }
}
node *findbyindex(list *l, int index)
{
    if(l -> head == NULL)
    {
        return NULL;
    }
    node *current = l -> head;
    int i = 0;
    while(i != index)
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
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int i, n, k1, k2, k3, m, t, j, x, z, a;
    (void) scanf("%d", &n);
    list *link;
    
    init(&link);
    for(i = 1; i <= n; i++)
    {
        (void) scanf("%d", &a);
        push_back(link, a);
    }
    print(link);
    (void) scanf("%d %d %d", &k1, &k2, &k3);
    node *find1 = find(link, k1);
    node *find2 = find(link, k2);
    node *find3 = find(link, k3);
    checkingexist(find1, find2, find3);
    (void)scanf("%d", &m);
    push_back(link, m);
    print(link);
    (void)scanf("%d", &t);
    push_front(link, t);
    print(link);
    (void) scanf("%d %d", &j, &x);
    node *FindNode = findbyindex(link, j - 1);
    insert_after(FindNode, x);
    print(link);
    (void) scanf("%d", &z);
    remove_node(link, z);
    print(link);
    clean(link);
    link -> head = NULL;
    return 0;
}


```


