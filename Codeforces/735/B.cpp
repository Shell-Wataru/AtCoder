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
const long long BASE_NUM = 1000000007;

int solve()
{
  ll h,w;
  scanf("%lld",&h);
  scanf("%lld",&w);
  vector<string> ans(h,string(w,'0'));
  for(int i = 0;i < h;i += 2){
    ans[i][0] = '1';
  }
  for(int i = 0;i < w;i += 2){
    ans[0][i] = '1';
  }
  for(int i = 2;i < h;i += 2){
    ans[i][w-1] = '1';
  }
  for(int i = 2;i < w;i += 2){
    ans[h-1][i] = '1';
  }
  if (ans[h-1][w-1] == '1' && ans[h-1][w-2] == '1'){
    ans[h-1][w-1] = '0';
  }else if(ans[h-1][w-1] == '1' && ans[h-2][w-1] == '1'){
    ans[h-1][w-1] = '0';
  }else if(ans[h-1][w-2] == '1' && ans[h-2][w-1] == '1'){
    ans[h-1][w-2] = '0';
  }
  for(int i = 0;i < h;i++){
    cout << ans[i] << "\n";
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