#include <iostream>
#include <algorithm>
#include <vector>
#include <boost/timer.hpp>

using namespace std;

int main()
{
    vector<size_t> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    boost::timer t;
    t.restart();
    do 
    {
        /*
        copy(v.begin(), v.end(), ostream_iterator<size_t>(cout, " "));
        cout << endl;
        */
    } while ( next_permutation(v.begin(), v.end()) );
    double duration = t.elapsed();

    cout << duration << endl;
}