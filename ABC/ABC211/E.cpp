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
using namespace std;
using ll = long long;

//https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
using ll = long long;

struct UnionFind
{
  vector<int> data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if (x == y)
      return (false);
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  bool same(int x, int y)
  {
    x = find(x), y = find(y);
    return x == y;
  }
  int find(int k)
  {
    if (data[k] < 0)
      return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k)
  {
    return (-data[find(k)]);
  }
};

set<vector<vector<ll>>> all_patterns(ll K)
{
  set<vector<vector<ll>>> ans;
  for (int h = 1; h <= K; h++)
  {
    ll w = K + 1 - h;
    vector<ll> pattern(h * w, 0);
    // cout << "h" << h << "w" << w << endl;
    fill(pattern.begin(), pattern.begin() + K, 1ll);
    // cout << "!!" << endl;
    sort(pattern.begin(), pattern.end());
    do
    {
      // for(auto p: pattern){
      //   cout << p;
      // }
      // cout << endl;
      UnionFind uf(h * w);
      for (int j = 0; j < h; j++)
      {
        for (int k = 0; k < w - 1; k++)
        {
          if (pattern[w * j + k] == 1 && pattern[w * j + (k + 1)] == 1)
          {
            uf.unite(w * j + k, w * j + k + 1);
          }
        }
      }
      for (int j = 0; j < h - 1; j++)
      {
        for (int k = 0; k < w; k++)
        {
          if (pattern[w * j + k] == 1 && pattern[w * (j + 1) + k] == 1)
          {
            uf.unite(w * j + k, w * (j + 1) + k);
          }
        }
      }
      ll min_row = numeric_limits<ll>::max();
      ll min_column = numeric_limits<ll>::max();
      ll max_row = numeric_limits<ll>::min();
      ll max_column = numeric_limits<ll>::min();
      bool united = false;
      for (ll j = 0; j < h; j++)
      {
        for (ll k = 0; k < w; k++)
        {
          if (pattern[w * j + k] == 1)
          {
            min_row = min(min_row, j);
            min_column = min(min_column, k);
            max_row = max(max_row, j);
            max_column = max(max_column, k);
          }
          if (uf.size(w * j + k) == K)
          {
            united = true;
          }
        }
      }
      if (united)
      {
        // cout << "found!!" << endl;
        // cout << max_row - min_row + 1 << endl;
        // cout << max_column - min_column + 1 << endl;
        vector<vector<ll>> result(max_row - min_row + 1, vector<ll>(max_column - min_column + 1, 0));
        // cout << "aa" << endl;
        for (int j = min_row; j <= max_row; j++)
        {
          for (int k = min_column; k <= max_column; k++)
          {
            result[j-min_row][k-min_column] = pattern[w * j + k];
          }
        }
        // cout << "before i" << endl;
        ans.insert(result);
        // cout << "inserted" << endl;
      }
    } while (next_permutation(pattern.begin(), pattern.end()));
  }
  // cout << "aa" << endl;
  return ans;
}
int main()
{
  ll N, K;
  cin >> N >> K;
  vector<string> G(N);
  for (int i = 0; i < N; i++)
  {
    cin >> G[i];
  }
  auto patterns = all_patterns(K);
  ll ans = 0;
  for(auto p:patterns){
    // cout << p.size() << "." << p[0].size() << endl;
    for(int i = 0;i + p.size() - 1 < N;i++){
      for(int j = 0;j + p[0].size() - 1<  N;j++){
        bool is_ok = true;
        for(int k = 0;k < p.size();k++){
          for(int l = 0;l < p[0].size();l++){
            if (p[k][l] == 1 && G[i+k][j+l] == '#'){
              is_ok = false;
              break;
            }
          }
        }
        if (is_ok){
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
