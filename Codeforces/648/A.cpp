#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;


int solve()
{
  ll n,m;
  scanf("%lld%lld",&n,&m);
  vector<vector<ll>> G(n,vector<ll>(m,0));
  set<ll> occupied_rows;
  set<ll> occupied_columns;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      cin >> G[i][j];
    }
  }
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      if (G[i][j] == 1){
        occupied_rows.insert(i);
        occupied_columns.insert(j);
      }
    }
  }
  ll can_puts = min(n - occupied_rows.size(), m - occupied_columns.size());
  if (can_puts % 2 == 1){
    cout << "Ashish" << endl;
  }else{
    cout << "Vivek" << endl;
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
  return 0;
}