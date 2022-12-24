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
#include <unordered_map>
using namespace std;
using ll = long long;

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  bool same(int x, int y) {
    x = find(x), y = find(y);
    return x == y;
  }
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};


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

vector<int> prime_numbers(int n){
    if (n <= 1){
        return vector<int>(0);
    }
    vector<int> ans = {2};
    for(int i = 3;i <= n;i++){
        bool is_prime = true;
        for(int j = 0; ans[j] * ans[j] <= i;j++){
            if (i % ans[j] == 0){
                is_prime = false;
                break;
            }
        }
        if (is_prime){
            ans.push_back(i);
        }
    }
    return ans;
}
vector<int> primes = prime_numbers(1000000);

int solve()
{
  ll N,K;
  cin >> N >> K;
  if (K == 0){
    cout << 1 << endl;
    return 0;
  }
  vector<ll> denominator(K);
  vector<ll> numerator(K);
  iota(numerator.begin(),numerator.end(),N-K+1);
  iota(denominator.begin(),denominator.end(),1);
  unordered_map<ll,ll> counts;
  for(auto p:primes){
    for(int i = 1;p*i <= K;i++){
        while(denominator[p*i-1] % p == 0){
            denominator[p*i-1] /= p;
            counts[p]--;
        }
    }
  }
  for(auto p:primes){
    for(ll i = (N-K+1+p-1)/p;p*i <= N;i++){
        while(numerator[p*i-(N-K+1)] % p == 0){
            numerator[p*i-(N-K+1)] /= p;
            counts[p]++;
        }
    }
  }
  ll ans = 1;
  for(auto n:numerator){
    if (n > 1 ){
        ans *=  2;
        ans %= 998244353;
    }
  }
  for(auto p:counts){
    ans *= (p.second+1);
    ans %= 998244353;
  }
  cout << ans << endl;
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
