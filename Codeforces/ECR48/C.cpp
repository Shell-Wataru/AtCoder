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
ll BASE_NUM = 1000000007;

struct edge{
    ll label;
};

int solve()
{
    ll n;
    cin >> n;
    vector<set<ll>> G(n);
    vector<pair<ll,ll>> edges;
    map<pair<ll,ll>,ll> labels;
    for(int i  =0; i< n-1;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].insert(b);
        G[b].insert(a);
        edges.push_back({min(a,b),max(a,b)});
    }
    queue<ll> q;
    for(int i = 0;i< n;i++){
        if (G[i].size() == 1){
            q.push(i);
        }
    }

    ll current = 0;
    while(!q.empty()){
        ll from = q.front();
        q.pop();
        // cout << from << ":" <<G[from].size() << endl;
        for(auto to: G[from]){
            // cout << current << endl;
            // cout << from  << to << endl;
            // cout << min(from,to)<< ", "<<max(from,to) << " " << current << endl;
            labels[{min(from,to),max(from,to)}] = current;
            current++;
            G[to].erase(from);
            q.push(to);
        }
        G[from].clear();
    }

    for(auto &e:edges){
        cout << labels[e] << endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    return 0;
}
