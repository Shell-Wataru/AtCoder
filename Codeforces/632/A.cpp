#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <iterator> // std::rbegin, std::rend

using namespace std;
using ll = long long;

int solve()
{
    ll n, m;
    cin >> n >> m;
    if (n * m % 2 == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i + j) % 2 == 0)
                {
                    cout << 'B';
                }
                else
                {
                    cout << 'W';
                }
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i + j) % 2 == 0 || (i == 0 && j == 1))
                {
                    cout << 'B';
                }
                else
                {
                    cout << 'W';
                }
            }
            cout << endl;
        }
    }
    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}