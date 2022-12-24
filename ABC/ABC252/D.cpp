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
  vector<ll> Counts(200001);
  vector<ll> DP0(200001,1);
  vector<ll> DP1(200001,0);
  vector<ll> DP2(200001,0);
  vector<ll> DP3(200001,0);
  for(int i = 0;i < N;i++){
    cin >> A[i];
    Counts[A[i]]++;
  }
  for(int i = 1;i < 200001;i++){
    DP1[i] = DP1[i-1] + Counts[i];
    DP2[i] = DP2[i-1] + Counts[i] * DP1[i-1];
    DP3[i] = DP3[i-1] + Counts[i] * DP2[i-1];
  }
  cout << DP3[200000] << endl;
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
