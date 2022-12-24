#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n, k;
  scanf("%lld", &n);
  scanf("%lld", &k);
  vector<ll> a(n,0);
  vector<ll> b(n);
  for(int i = 0;i < n;i++){
    cin >> b[i];
  }
  // cout << "!" << endl;
  deque<pair<ll,ll>> q;
  ll total_addition = 0;
  ll total_addition_count = 0;
  ll ans = 0;
  for(ll i = n-1;i>=0;i--){
    total_addition -= total_addition_count;
    while(!q.empty() && q.front().first > i){
      total_addition_count -= q.front().second;
      q.pop_front();
    }
    // cout << i << ":" << total_addition << endl;
    if (total_addition < b[i]){
      ll d = min(i,k-1);
      ll add_count = (b[i] - total_addition + d)/(d+1);
      // cout << "add:" << add_count << endl;
      ans += add_count;
      q.emplace_back(i-d,add_count);
      total_addition_count += add_count;
      total_addition += add_count * (d+1);
    }
  }
  cout << ans << "\n";
  return 0;
}

int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}