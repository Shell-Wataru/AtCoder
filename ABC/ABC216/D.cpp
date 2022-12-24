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
  ll N,M;
  cin >> N >> M;
  vector<stack<ll>> stacks(M);
  vector<ll> current_ball_at(N,-1);
  for(int i = 0;i < M;i++){
    ll k;
    cin >> k;
    for(int j = 0;j < k;j++){
      ll a;
      cin >> a;
      a--;
      stacks[i].push(a);
    }
  }
  queue<ll> new_balls;
  for(int i = 0;i < M;i++){
    new_balls.push(i);
  }
  while(!new_balls.empty()){
    ll i = new_balls.front();
    new_balls.pop();
    ll ball_color = stacks[i].top();
    if (current_ball_at[ball_color] == -1){
      current_ball_at[ball_color] = i;
    }else{
      stacks[i].pop();
      if (!stacks[i].empty()){
        new_balls.push(i);
      }
      stacks[current_ball_at[ball_color]].pop();
      if (!stacks[current_ball_at[ball_color]].empty()){
        new_balls.push(current_ball_at[ball_color]);
      }
      current_ball_at[ball_color] = -1;
    }
  }
  bool is_cleared = true;
  for(int i = 0;i < M;i++){
    if (!stacks[i].empty()){
      is_cleared = false;
      break;
    }
  }
  if (is_cleared){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
