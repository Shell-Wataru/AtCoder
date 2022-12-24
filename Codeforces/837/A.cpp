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
  map<ll,ll> counts;
  for(int i = 0;i < n;i++){
    ll a;
    cin >> a;
    counts[a]++;
  }
  auto p1 = *counts.begin();
  auto p2 = *counts.rbegin();
  if (p1.first != p2.first){
    cout << p1.second * p2.second*2 << "\n";
  }else{
    cout << p1.second * (p2.second-1) << "\n";
  }
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