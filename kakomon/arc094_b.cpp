#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>

using namespace std;
using ll = long long;

ll clear_index(ll a,ll l,ll r,ll target){
    if (l+1 == r){
        return l;
    }
    ll center = (l+r)/2;
    if ((a+center) % 2 == 0){
        ll value1 = (a+center)/2;
        ll value2 = (a+center)/2;
        if (value1 * value2 < target){
            return clear_index(a,center,r,target);
        }else{
            return clear_index(a,l,center,target);
        }
    }else{
        ll value1 = (a+center)/2;
        ll value2 = (a+center)/2 + 1;
        if (value1 * value2 < target){
            return clear_index(a,center,r,target);
        }else{
            return clear_index(a,l,center,target);
        }
    }
}
int main()
{
    // 整数の入力
    ll Q;
    cin >> Q;
    for(int i = 0;i < Q;i++){
        ll a,b;
        cin >> a >> b;
        if (a > b){
            swap(a,b);
        }

        if (a == b || a+1 == b){
            cout << 2*(a -1) << "\n";
        }else{
            ll ans = 2*(a -1);
            ans += clear_index(a,a+1,b,a*b) - a;
            cout << ans << "\n";
        }
    }
    cout <<flush;
    return 0;
}