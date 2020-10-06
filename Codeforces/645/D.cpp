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
ll BASE_NUM = 998244353;

int solve()
{
  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> S(k);
  for(int i = 0;i < k;i++){
    ll c;
    cin >> c;
    for (size_t j = 0; j < c; j++)
    {
      ll a;
      cin >> a;
      S[i].push_back(a);
    }
  }
  vector<ll> maxs(10);
  for(int i = 0;i < 10;){
    string q = "?";
    set<ll> queries;

  }
  return 0;
}

int main()
{
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  // cout << flush;
  return 0;
}