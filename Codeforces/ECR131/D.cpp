#define _USE_MATH_DEFINES
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

int solve()
{
  ll n;
  cin >> n;
  vector<vector<ll>> a(n,vector<ll>(2));
  vector<ll> ans(n);
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
  for(ll i = 0;i < n;i++){
    ll b;
    cin >> b;
    ll from = (i+2+b)/(b+1);
    ll to;
    if (b == 0){
        to = numeric_limits<ll>::max();
    }else{
        to = (i+1)/b;
    }
    a[i] = { from,to,i};
  }
  sort(a.rbegin(),a.rend());
  for(int i = 0;i < n;i++){
    while(!a.empty() && a.back()[0] <= i+1){
        q.push({a.back()[1],a.back()[2]});
        a.pop_back();
    }
    ans[q.top().second] = i+1;
    q.pop();
  }
  for(int i = 0;i < n;i++){
    if (i != 0){
        cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
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
  cout << flush;
  return 0;
}
