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
  string N;
  ll K;
  cin >> N >> K;
  ll biggest = 1;
  map<ll,ll> not_biggest;
  for(int i = 0;i < N.size();i++){
    ll d = N[i] - '0';
    map<ll,ll> new_not_biggest;
    for(int j = 0;j < d;j++){
      ll product = biggest*j;
      if (product <= K){
        new_not_biggest[product]++;
      }else{
        new_not_biggest[K+1]++;
      }
    }
    biggest *= d;
    for(auto p:not_biggest){
      for(int j = 0;j < 10;j++){
        ll product = p.first*j;
        if (product <= K){
          new_not_biggest[product] += p.second;
        }else{
          new_not_biggest[K+1] += p.second;
        }
      }
    }
    new_not_biggest[0]--;
    new_not_biggest[1]++;
    not_biggest = new_not_biggest;
    // cout << i << endl;
    // for(auto p:not_biggest){
    //   cout << p.first << ":" << p.second << endl;
    // }
  }
  ll ans = 0;
  if (biggest <= K){
    ans++;
  }
  for(auto p:not_biggest){
    if (p.first <= K){
      ans += p.second;
    }
  }
  ans--;
  cout << ans << endl;
  return 0;
}
