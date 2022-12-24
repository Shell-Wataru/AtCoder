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
    cin >> n;
    vector<ll> a(n);
    for(int i = 0;i < n;i++){
        scanf("%lld",&a[i]);
    }
    cin >> m;
    ll index = 0;
    for(int i = 0;i < m;i++){
        ll b;
        scanf("%lld",&b);
        index += b;
        index %= n;
    }
    cout << a[index] << "\n";
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    cout << flush;
    return 0;
}
