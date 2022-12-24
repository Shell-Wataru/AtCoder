#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;


ll ten_pow(ll k){
    if (k < 0){
        return 0;;
    }
    if (k == 0){
        return 1;
    }else{
        ll half = ten_pow(k/2);
        if (k % 2 == 0){
            return half * half;
        }else{
            return half * half * 10;
        }
    }
}

int solve(){
    ll l,r;
    cin >> l >> r;
    ll ans = 0;

    // ans = max(ans,r- max(r/10 + 1,l) + 1);
    for(int i = 0; i <= 10;i++){

        ll r1= min(r,ten_pow(i+1)-1);
        ll l1 = l;
        l1 = max(l1,r1/10+1);
        l1 = max(l1,ten_pow(i-1)+1);
        if (r1/ten_pow(i) > 1){
            l1 = max(l1,ten_pow(i));
        }
        for(int j = i;j >= 0;j--){
            l1 = max(l1, r1 % ten_pow(j) + 1);
        }
        // l1 = max(l1,r1-ten_pow(i)+1);
        // cout << r1 << "~" << l1 << endl;
        ans = max(ans,r1-l1 + 1);
    }
    cout << ans << endl;
    return 0;
}


int main()
{
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}