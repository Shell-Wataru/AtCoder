#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

ll dfs(vector<vector<ll>> &G,ll current,ll parent, ll K, ll &ans){
    ll d = 0;
    for(auto to:G[current]){
        if (to !=parent){
            d = max(d,dfs(G,to,current,K,ans)+1);
        }
    }
    if (d == (K-1) && current != 0 && parent != 0){
        ans++;
        return -1;
    }else{
        return d;
    }
    return 0;
}
int solve()
{
    ll N,K;
    scanf("%lld", &N);
    scanf("%lld", &K);
    vector<vector<ll>> G(N);
    vector<vector<ll>> revG(N);
    for(int i = 0;i < N;i++){
        ll a;
        scanf("%lld",&a);
        a--;
        G[i].push_back(a);
        if (i!= 0){
            revG[a].push_back(i);
        }

    }
    ll ans = 0;
    dfs(revG,0,-1,K,ans);
    if (G[0][0] != 0){
        ans++;
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    //   ll t;
    //   cin >> t;
    //   for (int i = 1; i <= t; i++)
    //   {
    solve();
    //   }
    cout << flush;
    return 0;
}