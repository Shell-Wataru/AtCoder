#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n,x;
    cin >> n >> x;
    vector<ll> W(n);
    for(int i = 0;i< n;i++){
        cin >> W[i];
    }
    sort(W.begin(),W.end(),greater<ll>());
    ll total_w = 0;
    ll ans = 0;
    for(int i = 0;i < n;i++){
        total_w += W[i];
        if(total_w >= (i+1)*x){
            ans++;
        }else{
            break;
        }
    }
    cout << ans << endl;
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
