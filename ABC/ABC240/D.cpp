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

int solve(){
  ll N;
  cin >> N;
  vector<pair<ll,ll>> q;
  ll total = 0;
  for(int i = 0; i < N;i++){
    ll a;
    cin >> a;
    if (q.empty()){
      q.push_back({a,1});
    }else if (q.back().first != a){
      q.push_back({a,1});
    }else{
      q.back().second++;
    }
    total++;
    if (q.back().first == q.back().second){
      total -= q.back().first;
      q.pop_back();
    }
    cout << total << "\n";
  }
  cout << flush;
  return 0;
}

int main()
{
  // 整数の入力
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
    solve();
  // }
  // cout << flush;
  return 0;
}
