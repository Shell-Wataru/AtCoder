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
#include <stack>

using namespace std;
using ll = long long;

int solve()
{
  string S;
  ll Q;
  cin >> S;
  cin >> Q;
  for (int i = 0; i < Q; i++)
  {
    ll t, k;
    cin >> t >> k;
    k--;
    ll c = 0;
    while ((1ll << c) <= k)
    {
      c++;
    }
    // cout << "c:" << c << endl;
    ll ans = S[0] - 'A';
    if (t > c)
    {
      ans += t-c;
      t = c;
      ans %= 3;
    }else{
      ans = S[k/(1ll<<t)] - 'A';
      k = k % (1ll<<t);
    }
    // cout << "t:" << t << endl;
    while(t > 0){
      t--;
      if (k < 1ll<<t){
        ans += 1;
        ans %= 3;
      }else{
        k -= 1ll<<t;
        ans += 2;
        ans %= 3;
      }
    }
    cout << (char)('A' + ans) << "\n";
  }
  cout << flush;
  return 0;
}

int main()
{
  // 整数の入力
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  // cout << flush;
  return 0;
}
