#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const int BASE_NUM = 1000000007;

int solve()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    ll total = 0;
    ll total_length = 0;
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&a[i]);
        total_length += a[i];
    }
    sort(a.begin(),a.end(),greater<ll>());
    ll min_cut = total_length/k;
    while(a.back() <= min_cut){
        total += a.back()*a.back();
        total_length -= a.back();
        k--;
        a.pop_back();
        min_cut = total_length/k;
    }
    cout << total << endl;
    return 0;
}
int main()
{
    // 整数の入力
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
        // }
    // cout << flush;
    return 0;
}
