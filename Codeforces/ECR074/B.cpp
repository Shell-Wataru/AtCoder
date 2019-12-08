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
void solve(){
    ll n,r;
    set<ll,greater<ll>> X;
    cin >> n >> r;
    for(int i = 0;i<n;i++){
        ll x;
        cin >> x;
        X.insert(x);
    }

    ll i = 0;
    for (auto x:X){
        if (x - i * r <= 0){
            cout << i << endl;
            return;
        }
        i++;
    }
    cout << i << endl;
    return;
}
int main()
{
    ll q;
    cin >> q;
    for(int i =0;i<q;i++){
        solve();
    }
   return 0;
}