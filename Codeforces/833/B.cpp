#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  cin >> n;
  string S;
  cin >> S;
  ll ans = 0;
  for(int i = 0;i < n;i++){
    vector<ll> counts(10,0);
    ll uniques = 0;
    ll max_counts = 0;
    for(int j = 0;i+j < n && j <= 100;j++){
      counts[S[i+j] -'0']++;
      if (counts[S[i+j] -'0'] == 1){
        uniques++;
      }
      max_counts = max(max_counts, counts[S[i+j] -'0']);
      if (max_counts <= uniques){
        ans++;
      }
    }
  }
  cout << ans << "\n";
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
  cout << flush;
  return 0;
}