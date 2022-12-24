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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

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
    // assert(n == B.height() && m == B.width());
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        (*this)[i][j] += B[i][j];
    return (*this);
  }

  Matrix &operator-=(const Matrix &B) {
    size_t n = height(), m = width();
    // assert(n == B.height() && m == B.width());
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        (*this)[i][j] -= B[i][j];
    return (*this);
  }

  Matrix &operator*=(const Matrix &B) {
    size_t n = height(), m = B.width(), p = width();
    // assert(p == B.height());
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


  T determinant() {
    Matrix B(*this);
    // assert(width() == height());
    T ret = 1;
    if (B.width() == 0){
      return ret;
    }
    for(int i = 0; i < width(); i++) {
      int idx = -1;
      for(int j = i; j < width(); j++) {
        if(B[j][i] != 0) idx = j;
      }
      if(idx == -1) return (0);
      if(i != idx) {
        ret *= -1;
        swap(B[i], B[idx]);
      }
      ret *= B[i][i];
      T vv = B[i][i];
      for(int j = 0; j < width(); j++) {
        B[i][j] /= vv;
      }
      for(int j = i + 1; j < width(); j++) {
        T a = B[j][i];
        for(int k = 0; k < width(); k++) {
          B[j][k] -= B[i][k] * a;
        }
      }
    }
    return (ret);
  }
};

int main()
{
    ll N, M;
    cin >> N >> M;
    ll L = N+M-1;
    if (N > M){
        swap(N,M);
    }
    if (N == 1 && M== 1){
        cout << 3 << endl;
    }else if (N == 1 && M== 2){
        cout << 6 << endl;
     }else if (N == 2 && M == 2){
        cout << 12 + 3 * 2 << endl;
    }else if (M == 3){
        ll L = N+M-1;
        vector<vector<ll>> DP(L+1,vector<ll>(10,0));
        DP[0][0] = 1;
        for(int i = 0;i < L;i++){
            DP[i+1][1] += DP[i][0];// 1
            DP[i+1][2] += DP[i][0] + DP[i][1] + DP[i][5];// 2
            DP[i+1][3] += DP[i][0] + DP[i][1] + DP[i][4];// 3
            DP[i+1][4] += DP[i][2] + DP[i][7];// 21
            DP[i+1][5] += DP[i][3] + DP[i][6];// 31
            DP[i+1][6] += DP[i][2];// 23
            DP[i+1][7] += DP[i][3];// 32
        }
        ll ans = 0;
        for(int i = 0;i < 10;i++){
            ans += DP[L][i];
        }
        if (N != 1){
            ans *=2;
        }
        cout << ans << endl;
    }else{
        ll L = N+M-1;
        Matrix<ll> M(10);
        M[1][0] = 1;
        M[2][0] = 1;
        M[2][1] = 1;
        M[3][0] = 1;
        M[3][1] = 1;
        M[3][4] = 1;
        M[4][2] = 1;
        M[4][8] = 1;
        M[5][3] = 1;
        M[5][6] = 1;
        M[6][2] = 1;
        M[7][3] = 1;
        M[8][5] = 1;
        M[9][7] = 1;
        auto mm = M^L;
        ll ans = 0;
        for(int i = 0;i < 10;i++){
            ans += mm[i][0];
        }
        if (N != 1){
            ans *=2;
        }
        cout << ans << endl;
    }
    return 0;
}
