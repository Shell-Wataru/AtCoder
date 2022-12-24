#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <climits>
using namespace std;
using ll = long long;

int solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> greater_sum(m);
    vector<ll> lower_sum(m);
    for (int i = 0; i < n; i++)
    {
        ll l, r, s;
        cin >> l >> r >> s;
        l--;
        r--;
        if (r+1 < m){
            greater_sum[r+1] += s;
        }
        if (l-1 >= 0){
            lower_sum[l-1] += s;
        }
    }
    for(int i = 0;i < m-1;i++){
        greater_sum[i+1] += greater_sum[i];
    }
    for(int i = m-1;i >= 1;i--){
        lower_sum[i-1] += lower_sum[i];
    }
    ll ans = 0;
    for(int i = 0;i< m;i++){
        ans = max(ans,lower_sum[i] + greater_sum[i]);
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
