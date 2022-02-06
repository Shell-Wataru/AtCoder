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
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
  ll n, k;
  scanf("%lld", &n);
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &a[i]);
  }
  if (a[0] == 1)
  {
    cout << n + 1;
    for (int i = 1; i <= n; i++)
    {
      cout << " " << i;
    }
    cout << "\n";
  }
  else if (a[n - 1] == 0)
  {
    ;
    for (int i = 1; i <= n + 1; i++)
    {
      if (i != 1)
      {
        cout << " ";
      }
      cout << i;
    }
    cout << "\n";
  }else{
    ll move_index = -1;
    for(int i = 0;i < n-1;i++){
      if (a[i] == 0 && a[i+1] == 1){
        move_index = i+1;
        break;
      }
    }
    for(int i = 1;i <= move_index;i++){
      if (i != 1)
      {
        cout << " ";
      }
      cout << i;
    }
    cout << " " << n + 1;
    for(int i = move_index + 1;i <= n;i++){
      cout << " " << i;
    }
    cout << "\n";
  }
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
