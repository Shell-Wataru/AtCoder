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
  vector<ll> b(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  for(int i = 0;i < n;i++){
    scanf("%lld",&b[i]);
  }
  ll plus_count = 0;
  ll minus_count = 0;
  for(int i = 0;i < n;i++){
    if (a[i] == 1 && b[i] == 0){
      minus_count++;
    }
    if (a[i] == 0 && b[i] == 1){
      plus_count++;
    }
  }
  cout << min(plus_count+minus_count,abs(plus_count-minus_count)+1) << "\n";
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