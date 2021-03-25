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

using namespace std;
using ll = long long;

int solve()
{
  ll n, k;
  scanf("%lld", &n);
  vector<bool> A(101,false);
  map<ll,ll> counts;
  for(int i = 0;i < n;i++){
    ll a;
    scanf("%lld",&a);
    if (!A[a]){
      A[a] = true;
    }else{
      counts[a]++;
    }
  }
  bool first = true;
  for(int i = 0;i <= 100;i++){
    if (A[i]){
      if (!first){
        cout << " ";
      }
      cout << i;
      first = false;
    }
  }
  for(auto &p:counts){
    for(int j = 0;j < p.second;j++){
      cout << " " << p.first;
    }
  }
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