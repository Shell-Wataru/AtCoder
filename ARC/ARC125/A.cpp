#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll N,M;
  cin >> N;
  cin >> M;
  vector<ll> S(N);
  vector<ll> T(M);
  for(int i = 0;i < N;i++){
    cin >> S[i];
  }
  for(int i = 0;i < M;i++){
    cin >> T[i];
  }
  bool contains_zero = false;
  bool contains_one = false;
  for(int i = 0;i < N;i++){
    if (S[i] == 0){
      contains_zero = true;
    }else{
      contains_one = true;
    }
  }
  if (!contains_zero){
    for(int i = 0;i < M;i++){
      if (T[i] == 0){
        cout << -1 << endl;
        return 0;
      }
    }
    cout << M << endl;
    return 0;
  }else if (!contains_one){
    for(int i = 0;i < M;i++){
      if (T[i] == 1){
        cout << -1 << endl;
        return 0;
      }
    }
    cout << M << endl;
    return 0;
  }else{
    ll ans = 0;
    ll move =  N;
    for(ll i = 1;i < N;i++){
      if (S[i] != S[0]){
        move = min(move,i);
      }
    }
    for(int i = N-1;i >= 1;i--){
      if (S[i] != S[0]){
        move = min(move,N-i);
      }
    }
    ll current = S[0];
    for(int i = 0;i<M;i++){
      if (T[i] == current){
        ans++;
      }else{
        ans += move;
        ans++;
        move = 1;
        current = T[i];
      }
    }
    cout << ans << endl;
  }

  return 0;
}