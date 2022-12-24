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
  ll x = 0;
  for(ll i = 0;i < 29;i++){
    cout << "? " << x + (1ll<<i) + (1ll<<30) << " " << x + (1ll<<i) << endl;
    // cerr << "? " << x + (1ll<<i) + (1ll<<30) << " " << x + (1ll<<i) << endl;
    ll g;
    cin >> g;
    // cerr << g << endl;
    if ( g % (1ll<<(i+1)) == 0){
      // cerr << "ok"<< endl;
      x += 1ll<<i;
    }else{
    }
  }
  cout << "? " << x + (1ll<<29) + 3 << " " << x + (1ll<<29) << endl;
  ll result;
  cin >> result;
  if (result % 3 != 0){
    x += 1ll<<29;
  }
  cout << "! " <<(1ll<<30) - x << endl;
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
