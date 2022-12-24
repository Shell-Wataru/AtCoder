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
#include <climits>
using namespace std;
using ll = long long;

int main()
{
  ll N, Q;
  cin >> N;
  vector<pair<ll,ll>> f(N);
  for(int i = 0;i < N;i++){
      ll a_i,t;
      cin >> a_i >> t;
      f[i].first = a_i;
      f[i].second = t;
  }
  ll a = 0;
  ll b = numeric_limits<ll>::min();
  ll c =numeric_limits<ll>::max();
  for(int i = N-1;i>=0;i--){
      if (f[i].second == 1){
          a += f[i].first;
      }else if (f[i].second == 2){
          b = max(b,a+ f[i].first);
      }else{
          c = min(max(a+f[i].first,b),c);
      }
  }
  cin >> Q;
  for(int i = 0;i < Q;i++){
      ll x;
      cin >> x;
      cout << min(max(x+a,b),c) << "\n";
  }
  cout << flush;
  return 0;
}