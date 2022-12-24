#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  bool same(int x, int y) {
    x = find(x), y = find(y);
    return x == y;
  }
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};

bool dfs(vector<vector<ll>> &G, UnionFind &uf,ll current, ll parent,ll target,ll depth){
    // cout << depth << endl;
    if (current == target){
        // cout << "!!" << endl;
        return true;
    }
    for(auto to:G[current]){
        if (to != parent && uf.find(to) != parent && !uf.same(to,current)){
            bool found = dfs(G,uf,uf.find(to),current,target,depth + 1);
            if (found){
            //     cout << current << "->" << to << endl;
            //     cout << uf.find(current) << "->" << to << endl;
                to = uf.find(to);
                uf.unite(current,to);
                ll new_current = uf.find(current);
                if (new_current == to){
                    for(auto sub_to:G[current]){
                        if (!uf.same(sub_to,new_current)){
                            G[new_current].push_back(sub_to);
                        }
                    }
                }else if (new_current == current){
                    for(auto sub_to:G[to]){
                        if (!uf.same(sub_to,new_current)){
                            G[new_current].push_back(sub_to);
                        }
                    }
                }else{
                    cout << "!!!" << endl;
                }
                return true;
            }
        }
    }
    return false;
}

string solve()
{
    ll N;
    cin >> N;
    UnionFind uf(N);
    vector<vector<ll>> G(N);
    map<ll,vector<ll>> F;
    for(int i = 0;i < N-1;i++){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0;i < N;i++){
        ll f;
        cin >> f;
        F[f].push_back(i);
    }
    // cout << N << endl;
    for(auto p:F){
        if (p.second.size() >= 2){
            for(int i = 1;i <p.second.size();i++){
                cout << i << ":"<< uf.find(p.second[0]) << "," << uf.find(p.second[i]) << endl;
                dfs(G,uf,uf.find(p.second[0]),-1,uf.find(p.second[i]),0);
            }
        }
    }
    ll ans = 0;
    for(int i = 0;i < N;i++){
        if (uf.find(i) == i){
            ans++;
        }
    }
    return to_string(ans-1);
}
int main()
{
    ll T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}