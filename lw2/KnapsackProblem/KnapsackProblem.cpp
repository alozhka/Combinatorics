#include <iostream>
#include <vector>
using namespace std;

struct item
{
    size_t weight, cost;
};

void knapsack(vector<item> &v, size_t max_cost, size_t max_weight)
{

}

// 0–1 Задача о рюкзаке
int main()
{
    /**
    * n - количество элементов
    * S - максимальную стоимость
    * T - максимальный вес
    */ 
    size_t n, S, T;
    setlocale(LC_ALL, "rus");

    cout << "Введите количество элементов, максимальную стоимость и максимальный вес: ";
    cin >> n >> S >> T;
    vector <item> v(n);
    for (int i = 0; i < n; i++)
    {
        cout << "\nВведите вес и стоимость " << i + 1 << " элемента: ";
        cin >> v[i].weight >> v[i].cost;
    }

    knapsack(v, S, T);

    return 0;
}