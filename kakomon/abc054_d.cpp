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

int solve()
{
    ll n,Ma,Mb;
    cin >> n >> Ma >> Mb;
    vector<vector<ll>> DP(401,vector<ll>(401,numeric_limits<ll>::max()/2));
    DP[0][0] = 0;
    for(int i = 0;i < n;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        for(int j = 400-a;j>= 0;j--){
            for(int k = 400 - b;k >= 0;k--){
                DP[j+a][k+b] = min(DP[j+a][k+b],DP[j][k]+ c);
            }
        }
    }
    ll ans = numeric_limits<ll>::max();
    for(int i = 1;i*Ma <= 400 && i*Mb <= 400;i++){
        ans = min(ans,DP[i*Ma][i*Mb]);
    }
    if (ans >= numeric_limits<ll>::max()/2 ){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

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
    return 0;
}