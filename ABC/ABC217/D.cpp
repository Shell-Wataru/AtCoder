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

struct UnionFind {
  vector< int > data;
  vector< int > width;

  UnionFind(int sz) {
    data.assign(sz, -1);
    width.assign(sz, 0);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    width[x] += width[y];
    data[y] = x;
    return (true);
  }

  bool same(int x, int y) {
    x = find(x), y = find(y);
    return x == y;
  }
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};

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
  ll l,Q;
  cin >> l >> Q;
  vector<pair<char,ll>> queries(Q);
  Compress<ll> compress;
  for(int i = 0;i < Q;i++){
    char c;
    ll x;
    cin >> c >> x;
    queries[i] = {c,x};
    compress.add(x);
  }
  compress.add(0);
  compress.build();
  ll L = compress.size();
  UnionFind uf(L);
  for(int i = 0;i < L;i++){
    if (i +1 < L){
      uf.width[i] = compress[i+1] - compress[i];
    }else{
      uf.width[i] = l - compress[i];
    }
  }
  vector<bool> cuts(L,false);
  for(int i = 0;i < Q;i++){
    char c = queries[i].first;
    ll x = compress.get(queries[i].second);
    if (c == '1'){
      cuts[x] = true;
    }
  }
  for(int i = 1;i < L;i++){
    if (!cuts[i]){
      uf.unite(i-1,i);
    }
  }
  reverse(queries.begin(),queries.end());
  vector<ll> answers;
  for(int i = 0;i < Q;i++){
    char c = queries[i].first;
    ll x = compress.get(queries[i].second);
    if (c == '1'){
      uf.unite(x-1,x);
    }else{
      answers.push_back(uf.width[uf.find(x)]);
    }
  }
  reverse(answers.begin(),answers.end());
  // cout << "!!" << endl;
  for(int i = 0;i < answers.size();i++){
    cout << answers[i] << "\n";
  }
  cout << flush;
  return 0;
}
