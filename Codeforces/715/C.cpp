#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int solve()
{
    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    for (size_t i = 0; i < n; i++)
    {
      scanf("%lld",&a[i]);
    }
    sort(a.begin(),a.end());
    vector<vector<ll>> DP(n,vector<ll>(n));
    for(int i = 0;i < n;i++){
      for(int j = 0;i + j < n;j++){
        if (i == 0){
          DP[j][i+j] = 0;
        }else {
          DP[j][i+j] = min(DP[j][i+j-1] + a[i+j] - a[j],DP[j+1][i+j] + a[i+j] - a[j]);
        }
      }
    }
    cout << DP[0][n-1] << "\n";
    return 0;
}

int main()
{
    // // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    cout << flush;
    return 0;
}
