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
  ll n;
  scanf("%lld",&n);
  vector<string> G(n);
  for(int i = 0;i < n;i++){
    cin >> G[i];
  }
  vector<vector<ll>> ans(n);
  for(int i = 0;i < n;i++){
    ans[i].push_back(i);
  }
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if (G[i][j] == '1'){
        ans[j].push_back(i);
      }
    }
  }
  for(int i = 0;i < n;i++){
    sort(ans[i].begin(),ans[i].end());
    cout << ans[i].size();
    for(int j = 0;j < ans[i].size();j++){
      cout << " " << ans[i][j]+1;
    }
    cout  << "\n";
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
