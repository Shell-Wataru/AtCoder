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
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
  ll N;
  cin >> N;
  vector<ll> C(9);
  ll minimum = numeric_limits<ll>::max();
  for(int i = 0;i < 9;i++){
    cin >> C[i];
    minimum = min(minimum,C[i]);
  }
  while(N >= minimum){
    pair<ll,ll> maximum = {0,0};
    for(int i = 0;i < 9;i++){
      if (N < C[i]){
        continue;
      }
      ll remain = N- C[i];
      ll remain_maximum_digit = (N-C[i])/minimum;
      maximum = max(maximum,{remain_maximum_digit,i});
    }
    cout << maximum.second + 1;
    N -= C[maximum.second];
  }
  cout << endl;
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 0;i < N;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
