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
#include <set>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

ll query(ll row_l,ll row_r, ll column_l,ll column_r){
  cout << "? " << row_l + 1 << " " << row_r << " " << column_l + 1 << " " << column_r << endl;
  // cerr << "? " << row_l + 1 << " " << row_r << " " << column_l + 1 << " " << column_r << endl;
  ll ret;
  cin >> ret;
  return ret;
}

int solve()
{
  ll N;
  cin >> N;
  ll row_l = 0;
  ll row_r = N;
  while(row_l+1 != row_r){
    ll center = (row_l+row_r)/2;
    ll c = query(row_l,center,0,N);
    // cerr << c << endl;
    if (c == center - row_l){
      row_l = center;
    }else{
      row_r = center;
    }
  }
  ll column_l = 0;
  ll column_r = N;
  while(column_l+1 != column_r){
    ll center = (column_l+column_r)/2;
    ll c = query(0,N,column_l,center);
    if (c == center - column_l){
      column_l = center;
    }else{
      column_r = center;
    }
  }
  cout << "! " << row_l + 1  << " " << column_l + 1 << endl;
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 0;i < N;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
