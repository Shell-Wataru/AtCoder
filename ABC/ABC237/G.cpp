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
  ll N,Q,X;
  cin >> N >> Q >> X;
  set<vector<ll>> P;
  for(int i = 0;i < N;i++){
    ll p;
    cin >> p;
    if (p < X){
      P.insert({i,i+1,1,1,0,0});
    }else if (p == X){
      P.insert({i,i+1,1,0,1,0});
    }else{
      P.insert({i,i+1,1,0,0,1});
    }
  }
  for(int i = 0;i < Q;i++){
    ll c,l,r;
    cin >> c >> l >> r;
    l--;
    auto iter = P.lower_bound({l,l+1,1,0,0,0});
    if (iter == P.end() || (*iter)[0] != l){
      iter--;
    }
    vector<vector<ll>> removed;
    vector<vector<ll>> inserted;
    while(iter != P.end() && (*iter)[0] < r){
      ll from = (*iter)[0];
      ll to = (*iter)[1];
      ll sort_type = (*iter)[2];
      ll smaller = (*iter)[3];
      ll same = (*iter)[4];
      ll bigger = (*iter)[5];
      removed.push_back(*iter);
      if (from < l && r < to){
        vector<ll> x = {from,l,sort_type,0,0,0};
        vector<ll> y = {l,r,c,0,0,0};
        vector<ll> z=  {r,to,sort_type,0,0,0};
        if (sort_type == 1){
          x[3] = min(l-from,smaller);
          x[4] = min(l-from-x[3],same);
          x[5] = min(l-from-x[3]-x[4],bigger);
          y[3]
        }
      }else if (from < l && to <= r){

      }else if (l <= from && r < to){

      }else if (l <= from && to <= r){

      }
    }
  }
  return 0;
}
