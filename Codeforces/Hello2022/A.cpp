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
  ll n,k;
  cin >> n >> k;
  if (2*k-1 <= n){
    vector<string> G(n,string(n,'.'));
    for(int i = 0;i < k;i++){
      G[2*i][2*i] = 'R';
    }
    for(int i = 0;i < n;i++){
      cout << G[i] << "\n";
    }
  }else{
    cout << -1 << "\n";
  }
  // cout << n << endl;
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