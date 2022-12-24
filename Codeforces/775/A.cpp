#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
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
  ll n,m;
  scanf("%lld", &n);
  scanf("%lld", &m);
  vector<vector<ll>> Colors(n,vector<ll>(m,0));
  Compress<ll> C;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      scanf("%lld",&Colors[i][j]);
      C.add(Colors[i][j]);
    }
  }
  C.build();
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      Colors[i][j] = C.get(Colors[i][j]);
    }
  }
  vector<vector<ll>> color_count_last_occur_row(C.size(),{0,0,0});
  vector<vector<ll>> color_count_last_occur_column(C.size(),{0,0,0});
  ll ans = 0;
  for(int i = 0;i < n;i++){
    set<ll> moved;
    for(int j = 0;j < m;j++){
      moved.insert(Colors[i][j]);
      ans += color_count_last_occur_row[Colors[i][j]][0] * (i - color_count_last_occur_row[Colors[i][j]][1]) + color_count_last_occur_row[Colors[i][j]][2];
    }
    for(auto c:moved){
      color_count_last_occur_row[c][2] += color_count_last_occur_row[c][0]*(i-color_count_last_occur_row[c][1]);
    }
    for(int j = 0;j < m;j++){
      color_count_last_occur_row[Colors[i][j]][0]++;
      color_count_last_occur_row[Colors[i][j]][1] = i;
    }
  }

  for(int j = 0;j < m;j++){
    set<ll> moved;
    for(int i = 0;i < n;i++){
      moved.insert(Colors[i][j]);
      ans += color_count_last_occur_column[Colors[i][j]][0] * (j - color_count_last_occur_column[Colors[i][j]][1]) + color_count_last_occur_column[Colors[i][j]][2];
    }
    for(auto c:moved){
      color_count_last_occur_column[c][2] += color_count_last_occur_column[c][0]*(j-color_count_last_occur_column[c][1]);
    }
    for(int i = 0;i < n;i++){
      color_count_last_occur_column[Colors[i][j]][0]++;
      color_count_last_occur_column[Colors[i][j]][1] = j;
    }
  }
  cout << ans;
  cout << "\n";
  return 0;
}

int main()
{
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}