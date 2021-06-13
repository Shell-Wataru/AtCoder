#define _USE_MATH_DEFINES
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
    ll n,q;
    scanf("%lld", &n);
    scanf("%lld", &q);
    vector<ll> indexes(50,numeric_limits<ll>::max());
    for(ll i = 0;i < n;i++){
        ll c;
        scanf("%lld",&c);
        c--;
        indexes[c] = min(indexes[c],i);
    }
    for(int i = 0;i < q;i++){
        ll t;
        cin >> t;
        t--;
        if (i!= 0){
            cout << " ";
        }
        cout << indexes[t] + 1;
        for(int j = 0;j < 50;j++){
            if (indexes[j] < indexes[t]){
                indexes[j]++;
            }
        }
        indexes[t] = 0;
    }
    cout << "\n";
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
    cout << flush;
    return 0;
}
