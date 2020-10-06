#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int main()
{
  // 整数の入力
  ll N, M;
  cin >> N;
  map<ll,ll> plus_counts;
  map<ll,ll> minus_counts;
  vector<pair<ll,ll>> A;
  for(int i = 1;i<= N;i++){
    ll a;
    cin >> a;
    A.push_back({a,i});
    // cout << a - i << endl;
    // cout << a + i << endl;
    plus_counts[a - i]++;
    minus_counts[a + i]++;
  }
  // cout << " ==" << endl;
  ll ans = 0;
  for(auto a:A){
    // cout << a.first << " " << a.second << endl;
    ans += plus_counts[- a.first -  a.second];
    ans += minus_counts[- a.first + a.second];
  }
  cout << ans /2 << endl;

  return 0;
}
