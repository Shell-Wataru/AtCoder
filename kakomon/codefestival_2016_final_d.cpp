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
    ll n,m;
    cin >> n >> m;
    vector<ll> counts(100001,0);
    vector<ll> remain_max(m,0);
    vector<ll> remain_min(m,0);
    for(int i = 0;i < n;i++){
        ll x;
        cin >> x;
        counts[x]++;
    }
    for(int i = 0; i < 100001;i++){
        remain_max[i % m] += counts[i] - counts[i] % 2;
        remain_min[i % m] += counts[i] % 2;
    }
    ll ans = 0;
    for(int i = 0; i < m;i++){
        if (i == 0){
            ans += (remain_max[i]+ remain_min[i])/2;
        }else if (i < m-i){
            ll add_one = min(remain_min[i],remain_min[m-i]);
            remain_min[i] -= add_one;
            remain_min[m-i] -= add_one;
            ans += add_one;
            if (remain_min[i] == 0){
                swap(remain_min[i],remain_min[m-i]);
                swap(remain_max[i],remain_max[m-i]);
            }
            ll add_two = min(remain_min[i],remain_max[m-i]);
            remain_min[i] -= add_two;
            remain_max[m-i] -= add_two;
            ans += add_two;
            ans += (remain_max[i] + remain_max[m-i])/2;
        }else if (i == m-i){
            ans += (remain_max[i]+ remain_min[i])/2;
        }
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
    return 0;
}