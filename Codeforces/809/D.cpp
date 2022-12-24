#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;

int value(vector<int> &a, int k, int center, int &maximum, int &minimum)
{
  ll n = a.size();
  minimum = numeric_limits<int>::max();
  maximum = numeric_limits<int>::min();
  for (int j = 0; j < n; j++)
  {
    int p = min(a[j] / (center + 1) + 1, k);
    minimum = min(minimum, a[j] / p);
    maximum = max(maximum, a[j] / p);
  }
  return maximum - minimum;
}

int solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  if (a[n-1]/ k == a[0]/k)
  {
    cout << 0 << "\n";
    return 0;
  }
  int ans = a[n-1]/ k - a[0]/k;
  int maximum = min(1000001, a[0] + ans);
  int minimum = a[0];
  int last_maximum = -1;

  while (last_maximum != maximum && maximum > 0)
  {
    // cout << maximum << endl;
    last_maximum = maximum;
    maximum = min(maximum,minimum + ans);
    // if (maximum == 1){
    //   break;
    // }
    ans = min(ans, value(a, k, maximum - 1, maximum, minimum));
  }
  cout << ans << "\n";
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
