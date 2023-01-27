#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

size_t findMinIndex(vector<size_t> &v)
{
    size_t indexmin = 0, min = v[0];

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < min)
        {
            min = v[i];
            indexmin = i;
        }
    }

    return indexmin;
}

void createPermutation(vector<size_t> &v)
{
    do
    {
        copy(v.begin(), v.end(), ostream_iterator<size_t>(cout, " "));
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
}

void splitLastIndexes(vector<size_t> &v, size_t currentIndex)
{
    size_t sum = 0;
    for (auto &n : v)
        sum += n;
}

void createCompositions(size_t size)
{
    vector<size_t> v;
    size_t curr = 0;
    bool isFirst = true;

    // инициализация
    for (int i = 0; i < size; i++)
    {
        v.push_back(1);
    }
    copy(v.begin(), v.end(), ostream_iterator<size_t>(cout, " "));
    cout << endl;

    while (v.size() > 1)
    {
        // ищем самый левый минимальный индекс
        curr = findMinIndex(v);

        // суммируем элементы и удаляем ненужный
        if (curr < v.size() - 1)
        {
            v[curr] += v[curr + 1];
            v.erase(v.begin() + curr + 1);
        }
        else
        {
            v[curr - 1] += v[curr];
            v.erase(v.begin() + curr);
        }

        // костыль для норамльной начальной генерации
        if (isFirst)
        {
            reverse(v.begin(), v.end());
            isFirst = false;
        }

        splitLastIndexes(v, curr);
        // генерируем перестановки
        createPermutation(v);
    }
    cout << endl;
}


int main()
{
    size_t size;

    setlocale(LC_ALL, "rus");
    cout << "Введите число: ";
	cin >> size;
    cout << endl;

    createCompositions(size);
    cout << endl;
}