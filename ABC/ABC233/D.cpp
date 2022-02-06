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

int main()
{
  // 整数の入力
  ll N,K;
  cin >> N >> K;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  map<ll,ll> counts;
  counts[0] = 1;
  ll ans = 0;
  ll total = 0;
  for(int i = 0;i < N;i++){
    total += A[i];
    ans += counts[total-K];
    counts[total] += 1;
  }
  cout << ans << endl;
  return 0;
}
