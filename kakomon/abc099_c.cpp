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
    ll N;
    cin >> N;
    vector<ll> W;
    W.push_back(1);
    ll six = 6;
    while(six <= N){
      W.push_back(six);
      six = six*6;
    }
    ll nine = 9;
    while(nine <= N){
      W.push_back(nine);
      nine = nine*9;
    }
    vector<vector<ll>> DP(W.size(),vector<ll>(N+1,numeric_limits<ll>::max()));
    DP[0][0] = 0;
    for(int i = 0;i < W.size();i++){
      for(int j = 0;j <= N;j++){
        if (i-1 >= 0){
          DP[i][j] = min(DP[i-1][j], DP[i][j]);
        }
        if (j - W[i] >= 0){
          DP[i][j] = min(DP[i][j-W[i]]+1, DP[i][j]);
        }
      }
    }
    cout << DP[W.size()-1][N] << endl;
    return 0;
}