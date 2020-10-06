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
ll BASE_NUM = 998244353;


int solve()
{
  ll n;
  cin >> n;
  vector<ll> ans;
  ans.push_back(1);
  n -= 1;
  while(n > 0){
    if (ans.back() * 2 <= n){
      ans.push_back(ans.back() * 2);
      n -= ans.back();
    }else{
      if (ans.back() < n){
        ans.push_back(n);
      }else{
        ll a= ans.back();
        ans.back() = (n+a)/2;
        ans.push_back((n+a+1)/2);
      }
      break;
    }
  }
  cout << ans.size() -1 << endl;
  for(int i = 1;i < ans.size();i++){
    if(i != 1){
      cout << " ";
    }
    cout << ans[i] - ans[i-1];
  }
  cout << "\n";
 return 0;
}

int main()
{
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}