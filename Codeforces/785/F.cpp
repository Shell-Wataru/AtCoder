#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int solve()
{

  ll n,k;
  scanf("%lld", &n);
  scanf("%lld", &k);
  for(int i = 0;i < n-1;i++){
    cout << ((i+1)^i) << endl;
  }
  for(int i = 0;i < n-1;i++){
    if (i != 0){
      cout << " ";
    }
    cout << (((i+1)^i)<<5);
  }
  cout << endl;
  ll x = 0;
  for(int i = 0;i < k;i++){
    ll new_x;
    scanf("%lld",&new_x);
    x ^= new_x;
    cout << (x % 32) + 1 << " " << (x>>5) + 1 << endl;
  }
  return 0;
}
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}