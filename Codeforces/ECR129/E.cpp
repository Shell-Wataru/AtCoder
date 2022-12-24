#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>
using namespace std;
using ll = long long;


ll distance_same_layer(ll x1,ll y1,ll x2,ll y2){
  ll layer = max(x1,y1);
  if (x1 == x2){
    return abs(y1- y2);
  }else if (y1 == y2){
    return abs(x1- x2);
  }else{
    return abs(layer - x1) + abs(layer - y1) + abs(layer - x2) + abs(layer - y2);
  }
}

struct SqrtDecomposition
{
  int N, B, K;
  vector<vector<ll>> data;
  vector<vector<ll>> block;

  SqrtDecomposition(int N) : N(N)
  { // 区間のlow以上の和を求める
    B = (int)sqrt(N);
    K = (N + B - 1) / B;
    block.assign(K, vector<ll>(4));
    data.assign(N,vector<ll>(4));
  }

  void set(int k, vector<ll> &x)
  {
    data[k] = x;
  }

  void build()
  {
    for (int k = 0; k < K; k++)
    {
      vector<ll> d(4,0);
      ll top_x = data[k*B][0];
      ll top_y = data[k*B][1];
      ll side_x = data[k*B][2];
      ll side_y = data[k*B][3];
      d[1] = k * B - top_y + k*B- side_x;
      d[2] = k * B - top_y + k*B- side_x;
      for (int i = k * B; i < min((k + 1) * B, N); i++)
      {
        ll next_top_x = data[i+1][0];
        ll next_top_y = data[i+1][1];
        ll next_side_x = data[i+1][2];
        ll next_side_y = data[i+1][3];
        vector<ll> next_d(4,numeric_limits<ll>::max());
        next_d[0] = min(next_d[0],d[0] + abs(next_top_y - top_y) + 1);
        next_d[2] = min(next_d[2],d[2] + abs(next_top_y - top_y) + 1);
        next_d[1] = min(next_d[3],d[1] + abs(next_side_x - top_x) + 1);
        next_d[3] = min(next_d[3],d[3] + abs(next_side_x - top_x) + 1);

        next_d[0] = min(next_d[0],next_d[1] + i - next_top_y + i- next_side_x);
        next_d[1] = min(next_d[1],next_d[0] + i - next_top_y + i- next_side_x);
        next_d[2] = min(next_d[2],next_d[3] + i - next_top_y + i- next_side_x);
        next_d[3] = min(next_d[3],next_d[2] + i - next_top_y + i- next_side_x);

        d = next_d;
        top_x = next_top_x;
        top_y = next_top_y;
        side_x = next_side_x;
        side_y = next_side_y;
      }
      block[k] = d;
    }
  }

  vector<ll> query(int a, int b) {
    vector<ll> d(4,0);
    ll top_x = data[a][0];
    ll top_y = data[a][1];
    ll side_x = data[a][2];
    ll side_y = data[a][3];
    d[1] = a - top_y + a- side_x;
    d[2] = a - top_y + a- side_x;

    for(int k = K - 1; k >=0; k--) {
      int l = k * B;
      int r = min(l + B, N);

      if(r <= a || b <= l) {

      } else if(a <= l && r <= b) {
          ll next_top_x = data[b][0];
          ll next_top_y = data[b][1];
          ll next_side_x = data[b][2];
          ll next_side_y = data[b][3];
          vector<ll> next_d(4,numeric_limits<ll>::max());
          next_d[0] = min(next_d[0],d[0] + block[k][0]);
          next_d[0] = min(next_d[0],d[1] + block[k][2]);
          next_d[1] = min(next_d[1],d[1] + block[k][3]);
          next_d[1] = min(next_d[1],d[0] + block[k][1]);
          next_d[2] = min(next_d[2],d[2] + block[k][0]);
          next_d[2] = min(next_d[2],d[3] + block[k][2]);
          next_d[3] = min(next_d[3],d[3] + block[k][3]);
          next_d[3] = min(next_d[3],d[2] + block[k][1]);
          d = next_d;
          top_x = next_top_x;
          top_y = next_top_y;
          side_x = next_side_x;
          side_y = next_side_y;
      } else {
        for(int i = max(a, l); i < min(b, r) ;i++) {
          ll next_top_x = data[i+1][0];
          ll next_top_y = data[i+1][1];
          ll next_side_x = data[i+1][2];
          ll next_side_y = data[i+1][3];
          vector<ll> next_d(4,numeric_limits<ll>::max());
          next_d[0] = min(next_d[0],d[0] + abs(next_top_y - top_y) + 1);
          next_d[2] = min(next_d[2],d[2] + abs(next_top_y - top_y) + 1);
          next_d[1] = min(next_d[3],d[1] + abs(next_side_x - top_x) + 1);
          next_d[3] = min(next_d[3],d[3] + abs(next_side_x - top_x) + 1);

          next_d[0] = min(next_d[0],next_d[1] + i - next_top_y + i- next_side_x);
          next_d[1] = min(next_d[1],next_d[0] + i - next_top_y + i- next_side_x);
          next_d[2] = min(next_d[2],next_d[3] + i - next_top_y + i- next_side_x);
          next_d[3] = min(next_d[3],next_d[2] + i - next_top_y + i- next_side_x);

          d = next_d;
          top_x = next_top_x;
          top_y = next_top_y;
          side_x = next_side_x;
          side_y = next_side_y;
        }
      }
    }
    return d;
  }
};

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<vector<ll>> doors(n-1,vector<ll>(4));
  for(int i = 0;i < n-1;i++){
    scanf("%lld",&doors[i][0]);
    scanf("%lld",&doors[i][1]);
    scanf("%lld",&doors[i][2]);
    scanf("%lld",&doors[i][3]);
    doors[i][0]--;
    doors[i][1]--;
    doors[i][2]--;
    doors[i][3]--;
  }
  SqrtDecomposition sq_dec(n-1);
  for(int i = 0;i < n;i++){
    sq_dec.set(i,doors[i]);
  }
  sq_dec.build();
  ll m;
  scanf("%lld",&m);
  for(int i = 0;i < m;i++){
    ll x1,y1,x2,y2;
    scanf("%lld",&x1);
    scanf("%lld",&y1);
    scanf("%lld",&x2);
    scanf("%lld",&y2);
    x1--;
    y1--;
    x2--;
    y2--;
    ll layer1 = max(x1,y1);
    ll layer2 = max(x2,y2);
    if(layer1 > layer2){
      swap(layer1,layer2);
      swap(x1,x2);
      swap(y1,y2);
    }
    if (layer1 == layer2){
      cout << distance_same_layer(x1,y1,x2,y2) << "\n";
    }else{
      auto d = sq_dec.query(layer1,layer2);
      ll ans = numeric_limits<ll>::max();
      ans = min(ans,distance_same_layer(x1,y1,doors[layer1][0],doors[layer1][1]) + d[0] + distance_same_layer(x2,y2,doors[layer2][0],doors[layer2][1]));
      ans = min(ans,distance_same_layer(x1,y1,doors[layer1][0],doors[layer1][1]) + d[1] + distance_same_layer(x2,y2,doors[layer2][2],doors[layer2][3]));
      ans = min(ans,distance_same_layer(x1,y1,doors[layer1][2],doors[layer1][2]) + d[2] + distance_same_layer(x2,y2,doors[layer2][0],doors[layer2][1]));
      ans = min(ans,distance_same_layer(x1,y1,doors[layer1][2],doors[layer1][2]) + d[3] + distance_same_layer(x2,y2,doors[layer2][2],doors[layer2][3]));
      cout << ans << "\n";
    }
  }
  return 0;
}
int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}