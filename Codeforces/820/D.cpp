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
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&a[i]);
  }
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&b[i]);
  }
  deque<ll> c(n);
  for(int i = 0;i < n;i++){
    c[i] = b[i]-a[i];
  }
  sort(c.begin(),c.end());
  ll ans = 0;
  while(c.size() >= 2){
    if (c.front()+ c.back() >= 0){
      c.pop_front();
      c.pop_back();
      ans++;
    }else{
      c.pop_front();
    }
  }
  cout << ans;

  cout << "\n";
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
