#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

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
    string s;
    cin >> s;
    UnionFind uf(26);
    set<pair<ll, ll>> used_edges;
    for (int i = 1; i < s.size(); i++)
    {
        ll left = s[i - 1] - 'a';
        ll right = s[i] - 'a';
        ll small = min(left, right);
        ll big = max(left, right);
        // cout << small << "," << big << endl;
        if (!uf.same(small, big))
        {
            uf.unite(small, big);
            used_edges.insert({small, big});
        }
        else if (used_edges.find({small, big}) == used_edges.end())
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    vector<vector<ll>> edges(26);
    for (auto p : used_edges)
    {
        edges[p.first].push_back(p.second);
        edges[p.second].push_back(p.first);
    }

    for (int i = 0; i < 26; i++)
    {
        if (edges[i].size() >= 3)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    ll first = -1;
    for (int i = 0; i < 26; i++)
    {
        if (edges[i].size() == 1)
        {
            first = i;
            break;
        }
    }

    cout << "YES" << endl;
    if (first == -1)
    {
        cout << "abcdefghijklmnopqrstuvwxyz" << endl;
        return 0;
    }
    // cout << "sss" << endl;
    ll current = edges[first][0];
    ll before = first;
    // cout << first << current << endl;
    cout << (char)('a' + first);
    cout << (char)('a' + current);
    while (edges[current].size() == 2)
    {
        if (edges[current][0] == before)
        {
            before = current;
            current = edges[before][1];
        }
        else
        {
            before = current;
            current = edges[before][0];
        }
        cout << (char)('a' + current);
    }
    for (int i = 0; i < 26; i++)
    {
        if (edges[i].size() == 0)
        {
            cout << (char)('a' + i);
        }
    }
    cout << endl;
    return 0;
}
int main()
{
    // 整数の入力
    long long T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solve();
    }

    return 0;
}