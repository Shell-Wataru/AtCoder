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
  ll N,P,Q,R;
  cin >> N >> P >> Q >> R;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  vector<ll> cumA(N+1,0);
  for(int i = 0;i < N;i++){
    cumA[i+1] = cumA[i] + A[i];
  }
  for(int x = 0;x <= N;x++){
    ll y = lower_bound(cumA.begin(),cumA.end(),cumA[x] + P) - cumA.begin();
    if (y > N || cumA[y] - cumA[x] != P){
        continue;
    }
    ll z = lower_bound(cumA.begin(),cumA.end(),cumA[y] + Q) - cumA.begin();
    if (z > N || cumA[z] - cumA[y] != Q){
        continue;
    }
    ll w = lower_bound(cumA.begin(),cumA.end(),cumA[z] + R) - cumA.begin();
    if (w > N || cumA[w] - cumA[z] != R){
        continue;
    }
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
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
