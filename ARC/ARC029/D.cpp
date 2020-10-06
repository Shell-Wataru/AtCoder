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
#include <functional>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

//https://ei1333.github.io/luzhiled/snippets/math/fast-fourier-transform.html
//https://cp-algorithms.com/algebra/fft.html#toc-tgt-7
namespace FastFourierTransform
{
  using real = double;

  struct C
  {
    real x, y;

    C() : x(0), y(0) {}

    C(real x, real y) : x(x), y(y) {}

    inline C operator+(const C &c) const { return C(x + c.x, y + c.y); }

    inline C operator-(const C &c) const { return C(x - c.x, y - c.y); }

    inline C operator*(const C &c) const { return C(x * c.x - y * c.y, x * c.y + y * c.x); }

    inline C conj() const { return C(x, -y); }
  };

  const real PI = acosl(-1);
  int base = 1;
  vector<C> rts = {{0, 0},
                   {1, 0}};
  vector<int> rev = {0, 1};

  void ensure_base(int nbase)
  {
    if (nbase <= base)
      return;
    rev.resize(1 << nbase);
    rts.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++)
    {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    while (base < nbase)
    {
      real angle = PI * 2.0 / (1 << (base + 1));
      for (int i = 1 << (base - 1); i < (1 << base); i++)
      {
        rts[i << 1] = rts[i];
        real angle_i = angle * (2 * i + 1 - (1 << base));
        rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
      }
      ++base;
    }
  }

  void fft(vector<C> &a, int n)
  {
    // assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++)
    {
      if (i < (rev[i] >> shift))
      {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for (int k = 1; k < n; k <<= 1)
    {
      for (int i = 0; i < n; i += 2 * k)
      {
        for (int j = 0; j < k; j++)
        {
          C z = a[i + j + k] * rts[j + k];
          a[i + j + k] = a[i + j] - z;
          a[i + j] = a[i + j] + z;
        }
      }
    }
  }

  vector<long long> multiply(const vector<long long> &a, const vector<long long> &b)
  {
    int need = (int)a.size() + (int)b.size() - 1;
    int nbase = 1;
    while ((1 << nbase) < need)
      nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    vector<C> fa(sz);
    for (int i = 0; i < sz; i++)
    {
      int x = (i < (int)a.size() ? a[i] : 0);
      int y = (i < (int)b.size() ? b[i] : 0);
      fa[i] = C(x, y);
    }
    fft(fa, sz);
    C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
    for (int i = 0; i <= (sz >> 1); i++)
    {
      int j = (sz - i) & (sz - 1);
      C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
      fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
      fa[i] = z;
    }
    for (int i = 0; i < (sz >> 1); i++)
    {
      C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
      C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];
      fa[i] = A0 + A1 * s;
    }
    fft(fa, sz >> 1);
    vector<long long> ret(need);
    for (int i = 0; i < need; i++)
    {
      ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
    }
    return ret;
  }
}; // namespace FastFourierTransform

vector<ll> solve(vector<vector<ll>> &G, vector<ll> &S, ll from)
{
  vector<ll> DP(1, 0);
  for (auto to : G[from])
  {
    vector<ll> sub_solve = solve(G, S, to);
    vector<ll> new_dp(DP.size() + sub_solve.size() -1 , numeric_limits<ll>::max());
    for (int i = 0; i < DP.size(); i++)
    {
      for (int j = 0; j < sub_solve.size(); j++)
      {
        new_dp[i + j] = min(new_dp[i + j], DP[i] + sub_solve[j]);
      };
    }
    DP = new_dp;
  }

  for (int i = 0; i < DP.size(); i++)
  {
    DP[i] += S[from];
  }
  DP.insert(DP.begin(), 0);
  //   cout << from << endl;
  // for (auto s : DP)
  // {
  //   cout << s << ",";
  // }
  // cout << endl;
  return DP;
}
int main()
{
  // 整数の入力
  int N, M;
  scanf("%d", &N);
  vector<ll> S(N);
  vector<vector<ll>> G(N);
  ll sum = 0;
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &S[i]);
    sum += S[i];
  }

  for (int i = 0; i < N - 1; i++)
  {
    ll a, b;
    scanf("%lld%lld", &a, &b);
    a--;
    b--;
    G[a].push_back(b);
  }

  scanf("%d", &M);
  vector<ll> T(M);
  for (int i = 0; i < M; i++)
  {
    scanf("%lld", &T[i]);
  }
  sort(T.begin(), T.end(), greater<ll>());
  T.insert(T.begin(), 0);
  vector<ll> solved = solve(G, S, 0);
  ll t_total = 0;
  ll s_total = 0;
  // for (auto s : solved)
  // {
  //   cout << s << ",";
  // }
  // cout << endl;
  // for (auto s : T)
  // {
  //   cout << s << ",";
  // }
  // cout << endl;
  ll max_sum = 0;
  for (int i = 0; i <= min(M,N); i++)
  {
    t_total += T[i];
    // cout << t_total << endl;
    // cout << sum - solved[i] + t_total << endl;
    max_sum = max(max_sum,sum - solved[i] + t_total);
  }
  cout << max_sum << endl;
  return 0;
}