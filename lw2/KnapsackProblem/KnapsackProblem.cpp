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

// 0�1 ������ � �������
int main()
{
    /**
    * n - ���������� ���������
    * S - ������������ ���������
    * T - ������������ ���
    */
    size_t n, S, T;
    setlocale(LC_ALL, "rus");

    cout << "������� ���������� ���������, ������������ ��������� � ������������ ���: ";
    cin >> n >> S >> T;
    vector <item> v(n);
    for (int i = 0; i < n; i++)
    {
        cout << "\n������� ��� � ��������� " << i + 1 << " ��������: ";
        cin >> v[i].weight >> v[i].cost;
    }

    knapsack(v, S, T);

    return 0;
}