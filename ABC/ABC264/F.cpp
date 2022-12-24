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
#include <set>
#include <atcoder/mincostflow>
using namespace std;
using ll = long long;
using namespace atcoder;

template <typename T>
struct V : vector<T>
{
    using vector<T>::vector;
};
V()->V<int>;
V(size_t)->V<int>;
template <typename T>
V(size_t, T) -> V<T>;
template <typename T>
vector<T> make_vec(size_t n, T a) { return vector<T>(n, a); }
template <typename... Ts>
auto make_vec(size_t n, Ts... ts) { return vector<decltype(make_vec(ts...))>(n, make_vec(ts...)); }
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto &e : v)
        os << e << ' ';
    return os;
}
struct fast_ios
{
    fast_ios()
    {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    };
} fast_ios_;

ll answer(ll H, ll W,char target, vector<ll> &R,vector<ll> &C,vector<string> &A){
  auto DP = make_vec(H,W,4,numeric_limits<ll>::max()/2);
  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
        if (i== 0 && j == 0){
            if (A[i][j] == target){
                DP[i][j][0] = 0;
                DP[i][j][3] = R[i]+C[j];
            }else{
                DP[i][j][1] = R[i];
                DP[i][j][2] = C[j];
            }
        }else{
            if (i > 0){
                if (A[i][j] == target){
                    DP[i][j][0] = min(DP[i][j][0],DP[i-1][j][0]);
                    DP[i][j][0] = min(DP[i][j][0],DP[i-1][j][1]);
                    // 反転
                    DP[i][j][3] = min(DP[i][j][3],DP[i-1][j][2] + R[i]);
                    DP[i][j][3] = min(DP[i][j][3],DP[i-1][j][3] + R[i]);
                }else{
                    DP[i][j][1] = min(DP[i][j][1],DP[i-1][j][0] + R[i]);
                    DP[i][j][1] = min(DP[i][j][1],DP[i-1][j][1] + R[i]);
                    // 反転
                    DP[i][j][2] = min(DP[i][j][2],DP[i-1][j][2]);
                    DP[i][j][2] = min(DP[i][j][2],DP[i-1][j][3]);
                }
            }
            if (j > 0){
                if (A[i][j] == target){
                    DP[i][j][0] = min(DP[i][j][0],DP[i][j-1][0]);
                    DP[i][j][3] = min(DP[i][j][3],DP[i][j-1][1] + C[j]);
                    DP[i][j][0] = min(DP[i][j][0],DP[i][j-1][2]);
                    DP[i][j][3] = min(DP[i][j][3],DP[i][j-1][3] + C[j]);
                }else{
                    DP[i][j][2] = min(DP[i][j][2],DP[i][j-1][0] + C[j]);
                    DP[i][j][1] = min(DP[i][j][1],DP[i][j-1][1]);
                    DP[i][j][2] = min(DP[i][j][2],DP[i][j-1][2] + C[j]);
                    DP[i][j][1] = min(DP[i][j][1],DP[i][j-1][3]);
                }
            }
        }
    }
  }
  ll ans = numeric_limits<ll>::max();
  for(int i = 0;i < 4;i++){
    ans = min(ans,DP[H-1][W-1][i]);
  }
  return ans;
}

int solve()
{
  ll H,W;
  cin >> H >> W;
  vector<ll> R(H);
  vector<ll> C(W);
  vector<string> A(H);
  for(int i = 0;i < H;i++){
    cin >> R[i];
  }
  for(int i = 0;i < W;i++){
    cin >> C[i];
  }
  for(int i = 0;i < H;i++){
    cin >> A[i];
  }
  cout << min( answer(H,W,'0',R,C,A), answer(H,W,'1',R,C,A)) << endl;
  return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
