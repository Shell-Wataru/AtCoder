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

int solve()
{
    ll n;
    scanf("%lld", &n);
    vector<ll> A(n);
    for(int i = 0;i < n;i++){
        scanf("%lld",&A[i]);
    }
    sort(A.begin(),A.end());
    ll Q;
    cin >> Q;
    for(int i = 0;i < Q;i++){
        ll b;
        scanf("%lld",&b);

        auto iter = lower_bound(A.begin(),A.end(),b);
        ll ans = numeric_limits<ll>::max();
        if (iter != A.end()){
            ans = min(ans,abs(*iter- b));
        }
        if (iter != A.begin()){
            iter--;
            ans = min(ans,abs(*iter- b));
        }
        cout << ans << endl;
    }
    return 0;
}

int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    return 0;
}