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
using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int solve()
{
  int n;
  scanf("%d", &n);
  vector<pair<ll,ll>> products(n);
  for(int i = 0;i < n;i++){
    ll a,b;
    scanf("%lld",&a);
    scanf("%lld",&b);
    products[i].first = b;
    products[i].second = a;
  }
  sort(products.begin(),products.end());
  deque<pair<ll,ll>> q(products.begin(),products.end());
  // for(auto d:q){
  //   cout << d.first << ":" << d.second << endl;
  // }
  ll total_buy = 0;
  ll ans = 0;
  while(!q.empty()){
    // cout << "f:" << q.front().first << endl;
    // cout << "total:" << total_buy << endl;
    // cout << "b:"  <<q.back().second << endl;
    // cout << "ans:" <<  ans  << endl;
    if (q.front().first <= total_buy){
      // cout << "A" << endl;
      ans += q.front().second;
      total_buy += q.front().second;
      q.pop_front();
    }else if(q.back().second + total_buy <= q.front().first ){
      // cout << "B" << endl;
      ans += q.back().second * 2;
      total_buy += q.back().second;
      q.pop_back();
    }else{
      // cout << "C" << endl;
      ll buy = q.front().first - total_buy;
      ans += buy * 2;
      total_buy += buy;
      q.back().second -= buy;
    }
  }
  cout << ans << "\n";
  return 0;
}

int main()
{
  // // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}
