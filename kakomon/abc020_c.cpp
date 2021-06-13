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
#include <stack>
#include <boost/multiprecision/cpp_int.hpp>

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

ll max_x(vector<string> M, ll T,ll H,ll W,ll l,ll r){
    if (l+1 == r){
        return l;
    }
    ll center = (l+r)/2;
    vector<vector<pair<ll,ll>>> edges(H*W);
    ll start,goal;
    for(int i = 0;i < H;i++){
        for(int j =0 ;j < W;j++){
            ll cost;
            if (M[i][j] == '.'){
                cost = 1;
            }else if (M[i][j] == '#'){
                cost = center;
            }else if (M[i][j] == 'S'){
                cost = 1;
                start = W*i + j;
            }else if (M[i][j] == 'G'){
                cost = 1;
                goal = W*i + j;
            }
            if (i > 0){
                edges[W*(i-1) + j].emplace_back(W*i+j,cost);
            }
            if (i < H - 1){
                edges[W*(i+1) + j].emplace_back(W*i+j,cost);
            }
            if (j > 0){
                edges[W*i + j-1].emplace_back(W*i+j,cost);
            }
            if (j < W - 1){
                edges[W*i + j+1].emplace_back(W*i+j,cost);
            }
        }
    }
    Dijkstra<ll> d(edges);
    d.solve(start);
    // cout << d.minc[goal] << endl;
    if (d.minc[goal] <= T){
        return max_x(M, T,H,W,center,r);
    }else{
        return max_x(M, T,H,W,l,center);
    }
}
int main()
{
    // 整数の入力
    ll H,W,T;
    cin >> H >> W>> T;
    vector<string> M(H);
    for (size_t i = 0; i < H; i++)
    {
        cin >> M[i];
    }
    cout << max_x(M,T,H,W,1,10000000000ll) << endl;
    return 0;
}