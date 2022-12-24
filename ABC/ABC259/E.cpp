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
  ll N;
  cin >> N;
  unordered_map<ll,ll> lcm;
  unordered_map<ll,ll> lcm_count;
  vector<unordered_map<ll,ll>> a(N);
  for(int i = 0;i < N;i++){
    ll m;
    cin >> m;
    for(int j = 0;j < m;j++){
      ll p,e;
      cin >> p >> e;
      if (lcm[p] < e){
        lcm[p] = e;
        lcm_count[p] = 1;
      }else if (lcm[p] == e ){
        lcm_count[p]++;
      }

      a[i][p] = e;
    }
  }
  set<vector<ll>> removed;
  for(int i = 0;i < N;i++){
    vector<ll> r;
    for(auto p:a[i]){
      if (lcm[p.first] == p.second && lcm_count[p.first] == 1){
        // cout << p.first << ",";
        r.push_back(p.first);
      }
    }
    // cout << endl;
    removed.insert(r);
  }
  cout << removed.size() << endl;
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
