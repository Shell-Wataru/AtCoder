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
  ll n, m, k;
  scanf("%lld", &n);
  scanf("%lld", &m);
  scanf("%lld", &k);
  vector<ll> a(k);
  for(int i = 0;i < k;i++){
    scanf("%lld",&a[i]);
    a[i]--;
  }
  ll current = 0;
  ll occupied = 0;
  vector<bool> opened(k,false);
  for(int i = k-1; i>= 0;i--){
    while(!opened[i]){
      opened[a[current]] = true;
      current++;
      occupied++;
    }
    if (occupied < n*m-2){
      occupied--;
    }else{
      cout << "TIDAK" << "\n";
      return 0;
    }
  }
  cout << "YA" << "\n";
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
