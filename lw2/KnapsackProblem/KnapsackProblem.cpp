#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

// �������� (�������� � ������� `v`)
// ���� (�������� � ������� `w`)
// ����� ���������� ��������� ��������� `n`
// ����������� ������� `W`
int knapsack(int v[], int w[], int n, int W, unordered_map<string, int> lookup)
{
    // ������� �������: ������������� �������
    if (W < 0) {
        return INT_MIN;
    }

    // ������� ������: ��������� �� �������� ��� ����������� ���������� ������ 0
    if (n < 0 || W == 0) {
        return 0;
    }

    // ������� ���������� ���� ����� �� ������������ ��������� �����
    string key = to_string(n) + "|" + to_string(W);

    // ���� ��������� ������� �������, ������ �� �
    // ��������� ��������� �� �����
    if (lookup.find(key) == lookup.end())
    {
        // ������ 1. �������� ������� ������� `v[n]` � ������ � ��������� ���
        // ���������� �������� `n-1` � ����������� ������������ `W-w[n]`
        int include = v[n] + knapsack(v, w, n - 1, W - w[n], lookup);

        // ������ 2. ��������� ������� ������� `v[n]` �� ������� � ��������� ���
        // ���������� �������� `n-1`
        int exclude = knapsack(v, w, n - 1, W, lookup);

        // ��������� ������������ ��������, ������� �� ��������, ������� ��� �������� ������� �������
        lookup[key] = max(include, exclude);
    }

    // ���������� ������� ������� ���������
    return lookup[key];
}

// 0�1 ������ � �������
int main()
{
    vector <size_t> V;
    // ����: ����� ���������, ������ �� ����� ����� � ���������
    int v[] = { 20, 5, 10, 40, 15, 25 };
    int w[] = { 1, 2, 3, 8, 7, 4 };

    // ����������� �������
    int W = 10;

    // ����� ���������� ���������
    int n = sizeof(v) / sizeof(v[0]);

    // ������� ����� ��� �������� ������� ���������
    unordered_map<string, int> lookup;

    cout << "Knapsack value is " << knapsack(v, w, n - 1, W, lookup);

    return 0;
}