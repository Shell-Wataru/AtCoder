#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

double two_expectation(ll a, ll b, ll c)
{
  double ans = 0;
  ll times = 1;
  ll total = a + b;
  double prob = 1.0;
  while (true)
  {
    ans += prob * times * b / total;
    if (a == 0)
    {
      break;
    }
    else
    {
      prob = prob * a / total;
      a = max(a - c, 0ll);
      b = total - a;
      times++;
    }
  }
  return ans;
}

int solve()
{
  ll c, m, p, v;
  double _c, _m, _p, _v;
  scanf("%lf", &_c);
  scanf("%lf", &_m);
  scanf("%lf", &_p);
  scanf("%lf", &_v);
  ll base = 1000000ll;
  c = round(_c * base);
  m = round(_m * base);
  p = round(_p * base);
  v = round(_v * base);
  // cout << c << m << p << v << endl;
  ll delta = v / 2;
  ll max_c_choose = 4 * (c + delta - 1) / delta + 1;
  ll max_m_choose = 4 * (m + delta - 1) / delta + 1;
  double ans = 0;
  vector<vector<double>> probabilities(max_c_choose + 2, vector<double>(max_m_choose + 2, 0));
  probabilities[0][0] = 1.0;
  for (int i = 0; i <= max_c_choose; i++)
  {
    for (int j = 0; j <= max_m_choose; j++)
    {
      ll current_c = c - delta * (3 * i - i - j);
      ll current_m = m - delta * (3 * j - i - j);
      ll current_p = base - current_c - current_m;
      if (current_c  < 0)
      {
        current_c += 2 * delta;
        current_m += current_c/2 - delta;
        current_p += current_c/2 - delta;
        current_c = 0;
      }
      else if (current_m < 0)
      {
        current_m += 2 * delta;
        current_c += current_m/2 - delta;
        current_p += current_m/2 - delta;
        current_m = 0;
      }

      double cc = 1.0 * current_c / base;
      double mm = 1.0 * current_m / base;
      double pp = 1.0 * current_p / base;
      if (probabilities[i][j] > 0)
      {
        // cout << i << "," << j <<":" << endl;
        // cout << current_c << "," << current_m << "," << current_p << endl;
        // if (current_c == 0){
        //   cout << two_expectation(current_m, current_p, v) << endl;
        // }
        // if (current_m == 0){
        //   cout << two_expectation(current_c, current_p, v) << endl;
        // }
        // if (current_c == 0 && current_m == 0){
        //   cout <<"!!" << endl;
        // }
      }

      if (current_c == 0)
      {
        ans += probabilities[i][j] * (i + j + two_expectation(current_m, current_p, v));
      }
      else if (current_m == 0)
      {
        ans += probabilities[i][j] * (i + j + two_expectation(current_c, current_p, v));
      }
      else
      {
        probabilities[i + 1][j] += cc * probabilities[i][j];
        probabilities[i][j + 1] += mm * probabilities[i][j];
        ans += (i + j + 1) * pp * probabilities[i][j];
      }
    }
  }
  cout << fixed << setprecision(12) << ans << "\n";
  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
