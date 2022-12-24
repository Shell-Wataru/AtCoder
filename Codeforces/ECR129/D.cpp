#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <unordered_map>
using namespace std;
using ll = long long;

int solve()
{
  ll n, x;
  scanf("%lld", &n);
  scanf("%lld", &x);
  unordered_map<ll,ll> distances;
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
  q.push({0,x});
  while(!q.empty()){
    auto p = q.top();
    q.pop();
    string x_s = to_string(p.second);
    if (distances.count(p.second) == 0){
      // cout << p.first << ":" << p.first << endl;
      distances[p.second] = p.first;
      if (x_s.size() >= n){
        cout << p.first << "\n";
        return 0;
      }else{
        for(auto c:x_s){
          // cout << p.second*(c-'0') << endl;
          q.push({p.first+1,p.second*(c-'0')});
        }
      }
    }
  }
  cout << -1 << "\n";
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