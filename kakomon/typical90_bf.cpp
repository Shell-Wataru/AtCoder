#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;
using ll = long long;

struct Doubling
{
    const int LOG;
    vector<vector<int>> table;

    Doubling(int sz, int64_t lim_t) : LOG(64 - __builtin_clzll(lim_t))
    {
        table.assign(LOG, vector<int>(sz, -1));
    }

    void set_next(int k, int x)
    {
        table[0][k] = x;
    }

    void build()
    {
        for (int k = 0; k + 1 < LOG; k++)
        {
            for (int i = 0; i < table[k].size(); i++)
            {
                if (table[k][i] == -1)
                    table[k + 1][i] = -1;
                else
                    table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    int query(int k, int64_t t)
    {
        for (int i = LOG - 1; i >= 0; i--)
        {
            if ((t >> i) & 1)
                k = table[i][k];
        }
        return k;
    }
};

int main()
{
    // 整数の入力
    ll N, K;
    cin >> N >> K;
    Doubling d(100000, numeric_limits<ll>::max());
    for (int x = 0; x < 100000; x++)
    {
        ll y = 0;
        for (auto c : to_string(x))
        {
            y += c - '0';
        }
        d.set_next(x, (x + y) % 100000);
    }
    d.build();
    cout << d.query(N, K) << endl;
    return 0;
}