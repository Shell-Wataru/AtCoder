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

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n,x,m;
    cin >> n >>x  >> m;
    ll lx = x;
    ll rx = x;
    for(int i = 0;i < m;i++){
        ll l,r;
        cin >> l >>  r;
        if (r >= lx){
            lx = min(l,lx);
        }
        if (l <= rx){
            rx = max(r,rx);
        }
    }
    cout << rx - lx + 1 << endl;
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
