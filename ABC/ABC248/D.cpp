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
#include <stack>

using namespace std;
using ll = long long;

int solve()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<vector<ll>> indexes(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
    A[i]--;
    indexes[A[i]].push_back(i);
  }
  ll Q;
  cin >> Q;
  for(int i = 0;i < Q;i++){
    ll l ,r ,x;
    cin >> l >> r >> x;
    l--;
    x--;
    auto iter_l = lower_bound(indexes[x].begin(),indexes[x].end(),l);
    auto iter_r = lower_bound(indexes[x].begin(),indexes[x].end(),r);
    cout << iter_r - iter_l << endl;
  }
  return 0;
}

int main()
{
  // 整数の入力
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
