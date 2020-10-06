#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n,0);
    map<ll,ll> used;
    for (int i = 0; i < n; i++)
    {
        ll aa;
        cin >> aa;
        a[i] = aa;
        ll powers = 0;
        while(aa > 0){
            used[powers] += aa % k;
            aa /= k;
        }
    }
    sort(a.begin(),a.end(),greater<ll>());
    for (int i = 0; i < n;i++){
        if(i != 0){
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
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
    return 0;
}
