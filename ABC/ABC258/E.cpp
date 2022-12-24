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
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

struct Doubling
{
  const int LOG;
  vector< vector< int > > table;

  Doubling(int sz, int64_t lim_t) : LOG(64 - __builtin_clzll(lim_t))
  {
    table.assign(LOG, vector< int >(sz, -1));
  }

  void set_next(int k, int x)
  {
    table[0][k] = x;
  }

  void build()
  {
    for(int k = 0; k + 1 < LOG; k++) {
      for(int i = 0; i < table[k].size(); i++) {
        if(table[k][i] == -1) table[k + 1][i] = -1;
        else table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  int query(int k, int64_t t)
  {
    for(int i = LOG - 1; i >= 0; i--) {
      if((t >> i) & 1) k = table[i][k];
    }
    return k;
  }
};

int solve()
{
  ll N,Q,X;
  cin >> N >> Q >> X;
  Doubling doubling(N,numeric_limits<ll>::max());
  vector<ll> W(N);
  vector<ll> ruisekiWa(N+1,0);
  vector<ll> contents(N);
  for(int i = 0;i < N;i++){
    cin >> W[i];
    ruisekiWa[i+1] = ruisekiWa[i] + W[i];
  }
  for(int i = 0;i < N;i++){
    // cout << i << ":";
    ll remain = X % ruisekiWa[N];
    contents[i] += (X/ruisekiWa[N]) * N;
    ll to = lower_bound(ruisekiWa.begin(),ruisekiWa.end(),ruisekiWa[i] + remain) - ruisekiWa.begin();
    // cout << to << endl;
    contents[i] += to - i;
    to--;
    if (to == N){
      remain -= ruisekiWa[N] - ruisekiWa[i];
      to = lower_bound(ruisekiWa.begin(),ruisekiWa.end(),remain) - ruisekiWa.begin();
      contents[i] += to-1;
      // cout << to << endl;
      to--;
    }
    // cout << (to+1) % N << endl;
    doubling.set_next(i,(to+1)%N);
  }
  doubling.build();
  // for(int i = 0;i < N;i++){
  //   cout << i << ":" << contents[i] << endl;
  // }
  for(int i = 0;i < Q;i++){
    ll k;
    cin >> k;
    ll current = doubling.query(0,k-1);
    cout << contents[current] << endl;
  }
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 0;i < N;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
