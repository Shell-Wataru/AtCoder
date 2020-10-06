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
ll BASE_NUM = 998244353;

int solve()
{
    ll n,k;
    scanf("%lld",&n);
    scanf("%lld",&k);
    // cout << n << endl;
    // cout << k << endl;
    vector<ll> a(n);
    for(int i = 0;i < n;i++){
        scanf("%lld",&a[i]);
    }

    ll max_value = 0;
    for(int i = 0;i < k;i++){
        max_value += n - i;
    }
    vector<ll> indexes;
    for(int i = 0;i< n;i++){
        if (a[i] > n - k){
            indexes.push_back(i);
        }
    }
    ll counts = 1;
    for(int i = 1;i < indexes.size();i++){
        counts = counts * (indexes[i] - indexes[i-1]) % BASE_NUM;
    }
    cout << max_value << " " << counts << endl;
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
