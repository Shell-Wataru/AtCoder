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
  cin >> n;
  vector<ll> a(n);
  ll max_a = 0;
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  vector<pair<ll,ll>> answers;
  for(int i = 0;i < n;i++){
    ll index =  64 - __builtin_clzll(a[i]);
    ll diff = (1ll<<index) - a[i];
    if (diff != 0){
      answers.push_back({i,diff});
    }
  }
  cout << answers.size() << "\n";
  for(auto p:answers){
    cout << p.first + 1<< " " << p.second << "\n";
  }
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