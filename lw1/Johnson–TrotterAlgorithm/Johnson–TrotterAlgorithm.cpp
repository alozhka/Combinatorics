#include <iostream>
#include <vector>
#include <boost/timer.hpp>

using namespace std;

int main()
{
    vector<size_t> v,p; // обычный, обратный
    vector<int> d;      // направления сдвига
    boost::timer t;
    size_t in, cur;

    setlocale(LC_ALL, "rus");
    cout << "Введите количество элементов в перестановке: ";
    cin >> in;
    cout << endl;

    v.push_back(in + 1);
    p.push_back(0); // занимаем нулевые ячейки
    d.push_back(0);
    for (int i = 1; i <= in; i++)
    {
        v.push_back(i);
        p.push_back(i);
        d.push_back(-1);
    }
    d[1] = 0;
    v.push_back(in + 1);
    cur = in + 1;

    t.restart();
    while (cur != 1)
    {
        
        copy(v.begin() + 1, v.end() - 1, ostream_iterator<size_t>(cout, " "));
        cout << endl;
        

        cur = in;
        while (v[ p[cur] + d[cur] ] > cur)
        {
            d[cur] = -d[cur];
            cur -= 1;
        }
        swap(  v[p[cur]], v[ p[cur] + d[cur] ]  );  // замена текущей позиции с позицией с учётом сдвига
        swap( p[  v[ p[cur] ]  ], p[cur] );          // это значение в -1 степени
    }
    double duration = t.elapsed();
    cout << duration << endl;
}