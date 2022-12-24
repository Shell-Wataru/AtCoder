#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> A(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &A[i]);
  }
  map<ll,ll> counts;
  counts[0] = 1;
  ll ans = 0;
  ll a = 1;
  ll b = 0;
  for(int i = 0;i < n;i++){
    // cout << (A[i]-b)*a << endl;
    ans += counts[(A[i]-b)*a];
    b = -b + A[i];
    a = -a;
    counts[-b*a]++;
    if (a == 1){
      auto iter = counts.begin();
      vector<ll> removes;
      while(iter != counts.end()){
        if (a*iter->first + b < 0){
          removes.push_back(iter->first);
          iter++;
        }else{
          break;
        }
      }
      for(auto r:removes){
        counts.erase(r);
      }
    }else{
      auto iter = counts.rbegin();
      vector<ll> removes;
      while(iter != counts.rend()){
        if (a*iter->first + b < 0){
          removes.push_back(iter->first);
          iter++;
        }else{
          break;
        }
      }
      for(auto r:removes){
        counts.erase(r);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}

int main()
{
  // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
