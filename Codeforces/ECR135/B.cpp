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
ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    scanf("%lld",&n);
    vector<ll> ans(n);
    ans[n-1] = n;
    ans[n-2] = n-1;
    if (n % 2 == 0){
        for(int i = 0;i < n-2;i++){
            ans[i] = n-2-i;
        }
    }else{
        ans[0] = 1;
        ans[1] = 3;
        ans[2] = 2;
        for(int i = 3;i < n-2;i++){
            ans[i] = n-2-i+3;
        }
    }
    for(int i = 0;i < n;i++){
        cout << ans[i] << " ";
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
    cout << flush;
    return 0;
}
