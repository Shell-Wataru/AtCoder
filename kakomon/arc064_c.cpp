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

using namespace std;
using ll = long long;

template <typename T>
struct S
{
    long long node, prev;
    T cost;
    S(long long n, T c, long long p) : node(n), cost(c), prev(p) {}
    bool operator>(const S &s) const
    {
        return cost > s.cost;
    }
};

template <typename T>
class Dijkstra
{
    long long n;
    vector<vector<T>> G;
    ll none_node = -1;

public:
    vector<T> minc;
    vector<long long> prev;

    Dijkstra(vector<vector<T>> &G) : n(G.size()), G(G), minc(n, numeric_limits<T>::max()), prev(G.size()) {}

    void solve(long long start)
    {
        minc.assign(n, numeric_limits<T>::max());
        priority_queue<S<T>, vector<S<T>>, greater<S<T>>> pq;
        pq.push(S<T>(start, 0, none_node));
        while (!pq.empty())
        {
            S<T> s = pq.top();
            pq.pop();
            if (minc[s.node] != numeric_limits<T>::max())
            {
                continue;
            }
            minc[s.node] = s.cost;
            prev[s.node] = s.prev;
            for(int i = 0;i < n;i++){
                pq.push(S<T>(i, s.cost + G[s.node][i], s.node));
            }
        }
    }

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << ":" << minc[i] << endl;
        }
    };

    vector<ll> path(ll last)
    {
        vector<ll> stack;
        stack.push_back(last);
        while (prev[stack.back()] != none_node)
        {
            stack.push_back(prev[stack.back()]);
        }
        reverse(stack.begin(), stack.end());
        return stack;
    };
};

int main()
{
    // 整数の入力
    ll xs,ys,xt,yt;
    cin >> xs >> ys >> xt >> yt;
    ll N;
    cin >> N;
    vector<ll> radius(N+2,0);
    vector<pair<ll,ll>> positions(N+2);
    positions[0] = {xs,ys};
    positions[N+1] = {xt,yt};
    vector<vector<double>> G(N+2,vector<double>(N+2,0));
    for(int i = 0;i < N;i++){
        ll x,y,r;
        cin >> x >> y >> r;
        positions[i+1] = {x,y};
        radius[i+1] = r;
    }
    // cout << "!!" << endl;
    for(int i = 0;i <= N+1;i++){
        for(int j = 0; j <= N+1;j++){
            G[i][j] = max(hypot(positions[i].first - positions[j].first ,positions[i].second - positions[j].second) - radius[i] - radius[j],0.0);
        }
    }
    // cout << "!!" << endl;
    Dijkstra<double> d(G);
    d.solve(0);
    cout << fixed << setprecision(12) << d.minc[N+1] << endl;
    return 0;
}