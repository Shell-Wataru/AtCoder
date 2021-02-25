#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n,k;
  cin >> n >> k;
  ll ans = 0;
  ll median_index = (n+1)/2 - 1;
  deque<ll> q;
  for(int i = 0;i < n*k;i++){
    ll a;
    cin >> a;
    q.push_back(a);
  }
  // cout << median_index << endl;
  for(int i = 0;i < k;i++){
    for(int j = 0;j < median_index;j++){
      q.pop_front();
    }
  }
  for(int i = 0;i < k;i++){
    for(int j = median_index;j < n;j++){
      if (j == median_index){
        ans+= q.front();
      }
      q.pop_front();
    }
  }
  cout << ans << endl;
  return 0;
}
int main()
{
  ll t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  return 0;
}