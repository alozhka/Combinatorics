#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

size_t findMinIndex(vector<size_t>& v)
{
    size_t indexmin = 0, min = v[0];

    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] < min)
        {
            min = v[i];
            indexmin = i;
        }
    }

    return indexmin;
}

void createPermutation(vector<size_t> v)
{
    sort(v.begin(), v.end());
    do
    {
        copy(v.begin(), v.end(), ostream_iterator<size_t>(cout, " "));
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
}

void createCompositions(ostream& ostr, size_t size)
{
    vector<size_t> v;
    size_t curr = 0;

    // инициализация
    for (int i = 0; i < size; i++)
    {
        v.push_back(1);
    }
    copy(v.begin(), v.end(), ostream_iterator<size_t>(ostr, " "));
    ostr << endl;

    while (v.size() > 1)
    {
        // ищем самый левый минимальный индекс
        curr = findMinIndex(v);

        v[curr]++;
        if (--v.back() == 0)
        {
            v.pop_back();
        }

        // генерируем перестановки
        createPermutation(v);
    }
    ostr << endl;
}


int main()
{
    size_t size;

    setlocale(LC_ALL, "rus");
    cout << "Введите число: ";
    cin >> size;
    cout << endl;

    createCompositions(cout, size);
    cout << endl;

    return 0;
}