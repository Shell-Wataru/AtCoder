#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    scanf("%lld",&n);
    vector<pair<ll,ll>> E(n);
    vector<set<ll>> G(n);
    vector<ll> Score(n+1);
    for (size_t i = 1; i <= n; i++)
    {
        ll u;
        scanf("%lld",&u);
        u--;
        E[i] = {u,i};
    }
    for (size_t i = 1; i <= n; i++)
    {
        scanf("%lld",&Score[i]);
    }

    for(auto &p: E){
        G[p.first].insert(p.second);
    }
    vector<map<ll,ll>> DP;
    DP.push_back({{0,0}});
    while(DP.back().size() > 0){
        vector<ll> children;
        vector<ll> children_scores;
        for(auto p:DP.back()){
            for(auto to:G[p.first]){
                children.push_back(to);
                children_scores.push_back(Score[to]);
            }
        }
        sort(children_scores.begin(),children_scores.end(),greater<ll>());
    }
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
    cout << flush;
    return 0;
}
