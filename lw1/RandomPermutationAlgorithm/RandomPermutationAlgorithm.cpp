#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    vector<size_t> v;
    size_t random_deep, rand_num, max;
    setlocale(LC_ALL, "rus");
    srand(1);

    cout << "Введите количество чисел в рандомной последовательности: ";
    cin >> max;
    cout << endl;
    cout << "Введите глубину перетасовки: ";
    cin >> random_deep;
    cout << endl;

    for (int i = 0; i <= max; i++) // инициализация
    {
        v.push_back(i);
    }

    for (int i = 0; i <= random_deep; i++)
    {
        for (int j = 1; j <= max; j++)
        {
            rand_num = rand() % (max + 1);  // берём рандом и меняем местами с текущей позицией в векторе
            swap(v[j], v[rand_num]);
        }
    }
    copy(v.begin() + 1, v.end(), ostream_iterator<size_t>(cout, " "));
    cout << endl;

    return 0;
}
