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
  ll n,d;
  scanf("%lld", &n);
  scanf("%lld", &d);
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> gt;
  vector<pair<ll,ll>> lte;

  for(int i = 0;i < n;i++){
    ll s,a;
    scanf("%lld",&s);
    scanf("%lld",&a);
    if (s < a){
      gt.push({a,s});
    }else{
      lte.push_back({s,a});
    }
  }
  lte.push_back({numeric_limits<ll>::max(),numeric_limits<ll>::max()});
  // cout << lte.size() << endl;
  sort(lte.begin(),lte.end());
  ll ans = 0;
  ll current = d;
  for(int i = 0;i < lte.size();i++){
    while(!gt.empty() &&  gt.top().first <= lte[i].first){
      if(gt.top().second < d){
        gt.pop();
      }else{
        ans++;
        d = max(gt.top().first,d);
        gt.pop();
      }
    }
    if (lte[i].first >= d){
      // cout << lte[i].first << " " << lte[i].second << endl;
      ans++;
      d = max(lte[i].second,d);
    }
  }

  cout << ans - 1<< "\n";
  return 0;
}

int main()
{
  // // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}
