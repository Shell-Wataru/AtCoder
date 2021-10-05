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
#include <numeric>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> ans(k);
    iota(ans.begin(),ans.end(),1);
    reverse(ans.begin() + k - (n-k) - 1, ans.end());
    for(int i = 0;i < k;i++){
        if (i!= 0){
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
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
