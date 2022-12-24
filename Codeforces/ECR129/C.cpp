#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
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
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  Compress<ll> ca,cb;
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
    ca.add(a[i]);
  }
  for(int i = 0;i < n;i++){
    scanf("%lld",&b[i]);
    cb.add(b[i]);
  }
  ca.build();
  cb.build();
  for(int i = 0;i < n;i++){
    a[i] = ca.get(a[i]);
    b[i] = cb.get(b[i]);
  }
  vector<pair<ll,ll>> swaps;
  for(int i = 0;i < n;i++){
    ll min_index = -1;
    ll min_value = numeric_limits<ll>::max();
    for(int j = i;j < n;j++){
      if (a[j] < min_value){
        min_value = a[j];
        min_index = j;
      }
    }
    if (min_index != i){
      swaps.push_back({i,min_index});
      swap(a[i],a[min_index]);
      swap(b[i],b[min_index]);
    }
  }
  for(int i = 0;i < n;i++){
    ll min_index = -1;
    ll min_value = numeric_limits<ll>::max();
    for(int j = i;j < n;j++){
      if (a[i] == a[j] && b[j] < min_value){
        min_value = b[j];
        min_index = j;
      }
    }
    if (min_index != i){
      swaps.push_back({i,min_index});
      swap(a[i],a[min_index]);
      swap(b[i],b[min_index]);
    }
  }
  for(int i = 0;i < n-1;i++){
    if (b[i] > b[i+1]){
      cout << -1 << "\n";
      return 0;
    }
  }
  cout << swaps.size() << "\n";
  for(auto s:swaps){
    cout << s.first + 1<< " " << s.second + 1<< "\n";
  }
  return 0;
}
int main()
{
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
