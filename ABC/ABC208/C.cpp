#define _USE_MATH_DEFINES
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
namespace mp = boost::multiprecision;

template <typename T>
struct Compress
{
  vector<T> xs;

  Compress() = default;

  Compress(const vector<T> &vs)
  {
    add(vs);
  }

  Compress(const initializer_list<vector<T>> &vs)
  {
    for (auto &p : vs)
      add(p);
  }

  void add(const vector<T> &vs)
  {
    copy(begin(vs), end(vs), back_inserter(xs));
  }

  void add(const T &x)
  {
    xs.emplace_back(x);
  }

  void build()
  {
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
  }

  vector<int> get(const vector<T> &vs) const
  {
    vector<int> ret;
    transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x)
              { return lower_bound(begin(xs), end(xs), x) - begin(xs); });
    return ret;
  }

  int get(const T &x) const
  {
    return lower_bound(begin(xs), end(xs), x) - begin(xs);
  }

  size_t size() const
  {
    return xs.size();
  }
  const T &operator[](int k) const
  {
    return xs[k];
  }
};

int main()
{
  ll N, K;
  cin >> N >> K;
  Compress<ll> compress;
  vector<ll> a(N);
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
    compress.add(a[i]);
  }
  compress.build();
  for (int i = 0; i < N; i++)
  {
    if (compress.get(a[i]) < K % N)
    {
      cout << K / N + 1 << endl;
    }
    else
    {
      cout << K / N << endl;
    }
  }
  return 0;
}