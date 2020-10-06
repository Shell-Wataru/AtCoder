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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n,0);
    map<ll,ll> used;
    for (int i = 0; i < n; i++)
    {
        ll aa;
        cin >> aa;
        a[i] = aa;
        ll powers = 0;
        while(aa > 0){
            used[powers] += aa % k;
            powers++;
            aa /= k;
        }
    }
    bool is_clear = true;
    for(auto p:used){
        // cout << p.second<< ",";
        if (p.second > 1){
            is_clear = false;
        }
    }
    // cout << endl;
    if (is_clear){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}
