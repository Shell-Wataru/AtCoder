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

int solve()
{
  ll n,m;
  scanf("%lld", &n);
  scanf("%lld", &m);
  map<ll,ll> first_arrival;
  map<ll,ll> last_arrival;
  vector<ll> u(n);
  for(int i = 0;i < n;i++){
    cin >> u[i];
    if (first_arrival.count(u[i]) == 0){
      first_arrival[u[i]] =  i;
    }
    last_arrival[u[i]] =  i;
  }
  for(int i = 0;i < m;i++){
    ll a,b;
    cin >> a >> b;
    if (first_arrival.count(a) == 1 && first_arrival.count(b) == 1 && first_arrival[a] <= last_arrival[b]){
      cout << "Yes\n";
    }else{
      cout << "No\n";
    }
  }
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
