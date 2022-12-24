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
    ll n,m,sx,sy,d;
    cin >> n >> m >> sx >> sy >> d;
    if ( (sx - d  <= 1 && sx+d >= n) || (sx - d  <= 1 && sy-d <= 1)  || (sy - d  <= 1 && sy+d >= m) || (sx + d  >= n && sy+d >= m)){
        cout << -1 << "\n";
    }else{
        cout << n+m-2 << "\n";
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
