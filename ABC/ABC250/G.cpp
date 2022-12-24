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
#include <set>
using namespace std;
using ll = long long;

ll solve()
{
  ll N;
  scanf("%lld",&N);
  vector<ll> P(N);
  for(int i = 0;i < N;i++){
    cin >> P[i];
  }
  priority_queue<ll,vector<ll>,greater<ll>> bigger_q;
  priority_queue<ll> smaller_q;
  for(int i = 0;i < N;i++){
    bigger_q.push(P[i]);
  }
  for(int i = 0;i < N/2;i++){
    smaller_q.push(bigger_q.top());
    bigger_q.pop();
  }
  if ( N % 2 == 1){
    bigger_q.pop();
  }
  for(int i = 0;i < N;i++){
    if (P[i] >= bigger_q.top()){

    }
  }
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 1; i <= N;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
