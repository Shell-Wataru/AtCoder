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
  priority_queue<ll,vector<ll>,greater<ll>> q;
  for(int i = 0;i < K;i++){
    q.push(A[i]);
  }
  cout << q.top() << "\n";
  for(int i = K;i < N;i++){
    q.push(A[i]);
    q.pop();
    cout << q.top() << "\n";
  }
  cout << flush;
  return 0;
}
