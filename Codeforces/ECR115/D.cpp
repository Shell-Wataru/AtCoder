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
  ll n;
  scanf("%lld", &n);
  vector<vector<ll>> a_pairs(n);
  vector<vector<ll>> b_pairs(n);
  for(int i = 0;i < n;i++){
    ll a,b;
    scanf("%lld",&a);
    scanf("%lld",&b);
    a--;
    b--;
    a_pairs[a].push_back(b);
    b_pairs[b].push_back(a);
  }
  ll ans = n*(n-1)*(n-2)/6;
  for(int i = 0;i < n;i++){
    for(auto b:a_pairs[i]){
      ans -= ((ll)a_pairs[i].size() - 1)*((ll)b_pairs[b].size() - 1);
    }
  }
  cout << ans << "\n";
  return 0;
}

int main()
{
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
  solve();
  }
  cout << flush;
  return 0;
}