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
  ll a,N;
  cin >> a >> N;
  vector<ll> DP(1000000,numeric_limits<ll>::max()/2);
  queue<pair<ll,ll>> q;
  q.push({1,0});
  while(!q.empty()){
    ll x = q.front().first;
    ll count = q.front().second;
    q.pop();
    if (DP[x] > count){
      DP[x] = count;
      if (x == N){
        break;
      }
      if (a*x < 1000000){
        q.push({a*x,count+1});
      }
      if (x % 10 != 0){
        string x_s = to_string(x);
        ll swapped = stoll(x_s.substr(x_s.size()-1) + x_s.substr(0,x_s.size()-1));
        // cout << x << ":"<< swapped << endl;
        q.push({swapped,count+1});
      }
    }
  }

  if (DP[N] == numeric_limits<ll>::max()/2){
    cout << -1 << endl;
  }else{
    cout << DP[N] << endl;
  }

  return 0;
}
