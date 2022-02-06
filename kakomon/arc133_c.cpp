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
#include <stack>

using namespace std;
using ll = long long;

ll maximum(vector<ll> &A,ll W, ll K){
    ll total = 0;
    ll ideal = (K - 1)*W;
    for(auto a:A){
        if (ideal/K * K + a <= ideal){
            total += ideal/K * K + a;
        }else{
            total += (ideal/K - 1) * K + a;
        }
    }
    return total;
}
int main()
{
  // 整数の入力
  ll H,W,K;
  cin >> H >> W >> K;
  vector<ll> A(H);
  vector<ll> B(W);
  ll a_total = 0;
  ll b_total = 0;
  for(int i = 0;i < H;i++){
      cin >> A[i];
      a_total += A[i];
  }
  for(int i = 0;i < W;i++){
      cin >> B[i];
      b_total += B[i];
  }
  if ( (a_total - b_total) % K != 0){
      cout << -1 << endl;
  }else{
      cout << min(maximum(A,W,K),maximum(B,H,K)) << endl;
  }
  return 0;
}
