#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0;i < n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a.begin(),a.end());
    vector<ll> ruiseki(n+1);
    for(int i = 0;i < n;i++){
        ruiseki[i+1] = ruiseki[i] + a[i];
    }
    // cin >> m;
    for(int i = 0;i < m;i++){
        ll x,y;
        scanf("%lld",&x);
        scanf("%lld",&y);
        cout << ruiseki[n-(x-y)]-ruiseki[n-x] << "\n";
    }
    return 0;
}
int main()
{
    // ll t;
    // cin >> t;
    // for (int i = 1; i <= t; i++)
    // {
        solve();
    // }
    cout << flush;
    return 0;
}
