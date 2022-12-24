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
  ll n,x;
  scanf("%lld", &n);
  scanf("%lld", &x);
  vector<ll> a(n);
  map<ll,ll> counts;
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &a[i]);
    counts[a[i]]++;
  }
  ll ans= 0;
  while(counts.size() > 0){
    auto p = *counts.begin();
    if (counts.find(p.first * x) == counts.end()){
      ans++;
    }else{
      counts[p.first * x]--;
      if (counts[p.first * x] == 0){
        counts.erase(p.first * x);
      }
    }
    if (p.second == 1){
      counts.erase(p.first);
    }else{
      counts[p.first]--;
    }
  }
  cout << ans;
  cout << "\n";
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