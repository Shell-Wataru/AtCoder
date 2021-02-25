#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll white_back = -1;
    ll black_back = -1;
    for(int i = 0;i < n;i++){
      scanf("%lld",&a[i]);
    }
    ll ans = 0;
    for(int i = 0;i < n;i++){
      bool add_to_white;
      if (white_back == a[i]){
        add_to_white = false;
      }else if (black_back == a[i]){
        add_to_white = true;
      }else if (i != n -1 && white_back == a[i+1]){
        add_to_white = true;
      }else if (i != n -1 && black_back == a[i+1]){
        add_to_white = false;
      }else{
        add_to_white = true;
      }
      if (add_to_white){
        if (white_back != a[i]){
          ans++;
        }
        white_back = a[i];
      }else{
        if (black_back != a[i]){
          ans++;
        }
        black_back = a[i];
      }
    }
    cout << ans << endl;
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
    // cout << flush;
    return 0;
}
