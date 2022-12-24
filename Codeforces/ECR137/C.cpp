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
  ll n;
  cin >> n;
  string S;
  cin >> S;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  vector<ll> DPmoved(n + 1, 0);
  vector<ll> DPnot_moved(n + 1, 0);
  for (int i = 0; i + 1 < n; i++)
  {
    if (S[i] == '1' && S[i + 1] == '1')
    {
      DPmoved[i + 1] = max(DPmoved[i + 1], DPmoved[i] + a[i]);
      DPnot_moved[i + 1] = max(DPnot_moved[i + 1], DPnot_moved[i] + a[i]);
      DPnot_moved[i + 1] = max(DPnot_moved[i + 1], DPmoved[i]);
    }
    else if (S[i] == '1' && S[i + 1] == '0')
    {
      DPnot_moved[i + 1] = max(DPnot_moved[i + 1], DPnot_moved[i] + a[i]);
      DPnot_moved[i + 1] = max(DPnot_moved[i + 1], DPmoved[i]);
    }
    else if (S[i] == '0' && S[i + 1] == '1')
    {
      DPmoved[i + 1] = max(DPmoved[i + 1], DPnot_moved[i] + a[i]);
      DPnot_moved[i + 1] = max(DPnot_moved[i + 1], DPnot_moved[i]);
    }
    else if (S[i] == '0' && S[i + 1] == '0')
    {
      DPnot_moved[i+1] = max(DPnot_moved[i + 1], DPnot_moved[i]);
    }
  }
  if (S[n-1] == '1'){
    cout << max(DPnot_moved[n-1]+a[n-1],DPmoved[n-1]) << endl;
  }else{
    cout << DPnot_moved[n-1] << endl;
  }
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
