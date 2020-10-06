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


struct edge_status{
    ll weight,children,cost;
};
struct edge_to{
    ll to,weight,cost;
};

auto compare = [](edge_status &a, edge_status &b) {
    return (a.weight - a.weight/2)* a.children * b.cost < (b.weight - b.weight/2)* b.children * a.cost;
};

ll dfs(vector<vector<edge_to>> &G,priority_queue<edge_status,vector<edge_status>,decltype(compare)> &q, ll &total_weight, ll current, ll parent){
    ll childrens = 0;
    for(auto &p:G[current]){
        if (p.to != parent){
            ll path_childrens = dfs(G,q,total_weight,p.to,current);
            childrens += path_childrens;
            total_weight += path_childrens * p.weight;
            q.push({p.weight,path_childrens,p.cost});
        }
    }
    if (childrens == 0){
        return 1;
    }else{
        return childrens;
    }
}

int solve()
{
    ll n,k;
    scanf("%lld", &n);
    scanf("%lld", &k);
    vector<vector<edge_to>> G(n);
    for(int i = 0;i < n-1;i++){
        ll a,b,w,c;
        scanf("%lld", &a);
        scanf("%lld", &b);
        scanf("%lld", &w);
        scanf("%lld", &c);
        a--;
        b--;
        G[a].push_back({b,w,c});
        G[b].push_back({a,w,c});
    }


    priority_queue<edge_status,vector<edge_status>,decltype(compare)> q(compare);
    ll total_weight = 0;
    dfs(G,q,total_weight,0,-1);

    ll ope = 0;
    while(total_weight > k){
        auto a = q.top();
        ope += a.cost;
        q.pop();
        total_weight = total_weight - (a.weight - a.weight/2)*a.children;
        q.push({a.weight/2,a.children,a.cost});
    }
    cout << ope << endl;
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    // cout << flush;
    return 0;
}
