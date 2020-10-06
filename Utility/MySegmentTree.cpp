#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
double MAX_VALUE = 1000001;

// https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
template< typename Monoid >
struct SegmentTree {
  using F = function< bool(Monoid &, Monoid &, Monoid &) >;

  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      f(seg[k], seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      bool changed = f(seg[k],seg[2 * k + 0], seg[2 * k + 1]);
      if (!changed){
        break;
      }
    }
  }

  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) f(L , L, seg[a++]);
      if(b & 1) f(R , seg[--b], R);
    }
    f(L, L, R);
    return L;
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }
};

int main() {
  vector<int> a{1,2,3,4,5,6,7,8};
  SegmentTree< int > seg(a.size(), [](int &target,int &a, int &b) {
    if (target != min(a, b)){
      target = min(a,b);
      return true;
    }else{
      return false;
    }
  }, INT_MAX);
  for(int i = 0;i < a.size();i++){
      seg.set(i, a[i]);
  }
  seg.build();
  cout << seg.query(0,a.size()) << endl;
  seg.update(0,10);
  cout << seg.query(0,a.size()) << endl;
}