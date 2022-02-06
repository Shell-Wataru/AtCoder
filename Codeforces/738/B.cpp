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
#include <numeric>

using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int solve()
{
  ll n;
  scanf("%lld", &n);
  string S;
  cin >> S;
  vector<pair<char, ll>> runlength;
  for (int i = 0; i < n; i++)
  {
    if (runlength.empty())
    {
      runlength.push_back({S[i], 1});
    }
    else if (runlength.back().first == S[i])
    {
      runlength.back().second++;
    }
    else
    {
      runlength.push_back({S[i], 1});
    }
  }
  string ans = "";

  for (int i = 0; i < runlength.size(); i++)
  {
    // cout << runlength[i].first << "~" << runlength[i].second << endl;
    if (runlength[i].first == '?')
    {
      if (i == 0)
      {
        string add;
        if (runlength[i + 1].first == 'R')
        {

          for (int j = 0; j < runlength[i].second; j++)
          {
            if (j % 2 == 0)
            {
              add += 'B';
            }
            else
            {
              add += 'R';
            }
          }
        }
        else
        {
          for (int j = 0; j < runlength[i].second; j++)
          {
            if (j % 2 == 0)
            {
              add += 'R';
            }
            else
            {
              add += 'B';
            }
          }
        }
        reverse(add.begin(), add.end());
        ans += add;
      }
      else if (i == runlength.size() - 1)
      {
        if (runlength[i - 1].first == 'R')
        {
          for (int j = 0; j < runlength[i].second; j++)
          {
            if (j % 2 == 0)
            {
              ans += 'B';
            }
            else
            {
              ans += 'R';
            }
          }
        }
        else
        {
          for (int j = 0; j < runlength[i].second; j++)
          {
            if (j % 2 == 0)
            {
              ans += 'R';
            }
            else
            {
              ans += 'B';
            }
          }
        }
      }
      else if (runlength[i - 1].first == runlength[i + 1].first)
      {
        if (runlength[i - 1].first == 'R')
        {
          for (int j = 0; j < runlength[i].second; j++)
          {
            if (j % 2 == 0)
            {
              ans += 'B';
            }
            else
            {
              ans += 'R';
            }
          }
        }
        else
        {
          for (int j = 0; j < runlength[i].second; j++)
          {
            if (j % 2 == 0)
            {
              ans += 'R';
            }
            else
            {
              ans += 'B';
            }
          }
        }
      }
      else
      {
        if (runlength[i - 1].first == 'R')
        {
          for (int j = 0; j < runlength[i].second; j++)
          {
            if (j % 2 == 0)
            {
              ans += 'B';
            }
            else
            {
              ans += 'R';
            }
          }
        }
        else
        {
          for (int j = 0; j < runlength[i].second; j++)
          {
            if (j % 2 == 0)
            {
              ans += 'R';
            }
            else
            {
              ans += 'B';
            }
          }
        }
      }
    }
    else
    {
      for (int j = 0; j < runlength[i].second; j++)
      {
        ans += runlength[i].first;
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