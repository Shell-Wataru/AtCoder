#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }

  unordered_set<ll> inserted;
  inserted.insert(0);
  ll current = 0;
  ll ans = 0;
  for(int i = 0;i < n;i++){
    current ^= a[i];
    if (inserted.count(current)){
      inserted.clear();
      inserted.insert(0);
      current = 0;
    }else{
      inserted.insert(current);
      ans++;
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