#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

struct UnionFind
{
    vector<int> data;

    UnionFind(int sz)
    {
        data.assign(sz, -1);
    }

    bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return (false);
        if (data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    bool same(int x, int y)
    {
        x = find(x), y = find(y);
        return x == y;
    }
    int find(int k)
    {
        if (data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }

    int size(int k)
    {
        return (-data[find(k)]);
    }
};

int solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> G(n);
    for (int i = 0; i < n; i++)
    {
        cin >> G[i];
    }
    bool can_make = true;
    for (int i = 0; i < n; i++)
    {
        bool has_black = false;
        bool has_white = false;
        bool has_second_black = false;
        for (int j = 0; j < m; j++)
        {
            if (!has_black)
            {
                if (G[i][j] == '#')
                {
                    has_black = true;
                }
            }
            else if (has_black && !has_white)
            {
                if (G[i][j] == '.')
                {
                    has_white = true;
                }
            }
            else if (has_black && has_white)
            {
                if (G[i][j] == '#')
                {
                    has_second_black = true;
                }
            }
        }
        if (has_second_black)
        {
            can_make = false;
        }
    }

    for (int i = 0; i < m; i++)
    {
        bool has_black = false;
        bool has_white = false;
        bool has_second_black = false;
        for (int j = 0; j < n; j++)
        {
            if (!has_black)
            {
                if (G[j][i] == '#')
                {
                    has_black = true;
                }
            }
            else if (has_black && !has_white)
            {
                if (G[j][i] == '.')
                {
                    has_white = true;
                }
            }
            else if (has_black && has_white)
            {
                if (G[j][i] == '#')
                {
                    has_second_black = true;
                }
            }
        }
        if (has_second_black)
        {
            can_make = false;
        }
    }

    bool has_white_only_row = false;
    bool has_white_only_column = false;
    for (int i = 0; i < m; i++)
    {
        bool white_only = true;
        for (int j = 0; j < n; j++)
        {
            if (G[j][i] == '#')
            {
                white_only = false;
            }
        }
        if (white_only)
        {
            has_white_only_column = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        bool white_only = true;
        for (int j = 0; j < m; j++)
        {
            if (G[i][j] == '#')
            {
                white_only = false;
            }
        }
        if (white_only)
        {
            has_white_only_row = true;
        }
    }
    if (has_white_only_column ^ has_white_only_row)
    {
        can_make = false;
    }

    if (!can_make)
    {
        cout << -1 << endl;
    }
    else
    {
        UnionFind uf(n * m);
        for (int i = 1; i < n; i++)
        {
            if (G[i - 1][0] == '#')
            {
                uf.unite((i - 1) * m + 0, i * m + 0);
            }
        }

        for (int j = 1; j < m; j++)
        {
            if (G[0][j] == '#')
            {
                if (G[0][j - 1] == '#')
                {
                    uf.unite(0 * m + j - 1, 0 * m + j);
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (G[i][j] == '#')
                {
                    if (G[i - 1][j] == '#')
                    {
                        uf.unite((i - 1) * m + j, i * m + j);
                    }
                    if (G[i][j - 1] == '#')
                    {
                        uf.unite(i * m + j - 1, i * m + j);
                    }
                }
            }
        }
        set<ll> fragments;
        for (int i = 0; i < n * m; i++)
        {
            if (G[i / m][i % m] == '#')
            {
                fragments.insert(uf.find(i));
            }
        }
        cout << fragments.size() << endl;
    }
    return 0;
}
int main()
{
    // ll t;
    // cin >> t;
    // for (int i = 1; i <= t; i++)
    // {
    solve();
    // }
    return 0;
}
