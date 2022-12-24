#include <iostream>
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
  ll n;
  scanf("%lld", &n);
  vector<vector<ll>> a(n);
  vector<ll> maximum(n);
  for (int i = 0; i < n; i++)
  {
    ll c;
    scanf("%lld", &c);
    maximum[i] = c - 1;
    a[i] = vector<ll>(c);
    for (int j = 0; j < c; j++)
    {
      scanf("%lld", &a[i][j]);
    }
  }
  ll m;
  scanf("%lld",&m);
  set<vector<ll>> banned;
  for (int i = 0; i < m; i++)
  {
    vector<ll> b(n);
    for (int j = 0; j < n; j++)
    {
      scanf("%lld", &b[j]);
      b[j]--;
    }
    banned.insert(b);
  }

  priority_queue<pair<ll, vector<ll>>,vector<pair<ll, vector<ll>>>,greater<pair<ll, vector<ll>>> > q;
  set<vector<ll>> visited;
  q.push({0, maximum});
  // cout << "!!!" << endl;
  while (!q.empty())
  {
    auto current = q.top().second;
    ll d = q.top().first;
    q.pop();
    // for (int i = 0; i < n; i++)
    //   {
    //     if (i != 0)
    //     {
    //       cout << " ";
    //     }
    //     cout << current[i] + 1;
    //   }
    //   cout << "\n";
    if (banned.find(current) == banned.end())
    {
      for (int i = 0; i < n; i++)
      {
        if (i != 0)
        {
          cout << " ";
        }
        cout << current[i] + 1;
      }
      cout << "\n";
      return 0;
    }
    for (int i = 0; i < n; i++)
    {
      if (current[i] > 0)
      {
        current[i]--;
        if (visited.find(current) == visited.end()){
          q.push({d + a[i][current[i] + 1] - a[i][current[i]], current});
          visited.insert(current);
        }
        current[i]++;
      }
    }
  }
  return 0;
}

int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}