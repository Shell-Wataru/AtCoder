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
using namespace std;
using ll = long long;

struct Mo {
  using ADD = function< void(int) >;
  using DEL = function< void(int) >;
  using REM = function< void(int) >;

  int width;
  vector< int > left, right, order;
  vector< bool > v;

  Mo(int N, int Q) : width((int) sqrt(N)), order(Q), v(N) {
    iota(begin(order), end(order), 0);
  }

  void add(int l, int r) { /* [l, r) */
    left.emplace_back(l);
    right.emplace_back(r);
  }

  int run(const ADD &add, const DEL &del, const REM &rem) {
    // assert(left.size() == order.size());
    sort(begin(order), end(order), [&](int a, int b) {
      int ablock = left[a] / width, bblock = left[b] / width;
      if(ablock != bblock) return ablock < bblock;
      if(ablock & 1) return right[a] < right[b];
      return right[a] > right[b];
    });
    int nl = 0, nr = 0;
    auto push = [&](int idx) {
      v[idx].flip();
      if(v[idx]) add(idx);
      else del(idx);
    };
    for(auto idx : order) {
      while(nl > left[idx]) push(--nl);
      while(nr < right[idx]) push(nr++);
      while(nl < left[idx]) push(nl++);
      while(nr > right[idx]) push(--nr);
      rem(idx);
    }
    return 0;
  }
};


int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
    A[i]--;
  }
  ll Q;
  cin >> Q;
  Mo mo(N,Q);
  for(int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    mo.add(--l, r);
  }
  vector<ll> colors(N,0);
  ll ret = 0;
  auto add = [&](int idx) {
    colors[A[idx]]++;
    if (colors[A[idx]] % 2 == 0){
      ret++;
    }
  };
  auto del = [&](int idx) {
    colors[A[idx]]--;
    if (colors[A[idx]] % 2 == 1){
      ret--;
    }
   };
  vector< int > ans(Q);
  auto rem = [&](int idx) { ans[idx] = ret; };
  mo.run(add, del, rem);
  for(int i = 0; i < Q; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
