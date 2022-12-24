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
  ll r1,c1,r2,c2,r3,c3;
  ll x,y;
  set<pair<ll,ll>> s;
  scanf("%lld",&r1);
  scanf("%lld",&c1);
  scanf("%lld",&r2);
  scanf("%lld",&c2);
  scanf("%lld",&r3);
  scanf("%lld",&c3);
  scanf("%lld",&x);
  scanf("%lld",&y);
  s.insert({r1,c1});
  s.insert({r2,c2});
  s.insert({r3,c3});
  if (s.count({1,1}) && s.count({1,2}) && s.count({2,1})){
    if (x == 1 || y == 1){
      cout << "YES" << "\n";
    }else{
      cout << "NO" << "\n";
    }
  }else if (s.count({1,n}) && s.count({1,n-1}) && s.count({2,n})){
    if (x == 1 || y == n){
      cout << "YES" << "\n";
    }else{
      cout << "NO" << "\n";
    }
  }else if(s.count({n,1}) && s.count({n-1,1}) && s.count({n,2})){
    if (x == n || y == 1){
      cout << "YES" << "\n";
    }else{
      cout << "NO" << "\n";
    }
  }else if (s.count({n,n}) && s.count({n,n-1}) && s.count({n-1,n})){
    if (x == n || y == n){
      cout << "YES" << "\n";
    }else{
      cout << "NO" << "\n";
    }
  }else{
    ll rr = r1 ^ r2 ^  r3;
    ll cc = c1 ^ c2 ^  c3;
    if ( (x-rr) % 2 == 0 && (y-cc) % 2 == 0){
      cout << "NO" << "\n";
    }else{
      cout << "YES" << "\n";
    }
  }

  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
