#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
  ll A,B,n;
  cin >> A >> B >> n;
  ll max_enemy_attack = 0;
  ll enemy_total_attack = 0;
  vector<ll> attacks(n);
  vector<ll> blocks(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&attacks[i]);
  }
  for(int i = 0;i < n;i++){
    scanf("%lld",&blocks[i]);
  }

  for(int i = 0;i < n;i++){
    ll a = attacks[i];
    ll b = blocks[i];
    max_enemy_attack = max(max_enemy_attack,a);
    enemy_total_attack += a * ((b + A - 1)/A);
  }

  if (enemy_total_attack - max_enemy_attack < B){
    cout << "YES" << "\n";
  }else{
    cout << "NO" << "\n";
  }
  return 0;
}
int main()
{
  ll t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}