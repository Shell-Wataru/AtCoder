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

namespace mp = boost::multiprecision;
using namespace std;

template<typename T> struct V : vector<T> { using vector<T>::vector; };
V() -> V<int>;
V(size_t) -> V<int>;
template<typename T> V(size_t, T) -> V<T>;
template<typename T> vector<T> make_vec(size_t n, T a) { return vector<T>(n, a); }
template<typename... Ts> auto make_vec(size_t n, Ts... ts) { return vector<decltype(make_vec(ts...))>(n, make_vec(ts...)); }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for (auto &e : v) os << e << ' '; return os; }
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;


using ll = long long;

const long long BASE_NUM = 1000000007;

//zero indexed and vector
template< typename T>
class BIT
{
public:
    vector<T> data;
    BIT(long long n) : data(n) {}
    void add(int index, T v)
    {
        int N = data.size();
        for (int i = index; i < N; i |= i + 1)
        {
            data[i] += v;
        }
    }

    long long sum(int index)
    {
        T retValue = 0;
        for (int i = index; i >= 0; i = (i & (i + 1)) - 1)
        {
            retValue += data[i];
        }
        return retValue;
    }

    void show(){
        for (auto v:data){
            cout << v << endl;
        }
    }
};

ll inversion_number(vector<ll> &A){
    BIT<ll> bit(A.size()*2);
    ll ans = 0;
    for (int i = 0; i < A.size(); i++) {
        ans += i - bit.sum(A[i]);
        bit.add(A[i], 1);
    }
    return ans;
}

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  for (size_t i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  for (size_t i = 0; i < N; i++)
  {
    cin >> B[i];
  }
  ll a_inverse_number = inversion_number(A);
  ll b_inverse_number = inversion_number(B);
  if ((a_inverse_number + b_inverse_number) % 2 == 0){

  }else{
    cout << -1 << endl;
  }
  return 0;
}