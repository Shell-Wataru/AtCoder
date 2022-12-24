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
ll BASE_NUM = 1000000007;

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<pair<ll,ll>> B(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
    B[i] = {A[i],i};
  }
  sort(B.rbegin(),B.rend());
  ll ans = 0;
  for(ll i = 0;i <= N;i++){
    vector<pair<ll,ll>> upper;
    vector<pair<ll,ll>> lower;
    for(ll j = 0;j < N;j++){
      if (B[j].second >= i){
        if (B[j].second >= lower.size()){
          lower.push_back(B[j]);
        }else{
          upper.push_back(B[j]);
        }
      }else{
        if (B[j].second <= N-1-upper.size()){
          upper.push_back(B[j]);
        }else{
          lower.push_back(B[j]);
        }
      }
    }
    sort(upper.rbegin(),upper.rend());
    sort(lower.rbegin(),lower.rend());
    ll current = 0;
    ll lower_index = 0;
    ll upper_index = N-1;
    for(auto p:lower){
      current += p.first * abs(p.second - lower_index);
      lower_index++;
    }
    for(auto p:upper){
      current += p.first * abs(upper_index - p.second);
      upper_index--;
    }
    ans = max(ans,current);
  }
  cout << ans << endl;
  return 0;
}
