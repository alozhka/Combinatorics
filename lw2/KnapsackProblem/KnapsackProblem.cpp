#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

// Значения (хранятся в массиве `v`)
// Веса (хранятся в массиве `w`)
// Общее количество различных элементов `n`
// Вместимость рюкзака `W`
int knapsack(int v[], int w[], int n, int W, unordered_map<string, int> lookup)
{
    // базовый вариант: отрицательная емкость
    if (W < 0) {
        return INT_MIN;
    }

    // базовый случай: элементов не осталось или вместимость становится равной 0
    if (n < 0 || W == 0) {
        return 0;
    }

    // создаем уникальный ключ карты из динамических элементов ввода
    string key = to_string(n) + "|" + to_string(W);

    // если подзадача видится впервые, решаем ее и
    // сохраняем результат на карту
    if (lookup.find(key) == lookup.end())
    {
        // Случай 1. Включить текущий предмет `v[n]` в рюкзак и повторить для
        // оставшиеся элементы `n-1` с уменьшенной вместимостью `W-w[n]`
        int include = v[n] + knapsack(v, w, n - 1, W - w[n], lookup);

        // Случай 2. Исключить текущий предмет `v[n]` из рюкзака и повторить для
        // оставшиеся элементы `n-1`
        int exclude = knapsack(v, w, n - 1, W, lookup);

        // присвоить максимальное значение, которое мы получаем, включая или исключая текущий элемент
        lookup[key] = max(include, exclude);
    }

    // возвращаем решение текущей подзадачи
    return lookup[key];
}

// 0–1 Задача о рюкзаке
int main()
{
    vector <size_t> V;
    // ввод: набор элементов, каждый со своим весом и значением
    int v[] = { 20, 5, 10, 40, 15, 25 };
    int w[] = { 1, 2, 3, 8, 7, 4 };

    // вместимость рюкзака
    int W = 10;

    // общее количество предметов
    int n = sizeof(v) / sizeof(v[0]);

    // создаем карту для хранения решений подзадачи
    unordered_map<string, int> lookup;

    cout << "Knapsack value is " << knapsack(v, w, n - 1, W, lookup);

    return 0;
}