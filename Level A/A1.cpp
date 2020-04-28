/*
Ссылка на задачу: https://codeforces.com/problemset/problem/1325/A

Комментарий: Задача на внимательность чтения условия.

В описании задачи задана нижняя граница для "a" и "b" единицей включительно.
Это позволяет воспользоваться свойствами НОД и НОК для единицы.

НОК любого числа и единицы всегда равен этому числу.
НОД любого числа и единицы всегда равен единице.

Нам требуется найти такие "a" и "b", сумма НОД и НОК которых равна принимаемому на вход "x".
Используя лазейку в условии, нам достаточно выводить "1" и "x - 1".

Замечание: Также эта задача решается с помощью алгоритма Евклида и перебора, но уложиться в ограниченное время не получится.
Студенты, начавшие сразу реализовывать способ, который первый пришел в голову, в конце поймут,
что стоит сначала хорошо проанализировать условие, так как оно может подсказать более рациональное решение.
Это покажет студенту, что к решению каждой задачи нужно подходить индивидуально, и не бросаться сразу реализовывать общий алгоритм.

Примеры:
1)
    x = 25,
    НОД(1, 24) = 1,
    НОК(1, 24) = 24,
    a = 1, b = 24.
2)
    x = 2,
    НОД(1, 2) = 1,
    НОК(1, 1) = 1,
    a = 1, b = 1.

Одна из реализаций:
*/

#include <iostream>

int main()
{
    int t(0);
    std::cin >> t;
    while (t--)
    {
        int x(0);
        std::cin >> x;
        printf("1 %d\n", x - 1);
    }
    return 0;
}