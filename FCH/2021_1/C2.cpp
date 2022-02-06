#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;
using ll = long long;

ll dfs_set_parent(ll current, ll parent, vector<set<ll>> &G, vector<ll> &parents)
{
    parents[current] = parent;
    for (auto to : G[current])
    {
        if (to != parent)
        {
            dfs_set_parent(to, current, G, parents);
        }
    }
    return 0;
}

pair<ll, ll> dfs(ll current, ll parent, vector<set<ll>> &G, vector<ll> &C)
{
    ll edges = 0;
    for (auto to : G[current])
    {
        if (to != parent){
            edges++;
        }
    }
    if (edges == 0)
    {
        return {C[current], current};
    }
    else
    {
        pair<ll, ll> answer;
        for (auto to : G[current])
        {
            if (to != parent)
            {
                auto d = dfs(to, current, G, C);
                if (d.first > answer.first)
                {
                    answer = d;
                }
            }
        }
        return {C[current] + answer.first, answer.second};
    }
}

vector<ll> path(ll root, ll leaf, vector<ll> &parents)
{
    vector<ll> ans;
    // cout << leaf << "," << root << endl;
    while (leaf != root)
    {

        ans.push_back(leaf);
        leaf = parents[leaf];
    }
    ans.push_back(root);
    return ans;
}

void remove_path(ll root, ll leaf, vector<set<ll>> &G, vector<ll> &parents, set<ll> &roots)
{
    vector<ll> max_path = path(root, leaf, parents);
    // cout << "path_size" << max_path.size() << endl;
    for(int i = 0;i < max_path.size()-1;i++){
        G[max_path[i]].erase(max_path[i+1]);
        G[max_path[i+1]].erase(max_path[i]);
    }
    for(auto r:max_path){
        roots.insert(r);
    }
}
string solve()
{
    ll N, K;
    cin >> N >> K;
    vector<set<ll>> G(N);
    vector<ll> C(N);
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].insert(v);
        G[v].insert(u);
    }
    vector<ll> parents(N);
    dfs_set_parent(0, -1, G, parents);
    set<ll> roots = {0};
    ll ans = C[0];
    for (int i = 0; i < K && roots.size() > 0; i++)
    {
        ll max_root = -1;
        ll max_value = 0;
        vector<ll> max_leafs;
        for (auto r : roots)
        {
            if (G[r].size() == 0){
                continue;
            }else{
                vector<vector<ll>> childs;
                for (auto to : G[r])
                {
                    auto p = dfs(to, r, G, C);
                    childs.push_back({p.first, to, p.second});
                }
                sort(childs.rbegin(), childs.rend());
                if (G[r].size() == 1){
                    if (childs[0][0] > max_value){
                        max_value = childs[0][0];
                        max_root = r;
                        max_leafs = {childs[0][2]};
                    }
                }else{
                    if (childs[0][0] + childs[1][0] > max_value){
                        max_value = childs[0][0] + childs[1][0];
                        max_root = r;
                        max_leafs = {childs[0][2],childs[1][2]};
                    }
                }
            }
        }
        cout << "leafs" << endl;
        for(auto l:max_leafs){
            cout << l << ",";
            remove_path(max_root, l, G, parents, roots);
        }
        cout << endl;
        ans += max_value;
    }
    return to_string(ans);
}

int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}
