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

int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    UnWeightedGraph G(N);
    for(int i = 0;i < M;i++){
        ll a,b;
        cin >> a>> b;
        a--;b--;
        G[a].push_back(b);
    }
    vector<ll> min_cycle;
    for(int i = 0;i < N;i++){
        // cout << i << endl;
        vector<ll> parents(N,-1);
        queue<ll> q;
        q.push(i);
        while(!q.empty()){
            ll current = q.front();
            q.pop();
            for(auto to:G[current]){
                if (parents[to] == -1){
                    q.push(to);
                    parents[to] = current;
                }
            }
        }
        if (parents[i] != -1){
            ll current = parents[i];
            vector<ll> cycle;
            cycle.push_back(i);
            while(current != i){
                cycle.push_back(current);
                current = parents[current];
            }
            if (min_cycle.size() == 0 || cycle.size() < min_cycle.size()){
                min_cycle = cycle;
            }
        }
    }
    if (min_cycle.size() == 0){
        cout << -1 << endl;
    }else{
        cout << min_cycle.size() << endl;
        for(auto node:min_cycle){
            cout << node + 1 << endl;
        }
    }

    return 0;
}