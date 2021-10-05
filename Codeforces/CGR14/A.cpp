#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;

ll BASE_NUM = 1000000007;
int solve()
{
  ll n,x;
  cin >> n >> x;
  vector<ll> w(n);
  ll total = 0;
  for(int i =0 ;i < n;i++){
    scanf("%lld",&w[i]);
    total += w[i];
  }
  if (total == x){
    cout << "NO\n";
  }else{
    sort(w.begin(),w.end());
    ll current = 0;
    for (size_t i = 0; i < n-1; i++)
    {
      current += w[i];
      if (current == x){
        swap(w[i],w[i+1]);
        break;
      }
    }
    cout << "YES\n";
    for(int i = 0;i < n;i++){
      if (i != 0){
        cout << " ";
      }
      cout << w[i];
    }
    cout << "\n";
  }
  return 0;
}

int main()
{
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