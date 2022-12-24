#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  cin >> n;
  ll base = 0;
  while(n-1 >= 1ll<<(base+1)){
    base++;
  }
  vector<ll> ans;
  for(int i = n-1;i>=1ll<<base;i--){
    ans.push_back(i);
  }
  for(int i =0;i<(1ll<<base);i++){
    ans.push_back(i);
  }
  for(int i = 0;i < n;i++){
    if (i!= 0){
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
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
  return 0;
}