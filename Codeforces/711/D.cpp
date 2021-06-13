#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <list>
using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
    int n,m;
    scanf("%d", &n);
    scanf("%d", &m);
    vector<vector<int>> DP(2,vector<int>(m+1,numeric_limits<int>::max()));
    DP[0][0] = 0;
    for(int i = 0;i < n;i++){
      ll current = i % 2;
      ll next = (i+1)%2;
      DP[next] = DP[current];
      ll t,x,y;
      scanf("%lld",&t);
      scanf("%lld",&x);
      scanf("%lld",&y);
      if (t == 1){
        ll plus = (x+ 100000-1)/100000;
        vector<ll> last_occur(plus,-1);
        for(int j = 0;j <= m;j++){
          if (DP[current][j] != numeric_limits<int>::max()){
            last_occur[j%plus] = j;
          }
          if (last_occur[j%plus] != -1 && (j - last_occur[j%plus])/plus <= y){
            DP[next][j] = min(i+1,DP[next][j]);
          }
        }
      }else{
        for(int j = m;j >= 1;j--){
          if (DP[current][j] == numeric_limits<int>::max()){
            continue;
          }
          ll current_k = j;
          for(int k = 1;k <= y;k++){
            current_k = (current_k * x + 100000 -1)/100000;
            if (current_k > m || DP[current][current_k] != numeric_limits<int>::max()){
              break;
            }
            DP[next][current_k] = min(i+1,DP[next][current_k]);
          }
        }
      }
    }
    for(int i = 1;i <= m;i++){
      if (i != 1){
        cout << " ";
      }
      if (DP[n%2][i] == numeric_limits<int>::max()){
        cout << -1;
      }else{
        cout << DP[n%2][i];
      }
    }
    cout << "\n";
    return 0;
}

int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    cout << flush;
    return 0;
}
