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

template <class T>
struct Matrix
{
  vector<vector<T>> A;

  Matrix() {}

  Matrix(size_t n, size_t m) : A(n, vector<T>(m, 0)) {}

  Matrix(size_t n) : A(n, vector<T>(n, 0)){};

  size_t height() const
  {
    return (A.size());
  }

  size_t width() const
  {
    if (height() == 0)
    {
      return 0;
    }
    else
    {
      return (A[0].size());
    }
  }

  inline const vector<T> &operator[](int k) const
  {
    return (A.at(k));
  }

  inline vector<T> &operator[](int k)
  {
    return (A.at(k));
  }

  static Matrix I(size_t n)
  {
    Matrix mat(n);
    for (int i = 0; i < n; i++)
      mat[i][i] = 1;
    return (mat);
  }

  Matrix &operator+=(const Matrix &B)
  {
    size_t n = height(), m = width();
    // assert(n == B.height() && m == B.width());
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        (*this)[i][j] += B[i][j];
    return (*this);
  }

  Matrix &operator-=(const Matrix &B)
  {
    size_t n = height(), m = width();
    // assert(n == B.height() && m == B.width());
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        (*this)[i][j] -= B[i][j];
    return (*this);
  }

  Matrix &operator*=(const Matrix &B)
  {
    size_t n = height(), m = B.width(), p = width();
    // assert(p == B.height());
    vector<vector<T>> C(n, vector<T>(m, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        for (int k = 0; k < p; k++)
          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j] % BASE_NUM) % BASE_NUM;
    A.swap(C);
    return (*this);
  }

  Matrix &operator^=(long long k)
  {
    Matrix B = Matrix::I(height());
    while (k > 0)
    {
      if (k & 1)
        B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return (*this);
  }

  Matrix operator+(const Matrix &B) const
  {
    return (Matrix(*this) += B);
  }

  Matrix operator-(const Matrix &B) const
  {
    return (Matrix(*this) -= B);
  }

  Matrix operator*(const Matrix &B) const
  {
    return (Matrix(*this) *= B);
  }

  Matrix operator^(const long long k) const
  {
    return (Matrix(*this) ^= k);
  }

  friend ostream &operator<<(ostream &os, Matrix &p)
  {
    size_t n = p.height(), m = p.width();
    for (int i = 0; i < n; i++)
    {
      os << "[";
      for (int j = 0; j < m; j++)
      {
        os << p[i][j] << (j + 1 == m ? "]\n" : ",");
      }
    }
    return (os);
  }

  T determinant()
  {
    Matrix B(*this);
    // assert(width() == height());
    T ret = 1;
    if (B.width() == 0)
    {
      return ret;
    }
    for (int i = 0; i < width(); i++)
    {
      int idx = -1;
      for (int j = i; j < width(); j++)
      {
        if (B[j][i] != 0)
          idx = j;
      }
      if (idx == -1)
        return (0);
      if (i != idx)
      {
        ret *= -1;
        swap(B[i], B[idx]);
      }
      ret *= B[i][i];
      T vv = B[i][i];
      for (int j = 0; j < width(); j++)
      {
        B[i][j] /= vv;
      }
      for (int j = i + 1; j < width(); j++)
      {
        T a = B[j][i];
        for (int k = 0; k < width(); k++)
        {
          B[j][k] -= B[i][k] * a;
        }
      }
    }
    return (ret);
  }
};

// https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
// を元にfunctionを使わないように改変
// https://noshi91.hatenablog.com/
template <typename Monoid>
struct SegmentTree
{
  using T = typename Monoid::T;

  int sz;
  vector<T> seg;
  const T id = Monoid::id();

  SegmentTree(int n)
  {
    sz = 1;
    while (sz < n)
      sz <<= 1;
    seg.assign(2 * sz, id);
  }

  void set(int k, const T &x)
  {
    seg[k + sz] = x;
  }

  void build()
  {
    for (int k = sz - 1; k > 0; k--)
    {
      seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const T &x)
  {
    k += sz;
    seg[k] = x;
    while (k >>= 1)
    {
      seg[k] = Monoid::op(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  T query(int a, int b)
  {
    T L = id, R = id;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)
    {
      if (a & 1)
        L = Monoid::op(L, seg[a++]);
      if (b & 1)
        R = Monoid::op(seg[--b], R);
    }
    return Monoid::op(L, R);
  }

  T operator[](const int &k) const
  {
    return seg[k + sz];
  }

  template <typename C>
  int find_subtree(int a, const C &check, T &M, bool type)
  {
    while (a < sz)
    {
      T nxt = type ? Monoid::op(seg[2 * a + type], M) : Monoid::op(M, seg[2 * a + type]);
      if (check(nxt))
        a = 2 * a + type;
      else
        M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }

  template <typename C>
  int find_first(int a, const C &check)
  {
    T L = id;
    if (a <= 0)
    {
      if (check(f(L, seg[1])))
        return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)
    {
      if (a & 1)
      {
        T nxt = Monoid::op(L, seg[a]);
        if (check(nxt))
          return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  template <typename C>
  int find_last(int b, const C &check)
  {
    T R = id;
    if (b >= sz)
    {
      if (check(f(seg[1], R)))
        return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for (b += sz; a < b; a >>= 1, b >>= 1)
    {
      if (b & 1)
      {
        T nxt = Monoid::op(seg[--b], R);
        if (check(nxt))
          return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

struct monoid_matrix4_product
{
  using T = Matrix<ll>;
  static T op(T l, T r) { return r * l; }
  static T id()
  {
    int n = 4;
    Matrix<ll> m(n, n);
    for (int i = 0; i < n; i++)
    {
      m[i][i] = 1;
    }
    return m;
  };
};

struct monoid_matrix2_product
{
  using T = Matrix<ll>;
  static T op(T l, T r) { return r * l; }
  static T id()
  {
    int n = 2;
    Matrix<ll> m(n, n);
    for (int i = 0; i < n; i++)
    {
      m[i][i] = 1;
    }
    return m;
  };
};

int main()
{
  // 整数の入力
  ll N, H, W;
  cin >> H >> W >> N;
  ;
  vector<pair<ll, ll>> changes(N);
  set<ll> changing_indexes;
  for (int i = 0; i < N; i++)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    changes[i] = {a, b};
    changing_indexes.insert(b);
  }
  ll before = -1;
  ll zipped_index = -1;
  map<ll, pair<ll, ll>> map_data;
  for (auto index : changing_indexes)
  {
    if (index - before == 1)
    {
      zipped_index++;
      map_data[index] = {zipped_index, 1};
      before = index;
    }
    else
    {
      zipped_index++;
      map_data[before + 1] = {zipped_index, index - before - 1};
      zipped_index++;
      map_data[index] = {zipped_index, 1};
      before = index;
    }
  }
  if (W - before - 1> 0){
    zipped_index++;
    map_data[before+1] = {zipped_index, W - before - 1};
  }
  if (H == 1)
  {
    SegmentTree<monoid_matrix2_product> seg(map_data.size());
    vector<bool> current_status(map_data.size(), false);
    for (auto p : map_data)
    {
      Matrix<ll> m(2);
      m[0][0] = 1;
      m[0][1] = 1;
      m[1][0] = 1;
      seg.set(p.second.first, m ^ (p.second.second));
    }
    seg.build();
    for (int i = 0; i < N; i++)
    {
      ll index = changes[i].second;
      ll zipped_i = map_data[index].first;
      current_status[zipped_i] = current_status[zipped_i] ^ true;
      if (current_status[zipped_i])
      {
        Matrix<ll> m(2);
        m[1][0] = 1;
        m[1][1] = 1;
        seg.update(zipped_i, m);
      }
      else
      {
        Matrix<ll> m(2);
        m[0][0] = 1;
        m[0][1] = 1;
        m[1][0] = 1;
        seg.update(zipped_i, m);
      }
      Matrix<ll> ans_m = seg.query(0, map_data.size());

      cout << (ans_m[0][1] + ans_m[1][1]) % BASE_NUM << endl;
    }
  }
  else
  {
    SegmentTree<monoid_matrix4_product> seg(map_data.size());
    vector<vector<bool>> current_status(map_data.size(), vector<bool>(2, false));
    for (auto p : map_data)
    {
      Matrix<ll> m(4);
      m.A = {
          {1, 1, 1, 1},
          {1, 0, 1, 0},
          {1, 1, 0, 0},
          {2, 1, 1, 1}};
      seg.set(p.second.first, m ^ (p.second.second));
    }
    seg.build();
    // cout << map_data.size() << endl;
    for (int i = 0; i < N; i++)
    {
      ll index = changes[i].second;
      ll zipped_i = map_data[index].first;
      current_status[zipped_i][changes[i].first] = current_status[zipped_i][changes[i].first] ^ true;
      // cout << zipped_i << endl;
      if (current_status[zipped_i] == vector<bool>({false, false}))
      {
        // cout << "a";
        Matrix<ll> m(4);
        m.A = {
            {1, 1, 1, 1},
            {1, 0, 1, 0},
            {1, 1, 0, 0},
            {2, 1, 1, 1}};
        seg.update(zipped_i, m);
      }
      else if (current_status[zipped_i] == vector<bool>({true, false}))
      {
        // cout << "b";
        Matrix<ll> m(4);
        m.A = {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {1, 0, 1, 0}};
        seg.update(zipped_i, m);
      }
      else if (current_status[zipped_i] == vector<bool>({false, true}))
      {
        // cout << "c";
        Matrix<ll> m(4);
        m.A = {
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0},
            {1, 1, 0, 0}};
        seg.update(zipped_i, m);
      }
      else if (current_status[zipped_i] == vector<bool>({true, true}))
      {
        // cout << "d";
        Matrix<ll> m(4);
        m.A = {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {1, 1, 1, 1}};
        seg.update(zipped_i, m);
      }
      Matrix<ll> ans_m = seg.query(0, map_data.size());

      cout << (ans_m[0][3] + ans_m[1][3] + ans_m[2][3] + ans_m[3][3]) % BASE_NUM << endl;
    }
  }
  return 0;
}