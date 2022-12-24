#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n,m;
  scanf("%lld", &n);
  scanf("%lld", &m);
  vector<pair<ll,ll>> constraints(m);
  for(int i = 0;i < m;i++){
      cin >> constraints[i].first >> constraints[i].second;
      constraints[i].first--;
       constraints[i].second--;
  }
  vector<ll> DP(1ll<<n,0);
  DP[0] = 1;
  for(int i = 0;i < 1ll<<n;i++){
      for(int j = 0;j < n;j++){
          if (!(i & (1ll<<j))){
            bool can_put = true;
            for(int k = 0;k < m;k++){
                if (constraints[k].second == j && !(i& (1ll<<constraints[k].first))){
                    can_put = false;
                    break;
                }
            }
            if (can_put){
                DP[i|(1ll<<j)] += DP[i];
            }
          }
      }
  }
  cout << DP[(1ll<<n)-1] << endl;
  return 0;
}

int main()
{
//   // 整数の入力
//   ll t;
//   cin >> t;
//   for (size_t i = 0; i < t; i++)
//   {
    solve();
//   }
//   cout << flush;
  return 0;
}