#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
using namespace std;
using ll = long long;

ll same_diff_number(ll head, ll length, ll diff)
{
  ll ans = 0;
  for (int i = 0; i < length; i++)
  {
    if (ans >= numeric_limits<ll>::max()/10){
      return 0;
    }
    if (head < 0 || head > 9){
      return 0;
    }
    ans *= 10;
    ans += head;
    head -= diff;
  }
  head += diff;
  if (head >= 0 && head <= 9)
  {
    return ans;
  }
  else
  {
    return 0;
  }
}

bool is_same_diff_number(ll X)
{
  string x = to_string(X);
  for (int i = 0; i < x.size() - 2; i++)
  {
    if (x[i] - x[i + 1] != x[i + 1] - x[i + 2])
    {
      return false;
    }
  }
  return true;
}

int main()
{
  ll X;
  cin >> X;
  ll ans = numeric_limits<ll>::max();
  // cout << ans << endl;
  for(int h = 1;h <= 9;h++){
    for(int l = 1;l < 19;l++){
      for(int d = -9; d <= 9;d++){
        if (same_diff_number(h,l,d) >= X){
          ans = min(ans,same_diff_number(h,l,d));
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
