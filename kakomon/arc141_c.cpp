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

int solve()
{
  ll N;
  cin >> N;
  deque<ll> A(2*N);
  deque<ll> B(2*N);
  for(int i = 0;i < 2*N;i++){
    cin >> A[i];
    A[i]--;
  }
  for(int i = 0;i < 2*N;i++){
    cin >> B[i];
    B[i]--;
  }
  string ans(2*N,'?');
  ll depth = 0;
  queue<ll> opens;
  queue<ll> closes;
  ans[A[0]] = '(';
  opens.push(A[0]);
  ll a_depth = 1;
  ll b_depth = 0;
  A.pop_front();
  while(!opens.empty()){
    while(!opens.empty()){
        ll a = opens.front();
        opens.pop();
        while(B.back() != a){
            if (ans[B.back()] == '?'){
                ans[B.back()] = ')';
                closes.push(B.back());
                b_depth++;
            }else{
                cout << -1 << endl;
                return 0;
            }
            B.pop_back();
        }
        b_depth--;
        B.pop_back();
        if (b_depth < 0){
            cout << -1 << endl;
            return 0;
        }
    }

    while(!closes.empty()){
        ll b = closes.front();
        closes.pop();
        while(A.front() != b){
            if (ans[A.front()] == '?'){
                ans[A.front()] = '(';
                a_depth++;
                opens.push(A.front());
            }else{
                cout << -1 << endl;
                return 0;
            }
            A.pop_front();
        }
        a_depth--;
        A.pop_front();
        if (a_depth < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    if (a_depth == 0 && !A.empty()){
        opens.push(A.front());
        ans[A.front()] = '(';
        a_depth++;
        A.pop_front();
    }
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
