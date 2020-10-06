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

ll min_hot_pours(ll h,ll c,ll t, ll l,ll r){
    if (l + 1 == r){
        return r;
    }
    ll center = (l+r)/2;
    if (center * h + (center - 1) * c >  t * (2 * center - 1)){
        return min_hot_pours(h,c,t,center,r);
    }else{
        return min_hot_pours(h,c,t,l,center);
    }
}

int solve()
{
    // cout << "==" << endl;
    ll h,c,t;
    cin >> h >> c >> t;
    if (2 * t <= h + c){
        cout << 2 << endl;
    }else{
        ll hot_pours = min_hot_pours(h,c,t,1,1e9);
        double diff_a = abs(t - 1.0*(hot_pours * h + (hot_pours - 1) * c)/(2*hot_pours - 1));
        hot_pours--;
        double diff_b = abs(t - 1.0*(hot_pours * h + (hot_pours - 1) * c)/(2*hot_pours - 1));
        if (diff_b <= diff_a){
            cout << 2 * hot_pours - 1 << endl;
        }else{
            hot_pours++;
            cout << 2 * hot_pours - 1 << endl;
        }
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    // cout << flush;
    return 0;
}
