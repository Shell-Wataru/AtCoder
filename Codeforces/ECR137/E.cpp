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
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll p1,t1,p2,t2,h,s;
  cin >> p1 >> t1 >> p2 >> t2 >> h >> s;
  priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> q;
  q.push({0,t1,t2,0});
  map<vector<ll>,ll> cache_damage;
  map<vector<ll>,ll> cache_time;
  while(!q.empty()){
    auto v = q.top();
    q.pop();
    ll total_t = v[0];
    ll current_t1 = v[1];
    ll current_t2 = v[2];
    ll damage = v[3];
    // cout << total_t << "," <<  current_t1 << "," << current_t2 << "," << damage<< endl;
    if (damage >= h){
      cout << total_t << endl;
      return 0;
    }
    if (cache_damage.count({total_t,current_t1,current_t2}) > 0 && cache_damage[{total_t,current_t1,current_t2}] >= damage){
      // cout << "hit!" << endl;
      continue;
    }
    cache_damage[{total_t,current_t1,current_t2}] = damage;
    if (cache_time.count({damage,current_t1,current_t2}) > 0 && cache_time[{damage,current_t1,current_t2}] <= total_t){
      // cout << "hit!" << endl;
      continue;
    }
    cache_time[{damage,current_t1,current_t2}] = total_t;
    if (current_t1 < current_t2 && p1-s> 0){
      q.push({
        total_t+current_t1,
        t1,
        current_t2-current_t1,
        damage + max(p1-s,0ll)
      });
    }else if (current_t1 > current_t2 && p2-s > 0){
      q.push({
        total_t+current_t2,
        current_t1-current_t2,
        t2,
        damage + max(p2-s,0ll)
      });
    }
    q.push({
      total_t+max(current_t1,current_t2),
      t1,
      t2,
      damage + max(p1+p2-s,0ll)
    });
  }
  return 0;
}
int main()
{
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}
