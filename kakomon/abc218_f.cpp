#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>
using namespace std;
using ll = long long;

const int NONE = -1;

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

    ll N,M;
    cin >> N >> M;
    vector<vector<pair<ll,ll>>> G(N);
    vector<pair<ll,ll>> edges(M);
    for(int i = 0;i < M;i++){
        ll s,t;
        cin >> s >> t;
        s--;
        t--;
        edges[i] = {s,t};
        G[s].push_back({t,1});
    }
    Dijkstra<ll> D(G);
    D.solve(0);
    auto path = D.path(N-1);
    set<pair<ll,ll>> used_paths;
    for(int i = 0;i < path.size()-1;i++){
        used_paths.insert({path[i],path[i+1]});
    }
    for(int i = 0;i < M;i++){
        if (used_paths.find({edges[i]}) != used_paths.end()){
            vector<vector<pair<ll,ll>>> removedG(N);
            for(int j = 0;j < M;j++){
                if (i != j){
                    removedG[edges[j].first].push_back({edges[j].second,1});
                }
            }
            Dijkstra<ll> removedD(removedG);
            removedD.solve(0);
            cout << removedD.minc[N-1] << endl;
        }else{
            cout << D.minc[N-1] << endl;
        }
    }
    return 0;
}
int main()
{
    //   int t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}