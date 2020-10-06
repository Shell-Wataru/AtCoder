#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;

int solve()
{
  ll n,d,m;
  cin >> n >> d >> m;
  vector<ll> B;
  vector<ll> S;
  for(int i = 0;i < n;i++){
    ll a;
    scanf("%lld",&a);
    if (a > m){
      B.push_back(a);
    }else{
      S.push_back(a);
    }
  }
  sort(B.begin(),B.end());
  sort(S.begin(),S.end());

  if (B.size() == 0){
    ll ans = 0;
    for(int i = 0;i < S.size();i++){
      ans+= S[i];
    }
    cout << ans << endl;
  }else{
    ll base = B.back();
    B.pop_back();
    reverse(B.begin(),B.end());

    vector<ll> SumB(B.size()+1,0);
    vector<ll> SumS(S.size()+1,0);
    for(int i = 0;i < B.size();i++){
      SumB[i+1] = SumB[i] + B[i];
    }
    for(int i = 0;i < S.size();i++){
      SumS[i+1] = SumS[i] + S[i];
    }
    ll b_size = B.size();
    ll ans = 0;
    for(int i = 0;i <= b_size;i++){
      ll removes = d * i;
      ll small_removes = max(removes - (b_size - i),0ll);
      if (small_removes <= S.size()){
        ans = max(ans,SumB[i] + SumS[S.size()] - SumS[small_removes]);
      }
    }
    cout << base + ans << endl;
  }
  return 0;
}

int main()
{
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  return 0;
}