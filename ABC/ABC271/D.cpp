#define _USE_MATH_DEFINES
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

int main()
{
  ll N,S;
  cin >> N >> S;
  vector<pair<ll,ll>>ab(N);
  for(int i = 0;i < N;i++){
    cin >> ab[i].first >> ab[i].second;
  }
  vector<vector<bool>> DP(N+1,vector<bool>(S+1,false));
  DP[0][0] = true;
  for(int i = 0;i < N;i++){
    for(int j = 0;j+ab[i].first <= S ;j++){
        DP[i+1][j+ab[i].first] = DP[i+1][j+ab[i].first] || DP[i][j];
    }
    for(int j = 0;j+ab[i].second <= S ;j++){
        DP[i+1][j+ab[i].second] = DP[i+1][j+ab[i].second] || DP[i][j];
    }
  }
  if (DP[N][S]){
    string answers(N,'a');
    // cout << answers << endl;
    ll current = S;
    for(int i = N-1;i>= 0;i--){
        if (current-ab[i].first >= 0 && DP[i][current-ab[i].first]){
            answers[i] = 'H';
            current -= ab[i].first;
        }else{
            answers[i] = 'T';
            current -= ab[i].second;
        }
    }
    cout << "Yes\n" << answers << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}