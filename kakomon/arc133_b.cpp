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
  ll N;
  cin >> N;
  vector<ll> P(N);
  vector<ll> Q(N);
  vector<ll> invQ(N+1);
  for(int i = 0;i < N;i++){
      cin >> P[i];
  }
  for(int i = 0;i < N;i++){
      cin >> Q[i];
      invQ[Q[i]] = i;
  }
  vector<ll> DP(N+1,numeric_limits<ll>::max());
  for(int i = 0;i < N;i++){
      vector<ll> indices;
      for(int j = 1;j * P[i]<= N;j++){
          indices.push_back(invQ[j*P[i]]);
      }
      sort(indices.rbegin(),indices.rend());
      for(auto j:indices){
          *lower_bound(DP.begin(),DP.end(),j) = j;
      }
  }
  cout << lower_bound(DP.begin(),DP.end(),numeric_limits<ll>::max()) - DP.begin() << endl;;
  return 0;
}
