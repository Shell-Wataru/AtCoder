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

int find(ll x, ll l,ll r){
    if (l + 1 == r){
        return r;
    }

    ll center = (l + r)/2;
    if (x <= center * (center + 1) /2){
        return find(x, l, center);
    }else{
        return find(x, center, r);
    }
}
int solve(){
    ll a,b;
    cin >> a >> b;
    ll diff = abs(a - b);
    if (diff == 0){
        cout << 0 << endl;
        return 0;
    }
    ll min_over = find(diff,0,1e6);
    for (int i = 0;i< 4;i++){
        ll current  = min_over + i;
        if ( (current * (current + 1)/2  - diff) % 2 == 0 ){
            cout << current << endl;
            break;
        }
    }
    return 0;
}

int main()
{
    ll n;
    cin >> n;
    for(int i=0;i<n;i++){
        solve();
    }
   return 0;
}
