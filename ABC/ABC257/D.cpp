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

ll answer(vector<vector<ll>> &J, ll l,ll r){
  if (l+1 == r){
    return r;
  }
  ll center = (l+r)/2;
  ll N = J.size();
  for(int i = 0;i < N;i++){
    queue<ll> q;
    vector<bool> visited(N);
    q.push(i);
    visited[i] = true;
    while(!q.empty()){
      ll current = q.front();
      q.pop();
      for(int j = 0;j < N;j++){
        if (!visited[j] && (abs(J[current][0] - J[j][0]) + abs(J[current][1] - J[j][1])+center - 1)/center <= J[current][2]){
          q.push(j);
          visited[j] = true;
        }
      }
    }
    if (all_of(visited.begin(),visited.end(),[](bool v){ return v;})){
      return answer(J,l,center);
    }
  }
  return answer(J,center,r);
}

int solve()
{
  ll N;
  cin >> N;
  vector<vector<ll>> J(N,vector<ll>(3));
  for(int i = 0;i < N;i++){
    cin >> J[i][0] >> J[i][1] >> J[i][2];
  }
  cout << answer(J,0,numeric_limits<ll>::max()/2) << endl;
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
