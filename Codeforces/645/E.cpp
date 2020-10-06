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

struct node
{
    ll a, b, c;
};

ll dfs(vector<vector<ll>> &G, vector<node> &nodes, ll parent, ll from, ll parent_cost, ll &zeroone, ll &onezero)
{

    ll cost = 0;
    for (auto to : G[from])
    {
        if (to != parent)
        {
            ll sub_zeroone = 0;
            ll sub_onezero = 0;
            cost += dfs(G, nodes, from, to, min(parent_cost, nodes[from].a),sub_zeroone,sub_onezero );
            onezero += sub_onezero;
            zeroone += sub_zeroone;
        }
    }
    if(nodes[from].b == 1 && nodes[from].c == 0){
        onezero++;
    }else if(nodes[from].b == 0 && nodes[from].c == 1) {
        zeroone++;
    }
    if (nodes[from].a <= parent_cost ){
        ll min_diff = min(onezero,zeroone);
        if (min_diff > 0){
            cost += nodes[from].a * 2 * min_diff;
            onezero -= min_diff;
            zeroone -= min_diff;
        }
    }
    return cost;
}
int solve()
{

    ll N;
    cin >> N;
    vector<node> nodes;
    vector<vector<ll>> G(N);
    ll c_zero_count = 0;
    ll b_zero_count = 0;
    for (int i = 0; i < N; i++)
    {
        node n;
        cin >> n.a >> n.b >> n.c;
        nodes.push_back(n);
        if (n.b == 0)
        {
            b_zero_count++;
        }
        if (n.c == 0)
        {
            c_zero_count++;
        }
    }
    for (int i = 0; i < N - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if (b_zero_count != c_zero_count)
    {
        cout << -1 << endl;
    }
    else
    {
        ll onezero = 0;
        ll zeroone = 0;
        ll cost = dfs(G,nodes,-1, 0, 1e9, onezero,zeroone);
        cout << cost << endl;
    }

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