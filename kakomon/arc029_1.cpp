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
    ll N;
    cin >> N;
    vector<ll> t(N);
    for(int i = 0;i < N;i++){
        cin >> t[i];
    }
    ll ans = numeric_limits<ll>::max();
    for(int i = 0;i < 1ll<<N;i++){
        ll a= 0;
        ll b = 0;
        for(int j = 0;j < N;j++){
            if (i & 1ll<<j){
                a += t[j];
            }else{
                b += t[j];
            }
        }
        ans = min(ans,max(a,b));
    }
    cout << ans << "\n";
    return 0;
}

int main()
{
    //   ll t;
    //   cin >> t;
    //   for (int i = 1; i <= t; i++)
    //   {
    solve();
    //   }
    cout << flush;
    return 0;
}