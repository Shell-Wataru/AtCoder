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
const ll BASE_NUM = 1000000007;

int solve()
{
    ll n,q;
    scanf("%lld", &n);
    scanf("%lld", &q);
    vector<ll> A(n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&A[i]);
    }
    vector<ll> DPp(n+1,0);
    vector<ll> DPn(n+1,0);
    for(int i = 0;i < n;i++){
        DPp[i+1] = max(DPp[i],DPn[i] + A[i]);
        DPn[i+1] = max(DPn[i],DPp[i] - A[i]);
    }
    cout << max(DPn[n],DPp[n]) << endl;
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
    // cout << flush;
    return 0;
}
