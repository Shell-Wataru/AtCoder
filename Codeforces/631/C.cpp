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

int solve()
{
    ll n,m;
    cin >> n >> m;
    vector<ll> L(m);
    ll total_l = 0;
    bool can_clear = true;
    for(int i = 0;i < m;i++){
        cin >> L[i];
        total_l += L[i];
        if (i +  L[i] > n){
            can_clear = false;
        }
    }
    if (total_l < n){
        can_clear = false;
    }

    if (!can_clear){
        cout << -1 << endl;
    }else{
        ll selectable_l = 0;
        ll selectable_r = 0;
        ll remain = n;
        for(int i = 0;i < m;i++){
            // cout << total_l <<  " " << remain << endl;
            // cout << selectable_r << " " << selectable_l << "remain" << total_l - remain << endl;
            ll p = selectable_r - min(total_l - remain, selectable_r - selectable_l);
            cout << p + 1 << endl;
            selectable_l = p + 1;
            selectable_r = p + L[i];
            total_l -= L[i];
            remain = n - (p + L[i]);
        }
    }
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
    return 0;
}
