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
#include <climits>

using namespace std;
using ll = long long;

int main()
{
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for(int i = 0;i < N;i++){
      cin >> A[i];
    }
    ll ans = 0;
    for(int i = 30;i>=0;i--){
      vector<ll> moves(N);
      ll target = ans | (1ll<<i);
      // cout << "Target" << target  << endl;
      for(int j = 0;j < N;j++){
        ll remain = target & ~A[j];
        if (remain == 0){
          moves[j] = 0;
        }else{
          ll a = 1ll<<(64 - __builtin_clzll(remain));
          moves[j] = (target % a) - (A[j] % a);
          // if (i == 2){
          // cout << "remain" << remain  << endl;
          // cout << "a" << a  << endl;
          // cout << "A[j]" << A[j]  << endl;
          // cout << "move" << moves[j]  << endl;

          // }
        }
      }
      sort(moves.begin(),moves.end());
      ll total_move = 0;
      for(int j = 0;j < K;j++){
        total_move += moves[j];
      }
      if (total_move <= M){
        // cout << i << endl;
        ans = target;
      }
    }
    cout << ans << endl;
    return 0;
}