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

ll and_query(ll i,ll j){
  cout << "and "<< i + 1 << " " << j + 1<< endl;
  ll ans;
  scanf("%lld",&ans);
  return ans;
}

ll or_query(ll i,ll j){
  cout << "or "<< i + 1 << " " << j + 1<< endl;
  ll ans;
  scanf("%lld",&ans);
  return ans;
}
int solve()
{
  ll n, k;
  scanf("%lld", &n);
  scanf("%lld", &k);
  vector<ll> a(n);
  ll ab = and_query(0,1) + or_query(0,1);
  ll bc = and_query(1,2) + or_query(1,2);
  ll ca = and_query(2,0) + or_query(2,0);
  a[0] = (ab - bc + ca)/2;
  a[1] = (ab + bc - ca)/2;
  a[2] = (-ab + bc + ca)/2;
  for(int i = 3;i < n;i++){
    ll total = and_query(0,i) + or_query(0,i);
    a[i] = total - a[0];
  }
  sort(a.begin(),a.end());
  cout << "finish " << a[k-1] << endl;
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
  // cout << flush;
  return 0;
}
