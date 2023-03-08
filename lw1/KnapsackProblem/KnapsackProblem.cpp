#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct item
{
    string name = "";
    size_t weight = 0, cost = 0;
};

void knapsack(vector<item>& v, size_t max_cost, size_t max_weight)
{
    set<string> allItems, viewedItems;

    for (auto& item : v)
    {
        allItems.insert(item.name);
    }

    for (int i = 0; i <= v.size(); i++)
    {
        if (viewedItems != allItems)
        {

        }
    }
}


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
        cout << "\nВведите название, вес и стоимость " << i + 1 << " элемента: ";
        cin >> v[i].name >> v[i].weight >> v[i].cost;
    }

    knapsack(v, S, T);

    return 0;
}