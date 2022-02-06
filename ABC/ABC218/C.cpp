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

bool can_make(ll N,vector<string>  &S,vector<string>  &T){
  ll s_count = 0;
  ll t_count = 0;
  ll s_min_i = numeric_limits<ll>::max();
  ll s_max_i = numeric_limits<ll>::min();
  ll s_min_j = numeric_limits<ll>::max();
  ll s_max_j = numeric_limits<ll>::min();
  ll t_min_i = numeric_limits<ll>::max();
  ll t_max_i = numeric_limits<ll>::min();
  ll t_min_j = numeric_limits<ll>::max();
  ll t_max_j = numeric_limits<ll>::min();
  for(ll i = 0;i < N;i++){
    for(ll j = 0;j < N;j++){
      if (S[i][j] == '#'){
        s_count++;
        s_min_i = min(s_min_i,i);
        s_max_i = max(s_max_i,i);
        s_min_j = min(s_min_j,j);
        s_max_j = max(s_max_j,j);
      }
      if (T[i][j] == '#'){
        t_count++;
        t_min_i = min(t_min_i,i);
        t_max_i = max(t_max_i,i);
        t_min_j = min(t_min_j,j);
        t_max_j = max(t_max_j,j);
      }
    }
  }
  if (s_count != t_count){
    return false;
  }
  bool ans = false;
  if (s_max_i - s_min_i ==  t_max_i - t_min_i && s_max_j - s_min_j ==  t_max_j - t_min_j){
    bool make_0 = true;
    for(int i = 0;i < s_max_i - s_min_i+1;i++){
      for(int j = 0; j < s_max_j - s_min_j+1;j++){
        if (S[s_min_i + i][s_min_j+ j] != T[t_min_i+i][t_min_j+j]){
          make_0 = false;
        }
      }
    }
    if (make_0){
      ans = true;
    }
    bool make_180 = true;
    for(int i = 0;i < s_max_i - s_min_i+1;i++){
      for(int j = 0; j < s_max_j - s_min_j+1;j++){
        if (S[s_min_i + i][s_min_j+ j] != T[t_max_i-i][t_max_j-j]){
          make_180 = false;
        }
      }
    }
    if (make_180){
      ans = true;
    }
  }

  if (s_max_i - s_min_i ==  t_max_j - t_min_j && s_max_j - s_min_j ==  t_max_i - t_min_i){
    bool make_90 = true;
    for(int i = 0;i < s_max_i - s_min_i+1;i++){
      for(int j = 0; j < s_max_j - s_min_j+1;j++){
        if (S[s_min_i + i][s_min_j+ j] != T[t_max_i-j][t_min_j+i]){
          make_90 = false;
        }
      }
    }
    if (make_90){
      ans = true;
    }
    bool make_270 = true;
    for(int i = 0;i < s_max_i - s_min_i+1;i++){
      for(int j = 0; j < s_max_j - s_min_j+1;j++){
        if (S[s_min_i + i][s_min_j+ j] != T[t_min_i+j][t_max_j-i]){
          make_270 = false;
        }
      }
    }
    if (make_270){
      ans = true;
    }
  }

  return ans;
}
int main()
{
  ll N;
  cin >> N;
  vector<string> S(N);
  vector<string> T(N);
  for(int i = 0;i < N;i++){
    cin >> S[i];
  }
  for(int i = 0;i < N;i++){
    cin >> T[i];
  }
  if (can_make(N,S,T)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}