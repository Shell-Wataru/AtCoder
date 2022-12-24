#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;

int solve()
{
  ll N;
  cin >>  N;
  vector<ll> a(N);
  vector<ll> b(N);
  for(int i = 0;i < N;i++){
    cin >> a[i];
  }
  for(int i = 0;i < N;i++){
    cin >> b[i];
  }
  for(int i = 0;i < N;i++){
    if (a[i] < b[i]){
      swap(a[i],b[i]);
    }
  }
  ll ans = 0;
  for(int i = 0;i < N-1;i++){
    ans += abs(a[i] - a[i+1]);
    ans += abs(b[i] - b[i+1]);
  }
  cout << ans << "\n";
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