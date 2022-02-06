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
using namespace std;
using ll = long long;

int solve()
{
  int n;
  scanf("%d", &n);
  vector<ll> a(n);
  vector<ll> b(n, -1);
  vector<ll> receiveb(n, -1);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &a[i]);
    a[i]--;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (receiveb[a[i]] == -1)
    {
      receiveb[a[i]] = i;
      b[i] = a[i];
      ans++;
    }
  }
  // for (int i = 0; i < n; i++)
  // {
  //   if (i != 0)
  //   {
  //     cout << " ";
  //   }
  //   cout << b[i] + 1;
  // }
  // cout << "\n";
  vector<ll> vacant;
  vector<ll> not_sent;
  for (int i = 0; i < n; i++)
  {
    if (receiveb[i] == -1)
    {
      vacant.push_back(i);
    }
    if (b[i] == -1)
    {
      not_sent.push_back(i);
    }
  }
  for (int i = 0; i < not_sent.size(); i++)
  {
    if (not_sent[i] != vacant.back())
    {
      b[not_sent[i]] = vacant.back();
      receiveb[vacant.back()] = not_sent[i];
      vacant.pop_back();
    }
    else if (vacant.size() >= 2)
    {
      ll target = vacant.size() - 2;
      b[not_sent[i]] = vacant[target];
      receiveb[vacant[target]] = not_sent[i];
      vacant.erase(vacant.begin() + target);
    }
  }

  if (vacant.size() == 1)
  {
    ll remain = vacant.back();
    ll conflict = receiveb[a[remain]];
    // cout << "r"<< remain << endl;
    // cout << "c" << conflict << endl;
    b[remain] = a[remain];
    b[conflict] = remain;
    receiveb[a[remain]] = remain;
    receiveb[remain] = conflict;
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++)
  {
    if (i != 0)
    {
      cout << " ";
    }
    cout << b[i] + 1;
  }
  cout << "\n";
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
