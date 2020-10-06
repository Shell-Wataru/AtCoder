#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

// dinic
class max_flow {
    struct edge { int to, cap, rev; };
    int V;
    vector<vector<edge>> G;
    vector<int> level;

public:
    max_flow(int V) : V(V) { G.assign(V,vector<edge>()); }

    void add_edge(int from, int to, int cap) {
        G[from].push_back((edge) {to, cap, (int) G[to].size()});
        G[to].push_back((edge) {from, 0, (int) G[from].size()-1});
    }

    void bfs(int s) {
        level.assign(V,-1);
        queue<int> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for(auto &e: G[v]){
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int i = 0; i < (int) G[v].size();i++) {
            edge& e = G[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int run(int s, int t) {
        int ret = 0, f;
        while (bfs(s), level[t] >= 0) {
            while ((f = dfs(s, t, INT_MAX)) > 0) ret += f;
        }
        return ret;
    }
};


struct Block
{
    ll x, y, z;
};
int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<Block> blocks;
    set<ll> unique_weights;
    set<pair<ll,ll>> unique_edges;
    map<ll, ll> zipped_weights;
    for (int i = 0; i < N; i++)
    {
        Block block;
        cin >> block.x >> block.y >> block.z;
        blocks.push_back(block);
        // cout << "=========" << endl;
        for (int j = 1; j < block.x; j++)
        {
            unique_weights.insert(j * block.y * block.z);
            unique_edges.insert({j * block.y * block.z,(block.x - j) * block.y * block.z});
        }
        for (int j = 1; j < block.y; j++)
        {
            unique_weights.insert(j * block.z * block.x);
            unique_edges.insert({j * block.z * block.x,(block.y - j) * block.z * block.x});
        }
        for (int j = 1; j < block.z; j++)
        {
            unique_weights.insert(j * block.x * block.y);
            unique_edges.insert({j * block.x * block.y,(block.z - j) * block.x * block.y});
        }
    }

    int num = 1;
    for(auto w: unique_weights){
        zipped_weights[w] = num;
        num++;
    }

    ll V = unique_weights.size();
    max_flow mf(2 * V +2);
    for(auto e: unique_edges){
        cout << zipped_weights[e.first] << zipped_weights[e.second] << endl;
        mf.add_edge(zipped_weights[e.first],zipped_weights[e.second] + V,1);
    }
    for(int i = 1;i <= V; i++){
        mf.add_edge(0,i,1);
        mf.add_edge(i + V,2 * V +1,1);
    }

    ll max_matching = mf.run(0, 2 * V +1);
    ll non_matching = V - max_matching;
    // cout << max_matching << endl;
    // cout << V << endl;
    // cout << non_matching << endl;
    cout << max_matching + non_matching * 2 << endl;
    return 0;
}