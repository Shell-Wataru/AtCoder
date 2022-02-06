
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n,x,t;
  scanf("%lld",&n);
  vector<ll> ans(n);
  iota(ans.begin(),ans.end(),1);
  if (n % 2 == 0){
    for(int i = 0;i < n;i+=2){
      swap(ans[i],ans[i+1]);
    }
  }else{
    swap(ans[0],ans[1]);
    swap(ans[1],ans[2]);
    for(int i = 3;i < n;i+= 2){
      swap(ans[i],ans[i+1]);
    }
  }
  for(int i = 0;i < n;i++){
    if (i != 0){
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
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