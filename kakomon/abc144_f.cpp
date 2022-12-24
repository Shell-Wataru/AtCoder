#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
#include <atcoder/string>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

double solve(ll N, vector<vector<ll>> &G, pair<ll, ll> e, vector<double> &current)
{
    vector<vector<double>> A(N, vector<double>(N));
    for (int j = 0; j < N; j++)
    {
        if (e.first == j)
        {
            if (G[j].size() == 1)
            {
                return numeric_limits<double>::max();
            }
            for (auto to : G[j])
            {
                if (to != e.second)
                {
                    A[j][to] = 1.0 / (G[j].size() - 1);
                }
            }
        }
        else
        {
            for (auto to : G[j])
            {
                if (to != j)
                {
                    A[j][to] = 1.0 / G[j].size();
                }
            }
        }
    }
    // for(int k = 0;k < N;k++){
    //         for(int l = 0;l < N;l++){
    //             cout << A[k][l] << ",";
    //         }
    //         cout << endl;
    //     }
    current[N - 1] = 0;
    for (int j = 0; j < 15; j++)
    {
        vector<double> next_current(N, 0);
        for (int k = 0; k < N; k++)
        {
            for (int l = 0; l < N; l++)
            {
                next_current[k] += A[k][l] * (current[l] + 1);
            }
        }
        // cout << next_current[0] << endl;
        swap(next_current, current);
    }
    if (current[0] > 1e-6)
    {
        return current[0];
    }
    else
    {
        return numeric_limits<double>::max();
    }
}

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> Edges(M);
    vector<vector<ll>> G(N);
    vector<vector<ll>> D(N, vector<ll>(N, numeric_limits<ll>::max() / 2));
    for (int i = 0; i < M; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        Edges[i] = {u, v};
        G[u].push_back(v);
        D[u][v] = 1;
    }
    vector<double> current(N, 0);
    double ans = solve(N, G, {-1ll, -1ll}, current);
    vector<pair<double, pair<ll, ll>>> targets;
    for (int i = 0; i < N - 1; i++)
    {
        if (G[i].size() == 1)
        {
            continue;
        }
        ll max_to = -1;
        double max_d = 0;
        double total_d = 0;
        for (auto to : G[i])
        {
            total_d += current[to];
            if (current[to] > max_d)
            {
                max_d = current[to];
                max_to = to;
            }
        }
        targets.push_back({total_d/G[i].size() - (total_d - max_d)/(G[i].size()-1), {
                i, max_to}});
    }
    sort(targets.rbegin(),targets.rend());
    // cout << targets[0].first << ":" <<  targets[0].second.first + 1 << "," << targets[0].second.second + 1<< endl;
    for (auto e : targets)
    {
        // cout << targets[0].first << endl;
        ans = min(ans, solve(N, G, e.second, current));
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
