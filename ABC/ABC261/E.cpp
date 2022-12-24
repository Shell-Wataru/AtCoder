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
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
  ll N,C;
  cin >> N >> C;
  vector<ll> f(30,2);
  for(int i = 0;i < N;i++){
    ll t,a;
    cin >> t >> a;
    if (t == 1){
      for(int j = 0;j < 30;j++){
        if (a & 1ll<<j){
          f[j] = f[j];
        }else{
          f[j] = 0;
        }
      }
    }else if (t == 2){
      for(int j = 0;j < 30;j++){
        if (a & 1ll<<j){
          f[j] = 3;
        }else{
          f[j] = f[j];
        }
      }
    }else{
      for(int j = 0;j < 30;j++){
        if (a & 1ll<<j){
          f[j] = f[j]^3;
        }else{
          f[j] = f[j];
        }
      }
    }
    ll new_c = 0;
    for(int j = 0;j < 30;j++){
      if (C & 1ll<<j){
        if (f[j] == 2 || f[j] == 3){
          new_c |= 1ll<<j;
        }
      }else{
        if (f[j] == 1 || f[j] == 3){
          new_c |= 1ll<<j;
        }
      }
    }
    cout << new_c << "\n";
    C = new_c;
  }

  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 0;i < N;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
