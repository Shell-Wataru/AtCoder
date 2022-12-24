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
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
    a[i]--;
  }
  ll l = n;
  ll r = n;
  for(int i = 0;i < n;i++){
    if (i!= a[i]){
      l = i;
      break;
    }
  }
  for(int i = l+1;i < n;i++){
    if (l == a[i]){
      r = i;
    }
  }
  reverse(a.begin()+l,a.begin()+r+1);
  for(int i =0;i < n;i++){
    if (i != 0){
      cout << " ";
    }
    cout << a[i] + 1;
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