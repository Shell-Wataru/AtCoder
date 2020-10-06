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
ll BASE_NUM = 998244353;

int search(vector<ll> &R, vector<ll> &G, vector<ll> &B, int r_index, int g_index, int b_index, ll &min_diff, map<ll, map<ll, map<ll, ll>>> &memo)
{
  if (memo[r_index][g_index].find(b_index) != memo[r_index][g_index].end())
  {
    return 0;
  }
  ll rw = R[r_index];
  ll gw = G[g_index];
  ll bw = B[b_index];
  ll diff = (rw - gw) * (rw - gw) + (gw - bw) * (gw - bw) + (bw - rw) * (bw - rw);
  memo[r_index][g_index][b_index] = diff;
  min_diff = min(min_diff, diff);
  if (r_index + 1 < R.size()){
    if (R[r_index+1] <= gw && R[r_index+1] <= bw){
      search(R, G, B, r_index + 1, g_index, b_index, min_diff, memo);
      return 0;
    }
  }

  if (g_index + 1 < G.size()){
    if (G[g_index+1] <= rw && G[g_index+1] <= bw){
      search(R, G, B, r_index, g_index+1, b_index, min_diff, memo);
      return 0;
    }
  }

  if (b_index + 1 < B.size()){
    if (B[b_index+1] <= gw && B[b_index+1] <= rw){
      search(R, G, B, r_index, g_index, b_index+1, min_diff, memo);
      return 0;
    }
  }

  if ((rw <= gw || rw <= bw) && r_index + 1 < R.size())
  {
    search(R, G, B, r_index + 1, g_index, b_index, min_diff, memo);
  }
  if ((gw <= rw || gw <= bw) && g_index + 1 < G.size())
  {
    search(R, G, B, r_index, g_index + 1, b_index, min_diff, memo);
  }
  if ((bw <= gw || bw <= rw) && b_index + 1 < B.size())
  {
    search(R, G, B, r_index, g_index, b_index + 1, min_diff, memo);
  }
  return 0;
}

int solve()
{
  ll r, g, b;
  scanf("%lld%lld%lld", &r, &g, &b);
  vector<ll> R(r);
  vector<ll> G(g);
  vector<ll> B(b);
  for (int i = 0; i < r; i++)
  {
    scanf("%lld", &R[i]);
  }
  for (int i = 0; i < g; i++)
  {
    scanf("%lld", &G[i]);
  }
  for (int i = 0; i < b; i++)
  {
    scanf("%lld", &B[i]);
  }
  ll r_index = 0;
  ll g_index = 0;
  ll b_index = 0;
  bool changed = true;
  ll min_diff = numeric_limits<ll>::max();
  sort(R.begin(), R.end());
  sort(G.begin(), G.end());
  sort(B.begin(), B.end());
  map<ll, map<ll, map<ll, ll>>> memo;
  search(R,G,B,0,0,0,min_diff,memo);
  cout << min_diff << endl;
  return 0;
}

int main()
{
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}