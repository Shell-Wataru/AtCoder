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

ll query(string &S){
    cout << "? " << S << endl;
    ll ans;
    cin >> ans;
    return ans;
}
int solve()
{
  ll n,m;
  scanf("%lld",&n);
  scanf("%lld",&m);
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
  vector<ll> L(m);
  ll total = 0;
  for(int i = 0;i < m;i++){
    string S1(m,'0');
    S1[i] = '1';
    L[i] = query(S1);
    q.push({L[i],i});
  }
  string S(m,'0');
  ll ans = 0;
  while(!q.empty()){
    auto p = q.top();
    q.pop();
    S[p.second] =  '1';
    ll l = query(S);
    if (l == ans + p.first){
      ans = l;
    }else{
      S[p.second] =  '0';
    }
  }
  // cerr << S << endl;
  cout << "! " << ans << endl;
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
  // cout << flush;
  return 0;
}