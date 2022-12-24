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

ll distance(ll a,ll b){
  ll ans = 0;
  while(a != b && b % a != 0 ){
    a >>= 1;
    ans++;
  }
  if (a == b){
    return ans;
  }else{
    ll ret = b/a;
    while(ret > 1){
      ret >>= 1;
      ans++;
    }
    return ans;
  }
}

ll solve(){
  ll N;
  cin >> N;
  vector<ll> B(N);
  vector<ll> A(N);
  map<ll,vector<ll>> grouping_a;
  map<ll,vector<ll>> grouping_b;
  for(int i = 0;i < N;i++){
    cin >> A[i];
    ll g = A[i];
    while(g % 2 == 0 && g != 0){
      g /= 2;
    }
    grouping_a[g].push_back(A[i]);
  }

  for(int i = 0;i < N;i++){
    cin >> B[i];
    ll g = B[i];
    while(g % 2 == 0 && g != 0){
      g /= 2;
    }
    grouping_b[g].push_back(B[i]);
  }
  ll ans = 0;
  while(!grouping_b.empty()){
    auto p = *grouping_b.rbegin();
    cout << "g:" << p.first << endl;
    cout  << "a:" << ans << endl;
    while(grouping_a.rbegin()->first > p.first){
      auto q1 = *grouping_a.rbegin();
      cout << "q1:" << q1.first << endl;
      for(auto a:q1.second){
        grouping_a[q1.first>>1].push_back(a);
      }
      grouping_a.erase(q1.first);
    }
    auto q = *grouping_a.rbegin();
    if (q.first != p.first || q.second.size() < p.second.size()){
      cout << -1 << endl;
      return 0;
    }
    sort(q.second.begin(),q.second.end());
    while(!p.second.empty()){
      cout << q.second.back() << "," << p.second.back() << "=" << distance(q.second.back(),p.second.back()) << endl;
      ans += distance(q.second.back(),p.second.back());
      p.second.pop_back();
      q.second.pop_back();
    }
    grouping_b.erase(p.first);
    if (q.second.size() == 0){
      grouping_a.erase(q.first);
    }else{
      grouping_a[q.first] = q.second;
    }
  }
  cout << ans << endl;
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 1; i <= N;i++){
    solve();
  // }
  cout << flush;
  return 0;
}
