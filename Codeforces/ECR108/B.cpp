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
    ll n,m,k;
    cin >> n >> m >> k;
    if (n*m - 1 == k ){
        cout << "YES" << endl;
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
    cout << flush;
    return 0;
}
