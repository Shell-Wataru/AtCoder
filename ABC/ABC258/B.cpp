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

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  string answer = "";
  vector<string> S(N);
  vector<pair<ll,ll>> directions = {
    {1,1},
    {1,0},
    {1,-1},
    {0,1},
    {0,-1},
    {-1,1},
    {-1,0},
    {-1,-1}
  };
  for(int i = 0;i < N;i++){
    cin >> S[i];
  }
  for(int i = 0;i < N;i++){
    for(int j = 0;j < N;j++){
      for(auto d:directions){
        string s;
        for(int k = 0;k < N;k++){
          ll x= (i + d.first*k + N) % N;
          ll y= (j + d.second*k + N) % N;
          // cout << x << "," << y << endl;
          s += S[x][y];
        }
        answer = max(answer,s);
      }
    }
  }
  cout << answer<< endl;
  return 0;
}