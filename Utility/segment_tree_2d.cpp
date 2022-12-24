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
#include <climits>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
double MAX_VALUE = 1000001;

// https://nyaannyaan.github.io/library/data-structure-2d/2d-segment-tree.hpp

template <typename T, typename F>
struct SegmentTree2D {
 private:
  int id(int h, int w) { return h * 2 * W + w; }

 public:
  int H, W;
  vector<T> seg;
  const F f;
  const T I;

  SegmentTree2D(int h, int w, F _f, const T& i) : f(_f), I(i) { init(h, w); }

  void init(int h, int w) {
    H = W = 1;
    while (H < h) H <<= 1;
    while (W < w) W <<= 1;
    seg.assign(4 * H * W, I);
  }

  // build にのみ呼ぶ
  void set(int h, int w, const T& x) { seg[id(h + H, w + W)] = x; }

  void build() {
    // w in [W, 2W)
    for (int w = W; w < 2 * W; w++) {
      for (int h = H - 1; h; h--) {
        seg[id(h, w)] = f(seg[id(2 * h + 0, w)], seg[id(2 * h + 1, w)]);
      }
    }
    // h in [0, 2H)
    for (int h = 0; h < 2 * H; h++) {
      for (int w = W - 1; w; w--) {
        seg[id(h, w)] = f(seg[id(h, 2 * w + 0)], seg[id(h, 2 * w + 1)]);
      }
    }
  }

  T get(int h, int w) const { return seg[id(h + H, w + W)]; }
  T operator()(int h, int w) const { return seg[id(h + H, w + W)]; }

  void update(int h, int w, const T& x) {
    h += H, w += W;
    seg[id(h, w)] = x;
    for (int i = h >> 1; i; i >>= 1) {
      seg[id(i, w)] = f(seg[id(2 * i + 0, w)], seg[id(2 * i + 1, w)]);
    }
    for (; h; h >>= 1) {
      for (int j = w >> 1; j; j >>= 1) {
        seg[id(h, j)] = f(seg[id(h, 2 * j + 0)], seg[id(h, 2 * j + 1)]);
      }
    }
  }

  T _inner_query(int h, int w1, int w2) {
    T res = I;
    for (; w1 < w2; w1 >>= 1, w2 >>= 1) {
      if (w1 & 1) res = f(res, seg[id(h, w1)]), w1++;
      if (w2 & 1) --w2, res = f(res, seg[id(h, w2)]);
    }
    return res;
  }

  // [ (h1,w1), (h2,w2) ) 半開
  T query(int h1,int h2, int w1,  int w2) {
    if (h1 >= h2 || w1 >= w2) return I;
    T res = I;
    h1 += H, h2 += H, w1 += W, w2 += W;
    for (; h1 < h2; h1 >>= 1, h2 >>= 1) {
      if (h1 & 1) res = f(res, _inner_query(h1, w1, w2)), h1++;
      if (h2 & 1) --h2, res = f(res, _inner_query(h2, w1, w2));
    }
    return res;
  }
};

/**
 * @brief 二次元セグメント木
 * @docs docs/data-structure-2d/2d-segment-tree.md
 */

int main(){
    auto f = [](int x, int y) { return max(x,y); };

    SegmentTree2D<  int, function<int(int,int)> > seg(8,8,f,0);
    seg.build();
    // for(int i = 0;i < 8;i++){
    //     for(int j = 0;j < 8;j++){
    //         seg.update(i,j,8*(8-i)+j);
    //     }
    // }
    seg.update(0,0,64);
    seg.update(1,0,56);
    // cout << seg.query(0,1,0,1) << endl;
    // cout << seg.query(1,2,1,2) << endl;
    // cout << seg.query(0,8,0,8) << endl;
    for(int i = 0;i < 8;i++){
        cout << seg.query(0,i,0,1) << endl;
    }
    return 0;
}