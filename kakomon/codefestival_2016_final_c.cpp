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
#include <numeric>

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

int main()
{
    ll N, M;
    cin >> N >> M;
    UnionFind uf(N);
    vector<vector<ll>> LanguageTalkers(M);
    for (int i = 0; i < N; i++)
    {
        ll K;
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            ll l;
            cin >> l;
            l--;
            LanguageTalkers[l].push_back(i);
        }
    }

    for (int i = 0; i < M; i++)
    {

        for (int j = 0; j < (ll) (LanguageTalkers[i].size()) - 1; j++)
        {
            uf.unite(LanguageTalkers[i][j], LanguageTalkers[i][j + 1]);
        }
    }
    // cout << uf.size(0) << endl;
    if (uf.size(0) == N)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}