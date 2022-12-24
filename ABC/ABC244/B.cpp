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

using namespace std;
using ll = long long;

vector<pair<ll,ll>> directions = {
  {1,0},
  {0,-1},
  {-1,0},
  {0,1}
};
int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  string T;
  cin >> T;
  ll x = 0;
  ll y = 0;
  ll d_index = 0;
  for(auto c:T){
    if (c == 'S'){
      x += directions[d_index].first;
      y += directions[d_index].second;
    }else{
      d_index = (d_index + 1) % 4;
    }
  }
  cout << x << " " << y << endl;
  return 0;
}