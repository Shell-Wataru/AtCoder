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
ll BASE_NUM = 1000000007;

long long extGCD(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

long long combination(long long n, long long m)
{
    long long value = 1;
    m = min(m, n - m);
    for (long long i = 0; i < m; i++)
    {
        value = (value * (n - i)) % BASE_NUM;
    }

    for (long long i = 1; i <= m; i++)
    {
        long long x, y, reverse;
        extGCD(i, BASE_NUM, x, y);
        reverse = (x + ((abs(x / BASE_NUM) + 1) * BASE_NUM)) % BASE_NUM;
        value = (value * reverse) % BASE_NUM;
    }
    return value;
}

ll reverse(ll n,ll modulo){
    ll x,y;
    extGCD(n, modulo, x, y);
    return (x + ((abs(x / modulo) + 1) * modulo)) % modulo;
}

template< class T >
struct Matrix {
  vector< vector< T > > A;

  Matrix() {}

  Matrix(size_t n, size_t m) : A(n, vector< T >(m, 0)) {}

  Matrix(size_t n) : A(n, vector< T >(n, 0)) {};

  size_t height() const {
    return (A.size());
  }

  size_t width() const {
    if (height() == 0){
      return 0;
    }else{
      return (A[0].size());
    }
  }

  inline const vector< T > &operator[](int k) const {
    return (A.at(k));
  }

  inline vector< T > &operator[](int k) {
    return (A.at(k));
  }

  static Matrix I(size_t n) {
    Matrix mat(n);
    for(int i = 0; i < n; i++) mat[i][i] = 1;
    return (mat);
  }

  Matrix &operator+=(const Matrix &B) {
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        (*this)[i][j] += B[i][j];
    return (*this);
  }

  Matrix &operator-=(const Matrix &B) {
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        (*this)[i][j] -= B[i][j];
    return (*this);
  }

  Matrix &operator*=(const Matrix &B) {
    size_t n = height(), m = B.width(), p = width();
    assert(p == B.height());
    vector< vector< T > > C(n, vector< T >(m, 0));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        for(int k = 0; k < p; k++)
          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
    A.swap(C);
    return (*this);
  }

  Matrix &operator^=(long long k) {
    Matrix B = Matrix::I(height());
    while(k > 0) {
      if(k & 1) B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return (*this);
  }

  Matrix operator+(const Matrix &B) const {
    return (Matrix(*this) += B);
  }

  Matrix operator-(const Matrix &B) const {
    return (Matrix(*this) -= B);
  }

  Matrix operator*(const Matrix &B) const {
    return (Matrix(*this) *= B);
  }

  Matrix operator^(const long long k) const {
    return (Matrix(*this) ^= k);
  }

  friend ostream &operator<<(ostream &os, Matrix &p) {
    size_t n = p.height(), m = p.width();
    for(int i = 0; i < n; i++) {
      os << "[";
      for(int j = 0; j < m; j++) {
        os << p[i][j] << (j + 1 == m ? "]\n" : ",");
      }
    }
    return (os);
  }

  //　BASE_NUMでの行列式
  T determinant() {
    Matrix B(*this);
    assert(width() == height());
    T ret = 1;
    if (B.width() == 0){
      return ret;
    }
    for(int i=0;i< width();i++){
      for(int j = 0;j<height();j++){
        B[i][j] = (BASE_NUM + B[i][j]) % BASE_NUM;
      }
    }

    for(int i = 0; i < width(); i++) {
      int idx = -1;
      for(int j = i; j < width(); j++) {
        if(B[j][i] != 0) {
          idx = j;
          break;
        }
      }
      if(idx == -1) return (0);
      if(i != idx) {
        cout << "swap!!" << i << endl;
        ret = BASE_NUM - ret;
        swap(B[i], B[idx]);
      }
      ret = ret * B[i][i] % BASE_NUM;
      T vv = B[i][i];
      T reverse_vv = reverse(vv,BASE_NUM);
      for(int j = 0; j < width(); j++) {
        B[i][j] = B[i][j] * reverse_vv % BASE_NUM;
      }
      for(int j = i + 1; j < width(); j++) {
        T a = B[j][i];
        for(int k = 0; k < width(); k++) {
          B[j][k] = (BASE_NUM + B[j][k] - (B[i][k] * a % BASE_NUM)) % BASE_NUM;
        }
      }
    }

    return (ret);
  }
};

struct UnionFind
{
  vector<int> data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if (x == y)
      return (false);
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  bool same(int x, int y)
  {
    x = find(x), y = find(y);
    return x == y;
  }

  int find(int k)
  {
    if (data[k] < 0)
      return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k)
  {
    return (-data[find(k)]);
  }
};

ll connected_graph_patterns(ll n, vector<pair<ll, ll>> &edges)
{
  set<ll> unique_nodes;
  map<ll, ll> zipped_nodes;
  for (auto p : edges)
  {
    unique_nodes.insert(p.first);
    unique_nodes.insert(p.second);
  }

  ll node_number = 0;
  for (auto n : unique_nodes)
  {
    zipped_nodes[n] = node_number;
    node_number++;
  }

  Matrix<ll> G(n - 1);
  for (auto e : edges)
  {
    ll from = zipped_nodes[e.first];
    ll to = zipped_nodes[e.second];
    if (from == to){
      continue;
    }
    if (from < n - 1)
    {
      G[from][from]++;
    }

    if (to < n - 1)
    {
      G[to][to]++;
    }

    if (from < n - 1 && to < n - 1)
    {
      G[from][to]--;
      G[to][from]--;
    }
  }
  return G.determinant() + 0.9;
};

pair<ll,ll> patterns(UnionFind &uf, vector<pair<ll, ll>> &edges)
{
  set<ll> unique_nodes;
  map<ll, ll> zipped_nodes;
  map<ll, vector<pair<ll, ll>>> connected_graphs;

  for (auto p : edges)
  {
    unique_nodes.insert(uf.find(p.first));
    unique_nodes.insert(uf.find(p.second));
  }

  ll node_number = 0;
  UnionFind connected_data(unique_nodes.size());
  for (auto n : unique_nodes)
  {
    zipped_nodes[n] = node_number;
    node_number++;
  }

  for (auto p : edges)
  {
    ll from = zipped_nodes[uf.find(p.first)];
    ll to = zipped_nodes[uf.find(p.second)];
    connected_data.unite(from, to);
  }

  for (auto p : edges)
  {
    ll from = zipped_nodes[uf.find(p.first)];
    ll to = zipped_nodes[uf.find(p.second)];
    ll group = connected_data.find(from);
    connected_graphs[group].push_back({from, to});
  }

  ll count = 1;
  for (auto g : connected_graphs)
  {
    ll spined_tree_patterns =connected_graph_patterns(connected_data.size(g.first), g.second);
    count = count * spined_tree_patterns % BASE_NUM;
  }

  for (auto p : edges)
  {
    uf.unite(p.first, p.second);
  }

  return {unique_nodes.size() - connected_graphs.size() ,count};
}

int main()
{
  // 整数の入力
  ll N, M;
  cin >> N >> M;
  UnionFind uf(N);

  map<ll, vector<pair<ll, ll>>> each_edges;
  for (int i = 0; i < M; i++)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    each_edges[c].push_back({a, b});
  }

  ll count = 1;
  ll money = 0;
  for (auto &edges : each_edges)
  {
    // cout << "!!" << edges.first << endl;
    pair<ll,ll> used_edges_and_count = patterns(uf, edges.second);
    // cout << used_edges_and_count.first << endl;
    count = count * used_edges_and_count.second % BASE_NUM;
    money += edges.first * used_edges_and_count.first;
  }
  cout << money << " " << count << endl;
  return 0;
}