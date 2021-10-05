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
    ll n,k;
    cin >> n >> k;
    k--;
    if (n % 2 == 0){
        cout << k % n + 1 << "\n";
    }else{
        ll interval = n/2;
        ll add = k/interval;
        cout << (k + add)%n + 1 << "\n";
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
