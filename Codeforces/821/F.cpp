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
  string S;
  cin >> S;
  ll w, m;
  ll n = S.size();
  cin >> w >> m;
  vector<ll> cumSum(n + 1);
  for (int i = 0; i < n; i++)
  {
    cumSum[i + 1] = cumSum[i] + (S[i] - '0');
    // cout << cumSum[i+1] << endl;
  }
  vector<ll> first_indices(9, numeric_limits<ll>::max());
  vector<ll> second_indices(9, numeric_limits<ll>::max());
  for (ll i = 0; i + w <= n; i++)
  {
    if (first_indices[(cumSum[i + w] - cumSum[i]) % 9] == numeric_limits<ll>::max()){
      first_indices[(cumSum[i + w] - cumSum[i]) % 9] = min(first_indices[(cumSum[i + w] - cumSum[i]) % 9], i);
    }else{
      second_indices[(cumSum[i + w] - cumSum[i]) % 9] = min(second_indices[(cumSum[i + w] - cumSum[i]) % 9], i);
    }

  }
  for (int i = 0; i < m; i++)
  {
    ll l, r, k;
    cin >> l >> r >> k;
    l--;
    // cout << cumSum[r] << "," << cumSum[l] << endl;
    // cout << l << endl;
    ll q = (cumSum[r] - cumSum[l]) % 9;
    // cout << q << endl;
    pair<ll, ll> ans = {numeric_limits<ll>::max(), numeric_limits<ll>::max()};
    for (int j = 0; j < 9; j++)
    {
      for (int kk = 0; kk < 9; kk++)
      {
        if (j != kk && ((j * q) + kk) % 9 == k && first_indices[j] != numeric_limits<ll>::max() && first_indices[kk] != numeric_limits<ll>::max())
        {
          ans = min(ans, {first_indices[j], first_indices[kk]});
        }else if (j == kk && ((j * q) + kk) % 9 == k && first_indices[j] != numeric_limits<ll>::max() && second_indices[kk] != numeric_limits<ll>::max()){
          ans = min(ans, {first_indices[j], second_indices[kk]});
        }
      }
    }
    if (ans != make_pair(numeric_limits<ll>::max(), numeric_limits<ll>::max()))
    {
      cout << ans.first+1 << " " << ans.second+1 << "\n";
    }
    else
    {
      cout << -1 << " " << -1 << "\n";
    }
  }
  return 0;
}
int main()
{
  // ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}