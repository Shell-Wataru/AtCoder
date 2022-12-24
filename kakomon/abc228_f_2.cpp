#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <climits>
#include <numeric>
using namespace std;
using ll = long long;

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


int solve()
{
    ll H, W, h1, w1, h2, w2;
    cin >> H >> W >> h1 >> w1 >> h2 >> w2;
    h2 = min(h1,h2);
    w2 = min(w1,w2);
    vector<vector<ll>> A(H, vector<ll>(W, 0));
    vector<vector<ll>> cumA(H + 1, vector<ll>(W + 1, 0));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> A[i][j];
            cumA[i + 1][j + 1] = A[i][j];
        }
    }
    for (int i = 0; i <= H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cumA[i][j + 1] += cumA[i][j];
        }
    }
    for (int j = 0; j <= W; j++)
    {
        for (int i = 0; i < H; i++)
        {
            cumA[i + 1][j] += cumA[i][j];
        }
    }
    // for(int i = 0;i <= H;i++){
    //     for(int j = 0;j <= W;j++){
    //         cout << cumA[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    auto f = [](ll x, ll y) { return max(x,y); };

    SegmentTree2D< ll, function<ll(ll,ll)> > seg(H+1,W+1, f, 0ll);

    for(int i = 0;i+h2 <= H;i++){
        for(int j = 0;j + w2 <= W;j++){
            seg.set(i,j,cumA[i+h2][j+w2] - cumA[i+h2][j] - cumA[i][j+w2] + cumA[i][j]);
            // cout << cumA[i+h2][j+w2] - cumA[i+h2][j] - cumA[i][j+w2] + cumA[i][j] << ",";
        }
        // cout << endl;
    }
    seg.build();
    // cout << endl;

    // for(int i = 0;i+h2 <= H;i++){
    //     for(int j = 0;j + w2 <= W;j++){
    //         cout << seg.query(i,i+1,j,j+1) << ",";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    ll ans = 0;
    for(int i = 0;i+h1 <= H;i++){
        for(int j = 0;j + w1 <= W;j++){
            ans = max(ans,
                cumA[i+h1][j+w1] - cumA[i+h1][j] - cumA[i][j+w1] + cumA[i][j] - seg.query(i,i+h1-h2+1,j,j+w1-w2+1)
            );
            // cout << i << "," << j << endl;
            // cout << "b:" << cumA[i+h1][j+w1] - cumA[i+h1][j] - cumA[i][j+w1] + cumA[i][j] << endl;
            // cout << "w:" << seg.query(i,i+h1-h2+1,j,j+w1-w2+1) << endl;
            // cout << cumA[i+h1][j+w1] - cumA[i+h1][j] - cumA[i][j+w1] + cumA[i][j] - seg.query(i,i+h1-h2+1,j,j+w1-w2+1) << endl;
        }
        // cout << endl;
    }
    cout << ans << "\n";
    return 0;
}
int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
