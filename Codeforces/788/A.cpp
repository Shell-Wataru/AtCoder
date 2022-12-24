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
  ll n;
  scanf("%lld",&n);
  vector<ll> a(n);
  ll positive = 0;
  ll negative = 0;
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
    if (a[i] > 0){
      positive++;
    }else{
      negative++;
    }
  }

  for(int i = 0;i < n;i++){
    if (i < negative){
      a[i] = - abs(a[i]);
    }else{
      a[i] = abs(a[i]);
    }
  }
  for(int i = 0;i < n-1;i++){
    if (a[i] > a[i+1]){
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
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