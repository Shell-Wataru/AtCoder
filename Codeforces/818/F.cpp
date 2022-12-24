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

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> a(n);
  vector<ll> b(n);
  map<ll,ll> a_counts;
  for(int i = 0;i < n;i++){
    cin >> a[i];
    while(a[i] % 2 == 0){
      a[i]/= 2;
    }
    a_counts[a[i]]++;
  }
  for(int i = 0;i < n;i++){
    cin >> b[i];
  }
  for(int i = 0;i < n;i++){
    while(a_counts[b[i]] == 0 && b[i] != 1){
      b[i]/= 2;
    }
    if (a_counts[b[i]] > 0){
      a_counts[b[i]]--;
    }else{
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}
int main()
{
  // ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
  solve();
  }
  cout << flush;
  return 0;
}