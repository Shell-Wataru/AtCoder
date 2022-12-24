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

using namespace std;
using ll = long long;

template <typename T>
struct edge
{
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x)
    {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T>
using Matrix = vector<vector<T>>;

bool can_merge(string &A, string &B)
{
    for (int i = 0; i < A.size(); i++)
    {
        if (!(A[i] == '*' || B[i] == '*' || A[i] == B[i]))
        {
            return false;
        }
    }
    return true;
}

void merge(string &A, string &B)
{
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == '*')
        {
            A[i] = B[i];
        }
    }
}
int main()
{
    // 整数の入力
    ll N, M;
    cin >> N >> M;
    vector<string> P(N);
    vector<vector<bool>> edges(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (can_merge(P[i], P[j]))
            {
                edges[i][j] = true;
            }
        }
    }
    vector<ll> DP(1ll << N, numeric_limits<ll>::max()/2);
    DP[0] = 0;
    ll ans = 0;
    // クリークごとに貪欲したがWA
    for (int i = 1; i < (1ll << N); i++)
    {
        bool is_clique = true;
        for (int j = 0; j < N; j++)
        {
            if (i & 1ll << j)
            {
                for (int k = j + 1; k < N; k++)
                {
                    if (i & 1ll << k)
                    {
                        if (!edges[j][k])
                        {
                            is_clique = false;
                        }
                    }
                }
            }
        }
        if (is_clique)
        {
            ll other = ((1ll << N) - 1) ^ i;
            // cout << bitset<14>(i) << endl;
            for (int sub = other; sub; sub = (sub - 1) & other)
            {
                DP[sub | i] = min(DP[sub | i], DP[sub] + 1);
            }
            DP[i] = 1;
        }
    }
    // for(int i = 0;i < 1ll<<N;i++){
    //     cout << DP[i] << endl;
    // }
    cout << DP[(1ll << N) - 1] << endl;
    return 0;
}