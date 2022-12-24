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
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
  ll n,m;
  scanf("%lld",&n);
  scanf("%lld",&m);
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  ll k;
  scanf("%lld",&k);
  vector<ll> b(k);
  for(int i = 0;i < k;i++){
    scanf("%lld",&b[i]);
  }
  vector<pair<ll,ll>> runlength_a;
  vector<pair<ll,ll>> runlength_b;
  for(int i = 0;i < n;i++){
    ll c= 1;
    while(a[i] % m == 0){
      a[i] /= m;
      c *= m;
    }
    if (runlength_a.empty() || runlength_a.back().first != a[i]){
      runlength_a.push_back({a[i],c});
    }else{
      runlength_a.back().second += c;
    }
  }
  for(int i = 0;i < k;i++){
    ll c= 1;
    while(b[i] % m == 0){
      b[i] /= m;
      c *= m;
    }
    if (runlength_b.empty() || runlength_b.back().first != b[i]){
      runlength_b.push_back({b[i],c});
    }else{
      runlength_b.back().second += c;
    }
  }
  if (runlength_a == runlength_b){
    cout << "Yes\n";
  }else{
    cout << "No\n";
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
  cout << flush;
  return 0;
}
