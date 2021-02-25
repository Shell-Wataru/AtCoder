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
    // 整数の入力
    ll N, T;
    cin >> N >> T;
    vector<ll> A(N);
    for(int i = 0;i < N;i++){
      cin >> A[i];
    }
    vector<ll> first_groups;
    vector<ll> second_groups;
    for(ll i = 0;i < (1ll<<(N/2));i++){
      ll total = 0;
      for(ll j = 0;j < N/2;j++){
        if (i & (1ll<<j)){
          total = min(total + A[j], T + 1);
        }
      }
      first_groups.push_back(total);
    }
    for(ll i = 0;i < (1<<(N - N/2));i++){
      ll total = 0;
      for(ll j = 0;j < N - N/2;j++){
        if (i & (1ll<<j)){
          total = min(total + A[j+N/2], T + 1);
        }
      }
      second_groups.push_back(total);
    }
    sort(second_groups.begin(),second_groups.end());
    ll max_t = 0;
    for(auto &f:first_groups){
      ll remain = T - f;
      if (remain < 0){
        continue;
      }
      auto ans = upper_bound(second_groups.begin(),second_groups.end(),remain);
      if (ans == second_groups.begin()){
        continue;
      }
      ans--;
      // cout << remain << " " << *ans << endl;
      max_t = max(f + *ans,max_t);
    }
    cout << max_t << endl;
    return 0;
}