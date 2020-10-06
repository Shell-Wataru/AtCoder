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



ll dfs(vector<vector<pair<ll,ll>>> &G,vector<pair<ll,ll>> &q, ll &total_weight, ll current, ll parent){
    ll childrens = 0;
    for(auto &p:G[current]){
        if (p.first != parent){
            ll path_childrens = dfs(G,q,total_weight,p.first,current);
            childrens += path_childrens;
            total_weight += path_childrens * p.second;
            q.push_back({p.second,path_childrens});
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
    vector<vector<pair<ll,ll>>> G(n);
    for(int i = 0;i < n-1;i++){
        ll a,b,w;
        scanf("%lld", &a);
        scanf("%lld", &b);
        scanf("%lld", &w);
        a--;
        b--;
        G[a].push_back({b,w});
        G[b].push_back({a,w});
    }


    vector<pair<ll,ll>> q;
    ll total_weight = 0;
    dfs(G,q,total_weight,0,-1);
    auto compare = [](pair<ll,ll> a, pair<ll,ll> b) {
        return (a.first - a.first/2)* a.second < (b.first - b.first/2)* b.second;
    };
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,decltype(compare)> qq(compare);
    for (size_t i = 0; i < q.size(); i++)
    {
        qq.push(q[i]);
    }

    ll ope = 0;
    while(total_weight > k){
        ope++;
        auto a = qq.top();
        qq.pop();
        total_weight = total_weight - (a.first - a.first/2)*a.second;
        qq.push({a.first/2,a.second});
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
