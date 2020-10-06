#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;

const ll INF = numeric_limits<ll>::max();
struct LazySegmentTree
{
private:
  ll n;
  vector<ll> node, lazy;
  vector<bool> lazyFlag;

public:
  LazySegmentTree(vector<ll> v)
  {
    ll sz = (ll)v.size();
    n = 1;
    while (n < sz)
      n *= 2;
    node.resize(2 * n - 1);
    lazy.resize(2 * n - 1, 0);
    lazyFlag.resize(2 * n - 1, false);

    for (ll i = 0; i < sz; i++)
      node[i + n - 1] = v[i];
    for (ll i = n - 2; i >= 0; i--)
      node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);
  }

  void lazyEvaluate(ll k, ll l, ll r)
  {
    if (lazyFlag[k])
    {
      node[k] = lazy[k] + node[k];
      if (r - l > 1)
      {
        lazy[k * 2 + 1] = lazy[k * 2 + 1] + lazy[k];
        lazy[k * 2 + 2] = lazy[k * 2 + 2] + lazy[k];
        lazyFlag[k * 2 + 1] = lazyFlag[k * 2 + 2] = true;
      }
      lazyFlag[k] = false;
      lazy[k] = 0;
    }
  }

  void update(ll a, ll b, ll x, ll k = 0, ll l = 0, ll r = -1)
  {
    if (r < 0)
      r = n;
    lazyEvaluate(k, l, r);
    if (b <= l || r <= a)
      return;
    if (a <= l && r <= b)
    {
      lazy[k] = lazy[k] + x;
      lazyFlag[k] = true;
      lazyEvaluate(k, l, r);
    }
    else
    {
      update(a, b, x, 2 * k + 1, l, (l + r) / 2);
      update(a, b, x, 2 * k + 2, (l + r) / 2, r);
      node[k] = min(node[2 * k + 1], node[2 * k + 2]);
    }
  }

  ll find(ll a, ll b, ll k = 0, ll l = 0, ll r = -1)
  {
    if (r < 0)
      r = n;
    lazyEvaluate(k, l, r);
    if (b <= l || r <= a)
      return INF;
    if (a <= l && r <= b)
      return node[k];
    ll vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
    ll vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
    return min(vl, vr);
  }

  int find_rightest_sub(int a, int b, ll x, int k = 0, int l = 0, int r = -1)
  {
    if (r < 0)
      r = n;
    lazyEvaluate(k, l, r);
    if (node[k] > x || r <= a || b <= l)
    { // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn -1
      return -1;
    }
    else if (k >= n - 1)
    { // 自分が葉ならその位置をreturn
      return (k - (n - 1));
    }
    else
    {
      int vr = find_rightest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
      if (vr != -1)
      { // 右の部分木を見て -1 以外ならreturn
        return vr;
      }
      else
      { // 左の部分木を見て値をreturn
        return find_rightest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
      }
    }
  }
};

int solve()
{
  ll n, q;
  cin >> n >> q;
  vector<ll> A(n + 1, 0);
  for (int i = 0; i < n; i++)
  {
    ll a;
    scanf("%lld", &a);
    A[a]++;
  }
  for (int i = 1; i <= n; i++)
  {
    A[i] += A[i - 1];
  }
  LazySegmentTree seg(A);
  for (int i = 0; i < q; i++)
  {
    ll x;
    scanf("%lld", &x);
    if (x < 0)
    {
      x = -x;
      ll kth_value = seg.find_rightest_sub(0, A.size(), x - 1) + 1;
      seg.update(kth_value, n + 1, -1);
      // for(int j = 0;j <= n;j++){
      //   cout << seg.find(j,j+1);
      // }
      // cout << endl;
    }
    else
    {
      seg.update(x, n + 1, 1);
    }
  }
  // for(int i = 0;i <= n;i++){
  //   cout << seg.find(i,i+1) << endl;
  // }
  ll ans = seg.find_rightest_sub(0, A.size(), 0);
  if (ans == n)
  {
    cout << 0 << endl;
  }
  else
  {
    cout << ans + 1 << endl;
  }

  return 0;
}

int main()
{
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  // cout << flush;
  return 0;
}