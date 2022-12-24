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

ll parseTime(string s){
  return stoll(s.substr(0,2)) * 1000 * 60 * 60 +  stoll(s.substr(3,2)) * 1000 * 60 + stoll(s.substr(6,2)) * 1000 + stoll(s.substr(9,3));
}

void setBeforeAfterPossiblity(ll t,ll l,ll r, bool &before,bool &after){
  if (l  < t + 1000 ){
    before = true;
  }
  if (t  < r){
    after = true;
  }
}

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<pair<ll,ll>> ranges(n);
  for(int i = 0;i < n;i++){
      string s,t;
      cin >> s >> t;
      ranges[i].first = parseTime(s);
      ranges[i].second = parseTime(t);
  }
  ll l = 0;
  ll r = 24 * 1000 * 60 * 60;
  for(int i = 0;i < n;i++){
    if (ranges[i].first >= ranges[i].second){
      l = max(l,ranges[i].first);
      r = min(r,ranges[i].second + 1000);
    }
  }

  for(int i = 0;i < n;i++){
    if (ranges[i].first >= ranges[i].second){
      cout << ranges[i].second + 1000 - ranges[i].first << endl;
    }else{
      bool l_before = false;
      bool l_after = false;
      bool r_before = false;
      bool r_after = false;
      setBeforeAfterPossiblity(ranges[i].first,l,r,l_before,l_after);
      setBeforeAfterPossiblity(ranges[i].second,l,r,r_before,r_after);
      // cout << l_before << "," << l_after << "," << r_before << "," << r_after << endl;
      if (l_before && l_after){
        cout << -1 << endl;
      }else if (r_before && r_after){
        cout << -1 << endl;
      }else if (l_after && r_after){
        cout << ranges[i].second - ranges[i].first << endl;
      }else if (l_before && r_before){
        cout << ranges[i].second - ranges[i].first << endl;
      }else{
        cout << ranges[i].second + 1000 - ranges[i].first << endl;
      }
    }
  }
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