#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  ll c;
  scanf("%lld", &n);
  scanf("%lld", &c);
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &a[i]);
  }
  ll minimum = numeric_limits<ll>::max();
  ll maximum = numeric_limits<ll>::min();
  vector<bool> contains(c+1);
  for(auto aa:a){
    minimum = min(minimum,aa);
    maximum = max(maximum,aa);
    contains[aa] = true;
  }
  for(int i = maximum;i >= minimum;i--){
    if (!contains[i]){
      continue;
    }
    ll x = maximum;
    ll y = i;
    while(true){
      if (!contains[x/y]){
        cout << "No" << endl;
        return 0;
      }else if (x/y == 1 || y == 1){
        break;
      }else{
        x = x/y;
        if (x < y){
          swap(x,y);
        }
      }

    }
  }
  cout << "Yes" << endl;
  return 0;
}

int main()
{
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}