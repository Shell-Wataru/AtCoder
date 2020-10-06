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

const int NONE = -1;

template< typename T >
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

template< typename T >
class Dijkstra
{
    long long n;
    vector<map<long long, T> > G;

  public:
    vector<T> minc;
    vector<long long> prev;

    Dijkstra(vector<map<long long, T> > &G) : n(G.size()), G(G), minc(n, NONE), prev(G.size()) {}

    void solve(long long start)
    {
        minc.assign(n, NONE);
        priority_queue<S<T>, vector<S<T>>, greater<S<T>> > pq;
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
        while(prev[stack.back()] != NONE){
            stack.push_back(prev[stack.back()]);
        }
        reverse(stack.begin(),stack.end());
        return stack;
    };
};

int solve()
{

    ll n,m,a,b,c;
    cin >> n >> m >> a >> b >> c;
    a--;
    b--;
    c--;
    vector<map<ll,ll>> G(n);
    vector<ll> p(m+1,0);
    for(int i = 0;i < m;i++){
        cin >> p[i];
    }
    sort(p.begin(),p.end());
    for(int i = 1;i <= m;i++){
        p[i] += p[i-1];
    }
    for(int i = 0;i < m;i++){
        ll from,to;
        cin >> from >> to;
        from--;
        to--;
        G[from][to] =1;
        G[to][from] =1;
    }
    Dijkstra<ll> from_a(G);
    Dijkstra<ll> from_b(G);
    Dijkstra<ll> from_c(G);
    from_a.solve(a);
    from_b.solve(b);
    from_c.solve(c);
    ll min_cost = numeric_limits<ll>::max();
    for(int i = 0;i < n;i++){
        // cout << i+1 << "a: " << from_a.minc[i] << "b: " << from_b.minc[i] << "c: " << from_c.minc[i] << endl;
        if (from_c.minc[i] + from_a.minc[i] + from_b.minc[i]  > m){
            continue;
        }else{
            min_cost = min(min_cost, 2 *  p[from_b.minc[i]] + 1 * (p[from_c.minc[i] + from_a.minc[i] + from_b.minc[i]] - p[from_b.minc[i]]));
        }
    }
    cout << min_cost << endl;
    return 0;
}
int main()
{
    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}