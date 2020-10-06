#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int show(vector<vector<ll>> &G)
{
    for (auto row : G)
    {
        for (auto cell : row)
        {
            cout << cell;
        }
        cout << endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> G(2, vector<ll>(n, 0));
    set<pair<ll, ll>> cants;
    for (int i = 0; i < q; i++)
    {
        ll r, c;
        cin >> r >> c;
        r--;
        c--;
        G[r][c] = (G[r][c] + 1) % 2;
        ll opposite = (r + 1) % 2;
        if (G[r][c] == 1)
        {
            if (G[opposite][c] == 1)
            {
                cants.insert({c, c});
            }
            if (c > 0)
            {
                if (G[opposite][c - 1] == 1)
                {
                    if (r == 0)
                    {
                        cants.insert({c, c - 1});
                    }
                    else
                    {
                        cants.insert({c - 1, c});
                    }
                }
            }
            if (c < n - 1)
            {
                if (G[opposite][c + 1] == 1)
                {
                    if (r == 0)
                    {
                        cants.insert({c, c + 1});
                    }
                    else
                    {
                        cants.insert({c + 1, c});
                    }
                }
            }
        }
        else
        {
            if (G[opposite][c] == 1)
            {
                cants.erase({c, c});
            }
            if (c > 0)
            {
                if (G[opposite][c - 1] == 1)
                {
                    if (r == 0)
                    {
                        cants.erase({c, c - 1});
                    }
                    else
                    {
                        cants.erase({c - 1, c});
                    }
                }
            }
            if (c < n - 1)
            {
                if (G[opposite][c + 1] == 1)
                {
                    if (r == 0)
                    {
                        cants.erase({c, c + 1});
                    }
                    else
                    {
                        cants.erase({c + 1, c});
                    }
                }
            }
        }
        if (cants.size() > 0)
        {
            cout << "No" << endl;
            // show(G);
            // for (auto c : cants)
            // {
            //     cout << c.first << c.second << endl;
            // }
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}
