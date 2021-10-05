
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
  ll n,m;
  scanf("%lld",&n);
  scanf("%lld",&m);
  string S;
  cin >> S;
  vector<ll> nearest_alive_left(n,numeric_limits<ll>::max());
  vector<ll> nearest_alive_right(n,numeric_limits<ll>::max());
  ll alive_disntace = numeric_limits<ll>::max()/2;
  for(int i = 0;i < n;i++){
    if (S[i] == '1'){
      alive_disntace = 0;
    }else{
      alive_disntace++;
    }
    nearest_alive_left[i] = min(nearest_alive_left[i],alive_disntace);
  }
  alive_disntace = numeric_limits<ll>::max()/2;
  for(int i = n-1;i >= 0;i--){
    if (S[i] == '1'){
      alive_disntace = 0;
    }else{
      alive_disntace++;
    }
    nearest_alive_right[i] = min(nearest_alive_right[i],alive_disntace);
  }
  for(int i = 0;i < n;i++){
    if (nearest_alive_right[i] == 0 || (min(nearest_alive_left[i],nearest_alive_right[i]) <= m && nearest_alive_left[i] != nearest_alive_right[i]) ){
      cout << 1;
    }else{
      cout << 0;
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