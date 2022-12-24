#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

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
        for (auto &p : vs)d
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
  ll n;
  scanf("%lld", &n);
  vector<ll> a(n);
  Compress<ll> C;
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
    C.add(a[i]);
  }
  C.build();
  ll N = C.size();
  vector<ll> counts(N,0);
  // cout << C.size() << endl;
  for(int i = 0;i < n;i++){
    counts[C.get(a[i])]++;
  }
  ll gte2_count = 0;
  for(int i = 0 ;i  < N;i++){
    if (counts[i] >= 2){
      gte2_count++;
    }
  }
  // cout << gte2_count << "," << N << endl;
  if (gte2_count == N){
    cout << N << "\n";
  }else{
    cout << gte2_count + 1 + (N-1-gte2_count)/2 << "\n";
  }
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
