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
const ll BASE_NUM = 1000000007;

ll value(ll i,ll max_n){
    if (i == 0){
        return numeric_limits<ll>::max();
    }else if(i == max_n){
        return numeric_limits<ll>::max();
    }
    cout << "? " << i << endl;
    ll v;
    scanf("%lld",&v);
    return v;
}

ll three_search(ll l,ll r,ll max_n){
    ll t1 = (2*l + r)/3;
    ll t2 = (l + 2 *r)/3;
    ll t1_value = value(t1,max_n);
    ll t2_value = value(t2,max_n);

    if (l + 2 == r){
        if(t1_value <= t2_value){
            return t1;
        }else{
            return t2;
        }
    }else{
        if(t1_value <= t2_value){
            return three_search(l,t2,max_n);
        }else{
            return three_search(t1,r,max_n);
        }
    }
}

int solve()
{
    ll n;
    cin >> n;
    ll answer = three_search(0,n+1,n+1);
    cout << "! " << answer << endl;
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
