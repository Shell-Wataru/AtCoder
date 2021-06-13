#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

template< typename T >
struct Compress {
  vector< T > xs;

  Compress() = default;

  Compress(const vector< T > &vs) {
    add(vs);
  }

  Compress(const initializer_list< vector< T > > &vs) {
    for(auto &p : vs) add(p);
  }

  void add(const vector< T > &vs) {
    copy(begin(vs), end(vs), back_inserter(xs));
  }

  void add(const T &x) {
    xs.emplace_back(x);
  }

  void build() {
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
  }

  vector< int > get(const vector< T > &vs) const {
    vector< int > ret;
    transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x) {
      return lower_bound(begin(xs), end(xs), x) - begin(xs);
    });
    return ret;
  }

  int get(const T &x) const {
    return lower_bound(begin(xs), end(xs), x) - begin(xs);
  }

  const T &operator[](int k) const {
    return xs[k];
  }
};

int main()
{
    ll N, C;
    cin >> N >> C;
    vector<ll> a(N);
    vector<ll> b(N);
    vector<ll> c(N);
    Compress<ll> compress;
    for(int i = 0;i < N;i++){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        compress.add(a[i]);
        compress.add(b[i]);
    }
    compress.build();
    vector<ll> imos(compress.xs.size()+1);
    for(int i = 0;i < N;i++){
        imos[compress.get(a[i])] += c[i];
        imos[compress.get(b[i])] -= c[i];
    }
    for(int i = 0;i < imos.size()-1;i++){
        imos[i+1] +=  imos[i];
    }

    ll ans = 0;
    for(int i = 0;i < imos.size()-1;i++){
        ans+= min(C,imos[i])* (compress.xs[i+1] - compress.xs[i]);
    }
    cout << ans << endl;
    return 0;
}