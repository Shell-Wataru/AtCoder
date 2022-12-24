#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <unordered_map>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> G(N);
    vector<bool> visited1(N, false);
    vector<bool> visited2(N, false);
    vector<pair<ll, ll>> edges1;
    vector<pair<ll, ll>> edges2;
    for (int i = 0; i < M; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    stack<pair<ll, ll>> s;
    queue<pair<ll, ll>> q;
    s.push({0, -1});
    q.push({0, -1});
    while (!s.empty())
    {
        auto current = s.top();
        s.pop();
        if (visited1[current.first])
        {
            continue;
        }
        visited1[current.first] = true;
        edges1.push_back(current);
        for (auto to : G[current.first])
        {
            s.push({to, current.first});
        }
    }

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();
        if (visited2[current.first])
        {
            continue;
        }
        visited2[current.first] = true;
        edges2.push_back(current);
        for (auto to : G[current.first])
        {
            q.push({to, current.first});
        }
    }

    for (int i = 1; i < N; i++)
    {
        cout << edges1[i].first + 1 << " " << edges1[i].second + 1 << "\n";
    }
    for (int i = 1; i < N; i++)
    {
        cout << edges2[i].first + 1 << " " << edges2[i].second + 1 << "\n";
    }

    cout << flush;
    return 0;
}