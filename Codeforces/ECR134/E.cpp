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
  ll n,m;
  cin >> n >> m;
  string s,t;
  cin >> s>> t;
  vector<pair<ll,ll>> DP1(m+1);
  vector<pair<ll,ll>> DP2(m+1);
  ll s_index = 0;
  ll last_deleted_index = -1;
  for(int i = 0;i < m;i++){
    DP2[i+1].first += DP2[i].first;
    while(s_index < n && s[s_index] != t[i]){
        DP2[i+1].first += s_index - last_deleted_index + 1;
        last_deleted_index = s_index;
        s_index++;
    }
    if (s[s_index] != t[i]){
        cout << -1 << "\n";
        return 0;
    }
    DP2[i+1].second = s_index;
    s_index++;
  }

  s_index = n-1;
  last_deleted_index = n;
  DP1[m].second = last_deleted_index;
  for(int i = m-1;i >= 0;i--){
    DP1[i].first+= DP1[i+1].first;
    while(s_index >= 0 && s[s_index] != t[i]){
        DP1[i].first += last_deleted_index - s_index;
        last_deleted_index = s_index;
        s_index--;
    }
    if (s[s_index] != t[i]){
        cout << -1 << "\n";
        return 0;
    }
    DP1[i].second = last_deleted_index;
    s_index--;
  }
  cout << "DP1" << endl;
  for(int i = 0;i <= m;i++){
    cout << i << ":" << DP1[i].first << "," <<  DP1[i].second << endl;
  }
  cout << "DP2" << endl;
  for(int i = 0;i <= m;i++){
    cout << i << ":" << DP2[i].first << "," <<  DP2[i].second << endl;
  }
  ll ans = DP1[0].first + DP1[0].second;
  for(int i = 1;i <= m;i++){
    ans = min(ans,DP1[i].first + DP2[i].first +1 + DP1[i].second - DP2[i].second);
  }
  cout << ans << endl;
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
