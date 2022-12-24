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
  scanf("%lld", &n);
  vector<double> DP(n + 1, 0);
  vector<double> factorial(n + 1);
  factorial[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    factorial[i] = factorial[i - 1] * i;
  }
  DP[0] = 0;
  DP[1] = 0;
  for (int i = 2; i <= n; i++)
  {
    double draw_rate = 0;
    for (int g = 0; g <= i; g++)
    {
      for (int c = 0; i - g - c >= 0; c++)
      {
        int p = i - g - c;
        if ((g == c && c == p) || ((g == 0) + (c == 0) + (p == 0) == 2))
        {
          draw_rate += factorial[i] / (factorial[g] * factorial[c] * factorial[p]) / pow(3, i);
        }
        else if (g == c)
        {
          if (p == 0 || g < p)
          {
            DP[i] += (DP[g] + 1) * factorial[i] / (factorial[g] * factorial[c] * factorial[p]) / pow(3, i);
          }
          else
          {
            DP[i] += (DP[p] + 1) * factorial[i] / (factorial[g] * factorial[c] * factorial[p]) / pow(3, i);
          }
        }
        else if (c == p)
        {
          if (g == 0 || c < g)
          {
            DP[i] += (DP[c] + 1) * factorial[i] / (factorial[g] * factorial[c] * factorial[p]) / pow(3, i);
          }
          else
          {
            DP[i] += (DP[g] + 1) * factorial[i] / (factorial[g] * factorial[c] * factorial[p]) / pow(3, i);
          }
        }
        else if (p == g)
        {
          if (c == 0 || p < c)
          {
            DP[i] += (DP[p] + 1) * factorial[i] / (factorial[g] * factorial[c] * factorial[p]) / pow(3, i);
          }
          else
          {
            DP[i] += (DP[c] + 1) * factorial[i] / (factorial[g] * factorial[c] * factorial[p]) / pow(3, i);
          }
        }
        else if (g == 0)
        {
          DP[i] += (DP[min(p, c)] + 1) * factorial[i] / (factorial[g] * factorial[c] * factorial[p]) / pow(3, i);
        }
        else if (p == 0)
        {
          DP[i] += (DP[min(c, g)] + 1) * factorial[i] / (factorial[g] * factorial[c] * factorial[p]) / pow(3, i);
        }
        else if (c == 0)
        {
          DP[i] += (DP[min(g, p)] + 1) * factorial[i] / (factorial[g] * factorial[c] * factorial[p]) / pow(3, i);
        }
        else
        {
          DP[i] += (DP[min(g, min(c, p))] + 1) * factorial[i] / (factorial[g] * factorial[c] * factorial[p]) / pow(3, i);
        }
      }
    }
    // cout << draw_rate << endl;
    // cout << DP[i] << endl;
    DP[i] /= 1.0 - draw_rate;
    DP[i] += 1 / (1.0 - draw_rate) - 1;
  }
  cout << fixed << setprecision(12) << DP[n] << endl;
  return 0;
}

int main()
{
  // ll t;
  // cin >> t;

  // for (int i = 1; i <= t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}