#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

int main()
{
  // 整数の入力
  ll N = 13;
  vector<vector<ll>> ans(N*N+N + 1,vector<ll>(N*N+N + 1,0));
  ll P = 0;
  vector<ll> Q(N);
  iota(Q.begin(),Q.end(),1);
  vector<vector<ll>> R(N,vector<ll>(N));
  for(int i = 0;i < N;i++){
    for (int j = 0; j < N; j++)
    {
      R[i][j] = N + 1 + N * i + j;
    }
  }

  ans[0][P] = 1;
  for(int i = 0;i < N;i++){
    ans[0][Q[i]] = 1;
  }

  for(int i = 0;i < N;i++){
    ans[i+1][P] = 1;
    for(int j = 0;j < N;j++){
      ans[i+1][R[j][i]] = 1;
    }
  }

  for(int r = 0;r < N;r++){
    for(int c = 0;c < N;c++){
      ans[N+1 + N*r + c][Q[c]] = 1;
      for (int i = 0; i < N; i++)
      {
        ans[N+1 + N*r + c][R[(r + c*i) % N][i]] = 1;
      }
    }
  }
  for(int i = 0;i< 150;i++){
    for(int j = 0;j < 150;j++){
      if (ans[i][j] == 1){
        cout << 'O';
      }else{
        cout << '.';
      }
    }
    cout << endl;
  }
  return 0;
}