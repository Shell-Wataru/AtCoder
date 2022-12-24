#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld", &n);
  string S;
  cin >> S;
  ll last_zero = -1;
  ll ans = 0;
  for(int i = 0;i < n;i++){
    if (S[i] == '0'){
      if (last_zero == -1){
        last_zero = i;
      }else{
        // cout << i - last_zero - 1<< endl;
        ans += max(2- (i- last_zero - 1),0ll);
        last_zero = i;
      }
    }else{

    }
  }
  cout << ans << endl;
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