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
#include <stack>

using namespace std;
using ll = long long;


int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  set<pair<ll,ll>> s;
  for(int i = 0;i < N;i++){
    ll x,y;
    cin >> x >> y;
    s.insert({x,y});
  }
  ll ans = 0;
  for(auto a:s){
    for(auto b:s){
      if (a.first < b.first && a.second < b.second){
        if (s.find({a.first,b.second}) != s.end() && s.find({b.first,a.second}) != s.end()){
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
