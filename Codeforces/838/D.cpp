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

ll query(ll x,ll y){
  cout << "? " << x + 1 << " " << y+1 << endl;
  // cerr << "? " << x + 1 << " " << y+1 << endl;
  ll ret;
  cin >> ret;
  return ret;
}
int solve()
{
  ll n;
  scanf("%lld", &n);
  ll x = 0,y = 1;
  ll current_max = query(x,y);
  for(int i = 2;i < n;i++){
    ll for_x = query(x,i);
    ll for_y = query(y,i);
    if (current_max >= for_x && current_max >= for_y){

    }else if(for_x >= current_max && for_x >= for_y){
      current_max = for_x;
      y = i;
    }else{
      current_max = for_y;
      x = i;
    }
  }
  cout << "! " << x + 1 << " " << y + 1 << endl;
  ll ret;
  cin >> ret;
  // cerr << "! " << x + 1 << " " << y + 1 << endl;
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
