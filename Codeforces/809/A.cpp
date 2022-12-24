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
  ll n,m;
  cin >> n >> m;
  string ans(m,'B');
  for(int i = 0;i < n;i++){
    ll a;
    scanf("%lld",&a);
    a--;
    if (ans[min(a,m-1-a)]== 'B'){
      ans[min(a,m-1-a)] = 'A';
    }else{
      ans[max(a,m-1-a)] = 'A';
    }
  }
  cout << ans;
  cout << "\n";
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