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
const long long BASE_NUM = 1000000007;

ll pair_counts(ll n,vector<ll> &indexes){
  ll m = indexes.size();
  vector<ll> ruisekiwa(m+1,0);
  for(int i = 0;i < m;i++){
    ruisekiwa[i+1] = ruisekiwa[i] + indexes[i];
  }
  ll i_total = 0;
  ll j_total = 0;
  ll ij_total = 0;
  for(int i = 0;i < m;i++){
    i_total += indexes[i] * (m - i - 1);
  }

  for(int i = m-1;i >= 0;i--){
    j_total += indexes[i] * i;
  }

  for(int i = 0;i < m;i++){
    ij_total += indexes[i] * (ruisekiwa[m] - ruisekiwa[i+1]);
  }

  return n*m*(m-1)/2 + n*i_total - j_total -ij_total;
}
int solve()
{
  int n;
  scanf("%d", &n);
  map<ll,vector<ll>> same_number_indexes;
  for(int i = 0;i < n;i++){
    ll a;
    scanf("%lld",&a);
    same_number_indexes[a].push_back(i);
  }
  ll ans = 0;
  for(auto &p:same_number_indexes){
    // cout << p.first << ":" << pair_counts(n,p.second) << endl;
    ans += pair_counts(n,p.second);
  }
  cout << ans << "\n";
  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
