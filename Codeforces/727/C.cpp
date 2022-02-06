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
  ll n,k,x;
  scanf("%lld", &n);
  scanf("%lld", &k);
  scanf("%lld", &x);
  vector<ll> a(n);
  vector<ll> needs;
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  sort(a.begin(),a.end());
  ll total_needs = 0;
  for(int i = 0;i < n-1;i++){
    needs.push_back( max((a[i+1]-a[i]-1)/x,0ll) );
    total_needs += needs.back();
  }
  sort(needs.begin(),needs.end());
  // for(auto nn:needs){
  //   cout << "n" << nn << endl;
  // }
  ll ans = 1;
  // cout << total_needs << endl;
  while(total_needs > k){
    // cout << "rm:" << needs.back() << endl;
    total_needs -= needs.back();
    needs.pop_back();
    ans++;
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
