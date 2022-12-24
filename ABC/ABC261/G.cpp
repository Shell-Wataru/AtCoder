#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
#include <bitset>
using namespace std;
using ll = long long;

ll solve()
{
  size_t N;
  cin >> N;
  vector<bitset<3000>> G(N);
  for(int i = 0;i < N;i++){
    string S;
    cin >> S;
    reverse(S.begin(),S.end());
    G[i] = bitset<3000>(S);
  }
  ll ans = 0;
  for(int i = 0;i < N;i++){
    for(int j = i+1;j < N;j++){
      if (G[i][j]){
        // cout << i << "," << j << endl;
        // cout << (G[i] & G[j]) << endl;
        ans += (G[i] & G[j]).count();
      }
    }
  }
  // cout << ans << endl;
  cout << ans/3 << endl;
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 1; i <= N;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
