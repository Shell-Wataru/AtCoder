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


int solve()
{
    // cout << "==" << endl;
    ll n;
    scanf("%lld", &n);
    vector<ll> as(n);
    vector<ll> bs(n+1);
    map<ll,ll> map_diff;
    for(int i = 0; i< n;i++){
        scanf("%lld", &as[i]);
    }

    for(int i = 0; i< n;i++){
        ll b;
        scanf("%lld", &b);
        bs[b] = i;
    }
    ll ans = 0;
    for(int i = 0; i < n;i++){
        map_diff[(i - bs[as[i]] + n) % n]++;
    }
    for(auto &p:map_diff){
        ans = max(ans,p.second);
    }
    cout << ans << endl;
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
    // cout << flush;
    return 0;
}
