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
    ll a,b,c,m;
    scanf("%lld",&a);
    scanf("%lld",&b);
    scanf("%lld",&c);
    scanf("%lld",&m);
    ll maximum = max(a-1,0ll) + max(b-1,0ll) + max(c-1,0ll);
    vector<ll> counts = {a,b,c};
    sort(counts.begin(),counts.end());
    ll minimum;
    if (counts[2] <= counts[1] + counts[0]+ 1){
        minimum = 0;
    }else{
        minimum = counts[2]- (counts[1] + counts[0]+ 1);
    }
    if (minimum <= m && m <= maximum){
        cout << "YES\n";
    }else{
        cout << "NO\n";
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
