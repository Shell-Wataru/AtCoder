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
    ll x,n,m;
    cin >> x>> n >> m;
    ll min_x = x;
    for(int i = 0;i < n;i++){
        x = x/2 + 10;
        min_x = min(min_x,x);
    }

    if(min_x <= 10 * m){
        cout << "YES"<< endl;
    }else{
        cout << "NO" << endl;
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
    return 0;
}
