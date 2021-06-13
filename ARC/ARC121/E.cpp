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
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

using ll = long long;

const long long BASE_NUM = 1000000007;

ll dfs(vector<vector<ll>> &G, ll current, ll parent, vector<ll> &data, ll K)
{
    if (parent != -1 && G[current].size() == 1)
    {
        if (K == 0){
            data[current] = 0;
        }else{
            data[current] = K + 1;
        }
        return data[current];
    }
    vector<ll> distances;
    for (auto to : G[current])
    {
        if (to != parent)
        {
            ll d = dfs(G, to, current, data, K) + 1;
            distances.push_back(d);
        }
    }
    sort(distances.begin(), distances.end());
    if (distances.size() == 1)
    {
        data[current] = distances.front() % (2 * K + 1);
    }
    else
    {
        if (distances.front() + distances.back() <= 2 * K + 1)
        {
            data[current] = distances.front() % (2 * K + 1);
        }
        else
        {
            data[current] = distances.back() % (2 * K + 1);
        }
    }

    return data[current];
}

int minimum_distance(ll l, ll r, ll N, ll K, vector<vector<ll>> &G)
{
    if (l + 1 == r)
    {
        return r;
    }
    ll center = (l + r) / 2;
    vector<ll> data(N, -1);
    dfs(G, 0, -1, data, center);
    ll count = 0;
    for (int i = 1; i < N; i++)
    {
        // cout << data[i] << ",";
        if (data[i] == 0)
        {
            count++;
        }
    }
    // cout << endl;
    if (data[0] > center || data[0] == 0){
        count++;
    }
    if (count == 0){
        count = 1;
    }
    // cout << center << ":" << count << endl;
    if (count <= K)
    {
        return minimum_distance(l, center, N, K, G);
    }
    else
    {
        return minimum_distance(center, r, N, K, G);
    }
}
int main()
{
    ll N, K;
    scanf("%lld", &N);
    scanf("%lld", &K);
    vector<vector<ll>> G(N);
    vector<ll> data1(N, -1);
    vector<ll> data2(N, -1);
    for (int i = 0; i < N - 1; i++)
    {
        ll u, v;
        scanf("%lld", &u);
        scanf("%lld", &v);
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    cout << minimum_distance(-1, N, N, K, G) << endl;
    return 0;
}