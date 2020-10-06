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
      {
        ll cij = 0;
        for (int k = 0; k < p; k++)
        {
          cij = (cij + (ll)(*this)[i][k] * B[k][j]) % BASE_NUM;
        }
        C[i][j] = cij;
      }
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

struct SqrtDecomposition
{
  int N, B, K;
  vector<int> data;
  vector<Matrix<int>> block;

  SqrtDecomposition(int N) : N(N)
  { // 区間のlow以上の和を求める
    B = (int)sqrt(N);
    K = (N + B - 1) / B;

    block.assign(K, Matrix<int>::I(10));
    data.assign(N, 0);
  }

  void set(int k, int &x)
  {
    data[k] = x;
  }

  void build()
  {
    for (int k = 0; k < K; k++)
    {
      Matrix<int> m = Matrix<int>::I(10);
      for (int i = k * B; i < min((k + 1) * B, N); i++)
      {
        Matrix<int> new_m(10);
        for (int j = 0; j < data[i]; j++)
        {
          for (int l = 0; l < 10; l++)
          {
            new_m[l][j] = (new_m[l][j] + m[l][0]) % BASE_NUM;
          }
        }

        for (int j = 1; j < 10; j++)
        {
          for (int l = 0; l < 10; l++)
          {
            new_m[l][j - 1] = (new_m[l][j - 1] + m[l][j]) % BASE_NUM;
          }
        }
        m = new_m;
      }
      // cout << m << endl;
      block[k] = m;
    }
  }

  vector<ll> query(int a, int b) {
    vector<ll> ret = {
      1,0,0,0,0,0,0,0,0,0
    };

    for(int k = K - 1; k >=0; k--) {
      int l = k * B;
      int r = min(l + B, N);

      if(r <= a || b <= l) {

      } else if(a <= l && r <= b) {
        vector<ll> new_ret(10);
        for(int i = 0;i < 10;i++){
          for(int j = 0; j < 10;j++){
            new_ret[i] =  (new_ret[i] + (block[k][i][j] * ret[j] % BASE_NUM)) % BASE_NUM;
          }
        }
        ret = new_ret;
      } else {
        for(int i = min(b, r) - 1; i >= max(a, l); i--) {
            ll new_val = 0;
            for(int j = 0;j < data[i];j++){
              new_val = (new_val + ret[j]) % BASE_NUM;
            }
            ret.pop_back();
            ret.insert(ret.begin(),new_val);
        }
      }
    }
    return ret;
  }

};

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  SqrtDecomposition sqrt_dec(N);
  for (int i = 0; i < N; i++)
  {
    int h;
    scanf("%d", &h);
    sqrt_dec.set(i,h);;
  }
  sqrt_dec.build();
  ll D;
  cin >> D;
  for (int i = 0; i < D; i++)
  {
    ll s, t;
    cin >> s >> t;
    s--;
    t--;
    auto m = sqrt_dec.query(s, t);
    // for(int j = 0;j < 10;j++){
    //   cout << m[j] << ",";
    // }
    // cout << endl;
    cout << m[0] << "\n";
  }
  cout << flush;

  return 0;
}