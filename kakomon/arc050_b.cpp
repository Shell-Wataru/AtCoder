#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

ll bouquet_count(ll R,ll B,ll x,ll y,ll l,ll r){
    if (l+1 == r){
        return l;
    }
    ll center = (l+r)/2;
    if (R-center < 0 || B -center < 0){
        return bouquet_count(R,B,x,y,l,center);
    }else{
        ll red_count = (R-center)/(x-1);
        ll blue_cout = (B-center)/(y-1);
        if (red_count + blue_cout >= center){
            return bouquet_count(R,B,x,y,center,r);
        }else{
            return bouquet_count(R,B,x,y,l,center);
        }
    }

}

int solve()
{
    ll R,B,x,y;
    cin >> R >> B >> x >> y;
    cout << bouquet_count(R,B,x,y,0,numeric_limits<ll>::max()) << "\n";
    return 0;
}

int main()
{
    // // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
