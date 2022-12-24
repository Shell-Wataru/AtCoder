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

int solve()
{
  ll n,k;
  cin >> n >> k;
  vector<ll> answer(n+1);
  vector<vector<ll>> currents(2,vector<ll>(n+1,0));
  currents[0][0] = 1;
  ll min_v = 0;
  ll index = 0;
  while(min_v + k <=  n){
    ll next_index = (index+1)%2;
    for(int i = min_v;i+k <= n;i++){
      currents[next_index][i+k] += currents[index][i];
      currents[next_index][i+k] += currents[next_index][i];
      currents[next_index][i+k] %= 998244353;
      answer[i+k] +=currents[next_index][i+k];
      answer[i+k] %= 998244353;
    }
    fill(currents[index].begin()+min_v,currents[index].end(),0);
    index = (index + 1) % 2;
    min_v+= k;
    k++;
  }
  for(int i = 1;i <= n;i++){
    cout << answer[i] << " ";
  }
  cout << "\n";
  return 0;
}
int main()
{
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}
