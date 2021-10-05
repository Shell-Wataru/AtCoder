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

const long long BASE_NUM = 998244353;

const int NONE = -1;

struct my_distance{
    ll cost,max_weight,min_weight;
    bool operator>(const my_distance &d) const
    {
        if (cost != d.cost){
            return cost > d.cost;
        }else if (max_weight != d.max_weight){
            return max_weight > d.max_weight;
        }else{
            return min_weight > d.min_weight;
        }
    }

    my_distance operator+(const my_distance &d) const
    {
        ll new_cost = cost + d.cost;
        ll new_max_weight = max_weight;
        ll new_min_weight = min_weight;
        if (max_weight < d.max_weight){
            new_cost += max_weight;
            new_max_weight = d.max_weight;
        }

        if (min_weight > d.min_weight){
            new_cost -= min_weight;
            new_min_weight = d.min_weight;
        }

        return my_distance({new_cost,new_max_weight,new_min_weight});
    }
    static const my_distance id() {
        return {0,0,0};
    }
};

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
    vector<vector<pair<long long, T>>> G;

public:
    vector<T> minc;
    vector<long long> prev;

    Dijkstra(vector<vector<pair<long long, T>>> &G) : n(G.size()), G(G), minc(n, NONE), prev(G.size()) {}

    void solve(long long start)
    {
        minc.assign(n, NONE);
        priority_queue<S<T>, vector<S<T>>, greater<S<T>>> pq;
        pq.push(S<T>(start, 0, NONE));
        while (!pq.empty())
        {
            S<T> s = pq.top();
            pq.pop();
            if (minc[s.node] != NONE)
            {
                continue;
            }
            minc[s.node] = s.cost;
            prev[s.node] = s.prev;
            for (auto itr = G[s.node].begin(); itr != G[s.node].end(); ++itr)
            {
                pq.push(S<T>(itr->first, s.cost + itr->second, s.node));
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
        while (prev[stack.back()] != NONE)
        {
            stack.push_back(prev[stack.back()]);
        }
        reverse(stack.begin(), stack.end());
        return stack;
    };
};

int solve()
{

    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll,my_distance>>> G(n);
    for(int i = 0;i < m;i++){
        ll u,v,c;
        scanf("%lld",&u);
        scanf("%lld",&v);
        scanf("%lld",&c);
        u--;
        v--;
        G[u].push_back({v,{c,c,c}});
        G[v].push_back({u,{c,c,c}});
    }
    Dijkstra<my_distance> d(G);
    d.solve(0);
    for(int i = 1;i < n;i++){
        if (i != 1){
            cout << " ";
        }
        cout << d.minc[i].cost;
    }
    cout << endl;
    return 0;
}
int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    return 0;
}