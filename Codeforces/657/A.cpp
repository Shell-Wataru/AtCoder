#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  string S;
  cin >> n;
  cin >> S;
  ll occurs = 0;
  string data = "abacaba";
  string ans = "";
  for (int i = 0; i < n - data.size() + 1; i++)
  {
    // cout << "i" << i << endl;
    string current = S;
    for (int j = 0; j < data.size(); j++)
    {
      if (current[i + j] == '?')
      {
        current[i + j] = data[j];
      }
    }
    for (int j = 0; j < n; j++)
    {
      if (current[j] == '?')
      {
        current[j] = 'z';
      }
    }
    ll occurs = 0;
    for (size_t j = 0; j < n - data.size() + 1; j++)
    {
      // cout << current.substr(j,data.size()) << endl;
      // cout << (current.substr(j,data.size()) == data) << endl;
      if (current.substr(j, data.size()) == data)
      {
        occurs++;
      }
    }
    // cout << current << endl;
    // cout << occurs << endl;
    if (occurs == 1)
    {
      ans = current;
      break;
    }
  }
  if (ans == "")
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
    cout << ans << endl;
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
  return 0;
}