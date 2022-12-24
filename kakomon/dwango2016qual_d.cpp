#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

struct UnionFind
{
  vector<int> data;
  vector<int> weights;
  vector<int> max_edge_weights;
  int bad_count = 0;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
    weights.assign(sz, -1);
    max_edge_weights.assign(sz, -1);
  }

  bool unite(int x, int y, int edge_weight)
  {
    x = find(x), y = find(y);
    if (x == y)
    {
      if (max_edge_weights[x] > weights[x])
      {
        bad_count--;
      }
      max_edge_weights[x] = max(max_edge_weights[x], edge_weight);
      if (max_edge_weights[x] > weights[x])
      {
        bad_count++;
      }
      return (false);
    }
    if (data[x] > data[y])
      swap(x, y);
    if (max_edge_weights[x] > weights[x])
    {
      bad_count--;
    }
    if (max_edge_weights[y] > weights[y])
    {
      bad_count--;
    }

    data[x] += data[y];
    weights[x] += weights[y];
    data[y] = x;
    weights[y] = 0;
    max_edge_weights[x] = max(max_edge_weights[x], edge_weight);
    max_edge_weights[x] = max(max_edge_weights[x], max_edge_weights[y]);
    if (max_edge_weights[x] > weights[x])
    {
      bad_count++;
    }
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
  int weight(int k)
  {
    return (weights[find(k)]);
  }
};

int solve()
{
  ll h, w;
  scanf("%lld", &h);
  scanf("%lld", &w);
  vector<vector<ll>> B(h, vector<ll>(w));
  vector<vector<ll>> cumSumB(h + 1, vector<ll>(w + 1));
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      scanf("%lld", &B[i][j]);
      cumSumB[i + 1][j + 1] = B[i][j];
    }
  }

  for (int i = 0; i <= h; i++)
  {
    for (int j = 1; j <= w; j++)
    {
      cumSumB[i][j] += cumSumB[i][j - 1];
    }
  }
  for (int i = 1; i <= h; i++)
  {
    for (int j = 0; j <= w; j++)
    {
      cumSumB[i][j] += cumSumB[i - 1][j];
    }
  }
  vector<vector<ll>> maxUL(h, vector<ll>(w, numeric_limits<ll>::min()));
  vector<vector<ll>> maxDR(h, vector<ll>(w, numeric_limits<ll>::min()));
  for (int i = 0; i < h; i++)
  {
    for (int j = i; j < h; j++)
    {
      ll current_total = 0;
      ll max_total = numeric_limits<ll>::min();
      for (int k = 0; k < w; k++)
      {
        current_total = max(current_total, 0ll) + cumSumB[j + 1][k + 1] - cumSumB[j + 1][k] - cumSumB[i][k+1] + cumSumB[i][k];
        max_total = max(max_total, current_total);
        maxUL[j][k] = max(maxUL[j][k], max_total);
      }
    }
  }

  for(int i = 1;i < h;i++){
    for(int j = 0;j < w;j++){
      maxUL[i][j] = max(maxUL[i][j],maxUL[i-1][j]);
    }
  }
  for(int i = 0;i < h;i++){
    for(int j = 1;j < w;j++){
      maxUL[i][j] = max(maxUL[i][j],maxUL[i][j-1]);
    }
  }

  for (int i = 0; i < h; i++)
  {
    for (int j = i; j < h; j++)
    {
      ll current_total = 0;
      ll max_total = numeric_limits<ll>::min();
      for (int k = w-1; k >= 0; k--)
      {
        current_total = max(current_total, 0ll) + cumSumB[j + 1][k + 1] - cumSumB[j + 1][k] - cumSumB[i][k+1] + cumSumB[i][k];
        max_total = max(max_total, current_total);
        maxDR[i][k] = max(maxDR[i][k], max_total);
      }
    }
  }

  for(int i = h-2;i >= 0;i--){
    for(int j = 0;j < w;j++){
      maxDR[i][j] = max(maxDR[i][j],maxDR[i+1][j]);
    }
  }
  for(int i = 0;i < h;i++){
    for(int j = w-2;j >= 0;j--){
      maxDR[i][j] = max(maxDR[i][j],maxDR[i][j+1]);
    }
  }

  // for(int i = 0;i < h;i++){
  //   for(int j = 0;j < w;j++){
  //     cout << maxUL[i][j] << ",";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  // for(int i = 0;i < h;i++){
  //   for(int j = 0;j < w;j++){
  //     cout << maxDR[i][j] << ",";
  //   }
  //   cout << endl;
  // }

  ll ans = numeric_limits<ll>::min();
  for(int i = 0;i < h-1;i++){
    for(int j = 0;j < w;j++){
      ans = max(ans,maxUL[i][j]+maxDR[i+1][0]);
    }
  }
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w-1;j++){
      ans = max(ans,maxUL[i][j]+maxDR[0][j+1]);
    }
  }
  cout << ans << endl;
  return 0;
}

int main()
{
  // // 整数の入力
  //   ll t;
  //   cin >> t;
  //   for (size_t i = 0; i < t; i++)
  //   {
  solve();
  //   }
  //   cout << flush;
  return 0;
}
