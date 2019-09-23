#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

ll minium(ll n,ll a1,ll a2,ll k1, ll k2){
    ll zero_n = a1 * (k1 - 1) + a2 * (k2 - 1);
    return max(n - zero_n,0LL);
}

int maximum(ll n,ll a1,ll a2,ll k1, ll k2){
    ll value = 0;

    if (k1 < k2){
        value += min(n/k1,a1);
        n = n - k1 * value;
        value += min(n/k2,a2);
    }else{
        value += min(n/k2,a2);
        n = n - k2 * value;
        value += min(n/k1,a1);
    }

    return value;
}
int main()
{
    // 整数の入力
    ll n,a1,a2,k1,k2;
    cin >> a1;
    cin >> a2;
    cin >> k1;
    cin >> k2;
    cin >> n;
    ll mi = minium(n,a1,a2,k1,k2);
    ll ma = maximum(n,a1,a2,k1,k2);
    cout << mi << " " << ma << endl;
    return 0;
}