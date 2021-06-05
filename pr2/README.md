### 1 Введение

Задание:

1. Должна быть выполнена 1 практическая работа

2. Написать программы в соответствии с вариантом 

3. Настроить pipeline

4. Составить блок-схемы программ

5. Написать отчет по работе в разметке Markdown (README.md)

6. Загрузить на gitlab и убедиться, что проверка pipeline проходит успешно

7. Защитить работу у преподавателя

Задания на вторую практическую работу представлены в таблице 1.

Таблица 1 - Задания
| Номер | Задание |
| ------------- | ------------- |
|  1  | Написать программу, которая вычисляет отрицательную сумму введенной последовательности чисел.  |
| 2  | Написать программу, которая вычисляет сумму квадратов чисел, стоящих на нечетных местах в последовательности. |

### 2 Ход работы
#### 2.1 Работа с кодом
С помощью онлайн компилятора были написаны коды, которые представлены ниже.
Код для программы №1, соответствующий 4 заданию из вариантов, выглядит следующим образом:
```с
#include <stdio.h>

int main()
{
int sum=0,n,i,x;
(void)scanf("%d", &n);
for(i=1;i<=n;i++)
{
(void)scanf("%d", &x);
sum+=x*(-1);
}
printf("%d", sum);
return 0;
}
 
```

В ходе выполнения программы вводится число n, которое обозначает, сколько чисел в цикле нужно будет ввести, чтобы посчитать отрицательную сумму. Затем вводится сама числовая последовательность, и в результате выводится значение отрицательной суммы этой последовательности. Результат работы программы №1 представлен на рисунке 1.


![](https://sun9-47.userapi.com/impg/TvyB0yiwx8o951mvSPxKHKowdy9Gl1nhQyP_sg/8ric2o9Wf9U.jpg?size=411x167&quality=96&sign=32afb68a0d0a01ff48026f3ec238f670&type=album)

Рисунок 1 — Результат работы программы №1

Код для программы №2, соостветствующий 14 варианту заданий, выглядит следующим образом:
```с
#include <stdio.h>
#include <math.h>

int main()
{
int sum=0,n,i; double x;
(void)scanf("%d", &n);
for(i=1;i<=n;i++)
{
(void)scanf("%lf", &x);
if(i%2!=0)
{
sum+=pow(x,2);
}
}
printf("%d", sum);
return 0;
}
```
В ходе выполнения программы вводится число n, которое обозначает, сколько чисел в цикле нужно будет ввести. Затем вводится последовательность чисел, и те числа, которые находятся на нечетных местах в этой последовательности суммируются между собой, в конце выводится сумма этих чисел. Результат работы программы №2 представлен на рисунке 2.


![](https://sun9-63.userapi.com/impg/TMQnWQhK9QQgAECaD5KgluDtebm3HOgFYQKNjQ/3GXqN0Bg4qw.jpg?size=403x199&quality=96&sign=b47271be1ce7e0b7a36af6adc614bb65&type=album)

Рисунок 2 — Результат работы программы №2

#### 2.2 Настройка pipeline

Для корректной загрузки файлов на удаленный репозиторий в файле .gitlab_cy.yml нужно найти пункт stages и добавить pr2. Далее все места, где написано \<NN> заменить на номера программ в разделе, где описываются программы второй практической работы. На рисунке 3 представлено то, как это должно выглядеть. 

![](https://sun9-76.userapi.com/impg/hVpzz9hl8SyBYKvc3vDK8ZV5YKLY7hhaxhRH_A/JgB1Dd8nZ9Y.jpg?size=555x682&quality=96&sign=deb79425cb4e86b7c261086531f1be60&type=album)

Рисунок 3 — Настройка pipeline
#### 2.3 Работа с GitLab

После написания кодов необхожимо загрузить файлы в локальные проект, а затем загрузить их на удаленный репозиторий с помощью CLion.
После загрузки проекта он должен пройти pipeline проверку. Результаты проверки представлены на рисунке 4.



![](https://sun9-29.userapi.com/impg/PoB7Yrza8PcOScUQxRYTXs4KqDv5tvzlI-Fihw/B3blRhuh95E.jpg?size=571x606&quality=96&sign=218c81dc8fbf20aeba82f21f0c317740&type=album)

Рисунок 4 — Результаты pipeline-проверки

#### 2.4 Составление блок-схем
Также к программам были составлены блок-схемы, которые изображены на рисунках 5 и 6.



![](https://sun9-51.userapi.com/impg/5fb3grZZv0Rq25R_cynG_h0A9jXdGapkI3k9XA/PTUOerWW4Bc.jpg?size=200x501&quality=96&sign=5cdb9a744caed288d4efc60d886af2ef&type=album)

Рисунок 5 — Блок-схема программы №1

![](https://sun9-9.userapi.com/impg/sE0Eal6sxJd4G19Abz1DBG-HH-my7p49rkCudA/8JhcPozpYRU.jpg?size=281x600&quality=96&sign=b4c8c92c3518119210abbdaa8ba460de&type=album)

Рисунок 6 — Блок-схема программы №2
### 3 Заключение
В ходе выполнения второй практической работы были написаны две программы, также к ним были составлены блок-схемы. Также программы успешно прошли pipeline проверку.

