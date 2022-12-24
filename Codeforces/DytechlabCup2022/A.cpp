
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
  ll n,k;
  scanf("%lld",&n);
  scanf("%lld",&k);
  string S;
  cin >> S;
  string ans(k,'*');
  vector<ll> counts(26,0);
  for(auto c:S){
    counts[c-'a']++;
  }
  for(int i = 0;i < k;i++){
    ll a = n/k;
    for(int j = 0;j < min(n/k,25ll);j++){
      if (counts[j]>0){
        counts[j]--;
      }else{
        a = j;
        break;
      }
    }
    ans[i] = 'a' + a;
  }
  cout << ans << "\n";
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
  cout << flush;
  return 0;
}