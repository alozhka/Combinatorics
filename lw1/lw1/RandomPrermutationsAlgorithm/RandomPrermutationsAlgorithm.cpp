#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main()
{
    vector<size_t> v;
    size_t random_deep, rand_num, max;
    setlocale(LC_ALL, "rus");
    srand(1);

    cout << "������� ���������� ����� � ��������� ������������������: ";
    cin >> max;
    cout << endl;
    cout << "������� ���������� ������� �����������: ";
    cin >> random_deep;
    cout << endl;

    for (int i = 0; i <= max ; i++) // �������������
    {
        v.push_back(i);
    }

    for (int i = 0; i <= random_deep; i++)
    {
        for (int j = 1; j <= max; j++)
        {
            rand_num = rand() % (max + 1);  // ���� ������ � ������ ������� � ������� �������� � �������
            swap(v[j], v[rand_num]);
        }
    }
    copy(v.begin() + 1, v.end(), ostream_iterator<size_t>(cout, " "));
    cout << endl;

    return 0;
}
