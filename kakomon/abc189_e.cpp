#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <list>
#include <stack>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 2;

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
    // 整数の入力
    ll N,M,Q;
    cin >> N;
    vector<pair<ll,ll>> p(N);

    for (size_t i = 0; i < N; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    cin >> M;
    vector<pair<ll,ll>> o(M);
    for (size_t i = 0; i < M; i++)
    {
        cin >> o[i].first;
        if (o[i].first == 1){
            o[i].second = -1;
        }else if(o[i].first == 2){
            o[i].second = -1;
        }else if(o[i].first == 3){
            cin >> o[i].second;
        }else if(o[i].first == 4){
            cin >> o[i].second;

        }
    }
    cin >> Q;
    vector<pair<ll,ll>> Query(Q);
    for (size_t i = 0; i < Q; i++)
    {
        cin >> Query[i].first >> Query[i].second;
        Query[i].second--;
    }
    map<pair<ll,ll>,pair<ll,ll>> results;
    auto sorted_query(Query);
    sort(sorted_query.begin(),sorted_query.end());
    // (a b \\ c d) x + (e \\ f)
    Matrix<ll> A = Matrix<ll>::I(2);
    Matrix<ll> b = Matrix<ll>(2,1);
    ll current = 0;
    for(int i = 0;i < Q;i++){
        while(current < sorted_query[i].first){
            if (o[current].first == 1){
                Matrix<ll> multiply(2);
                Matrix<ll> add(2,1);
                multiply[0][1] = 1;
                multiply[1][0] = -1;
                A = multiply*A;
                b = multiply*b + add;
            }else if (o[current].first == 2){
                Matrix<ll> multiply(2);
                Matrix<ll> add(2,1);
                multiply[0][1] = -1;
                multiply[1][0] = 1;
                A = multiply*A;
                b = multiply*b + add;
            }else if(o[current].first == 3){
                Matrix<ll> multiply(2);
                Matrix<ll> add(2,1);
                multiply[0][0] = -1;
                multiply[1][1] = 1;
                add[0][0] = 2*o[current].second;
                A = multiply*A;
                b = multiply*b + add;
            }else{
                Matrix<ll> multiply(2);
                Matrix<ll> add(2,1);
                multiply[0][0] = 1;
                multiply[1][1] = -1;
                add[1][0] = 2*o[current].second;
                A = multiply*A;
                b = multiply*b + add;
            }
            // cout << "A" << endl;
            // cout << A;
            // cout << "b" << endl;
            // cout << b;
            current++;
        }
        Matrix<ll> point(2,1);
        point[0][0] = p[sorted_query[i].second].first;
        point[1][0] = p[sorted_query[i].second].second;
        Matrix<ll> moved = A*point + b;
        results[sorted_query[i]] = {moved[0][0],moved[1][0]};
    }
    for (size_t i = 0; i < Q; i++)
    {
        cout << results[Query[i]].first << " " << results[Query[i]].second << endl;
    }
    return 0;
}