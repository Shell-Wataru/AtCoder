#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;

ll answer(vector<ll> &proficients,ll l, ll r){
  if (l+1 == r){
    return r;
  }
  ll center = (l+r)/2;
  ll free_tasks = 0;
  for(auto p:proficients){
    if (p >= center){
      free_tasks -= p -center;
    }else{
      free_tasks += (center-p)/2;
    }
  }
  if (free_tasks >= 0){
    return answer(proficients,l,center);
  }else{
    return answer(proficients,center,r);
  }
}

int solve()
{
  ll n,m;
  cin >> n;
  cin >> m;
  vector<ll> proficients(n,0);
  for(int i = 0;i < m;i++){
    ll a;
    cin >> a;
    a--;
    proficients[a]++;
  }
  cout << answer(proficients,0,2*m) << "\n";
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
