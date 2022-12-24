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
  ll N,Q;
  cin >> N >> Q;
  vector<set<ll,greater<ll>>> ranges(N+1);
  for(int i = 0;i < Q;i++){
    ll l,r;
    cin >> l >> r;
    l--;
    ranges[l].insert(r);
  }
  for(int i = 0;i < N;i++){
    ll last = -1;
    for(auto l:ranges[i]){
      if (last == -1){
        last = l;
      }else{
        ranges[l].insert(last);
        last = l;
      }
    }
  }
  ll current = 0;
  while(!ranges[current].empty()){
    auto iter =  ranges[current].end();
    iter--;
    current = *iter;
  }
  if (current == N){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
