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

namespace mp = boost::multiprecision;
using namespace std;

template<typename T> struct V : vector<T> { using vector<T>::vector; };
V() -> V<int>;
V(size_t) -> V<int>;
template<typename T> V(size_t, T) -> V<T>;
template<typename T> vector<T> make_vec(size_t n, T a) { return vector<T>(n, a); }
template<typename... Ts> auto make_vec(size_t n, Ts... ts) { return vector<decltype(make_vec(ts...))>(n, make_vec(ts...)); }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for (auto &e : v) os << e << ' '; return os; }
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;


using ll = long long;

const long long BASE_NUM = 1000000007;

int main()
{
  ll N,P;
  cin >> N >> P;
  V<pair<ll,ll>> W(N);
  for(int i = 0; i < N;i++){
    cin >> W[i].first >> W[i].second;
  }
  sort(W.begin(),W.end(),greater<pair<ll,ll>>());
  auto max_values = make_vec<ll>(N+1,0);
  for(int i = N-1;i >= 0;i--){
    max_values[i] = max(max_values[i+1],W[i].second);
  }
  // cout << max_values << endl;
  auto DP = make_vec<ll>(N+1,P+1,0ll);
  ll ans = 0;
  for(int i = 0;i < N;i++){
    for(int j = 0;j <= P;j++){
      DP[i+1][j] = max(DP[i+1][j], DP[i][j]);
      if (j + W[i].first <= P){
        DP[i+1][j + W[i].first] = max(DP[i+1][j + W[i].first],DP[i][j] + W[i].second);
      }
      ans = max(ans,DP[i+1][j] + max_values[i+1]);
    }
  }
  // for(int i = 0;i <= N;i++){
  //   for(int j = 0;j <= P;j++){
  //     cout << DP[i][j] << ",";
  //   }
  //   cout << endl;
  // }
  cout << ans << endl;
  return 0;
}