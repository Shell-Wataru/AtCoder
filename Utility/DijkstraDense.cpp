#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>
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

int main(){
    vector<vector<ll>> G{
        {0,1,2,9},
        {1,0,2,3},
        {1,2,0,3},
        {1,2,3,0}
    };
    Dijkstra<ll> d(G);
    d.solve(0);
    d.print();
    return 0;
}