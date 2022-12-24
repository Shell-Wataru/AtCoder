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
#include <set>
#include <atcoder/mincostflow>
using namespace std;
using ll = long long;
using namespace atcoder;

const long long BASE_NUM = 1000000007;
map<pair<ll,ll>,ll> cache;

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
    BIT<ll> bit(A.size());
    ll ans = 0;
    ll n = A.size();
    for (int i = 0; i < n; i++) {
        ans += i - bit.sum(A[i]);
        bit.add(A[i], 1);
    }
    return ans;
}

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


int solve()
{
  ll N;
  cin >> N;
  vector<ll> C(N);
  vector<ll> X(N);
  for(int i = 0;i < N;i++){
    cin >> C[i];
    C[i]--;
  }
  for(int i = 0;i < N;i++){
    cin >> X[i];
    X[i]--;
  }
  vector<vector<ll>> ColoredXs(N);
  for(int i = 0;i < N;i++){
    ColoredXs[C[i]].push_back(X[i]);
  }
  ll ans = inversion_number(X);
  // cout << ans << endl;
  for(int i = 0;i < N;i++){
    Compress<ll> CC;
    for(auto cx:ColoredXs[i]){
      CC.add(cx);
    }
    CC.build();
    vector<ll> x;
    for(auto cx:ColoredXs[i]){
      x.push_back(CC.get(cx));
    }
    // cout << i << ":" << inversion_number(x) << endl;
    // cout << x.size() << endl;
    ans -= inversion_number(x);
  }
  cout << ans << endl;
  return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
