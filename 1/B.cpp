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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
  // 整数の入力
  ll N,M,Q;
  cin >> N >> M >> Q;
  vector<ll> question_solved(M,0);
  vector<vector<ll>> human_solved(N,vector<ll>(M,0));
  for(int i = 0;i < Q;i++){
    ll type;
    cin >> type;
    if (type == 1){
      ll n;
      cin >> n;
      n--;
      ll score = 0;
      for(int j = 0;j < M;j++){
        if (human_solved[n][j] == 1){
          score += N - question_solved[j];
        }
      }
      cout << score << endl;
    }else{
      ll n,m;
      cin >> n >> m;
      n--;
      m--;
      human_solved[n][m]++;
      question_solved[m]++;
    }
  }
  return 0;
}