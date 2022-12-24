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
  ll N,M;
  cin >> N >> M;
  vector<ll> A(N+1);
  vector<ll> B(M+1);
  vector<ll> C(N+M+1);
  for(int i = 0;i <= N;i++){
    cin >> A[i];
  }
  for(int i = 0;i <= N+M;i++){
    cin >> C[i];
  }
  for(int i = 0;i <= M;i++){
    ll others = 0;
    for(int j = 1;j <= i;j++){
      if (N-j >= 0){
        others += A[N-j]*B[M-(i-j)];
      }
    }
    // cout << others << endl;
    // cout << (C[N+M-i]- others)<< "/" << A[N]  << endl;
    B[M-i] = (C[N+M-i]- others)/A[N];
  }
  for(int i = 0;i <= M;i++){
    if (i != 0){
      cout << " ";
    }
    cout << B[i];
  }
  cout << endl;
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
  // cout << flush;
  return 0;
}
