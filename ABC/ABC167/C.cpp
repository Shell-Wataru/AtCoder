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
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;


int main()
{
  // 整数の入力

  ll N, M, X;
  cin >> N >> M >> X;
  vector<ll> C(N);
  vector<vector<ll>> A(N,vector<ll>(M,0));
  for(int i = 0;i < N;i++){
    cin >> C[i];
    for(int j = 0; j < M;j++){
      cin >> A[i][j];
    }
  }

  ll min_cost = BASE_NUM;
  for(int i = 0;i< (1<<N);i++){
    vector<ll> understands(M,0);
    ll cost = 0;
    for(int j = 0;j < N;j++){
      if(i & (1<<j)){
        cost += C[j];
        for(int k = 0;k < M;k++){
          understands[k] += A[j][k];
        }
      }
    }

    bool understood = true;
    for(int k = 0;k < M;k++){
      if (understands[k] < X){
        understood = false;
      }
    }
    if (understood){
      min_cost = min(min_cost,cost);
    }

  }
  if (min_cost == BASE_NUM){
    cout << -1 << endl;
  }else{
    cout << min_cost << endl;
  }
  return 0;
}