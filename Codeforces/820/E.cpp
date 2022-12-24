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

ll query(ll a,ll b){
  cout << "? " << a << " " << b << endl;
  ll ret;
  cin >> ret;
  return ret;
}

int solve()
{
  vector<ll> results(50);
  for(int i = 0;i < 25;i++){
    ll a = query(i+1,i+2);
    ll b = query(i+2,i+1);
    if (a == -1){
      cout << "! " << i+1 << endl;
      return 0;
    }else if (a != b){
      cout << "! " << a+b << endl;
      return 0;
    }
  }
  // sort(results.begin(),results.end());

  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  // cout << flush;
  return 0;
}
