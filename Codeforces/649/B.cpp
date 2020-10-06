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

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n;
  cin >> n;
  vector<ll> S(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &S[i]);
  }
  vector<ll> ans;
  for (int i = 0; i < n; i++)
  {
    if (i == 0 || i == n - 1)
    {
      ans.push_back(S[i]);
    }
    else if (S[i - 1] < S[i] && S[i] > S[i + 1])
    {
      ans.push_back(S[i]);
    }
    else if (S[i - 1] > S[i] && S[i] < S[i + 1])
    {
      ans.push_back(S[i]);
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
  {
    if (i != 0)
    {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << endl;
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
