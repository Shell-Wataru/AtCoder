#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
using namespace std;
using ll = long long;

int main()
{
  ll N;
  cin >> N;
  vector<pair<ll,ll>> points(N);
  for(int i = 0;i < N;i++){
    ll x,y;
    cin >> x >> y;
    x--;
    points[i] = {x,y};
  }
  sort(points.begin(),points.end(),[](pair<ll,ll> &l,pair<ll,ll> &r){
    if (l.first == 0){
      return false;
    }else if (r.first == 0){
      return true;
    }else{
      return l.first * r.second > r.first * l.second;
    }
  });
  pair<ll,ll> current = {1,0};
  ll ans = 0;
  for(int i = 0;i < N;i++){
    // cout << points[i].first << "," << points[i].second << endl;
    // cout << 1.0* points[i].first/points[i].second << endl;
    pair<ll,ll> under = {points[i].first + 1,points[i].second-1};
    if (under.second  * current.first >= under.first  * current.second){
      ans++;
      current = points[i];
    }
  }
  cout << ans << endl;
  return 0;
}
