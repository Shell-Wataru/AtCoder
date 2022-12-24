#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
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
    ll N, L, Q;
    cin >> N;
    vector<ll> A(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cin >> L >> Q;
    Doubling d(N,numeric_limits<ll>::max());
    for(int i = 0;i < N;i++){
        auto iter_to = upper_bound(A.begin(),A.end(),A[i]+L);
        iter_to--;
        ll to = iter_to - A.begin();
        d.set_next(i,to);
    }
    d.build();
    for(int i = 0; i < Q;i++){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        if (a > b){
            swap(a,b);
        }
        ll l = 0;
        ll r = N;
        while(l + 1 < r){
            ll center = (l+r)/2;
            ll to = d.query(a,center);
            if (to >= b){
                r = center;
            }else{
                l = center;
            }
        }
        cout << r << "\n";
    }
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
