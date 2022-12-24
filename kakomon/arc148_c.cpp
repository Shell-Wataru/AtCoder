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
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;

int main()
{
  ll N,Q;
  cin >> N >> Q;
  vector<vector<ll>> G(N);
  vector<ll> P(N,-1);
  for(int i = 0;i < N-1;i++){
    ll p;
    cin >> p;
    p--;
    G[p].push_back(i+1);
    P[i+1] = p;
  }
  for(int i = 0;i < Q;i++){
    ll M;
    cin >> M;
    unordered_set<ll> vs;
    // unordered_set<ll> used;
    ll ans = 0;
    for(int j = 0;j < M;j++){
      ll v;
      cin >> v;
      v--;
      vs.insert(v);
      ans += G[v].size()+1;
    }
    // cout << ans << endl;
    for(auto v:vs){
        if (vs.count(P[v])){
            // cout << "!" << endl;
            ans -= 2;
        }
    }
    cout << ans << "\n";
  }
  cout << flush;
  return 0;
}
