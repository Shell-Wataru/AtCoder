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
int BASE_NUM = 998244353;

int solve()
{
  ll n,l,r;
  scanf("%lld",&n);
  scanf("%lld",&l);
  scanf("%lld",&r);
  vector<ll> l_counts(n);
  vector<ll> r_counts(n);
  ll l_total = l;
  ll r_total = r;
  for(int i = 0;i < l;i++){
    ll c;
    scanf("%lld",&c);
    c--;
    l_counts[c]++;
  }
  for(int i = 0;i < r;i++){
    ll c;
    scanf("%lld",&c);
    c--;
    r_counts[c]++;
  }
  ll cost = 0;
  for(int i = 0;i < n;i++){
    ll lr_min = min(l_counts[i],r_counts[i]);
    l_counts[i] -= lr_min;
    r_counts[i] -= lr_min;
    l_total -= lr_min;
    r_total -= lr_min;
  }
  // cout << l_total << " " << r_total << endl;
  for(int i = 0;i < n;i++){
    while (l_counts[i] >= 2 && l_total > r_total){
      l_counts[i] -= 2;
      l_total -= 2;
      cost++;
    }
    while (r_counts[i] >= 2 && l_total < r_total){
      r_counts[i] -= 2;
      r_total -= 2;
      cost++;
    }
  }
  // cout << l_total << " " << r_total << endl;
  // cout << cost << endl;
  cost += min(l_total,r_total);
  cost += abs(l_total-r_total);
  cout << cost << "\n";
  return 0;
}

int main()
{
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}