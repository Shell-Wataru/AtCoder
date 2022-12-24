#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
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
  ll n,q;
  cin >> n;
  cin >> q;
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  sort(a.begin(),a.end());
  set<ll> unique_a;
  vector<pair<ll,ll>> ranges;
  for(int i = 0;i < n;i++){
    ll k = a[i];
    while(unique_a.count(k) == 1){
      unique_a.erase(k);
      k++;
    }
    unique_a.insert(k);
  }
  for(auto k:unique_a){
    if (ranges.empty() || ranges.back().first != k){
      ranges.push_back({k+1,k});
    }else{
      ranges.back().first++;
    }
  }
  cout << "!" << ranges.back().first << endl;
  for(int i = 0;i < q;i++){
    ll k,l;
    cin >> k >> l;
    k--;
    auto p1 = make_pair(a[k],-1ll);
    auto p2 = make_pair(l,-1ll);
    ll remove_index = upper_bound(ranges.begin(),ranges.end(),p1) - ranges.begin();
    ll add_index = upper_bound(ranges.begin(),ranges.end(),p2) - ranges.begin();
    if (remove_index < add_index){
      if (add_index == ranges.size()-1){
        cout << ranges.back().first << "\n";
      }else{
        cout << ranges.back().first - 1 << "\n";
      }
    }else if (remove_index == add_index){
      if (l > a[k]){
        if (add_index == ranges.size()-1){
          cout << ranges.back().first << "\n";
        }else{
          cout << ranges.back().first - 1 << "\n";
        }
      }else if (l == a[k]){
        cout << ranges.back().first - 1 << "\n";
      }else{
        if (remove_index == ranges.size() - 1){
          cout << ranges.back().first - 2 << "\n";
        }else{
          cout << ranges.back().first - 1 << "\n";
        }
      }
    }else{
      if (remove_index == ranges.size() - 1){
        cout << ranges.back().first - 2 << "\n";
      }else{
        cout << ranges.back().first - 1 << "\n";
      }
    }
  }
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}
