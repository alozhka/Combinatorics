#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/timer.hpp>

using namespace std;

int main()
{
    vector<size_t> v =    { 8, 1,  2,  3,  4,  5,  6,  7,  8 };  // текущий
    vector<size_t> p = v;                                                     // обратный
    vector<int> d =       { 0, 0, -1, -1, -1, -1, -1, -1 };      // направление
    boost::timer t;

    size_t cur = 11;
    t.restart();
    while (cur != 1)
    {
        copy(v.begin(), v.end(), ostream_iterator<size_t>(cout, " "));
        cout << endl;

        cur = 7;
        while (v[ p[cur] + d[cur] ] > cur)
        {
            d[cur] = -d[cur];
            cur -= 1;
        }
        // замена текущей позиции с позицией с учётом сдвига
        swap(  v[p[cur]], v[ p[cur] + d[cur] ]  );
        // это значение в -1 степени
        swap( p[  v[ p[cur] ]  ], p[cur]);
    }
    cout << t.elapsed() << endl;
}