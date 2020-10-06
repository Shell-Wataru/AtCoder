#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

ll first_eats_count(ll n,ll l,ll r){
    if(l + 1 == r){
        return l;
    }
    ll center = (l+r)/2;
    ll eats = center * (center + 1)/2;
    if (eats <= n){
        return first_eats_count(n,center,r);
    }else{
        return first_eats_count(n,l,center);
    }
};

ll eats_count(ll n,ll start,ll l,ll r){
    // cout << l << " " << r << endl;
    if(l + 1 == r){
        return l;
    }
    ll center = (l+r)/2;
    ll eats;
    if (center == 0){
        eats = 0;
    }else{
        eats = center * (start + start + 2 * (center-1))/2;
    }
    // cout << eats << endl;
    if (eats <= n){
        return eats_count(n,start,center,r);
    }else{
        return eats_count(n,start,l,center);
    }
};

string solve(){
    ll left_pans,right_pans;
    cin >> left_pans >> right_pans;
    ll first_eats = first_eats_count(abs(left_pans- right_pans),0,1000000000ll*2);
    // cout << first_eats << endl;
    if (left_pans >= right_pans){
        left_pans -= first_eats * (first_eats + 1)/2;
    }else{
        right_pans -= first_eats * (first_eats + 1)/2;
    }
    // cout << left_pans << " " << right_pans << endl;
    ll left_eat = 0;
    ll right_eat = 0;
    if (left_pans >= right_pans){
        left_eat = eats_count(left_pans,first_eats + 1,0,1000000000ll*2);
        right_eat = eats_count(right_pans,first_eats + 2,0,1000000000ll*2);
        if (left_eat > 0){
            left_pans -= left_eat * (first_eats + 1 + (first_eats + 1 + (left_eat - 1) * 2))/2;
        }
        if (right_eat > 0){
            right_pans -= right_eat * (first_eats + 2 + (first_eats + 2 + (right_eat - 1) * 2))/2;
        }
    }else{
        left_eat = eats_count(left_pans,first_eats + 2,0,1000000000ll*2);
        right_eat = eats_count(right_pans,first_eats + 1,0,1000000000ll*2);
        if (left_eat > 0){
            left_pans -= left_eat * (first_eats + 2 + (first_eats + 2 + (left_eat - 1) * 2))/2;
        }
        if (right_eat > 0){
            right_pans -= right_eat * (first_eats + 1 + (first_eats + 1 + (right_eat - 1) * 2))/2;
        }
    }

    return to_string(first_eats + left_eat + right_eat) + " " + to_string(left_pans) +  " " + to_string(right_pans);
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}