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
#include <stack>

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

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<pair<ll,ll>> AB(N);
  Compress<ll> compress;
  for(int i = 0;i < N;i++){
    ll a,b;
    cin >> a >> b;
    a--;
    AB[i] = {a,a+b};
    compress.add(a);
    compress.add(a+b);
  }
  compress.add(0);
  compress.build();
  vector<ll> imos(compress.size(),0);
  for(int i = 0;i < N;i++){
    imos[compress.get(AB[i].first)]++;
    imos[compress.get(AB[i].second)]--;
  }
  for(int i = 0;i <compress.size()-1;i++){
    imos[i+1] += imos[i];
  }
  vector<ll> ans(N+1);
  for(int i = 0;i <compress.size()-1;i++){
    // cout << imos[i] << endl;
    ans[imos[i]] += compress[i+1] - compress[i];
  }
  for(int i = 1;i <= N;i++){
    if (i!= 1){
      cout << " ";
    }
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
