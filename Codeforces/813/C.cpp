#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
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
  scanf("%lld", &n);
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  vector<bool> changed(n+1,false);
  for(int i = 1;i < n;i++){
    if (changed[a[i]]){
      a[i] = 0;
    }
    if (a[i] < a[i-1]){
      ll current = i-1;
      while(current >= 0 && a[current] > 0){
        changed[a[current]] = true;
        a[current] = 0;
        current--;
      }
    }
  }
  ll ans = 0;
  for(auto c:changed){
    if (c){
      ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}

int main()
{
  // cout << "!" << endl;
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
