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

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int minimum_add(vector<ll> &a,ll &k,ll l,ll r){
    // cout << l << " "<< r << endl;
    if (l + 1 == r){
        return r;
    }

    ll center = (l+r)/2;
    ll current_total = a[0] + center;

    bool is_ok = true;
    for(int i = 1;i < a.size();i++){
        if (a[i]*100 > k*current_total){
            is_ok = false;
            break;
        }else{
            current_total += a[i];
        }
    }
    if (is_ok){
        return minimum_add(a,k,l,center);
    }else{
        return minimum_add(a,k,center,r);
    }
}
int solve()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> A(n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&A[i]);
    }
    ll add = minimum_add(A,k,-1,1000000000000000ll);
    cout << add << endl;
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
