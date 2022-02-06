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
    ll n;
    scanf("%lld", &n);
    vector<ll> a(n);
    for(int i = 0;i < n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a.begin(),a.end());
    for(int i =0;i < n/2;i++){
        cout << a[i+1] << " " << a[0] << "\n";
    }
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
