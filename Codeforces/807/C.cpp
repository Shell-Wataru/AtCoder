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
  ll n,c,q;
  scanf("%lld", &n);
  scanf("%lld", &c);
  scanf("%lld", &q);
  string S;
  cin >> S;
  vector<pair<ll,ll>> copies(c);
  vector<ll> total(c+1,S.size());
  for(int i = 0;i < c;i++){
    ll l,r;
    scanf("%lld",&l);
    scanf("%lld",&r);
    l--;
    copies[i] = {l,r};
    total[i+1] = total[i] + r-l;
  }
  for(int i = 0;i < q;i++){
    // cout << "i:" << i << endl;
    ll k;
    scanf("%lld",&k);
    k--;
    while(k >= S.size()){
      ll index = upper_bound(total.begin(),total.end(),k) - total.begin();
      index--;
      ll remain = k - total[index];
      // cout << "k:" << k << endl;
      // cout << "index:" << index << endl;
      // cout << "remain:" << remain << endl;
      k = copies[index].first + remain;
    }
    // cout << "k:" << k << endl;
    cout << S[k] << "\n";
  }
  return 0;
}

int main()
{
  // cout << "!" << endl;
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
