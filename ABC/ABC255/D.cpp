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
  ll N,Q;
  cin >> N >> Q;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  sort(A.begin(),A.end());
  vector<ll> ruiseki(N+1,0);
  for(int i = 0;i < N;i++){
    ruiseki[i+1] = ruiseki[i] + A[i];
  }
  for(int i = 0;i < Q;i++){
    ll x;
    cin >> x;
    ll index = lower_bound(A.begin(),A.end(),x) - A.begin();
    cout << (x * index - ruiseki[index]) +  (ruiseki[N] - ruiseki[index] - (N-index)*x) << endl;
  }
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
