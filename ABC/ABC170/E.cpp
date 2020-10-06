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
ll BASE_NUM = 2000000007;

struct SqrtDecomposition
{
  int N, B, K;
  vector<map<ll, ll>> data;
  vector<ll> block;

  SqrtDecomposition(int N) : N(N)
  { // 区間のlow以上の和を求める
    B = (int)sqrt(N);
    K = (N + B - 1) / B;

    block.assign(K, 0);
    data.assign(N, map<ll, ll>());
  }

  void set(int k)
  {
    ll block_index = k / B;
    ll min_rate = BASE_NUM;
    for (int i = block_index * B; i < min((block_index + 1) * B, (ll)N); i++)
    {
      if (data[i].size() > 0)
      {
        auto last = data[i].end();
        last--;
        min_rate = min(min_rate, (*last).first);
      }
    }
    block[block_index] = min_rate;
  }

  void set(int k, map<ll, ll> &x)
  {
    data[k] = x;
    set(k);
  }

  void build()
  {
    for (int k = 0; k < K; k++)
    {
      ll min_rate = BASE_NUM;
      for (int i = k * B; i < min((k + 1) * B, N); i++)
      {
        if (data[i].size() > 0)
        {
          auto last = data[i].end();
          last--;
          min_rate = min(min_rate, (*last).first);
        }
      }
      block[k] = min_rate;
    }
  }

  ll query(int a, int b)
  {
    ll min_rate = BASE_NUM;
    for (int k = K - 1; k >= 0; k--)
    {
      int l = k * B;
      int r = min(l + B, N);

      if (r <= a || b <= l)
      {
      }
      else if (a <= l && r <= b)
      {
        min_rate = min(min_rate, block[k]);
      }
      else
      {
        ll sub_min_rate = BASE_NUM;
        for (int i = min(b, r) - 1; i >= max(a, l); i--)
        {
          if (data[i].size() > 0)
          {
            auto last = data[i].end();
            last--;
            sub_min_rate = min(sub_min_rate, (*last).first);
          }
        }
        min_rate = min(min_rate, sub_min_rate);
      }
    }
    return min_rate;
  }
};

int main()
{
  // 整数の入力
  ll N, Q;
  cin >> N >> Q;
  vector<pair<ll, ll>> shozoku_and_rate(N);
  SqrtDecomposition sqDec(200000);
  for (int i = 0; i < N; i++)
  {
    ll a, b;
    scanf("%lld", &a);
    scanf("%lld", &b);
    b--;
    shozoku_and_rate[i] = {a, b};
    sqDec.data[b][a]++;
  }
  // cout << "aa" << endl;
  sqDec.build();
  // for(int i = 0; i< N;i++){
  //   // cout << sqDec.data[i].size() << " ";
  //   // auto iter = sqDec.data[i].end();
  //   // iter--;
  //   // cout << (*iter).first << endl;
  //   for(auto p:sqDec.data[i]){
  //     cout << p.first << ",";
  //   }
  //   cout << endl;
  // }
  // cout << sqDec.query(0,N) << endl;
  // for(auto v:sqDec.block){
  //   cout << v << ",";
  // }
  // cout << endl;
  for (int i = 0; i < Q; i++)
  {
    ll c, d;
    scanf("%lld", &c);
    scanf("%lld", &d);
    c--;
    d--;
    sqDec.data[shozoku_and_rate[c].second][shozoku_and_rate[c].first]--;
    if (sqDec.data[shozoku_and_rate[c].second][shozoku_and_rate[c].first] == 0)
    {
      sqDec.data[shozoku_and_rate[c].second].erase(shozoku_and_rate[c].first);
    }
    sqDec.data[d][shozoku_and_rate[c].first]++;
    sqDec.set(shozoku_and_rate[c].second);
    sqDec.set(d);
    shozoku_and_rate[c].second = d;
    cout << sqDec.query(0, 200000) << "\n";
    // for(auto v:sqDec.block){
    //   cout << v << ",";
    // }
    // cout << endl;
    //   for(int j = 0; j< N;j++){
    //     for(auto p:sqDec.data[j]){
    //       cout << p.first << ",";
    //     }
    //     cout << endl;
    //   }
    //  cout << endl;
  }
  cout << flush;
  return 0;
}
